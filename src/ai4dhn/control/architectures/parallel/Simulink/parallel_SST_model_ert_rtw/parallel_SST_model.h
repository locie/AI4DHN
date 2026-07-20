/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: parallel_SST_model.h
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

#ifndef parallel_SST_model_h_
#define parallel_SST_model_h_
#ifndef parallel_SST_model_COMMON_INCLUDES_
#define parallel_SST_model_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* parallel_SST_model_COMMON_INCLUDES_ */

#include "parallel_SST_model_types.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct
{
  real_T Clock;                        /* 'Clock' (':70:540') */
  real_T Clock_o;                      /* 'Clock' (':71:540') */
  real_T Clock_h;                      /* 'Clock' (':206:5') */
  real_T Clock_c;                      /* 'Clock' (':1:540') */
  real_T Clock_hf;                     /* 'Clock' (':637:277') */
  real_T Clock_b;                      /* 'Clock' (':2:540') */
  real_T T_out;                        /* 'thermal_pipe_function' (':2:523') */
  real_T T_2_out;                      /* 'heat_exchanger_function' (':73:5') */
  real_T T_3_;                         /* '3WV_function' (':905:1') */
  real_T Tn;                           /* 'storage_TC_func' (':206:8') */
  real_T T_1_out;                      /* 'heat_exchanger_function' (':72:5') */
}
B_parallel_SST_model_T;

/* Block states (default storage) for system 'parallel_SST_model' */
typedef struct
{
  real_T Delay_DSTATE;                 /* 'Delay' (':899') */
  real_T Delay1_DSTATE;                /* 'Delay1' (':900') */
  real_T Delay6_DSTATE;                /* 'Delay6' (':890') */
  real_T Delay5_DSTATE;                /* 'Delay5' (':889') */
  real_T Delay_DSTATE_h;               /* 'Delay' (':70:541') */
  real_T Delay_DSTATE_f;               /* 'Delay' (':71:541') */
  real_T Delay_DSTATE_l;               /* 'Delay' (':206:6') */
  real_T Delay2_DSTATE;                /* 'Delay2' (':894') */
  real_T Delay7_DSTATE;                /* 'Delay7' (':896') */
  real_T Delay_DSTATE_o;               /* 'Delay' (':1:541') */
  real_T Delay_DSTATE_i;               /* 'Delay' (':637:278') */
  real_T Delay_DSTATE_m;               /* 'Delay' (':2:541') */
  real_T A;                        /* 'thermal_emitters_function' (':637:65') */
  real_T timeIdx;                  /* 'thermal_emitters_function' (':637:65') */
  real_T k;                            /* 'thermal_pipe_function' (':1:523') */
  real_T A_b;                          /* 'thermal_pipe_function' (':1:523') */
  real_T timeIdx_c;                    /* 'thermal_pipe_function' (':1:523') */
  real_T k_o;                          /* 'thermal_pipe_function' (':2:523') */
  real_T A_k;                          /* 'thermal_pipe_function' (':2:523') */
  real_T timeIdx_m;                    /* 'thermal_pipe_function' (':2:523') */
  real_T k_j;                          /* 'thermal_pipe_function' (':70:523') */
  real_T A_i;                          /* 'thermal_pipe_function' (':70:523') */
  real_T timeIdx_cc;                   /* 'thermal_pipe_function' (':70:523') */
  real_T V1;                           /* 'storage_TC_func' (':206:8') */
  real_T Vn;                           /* 'storage_TC_func' (':206:8') */
  real_T T_avg;                        /* 'storage_TC_func' (':206:8') */
  real_T T_mid;                        /* 'storage_TC_func' (':206:8') */
  real_T timeIdx_f;                    /* 'storage_TC_func' (':206:8') */
  real_T k_h;                          /* 'thermal_pipe_function' (':71:523') */
  real_T A_j;                          /* 'thermal_pipe_function' (':71:523') */
  real_T timeIdx_p;                    /* 'thermal_pipe_function' (':71:523') */
  captured_var_parallel_SST_mod_T tau; /* 'thermal_pipe_function' (':71:523') */
  captured_var_parallel_SST_mod_T n_dx;/* 'thermal_pipe_function' (':71:523') */
  captured_var_parallel_SST_mod_T dx;  /* 'thermal_pipe_function' (':71:523') */
  captured_var_parallel_SST_mod_T tau_m;/* 'thermal_pipe_function' (':70:523') */
  captured_var_parallel_SST_mod_T n_dx_p;/* 'thermal_pipe_function' (':70:523') */
  captured_var_parallel_SST_mod_T dx_g;/* 'thermal_pipe_function' (':70:523') */
  captured_var_parallel_SST_mod_T tau_h;/* 'thermal_pipe_function' (':2:523') */
  captured_var_parallel_SST_mod_T n_dx_j;/* 'thermal_pipe_function' (':2:523') */
  captured_var_parallel_SST_mod_T dx_i;/* 'thermal_pipe_function' (':2:523') */
  captured_var_parallel_SST_mod_T tau_h4;/* 'thermal_pipe_function' (':1:523') */
  captured_var_parallel_SST_mod_T n_dx_l;/* 'thermal_pipe_function' (':1:523') */
  captured_var_parallel_SST_mod_T dx_ij;/* 'thermal_pipe_function' (':1:523') */
  captured_var_parallel_SST_mod_T n_dx_jn;
                                   /* 'thermal_emitters_function' (':637:65') */
  captured_var_parallel_SST_mod_T dx_k;
                                   /* 'thermal_emitters_function' (':637:65') */
  captured_var_parallel_SST_mod_T tau_n;
                                   /* 'thermal_emitters_function' (':637:65') */
  emxArray_real_T_parallel_SST__T* T;
                                   /* 'thermal_emitters_function' (':637:65') */
  emxArray_real_T_parallel_SST__T* T_m;/* 'thermal_pipe_function' (':1:523') */
  emxArray_real_T_parallel_SST__T* T_o;/* 'thermal_pipe_function' (':2:523') */
  emxArray_real_T_parallel_SST__T* T_k;/* 'thermal_pipe_function' (':70:523') */
  emxArray_real_T_parallel_SST__T* T_init;/* 'storage_TC_func' (':206:8') */
  emxArray_real_T_parallel_SST__T* T_p;/* 'thermal_pipe_function' (':71:523') */
  int32_T SFunction_DIMS9;             /* 'storage_TC_func' (':206:8') */
  boolean_T tau_not_empty;         /* 'thermal_emitters_function' (':637:65') */
  boolean_T k_not_empty;               /* 'thermal_pipe_function' (':1:523') */
  boolean_T k_not_empty_b;             /* 'thermal_pipe_function' (':2:523') */
  boolean_T k_not_empty_h;             /* 'thermal_pipe_function' (':70:523') */
  boolean_T V1_not_empty;              /* 'storage_TC_func' (':206:8') */
  boolean_T k_not_empty_f;             /* 'thermal_pipe_function' (':71:523') */
}
DW_parallel_SST_model_T;

