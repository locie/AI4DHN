from pathlib import Path
from pandas import DataFrame, concat

def _is_iter(value):
    try:
        iter(value)
    except TypeError as e: # <value> object is not iterable
        return False
    else:
        return True
    
def postprocess(inputs, outputs, indicators, other_variables, index, save_directory, suffix="", save=True, plot=True):
    """Concatenate provided inputs, outputs, indicators and other variables in a unique pd.DataFrame.
    Conflict are prevented by appending suffixes:

    - "var_name (in)" for inputs
    - "var_name (out)" for outputs
    - "var_name (indic)" for indicators
    - "var_name (other)" for other_variables

    This DataFrame can be:
     
    - visualized with `plotly`

        Plotting take more than 2 minutes for a full-year at 1 min time step. See the Notes section for further information. 

    - and/or saved to disk as a CSV file named "results.csv".

        This file is compatible with the "Simulation Data Inspector" (Simulink.sdi.view) of Matlab/Simulink (thanks to first column "time", seconds).
    

    Parameters
    ----------
    inputs : dict[int, dict[str, float|Iterable[float]]]
        Inputs that were fed to the physical model.
        Outer dictionary keys are simulation time steps. Inner dictionary are names-values mappings of physical variables.
    outputs : dict[int, dict[str, float|Iterable[float]]]
        Outputs returned by the physical model.
        Outer dictionary keys are simulation time steps. Inner dictionary are names-values mappings of physical variables.
    indicators : dict[int, dict[str, float|Iterable[float]]]
        User-defined indicators. 
        The main indicator is `physical_error`, which is used in the PPO training process.
        Outer dictionary keys are simulation time steps. Inner dictionary are names-values mappings of physical variables.
    other_variables : dict[int, dict[str, float|Iterable[float]]]
        Additional variables to process.
        Outer dictionary keys are simulation time steps. Inner dictionary are names-values mappings of physical variables.
    index : pd.DatetimeIndex
        Temporal information of the simulation. 
        `index[0]` will be associated with key inputs[0] and so on (same for `outputs`, `indicators` and `other_variables`)
    save_directory : pathlib.Path
        Directory for CSV file when `save=True`.
    suffix : str, optional
        Text to append at the end of saved file, by default ""
    save : bool, optional
        Whether to save the full DataFrame to disk, by default True
    plot : bool, optional
        Whether to plot the full DataFrame using `plotly`, by default True.


    Returns
    -------
    pd.DataFrame
        Concatenation of all passed variables.

        - axis 0 (rows) is the temporal axis. Temporal information is provided through the `index` argument.
        - axis 1 (columns) is the variable axis. This order is observed:
            
            1. `indicators` variables
            2. `inputs` variables
            3. `outputs` variables
            4. `other_variables` variables


    Notes
    -----
    1. About `plot=True`.
    One figure is drawn for each simulation month. Each figure contains four subplots:

    - upper left: all variables named "T_[...] (in|out|other)", that are not indicators.

    This is typically intended for temperatures, that typically range from 0 to 200 °C

    - lower left: all variables named "m_[...] (in|out|other)", that are not indicators.

    This is typically intended for mass flow rates, that typically range from 0 to 5 kg/s

    - upper right: all variables named "P_[...] (in|out|other)" or "Q_[...] (in|out|other)", that are not indicators.

    This is typically intended for thermal power, that typically range from 0 to 500,000 W

    - lower right: all remaining variables.

    This includes all indicators.

    2. About `save=True`.
    If any non-scalar variable is present in the provided data, it will be saved to a dedicated file.
    """
    
    # sorting inputs/outputs/indicators/other variables depending on if they are scalar or 1D iterables
    iter_names = {}
    scalar_names = {}

    for var, suffix_iter in [
                            (inputs, "in"),
                            (outputs, "out"),
                            (indicators, "indic"),
                            (other_variables, "other"),
                            ]:
        
        idx = list(var.keys())[0]
        iter_names[suffix_iter] = []
        scalar_names[suffix_iter] = []
        for name, value in var[idx].items():
            if _is_iter(value):
                iter_names[suffix_iter].append(name)
            else:
                scalar_names[suffix_iter].append(name) 

    # converting dicts to DataFrames
    inputs_ = DataFrame.from_dict(inputs, orient="index")
    inputs_.index = index
    inputs_ = inputs_.sort_index()          # needed for chronological order


    outputs_ = DataFrame.from_dict(outputs, orient="index")
    outputs_.index = index
    outputs_ = outputs_.sort_index()          # needed for chronological order
    

    indicators_ = DataFrame.from_dict(indicators, orient="index")
    indicators_.index = index
    indicators_ = indicators_.sort_index()            # needed for chronological order

    other_variables_ = DataFrame.from_dict(other_variables, orient="index")
    other_variables_.index = index
    other_variables_ = other_variables_.sort_index()            # needed for chronological order


    print("Indicators overview (mean): ")
    print(indicators_[scalar_names["indic"]].mean())

    inputs_.columns = [f"{c} (in)"     for c in inputs_.columns]
    outputs_.columns = [f"{c} (out)"    for c in outputs_.columns]
    indicators_.columns =  [f"{c} (indic)" for c in indicators_.columns]
    other_variables_.columns =  [f"{c} (other)" for c in other_variables_.columns]
    
    df = concat([indicators_, inputs_, outputs_, other_variables_], axis=1)

    time = (df.index -df.index[0]).total_seconds()
    df.insert(0, "time", time)

    if save | plot:

        # removing inputs/outputs/indicators/other variables that are iterables.
        # each will be saved in a dedicated file
        to_drop = sum(
                [[f"{e} ({suffix_iter})" for e in iter_names[suffix_iter]] for suffix_iter in ("in", "out", "indic", "other")],
                []
                    )
        df_ = df.drop(to_drop, axis=1)

        if save:
            directory = Path(save_directory)
            directory.mkdir(parents=True, exist_ok=True)

            # scalar results export
            # full datetime information must be kept, though "time" is the first column now
            df_ref = df_.reset_index() \
                      .set_index("time")
            
            df_ref.to_csv(directory/f"results{suffix}.csv", index=True) 

            # export of iterable inputs/outputs/indicators/other variables
            for var, suffix_iter in [
                                    (inputs, "in"),
                                    (outputs, "out"),
                                    (indicators, "indic"),
                                    (other_variables, "other"),
                                    ]:                
                for name in iter_names[suffix_iter]:
                    data = {}
                    for idx in var.keys():
                        data[idx] = var[idx][name]
                    df__ = DataFrame.from_dict(data, orient="index")
                    df__ = df__.set_index(df_ref.index)       # "time" column
                    df__.insert(0, "index", df_ref["index"])
                    df__.to_csv(directory / f"{name}{suffix}___{suffix_iter}.csv")

        if plot:
            _plot(df_)
    return df

