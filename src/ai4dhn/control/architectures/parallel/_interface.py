

"""
This files is the software interface with the C version of a Simulink model of substation.
This file was generated and must not be modified.
"""
from ctypes import cdll, c_double, c_int, byref, POINTER
from pathlib import Path
from shutil import copy2
from os import PathLike
from tempfile import TemporaryDirectory
    

# Description of inputs, outputs and parameters
if True:

    pass
    # 
    # ### INPUTS
    # 
    # - m_prim
    # - T_prim_in
    # - m_SH_dir
    # - m_SH_3V
    # - m_DHW_sec
    # - m_DHW_w
    # - m_DHW_recirc
    # - T_cold
    # - m_DHW_dir
    # - m_DHW_3V
    # 
    # ### OUTPUTS
    # 
    # - T_sec_in
    # - T_DHW_out
    # - T_out
    # - T_DHW_sec_out
    # - T_DHW_sec_in
    # - T_DHW_prim_in
    # - T_DHW_prim_out
    # - T_SH_out
    # - T_SH_in
    # - T_prim_out
    # - T_sec_out
    # - T_SH_emitter_out
    # - T_stor_n
    # - Q_SH
    # - Q_primary_HX
    # - Q_DHW_HX
    # - m_DHW
    # - Q_SH_supply
    # - Q_SH_return
    # - T_stor_out
    # - T_stor_avg
    # - T_stor_mid
    # - T_stor_std
    # - T_stor_half
    # - T_stor_1
    # - m_DHW_prim
    # - m_sec
    # - m_SH
    # - Q_DHW_supply
    # - Q_DHW_return
    # - efficiency_primary_HX
    # - efficiency_DHW_HX
    # - T_DHW_in
    # - T_SH_emitter_in
    # - T_stor_in
    # - m_DHW_stor
    # 
    # ### PARAMETERS
    # 
    #       getting current value: `getP_{name}()`
    #       setting a new value for one parameter: `setP_{name}(value)`
    #       setting a new value for several parameters: `setP_from_dict(dict_like)`
    #       getting all parameters values as a dictionary: `getP_as_dict()`
    #       physical units to be used can be seen in the Simulink version of this model`
    # 
    # - DHWheatexchanger_A
    # - Primaryheatexchanger_A
    # - DHWreturnpipe_D
    # - DHWstorage_D
    # - DHWsupplypipe_D
    # - SHreturnpipe_D
    # - SHsupplypipe_D
    # - SHthermalemitters_D
    # - DHWstorage_H
    # - DHWreturnpipe_L
    # - DHWsupplypipe_L
    # - SHreturnpipe_L
    # - SHsupplypipe_L
    # - SHthermalemitters_L
    # - SHthermalemitters_T_air
    # - DHWstorage_T_amb
    # - DHWreturnpipe_T_duct
    # - DHWsupplypipe_T_duct
    # - SHreturnpipe_T_duct
    # - SHsupplypipe_T_duct
    # - DHWstorage_U
    # - SHthermalemitters_U
    # - DHWheatexchanger_U
    # - Primaryheatexchanger_U
    # - DHWstorage_V_min
    # - DHWstorage_V_var
    # - DHWstorage_eps
    # - DHWreturnpipe_m_min
    # - DHWsupplypipe_m_min
    # - SHreturnpipe_m_min
    # - SHsupplypipe_m_min
    # - SHthermalemitters_m_min
    # - DHWstorage_n
    # - SHthermalemitters_n_radiators
    # - SHthermalemitters_n_tubes
    # - DHWbypassvalve_unknown_T
    # - DHWstoragetopvalve_unknown_T
    # - DHWcoldwaterrefill_unknown_T
    # - DHWstoragebottomvalve_unknown_T
    # - SHbypassvalve_unknown_T
    # - SHDHWreturnvalve_unknown_T
    # - DHWbypassvalve_unknown_m
    # - DHWstoragetopvalve_unknown_m
    # - DHWcoldwaterrefill_unknown_m
    # - DHWstoragebottomvalve_unknown_m
    # - SHbypassvalve_unknown_m
    # - SHDHWreturnvalve_unknown_m
    # - Delay_InitialCondition
    # - Delay1_InitialCondition
    # - Constant1_Value
    # - Delay6_InitialCondition
    # - Delay5_InitialCondition
    # - Switch3_Threshold
    # - Constant5_Value
    # - Constant6_Value
    # - Switch2_Threshold
    # - Delay_InitialCondition_o
    # - Delay_InitialCondition_k
    # - Constant7_Value
    # - Switch_Threshold
    # - Delay_InitialCondition_o4
    # - Switch4_Threshold
    # - Constant_Value
    # - Constant4_Value
    # - Switch1_Threshold
    # - Delay2_InitialCondition
    # - Delay7_InitialCondition
    # - Constant2_Value
    # - Delay_InitialCondition_j
    # - Delay_InitialCondition_l
    # - Delay_InitialCondition_jr
    # - Constant3_Value

class Interface:

    _first_instance = True
    lib_path: PathLike | str = None

    

# =======
# MAPPERS
# =======

# -- U --

    _mapper_U = {0: 'm_prim', 1: 'T_prim_in', 2: 'm_SH_dir', 3: 'm_SH_3V', 4: 'm_DHW_sec', 5: 'm_DHW_w', 6: 'm_DHW_recirc', 7: 'T_cold', 8: 'm_DHW_dir', 9: 'm_DHW_3V'}
    # -- Y --

    _mapper_Y = {0: 'T_sec_in', 1: 'T_DHW_out', 2: 'T_out', 3: 'T_DHW_sec_out', 4: 'T_DHW_sec_in', 5: 'T_DHW_prim_in', 6: 'T_DHW_prim_out', 7: 'T_SH_out', 8: 'T_SH_in', 9: 'T_prim_out', 10: 'T_sec_out', 11: 'T_SH_emitter_out', 12: 'T_stor_n', 13: 'Q_SH', 14: 'Q_primary_HX', 15: 'Q_DHW_HX', 16: 'm_DHW', 17: 'Q_SH_supply', 18: 'Q_SH_return', 19: 'T_stor_out', 20: 'T_stor_avg', 21: 'T_stor_mid', 22: 'T_stor_std', 23: 'T_stor_half', 24: 'T_stor_1', 25: 'm_DHW_prim', 26: 'm_sec', 27: 'm_SH', 28: 'Q_DHW_supply', 29: 'Q_DHW_return', 30: 'efficiency_primary_HX', 31: 'efficiency_DHW_HX', 32: 'T_DHW_in', 33: 'T_SH_emitter_in', 34: 'T_stor_in', 35: 'm_DHW_stor'}
    # -- P --

    _mapper_P = {0: 'DHWheatexchanger_A', 1: 'Primaryheatexchanger_A', 2: 'DHWreturnpipe_D', 3: 'DHWstorage_D', 4: 'DHWsupplypipe_D', 5: 'SHreturnpipe_D', 6: 'SHsupplypipe_D', 7: 'SHthermalemitters_D', 8: 'DHWstorage_H', 9: 'DHWreturnpipe_L', 10: 'DHWsupplypipe_L', 11: 'SHreturnpipe_L', 12: 'SHsupplypipe_L', 13: 'SHthermalemitters_L', 14: 'SHthermalemitters_T_air', 15: 'DHWstorage_T_amb', 16: 'DHWreturnpipe_T_duct', 17: 'DHWsupplypipe_T_duct', 18: 'SHreturnpipe_T_duct', 19: 'SHsupplypipe_T_duct', 20: 'DHWstorage_U', 21: 'SHthermalemitters_U', 22: 'DHWheatexchanger_U', 23: 'Primaryheatexchanger_U', 24: 'DHWstorage_V_min', 25: 'DHWstorage_V_var', 26: 'DHWstorage_eps', 27: 'DHWreturnpipe_m_min', 28: 'DHWsupplypipe_m_min', 29: 'SHreturnpipe_m_min', 30: 'SHsupplypipe_m_min', 31: 'SHthermalemitters_m_min', 32: 'DHWstorage_n', 33: 'SHthermalemitters_n_radiators', 34: 'SHthermalemitters_n_tubes', 35: 'DHWbypassvalve_unknown_T', 36: 'DHWstoragetopvalve_unknown_T', 37: 'DHWcoldwaterrefill_unknown_T', 38: 'DHWstoragebottomvalve_unknown_T', 39: 'SHbypassvalve_unknown_T', 40: 'SHDHWreturnvalve_unknown_T', 41: 'DHWbypassvalve_unknown_m', 42: 'DHWstoragetopvalve_unknown_m', 43: 'DHWcoldwaterrefill_unknown_m', 44: 'DHWstoragebottomvalve_unknown_m', 45: 'SHbypassvalve_unknown_m', 46: 'SHDHWreturnvalve_unknown_m', 47: 'Delay_InitialCondition', 48: 'Delay1_InitialCondition', 49: 'Constant1_Value', 50: 'Delay6_InitialCondition', 51: 'Delay5_InitialCondition', 52: 'Switch3_Threshold', 53: 'Constant5_Value', 54: 'Constant6_Value', 55: 'Switch2_Threshold', 56: 'Delay_InitialCondition_o', 57: 'Delay_InitialCondition_k', 58: 'Constant7_Value', 59: 'Switch_Threshold', 60: 'Delay_InitialCondition_o4', 61: 'Switch4_Threshold', 62: 'Constant_Value', 63: 'Constant4_Value', 64: 'Switch1_Threshold', 65: 'Delay2_InitialCondition', 66: 'Delay7_InitialCondition', 67: 'Constant2_Value', 68: 'Delay_InitialCondition_j', 69: 'Delay_InitialCondition_l', 70: 'Delay_InitialCondition_jr', 71: 'Constant3_Value'}
    

    def _check_param_setter(func):
        def new_func(self, *args, **kwargs):
            if self._was_called:
                raise MemoryError(f"'{func.__name__}': The value of a parameter cannot be changed after a first call to `run_physical_model`.")
            return func(self, *args, **kwargs)
        return new_func

    def clean_disk_copy(self):     
        """
        Remove the compiled file associated with this instance (*.so library). 
        Will not cause a crash since corresponding library is already loaded in memory.
        """ 
        try:  
            self._lib_path_copy.unlink()
        except FileNotFoundError:
            pass
        else:
            self._tmp_dir.cleanup()
            del self._tmp_dir

    def __init__(self, \
                 time_step: int,
                 hide_outputs: bool=False):

        self._was_called = False
        self._hide_outputs = hide_outputs

        if self._hide_outputs:
            try:
                from wurlitzer import pipes
            except ImportError as e:
                raise ImportError("package 'wurlitzer' (pip, conda) is needed to hive textual outputs/logs of the physical model (argument `hide_outputs=True`)")
            else:
                self._pipes = pipes
                print("hide_outputs=True may increase slightly the physical model running time.")

        # *.so library is copied since two instances with same library file name would share the same memory space
        self._tmp_dir = TemporaryDirectory() # safer than raw "/tmp" and Windows compatible
        self._lib_path_copy = Path(self._tmp_dir.name) / f"AI4DHN_tmpLibCopy_{self.lib_path.stem}_{id(self)}.so"
        copy2(self.lib_path, self._lib_path_copy)
        self._lib = cdll.LoadLibrary(self._lib_path_copy)    

        self._lib.initialize.argtypes = (POINTER(c_int), )
        self._lib._get_SimulationTime.argtypes = (POINTER(c_double), )
        
        self._initialize(time_step) 

        

# =======
# ARG TYPES
# =======