/* External inputs (root inport signals with default storage) */
typedef struct
{
  real_T m_prim;                       /* 'm_prim' (':345') */
  real_T T_prim_in;                    /* 'T_prim_in' (':346') */
  real_T m_SH_dir;                     /* 'm_SH_dir' (':340') */
  real_T m_SH_3V;                      /* 'm_SH_3V' (':344') */
  real_T m_DHW_sec;                    /* 'm_DHW_sec' (':853') */
  real_T m_DHW_w;                      /* 'm_DHW_w' (':341') */
  real_T m_DHW_recirc;                 /* 'm_DHW_recirc' (':1067') */
  real_T T_cold;                       /* 'T_cold' (':347') */
  real_T m_DHW_dir;                    /* 'm_DHW_dir' (':348') */
  real_T m_DHW_3V;                     /* 'm_DHW_3V' (':349') */
}
ExtU_parallel_SST_model_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct
{
  real_T T_sec_in;                     /* 'T_sec_in' (':428') */
  real_T T_DHW_out;                    /* 'T_DHW_out' (':429') */
  real_T T_out;                        /* 'T_out' (':430') */
  real_T T_DHW_sec_out;                /* 'T_DHW_sec_out' (':431') */
  real_T T_DHW_sec_in;                 /* 'T_DHW_sec_in' (':432') */
  real_T T_DHW_prim_in;                /* 'T_DHW_prim_in' (':433') */
  real_T T_DHW_prim_out;               /* 'T_DHW_prim_out' (':434') */
  real_T T_SH_out;                     /* 'T_SH_out' (':435') */
  real_T T_SH_in;                      /* 'T_SH_in' (':436') */
  real_T T_prim_out;                   /* 'T_prim_out' (':437') */
  real_T T_sec_out;                    /* 'T_sec_out' (':438') */
  real_T T_SH_emitter_out;             /* 'T_SH_emitter_out' (':439') */
  real_T T_stor_n;                     /* 'T_stor_n' (':440') */
  real_T Q_SH;                         /* 'Q_SH' (':441') */
  real_T Q_primary_HX;                 /* 'Q_primary_HX' (':442') */
  real_T Q_DHW_HX;                     /* 'Q_DHW_HX' (':443') */
  real_T m_DHW;                        /* 'm_DHW' (':445') */
  real_T Q_SH_supply;                  /* 'Q_SH_supply' (':446') */
  real_T Q_SH_return;                  /* 'Q_SH_return' (':447') */
  real_T T_stor_out;                   /* 'T_stor_out' (':448') */
  real_T T_stor_avg;                   /* 'T_stor_avg' (':449') */
  real_T T_stor_mid;                   /* 'T_stor_mid' (':450') */
  real_T T_stor_std;                   /* 'T_stor_std' (':451') */
  real_T T_stor_half;                  /* 'T_stor_half' (':452') */
  real_T T_stor_1;                     /* 'T_stor_1' (':453') */
  real_T m_DHW_prim;                   /* 'm_DHW_prim' (':454') */
  real_T m_sec;                        /* 'm_sec' (':455') */
  real_T m_SH;                         /* 'm_SH' (':456') */
  real_T Q_DHW_supply;                 /* 'Q_DHW_supply' (':457') */
  real_T Q_DHW_return;                 /* 'Q_DHW_return' (':458') */
  real_T efficiency_primary_HX;        /* 'efficiency_primary_HX' (':459') */
  real_T efficiency_DHW_HX;            /* 'efficiency_DHW_HX' (':460') */
  real_T T_DHW_in;                     /* 'T_DHW_in' (':607') */
  real_T T_SH_emitter_in;              /* 'T_SH_emitter_in' (':614') */
  real_T T_stor_in;                    /* 'T_stor_in' (':880') */
  real_T m_DHW_stor;                   /* 'm_DHW_stor' (':1073') */
}
ExtY_parallel_SST_model_T;

