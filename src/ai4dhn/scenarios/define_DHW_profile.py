def call():

    from ai4dhn.control.utilities import provide_dir_path


    def run(args):

        # import warnings
        # warnings.filterwarnings('ignore')

        # --- Constants ---
        holidays = OpenDHW.get_holidays(country_code = args.country_code, year = args.year) 

        # generate time-series with OpenDHW
        timeseries_df = OpenDHW.generate_dhw_profile(
            s_step=60,  # 60 seconds, then resampled
            categories=args.categories,
            occupancy=args.occupancy,
            building_type=args.building_type,
            weekend_weekday_factor=1.2 if args.building_type in {"SFH", "TH", "MFH", "AB"} else 1,
            holidays=holidays,
            mean_drawoff_vol_per_day=args.mean_drawoff_vol_per_day,
            initial_day=datetime(day=1, month=1, year=args.year).weekday()
        )
        
        timeseries_df["DHW draw-off [kg/s]"]  = timeseries_df["Water_LperH"] / 3600
        timeseries_df = timeseries_df[["DHW draw-off [kg/s]"]]


        index = date_range(start=f'{args.year}-01-01', periods=len(timeseries_df), freq="60s")
        local_index = index.tz_localize(args.UTC_offset*3600)
        UTC_index   = index.tz_localize("UTC")
        timeseries_df = timeseries_df.set_index(local_index)
        timeseries_df = timeseries_df.reindex(UTC_index, fill_value=0)
        timeseries_df = timeseries_df.resample(f"{args.time_step}s").interpolate()

        # save timeseries
        p = args.scenario
        p.mkdir(exist_ok=True, parents=True)
        if (p/"DHW.csv").exists() and (not args.overwrite):
            raise FileExistsError(f"A DHW file was found for scenario {args.scenario}. " 
                                "Please delete it or call this script with `--overwrite`")

        timeseries_df.index.name = "time(UTC)" # same than SH
        timeseries_df.to_csv(p/"DHW.csv", float_format="%.4f")
        
        
        with open(p/"DHW_description.txt", "w") as f:
            for k, v in vars(args).items():
                if k != "overwrite":
                    f.write(f"{k}: {v}\n\n")


    description = \
"""This scripts generates an annual OpenDHW Timeseries (in kg/s). Date is UTC.

DESCRIPTION
    It is based on the OpenDHW package.
    MIT License
    Copyright (c) 2024 RWTH Aachen University   
        - E.ON Energy Research Center 
        - Institute for Energy Efficient Buildings and Indoor Climate


    Like DHWcalc, OpenDHW need a parametrisation. The usual parametrisation for 
    households is 40 L/(person*day). This value is set 
    as 'mean_drawoff_vol_per_day'. For example, a single-family house 
    (SFH) with 5 occupants would have a total mean daily water consumption of 
    200 L/day (5 people * 40 L/person/day).

    For non-residental buildings, the daily probability functions are based on 
    the "people profile" described in the SIA Standard-Nutzungsbedingungen
    für die Energie- und Gebäudetechnik (Merkblatt 2024).

    Building types supported by the script:

    - SFH: Single Family House
    - TH: Terraced House
    - MFH: Multi-Family House
    - AB: Apartment Block
    - SC: School 
    - OB: Office building
    - GS: Grocery store
    - RE: Restaurant


TECHNICAL NOTE

    By default, OpenDHW produces data:

    - with temporal information of the year 2019.
    (Yet, the initial day `initial_day` is taken into account in the computaiton steps)
    - that is time zone unaware. I.e. the used time is local time, 
    but not associated with any specific place/time zone in the world.

    This script transforms this data:

    - new temporal information is of the year `args.year`
    - localized according to `UTC_offset`, and then converted to UTC to be compliant 
    with SH and weather data generated using the `ai4dhn-define-SH-profile` script.
    This conversion introduces new time stamps for which no DHW draw-off data is available 
    (at the beginning or end of the year). In these cases, the value
    0 kg/s is used.

    In case the `merge` script is called to create a unified thermal demands file,    
    the temporal information of the DHW profile is used as reference.
"""

    from argparse import ArgumentParser, RawTextHelpFormatter, ArgumentDefaultsHelpFormatter

    class Formatter_(RawTextHelpFormatter, ArgumentDefaultsHelpFormatter): 
        pass
    parser = ArgumentParser(description=description,
                            formatter_class=Formatter_)

    parser.add_argument("scenario", 
                        type=provide_dir_path,
                        help="Output directory. Will be created if needed.",
                        )
    
    parser.add_argument("--time_step", 
                        type=int,
                        help="Time step in minutes",
                        required=True)
    
    parser.add_argument("--year",
                        type=int,
                        help="""Used to make a distinction betweek weekday (Monday to Friday)
and week-end days (Saturday, Sunday).""",
                        required=True)

    parser.add_argument("--building_type", 
                        help="""Type of the building. 
Some building types are identical to the ones defined by the Tabula documentation
(call `ai4dhn-define-SH-profile` with argument `export`), 
some other are different (see DHWCalc documentation).""",
                        choices=("SFH", "TH", "MFH", "AB", "SC", "OB", "GS", "RE"),
                        required=True)
    

    parser.add_argument("--occupancy", 
                        type=int,
                        help="""Number of persons in the building. 
It could be for instance: 
floor(n_Apartment * pers_per_apartment) + 1 with pers_per_apartment=2.1""",
                        # "source: Ademe (France): "Les besoins d’eau chaude sanitaire en habitat individuel et collectif"
                        required=True)
    
    parser.add_argument("--country_code", 
                        help="""Country code that determines holiday periods 
(DHW draw-off is smaller during these periods).""",
                        required=True)
    
    parser.add_argument("--UTC_offset",
                        type=int, 
                        help="""Shift in hours from UTC. 
Needed for compliance with space heating data.""",
                        required=True)
    
    parser.add_argument("--mean_drawoff_vol_per_day", 
                        type=float,
                        help="""Average daily mass of hot water per person [kg/(person.day)]""",
                        default=40,     
                        required=False) # Ademe (france): 35 l/(jour.personne)

    parser.add_argument("--categories", 
                        help="Number of draw-off points",
                        default=4,
                        type=int,
                        choices=[1, 4],
                        required=False)
    

    parser.add_argument("--overwrite", 
                        action="store_true",
                        help="Whether to overwrite an existing domestic hot water file.")

    args = parser.parse_args()


    args.time_step *= 60 # convert from minute to second
    from calendar import isleap

    if isleap(args.year):
        raise ValueError("`year` must not be a leap year.")
    
    from datetime import datetime
    import OpenDHW
    from pandas import date_range

    run(args)

