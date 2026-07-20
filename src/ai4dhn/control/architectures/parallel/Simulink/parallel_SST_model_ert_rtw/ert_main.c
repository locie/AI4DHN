/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "parallel_SST_model.h"        /* Model header file */

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag)
  {
    rtmSetErrorStatus(parallel_SST_model_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  parallel_SST_model_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example main function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific. This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  parallel_SST_model_initialize();

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 60.0 seconds (base rate of the model) here.
   * The call syntax for rt_OneStep is
   *
   *  rt_OneStep();
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(parallel_SST_model_M) == (NULL))
  {
    /*  Perform application tasks here */
  }

  /* Terminate model */
  parallel_SST_model_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */


/* ======
GETTERS
=======*/

//-- U --

void getU_m_prim(real_T * m_prim){
        *m_prim = parallel_SST_model_U.m_prim;
}
    
void getU_T_prim_in(real_T * T_prim_in){
        *T_prim_in = parallel_SST_model_U.T_prim_in;
}
    
void getU_m_SH_dir(real_T * m_SH_dir){
        *m_SH_dir = parallel_SST_model_U.m_SH_dir;
}
    
void getU_m_SH_3V(real_T * m_SH_3V){
        *m_SH_3V = parallel_SST_model_U.m_SH_3V;
}
    
void getU_m_DHW_sec(real_T * m_DHW_sec){
        *m_DHW_sec = parallel_SST_model_U.m_DHW_sec;
}
    
void getU_m_DHW_w(real_T * m_DHW_w){
        *m_DHW_w = parallel_SST_model_U.m_DHW_w;
}
    
void getU_m_DHW_recirc(real_T * m_DHW_recirc){
        *m_DHW_recirc = parallel_SST_model_U.m_DHW_recirc;
}
    
void getU_T_cold(real_T * T_cold){
        *T_cold = parallel_SST_model_U.T_cold;
}
    
void getU_m_DHW_dir(real_T * m_DHW_dir){
        *m_DHW_dir = parallel_SST_model_U.m_DHW_dir;
}
    
void getU_m_DHW_3V(real_T * m_DHW_3V){
        *m_DHW_3V = parallel_SST_model_U.m_DHW_3V;
}
    //-- Y --

void getY_T_sec_in(real_T * T_sec_in){
        *T_sec_in = parallel_SST_model_Y.T_sec_in;
}
    
void getY_T_DHW_out(real_T * T_DHW_out){
        *T_DHW_out = parallel_SST_model_Y.T_DHW_out;
}
    
void getY_T_out(real_T * T_out){
        *T_out = parallel_SST_model_Y.T_out;
}
    
void getY_T_DHW_sec_out(real_T * T_DHW_sec_out){
        *T_DHW_sec_out = parallel_SST_model_Y.T_DHW_sec_out;
}
    
void getY_T_DHW_sec_in(real_T * T_DHW_sec_in){
        *T_DHW_sec_in = parallel_SST_model_Y.T_DHW_sec_in;
}
    
void getY_T_DHW_prim_in(real_T * T_DHW_prim_in){
        *T_DHW_prim_in = parallel_SST_model_Y.T_DHW_prim_in;
}
    
void getY_T_DHW_prim_out(real_T * T_DHW_prim_out){
        *T_DHW_prim_out = parallel_SST_model_Y.T_DHW_prim_out;
}
    
void getY_T_SH_out(real_T * T_SH_out){
        *T_SH_out = parallel_SST_model_Y.T_SH_out;
}
    
void getY_T_SH_in(real_T * T_SH_in){
        *T_SH_in = parallel_SST_model_Y.T_SH_in;
}
    
void getY_T_prim_out(real_T * T_prim_out){
        *T_prim_out = parallel_SST_model_Y.T_prim_out;
}
    
void getY_T_sec_out(real_T * T_sec_out){
        *T_sec_out = parallel_SST_model_Y.T_sec_out;
}
    
void getY_T_SH_emitter_out(real_T * T_SH_emitter_out){
        *T_SH_emitter_out = parallel_SST_model_Y.T_SH_emitter_out;
}
    
void getY_T_stor_n(real_T * T_stor_n){
        *T_stor_n = parallel_SST_model_Y.T_stor_n;
}
    
void getY_Q_SH(real_T * Q_SH){
        *Q_SH = parallel_SST_model_Y.Q_SH;
}
    
void getY_Q_primary_HX(real_T * Q_primary_HX){
        *Q_primary_HX = parallel_SST_model_Y.Q_primary_HX;
}
    
void getY_Q_DHW_HX(real_T * Q_DHW_HX){
        *Q_DHW_HX = parallel_SST_model_Y.Q_DHW_HX;
}
    
void getY_m_DHW(real_T * m_DHW){
        *m_DHW = parallel_SST_model_Y.m_DHW;
}
    
void getY_Q_SH_supply(real_T * Q_SH_supply){
        *Q_SH_supply = parallel_SST_model_Y.Q_SH_supply;
}
    
void getY_Q_SH_return(real_T * Q_SH_return){
        *Q_SH_return = parallel_SST_model_Y.Q_SH_return;
}
    
void getY_T_stor_out(real_T * T_stor_out){
        *T_stor_out = parallel_SST_model_Y.T_stor_out;
}
    
void getY_T_stor_avg(real_T * T_stor_avg){
        *T_stor_avg = parallel_SST_model_Y.T_stor_avg;
}
    
void getY_T_stor_mid(real_T * T_stor_mid){
        *T_stor_mid = parallel_SST_model_Y.T_stor_mid;
}
    
void getY_T_stor_std(real_T * T_stor_std){
        *T_stor_std = parallel_SST_model_Y.T_stor_std;
}
    
void getY_T_stor_half(real_T * T_stor_half){
        *T_stor_half = parallel_SST_model_Y.T_stor_half;
}
    
void getY_T_stor_1(real_T * T_stor_1){
        *T_stor_1 = parallel_SST_model_Y.T_stor_1;
}
    
void getY_m_DHW_prim(real_T * m_DHW_prim){
        *m_DHW_prim = parallel_SST_model_Y.m_DHW_prim;
}
    
void getY_m_sec(real_T * m_sec){
        *m_sec = parallel_SST_model_Y.m_sec;
}
    
void getY_m_SH(real_T * m_SH){
        *m_SH = parallel_SST_model_Y.m_SH;
}
    
void getY_Q_DHW_supply(real_T * Q_DHW_supply){
        *Q_DHW_supply = parallel_SST_model_Y.Q_DHW_supply;
}
    
void getY_Q_DHW_return(real_T * Q_DHW_return){
        *Q_DHW_return = parallel_SST_model_Y.Q_DHW_return;
}
    
void getY_efficiency_primary_HX(real_T * efficiency_primary_HX){
        *efficiency_primary_HX = parallel_SST_model_Y.efficiency_primary_HX;
}
    
void getY_efficiency_DHW_HX(real_T * efficiency_DHW_HX){
        *efficiency_DHW_HX = parallel_SST_model_Y.efficiency_DHW_HX;
}
    
void getY_T_DHW_in(real_T * T_DHW_in){
        *T_DHW_in = parallel_SST_model_Y.T_DHW_in;
}
    
void getY_T_SH_emitter_in(real_T * T_SH_emitter_in){
        *T_SH_emitter_in = parallel_SST_model_Y.T_SH_emitter_in;
}
    
void getY_T_stor_in(real_T * T_stor_in){
        *T_stor_in = parallel_SST_model_Y.T_stor_in;
}
    
void getY_m_DHW_stor(real_T * m_DHW_stor){
        *m_DHW_stor = parallel_SST_model_Y.m_DHW_stor;
}
    //-- P --

void getP_DHWheatexchanger_A(real_T * DHWheatexchanger_A){
        *DHWheatexchanger_A = parallel_SST_model_P.DHWheatexchanger_A;
}
    
void getP_Primaryheatexchanger_A(real_T * Primaryheatexchanger_A){
        *Primaryheatexchanger_A = parallel_SST_model_P.Primaryheatexchanger_A;
}
    
void getP_DHWreturnpipe_D(real_T * DHWreturnpipe_D){
        *DHWreturnpipe_D = parallel_SST_model_P.DHWreturnpipe_D;
}
    
void getP_DHWstorage_D(real_T * DHWstorage_D){
        *DHWstorage_D = parallel_SST_model_P.DHWstorage_D;
}
    
void getP_DHWsupplypipe_D(real_T * DHWsupplypipe_D){
        *DHWsupplypipe_D = parallel_SST_model_P.DHWsupplypipe_D;
}
    
void getP_SHreturnpipe_D(real_T * SHreturnpipe_D){
        *SHreturnpipe_D = parallel_SST_model_P.SHreturnpipe_D;
}
    
void getP_SHsupplypipe_D(real_T * SHsupplypipe_D){
        *SHsupplypipe_D = parallel_SST_model_P.SHsupplypipe_D;
}
    
void getP_SHthermalemitters_D(real_T * SHthermalemitters_D){
        *SHthermalemitters_D = parallel_SST_model_P.SHthermalemitters_D;
}
    
void getP_DHWstorage_H(real_T * DHWstorage_H){
        *DHWstorage_H = parallel_SST_model_P.DHWstorage_H;
}
    
void getP_DHWreturnpipe_L(real_T * DHWreturnpipe_L){
        *DHWreturnpipe_L = parallel_SST_model_P.DHWreturnpipe_L;
}
    
void getP_DHWsupplypipe_L(real_T * DHWsupplypipe_L){
        *DHWsupplypipe_L = parallel_SST_model_P.DHWsupplypipe_L;
}
    
void getP_SHreturnpipe_L(real_T * SHreturnpipe_L){
        *SHreturnpipe_L = parallel_SST_model_P.SHreturnpipe_L;
}
    
void getP_SHsupplypipe_L(real_T * SHsupplypipe_L){
        *SHsupplypipe_L = parallel_SST_model_P.SHsupplypipe_L;
}
    
void getP_SHthermalemitters_L(real_T * SHthermalemitters_L){
        *SHthermalemitters_L = parallel_SST_model_P.SHthermalemitters_L;
}
    
void getP_SHthermalemitters_T_air(real_T * SHthermalemitters_T_air){
        *SHthermalemitters_T_air = parallel_SST_model_P.SHthermalemitters_T_air;
}
    
void getP_DHWstorage_T_amb(real_T * DHWstorage_T_amb){
        *DHWstorage_T_amb = parallel_SST_model_P.DHWstorage_T_amb;
}
    
void getP_DHWreturnpipe_T_duct(real_T * DHWreturnpipe_T_duct){
        *DHWreturnpipe_T_duct = parallel_SST_model_P.DHWreturnpipe_T_duct;
}
    
void getP_DHWsupplypipe_T_duct(real_T * DHWsupplypipe_T_duct){
        *DHWsupplypipe_T_duct = parallel_SST_model_P.DHWsupplypipe_T_duct;
}
    
void getP_SHreturnpipe_T_duct(real_T * SHreturnpipe_T_duct){
        *SHreturnpipe_T_duct = parallel_SST_model_P.SHreturnpipe_T_duct;
}
    
void getP_SHsupplypipe_T_duct(real_T * SHsupplypipe_T_duct){
        *SHsupplypipe_T_duct = parallel_SST_model_P.SHsupplypipe_T_duct;
}
    
void getP_DHWstorage_U(real_T * DHWstorage_U){
        *DHWstorage_U = parallel_SST_model_P.DHWstorage_U;
}
    
void getP_SHthermalemitters_U(real_T * SHthermalemitters_U){
        *SHthermalemitters_U = parallel_SST_model_P.SHthermalemitters_U;
}
    
void getP_DHWheatexchanger_U(real_T * DHWheatexchanger_U){
        *DHWheatexchanger_U = parallel_SST_model_P.DHWheatexchanger_U;
}
    
void getP_Primaryheatexchanger_U(real_T * Primaryheatexchanger_U){
        *Primaryheatexchanger_U = parallel_SST_model_P.Primaryheatexchanger_U;
}
    
void getP_DHWstorage_V_min(real_T * DHWstorage_V_min){
        *DHWstorage_V_min = parallel_SST_model_P.DHWstorage_V_min;
}
    
void getP_DHWstorage_V_var(real_T * DHWstorage_V_var){
        *DHWstorage_V_var = parallel_SST_model_P.DHWstorage_V_var;
}
    
void getP_DHWstorage_eps(real_T * DHWstorage_eps){
        *DHWstorage_eps = parallel_SST_model_P.DHWstorage_eps;
}
    
void getP_DHWreturnpipe_m_min(real_T * DHWreturnpipe_m_min){
        *DHWreturnpipe_m_min = parallel_SST_model_P.DHWreturnpipe_m_min;
}
    
void getP_DHWsupplypipe_m_min(real_T * DHWsupplypipe_m_min){
        *DHWsupplypipe_m_min = parallel_SST_model_P.DHWsupplypipe_m_min;
}
    
void getP_SHreturnpipe_m_min(real_T * SHreturnpipe_m_min){
        *SHreturnpipe_m_min = parallel_SST_model_P.SHreturnpipe_m_min;
}
    
void getP_SHsupplypipe_m_min(real_T * SHsupplypipe_m_min){
        *SHsupplypipe_m_min = parallel_SST_model_P.SHsupplypipe_m_min;
}
    
void getP_SHthermalemitters_m_min(real_T * SHthermalemitters_m_min){
        *SHthermalemitters_m_min = parallel_SST_model_P.SHthermalemitters_m_min;
}
    
void getP_DHWstorage_n(real_T * DHWstorage_n){
        *DHWstorage_n = parallel_SST_model_P.DHWstorage_n;
}
    
void getP_SHthermalemitters_n_radiators(real_T * SHthermalemitters_n_radiators){
        *SHthermalemitters_n_radiators = parallel_SST_model_P.SHthermalemitters_n_radiators;
}
    
void getP_SHthermalemitters_n_tubes(real_T * SHthermalemitters_n_tubes){
        *SHthermalemitters_n_tubes = parallel_SST_model_P.SHthermalemitters_n_tubes;
}
    
void getP_DHWbypassvalve_unknown_T(real_T * DHWbypassvalve_unknown_T){
        *DHWbypassvalve_unknown_T = parallel_SST_model_P.DHWbypassvalve_unknown_T;
}
    
void getP_DHWstoragetopvalve_unknown_T(real_T * DHWstoragetopvalve_unknown_T){
        *DHWstoragetopvalve_unknown_T = parallel_SST_model_P.DHWstoragetopvalve_unknown_T;
}
    
void getP_DHWcoldwaterrefill_unknown_T(real_T * DHWcoldwaterrefill_unknown_T){
        *DHWcoldwaterrefill_unknown_T = parallel_SST_model_P.DHWcoldwaterrefill_unknown_T;
}
    
void getP_DHWstoragebottomvalve_unknown_T(real_T * DHWstoragebottomvalve_unknown_T){
        *DHWstoragebottomvalve_unknown_T = parallel_SST_model_P.DHWstoragebottomvalve_unknown_T;
}
    
void getP_SHbypassvalve_unknown_T(real_T * SHbypassvalve_unknown_T){
        *SHbypassvalve_unknown_T = parallel_SST_model_P.SHbypassvalve_unknown_T;
}
    
void getP_SHDHWreturnvalve_unknown_T(real_T * SHDHWreturnvalve_unknown_T){
        *SHDHWreturnvalve_unknown_T = parallel_SST_model_P.SHDHWreturnvalve_unknown_T;
}
    
void getP_DHWbypassvalve_unknown_m(real_T * DHWbypassvalve_unknown_m){
        *DHWbypassvalve_unknown_m = parallel_SST_model_P.DHWbypassvalve_unknown_m;
}
    
void getP_DHWstoragetopvalve_unknown_m(real_T * DHWstoragetopvalve_unknown_m){
        *DHWstoragetopvalve_unknown_m = parallel_SST_model_P.DHWstoragetopvalve_unknown_m;
}
    
void getP_DHWcoldwaterrefill_unknown_m(real_T * DHWcoldwaterrefill_unknown_m){
        *DHWcoldwaterrefill_unknown_m = parallel_SST_model_P.DHWcoldwaterrefill_unknown_m;
}
    
void getP_DHWstoragebottomvalve_unknown_m(real_T * DHWstoragebottomvalve_unknown_m){
        *DHWstoragebottomvalve_unknown_m = parallel_SST_model_P.DHWstoragebottomvalve_unknown_m;
}
    
void getP_SHbypassvalve_unknown_m(real_T * SHbypassvalve_unknown_m){
        *SHbypassvalve_unknown_m = parallel_SST_model_P.SHbypassvalve_unknown_m;
}
    
void getP_SHDHWreturnvalve_unknown_m(real_T * SHDHWreturnvalve_unknown_m){
        *SHDHWreturnvalve_unknown_m = parallel_SST_model_P.SHDHWreturnvalve_unknown_m;
}
    
void getP_Delay_InitialCondition(real_T * Delay_InitialCondition){
        *Delay_InitialCondition = parallel_SST_model_P.Delay_InitialCondition;
}
    
void getP_Delay1_InitialCondition(real_T * Delay1_InitialCondition){
        *Delay1_InitialCondition = parallel_SST_model_P.Delay1_InitialCondition;
}
    
void getP_Constant1_Value(real_T * Constant1_Value){
        *Constant1_Value = parallel_SST_model_P.Constant1_Value;
}
    
void getP_Delay6_InitialCondition(real_T * Delay6_InitialCondition){
        *Delay6_InitialCondition = parallel_SST_model_P.Delay6_InitialCondition;
}
    
void getP_Delay5_InitialCondition(real_T * Delay5_InitialCondition){
        *Delay5_InitialCondition = parallel_SST_model_P.Delay5_InitialCondition;
}
    
void getP_Switch3_Threshold(real_T * Switch3_Threshold){
        *Switch3_Threshold = parallel_SST_model_P.Switch3_Threshold;
}
    
void getP_Constant5_Value(real_T * Constant5_Value){
        *Constant5_Value = parallel_SST_model_P.Constant5_Value;
}
    
void getP_Constant6_Value(real_T * Constant6_Value){
        *Constant6_Value = parallel_SST_model_P.Constant6_Value;
}
    
void getP_Switch2_Threshold(real_T * Switch2_Threshold){
        *Switch2_Threshold = parallel_SST_model_P.Switch2_Threshold;
}
    
void getP_Delay_InitialCondition_o(real_T * Delay_InitialCondition_o){
        *Delay_InitialCondition_o = parallel_SST_model_P.Delay_InitialCondition_o;
}
    
void getP_Delay_InitialCondition_k(real_T * Delay_InitialCondition_k){
        *Delay_InitialCondition_k = parallel_SST_model_P.Delay_InitialCondition_k;
}
    
void getP_Constant7_Value(real_T * Constant7_Value){
        *Constant7_Value = parallel_SST_model_P.Constant7_Value;
}
    
void getP_Switch_Threshold(real_T * Switch_Threshold){
        *Switch_Threshold = parallel_SST_model_P.Switch_Threshold;
}
    
void getP_Delay_InitialCondition_o4(real_T * Delay_InitialCondition_o4){
        *Delay_InitialCondition_o4 = parallel_SST_model_P.Delay_InitialCondition_o4;
}
    
void getP_Switch4_Threshold(real_T * Switch4_Threshold){
        *Switch4_Threshold = parallel_SST_model_P.Switch4_Threshold;
}
    
void getP_Constant_Value(real_T * Constant_Value){
        *Constant_Value = parallel_SST_model_P.Constant_Value;
}
    
void getP_Constant4_Value(real_T * Constant4_Value){
        *Constant4_Value = parallel_SST_model_P.Constant4_Value;
}
    
void getP_Switch1_Threshold(real_T * Switch1_Threshold){
        *Switch1_Threshold = parallel_SST_model_P.Switch1_Threshold;
}
    
void getP_Delay2_InitialCondition(real_T * Delay2_InitialCondition){
        *Delay2_InitialCondition = parallel_SST_model_P.Delay2_InitialCondition;
}
    
void getP_Delay7_InitialCondition(real_T * Delay7_InitialCondition){
        *Delay7_InitialCondition = parallel_SST_model_P.Delay7_InitialCondition;
}
    
void getP_Constant2_Value(real_T * Constant2_Value){
        *Constant2_Value = parallel_SST_model_P.Constant2_Value;
}
    
void getP_Delay_InitialCondition_j(real_T * Delay_InitialCondition_j){
        *Delay_InitialCondition_j = parallel_SST_model_P.Delay_InitialCondition_j;
}
    
void getP_Delay_InitialCondition_l(real_T * Delay_InitialCondition_l){
        *Delay_InitialCondition_l = parallel_SST_model_P.Delay_InitialCondition_l;
}
    
void getP_Delay_InitialCondition_jr(real_T * Delay_InitialCondition_jr){
        *Delay_InitialCondition_jr = parallel_SST_model_P.Delay_InitialCondition_jr;
}
    
void getP_Constant3_Value(real_T * Constant3_Value){
        *Constant3_Value = parallel_SST_model_P.Constant3_Value;
}
    

/* ======
SETTERS
=======*/

//-- U --

void setU_m_prim(real_T * m_prim){
        parallel_SST_model_U.m_prim = *m_prim;
}
    
void setU_T_prim_in(real_T * T_prim_in){
        parallel_SST_model_U.T_prim_in = *T_prim_in;
}
    
void setU_m_SH_dir(real_T * m_SH_dir){
        parallel_SST_model_U.m_SH_dir = *m_SH_dir;
}
    
void setU_m_SH_3V(real_T * m_SH_3V){
        parallel_SST_model_U.m_SH_3V = *m_SH_3V;
}
    
void setU_m_DHW_sec(real_T * m_DHW_sec){
        parallel_SST_model_U.m_DHW_sec = *m_DHW_sec;
}
    
void setU_m_DHW_w(real_T * m_DHW_w){
        parallel_SST_model_U.m_DHW_w = *m_DHW_w;
}
    
void setU_m_DHW_recirc(real_T * m_DHW_recirc){
        parallel_SST_model_U.m_DHW_recirc = *m_DHW_recirc;
}
    
void setU_T_cold(real_T * T_cold){
        parallel_SST_model_U.T_cold = *T_cold;
}
    
void setU_m_DHW_dir(real_T * m_DHW_dir){
        parallel_SST_model_U.m_DHW_dir = *m_DHW_dir;
}
    
void setU_m_DHW_3V(real_T * m_DHW_3V){
        parallel_SST_model_U.m_DHW_3V = *m_DHW_3V;
}
    //-- P --

void setP_DHWheatexchanger_A(real_T * DHWheatexchanger_A){
        parallel_SST_model_P.DHWheatexchanger_A = *DHWheatexchanger_A;
}
    
void setP_Primaryheatexchanger_A(real_T * Primaryheatexchanger_A){
        parallel_SST_model_P.Primaryheatexchanger_A = *Primaryheatexchanger_A;
}
    
void setP_DHWreturnpipe_D(real_T * DHWreturnpipe_D){
        parallel_SST_model_P.DHWreturnpipe_D = *DHWreturnpipe_D;
}
    
void setP_DHWstorage_D(real_T * DHWstorage_D){
        parallel_SST_model_P.DHWstorage_D = *DHWstorage_D;
}
    
void setP_DHWsupplypipe_D(real_T * DHWsupplypipe_D){
        parallel_SST_model_P.DHWsupplypipe_D = *DHWsupplypipe_D;
}
    
void setP_SHreturnpipe_D(real_T * SHreturnpipe_D){
        parallel_SST_model_P.SHreturnpipe_D = *SHreturnpipe_D;
}
    
void setP_SHsupplypipe_D(real_T * SHsupplypipe_D){
        parallel_SST_model_P.SHsupplypipe_D = *SHsupplypipe_D;
}
    
void setP_SHthermalemitters_D(real_T * SHthermalemitters_D){
        parallel_SST_model_P.SHthermalemitters_D = *SHthermalemitters_D;
}
    
void setP_DHWstorage_H(real_T * DHWstorage_H){
        parallel_SST_model_P.DHWstorage_H = *DHWstorage_H;
}
    
void setP_DHWreturnpipe_L(real_T * DHWreturnpipe_L){
        parallel_SST_model_P.DHWreturnpipe_L = *DHWreturnpipe_L;
}
    
void setP_DHWsupplypipe_L(real_T * DHWsupplypipe_L){
        parallel_SST_model_P.DHWsupplypipe_L = *DHWsupplypipe_L;
}
    
void setP_SHreturnpipe_L(real_T * SHreturnpipe_L){
        parallel_SST_model_P.SHreturnpipe_L = *SHreturnpipe_L;
}
    
void setP_SHsupplypipe_L(real_T * SHsupplypipe_L){
        parallel_SST_model_P.SHsupplypipe_L = *SHsupplypipe_L;
}
    
void setP_SHthermalemitters_L(real_T * SHthermalemitters_L){
        parallel_SST_model_P.SHthermalemitters_L = *SHthermalemitters_L;
}
    
void setP_SHthermalemitters_T_air(real_T * SHthermalemitters_T_air){
        parallel_SST_model_P.SHthermalemitters_T_air = *SHthermalemitters_T_air;
}
    
void setP_DHWstorage_T_amb(real_T * DHWstorage_T_amb){
        parallel_SST_model_P.DHWstorage_T_amb = *DHWstorage_T_amb;
}
    
void setP_DHWreturnpipe_T_duct(real_T * DHWreturnpipe_T_duct){
        parallel_SST_model_P.DHWreturnpipe_T_duct = *DHWreturnpipe_T_duct;
}
    
void setP_DHWsupplypipe_T_duct(real_T * DHWsupplypipe_T_duct){
        parallel_SST_model_P.DHWsupplypipe_T_duct = *DHWsupplypipe_T_duct;
}
    
void setP_SHreturnpipe_T_duct(real_T * SHreturnpipe_T_duct){
        parallel_SST_model_P.SHreturnpipe_T_duct = *SHreturnpipe_T_duct;
}
    
void setP_SHsupplypipe_T_duct(real_T * SHsupplypipe_T_duct){
        parallel_SST_model_P.SHsupplypipe_T_duct = *SHsupplypipe_T_duct;
}
    
void setP_DHWstorage_U(real_T * DHWstorage_U){
        parallel_SST_model_P.DHWstorage_U = *DHWstorage_U;
}
    
void setP_SHthermalemitters_U(real_T * SHthermalemitters_U){
        parallel_SST_model_P.SHthermalemitters_U = *SHthermalemitters_U;
}
    
void setP_DHWheatexchanger_U(real_T * DHWheatexchanger_U){
        parallel_SST_model_P.DHWheatexchanger_U = *DHWheatexchanger_U;
}
    
void setP_Primaryheatexchanger_U(real_T * Primaryheatexchanger_U){
        parallel_SST_model_P.Primaryheatexchanger_U = *Primaryheatexchanger_U;
}
    
void setP_DHWstorage_V_min(real_T * DHWstorage_V_min){
        parallel_SST_model_P.DHWstorage_V_min = *DHWstorage_V_min;
}
    
void setP_DHWstorage_V_var(real_T * DHWstorage_V_var){
        parallel_SST_model_P.DHWstorage_V_var = *DHWstorage_V_var;
}
    
void setP_DHWstorage_eps(real_T * DHWstorage_eps){
        parallel_SST_model_P.DHWstorage_eps = *DHWstorage_eps;
}
    
void setP_DHWreturnpipe_m_min(real_T * DHWreturnpipe_m_min){
        parallel_SST_model_P.DHWreturnpipe_m_min = *DHWreturnpipe_m_min;
}
    
void setP_DHWsupplypipe_m_min(real_T * DHWsupplypipe_m_min){
        parallel_SST_model_P.DHWsupplypipe_m_min = *DHWsupplypipe_m_min;
}
    
void setP_SHreturnpipe_m_min(real_T * SHreturnpipe_m_min){
        parallel_SST_model_P.SHreturnpipe_m_min = *SHreturnpipe_m_min;
}
    
void setP_SHsupplypipe_m_min(real_T * SHsupplypipe_m_min){
        parallel_SST_model_P.SHsupplypipe_m_min = *SHsupplypipe_m_min;
}
    
void setP_SHthermalemitters_m_min(real_T * SHthermalemitters_m_min){
        parallel_SST_model_P.SHthermalemitters_m_min = *SHthermalemitters_m_min;
}
    
void setP_DHWstorage_n(real_T * DHWstorage_n){
        parallel_SST_model_P.DHWstorage_n = *DHWstorage_n;
}
    
void setP_SHthermalemitters_n_radiators(real_T * SHthermalemitters_n_radiators){
        parallel_SST_model_P.SHthermalemitters_n_radiators = *SHthermalemitters_n_radiators;
}
    
void setP_SHthermalemitters_n_tubes(real_T * SHthermalemitters_n_tubes){
        parallel_SST_model_P.SHthermalemitters_n_tubes = *SHthermalemitters_n_tubes;
}
    
void setP_DHWbypassvalve_unknown_T(real_T * DHWbypassvalve_unknown_T){
        parallel_SST_model_P.DHWbypassvalve_unknown_T = *DHWbypassvalve_unknown_T;
}
    
void setP_DHWstoragetopvalve_unknown_T(real_T * DHWstoragetopvalve_unknown_T){
        parallel_SST_model_P.DHWstoragetopvalve_unknown_T = *DHWstoragetopvalve_unknown_T;
}
    
void setP_DHWcoldwaterrefill_unknown_T(real_T * DHWcoldwaterrefill_unknown_T){
        parallel_SST_model_P.DHWcoldwaterrefill_unknown_T = *DHWcoldwaterrefill_unknown_T;
}
    
void setP_DHWstoragebottomvalve_unknown_T(real_T * DHWstoragebottomvalve_unknown_T){
        parallel_SST_model_P.DHWstoragebottomvalve_unknown_T = *DHWstoragebottomvalve_unknown_T;
}
    
void setP_SHbypassvalve_unknown_T(real_T * SHbypassvalve_unknown_T){
        parallel_SST_model_P.SHbypassvalve_unknown_T = *SHbypassvalve_unknown_T;
}
    
void setP_SHDHWreturnvalve_unknown_T(real_T * SHDHWreturnvalve_unknown_T){
        parallel_SST_model_P.SHDHWreturnvalve_unknown_T = *SHDHWreturnvalve_unknown_T;
}
    
void setP_DHWbypassvalve_unknown_m(real_T * DHWbypassvalve_unknown_m){
        parallel_SST_model_P.DHWbypassvalve_unknown_m = *DHWbypassvalve_unknown_m;
}
    
void setP_DHWstoragetopvalve_unknown_m(real_T * DHWstoragetopvalve_unknown_m){
        parallel_SST_model_P.DHWstoragetopvalve_unknown_m = *DHWstoragetopvalve_unknown_m;
}
    
void setP_DHWcoldwaterrefill_unknown_m(real_T * DHWcoldwaterrefill_unknown_m){
        parallel_SST_model_P.DHWcoldwaterrefill_unknown_m = *DHWcoldwaterrefill_unknown_m;
}
    
void setP_DHWstoragebottomvalve_unknown_m(real_T * DHWstoragebottomvalve_unknown_m){
        parallel_SST_model_P.DHWstoragebottomvalve_unknown_m = *DHWstoragebottomvalve_unknown_m;
}
    
void setP_SHbypassvalve_unknown_m(real_T * SHbypassvalve_unknown_m){
        parallel_SST_model_P.SHbypassvalve_unknown_m = *SHbypassvalve_unknown_m;
}
    
void setP_SHDHWreturnvalve_unknown_m(real_T * SHDHWreturnvalve_unknown_m){
        parallel_SST_model_P.SHDHWreturnvalve_unknown_m = *SHDHWreturnvalve_unknown_m;
}
    
void setP_Delay_InitialCondition(real_T * Delay_InitialCondition){
        parallel_SST_model_P.Delay_InitialCondition = *Delay_InitialCondition;
}
    
void setP_Delay1_InitialCondition(real_T * Delay1_InitialCondition){
        parallel_SST_model_P.Delay1_InitialCondition = *Delay1_InitialCondition;
}
    
void setP_Constant1_Value(real_T * Constant1_Value){
        parallel_SST_model_P.Constant1_Value = *Constant1_Value;
}
    
void setP_Delay6_InitialCondition(real_T * Delay6_InitialCondition){
        parallel_SST_model_P.Delay6_InitialCondition = *Delay6_InitialCondition;
}
    
void setP_Delay5_InitialCondition(real_T * Delay5_InitialCondition){
        parallel_SST_model_P.Delay5_InitialCondition = *Delay5_InitialCondition;
}
    
void setP_Switch3_Threshold(real_T * Switch3_Threshold){
        parallel_SST_model_P.Switch3_Threshold = *Switch3_Threshold;
}
    
void setP_Constant5_Value(real_T * Constant5_Value){
        parallel_SST_model_P.Constant5_Value = *Constant5_Value;
}
    
void setP_Constant6_Value(real_T * Constant6_Value){
        parallel_SST_model_P.Constant6_Value = *Constant6_Value;
}
    
void setP_Switch2_Threshold(real_T * Switch2_Threshold){
        parallel_SST_model_P.Switch2_Threshold = *Switch2_Threshold;
}
    
void setP_Delay_InitialCondition_o(real_T * Delay_InitialCondition_o){
        parallel_SST_model_P.Delay_InitialCondition_o = *Delay_InitialCondition_o;
}
    
void setP_Delay_InitialCondition_k(real_T * Delay_InitialCondition_k){
        parallel_SST_model_P.Delay_InitialCondition_k = *Delay_InitialCondition_k;
}
    
void setP_Constant7_Value(real_T * Constant7_Value){
        parallel_SST_model_P.Constant7_Value = *Constant7_Value;
}
    
void setP_Switch_Threshold(real_T * Switch_Threshold){
        parallel_SST_model_P.Switch_Threshold = *Switch_Threshold;
}
    
void setP_Delay_InitialCondition_o4(real_T * Delay_InitialCondition_o4){
        parallel_SST_model_P.Delay_InitialCondition_o4 = *Delay_InitialCondition_o4;
}
    
void setP_Switch4_Threshold(real_T * Switch4_Threshold){
        parallel_SST_model_P.Switch4_Threshold = *Switch4_Threshold;
}
    
void setP_Constant_Value(real_T * Constant_Value){
        parallel_SST_model_P.Constant_Value = *Constant_Value;
}
    
void setP_Constant4_Value(real_T * Constant4_Value){
        parallel_SST_model_P.Constant4_Value = *Constant4_Value;
}
    
void setP_Switch1_Threshold(real_T * Switch1_Threshold){
        parallel_SST_model_P.Switch1_Threshold = *Switch1_Threshold;
}
    
void setP_Delay2_InitialCondition(real_T * Delay2_InitialCondition){
        parallel_SST_model_P.Delay2_InitialCondition = *Delay2_InitialCondition;
}
    
void setP_Delay7_InitialCondition(real_T * Delay7_InitialCondition){
        parallel_SST_model_P.Delay7_InitialCondition = *Delay7_InitialCondition;
}
    
void setP_Constant2_Value(real_T * Constant2_Value){
        parallel_SST_model_P.Constant2_Value = *Constant2_Value;
}
    
void setP_Delay_InitialCondition_j(real_T * Delay_InitialCondition_j){
        parallel_SST_model_P.Delay_InitialCondition_j = *Delay_InitialCondition_j;
}
    
void setP_Delay_InitialCondition_l(real_T * Delay_InitialCondition_l){
        parallel_SST_model_P.Delay_InitialCondition_l = *Delay_InitialCondition_l;
}
    
void setP_Delay_InitialCondition_jr(real_T * Delay_InitialCondition_jr){
        parallel_SST_model_P.Delay_InitialCondition_jr = *Delay_InitialCondition_jr;
}
    
void setP_Constant3_Value(real_T * Constant3_Value){
        parallel_SST_model_P.Constant3_Value = *Constant3_Value;
}
    
void initialize(int * stepSize0){
        parallel_SST_model_initialize();
        parallel_SST_model_M->Timing.stepSize0 = *stepSize0;
}


void _get_SimulationTime(real_T * SimulationTime){
        *SimulationTime = parallel_SST_model_M->Timing.t[0];
}

    