/* Parameters (default storage) */
struct P_parallel_SST_model_T_
{
  real_T DHWheatexchanger_A;           /* Mask Parameter: DHWheatexchanger_A
                                        * Referenced by: 'heat_exchanger_function' (':72:5')
                                        */
  real_T Primaryheatexchanger_A;       /* Mask Parameter: Primaryheatexchanger_A
                                        * Referenced by: 'heat_exchanger_function' (':73:5')
                                        */
  real_T DHWreturnpipe_D;              /* Mask Parameter: DHWreturnpipe_D
                                        * Referenced by: 'thermal_pipe_function' (':71:523')
                                        */
  real_T DHWstorage_D;                 /* Mask Parameter: DHWstorage_D
                                        * Referenced by: 'storage_TC_func' (':206:8')
                                        */
  real_T DHWsupplypipe_D;              /* Mask Parameter: DHWsupplypipe_D
                                        * Referenced by: 'thermal_pipe_function' (':70:523')
                                        */
  real_T SHreturnpipe_D;               /* Mask Parameter: SHreturnpipe_D
                                        * Referenced by: 'thermal_pipe_function' (':2:523')
                                        */
  real_T SHsupplypipe_D;               /* Mask Parameter: SHsupplypipe_D
                                        * Referenced by: 'thermal_pipe_function' (':1:523')
                                        */
  real_T SHthermalemitters_D;          /* Mask Parameter: SHthermalemitters_D
                                        * Referenced by: 'thermal_emitters_function' (':637:65')
                                        */
  real_T DHWstorage_H;                 /* Mask Parameter: DHWstorage_H
                                        * Referenced by: 'storage_TC_func' (':206:8')
                                        */
  real_T DHWreturnpipe_L;              /* Mask Parameter: DHWreturnpipe_L
                                        * Referenced by: 'thermal_pipe_function' (':71:523')
                                        */
  real_T DHWsupplypipe_L;              /* Mask Parameter: DHWsupplypipe_L
                                        * Referenced by: 'thermal_pipe_function' (':70:523')
                                        */
  real_T SHreturnpipe_L;               /* Mask Parameter: SHreturnpipe_L
                                        * Referenced by: 'thermal_pipe_function' (':2:523')
                                        */
  real_T SHsupplypipe_L;               /* Mask Parameter: SHsupplypipe_L
                                        * Referenced by: 'thermal_pipe_function' (':1:523')
                                        */
  real_T SHthermalemitters_L;          /* Mask Parameter: SHthermalemitters_L
                                        * Referenced by: 'thermal_emitters_function' (':637:65')
                                        */
  real_T SHthermalemitters_T_air;     /* Mask Parameter: SHthermalemitters_T_air
                                       * Referenced by: 'thermal_emitters_function' (':637:65')
                                       */
  real_T DHWstorage_T_amb;             /* Mask Parameter: DHWstorage_T_amb
                                        * Referenced by: 'storage_TC_func' (':206:8')
                                        */
  real_T DHWreturnpipe_T_duct;         /* Mask Parameter: DHWreturnpipe_T_duct
                                        * Referenced by: 'thermal_pipe_function' (':71:523')
                                        */
  real_T DHWsupplypipe_T_duct;         /* Mask Parameter: DHWsupplypipe_T_duct
                                        * Referenced by: 'thermal_pipe_function' (':70:523')
                                        */
  real_T SHreturnpipe_T_duct;          /* Mask Parameter: SHreturnpipe_T_duct
                                        * Referenced by: 'thermal_pipe_function' (':2:523')
                                        */
  real_T SHsupplypipe_T_duct;          /* Mask Parameter: SHsupplypipe_T_duct
                                        * Referenced by: 'thermal_pipe_function' (':1:523')
                                        */
  real_T DHWstorage_U;                 /* Mask Parameter: DHWstorage_U
                                        * Referenced by: 'storage_TC_func' (':206:8')
                                        */
  real_T SHthermalemitters_U;          /* Mask Parameter: SHthermalemitters_U
                                        * Referenced by: 'thermal_emitters_function' (':637:65')
                                        */
  real_T DHWheatexchanger_U;           /* Mask Parameter: DHWheatexchanger_U
                                        * Referenced by: 'heat_exchanger_function' (':72:5')
                                        */
  real_T Primaryheatexchanger_U;       /* Mask Parameter: Primaryheatexchanger_U
                                        * Referenced by: 'heat_exchanger_function' (':73:5')
                                        */
  real_T DHWstorage_V_min;             /* Mask Parameter: DHWstorage_V_min
                                        * Referenced by: 'storage_TC_func' (':206:8')
                                        */
  real_T DHWstorage_V_var;             /* Mask Parameter: DHWstorage_V_var
                                        * Referenced by: 'storage_TC_func' (':206:8')
                                        */
  real_T DHWstorage_eps;               /* Mask Parameter: DHWstorage_eps
                                        * Referenced by: 'storage_TC_func' (':206:8')
                                        */
  real_T DHWreturnpipe_m_min;          /* Mask Parameter: DHWreturnpipe_m_min
                                        * Referenced by: 'thermal_pipe_function' (':71:523')
                                        */
  real_T DHWsupplypipe_m_min;          /* Mask Parameter: DHWsupplypipe_m_min
                                        * Referenced by: 'thermal_pipe_function' (':70:523')
                                        */
  real_T SHreturnpipe_m_min;           /* Mask Parameter: SHreturnpipe_m_min
                                        * Referenced by: 'thermal_pipe_function' (':2:523')
                                        */
  real_T SHsupplypipe_m_min;           /* Mask Parameter: SHsupplypipe_m_min
                                        * Referenced by: 'thermal_pipe_function' (':1:523')
                                        */
  real_T SHthermalemitters_m_min;     /* Mask Parameter: SHthermalemitters_m_min
                                       * Referenced by: 'thermal_emitters_function' (':637:65')
                                       */
  real_T DHWstorage_n;                 /* Mask Parameter: DHWstorage_n
                                        * Referenced by: 'storage_TC_func' (':206:8')
                                        */
  real_T SHthermalemitters_n_radiators;
                                /* Mask Parameter: SHthermalemitters_n_radiators
                                 * Referenced by: 'thermal_emitters_function' (':637:65')
                                 */
  real_T SHthermalemitters_n_tubes; /* Mask Parameter: SHthermalemitters_n_tubes
                                     * Referenced by: 'thermal_emitters_function' (':637:65')
                                     */
  real_T DHWbypassvalve_unknown_T;   /* Mask Parameter: DHWbypassvalve_unknown_T
                                      * Referenced by: '3WV_function' (':903:1')
                                      */
  real_T DHWstoragetopvalve_unknown_T;
                                 /* Mask Parameter: DHWstoragetopvalve_unknown_T
                                  * Referenced by: '3WV_function' (':906:1')
                                  */
  real_T DHWcoldwaterrefill_unknown_T;
                                 /* Mask Parameter: DHWcoldwaterrefill_unknown_T
                                  * Referenced by: '3WV_function' (':1075:1')
                                  */
  real_T DHWstoragebottomvalve_unknown_T;
                              /* Mask Parameter: DHWstoragebottomvalve_unknown_T
                               * Referenced by: '3WV_function' (':905:1')
                               */
  real_T SHbypassvalve_unknown_T;     /* Mask Parameter: SHbypassvalve_unknown_T
                                       * Referenced by: '3WV_function' (':907:1')
                                       */
  real_T SHDHWreturnvalve_unknown_T;
                                   /* Mask Parameter: SHDHWreturnvalve_unknown_T
                                    * Referenced by: '3WV_function' (':904:1')
                                    */
  real_T DHWbypassvalve_unknown_m;   /* Mask Parameter: DHWbypassvalve_unknown_m
                                      * Referenced by: '3WV_function' (':903:1')
                                      */
  real_T DHWstoragetopvalve_unknown_m;
                                 /* Mask Parameter: DHWstoragetopvalve_unknown_m
                                  * Referenced by: '3WV_function' (':906:1')
                                  */
  real_T DHWcoldwaterrefill_unknown_m;
                                 /* Mask Parameter: DHWcoldwaterrefill_unknown_m
                                  * Referenced by: '3WV_function' (':1075:1')
                                  */
  real_T DHWstoragebottomvalve_unknown_m;
                              /* Mask Parameter: DHWstoragebottomvalve_unknown_m
                               * Referenced by: '3WV_function' (':905:1')
                               */
  real_T SHbypassvalve_unknown_m;     /* Mask Parameter: SHbypassvalve_unknown_m
                                       * Referenced by: '3WV_function' (':907:1')
                                       */
  real_T SHDHWreturnvalve_unknown_m;
                                   /* Mask Parameter: SHDHWreturnvalve_unknown_m
                                    * Referenced by: '3WV_function' (':904:1')
                                    */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: 'Delay' (':899')
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: 'Delay1' (':900')
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: 'Constant1' (':779')
                                        */
  real_T Delay6_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: 'Delay6' (':890')
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: 'Delay5' (':889')
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: 'Switch3' (':870')
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: 'Constant5' (':814')
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: 'Constant6' (':815')
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: 'Switch2' (':813')
                                        */
  real_T Delay_InitialCondition_o;     /* Expression: 0.0
                                        * Referenced by: 'Delay' (':70:541')
                                        */
  real_T Delay_InitialCondition_k;     /* Expression: 0.0
                                        * Referenced by: 'Delay' (':71:541')
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: 'Constant7' (':1076')
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: 'Switch' (':225')
                                        */
  real_T Delay_InitialCondition_o4;    /* Expression: 0.0
                                        * Referenced by: 'Delay' (':206:6')
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: 'Switch4' (':874')
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: 'Constant' (':795')
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: 'Constant4' (':796')
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: 'Switch1' (':794')
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: 'Delay2' (':894')
                                        */
  real_T Delay7_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: 'Delay7' (':896')
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: 'Constant2' (':766')
                                        */
  real_T Delay_InitialCondition_j;     /* Expression: 0.0
                                        * Referenced by: 'Delay' (':1:541')
                                        */
  real_T Delay_InitialCondition_l;     /* Expression: 0.0
                                        * Referenced by: 'Delay' (':637:278')
                                        */
  real_T Delay_InitialCondition_jr;    /* Expression: 0.0
                                        * Referenced by: 'Delay' (':2:541')
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: 'Constant3' (':787')
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_parallel_SST_model_T
{
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct
  {
    uint32_T clockTick0;
    time_T stepSize0;
    uint16_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  }
  Timing;
};

/* Block parameters (default storage) */
extern P_parallel_SST_model_T parallel_SST_model_P;

/* Block signals (default storage) */
extern B_parallel_SST_model_T parallel_SST_model_B;

/* Block states (default storage) */
extern DW_parallel_SST_model_T parallel_SST_model_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_parallel_SST_model_T parallel_SST_model_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_parallel_SST_model_T parallel_SST_model_Y;

/* Model entry point functions */
extern void parallel_SST_model_initialize(void);
extern void parallel_SST_model_step(void);
extern void parallel_SST_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_parallel_SST_model_T *const parallel_SST_model_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 * Block synthesized block : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is 'block_name' ('SID'), where block_name is the name of the block
 * and SID is the Simulink identifier of the block without the model name.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system(':3')    - opens block with Simulink identifier 'model:3'
 */
#endif                                 /* parallel_SST_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