def _plot(df):
    """
    The preferred way of calling this function is from the `postprocess` function. Please see `postprocess` docstring
    """
    from plotly.subplots import make_subplots
    import plotly.graph_objects as go


    def _plot_month(df_, month_name):          
        fig = make_subplots(rows=2, cols=2, 
                            vertical_spacing = 0.04,
                            horizontal_spacing=0.02,
                            subplot_titles=["Temperatures (°C)", "Power (W)", "Mass flow (kg/s)", "Indicators and non-prefixed variables"],
                            shared_xaxes="all",
                            )
        plotted = []
        # inputs/outputs/other variables whose name starts with "T_"
        for col in df_.filter(regex=r"^T_.*?\((in|out|other)\)$").sort_index(axis=1):
            plotted.append(col)
            fig.add_trace(go.Scatter(
                x=df_.index,
                y=df_[col],
                name=col,
                visible="legendonly",
            ), row=1, col=1)

        # inputs/outputs/other variables whose name starts with "m_"
        for col in df_.filter(regex=r"^m_.*?\((in|out|other)\)$").sort_index(axis=1):
            plotted.append(col)
            fig.add_trace(go.Scatter(
                x=df_.index,
                y=df_[col],
                name=col,
                visible="legendonly",
            ), row=2, col=1)


        # inputs/outputs/other variables whose name starts with "P_" or "Q_"
        for col in df_.filter(regex=r"^(P|Q)_.*?\((in|out|other)\)$").sort_index(axis=1):
            plotted.append(col)
            fig.add_trace(go.Scatter(
                x=df_.index,
                y=df_[col],
                name=col,
                visible="legendonly",
            ), row=1, col=2)


        # all remaining variables
        for col in df_.sort_index(axis=1).columns:
            if col not in plotted:
                fig.add_trace(go.Scatter(
                    x=df_.index,
                    y=df_[col],
                    name=col,
                    visible="legendonly",
                ), row=2, col=2)
        
        # print("Variables plotted in the lower right corner")
        # print(*[f"- {c}" for c in (set(df_.columns)-set(plotted))], sep="\n")


        fig.update_layout(title={
                                "text": month_name,
                                "font": dict(color="red")}, 
                            margin=dict(l=20, r=20, t=25, b=20))
        fig.show()

    for month_name in df.index.month_name().unique():
        df_ = df[df.index.month_name()==month_name]
        _plot_month(df_, month_name)

