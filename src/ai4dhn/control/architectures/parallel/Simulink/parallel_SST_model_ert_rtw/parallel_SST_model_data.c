/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: parallel_SST_model_data.c
 *
 * Code generated for Simulink model 'parallel_SST_model'.
 *
 * Model version                  : 1.240
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Jul  7 08:49:59 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "parallel_SST_model.h"

/* Block parameters (default storage) */
P_parallel_SST_model_T parallel_SST_model_P =
{
  /* Mask Parameter: DHWheatexchanger_A
   * Referenced by: 'heat_exchanger_function' (':72:5')
   */
  100.0,

  /* Mask Parameter: Primaryheatexchanger_A
   * Referenced by: 'heat_exchanger_function' (':73:5')
   */
  100.0,

  /* Mask Parameter: DHWreturnpipe_D
   * Referenced by: 'thermal_pipe_function' (':71:523')
   */
  0.03,

  /* Mask Parameter: DHWstorage_D
   * Referenced by: 'storage_TC_func' (':206:8')
   */
  1.0,

  /* Mask Parameter: DHWsupplypipe_D
   * Referenced by: 'thermal_pipe_function' (':70:523')
   */
  0.03,

  /* Mask Parameter: SHreturnpipe_D
   * Referenced by: 'thermal_pipe_function' (':2:523')
   */
  0.05,

  /* Mask Parameter: SHsupplypipe_D
   * Referenced by: 'thermal_pipe_function' (':1:523')
   */
  0.05,

  /* Mask Parameter: SHthermalemitters_D
   * Referenced by: 'thermal_emitters_function' (':637:65')
   */
  0.02,

  /* Mask Parameter: DHWstorage_H
   * Referenced by: 'storage_TC_func' (':206:8')
   */
  1.5,

  /* Mask Parameter: DHWreturnpipe_L
   * Referenced by: 'thermal_pipe_function' (':71:523')
   */
  50.0,

  /* Mask Parameter: DHWsupplypipe_L
   * Referenced by: 'thermal_pipe_function' (':70:523')
   */
  50.0,

  /* Mask Parameter: SHreturnpipe_L
   * Referenced by: 'thermal_pipe_function' (':2:523')
   */
  50.0,

  /* Mask Parameter: SHsupplypipe_L
   * Referenced by: 'thermal_pipe_function' (':1:523')
   */
  50.0,

  /* Mask Parameter: SHthermalemitters_L
   * Referenced by: 'thermal_emitters_function' (':637:65')
   */
  0.46,

  /* Mask Parameter: SHthermalemitters_T_air
   * Referenced by: 'thermal_emitters_function' (':637:65')
   */
  20.0,

  /* Mask Parameter: DHWstorage_T_amb
   * Referenced by: 'storage_TC_func' (':206:8')
   */
  20.0,

  /* Mask Parameter: DHWreturnpipe_T_duct
   * Referenced by: 'thermal_pipe_function' (':71:523')
   */
  15.0,

  /* Mask Parameter: DHWsupplypipe_T_duct
   * Referenced by: 'thermal_pipe_function' (':70:523')
   */
  15.0,

  /* Mask Parameter: SHreturnpipe_T_duct
   * Referenced by: 'thermal_pipe_function' (':2:523')
   */
  15.0,

  /* Mask Parameter: SHsupplypipe_T_duct
   * Referenced by: 'thermal_pipe_function' (':1:523')
   */
  15.0,

  /* Mask Parameter: DHWstorage_U
   * Referenced by: 'storage_TC_func' (':206:8')
   */
  5.0,

  /* Mask Parameter: SHthermalemitters_U
   * Referenced by: 'thermal_emitters_function' (':637:65')
   */
  10.0,

  /* Mask Parameter: DHWheatexchanger_U
   * Referenced by: 'heat_exchanger_function' (':72:5')
   */
  1000.0,

  /* Mask Parameter: Primaryheatexchanger_U
   * Referenced by: 'heat_exchanger_function' (':73:5')
   */
  1000.0,

  /* Mask Parameter: DHWstorage_V_min
   * Referenced by: 'storage_TC_func' (':206:8')
   */
  10.0,

  /* Mask Parameter: DHWstorage_V_var
   * Referenced by: 'storage_TC_func' (':206:8')
   */
  60.0,

  /* Mask Parameter: DHWstorage_eps
   * Referenced by: 'storage_TC_func' (':206:8')
   */
  2.0,

  /* Mask Parameter: DHWreturnpipe_m_min
   * Referenced by: 'thermal_pipe_function' (':71:523')
   */
  0.1,

  /* Mask Parameter: DHWsupplypipe_m_min
   * Referenced by: 'thermal_pipe_function' (':70:523')
   */
  0.1,

  /* Mask Parameter: SHreturnpipe_m_min
   * Referenced by: 'thermal_pipe_function' (':2:523')
   */
  0.09,

  /* Mask Parameter: SHsupplypipe_m_min
   * Referenced by: 'thermal_pipe_function' (':1:523')
   */
  0.09,

  /* Mask Parameter: SHthermalemitters_m_min
   * Referenced by: 'thermal_emitters_function' (':637:65')
   */
  0.09,

  /* Mask Parameter: DHWstorage_n
   * Referenced by: 'storage_TC_func' (':206:8')
   */
  61.0,

  /* Mask Parameter: SHthermalemitters_n_radiators
   * Referenced by: 'thermal_emitters_function' (':637:65')
   */
  12.0,

  /* Mask Parameter: SHthermalemitters_n_tubes
   * Referenced by: 'thermal_emitters_function' (':637:65')
   */
  136.0,

  /* Mask Parameter: DHWbypassvalve_unknown_T
   * Referenced by: '3WV_function' (':903:1')
   */
  3.0,

  /* Mask Parameter: DHWstoragetopvalve_unknown_T
   * Referenced by: '3WV_function' (':906:1')
   */
  3.0,

  /* Mask Parameter: DHWcoldwaterrefill_unknown_T
   * Referenced by: '3WV_function' (':1075:1')
   */
  3.0,

  /* Mask Parameter: DHWstoragebottomvalve_unknown_T
   * Referenced by: '3WV_function' (':905:1')
   */
  3.0,

  /* Mask Parameter: SHbypassvalve_unknown_T
   * Referenced by: '3WV_function' (':907:1')
   */
  3.0,

  /* Mask Parameter: SHDHWreturnvalve_unknown_T
   * Referenced by: '3WV_function' (':904:1')
   */
  3.0,

  /* Mask Parameter: DHWbypassvalve_unknown_m
   * Referenced by: '3WV_function' (':903:1')
   */
  3.0,

  /* Mask Parameter: DHWstoragetopvalve_unknown_m
   * Referenced by: '3WV_function' (':906:1')
   */
  3.0,

  /* Mask Parameter: DHWcoldwaterrefill_unknown_m
   * Referenced by: '3WV_function' (':1075:1')
   */
  3.0,

  /* Mask Parameter: DHWstoragebottomvalve_unknown_m
   * Referenced by: '3WV_function' (':905:1')
   */
  3.0,

  /* Mask Parameter: SHbypassvalve_unknown_m
   * Referenced by: '3WV_function' (':907:1')
   */
  3.0,

  /* Mask Parameter: SHDHWreturnvalve_unknown_m
   * Referenced by: '3WV_function' (':904:1')
   */
  3.0,

  /* Expression: 0.0
   * Referenced by: 'Delay' (':899')
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: 'Delay1' (':900')
   */
  0.0,

  /* Expression: 1
   * Referenced by: 'Constant1' (':779')
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: 'Delay6' (':890')
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: 'Delay5' (':889')
   */
  0.0,

  /* Expression: 0
   * Referenced by: 'Switch3' (':870')
   */
  0.0,

  /* Expression: 0
   * Referenced by: 'Constant5' (':814')
   */
  0.0,

  /* Expression: 1
   * Referenced by: 'Constant6' (':815')
   */
  1.0,

  /* Expression: 0
   * Referenced by: 'Switch2' (':813')
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: 'Delay' (':70:541')
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: 'Delay' (':71:541')
   */
  0.0,

  /* Expression: 1
   * Referenced by: 'Constant7' (':1076')
   */
  1.0,

  /* Expression: 0
   * Referenced by: 'Switch' (':225')
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: 'Delay' (':206:6')
   */
  0.0,

  /* Expression: 0
   * Referenced by: 'Switch4' (':874')
   */
  0.0,

  /* Expression: 0
   * Referenced by: 'Constant' (':795')
   */
  0.0,

  /* Expression: 1
   * Referenced by: 'Constant4' (':796')
   */
  1.0,

  /* Expression: 0
   * Referenced by: 'Switch1' (':794')
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: 'Delay2' (':894')
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: 'Delay7' (':896')
   */
  0.0,

  /* Expression: 1
   * Referenced by: 'Constant2' (':766')
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: 'Delay' (':1:541')
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: 'Delay' (':637:278')
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: 'Delay' (':2:541')
   */
  0.0,

  /* Expression: 1
   * Referenced by: 'Constant3' (':787')
   */
  1.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