# -- U --

        self._lib.getU_m_prim.argtypes = (POINTER(c_double), )
        self._lib.setU_m_prim.argtypes = (POINTER(c_double), )
    
        self._lib.getU_T_prim_in.argtypes = (POINTER(c_double), )
        self._lib.setU_T_prim_in.argtypes = (POINTER(c_double), )
    
        self._lib.getU_m_SH_dir.argtypes = (POINTER(c_double), )
        self._lib.setU_m_SH_dir.argtypes = (POINTER(c_double), )
    
        self._lib.getU_m_SH_3V.argtypes = (POINTER(c_double), )
        self._lib.setU_m_SH_3V.argtypes = (POINTER(c_double), )
    
        self._lib.getU_m_DHW_sec.argtypes = (POINTER(c_double), )
        self._lib.setU_m_DHW_sec.argtypes = (POINTER(c_double), )
    
        self._lib.getU_m_DHW_w.argtypes = (POINTER(c_double), )
        self._lib.setU_m_DHW_w.argtypes = (POINTER(c_double), )
    
        self._lib.getU_m_DHW_recirc.argtypes = (POINTER(c_double), )
        self._lib.setU_m_DHW_recirc.argtypes = (POINTER(c_double), )
    
        self._lib.getU_T_cold.argtypes = (POINTER(c_double), )
        self._lib.setU_T_cold.argtypes = (POINTER(c_double), )
    
        self._lib.getU_m_DHW_dir.argtypes = (POINTER(c_double), )
        self._lib.setU_m_DHW_dir.argtypes = (POINTER(c_double), )
    
        self._lib.getU_m_DHW_3V.argtypes = (POINTER(c_double), )
        self._lib.setU_m_DHW_3V.argtypes = (POINTER(c_double), )
    # -- P --

        self._lib.getP_DHWheatexchanger_A.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWheatexchanger_A.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Primaryheatexchanger_A.argtypes = (POINTER(c_double), )
        self._lib.setP_Primaryheatexchanger_A.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWreturnpipe_D.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWreturnpipe_D.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWstorage_D.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWstorage_D.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWsupplypipe_D.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWsupplypipe_D.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHreturnpipe_D.argtypes = (POINTER(c_double), )
        self._lib.setP_SHreturnpipe_D.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHsupplypipe_D.argtypes = (POINTER(c_double), )
        self._lib.setP_SHsupplypipe_D.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHthermalemitters_D.argtypes = (POINTER(c_double), )
        self._lib.setP_SHthermalemitters_D.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWstorage_H.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWstorage_H.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWreturnpipe_L.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWreturnpipe_L.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWsupplypipe_L.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWsupplypipe_L.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHreturnpipe_L.argtypes = (POINTER(c_double), )
        self._lib.setP_SHreturnpipe_L.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHsupplypipe_L.argtypes = (POINTER(c_double), )
        self._lib.setP_SHsupplypipe_L.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHthermalemitters_L.argtypes = (POINTER(c_double), )
        self._lib.setP_SHthermalemitters_L.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHthermalemitters_T_air.argtypes = (POINTER(c_double), )
        self._lib.setP_SHthermalemitters_T_air.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWstorage_T_amb.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWstorage_T_amb.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWreturnpipe_T_duct.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWreturnpipe_T_duct.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWsupplypipe_T_duct.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWsupplypipe_T_duct.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHreturnpipe_T_duct.argtypes = (POINTER(c_double), )
        self._lib.setP_SHreturnpipe_T_duct.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHsupplypipe_T_duct.argtypes = (POINTER(c_double), )
        self._lib.setP_SHsupplypipe_T_duct.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWstorage_U.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWstorage_U.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHthermalemitters_U.argtypes = (POINTER(c_double), )
        self._lib.setP_SHthermalemitters_U.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWheatexchanger_U.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWheatexchanger_U.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Primaryheatexchanger_U.argtypes = (POINTER(c_double), )
        self._lib.setP_Primaryheatexchanger_U.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWstorage_V_min.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWstorage_V_min.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWstorage_V_var.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWstorage_V_var.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWstorage_eps.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWstorage_eps.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWreturnpipe_m_min.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWreturnpipe_m_min.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWsupplypipe_m_min.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWsupplypipe_m_min.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHreturnpipe_m_min.argtypes = (POINTER(c_double), )
        self._lib.setP_SHreturnpipe_m_min.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHsupplypipe_m_min.argtypes = (POINTER(c_double), )
        self._lib.setP_SHsupplypipe_m_min.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHthermalemitters_m_min.argtypes = (POINTER(c_double), )
        self._lib.setP_SHthermalemitters_m_min.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWstorage_n.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWstorage_n.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHthermalemitters_n_radiators.argtypes = (POINTER(c_double), )
        self._lib.setP_SHthermalemitters_n_radiators.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHthermalemitters_n_tubes.argtypes = (POINTER(c_double), )
        self._lib.setP_SHthermalemitters_n_tubes.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWbypassvalve_unknown_T.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWbypassvalve_unknown_T.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWstoragetopvalve_unknown_T.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWstoragetopvalve_unknown_T.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWcoldwaterrefill_unknown_T.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWcoldwaterrefill_unknown_T.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWstoragebottomvalve_unknown_T.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWstoragebottomvalve_unknown_T.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHbypassvalve_unknown_T.argtypes = (POINTER(c_double), )
        self._lib.setP_SHbypassvalve_unknown_T.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHDHWreturnvalve_unknown_T.argtypes = (POINTER(c_double), )
        self._lib.setP_SHDHWreturnvalve_unknown_T.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWbypassvalve_unknown_m.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWbypassvalve_unknown_m.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWstoragetopvalve_unknown_m.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWstoragetopvalve_unknown_m.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWcoldwaterrefill_unknown_m.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWcoldwaterrefill_unknown_m.argtypes = (POINTER(c_double), )
    
        self._lib.getP_DHWstoragebottomvalve_unknown_m.argtypes = (POINTER(c_double), )
        self._lib.setP_DHWstoragebottomvalve_unknown_m.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHbypassvalve_unknown_m.argtypes = (POINTER(c_double), )
        self._lib.setP_SHbypassvalve_unknown_m.argtypes = (POINTER(c_double), )
    
        self._lib.getP_SHDHWreturnvalve_unknown_m.argtypes = (POINTER(c_double), )
        self._lib.setP_SHDHWreturnvalve_unknown_m.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Delay_InitialCondition.argtypes = (POINTER(c_double), )
        self._lib.setP_Delay_InitialCondition.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Delay1_InitialCondition.argtypes = (POINTER(c_double), )
        self._lib.setP_Delay1_InitialCondition.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Constant1_Value.argtypes = (POINTER(c_double), )
        self._lib.setP_Constant1_Value.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Delay6_InitialCondition.argtypes = (POINTER(c_double), )
        self._lib.setP_Delay6_InitialCondition.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Delay5_InitialCondition.argtypes = (POINTER(c_double), )
        self._lib.setP_Delay5_InitialCondition.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Switch3_Threshold.argtypes = (POINTER(c_double), )
        self._lib.setP_Switch3_Threshold.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Constant5_Value.argtypes = (POINTER(c_double), )
        self._lib.setP_Constant5_Value.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Constant6_Value.argtypes = (POINTER(c_double), )
        self._lib.setP_Constant6_Value.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Switch2_Threshold.argtypes = (POINTER(c_double), )
        self._lib.setP_Switch2_Threshold.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Delay_InitialCondition_o.argtypes = (POINTER(c_double), )
        self._lib.setP_Delay_InitialCondition_o.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Delay_InitialCondition_k.argtypes = (POINTER(c_double), )
        self._lib.setP_Delay_InitialCondition_k.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Constant7_Value.argtypes = (POINTER(c_double), )
        self._lib.setP_Constant7_Value.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Switch_Threshold.argtypes = (POINTER(c_double), )
        self._lib.setP_Switch_Threshold.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Delay_InitialCondition_o4.argtypes = (POINTER(c_double), )
        self._lib.setP_Delay_InitialCondition_o4.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Switch4_Threshold.argtypes = (POINTER(c_double), )
        self._lib.setP_Switch4_Threshold.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Constant_Value.argtypes = (POINTER(c_double), )
        self._lib.setP_Constant_Value.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Constant4_Value.argtypes = (POINTER(c_double), )
        self._lib.setP_Constant4_Value.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Switch1_Threshold.argtypes = (POINTER(c_double), )
        self._lib.setP_Switch1_Threshold.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Delay2_InitialCondition.argtypes = (POINTER(c_double), )
        self._lib.setP_Delay2_InitialCondition.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Delay7_InitialCondition.argtypes = (POINTER(c_double), )
        self._lib.setP_Delay7_InitialCondition.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Constant2_Value.argtypes = (POINTER(c_double), )
        self._lib.setP_Constant2_Value.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Delay_InitialCondition_j.argtypes = (POINTER(c_double), )
        self._lib.setP_Delay_InitialCondition_j.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Delay_InitialCondition_l.argtypes = (POINTER(c_double), )
        self._lib.setP_Delay_InitialCondition_l.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Delay_InitialCondition_jr.argtypes = (POINTER(c_double), )
        self._lib.setP_Delay_InitialCondition_jr.argtypes = (POINTER(c_double), )
    
        self._lib.getP_Constant3_Value.argtypes = (POINTER(c_double), )
        self._lib.setP_Constant3_Value.argtypes = (POINTER(c_double), )
    

        if Interface._first_instance:
            print("""Successful interfacing with C-code. Please use the following methods:
    - `getP_[...]`: returns the current value of a parameter
    - `getP_as_dict`: returns all parameter values.
    - `setP_[...]`: sets a new value for a parameter
        Must be called before `run_physical_model`.
    - `setP_from_dict`: sets new values for some parameters.
        Must be called before `run_physical_model`.
    - `run_physical_model`: runs the physical model given specified physical inputs. Returns corresponding outputs.
            """)
            Interface._first_instance = False


# these methods makes the interface with the C-code


# =======
# GETTERS
# =======

