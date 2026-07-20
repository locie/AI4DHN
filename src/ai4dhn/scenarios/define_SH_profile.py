def call():

    from pathlib import Path

    from ai4dhn.control.utilities import provide_dir_path



    def get_TMY(args):
        """Returns a one-year dataset of meteorological data as a Typical Meteorological Year.

        """
        # `coerce_year=None` is not used since it would make the resampling process difficult
        df, years, *_ = pvlib.iotools.get_pvgis_tmy(args.latitude, 
                                                    args.longitude, 
                                                    startyear=args.start_year, 
                                                    endyear=args.end_year)

        df = df[["dni", "dhi", "wind_speed", "temp_air"]]
        external_temperature, direct_normal_irradiance, diffuse_horizontal_irradiance = df[["temp_air", "dni", "dhi"]].T.values
        index = df.index
        direct_normal_irradiance = direct_normal_irradiance * 1e-3              # kW/m2
        diffuse_horizontal_irradiance = diffuse_horizontal_irradiance * 1e-3    # kW/m2
        dir_path = args.scenario
        dir_path.mkdir(exist_ok=True,parents=True)

        if (dir_path/"SH.csv").exists() and (not args.overwrite):
            raise FileExistsError(f"A space heating file was found for scenario {args.scenario}. " 
                                "Please delete it or call this script with argument `--overwrite`")
        
        df2 = pvlib.solarposition.get_solarposition(df.index, args.latitude, args.longitude)
        azimuth, elevation = df2[["azimuth", "elevation"]].T.values

        if args.time_step != 3600:
            df = df.resample(f"{args.time_step}s").interpolate()
        df.to_csv(dir_path/"weather.csv")
        return azimuth, elevation, index, external_temperature, direct_normal_irradiance, diffuse_horizontal_irradiance, years

    def get_weather_realyear(args):
        """Returns a one-year dataset of meteorological data (real measurements during the given year).

        """
        df, metadata = pvlib.iotools.get_pvgis_hourly(args.latitude, args.longitude, start=args.year, end=args.year)
        # For an unknown reason, `get_pvgis_hourly` returns data that is shifted of a few minutes.
        # The operation below ensures timestamps correspond to full hours
        df.index = df.index - df.index.minute * Timedelta(minutes=1)

        # The diffuse irradiance "dhi" of "PVGIS TMY" may be an average of 
        # "poa_sky_diffuse" and 'poa_ground_diffuse' specified in "PVGIS hourly"
        # The assumption here is: dhi = poa_sky_diffuse
        df = df[["poa_direct", "poa_sky_diffuse", "wind_speed", "temp_air"]]
        df.columns = ["dni", "dhi", "wind_speed", "temp_air"]


        external_temperature, direct_normal_irradiance, diffuse_horizontal_irradiance = df[['temp_air', "dni", "dhi"]].T.values
        index = df.index

        dir_path = args.scenario
        dir_path.mkdir(exist_ok=True, parents=True)

        if (dir_path/"SH.csv").exists() and (not args.overwrite):
            raise FileExistsError(f"A space heating file was found for scenario {args.scenario}. " 
                                "Please delete it or call this script with argument `--overwrite`")
        
        df2 = pvlib.solarposition.get_solarposition(df.index, args.latitude, args.longitude)
        azimuth, elevation = df2[["azimuth", "elevation"]].T.values
        
        if args.time_step != 3600:
            df = df.resample(f"{args.time_step}s").interpolate()
        df.to_csv(dir_path/"weather.csv")

        years = [args.year]

        return azimuth, elevation, index, external_temperature, direct_normal_irradiance, diffuse_horizontal_irradiance, years

    def _get_buildings_list():
        buildings_list = list(Building._TD1.index.unique().dropna())[2:]
        buildings_list = [e.split(".") + [e] for e in buildings_list]
        buildings_list = [e for e in buildings_list if len(e) == 8 + 1]
        df = DataFrame(buildings_list)
        df.columns = ["country", "climate zone", "building type", "period", "unused1", "sample or stock average", "unused2", "retrofitting level", "name"]
        df = df[df["sample or stock average"]=="ReEx"].drop("sample or stock average", axis=1)
        df = df.set_index(list(df.columns[:-1]))
        return df

    def export_buildings_list():
        df = _get_buildings_list()
        p = Path.cwd() / "buildings_list.csv"
        df.to_csv(p, index=True)


    def run(args):
        building = Building(args.building_name)
        f = get_TMY if args.weather_mode == "TMY" else get_weather_realyear
        azimuth, elevation, index, external_temperature, direct_normal_irradiance, diffuse_horizontal_irradiance, years = f(args)
        weather = Weather(external_temperature,
                    direct_normal_irradiance,
                    diffuse_horizontal_irradiance,
                    azimuth,
                    elevation
                    )

        demand = Demand(building, weather, DHW_profile_draw_off=zeros(8760), drop_contributions=False)
        df = demand.df[["SH"]] # Space cooling "SC" could be used to in more advanced studies
        df.columns = ["Space heating [W]"]
        # converting to W/m2
        df = df * 1e3          
        val1 = df["Space heating [W]"].sum()/1e3
        # surfacic demand is converted to total demand
        df = df * building.A_C_Ref                          
        val2 = df["Space heating [W]"].sum()/1e6
        content  = "Space heating demand:\n"
        content += f"- SH: {val1: 3.0f} kWh/(m2.year)\n"
        content += f"- SH: {val2: 3.0f} MWh/year\n\n\n"

        dir_path = args.scenario
        dir_path.mkdir(exist_ok=True, parents=True)

        df = df.set_index(index)

        if args.time_step != 3600:
            df = df.resample(f"{args.time_step}s").interpolate()

        df["Space heating [W]"].to_csv(f"{args.scenario}/SH.csv", float_format="%.0f")
        
        str_io = StringIO()
        pprint(years, width=200, stream=str_io)
        content += "Weather data properties:\n"
        content += str_io.getvalue()


            
        with open(f"{args.scenario}/SH_description.txt", "w") as f:
            for k, v in vars(args).items():
                if k != "overwrite":
                    f.write(f"{k}: {v}\n\n")

            f.writelines(content)








    description = \
