/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: parallel_SST_model_private.h
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

#ifndef parallel_SST_model_private_h_
#define parallel_SST_model_private_h_
#include "rtwtypes.h"
#include "parallel_SST_model_types.h"
#include "parallel_SST_model.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void parallel_SST_model_uWV_function(real_T rtu_m_1, real_T rtu_T_1,
  real_T rtu_m_2, real_T rtu_T_2, real_T rtu_m_3, real_T rtu_T_3, real_T
  rtu_merge, real_T *rty_m_1_, real_T *rty_T_1_, real_T *rty_m_2_, real_T
  *rty_T_2_, real_T *rty_m_3_, real_T *rty_T_3_, real_T rtp_unknown_T, real_T
  rtp_unknown_m);
extern void paralle_heat_exchanger_function(real_T rtu_m_1, real_T rtu_m_2,
  real_T rtu_T_1_in, real_T rtu_T_2_in, real_T *rty_T_1_out, real_T *rty_T_2_out,
  real_T *rty_Q, real_T *rty_efficiency, real_T rtp_A, real_T rtp_U);

#endif                                 /* parallel_SST_model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
