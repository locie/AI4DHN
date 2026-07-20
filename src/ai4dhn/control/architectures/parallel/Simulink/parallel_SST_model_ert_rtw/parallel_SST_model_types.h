/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: parallel_SST_model_types.h
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

#ifndef parallel_SST_model_types_h_
#define parallel_SST_model_types_h_
#include "rtwtypes.h"
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_char_T */

#ifndef typedef_emxArray_char_T_parallel_SST__T
#define typedef_emxArray_char_T_parallel_SST__T

typedef struct emxArray_char_T emxArray_char_T_parallel_SST__T;

#endif                             /* typedef_emxArray_char_T_parallel_SST__T */

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_char_T */

#ifndef typedef_emxArray_char_T_parallel_SS_n_T
#define typedef_emxArray_char_T_parallel_SS_n_T

typedef struct emxArray_char_T emxArray_char_T_parallel_SS_n_T;

#endif                             /* typedef_emxArray_char_T_parallel_SS_n_T */

/* Custom Type definition for MATLAB Function: ''thermal_emitters_function' (':637:65')' */
#ifndef struct_tag_jIb3oaniHywPjnkMnmeIbB
#define struct_tag_jIb3oaniHywPjnkMnmeIbB

struct tag_jIb3oaniHywPjnkMnmeIbB
{
  real_T contents;
};

#endif                                 /* struct_tag_jIb3oaniHywPjnkMnmeIbB */

#ifndef typedef_captured_var_parallel_SST_mod_T
#define typedef_captured_var_parallel_SST_mod_T

typedef struct tag_jIb3oaniHywPjnkMnmeIbB captured_var_parallel_SST_mod_T;

#endif                             /* typedef_captured_var_parallel_SST_mod_T */

/* Custom Type definition for MATLAB Function: ''storage_TC_func' (':206:8')' */
#ifndef struct_tag_hJLXW5eeiiQClOA7PEOtYB
#define struct_tag_hJLXW5eeiiQClOA7PEOtYB

struct tag_hJLXW5eeiiQClOA7PEOtYB
{
  boolean_T contents;
};

#endif                                 /* struct_tag_hJLXW5eeiiQClOA7PEOtYB */

#ifndef typedef_captured_var_1_parallel_SST_m_T
#define typedef_captured_var_1_parallel_SST_m_T

typedef struct tag_hJLXW5eeiiQClOA7PEOtYB captured_var_1_parallel_SST_m_T;

#endif                             /* typedef_captured_var_1_parallel_SST_m_T */

#ifndef struct_tag_JrTEP38GMfv0hLhSLyVGj
#define struct_tag_JrTEP38GMfv0hLhSLyVGj

struct tag_JrTEP38GMfv0hLhSLyVGj
{
  captured_var_parallel_SST_mod_T *n;
  captured_var_1_parallel_SST_m_T *is_moving_grid;
  captured_var_parallel_SST_mod_T *rho;
  captured_var_parallel_SST_mod_T *V_tot;
  captured_var_parallel_SST_mod_T *V_TC;
  captured_var_parallel_SST_mod_T *Cp;
  captured_var_parallel_SST_mod_T *U;
  captured_var_parallel_SST_mod_T *P;
  captured_var_parallel_SST_mod_T *A;
  captured_var_parallel_SST_mod_T *T_amb;
  captured_var_parallel_SST_mod_T *eps;
  captured_var_parallel_SST_mod_T *dx;
  real_T m_top_;
  real_T m_bottom_;
  real_T m_down;
  real_T m_up;
  real_T T_top;
  real_T T_bottom;
};

#endif                                 /* struct_tag_JrTEP38GMfv0hLhSLyVGj */

#ifndef typedef_s_JrTEP38GMfv0hLhSLyVGj_paral_T
#define typedef_s_JrTEP38GMfv0hLhSLyVGj_paral_T

typedef struct tag_JrTEP38GMfv0hLhSLyVGj s_JrTEP38GMfv0hLhSLyVGj_paral_T;

#endif                             /* typedef_s_JrTEP38GMfv0hLhSLyVGj_paral_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_real_T */

#ifndef typedef_emxArray_real_T_parallel_SST__T
#define typedef_emxArray_real_T_parallel_SST__T

typedef struct emxArray_real_T emxArray_real_T_parallel_SST__T;

#endif                             /* typedef_emxArray_real_T_parallel_SST__T */

/* Parameters (default storage) */
typedef struct P_parallel_SST_model_T_ P_parallel_SST_model_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_parallel_SST_model_T RT_MODEL_parallel_SST_model_T;

#endif                                 /* parallel_SST_model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
