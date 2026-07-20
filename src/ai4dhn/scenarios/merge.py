def call():
    from pathlib import Path
    from ai4dhn.control.utilities import provide_dir_path

    def provide_date_str(arg):
        try:
            arg = to_datetime(f"2026-{arg}", format="%Y-%m-%d", utc=True)
        except ValueError as e:
            raise ValueError("Invalid date format") # unused, replaced by Error defined at argparse level
        else:
            return arg
        
    def run(args):
        p = args.scenario
        df_SH = read_csv(p/"SH.csv", index_col=0, parse_dates=True)
        df_weather = read_csv(p/"weather.csv", index_col=0, parse_dates=True)
        df_DHW = read_csv(p/"DHW.csv", index_col=0, parse_dates=True)
        df_ = merge(left=df_weather, right=df_SH, how="inner", left_index=True, right_index=True)
        n = min(len(df_), len(df_DHW))
        # technical note: df_DHW and df_ can have different number or rows since:
        # - DHW profile is always downsampled (from minute to "greater than minute" time step)
        # - SH profile can be up or downsampled
        df_ = df_.set_index(df_DHW.index[:n], drop=True) 
        df = merge(left=df_, right=df_DHW, how="inner", left_index=True, right_index=True)
        cond1 = df.isna().any(axis=None)
        cond2 = len(df) != len(df_SH)
        if cond1 or cond2:
            raise ValueError("Invalid data. Do \"SH.csv\" and \"DHW.csv\" share the same profile?")
        df = df.iloc[:,::-1]
        if args.start_day is not None:
            df = df.loc[args.start_day:]
        if args.end_day is not None:
            # example: if end_day=12-31 is passed
            # - then args.end_day is 31th of december at midnight 
            #   (i.e. start of the day)
            # - but we want the entire day of 31th december (thus: days = 1 in `Timedelta`)
            # - but we don't want the first sample of the day after (thus: nanoseconds=-1 in `Timedelta`)
            #  note: `df.loc[:<something>]` cannot be easily used since it includes <something>
            last_time_day_before = args.end_day + Timedelta(days=1, nanoseconds=-1)
            to_keep = df.index <= last_time_day_before
            df = df.loc[to_keep] 
        df.to_csv(p/"data.csv")
        
    description = """
Merge 3 CSV files:

    - a space heating demand profile, "SH.csv" (unit: Watt)
    This profile is defined by calling `ai4dhn-define-SH-profile`.

    - associated weather data (various units)
    This profile is defined by the same call to `ai4dhn-define-SH-profile`.

    - a domestic hot water demand profile, "DHW.csv" (unit: kg/s)
    This profile is defined by  `ai4dhn-define-DHW-profile`






The resulting file is called "data.csv". 

Some other data files are mandatory and must be created in the same directory. 
They are:

    - SST_parameters.json: physical parameters of the substation model. 
    Names must match the names of the C-code versio of the model. 
    Please see the header of generated file `_interface.py` for a list of parameters names.
    
    - constant_data.json: all relevant data to be used by the control algorithm. 



"""
    from argparse import ArgumentParser, RawTextHelpFormatter, ArgumentDefaultsHelpFormatter
    from pandas import read_csv, merge, to_datetime, Timedelta
    class Formatter_(RawTextHelpFormatter, ArgumentDefaultsHelpFormatter): 
        pass
    parser = ArgumentParser(description=description,
                            formatter_class=Formatter_)
    parser.add_argument("--start_day", 
                        type=provide_date_str,
                        default=None,
                        help=\
"""Concatenated annual data will be truncated to start on this day (included).
Day of the year with format MM-DD, e.g. 06-18 for June 18th. 

Truncating the data may cause inconsistent behaviour with the `[...]_SH_filter`
arguments of `ai4dhn-control` command.s
"""
                        )
    parser.add_argument("--end_day", 
                        type=provide_date_str,
                        default=None,
                        help=\
"""Concatenated annual data will be truncated to end on this day (excluded).
Day of the year with format MM-DD, e.g. 06-18 for June 18th.

Truncating the data may cause inconsistent behaviour with the `[...]_SH_filter`
arguments of `ai4dhn-control` command.
"""
                        )
    
    
    parser.add_argument("scenario", 
                        type=provide_dir_path,
                        help="""Path to the directory containing CSV thermal demand files: 
space heating, domestic hot water and weather data.""",
                        )
    args = parser.parse_args()
    run(args)