""" This scripts generates an annual space heating profile (in kW). Date is UTC.

It is based on the following packages:

    - pvlib: download weather data

    - tdmat: define building properties and corresponding thermal demand
        https://github.com/BNerot/tdmat
        Apache License Version 2.0
"""

    from argparse import ArgumentParser, RawTextHelpFormatter, ArgumentDefaultsHelpFormatter
    class Formatter_(RawTextHelpFormatter, ArgumentDefaultsHelpFormatter): 
        pass




    parser = ArgumentParser(description=description,
                            formatter_class=Formatter_)
    subparser = parser.add_subparsers(dest="mode",
                                    title="mode",
                                    required=True)
    subparser.formatter_class = Formatter_


    export_parser = subparser.add_parser("export",
                            help="""
Export in the current directory the names (and main properties) of the buildings
than can be used to generate a space heating profile.""")
    export_parser.formatter_class = Formatter_
    


    generate_parser = subparser.add_parser("generate",
                                    help="""
Download hourly weather data and generate the corresponding SH profile.
This profile is then resampled to match the given time step. 
Please call this script with arguments `generate --help` for further information.""")
    generate_parser.formatter_class = Formatter_

    
    generate_parser.add_argument("--building_name", 
                        help="""
Name of a building in the Tabula database. 
The building thermal properties are used to compute a space heating demand profile. 
Call this script with arguments `export` to get a list of available buildings. 
Some buildings may be inappropriate or produce an error, 
please always check the generated profile.""",
                        required=True)
    
    generate_parser.add_argument("--time_step", 
                        type=int,
                        help="Time step in minutes",
                        required=True)
    
    generate_parser.add_argument("--latitude", 
                        type=float,
                        help="Following WGS 84. Defines weather data.",
                        required=True)
    
    generate_parser.add_argument("--longitude", 
                        type=float,
                        help="Following WGS 84. Defines weather data.",
                        required=True)    
    
    generate_parser.add_argument("--place_name", 
                        help="Tag refering to (latitude, longitude), only for tracability purpose.",
                        default="",
                        required=False)

    generate_parser.add_argument("--overwrite", 
                        action="store_true",
                        help="Whether to overwrite an existing space heating file.")
    
    

    generate_subparser = generate_parser.add_subparsers(title="weather_mode",
                                                        dest="weather_mode",
                                                        required=True)
    generate_subparser.formatter_class = Formatter_
    
    generate_TMY_parser = generate_subparser.add_parser("TMY",
                                help="""
Generate a space heating profile based on a Typical Meteorological Year. 
Please call this script with arguments `generate TMY --help` 
for further information.""")
    generate_TMY_parser.formatter_class = Formatter_
    
    generate_TMY_parser.add_argument("scenario", 
                                     type=provide_dir_path,
                                     help="Output directory. Will be created if needed.",
                                     )
    
    generate_TMY_parser.add_argument("--start_year", 
                        type=int,
                        help="First year of period to build TMY.",
                        required=True)
    
    generate_TMY_parser.add_argument("--end_year", 
                        type=int,
                        help="Last year of period to build TMY.",
                        required=True)


    generate_realyear_parser = generate_subparser.add_parser("realyear",
                                help="""
Generate a space heating profile based on weather data from given year.
Please call this script with arguments `generate realyear --help`
for further information.""")
    generate_realyear_parser.formatter_class = Formatter_
        
    
    generate_realyear_parser.add_argument("scenario", 
                                     type=provide_dir_path,
                        help="Output directory. Will be created if needed.",
                        )
    
    generate_realyear_parser.add_argument("--year", 
                        type=int,
                        help="""
Year for weather data. 
Must not be a leap year (compatibility with DHW profile generation). 
Recent leap years are 2012, 2016, 2020.""",
                        required=True)
    
    args = parser.parse_args()

    import warnings
    warnings.filterwarnings("ignore")
    from tdmat import Building, Demand, Weather


    from io import StringIO
    from pprint import pprint

    from numpy import zeros
    from pandas import DataFrame, concat, date_range, Timedelta

    if args.mode == "export":
        export_buildings_list()
    else:

        args.time_step *= 60 # conversion from minutes to seconds
        import pvlib
        if args.weather_mode == "TMY":
            pass
        else:
            from calendar import isleap
            if isleap(args.year):
                raise ValueError(f"`year` must not be a leap year, year '{args.year}' was passed.")
        run(args)