# -- U --

    def _getU_m_prim(self):
        """Get current value for the scalar `m_prim`.

        Returns
        -------
        float
        """
        m_prim = c_double()
        self._lib.getU_m_prim(byref(m_prim))
        return m_prim.value
    
    def _getU_T_prim_in(self):
        """Get current value for the scalar `T_prim_in`.

        Returns
        -------
        float
        """
        T_prim_in = c_double()
        self._lib.getU_T_prim_in(byref(T_prim_in))
        return T_prim_in.value
    
    def _getU_m_SH_dir(self):
        """Get current value for the scalar `m_SH_dir`.

        Returns
        -------
        float
        """
        m_SH_dir = c_double()
        self._lib.getU_m_SH_dir(byref(m_SH_dir))
        return m_SH_dir.value
    
    def _getU_m_SH_3V(self):
        """Get current value for the scalar `m_SH_3V`.

        Returns
        -------
        float
        """
        m_SH_3V = c_double()
        self._lib.getU_m_SH_3V(byref(m_SH_3V))
        return m_SH_3V.value
    
    def _getU_m_DHW_sec(self):
        """Get current value for the scalar `m_DHW_sec`.

        Returns
        -------
        float
        """
        m_DHW_sec = c_double()
        self._lib.getU_m_DHW_sec(byref(m_DHW_sec))
        return m_DHW_sec.value
    
    def _getU_m_DHW_w(self):
        """Get current value for the scalar `m_DHW_w`.

        Returns
        -------
        float
        """
        m_DHW_w = c_double()
        self._lib.getU_m_DHW_w(byref(m_DHW_w))
        return m_DHW_w.value
    
    def _getU_m_DHW_recirc(self):
        """Get current value for the scalar `m_DHW_recirc`.

        Returns
        -------
        float
        """
        m_DHW_recirc = c_double()
        self._lib.getU_m_DHW_recirc(byref(m_DHW_recirc))
        return m_DHW_recirc.value
    
    def _getU_T_cold(self):
        """Get current value for the scalar `T_cold`.

        Returns
        -------
        float
        """
        T_cold = c_double()
        self._lib.getU_T_cold(byref(T_cold))
        return T_cold.value
    
    def _getU_m_DHW_dir(self):
        """Get current value for the scalar `m_DHW_dir`.

        Returns
        -------
        float
        """
        m_DHW_dir = c_double()
        self._lib.getU_m_DHW_dir(byref(m_DHW_dir))
        return m_DHW_dir.value
    
    def _getU_m_DHW_3V(self):
        """Get current value for the scalar `m_DHW_3V`.

        Returns
        -------
        float
        """
        m_DHW_3V = c_double()
        self._lib.getU_m_DHW_3V(byref(m_DHW_3V))
        return m_DHW_3V.value
    
    def _getU(self):
        res = tuple(func() for func in [self._getU_m_prim, self._getU_T_prim_in, self._getU_m_SH_dir, self._getU_m_SH_3V, self._getU_m_DHW_sec, self._getU_m_DHW_w, self._getU_m_DHW_recirc, self._getU_T_cold, self._getU_m_DHW_dir, self._getU_m_DHW_3V])
        return res
    # -- Y --

    def _getY_T_sec_in(self):
        """Get current value for the scalar `T_sec_in`.

        Returns
        -------
        float
        """
        T_sec_in = c_double()
        self._lib.getY_T_sec_in(byref(T_sec_in))
        return T_sec_in.value
    
    def _getY_T_DHW_out(self):
        """Get current value for the scalar `T_DHW_out`.

        Returns
        -------
        float
        """
        T_DHW_out = c_double()
        self._lib.getY_T_DHW_out(byref(T_DHW_out))
        return T_DHW_out.value
    
    def _getY_T_out(self):
        """Get current value for the scalar `T_out`.

        Returns
        -------
        float
        """
        T_out = c_double()
        self._lib.getY_T_out(byref(T_out))
        return T_out.value
    
    def _getY_T_DHW_sec_out(self):
        """Get current value for the scalar `T_DHW_sec_out`.

        Returns
        -------
        float
        """
        T_DHW_sec_out = c_double()
        self._lib.getY_T_DHW_sec_out(byref(T_DHW_sec_out))
        return T_DHW_sec_out.value
    
    def _getY_T_DHW_sec_in(self):
        """Get current value for the scalar `T_DHW_sec_in`.

        Returns
        -------
        float
        """
        T_DHW_sec_in = c_double()
        self._lib.getY_T_DHW_sec_in(byref(T_DHW_sec_in))
        return T_DHW_sec_in.value
    
    def _getY_T_DHW_prim_in(self):
        """Get current value for the scalar `T_DHW_prim_in`.

        Returns
        -------
        float
        """
        T_DHW_prim_in = c_double()
        self._lib.getY_T_DHW_prim_in(byref(T_DHW_prim_in))
        return T_DHW_prim_in.value
    
    def _getY_T_DHW_prim_out(self):
        """Get current value for the scalar `T_DHW_prim_out`.

        Returns
        -------
        float
        """
        T_DHW_prim_out = c_double()
        self._lib.getY_T_DHW_prim_out(byref(T_DHW_prim_out))
        return T_DHW_prim_out.value
    
    def _getY_T_SH_out(self):
        """Get current value for the scalar `T_SH_out`.

        Returns
        -------
        float
        """
        T_SH_out = c_double()
        self._lib.getY_T_SH_out(byref(T_SH_out))
        return T_SH_out.value
    
    def _getY_T_SH_in(self):
        """Get current value for the scalar `T_SH_in`.

        Returns
        -------
        float
        """
        T_SH_in = c_double()
        self._lib.getY_T_SH_in(byref(T_SH_in))
        return T_SH_in.value
    
    def _getY_T_prim_out(self):
        """Get current value for the scalar `T_prim_out`.

        Returns
        -------
        float
        """
        T_prim_out = c_double()
        self._lib.getY_T_prim_out(byref(T_prim_out))
        return T_prim_out.value
    
    def _getY_T_sec_out(self):
        """Get current value for the scalar `T_sec_out`.

        Returns
        -------
        float
        """
        T_sec_out = c_double()
        self._lib.getY_T_sec_out(byref(T_sec_out))
        return T_sec_out.value
    
    def _getY_T_SH_emitter_out(self):
        """Get current value for the scalar `T_SH_emitter_out`.

        Returns
        -------
        float
        """
        T_SH_emitter_out = c_double()
        self._lib.getY_T_SH_emitter_out(byref(T_SH_emitter_out))
        return T_SH_emitter_out.value
    
    def _getY_T_stor_n(self):
        """Get current value for the scalar `T_stor_n`.

        Returns
        -------
        float
        """
        T_stor_n = c_double()
        self._lib.getY_T_stor_n(byref(T_stor_n))
        return T_stor_n.value
    
    def _getY_Q_SH(self):
        """Get current value for the scalar `Q_SH`.

        Returns
        -------
        float
        """
        Q_SH = c_double()
        self._lib.getY_Q_SH(byref(Q_SH))
        return Q_SH.value
    
    def _getY_Q_primary_HX(self):
        """Get current value for the scalar `Q_primary_HX`.

        Returns
        -------
        float
        """
        Q_primary_HX = c_double()
        self._lib.getY_Q_primary_HX(byref(Q_primary_HX))
        return Q_primary_HX.value
    
    def _getY_Q_DHW_HX(self):
        """Get current value for the scalar `Q_DHW_HX`.

        Returns
        -------
        float
        """
        Q_DHW_HX = c_double()
        self._lib.getY_Q_DHW_HX(byref(Q_DHW_HX))
        return Q_DHW_HX.value
    
    def _getY_m_DHW(self):
        """Get current value for the scalar `m_DHW`.

        Returns
        -------
        float
        """
        m_DHW = c_double()
        self._lib.getY_m_DHW(byref(m_DHW))
        return m_DHW.value
    
    def _getY_Q_SH_supply(self):
        """Get current value for the scalar `Q_SH_supply`.

        Returns
        -------
        float
        """
        Q_SH_supply = c_double()
        self._lib.getY_Q_SH_supply(byref(Q_SH_supply))
        return Q_SH_supply.value
    
    def _getY_Q_SH_return(self):
        """Get current value for the scalar `Q_SH_return`.

        Returns
        -------
        float
        """
        Q_SH_return = c_double()
        self._lib.getY_Q_SH_return(byref(Q_SH_return))
        return Q_SH_return.value
    
    def _getY_T_stor_out(self):
        """Get current value for the scalar `T_stor_out`.

        Returns
        -------
        float
        """
        T_stor_out = c_double()
        self._lib.getY_T_stor_out(byref(T_stor_out))
        return T_stor_out.value
    
    def _getY_T_stor_avg(self):
        """Get current value for the scalar `T_stor_avg`.

        Returns
        -------
        float
        """
        T_stor_avg = c_double()
        self._lib.getY_T_stor_avg(byref(T_stor_avg))
        return T_stor_avg.value
    
    def _getY_T_stor_mid(self):
        """Get current value for the scalar `T_stor_mid`.

        Returns
        -------
        float
        """
        T_stor_mid = c_double()
        self._lib.getY_T_stor_mid(byref(T_stor_mid))
        return T_stor_mid.value
    
    def _getY_T_stor_std(self):
        """Get current value for the scalar `T_stor_std`.

        Returns
        -------
        float
        """
        T_stor_std = c_double()
        self._lib.getY_T_stor_std(byref(T_stor_std))
        return T_stor_std.value
    
    def _getY_T_stor_half(self):
        """Get current value for the scalar `T_stor_half`.

        Returns
        -------
        float
        """
        T_stor_half = c_double()
        self._lib.getY_T_stor_half(byref(T_stor_half))
        return T_stor_half.value
    
    def _getY_T_stor_1(self):
        """Get current value for the scalar `T_stor_1`.

        Returns
        -------
        float
        """
        T_stor_1 = c_double()
        self._lib.getY_T_stor_1(byref(T_stor_1))
        return T_stor_1.value
    
    def _getY_m_DHW_prim(self):
        """Get current value for the scalar `m_DHW_prim`.

        Returns
        -------
        float
        """
        m_DHW_prim = c_double()
        self._lib.getY_m_DHW_prim(byref(m_DHW_prim))
        return m_DHW_prim.value
    
    def _getY_m_sec(self):
        """Get current value for the scalar `m_sec`.

        Returns
        -------
        float
        """
        m_sec = c_double()
        self._lib.getY_m_sec(byref(m_sec))
        return m_sec.value
    
    def _getY_m_SH(self):
        """Get current value for the scalar `m_SH`.

        Returns
        -------
        float
        """
        m_SH = c_double()
        self._lib.getY_m_SH(byref(m_SH))
        return m_SH.value
    
    def _getY_Q_DHW_supply(self):
        """Get current value for the scalar `Q_DHW_supply`.

        Returns
        -------
        float
        """
        Q_DHW_supply = c_double()
        self._lib.getY_Q_DHW_supply(byref(Q_DHW_supply))
        return Q_DHW_supply.value
    
    def _getY_Q_DHW_return(self):
        """Get current value for the scalar `Q_DHW_return`.

        Returns
        -------
        float
        """
        Q_DHW_return = c_double()
        self._lib.getY_Q_DHW_return(byref(Q_DHW_return))
        return Q_DHW_return.value
    
    def _getY_efficiency_primary_HX(self):
        """Get current value for the scalar `efficiency_primary_HX`.

        Returns
        -------
        float
        """
        efficiency_primary_HX = c_double()
        self._lib.getY_efficiency_primary_HX(byref(efficiency_primary_HX))
        return efficiency_primary_HX.value
    
    def _getY_efficiency_DHW_HX(self):
        """Get current value for the scalar `efficiency_DHW_HX`.

        Returns
        -------
        float
        """
        efficiency_DHW_HX = c_double()
        self._lib.getY_efficiency_DHW_HX(byref(efficiency_DHW_HX))
        return efficiency_DHW_HX.value
    
    def _getY_T_DHW_in(self):
        """Get current value for the scalar `T_DHW_in`.

        Returns
        -------
        float
        """
        T_DHW_in = c_double()
        self._lib.getY_T_DHW_in(byref(T_DHW_in))
        return T_DHW_in.value
    
    def _getY_T_SH_emitter_in(self):
        """Get current value for the scalar `T_SH_emitter_in`.

        Returns
        -------
        float
        """
        T_SH_emitter_in = c_double()
        self._lib.getY_T_SH_emitter_in(byref(T_SH_emitter_in))
        return T_SH_emitter_in.value
    
    def _getY_T_stor_in(self):
        """Get current value for the scalar `T_stor_in`.

        Returns
        -------
        float
        """
        T_stor_in = c_double()
        self._lib.getY_T_stor_in(byref(T_stor_in))
        return T_stor_in.value
    
    def _getY_m_DHW_stor(self):
        """Get current value for the scalar `m_DHW_stor`.

        Returns
        -------
        float
        """
        m_DHW_stor = c_double()
        self._lib.getY_m_DHW_stor(byref(m_DHW_stor))
        return m_DHW_stor.value
    
    def _getY(self):
        res = tuple(func() for func in [self._getY_T_sec_in, self._getY_T_DHW_out, self._getY_T_out, self._getY_T_DHW_sec_out, self._getY_T_DHW_sec_in, self._getY_T_DHW_prim_in, self._getY_T_DHW_prim_out, self._getY_T_SH_out, self._getY_T_SH_in, self._getY_T_prim_out, self._getY_T_sec_out, self._getY_T_SH_emitter_out, self._getY_T_stor_n, self._getY_Q_SH, self._getY_Q_primary_HX, self._getY_Q_DHW_HX, self._getY_m_DHW, self._getY_Q_SH_supply, self._getY_Q_SH_return, self._getY_T_stor_out, self._getY_T_stor_avg, self._getY_T_stor_mid, self._getY_T_stor_std, self._getY_T_stor_half, self._getY_T_stor_1, self._getY_m_DHW_prim, self._getY_m_sec, self._getY_m_SH, self._getY_Q_DHW_supply, self._getY_Q_DHW_return, self._getY_efficiency_primary_HX, self._getY_efficiency_DHW_HX, self._getY_T_DHW_in, self._getY_T_SH_emitter_in, self._getY_T_stor_in, self._getY_m_DHW_stor])
        return res
    # -- P --

    def getP_DHWheatexchanger_A(self):
        """Get current value for the scalar `DHWheatexchanger_A`.

        Returns
        -------
        float
        """
        DHWheatexchanger_A = c_double()
        self._lib.getP_DHWheatexchanger_A(byref(DHWheatexchanger_A))
        return DHWheatexchanger_A.value
    
    def getP_Primaryheatexchanger_A(self):
        """Get current value for the scalar `Primaryheatexchanger_A`.

        Returns
        -------
        float
        """
        Primaryheatexchanger_A = c_double()
        self._lib.getP_Primaryheatexchanger_A(byref(Primaryheatexchanger_A))
        return Primaryheatexchanger_A.value
    
    def getP_DHWreturnpipe_D(self):
        """Get current value for the scalar `DHWreturnpipe_D`.

        Returns
        -------
        float
        """
        DHWreturnpipe_D = c_double()
        self._lib.getP_DHWreturnpipe_D(byref(DHWreturnpipe_D))
        return DHWreturnpipe_D.value
    
    def getP_DHWstorage_D(self):
        """Get current value for the scalar `DHWstorage_D`.

        Returns
        -------
        float
        """
        DHWstorage_D = c_double()
        self._lib.getP_DHWstorage_D(byref(DHWstorage_D))
        return DHWstorage_D.value
    
    def getP_DHWsupplypipe_D(self):
        """Get current value for the scalar `DHWsupplypipe_D`.

        Returns
        -------
        float
        """
        DHWsupplypipe_D = c_double()
        self._lib.getP_DHWsupplypipe_D(byref(DHWsupplypipe_D))
        return DHWsupplypipe_D.value
    
    def getP_SHreturnpipe_D(self):
        """Get current value for the scalar `SHreturnpipe_D`.

        Returns
        -------
        float
        """
        SHreturnpipe_D = c_double()
        self._lib.getP_SHreturnpipe_D(byref(SHreturnpipe_D))
        return SHreturnpipe_D.value
    
    def getP_SHsupplypipe_D(self):
        """Get current value for the scalar `SHsupplypipe_D`.

        Returns
        -------
        float
        """
        SHsupplypipe_D = c_double()
        self._lib.getP_SHsupplypipe_D(byref(SHsupplypipe_D))
        return SHsupplypipe_D.value
    
    def getP_SHthermalemitters_D(self):
        """Get current value for the scalar `SHthermalemitters_D`.

        Returns
        -------
        float
        """
        SHthermalemitters_D = c_double()
        self._lib.getP_SHthermalemitters_D(byref(SHthermalemitters_D))
        return SHthermalemitters_D.value
    
    def getP_DHWstorage_H(self):
        """Get current value for the scalar `DHWstorage_H`.

        Returns
        -------
        float
        """
        DHWstorage_H = c_double()
        self._lib.getP_DHWstorage_H(byref(DHWstorage_H))
        return DHWstorage_H.value
    
    def getP_DHWreturnpipe_L(self):
        """Get current value for the scalar `DHWreturnpipe_L`.

        Returns
        -------
        float
        """
        DHWreturnpipe_L = c_double()
        self._lib.getP_DHWreturnpipe_L(byref(DHWreturnpipe_L))
        return DHWreturnpipe_L.value
    
    def getP_DHWsupplypipe_L(self):
        """Get current value for the scalar `DHWsupplypipe_L`.

        Returns
        -------
        float
        """
        DHWsupplypipe_L = c_double()
        self._lib.getP_DHWsupplypipe_L(byref(DHWsupplypipe_L))
        return DHWsupplypipe_L.value
    
    def getP_SHreturnpipe_L(self):
        """Get current value for the scalar `SHreturnpipe_L`.

        Returns
        -------
        float
        """
        SHreturnpipe_L = c_double()
        self._lib.getP_SHreturnpipe_L(byref(SHreturnpipe_L))
        return SHreturnpipe_L.value
    
    def getP_SHsupplypipe_L(self):
        """Get current value for the scalar `SHsupplypipe_L`.

        Returns
        -------
        float
        """
        SHsupplypipe_L = c_double()
        self._lib.getP_SHsupplypipe_L(byref(SHsupplypipe_L))
        return SHsupplypipe_L.value
    
    def getP_SHthermalemitters_L(self):
        """Get current value for the scalar `SHthermalemitters_L`.

        Returns
        -------
        float
        """
        SHthermalemitters_L = c_double()
        self._lib.getP_SHthermalemitters_L(byref(SHthermalemitters_L))
        return SHthermalemitters_L.value
    
    def getP_SHthermalemitters_T_air(self):
        """Get current value for the scalar `SHthermalemitters_T_air`.

        Returns
        -------
        float
        """
        SHthermalemitters_T_air = c_double()
        self._lib.getP_SHthermalemitters_T_air(byref(SHthermalemitters_T_air))
        return SHthermalemitters_T_air.value
    
    def getP_DHWstorage_T_amb(self):
        """Get current value for the scalar `DHWstorage_T_amb`.

        Returns
        -------
        float
        """
        DHWstorage_T_amb = c_double()
        self._lib.getP_DHWstorage_T_amb(byref(DHWstorage_T_amb))
        return DHWstorage_T_amb.value
    
    def getP_DHWreturnpipe_T_duct(self):
        """Get current value for the scalar `DHWreturnpipe_T_duct`.

        Returns
        -------
        float
        """
        DHWreturnpipe_T_duct = c_double()
        self._lib.getP_DHWreturnpipe_T_duct(byref(DHWreturnpipe_T_duct))
        return DHWreturnpipe_T_duct.value
    
    def getP_DHWsupplypipe_T_duct(self):
        """Get current value for the scalar `DHWsupplypipe_T_duct`.

        Returns
        -------
        float
        """
        DHWsupplypipe_T_duct = c_double()
        self._lib.getP_DHWsupplypipe_T_duct(byref(DHWsupplypipe_T_duct))
        return DHWsupplypipe_T_duct.value
    
    def getP_SHreturnpipe_T_duct(self):
        """Get current value for the scalar `SHreturnpipe_T_duct`.

        Returns
        -------
        float
        """
        SHreturnpipe_T_duct = c_double()
        self._lib.getP_SHreturnpipe_T_duct(byref(SHreturnpipe_T_duct))
        return SHreturnpipe_T_duct.value
    
    def getP_SHsupplypipe_T_duct(self):
        """Get current value for the scalar `SHsupplypipe_T_duct`.

        Returns
        -------
        float
        """
        SHsupplypipe_T_duct = c_double()
        self._lib.getP_SHsupplypipe_T_duct(byref(SHsupplypipe_T_duct))
        return SHsupplypipe_T_duct.value
    
    def getP_DHWstorage_U(self):
        """Get current value for the scalar `DHWstorage_U`.

        Returns
        -------
        float
        """
        DHWstorage_U = c_double()
        self._lib.getP_DHWstorage_U(byref(DHWstorage_U))
        return DHWstorage_U.value
    
    def getP_SHthermalemitters_U(self):
        """Get current value for the scalar `SHthermalemitters_U`.

        Returns
        -------
        float
        """
        SHthermalemitters_U = c_double()
        self._lib.getP_SHthermalemitters_U(byref(SHthermalemitters_U))
        return SHthermalemitters_U.value
    
    def getP_DHWheatexchanger_U(self):
        """Get current value for the scalar `DHWheatexchanger_U`.

        Returns
        -------
        float
        """
        DHWheatexchanger_U = c_double()
        self._lib.getP_DHWheatexchanger_U(byref(DHWheatexchanger_U))
        return DHWheatexchanger_U.value
    
    def getP_Primaryheatexchanger_U(self):
        """Get current value for the scalar `Primaryheatexchanger_U`.

        Returns
        -------
        float
        """
        Primaryheatexchanger_U = c_double()
        self._lib.getP_Primaryheatexchanger_U(byref(Primaryheatexchanger_U))
        return Primaryheatexchanger_U.value
    
    def getP_DHWstorage_V_min(self):
        """Get current value for the scalar `DHWstorage_V_min`.

        Returns
        -------
        float
        """
        DHWstorage_V_min = c_double()
        self._lib.getP_DHWstorage_V_min(byref(DHWstorage_V_min))
        return DHWstorage_V_min.value
    
    def getP_DHWstorage_V_var(self):
        """Get current value for the scalar `DHWstorage_V_var`.

        Returns
        -------
        float
        """
        DHWstorage_V_var = c_double()
        self._lib.getP_DHWstorage_V_var(byref(DHWstorage_V_var))
        return DHWstorage_V_var.value
    
    def getP_DHWstorage_eps(self):
        """Get current value for the scalar `DHWstorage_eps`.

        Returns
        -------
        float
        """
        DHWstorage_eps = c_double()
        self._lib.getP_DHWstorage_eps(byref(DHWstorage_eps))
        return DHWstorage_eps.value
    
    def getP_DHWreturnpipe_m_min(self):
        """Get current value for the scalar `DHWreturnpipe_m_min`.

        Returns
        -------
        float
        """
        DHWreturnpipe_m_min = c_double()
        self._lib.getP_DHWreturnpipe_m_min(byref(DHWreturnpipe_m_min))
        return DHWreturnpipe_m_min.value
    
    def getP_DHWsupplypipe_m_min(self):
        """Get current value for the scalar `DHWsupplypipe_m_min`.

        Returns
        -------
        float
        """
        DHWsupplypipe_m_min = c_double()
        self._lib.getP_DHWsupplypipe_m_min(byref(DHWsupplypipe_m_min))
        return DHWsupplypipe_m_min.value
    
    def getP_SHreturnpipe_m_min(self):
        """Get current value for the scalar `SHreturnpipe_m_min`.

        Returns
        -------
        float
        """
        SHreturnpipe_m_min = c_double()
        self._lib.getP_SHreturnpipe_m_min(byref(SHreturnpipe_m_min))
        return SHreturnpipe_m_min.value
    
    def getP_SHsupplypipe_m_min(self):
        """Get current value for the scalar `SHsupplypipe_m_min`.

        Returns
        -------
        float
        """
        SHsupplypipe_m_min = c_double()
        self._lib.getP_SHsupplypipe_m_min(byref(SHsupplypipe_m_min))
        return SHsupplypipe_m_min.value
    
    def getP_SHthermalemitters_m_min(self):
        """Get current value for the scalar `SHthermalemitters_m_min`.

        Returns
        -------
        float
        """
        SHthermalemitters_m_min = c_double()
        self._lib.getP_SHthermalemitters_m_min(byref(SHthermalemitters_m_min))
        return SHthermalemitters_m_min.value
    
    def getP_DHWstorage_n(self):
        """Get current value for the scalar `DHWstorage_n`.

        Returns
        -------
        float
        """
        DHWstorage_n = c_double()
        self._lib.getP_DHWstorage_n(byref(DHWstorage_n))
        return DHWstorage_n.value
    
    def getP_SHthermalemitters_n_radiators(self):
        """Get current value for the scalar `SHthermalemitters_n_radiators`.

        Returns
        -------
        float
        """
        SHthermalemitters_n_radiators = c_double()
        self._lib.getP_SHthermalemitters_n_radiators(byref(SHthermalemitters_n_radiators))
        return SHthermalemitters_n_radiators.value
    
    def getP_SHthermalemitters_n_tubes(self):
        """Get current value for the scalar `SHthermalemitters_n_tubes`.

        Returns
        -------
        float
        """
        SHthermalemitters_n_tubes = c_double()
        self._lib.getP_SHthermalemitters_n_tubes(byref(SHthermalemitters_n_tubes))
        return SHthermalemitters_n_tubes.value
    
    def getP_DHWbypassvalve_unknown_T(self):
        """Get current value for the scalar `DHWbypassvalve_unknown_T`.

        Returns
        -------
        float
        """
        DHWbypassvalve_unknown_T = c_double()
        self._lib.getP_DHWbypassvalve_unknown_T(byref(DHWbypassvalve_unknown_T))
        return DHWbypassvalve_unknown_T.value
    
    def getP_DHWstoragetopvalve_unknown_T(self):
        """Get current value for the scalar `DHWstoragetopvalve_unknown_T`.

        Returns
        -------
        float
        """
        DHWstoragetopvalve_unknown_T = c_double()
        self._lib.getP_DHWstoragetopvalve_unknown_T(byref(DHWstoragetopvalve_unknown_T))
        return DHWstoragetopvalve_unknown_T.value
    
    def getP_DHWcoldwaterrefill_unknown_T(self):
        """Get current value for the scalar `DHWcoldwaterrefill_unknown_T`.

        Returns
        -------
        float
        """
        DHWcoldwaterrefill_unknown_T = c_double()
        self._lib.getP_DHWcoldwaterrefill_unknown_T(byref(DHWcoldwaterrefill_unknown_T))
        return DHWcoldwaterrefill_unknown_T.value
    
    def getP_DHWstoragebottomvalve_unknown_T(self):
        """Get current value for the scalar `DHWstoragebottomvalve_unknown_T`.

        Returns
        -------
        float
        """
        DHWstoragebottomvalve_unknown_T = c_double()
        self._lib.getP_DHWstoragebottomvalve_unknown_T(byref(DHWstoragebottomvalve_unknown_T))
        return DHWstoragebottomvalve_unknown_T.value
    
    def getP_SHbypassvalve_unknown_T(self):
        """Get current value for the scalar `SHbypassvalve_unknown_T`.

        Returns
        -------
        float
        """
        SHbypassvalve_unknown_T = c_double()
        self._lib.getP_SHbypassvalve_unknown_T(byref(SHbypassvalve_unknown_T))
        return SHbypassvalve_unknown_T.value
    
    def getP_SHDHWreturnvalve_unknown_T(self):
        """Get current value for the scalar `SHDHWreturnvalve_unknown_T`.

        Returns
        -------
        float
        """
        SHDHWreturnvalve_unknown_T = c_double()
        self._lib.getP_SHDHWreturnvalve_unknown_T(byref(SHDHWreturnvalve_unknown_T))
        return SHDHWreturnvalve_unknown_T.value
    
    def getP_DHWbypassvalve_unknown_m(self):
        """Get current value for the scalar `DHWbypassvalve_unknown_m`.

        Returns
        -------
        float
        """
        DHWbypassvalve_unknown_m = c_double()
        self._lib.getP_DHWbypassvalve_unknown_m(byref(DHWbypassvalve_unknown_m))
        return DHWbypassvalve_unknown_m.value
    
    def getP_DHWstoragetopvalve_unknown_m(self):
        """Get current value for the scalar `DHWstoragetopvalve_unknown_m`.

        Returns
        -------
        float
        """
        DHWstoragetopvalve_unknown_m = c_double()
        self._lib.getP_DHWstoragetopvalve_unknown_m(byref(DHWstoragetopvalve_unknown_m))
        return DHWstoragetopvalve_unknown_m.value
    
    def getP_DHWcoldwaterrefill_unknown_m(self):
        """Get current value for the scalar `DHWcoldwaterrefill_unknown_m`.

        Returns
        -------
        float
        """
        DHWcoldwaterrefill_unknown_m = c_double()
        self._lib.getP_DHWcoldwaterrefill_unknown_m(byref(DHWcoldwaterrefill_unknown_m))
        return DHWcoldwaterrefill_unknown_m.value
    
    def getP_DHWstoragebottomvalve_unknown_m(self):
        """Get current value for the scalar `DHWstoragebottomvalve_unknown_m`.

        Returns
        -------
        float
        """
        DHWstoragebottomvalve_unknown_m = c_double()
        self._lib.getP_DHWstoragebottomvalve_unknown_m(byref(DHWstoragebottomvalve_unknown_m))
        return DHWstoragebottomvalve_unknown_m.value
    
    def getP_SHbypassvalve_unknown_m(self):
        """Get current value for the scalar `SHbypassvalve_unknown_m`.

        Returns
        -------
        float
        """
        SHbypassvalve_unknown_m = c_double()
        self._lib.getP_SHbypassvalve_unknown_m(byref(SHbypassvalve_unknown_m))
        return SHbypassvalve_unknown_m.value
    
    def getP_SHDHWreturnvalve_unknown_m(self):
        """Get current value for the scalar `SHDHWreturnvalve_unknown_m`.

        Returns
        -------
        float
        """
        SHDHWreturnvalve_unknown_m = c_double()
        self._lib.getP_SHDHWreturnvalve_unknown_m(byref(SHDHWreturnvalve_unknown_m))
        return SHDHWreturnvalve_unknown_m.value
    
    def getP_Delay_InitialCondition(self):
        """Get current value for the scalar `Delay_InitialCondition`.

        Returns
        -------
        float
        """
        Delay_InitialCondition = c_double()
        self._lib.getP_Delay_InitialCondition(byref(Delay_InitialCondition))
        return Delay_InitialCondition.value
    
    def getP_Delay1_InitialCondition(self):
        """Get current value for the scalar `Delay1_InitialCondition`.

        Returns
        -------
        float
        """
        Delay1_InitialCondition = c_double()
        self._lib.getP_Delay1_InitialCondition(byref(Delay1_InitialCondition))
        return Delay1_InitialCondition.value
    
    def getP_Constant1_Value(self):
        """Get current value for the scalar `Constant1_Value`.

        Returns
        -------
        float
        """
        Constant1_Value = c_double()
        self._lib.getP_Constant1_Value(byref(Constant1_Value))
        return Constant1_Value.value
    
    def getP_Delay6_InitialCondition(self):
        """Get current value for the scalar `Delay6_InitialCondition`.

        Returns
        -------
        float
        """
        Delay6_InitialCondition = c_double()
        self._lib.getP_Delay6_InitialCondition(byref(Delay6_InitialCondition))
        return Delay6_InitialCondition.value
    
    def getP_Delay5_InitialCondition(self):
        """Get current value for the scalar `Delay5_InitialCondition`.

        Returns
        -------
        float
        """
        Delay5_InitialCondition = c_double()
        self._lib.getP_Delay5_InitialCondition(byref(Delay5_InitialCondition))
        return Delay5_InitialCondition.value
    
    def getP_Switch3_Threshold(self):
        """Get current value for the scalar `Switch3_Threshold`.

        Returns
        -------
        float
        """
        Switch3_Threshold = c_double()
        self._lib.getP_Switch3_Threshold(byref(Switch3_Threshold))
        return Switch3_Threshold.value
    
    def getP_Constant5_Value(self):
        """Get current value for the scalar `Constant5_Value`.

        Returns
        -------
        float
        """
        Constant5_Value = c_double()
        self._lib.getP_Constant5_Value(byref(Constant5_Value))
        return Constant5_Value.value
    
    def getP_Constant6_Value(self):
        """Get current value for the scalar `Constant6_Value`.

        Returns
        -------
        float
        """
        Constant6_Value = c_double()
        self._lib.getP_Constant6_Value(byref(Constant6_Value))
        return Constant6_Value.value
    
    def getP_Switch2_Threshold(self):
        """Get current value for the scalar `Switch2_Threshold`.

        Returns
        -------
        float
        """
        Switch2_Threshold = c_double()
        self._lib.getP_Switch2_Threshold(byref(Switch2_Threshold))
        return Switch2_Threshold.value
    
    def getP_Delay_InitialCondition_o(self):
        """Get current value for the scalar `Delay_InitialCondition_o`.

        Returns
        -------
        float
        """
        Delay_InitialCondition_o = c_double()
        self._lib.getP_Delay_InitialCondition_o(byref(Delay_InitialCondition_o))
        return Delay_InitialCondition_o.value
    
    def getP_Delay_InitialCondition_k(self):
        """Get current value for the scalar `Delay_InitialCondition_k`.

        Returns
        -------
        float
        """
        Delay_InitialCondition_k = c_double()
        self._lib.getP_Delay_InitialCondition_k(byref(Delay_InitialCondition_k))
        return Delay_InitialCondition_k.value
    
    def getP_Constant7_Value(self):
        """Get current value for the scalar `Constant7_Value`.

        Returns
        -------
        float
        """
        Constant7_Value = c_double()
        self._lib.getP_Constant7_Value(byref(Constant7_Value))
        return Constant7_Value.value
    
    def getP_Switch_Threshold(self):
        """Get current value for the scalar `Switch_Threshold`.

        Returns
        -------
        float
        """
        Switch_Threshold = c_double()
        self._lib.getP_Switch_Threshold(byref(Switch_Threshold))
        return Switch_Threshold.value
    
    def getP_Delay_InitialCondition_o4(self):
        """Get current value for the scalar `Delay_InitialCondition_o4`.

        Returns
        -------
        float
        """
        Delay_InitialCondition_o4 = c_double()
        self._lib.getP_Delay_InitialCondition_o4(byref(Delay_InitialCondition_o4))
        return Delay_InitialCondition_o4.value
    
    def getP_Switch4_Threshold(self):
        """Get current value for the scalar `Switch4_Threshold`.

        Returns
        -------
        float
        """
        Switch4_Threshold = c_double()
        self._lib.getP_Switch4_Threshold(byref(Switch4_Threshold))
        return Switch4_Threshold.value
    
    def getP_Constant_Value(self):
        """Get current value for the scalar `Constant_Value`.

        Returns
        -------
        float
        """
        Constant_Value = c_double()
        self._lib.getP_Constant_Value(byref(Constant_Value))
        return Constant_Value.value
    
    def getP_Constant4_Value(self):
        """Get current value for the scalar `Constant4_Value`.

        Returns
        -------
        float
        """
        Constant4_Value = c_double()
        self._lib.getP_Constant4_Value(byref(Constant4_Value))
        return Constant4_Value.value
    
    def getP_Switch1_Threshold(self):
        """Get current value for the scalar `Switch1_Threshold`.

        Returns
        -------
        float
        """
        Switch1_Threshold = c_double()
        self._lib.getP_Switch1_Threshold(byref(Switch1_Threshold))
        return Switch1_Threshold.value
    
    def getP_Delay2_InitialCondition(self):
        """Get current value for the scalar `Delay2_InitialCondition`.

        Returns
        -------
        float
        """
        Delay2_InitialCondition = c_double()
        self._lib.getP_Delay2_InitialCondition(byref(Delay2_InitialCondition))
        return Delay2_InitialCondition.value
    
    def getP_Delay7_InitialCondition(self):
        """Get current value for the scalar `Delay7_InitialCondition`.

        Returns
        -------
        float
        """
        Delay7_InitialCondition = c_double()
        self._lib.getP_Delay7_InitialCondition(byref(Delay7_InitialCondition))
        return Delay7_InitialCondition.value
    
    def getP_Constant2_Value(self):
        """Get current value for the scalar `Constant2_Value`.

        Returns
        -------
        float
        """
        Constant2_Value = c_double()
        self._lib.getP_Constant2_Value(byref(Constant2_Value))
        return Constant2_Value.value
    
    def getP_Delay_InitialCondition_j(self):
        """Get current value for the scalar `Delay_InitialCondition_j`.

        Returns
        -------
        float
        """
        Delay_InitialCondition_j = c_double()
        self._lib.getP_Delay_InitialCondition_j(byref(Delay_InitialCondition_j))
        return Delay_InitialCondition_j.value
    
    def getP_Delay_InitialCondition_l(self):
        """Get current value for the scalar `Delay_InitialCondition_l`.

        Returns
        -------
        float
        """
        Delay_InitialCondition_l = c_double()
        self._lib.getP_Delay_InitialCondition_l(byref(Delay_InitialCondition_l))
        return Delay_InitialCondition_l.value
    
    def getP_Delay_InitialCondition_jr(self):
        """Get current value for the scalar `Delay_InitialCondition_jr`.

        Returns
        -------
        float
        """
        Delay_InitialCondition_jr = c_double()
        self._lib.getP_Delay_InitialCondition_jr(byref(Delay_InitialCondition_jr))
        return Delay_InitialCondition_jr.value
    
    def getP_Constant3_Value(self):
        """Get current value for the scalar `Constant3_Value`.

        Returns
        -------
        float
        """
        Constant3_Value = c_double()
        self._lib.getP_Constant3_Value(byref(Constant3_Value))
        return Constant3_Value.value
    
    def getP(self):
        res = tuple(func() for func in [self.getP_DHWheatexchanger_A, self.getP_Primaryheatexchanger_A, self.getP_DHWreturnpipe_D, self.getP_DHWstorage_D, self.getP_DHWsupplypipe_D, self.getP_SHreturnpipe_D, self.getP_SHsupplypipe_D, self.getP_SHthermalemitters_D, self.getP_DHWstorage_H, self.getP_DHWreturnpipe_L, self.getP_DHWsupplypipe_L, self.getP_SHreturnpipe_L, self.getP_SHsupplypipe_L, self.getP_SHthermalemitters_L, self.getP_SHthermalemitters_T_air, self.getP_DHWstorage_T_amb, self.getP_DHWreturnpipe_T_duct, self.getP_DHWsupplypipe_T_duct, self.getP_SHreturnpipe_T_duct, self.getP_SHsupplypipe_T_duct, self.getP_DHWstorage_U, self.getP_SHthermalemitters_U, self.getP_DHWheatexchanger_U, self.getP_Primaryheatexchanger_U, self.getP_DHWstorage_V_min, self.getP_DHWstorage_V_var, self.getP_DHWstorage_eps, self.getP_DHWreturnpipe_m_min, self.getP_DHWsupplypipe_m_min, self.getP_SHreturnpipe_m_min, self.getP_SHsupplypipe_m_min, self.getP_SHthermalemitters_m_min, self.getP_DHWstorage_n, self.getP_SHthermalemitters_n_radiators, self.getP_SHthermalemitters_n_tubes, self.getP_DHWbypassvalve_unknown_T, self.getP_DHWstoragetopvalve_unknown_T, self.getP_DHWcoldwaterrefill_unknown_T, self.getP_DHWstoragebottomvalve_unknown_T, self.getP_SHbypassvalve_unknown_T, self.getP_SHDHWreturnvalve_unknown_T, self.getP_DHWbypassvalve_unknown_m, self.getP_DHWstoragetopvalve_unknown_m, self.getP_DHWcoldwaterrefill_unknown_m, self.getP_DHWstoragebottomvalve_unknown_m, self.getP_SHbypassvalve_unknown_m, self.getP_SHDHWreturnvalve_unknown_m, self.getP_Delay_InitialCondition, self.getP_Delay1_InitialCondition, self.getP_Constant1_Value, self.getP_Delay6_InitialCondition, self.getP_Delay5_InitialCondition, self.getP_Switch3_Threshold, self.getP_Constant5_Value, self.getP_Constant6_Value, self.getP_Switch2_Threshold, self.getP_Delay_InitialCondition_o, self.getP_Delay_InitialCondition_k, self.getP_Constant7_Value, self.getP_Switch_Threshold, self.getP_Delay_InitialCondition_o4, self.getP_Switch4_Threshold, self.getP_Constant_Value, self.getP_Constant4_Value, self.getP_Switch1_Threshold, self.getP_Delay2_InitialCondition, self.getP_Delay7_InitialCondition, self.getP_Constant2_Value, self.getP_Delay_InitialCondition_j, self.getP_Delay_InitialCondition_l, self.getP_Delay_InitialCondition_jr, self.getP_Constant3_Value])
        return res
    
    def getP_as_dict(self):
        """Return all parameter values as a dict.

        """
        parameters = dict()            
        for name in sorted(['DHWheatexchanger_A', 'Primaryheatexchanger_A', 'DHWreturnpipe_D', 'DHWstorage_D', 'DHWsupplypipe_D', 'SHreturnpipe_D', 'SHsupplypipe_D', 'SHthermalemitters_D', 'DHWstorage_H', 'DHWreturnpipe_L', 'DHWsupplypipe_L', 'SHreturnpipe_L', 'SHsupplypipe_L', 'SHthermalemitters_L', 'SHthermalemitters_T_air', 'DHWstorage_T_amb', 'DHWreturnpipe_T_duct', 'DHWsupplypipe_T_duct', 'SHreturnpipe_T_duct', 'SHsupplypipe_T_duct', 'DHWstorage_U', 'SHthermalemitters_U', 'DHWheatexchanger_U', 'Primaryheatexchanger_U', 'DHWstorage_V_min', 'DHWstorage_V_var', 'DHWstorage_eps', 'DHWreturnpipe_m_min', 'DHWsupplypipe_m_min', 'SHreturnpipe_m_min', 'SHsupplypipe_m_min', 'SHthermalemitters_m_min', 'DHWstorage_n', 'SHthermalemitters_n_radiators', 'SHthermalemitters_n_tubes', 'DHWbypassvalve_unknown_T', 'DHWstoragetopvalve_unknown_T', 'DHWcoldwaterrefill_unknown_T', 'DHWstoragebottomvalve_unknown_T', 'SHbypassvalve_unknown_T', 'SHDHWreturnvalve_unknown_T', 'DHWbypassvalve_unknown_m', 'DHWstoragetopvalve_unknown_m', 'DHWcoldwaterrefill_unknown_m', 'DHWstoragebottomvalve_unknown_m', 'SHbypassvalve_unknown_m', 'SHDHWreturnvalve_unknown_m', 'Delay_InitialCondition', 'Delay1_InitialCondition', 'Constant1_Value', 'Delay6_InitialCondition', 'Delay5_InitialCondition', 'Switch3_Threshold', 'Constant5_Value', 'Constant6_Value', 'Switch2_Threshold', 'Delay_InitialCondition_o', 'Delay_InitialCondition_k', 'Constant7_Value', 'Switch_Threshold', 'Delay_InitialCondition_o4', 'Switch4_Threshold', 'Constant_Value', 'Constant4_Value', 'Switch1_Threshold', 'Delay2_InitialCondition', 'Delay7_InitialCondition', 'Constant2_Value', 'Delay_InitialCondition_j', 'Delay_InitialCondition_l', 'Delay_InitialCondition_jr', 'Constant3_Value']):
            func = getattr(self, f"getP_{name}")
            parameters[name] = func()
        return parameters            
    

