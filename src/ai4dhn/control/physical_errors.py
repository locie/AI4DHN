
# Whether the minimization of T_prim_out, the return temperature at the primary side of themain heat exchanger, is achieved.
# By default True
minimize_T_prim_out = True

def compute_physical_errors(Q_SH, Q_SH_ref, 
                    T_DHW_out, T_DHW_out_ref, 
                    T_prim_in,T_prim_out
                     ):
    """Compute a physical error comparing reference data and physical model ouputs.

    Parameters
    ----------
    Q_SH : float
        Delivered space heating power [W].
    Q_SH_ref : float
        Reference space heating demand [W].
    T_DHW_out : float
        Return temperature of the DHW circulation loop [°C].
    T_DHW_out_ref : float
        Minimum temperature of the DHW circulation loop [°C]. 
        The used interval is [T_DHW_out_ref, T_DHW_out_ref+10]
    T_prim_in : float
        Inlet temperature at the primary side of the main heat exchanger of the substation.
        Must be provided even for minimize_T_prim_out = False.
    T_prim_out : float
        Outlet (return) temperature at the primary side of the main heat exchanger of the substation.
        Must be provided even for minimize_T_prim_out = False.

    Returns
    -------
    dict
        Mapping that contains the computed errors.

        - individual errors contributions.
        Are currently unused in the PPO trainnig phase.
        - total error, sum of all contributions, with key "physical_error_all_contribs"
        - total error used for training the PPO, with key "physical_error".
        This error differs from from "physical_error_all_contribs" by excluding the contribution
        of primary return temperature minimization when  `minimize_T_prim_out` is False
    """


    errors = {}
    
    ###############################################################################
    # OBJ 1: Domestic Hot Water: return temperature of the DHW circulation loop.
    # Must be in the range [T_DHW_out_ref, T_DHW_out_ref+10] 
    ###############################################################################

    # if `piecewise_SH` is True, space heating error is transformed by the function 
    # error --> error ^ (1/4) whenever error > 5.
    # This is an attempt to facilitate learning of the PPO agents that seem to struggle when error explodes during
    # summer and warm days (that have close to zero space heating demands). 
    piecewise_SH = False

    # In some rare cases, the delivered space heating power might be negative.
    # (it happens whenever the supply space heatig temperature in the emitters is lower than the reference indoor temperature)
    # Setting `Q_positif` to True will replace negative powers by zero before computing the error.
    Q_positif = False 

    errors["error_SH"] =  0
    MAE_break = 5
    n = 4
    K1 = n * MAE_break ** (1 - 1/n)
    K2 = (n - 1) * MAE_break
    if Q_positif:
        Q_SH = max(Q_SH, 0)
    MAE =  abs(Q_SH-Q_SH_ref) / Q_SH_ref
    f_left =  lambda MAE_: MAE_
    f_right = lambda MAE_: K1 * (MAE_ ** (1 / n)) - K2
    if MAE < MAE_break:                       
        errors["error_SH"] = f_left(MAE)
    else: 
        errors["error_SH"] = f_right(MAE) if piecewise_SH else f_left(MAE)

    ###############################################################################
    # OBJ 2: Domestic Hot Water: return temperature of the DHW circulation loop.
    # Must be in the range [T_DHW_out_ref, T_DHW_out_ref+10] where 
    ###############################################################################

    errors["error_DHW"] =  0
    f_left =  lambda T: 0.1 * (T_DHW_out_ref - T) + f_center(T_DHW_out_ref)
    f_right = lambda T: 0.1 * (T - (T_DHW_out_ref + 10)) + f_center(T_DHW_out_ref)
    f_center = lambda T: 0.01 * abs(T_DHW_out_ref + 5 - T)
    if T_DHW_out < T_DHW_out_ref:                       
        errors["error_DHW"] = f_left(T_DHW_out)
    elif T_DHW_out_ref + 10 < T_DHW_out:
        errors["error_DHW"] = f_right(T_DHW_out)
    else: 
        errors["error_DHW"] = f_center(T_DHW_out)

    ###############################################################################
    # OBJ 3: Return temperature of the district heating network (must be minimized)
    # this objective is used for training only if minimize_T_prim_out is True
    ###############################################################################

    errors["T_prim_out"] = 0.01 * (T_prim_out - T_prim_in)


    ################################
    # Total error: all contributions
    ################################
    errors["physical_error_all_contribs"] = sum([
                                    errors["error_SH"],
                                    errors["error_DHW"],
                                    errors["T_prim_out"]
                                    ]
                                    )
    
    #######################################################################
    # Total error: only the contributions that must be use for PPO training.
    # See `minimize_T_prim_out`.
    #######################################################################
    
    if minimize_T_prim_out:
        errors["physical_error"] = errors["physical_error_all_contribs"]
    else:
        errors["physical_error"] = sum([
                                    errors["error_SH"],
                                    errors["error_DHW"],
                                             ])
    return errors