# =======
# SETTERS
# =======

# -- U --

    
    def _setU_m_prim(self, value):
        """Set a new value for the scalar `m_prim`.

        Parameters
        ----------
        value : float
            New value for variable named m_prim
        """
        m_prim = c_double(value)
        self._lib.setU_m_prim(byref(m_prim))
    
    
    def _setU_T_prim_in(self, value):
        """Set a new value for the scalar `T_prim_in`.

        Parameters
        ----------
        value : float
            New value for variable named T_prim_in
        """
        T_prim_in = c_double(value)
        self._lib.setU_T_prim_in(byref(T_prim_in))
    
    
    def _setU_m_SH_dir(self, value):
        """Set a new value for the scalar `m_SH_dir`.

        Parameters
        ----------
        value : float
            New value for variable named m_SH_dir
        """
        m_SH_dir = c_double(value)
        self._lib.setU_m_SH_dir(byref(m_SH_dir))
    
    
    def _setU_m_SH_3V(self, value):
        """Set a new value for the scalar `m_SH_3V`.

        Parameters
        ----------
        value : float
            New value for variable named m_SH_3V
        """
        m_SH_3V = c_double(value)
        self._lib.setU_m_SH_3V(byref(m_SH_3V))
    
    
    def _setU_m_DHW_sec(self, value):
        """Set a new value for the scalar `m_DHW_sec`.

        Parameters
        ----------
        value : float
            New value for variable named m_DHW_sec
        """
        m_DHW_sec = c_double(value)
        self._lib.setU_m_DHW_sec(byref(m_DHW_sec))
    
    
    def _setU_m_DHW_w(self, value):
        """Set a new value for the scalar `m_DHW_w`.

        Parameters
        ----------
        value : float
            New value for variable named m_DHW_w
        """
        m_DHW_w = c_double(value)
        self._lib.setU_m_DHW_w(byref(m_DHW_w))
    
    
    def _setU_m_DHW_recirc(self, value):
        """Set a new value for the scalar `m_DHW_recirc`.

        Parameters
        ----------
        value : float
            New value for variable named m_DHW_recirc
        """
        m_DHW_recirc = c_double(value)
        self._lib.setU_m_DHW_recirc(byref(m_DHW_recirc))
    
    
    def _setU_T_cold(self, value):
        """Set a new value for the scalar `T_cold`.

        Parameters
        ----------
        value : float
            New value for variable named T_cold
        """
        T_cold = c_double(value)
        self._lib.setU_T_cold(byref(T_cold))
    
    
    def _setU_m_DHW_dir(self, value):
        """Set a new value for the scalar `m_DHW_dir`.

        Parameters
        ----------
        value : float
            New value for variable named m_DHW_dir
        """
        m_DHW_dir = c_double(value)
        self._lib.setU_m_DHW_dir(byref(m_DHW_dir))
    
    
    def _setU_m_DHW_3V(self, value):
        """Set a new value for the scalar `m_DHW_3V`.

        Parameters
        ----------
        value : float
            New value for variable named m_DHW_3V
        """
        m_DHW_3V = c_double(value)
        self._lib.setU_m_DHW_3V(byref(m_DHW_3V))
    
    def _setU(self, values):
        for values_, func in zip(values, [self._setU_m_prim, self._setU_T_prim_in, self._setU_m_SH_dir, self._setU_m_SH_3V, self._setU_m_DHW_sec, self._setU_m_DHW_w, self._setU_m_DHW_recirc, self._setU_T_cold, self._setU_m_DHW_dir, self._setU_m_DHW_3V]):
            func(values_)
    # -- P --

    @_check_param_setter
    def setP_DHWheatexchanger_A(self, value):
        """Set a new value for the scalar `DHWheatexchanger_A`.

        Parameters
        ----------
        value : float
            New value for variable named DHWheatexchanger_A
        """
        DHWheatexchanger_A = c_double(value)
        self._lib.setP_DHWheatexchanger_A(byref(DHWheatexchanger_A))
    
    @_check_param_setter
    def setP_Primaryheatexchanger_A(self, value):
        """Set a new value for the scalar `Primaryheatexchanger_A`.

        Parameters
        ----------
        value : float
            New value for variable named Primaryheatexchanger_A
        """
        Primaryheatexchanger_A = c_double(value)
        self._lib.setP_Primaryheatexchanger_A(byref(Primaryheatexchanger_A))
    
    @_check_param_setter
    def setP_DHWreturnpipe_D(self, value):
        """Set a new value for the scalar `DHWreturnpipe_D`.

        Parameters
        ----------
        value : float
            New value for variable named DHWreturnpipe_D
        """
        DHWreturnpipe_D = c_double(value)
        self._lib.setP_DHWreturnpipe_D(byref(DHWreturnpipe_D))
    
    @_check_param_setter
    def setP_DHWstorage_D(self, value):
        """Set a new value for the scalar `DHWstorage_D`.

        Parameters
        ----------
        value : float
            New value for variable named DHWstorage_D
        """
        DHWstorage_D = c_double(value)
        self._lib.setP_DHWstorage_D(byref(DHWstorage_D))
    
    @_check_param_setter
    def setP_DHWsupplypipe_D(self, value):
        """Set a new value for the scalar `DHWsupplypipe_D`.

        Parameters
        ----------
        value : float
            New value for variable named DHWsupplypipe_D
        """
        DHWsupplypipe_D = c_double(value)
        self._lib.setP_DHWsupplypipe_D(byref(DHWsupplypipe_D))
    
    @_check_param_setter
    def setP_SHreturnpipe_D(self, value):
        """Set a new value for the scalar `SHreturnpipe_D`.

        Parameters
        ----------
        value : float
            New value for variable named SHreturnpipe_D
        """
        SHreturnpipe_D = c_double(value)
        self._lib.setP_SHreturnpipe_D(byref(SHreturnpipe_D))
    
    @_check_param_setter
    def setP_SHsupplypipe_D(self, value):
        """Set a new value for the scalar `SHsupplypipe_D`.

        Parameters
        ----------
        value : float
            New value for variable named SHsupplypipe_D
        """
        SHsupplypipe_D = c_double(value)
        self._lib.setP_SHsupplypipe_D(byref(SHsupplypipe_D))
    
    @_check_param_setter
    def setP_SHthermalemitters_D(self, value):
        """Set a new value for the scalar `SHthermalemitters_D`.

        Parameters
        ----------
        value : float
            New value for variable named SHthermalemitters_D
        """
        SHthermalemitters_D = c_double(value)
        self._lib.setP_SHthermalemitters_D(byref(SHthermalemitters_D))
    
    @_check_param_setter
    def setP_DHWstorage_H(self, value):
        """Set a new value for the scalar `DHWstorage_H`.

        Parameters
        ----------
        value : float
            New value for variable named DHWstorage_H
        """
        DHWstorage_H = c_double(value)
        self._lib.setP_DHWstorage_H(byref(DHWstorage_H))
    
    @_check_param_setter
    def setP_DHWreturnpipe_L(self, value):
        """Set a new value for the scalar `DHWreturnpipe_L`.

        Parameters
        ----------
        value : float
            New value for variable named DHWreturnpipe_L
        """
        DHWreturnpipe_L = c_double(value)
        self._lib.setP_DHWreturnpipe_L(byref(DHWreturnpipe_L))
    
    @_check_param_setter
    def setP_DHWsupplypipe_L(self, value):
        """Set a new value for the scalar `DHWsupplypipe_L`.

        Parameters
        ----------
        value : float
            New value for variable named DHWsupplypipe_L
        """
        DHWsupplypipe_L = c_double(value)
        self._lib.setP_DHWsupplypipe_L(byref(DHWsupplypipe_L))
    
    @_check_param_setter
    def setP_SHreturnpipe_L(self, value):
        """Set a new value for the scalar `SHreturnpipe_L`.

        Parameters
        ----------
        value : float
            New value for variable named SHreturnpipe_L
        """
        SHreturnpipe_L = c_double(value)
        self._lib.setP_SHreturnpipe_L(byref(SHreturnpipe_L))
    
    @_check_param_setter
    def setP_SHsupplypipe_L(self, value):
        """Set a new value for the scalar `SHsupplypipe_L`.

        Parameters
        ----------
        value : float
            New value for variable named SHsupplypipe_L
        """
        SHsupplypipe_L = c_double(value)
        self._lib.setP_SHsupplypipe_L(byref(SHsupplypipe_L))
    
    @_check_param_setter
    def setP_SHthermalemitters_L(self, value):
        """Set a new value for the scalar `SHthermalemitters_L`.

        Parameters
        ----------
        value : float
            New value for variable named SHthermalemitters_L
        """
        SHthermalemitters_L = c_double(value)
        self._lib.setP_SHthermalemitters_L(byref(SHthermalemitters_L))
    
    @_check_param_setter
    def setP_SHthermalemitters_T_air(self, value):
        """Set a new value for the scalar `SHthermalemitters_T_air`.

        Parameters
        ----------
        value : float
            New value for variable named SHthermalemitters_T_air
        """
        SHthermalemitters_T_air = c_double(value)
        self._lib.setP_SHthermalemitters_T_air(byref(SHthermalemitters_T_air))
    
    @_check_param_setter
    def setP_DHWstorage_T_amb(self, value):
        """Set a new value for the scalar `DHWstorage_T_amb`.

        Parameters
        ----------
        value : float
            New value for variable named DHWstorage_T_amb
        """
        DHWstorage_T_amb = c_double(value)
        self._lib.setP_DHWstorage_T_amb(byref(DHWstorage_T_amb))
    
    @_check_param_setter
    def setP_DHWreturnpipe_T_duct(self, value):
        """Set a new value for the scalar `DHWreturnpipe_T_duct`.

        Parameters
        ----------
        value : float
            New value for variable named DHWreturnpipe_T_duct
        """
        DHWreturnpipe_T_duct = c_double(value)
        self._lib.setP_DHWreturnpipe_T_duct(byref(DHWreturnpipe_T_duct))
    
    @_check_param_setter
    def setP_DHWsupplypipe_T_duct(self, value):
        """Set a new value for the scalar `DHWsupplypipe_T_duct`.

        Parameters
        ----------
        value : float
            New value for variable named DHWsupplypipe_T_duct
        """
        DHWsupplypipe_T_duct = c_double(value)
        self._lib.setP_DHWsupplypipe_T_duct(byref(DHWsupplypipe_T_duct))
    
    @_check_param_setter
    def setP_SHreturnpipe_T_duct(self, value):
        """Set a new value for the scalar `SHreturnpipe_T_duct`.

        Parameters
        ----------
        value : float
            New value for variable named SHreturnpipe_T_duct
        """
        SHreturnpipe_T_duct = c_double(value)
        self._lib.setP_SHreturnpipe_T_duct(byref(SHreturnpipe_T_duct))
    
    @_check_param_setter
    def setP_SHsupplypipe_T_duct(self, value):
        """Set a new value for the scalar `SHsupplypipe_T_duct`.

        Parameters
        ----------
        value : float
            New value for variable named SHsupplypipe_T_duct
        """
        SHsupplypipe_T_duct = c_double(value)
        self._lib.setP_SHsupplypipe_T_duct(byref(SHsupplypipe_T_duct))
    
    @_check_param_setter
    def setP_DHWstorage_U(self, value):
        """Set a new value for the scalar `DHWstorage_U`.

        Parameters
        ----------
        value : float
            New value for variable named DHWstorage_U
        """
        DHWstorage_U = c_double(value)
        self._lib.setP_DHWstorage_U(byref(DHWstorage_U))
    
    @_check_param_setter
    def setP_SHthermalemitters_U(self, value):
        """Set a new value for the scalar `SHthermalemitters_U`.

        Parameters
        ----------
        value : float
            New value for variable named SHthermalemitters_U
        """
        SHthermalemitters_U = c_double(value)
        self._lib.setP_SHthermalemitters_U(byref(SHthermalemitters_U))
    
    @_check_param_setter
    def setP_DHWheatexchanger_U(self, value):
        """Set a new value for the scalar `DHWheatexchanger_U`.

        Parameters
        ----------
        value : float
            New value for variable named DHWheatexchanger_U
        """
        DHWheatexchanger_U = c_double(value)
        self._lib.setP_DHWheatexchanger_U(byref(DHWheatexchanger_U))
    
    @_check_param_setter
    def setP_Primaryheatexchanger_U(self, value):
        """Set a new value for the scalar `Primaryheatexchanger_U`.

        Parameters
        ----------
        value : float
            New value for variable named Primaryheatexchanger_U
        """
        Primaryheatexchanger_U = c_double(value)
        self._lib.setP_Primaryheatexchanger_U(byref(Primaryheatexchanger_U))
    
    @_check_param_setter
    def setP_DHWstorage_V_min(self, value):
        """Set a new value for the scalar `DHWstorage_V_min`.

        Parameters
        ----------
        value : float
            New value for variable named DHWstorage_V_min
        """
        DHWstorage_V_min = c_double(value)
        self._lib.setP_DHWstorage_V_min(byref(DHWstorage_V_min))
    
    @_check_param_setter
    def setP_DHWstorage_V_var(self, value):
        """Set a new value for the scalar `DHWstorage_V_var`.

        Parameters
        ----------
        value : float
            New value for variable named DHWstorage_V_var
        """
        DHWstorage_V_var = c_double(value)
        self._lib.setP_DHWstorage_V_var(byref(DHWstorage_V_var))
    
    @_check_param_setter
    def setP_DHWstorage_eps(self, value):
        """Set a new value for the scalar `DHWstorage_eps`.

        Parameters
        ----------
        value : float
            New value for variable named DHWstorage_eps
        """
        DHWstorage_eps = c_double(value)
        self._lib.setP_DHWstorage_eps(byref(DHWstorage_eps))
    
    @_check_param_setter
    def setP_DHWreturnpipe_m_min(self, value):
        """Set a new value for the scalar `DHWreturnpipe_m_min`.

        Parameters
        ----------
        value : float
            New value for variable named DHWreturnpipe_m_min
        """
        DHWreturnpipe_m_min = c_double(value)
        self._lib.setP_DHWreturnpipe_m_min(byref(DHWreturnpipe_m_min))
    
    @_check_param_setter
    def setP_DHWsupplypipe_m_min(self, value):
        """Set a new value for the scalar `DHWsupplypipe_m_min`.

        Parameters
        ----------
        value : float
            New value for variable named DHWsupplypipe_m_min
        """
        DHWsupplypipe_m_min = c_double(value)
        self._lib.setP_DHWsupplypipe_m_min(byref(DHWsupplypipe_m_min))
    
    @_check_param_setter
    def setP_SHreturnpipe_m_min(self, value):
        """Set a new value for the scalar `SHreturnpipe_m_min`.

        Parameters
        ----------
        value : float
            New value for variable named SHreturnpipe_m_min
        """
        SHreturnpipe_m_min = c_double(value)
        self._lib.setP_SHreturnpipe_m_min(byref(SHreturnpipe_m_min))
    
    @_check_param_setter
    def setP_SHsupplypipe_m_min(self, value):
        """Set a new value for the scalar `SHsupplypipe_m_min`.

        Parameters
        ----------
        value : float
            New value for variable named SHsupplypipe_m_min
        """
        SHsupplypipe_m_min = c_double(value)
        self._lib.setP_SHsupplypipe_m_min(byref(SHsupplypipe_m_min))
    
    @_check_param_setter
    def setP_SHthermalemitters_m_min(self, value):
        """Set a new value for the scalar `SHthermalemitters_m_min`.

        Parameters
        ----------
        value : float
            New value for variable named SHthermalemitters_m_min
        """
        SHthermalemitters_m_min = c_double(value)
        self._lib.setP_SHthermalemitters_m_min(byref(SHthermalemitters_m_min))
    
    @_check_param_setter
    def setP_DHWstorage_n(self, value):
        """Set a new value for the scalar `DHWstorage_n`.

        Parameters
        ----------
        value : float
            New value for variable named DHWstorage_n
        """
        DHWstorage_n = c_double(value)
        self._lib.setP_DHWstorage_n(byref(DHWstorage_n))
    
    @_check_param_setter
    def setP_SHthermalemitters_n_radiators(self, value):
        """Set a new value for the scalar `SHthermalemitters_n_radiators`.

        Parameters
        ----------
        value : float
            New value for variable named SHthermalemitters_n_radiators
        """
        SHthermalemitters_n_radiators = c_double(value)
        self._lib.setP_SHthermalemitters_n_radiators(byref(SHthermalemitters_n_radiators))
    
    @_check_param_setter
    def setP_SHthermalemitters_n_tubes(self, value):
        """Set a new value for the scalar `SHthermalemitters_n_tubes`.

        Parameters
        ----------
        value : float
            New value for variable named SHthermalemitters_n_tubes
        """
        SHthermalemitters_n_tubes = c_double(value)
        self._lib.setP_SHthermalemitters_n_tubes(byref(SHthermalemitters_n_tubes))
    
    @_check_param_setter
    def setP_DHWbypassvalve_unknown_T(self, value):
        """Set a new value for the scalar `DHWbypassvalve_unknown_T`.

        Parameters
        ----------
        value : float
            New value for variable named DHWbypassvalve_unknown_T
        """
        DHWbypassvalve_unknown_T = c_double(value)
        self._lib.setP_DHWbypassvalve_unknown_T(byref(DHWbypassvalve_unknown_T))
    
    @_check_param_setter
    def setP_DHWstoragetopvalve_unknown_T(self, value):
        """Set a new value for the scalar `DHWstoragetopvalve_unknown_T`.

        Parameters
        ----------
        value : float
            New value for variable named DHWstoragetopvalve_unknown_T
        """
        DHWstoragetopvalve_unknown_T = c_double(value)
        self._lib.setP_DHWstoragetopvalve_unknown_T(byref(DHWstoragetopvalve_unknown_T))
    
    @_check_param_setter
    def setP_DHWcoldwaterrefill_unknown_T(self, value):
        """Set a new value for the scalar `DHWcoldwaterrefill_unknown_T`.

        Parameters
        ----------
        value : float
            New value for variable named DHWcoldwaterrefill_unknown_T
        """
        DHWcoldwaterrefill_unknown_T = c_double(value)
        self._lib.setP_DHWcoldwaterrefill_unknown_T(byref(DHWcoldwaterrefill_unknown_T))
    
    @_check_param_setter
    def setP_DHWstoragebottomvalve_unknown_T(self, value):
        """Set a new value for the scalar `DHWstoragebottomvalve_unknown_T`.

        Parameters
        ----------
        value : float
            New value for variable named DHWstoragebottomvalve_unknown_T
        """
        DHWstoragebottomvalve_unknown_T = c_double(value)
        self._lib.setP_DHWstoragebottomvalve_unknown_T(byref(DHWstoragebottomvalve_unknown_T))
    
    @_check_param_setter
    def setP_SHbypassvalve_unknown_T(self, value):
        """Set a new value for the scalar `SHbypassvalve_unknown_T`.

        Parameters
        ----------
        value : float
            New value for variable named SHbypassvalve_unknown_T
        """
        SHbypassvalve_unknown_T = c_double(value)
        self._lib.setP_SHbypassvalve_unknown_T(byref(SHbypassvalve_unknown_T))
    
    @_check_param_setter
    def setP_SHDHWreturnvalve_unknown_T(self, value):
        """Set a new value for the scalar `SHDHWreturnvalve_unknown_T`.

        Parameters
        ----------
        value : float
            New value for variable named SHDHWreturnvalve_unknown_T
        """
        SHDHWreturnvalve_unknown_T = c_double(value)
        self._lib.setP_SHDHWreturnvalve_unknown_T(byref(SHDHWreturnvalve_unknown_T))
    
    @_check_param_setter
    def setP_DHWbypassvalve_unknown_m(self, value):
        """Set a new value for the scalar `DHWbypassvalve_unknown_m`.

        Parameters
        ----------
        value : float
            New value for variable named DHWbypassvalve_unknown_m
        """
        DHWbypassvalve_unknown_m = c_double(value)
        self._lib.setP_DHWbypassvalve_unknown_m(byref(DHWbypassvalve_unknown_m))
    
    @_check_param_setter
    def setP_DHWstoragetopvalve_unknown_m(self, value):
        """Set a new value for the scalar `DHWstoragetopvalve_unknown_m`.

        Parameters
        ----------
        value : float
            New value for variable named DHWstoragetopvalve_unknown_m
        """
        DHWstoragetopvalve_unknown_m = c_double(value)
        self._lib.setP_DHWstoragetopvalve_unknown_m(byref(DHWstoragetopvalve_unknown_m))
    
    @_check_param_setter
    def setP_DHWcoldwaterrefill_unknown_m(self, value):
        """Set a new value for the scalar `DHWcoldwaterrefill_unknown_m`.

        Parameters
        ----------
        value : float
            New value for variable named DHWcoldwaterrefill_unknown_m
        """
        DHWcoldwaterrefill_unknown_m = c_double(value)
        self._lib.setP_DHWcoldwaterrefill_unknown_m(byref(DHWcoldwaterrefill_unknown_m))
    
    @_check_param_setter
    def setP_DHWstoragebottomvalve_unknown_m(self, value):
        """Set a new value for the scalar `DHWstoragebottomvalve_unknown_m`.

        Parameters
        ----------
        value : float
            New value for variable named DHWstoragebottomvalve_unknown_m
        """
        DHWstoragebottomvalve_unknown_m = c_double(value)
        self._lib.setP_DHWstoragebottomvalve_unknown_m(byref(DHWstoragebottomvalve_unknown_m))
    
    @_check_param_setter
    def setP_SHbypassvalve_unknown_m(self, value):
        """Set a new value for the scalar `SHbypassvalve_unknown_m`.

        Parameters
        ----------
        value : float
            New value for variable named SHbypassvalve_unknown_m
        """
        SHbypassvalve_unknown_m = c_double(value)
        self._lib.setP_SHbypassvalve_unknown_m(byref(SHbypassvalve_unknown_m))
    
    @_check_param_setter
    def setP_SHDHWreturnvalve_unknown_m(self, value):
        """Set a new value for the scalar `SHDHWreturnvalve_unknown_m`.

        Parameters
        ----------
        value : float
            New value for variable named SHDHWreturnvalve_unknown_m
        """
        SHDHWreturnvalve_unknown_m = c_double(value)
        self._lib.setP_SHDHWreturnvalve_unknown_m(byref(SHDHWreturnvalve_unknown_m))
    
    @_check_param_setter
    def setP_Delay_InitialCondition(self, value):
        """Set a new value for the scalar `Delay_InitialCondition`.

        Parameters
        ----------
        value : float
            New value for variable named Delay_InitialCondition
        """
        Delay_InitialCondition = c_double(value)
        self._lib.setP_Delay_InitialCondition(byref(Delay_InitialCondition))
    
    @_check_param_setter
    def setP_Delay1_InitialCondition(self, value):
        """Set a new value for the scalar `Delay1_InitialCondition`.

        Parameters
        ----------
        value : float
            New value for variable named Delay1_InitialCondition
        """
        Delay1_InitialCondition = c_double(value)
        self._lib.setP_Delay1_InitialCondition(byref(Delay1_InitialCondition))
    
    @_check_param_setter
    def setP_Constant1_Value(self, value):
        """Set a new value for the scalar `Constant1_Value`.

        Parameters
        ----------
        value : float
            New value for variable named Constant1_Value
        """
        Constant1_Value = c_double(value)
        self._lib.setP_Constant1_Value(byref(Constant1_Value))
    
    @_check_param_setter
    def setP_Delay6_InitialCondition(self, value):
        """Set a new value for the scalar `Delay6_InitialCondition`.

        Parameters
        ----------
        value : float
            New value for variable named Delay6_InitialCondition
        """
        Delay6_InitialCondition = c_double(value)
        self._lib.setP_Delay6_InitialCondition(byref(Delay6_InitialCondition))
    
    @_check_param_setter
    def setP_Delay5_InitialCondition(self, value):
        """Set a new value for the scalar `Delay5_InitialCondition`.

        Parameters
        ----------
        value : float
            New value for variable named Delay5_InitialCondition
        """
        Delay5_InitialCondition = c_double(value)
        self._lib.setP_Delay5_InitialCondition(byref(Delay5_InitialCondition))
    
    @_check_param_setter
    def setP_Switch3_Threshold(self, value):
        """Set a new value for the scalar `Switch3_Threshold`.

        Parameters
        ----------
        value : float
            New value for variable named Switch3_Threshold
        """
        Switch3_Threshold = c_double(value)
        self._lib.setP_Switch3_Threshold(byref(Switch3_Threshold))
    
    @_check_param_setter
    def setP_Constant5_Value(self, value):
        """Set a new value for the scalar `Constant5_Value`.

        Parameters
        ----------
        value : float
            New value for variable named Constant5_Value
        """
        Constant5_Value = c_double(value)
        self._lib.setP_Constant5_Value(byref(Constant5_Value))
    
    @_check_param_setter
    def setP_Constant6_Value(self, value):
        """Set a new value for the scalar `Constant6_Value`.

        Parameters
        ----------
        value : float
            New value for variable named Constant6_Value
        """
        Constant6_Value = c_double(value)
        self._lib.setP_Constant6_Value(byref(Constant6_Value))
    
    @_check_param_setter
    def setP_Switch2_Threshold(self, value):
        """Set a new value for the scalar `Switch2_Threshold`.

        Parameters
        ----------
        value : float
            New value for variable named Switch2_Threshold
        """
        Switch2_Threshold = c_double(value)
        self._lib.setP_Switch2_Threshold(byref(Switch2_Threshold))
    
    @_check_param_setter
    def setP_Delay_InitialCondition_o(self, value):
        """Set a new value for the scalar `Delay_InitialCondition_o`.

        Parameters
        ----------
        value : float
            New value for variable named Delay_InitialCondition_o
        """
        Delay_InitialCondition_o = c_double(value)
        self._lib.setP_Delay_InitialCondition_o(byref(Delay_InitialCondition_o))
    
    @_check_param_setter
    def setP_Delay_InitialCondition_k(self, value):
        """Set a new value for the scalar `Delay_InitialCondition_k`.

        Parameters
        ----------
        value : float
            New value for variable named Delay_InitialCondition_k
        """
        Delay_InitialCondition_k = c_double(value)
        self._lib.setP_Delay_InitialCondition_k(byref(Delay_InitialCondition_k))
    
    @_check_param_setter
    def setP_Constant7_Value(self, value):
        """Set a new value for the scalar `Constant7_Value`.

        Parameters
        ----------
        value : float
            New value for variable named Constant7_Value
        """
        Constant7_Value = c_double(value)
        self._lib.setP_Constant7_Value(byref(Constant7_Value))
    
    @_check_param_setter
    def setP_Switch_Threshold(self, value):
        """Set a new value for the scalar `Switch_Threshold`.

        Parameters
        ----------
        value : float
            New value for variable named Switch_Threshold
        """
        Switch_Threshold = c_double(value)
        self._lib.setP_Switch_Threshold(byref(Switch_Threshold))
    
    @_check_param_setter
    def setP_Delay_InitialCondition_o4(self, value):
        """Set a new value for the scalar `Delay_InitialCondition_o4`.

        Parameters
        ----------
        value : float
            New value for variable named Delay_InitialCondition_o4
        """
        Delay_InitialCondition_o4 = c_double(value)
        self._lib.setP_Delay_InitialCondition_o4(byref(Delay_InitialCondition_o4))
    
    @_check_param_setter
    def setP_Switch4_Threshold(self, value):
        """Set a new value for the scalar `Switch4_Threshold`.

        Parameters
        ----------
        value : float
            New value for variable named Switch4_Threshold
        """
        Switch4_Threshold = c_double(value)
        self._lib.setP_Switch4_Threshold(byref(Switch4_Threshold))
    
    @_check_param_setter
    def setP_Constant_Value(self, value):
        """Set a new value for the scalar `Constant_Value`.

        Parameters
        ----------
        value : float
            New value for variable named Constant_Value
        """
        Constant_Value = c_double(value)
        self._lib.setP_Constant_Value(byref(Constant_Value))
    
    @_check_param_setter
    def setP_Constant4_Value(self, value):
        """Set a new value for the scalar `Constant4_Value`.

        Parameters
        ----------
        value : float
            New value for variable named Constant4_Value
        """
        Constant4_Value = c_double(value)
        self._lib.setP_Constant4_Value(byref(Constant4_Value))
    
    @_check_param_setter
    def setP_Switch1_Threshold(self, value):
        """Set a new value for the scalar `Switch1_Threshold`.

        Parameters
        ----------
        value : float
            New value for variable named Switch1_Threshold
        """
        Switch1_Threshold = c_double(value)
        self._lib.setP_Switch1_Threshold(byref(Switch1_Threshold))
    
    @_check_param_setter
    def setP_Delay2_InitialCondition(self, value):
        """Set a new value for the scalar `Delay2_InitialCondition`.

        Parameters
        ----------
        value : float
            New value for variable named Delay2_InitialCondition
        """
        Delay2_InitialCondition = c_double(value)
        self._lib.setP_Delay2_InitialCondition(byref(Delay2_InitialCondition))
    
    @_check_param_setter
    def setP_Delay7_InitialCondition(self, value):
        """Set a new value for the scalar `Delay7_InitialCondition`.

        Parameters
        ----------
        value : float
            New value for variable named Delay7_InitialCondition
        """
        Delay7_InitialCondition = c_double(value)
        self._lib.setP_Delay7_InitialCondition(byref(Delay7_InitialCondition))
    
    @_check_param_setter
    def setP_Constant2_Value(self, value):
        """Set a new value for the scalar `Constant2_Value`.

        Parameters
        ----------
        value : float
            New value for variable named Constant2_Value
        """
        Constant2_Value = c_double(value)
        self._lib.setP_Constant2_Value(byref(Constant2_Value))
    
    @_check_param_setter
    def setP_Delay_InitialCondition_j(self, value):
        """Set a new value for the scalar `Delay_InitialCondition_j`.

        Parameters
        ----------
        value : float
            New value for variable named Delay_InitialCondition_j
        """
        Delay_InitialCondition_j = c_double(value)
        self._lib.setP_Delay_InitialCondition_j(byref(Delay_InitialCondition_j))
    
    @_check_param_setter
    def setP_Delay_InitialCondition_l(self, value):
        """Set a new value for the scalar `Delay_InitialCondition_l`.

        Parameters
        ----------
        value : float
            New value for variable named Delay_InitialCondition_l
        """
        Delay_InitialCondition_l = c_double(value)
        self._lib.setP_Delay_InitialCondition_l(byref(Delay_InitialCondition_l))
    
    @_check_param_setter
    def setP_Delay_InitialCondition_jr(self, value):
        """Set a new value for the scalar `Delay_InitialCondition_jr`.

        Parameters
        ----------
        value : float
            New value for variable named Delay_InitialCondition_jr
        """
        Delay_InitialCondition_jr = c_double(value)
        self._lib.setP_Delay_InitialCondition_jr(byref(Delay_InitialCondition_jr))
    
    @_check_param_setter
    def setP_Constant3_Value(self, value):
        """Set a new value for the scalar `Constant3_Value`.

        Parameters
        ----------
        value : float
            New value for variable named Constant3_Value
        """
        Constant3_Value = c_double(value)
        self._lib.setP_Constant3_Value(byref(Constant3_Value))
    
    def setP(self, values):
        for values_, func in zip(values, [self.setP_DHWheatexchanger_A, self.setP_Primaryheatexchanger_A, self.setP_DHWreturnpipe_D, self.setP_DHWstorage_D, self.setP_DHWsupplypipe_D, self.setP_SHreturnpipe_D, self.setP_SHsupplypipe_D, self.setP_SHthermalemitters_D, self.setP_DHWstorage_H, self.setP_DHWreturnpipe_L, self.setP_DHWsupplypipe_L, self.setP_SHreturnpipe_L, self.setP_SHsupplypipe_L, self.setP_SHthermalemitters_L, self.setP_SHthermalemitters_T_air, self.setP_DHWstorage_T_amb, self.setP_DHWreturnpipe_T_duct, self.setP_DHWsupplypipe_T_duct, self.setP_SHreturnpipe_T_duct, self.setP_SHsupplypipe_T_duct, self.setP_DHWstorage_U, self.setP_SHthermalemitters_U, self.setP_DHWheatexchanger_U, self.setP_Primaryheatexchanger_U, self.setP_DHWstorage_V_min, self.setP_DHWstorage_V_var, self.setP_DHWstorage_eps, self.setP_DHWreturnpipe_m_min, self.setP_DHWsupplypipe_m_min, self.setP_SHreturnpipe_m_min, self.setP_SHsupplypipe_m_min, self.setP_SHthermalemitters_m_min, self.setP_DHWstorage_n, self.setP_SHthermalemitters_n_radiators, self.setP_SHthermalemitters_n_tubes, self.setP_DHWbypassvalve_unknown_T, self.setP_DHWstoragetopvalve_unknown_T, self.setP_DHWcoldwaterrefill_unknown_T, self.setP_DHWstoragebottomvalve_unknown_T, self.setP_SHbypassvalve_unknown_T, self.setP_SHDHWreturnvalve_unknown_T, self.setP_DHWbypassvalve_unknown_m, self.setP_DHWstoragetopvalve_unknown_m, self.setP_DHWcoldwaterrefill_unknown_m, self.setP_DHWstoragebottomvalve_unknown_m, self.setP_SHbypassvalve_unknown_m, self.setP_SHDHWreturnvalve_unknown_m, self.setP_Delay_InitialCondition, self.setP_Delay1_InitialCondition, self.setP_Constant1_Value, self.setP_Delay6_InitialCondition, self.setP_Delay5_InitialCondition, self.setP_Switch3_Threshold, self.setP_Constant5_Value, self.setP_Constant6_Value, self.setP_Switch2_Threshold, self.setP_Delay_InitialCondition_o, self.setP_Delay_InitialCondition_k, self.setP_Constant7_Value, self.setP_Switch_Threshold, self.setP_Delay_InitialCondition_o4, self.setP_Switch4_Threshold, self.setP_Constant_Value, self.setP_Constant4_Value, self.setP_Switch1_Threshold, self.setP_Delay2_InitialCondition, self.setP_Delay7_InitialCondition, self.setP_Constant2_Value, self.setP_Delay_InitialCondition_j, self.setP_Delay_InitialCondition_l, self.setP_Delay_InitialCondition_jr, self.setP_Constant3_Value]):
            func(values_)
    
    def setP_from_dict(self, parameters, debug=False):
        """Set some parameter values using a dict-like object.

        Please have a look at the top of this file for a list of parameters,
        or call `getP_as_dict`.

        """
        modified_params = {}
        for key, value in parameters.items():
            if value is not None:
                if debug: 
                    func = getattr(self, f"getP_{key}")
                    old_value = func()
                    if old_value != value:
                        modified_params[key] = old_value
                try:
                    func = getattr(self, f"setP_{key}")
                except:
                    raise NameError(f"Parameter '{key}' does not exist in the model.")
                func(value)
                
        if debug:
            print("DEBUG: modification of model parameters using a dict (setP_from_dict): ")
            
            for name in sorted(['DHWheatexchanger_A', 'Primaryheatexchanger_A', 'DHWreturnpipe_D', 'DHWstorage_D', 'DHWsupplypipe_D', 'SHreturnpipe_D', 'SHsupplypipe_D', 'SHthermalemitters_D', 'DHWstorage_H', 'DHWreturnpipe_L', 'DHWsupplypipe_L', 'SHreturnpipe_L', 'SHsupplypipe_L', 'SHthermalemitters_L', 'SHthermalemitters_T_air', 'DHWstorage_T_amb', 'DHWreturnpipe_T_duct', 'DHWsupplypipe_T_duct', 'SHreturnpipe_T_duct', 'SHsupplypipe_T_duct', 'DHWstorage_U', 'SHthermalemitters_U', 'DHWheatexchanger_U', 'Primaryheatexchanger_U', 'DHWstorage_V_min', 'DHWstorage_V_var', 'DHWstorage_eps', 'DHWreturnpipe_m_min', 'DHWsupplypipe_m_min', 'SHreturnpipe_m_min', 'SHsupplypipe_m_min', 'SHthermalemitters_m_min', 'DHWstorage_n', 'SHthermalemitters_n_radiators', 'SHthermalemitters_n_tubes', 'DHWbypassvalve_unknown_T', 'DHWstoragetopvalve_unknown_T', 'DHWcoldwaterrefill_unknown_T', 'DHWstoragebottomvalve_unknown_T', 'SHbypassvalve_unknown_T', 'SHDHWreturnvalve_unknown_T', 'DHWbypassvalve_unknown_m', 'DHWstoragetopvalve_unknown_m', 'DHWcoldwaterrefill_unknown_m', 'DHWstoragebottomvalve_unknown_m', 'SHbypassvalve_unknown_m', 'SHDHWreturnvalve_unknown_m', 'Delay_InitialCondition', 'Delay1_InitialCondition', 'Constant1_Value', 'Delay6_InitialCondition', 'Delay5_InitialCondition', 'Switch3_Threshold', 'Constant5_Value', 'Constant6_Value', 'Switch2_Threshold', 'Delay_InitialCondition_o', 'Delay_InitialCondition_k', 'Constant7_Value', 'Switch_Threshold', 'Delay_InitialCondition_o4', 'Switch4_Threshold', 'Constant_Value', 'Constant4_Value', 'Switch1_Threshold', 'Delay2_InitialCondition', 'Delay7_InitialCondition', 'Constant2_Value', 'Delay_InitialCondition_j', 'Delay_InitialCondition_l', 'Delay_InitialCondition_jr', 'Constant3_Value']):
                func = getattr(self, f"getP_{name}")
                value = func()
                print(f"    - {name}: {value}", end="")
                if name in modified_params:
                    print(max(60-len(name), 0) * " ", f" (previous value: {modified_params[name]})")
                else:
                    print("")
            
    


    def _initialize(self, time_step: int):
        """Initialize the physical model using time step `time_step`. 
        
        Must be called at the very beginning of the script.

        Parameters
        ----------
        time_step : int, seconds

        Notes
        -----
        Time step must not be set outside of this function.
        """
        stepSize0 = c_int(time_step)
        self._lib.initialize(byref(stepSize0))
        if Interface._first_instance:
            print("Decreasing time step has a limited effect on running time since the substation models \
makes use of dedicated ODE solver at the component level (with their own time step)")
    

    def run_physical_model(self, inputs):
        """Execute the physical model given specified inputs.
         
        Parameters
        ----------
        inputs : dict-like
            Mapping {input_name: value} where:
            
            - each `input_name` corresponds to an input port in the Simulink version of this model
            - each `value` must be a float scalar or a 1-D numerical array, as defined in the Simulink version of this model

        Raises
        ------
        ValueError
            If keys of `inputs` do not match the model inputs names.
        """
        self._was_called = True

        # converting the dict into a list, after checking that all requried inputs are specified
        inputs_ = [0] * len(Interface._mapper_U)
        s1 = set(inputs) - set(Interface._mapper_U.values())
        s2 = set(Interface._mapper_U.values()) - set(inputs)
        if s1 - s2:
            raise ValueError(f"The following inputs do not exist in the model: {s1-s2}.")
        if s2 - s1:
            raise ValueError(f"The following values are expected by the model as inputs but where not found in passed mapping: {s2-s1}.")
        
        for k in range(len(Interface._mapper_U)):               # keeps the order expected by the `_setU` methods
            value = inputs[Interface._mapper_U[k]]
            inputs_[k] = value
        
        # assigning all inputs at one 
        self._setU(inputs_)
               
        # running the model
        if self._hide_outputs:
            with self._pipes() as (out, err):
                self._lib.parallel_SST_model_step() 
        else:
            self._lib.parallel_SST_model_step() 
            
        # fetching outputs and converting to a dict            
        outputs_ = self._getY()  
        outputs = {Interface._mapper_Y[k]: outputs_[k] for k in range(len(Interface._mapper_Y))}
        return outputs
        



    def get_SimulationTime(self):
        """
        Return time spent in simulation, in seconds.
        """
        SimulationTime = c_double()
        self._lib._get_SimulationTime(byref(SimulationTime))
        return SimulationTime.value

    