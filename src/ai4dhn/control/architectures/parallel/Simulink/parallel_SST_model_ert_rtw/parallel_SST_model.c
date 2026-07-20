/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: parallel_SST_model.c
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
#include "rtwtypes.h"
#include "parallel_SST_model_types.h"
#include "parallel_SST_model_private.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include <emmintrin.h>

/* Block signals (default storage) */
B_parallel_SST_model_T parallel_SST_model_B;

/* Block states (default storage) */
DW_parallel_SST_model_T parallel_SST_model_DW;

/* External inputs (root inport signals with default storage) */
ExtU_parallel_SST_model_T parallel_SST_model_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_parallel_SST_model_T parallel_SST_model_Y;

/* Real-time model */
static RT_MODEL_parallel_SST_model_T parallel_SST_model_M_;
RT_MODEL_parallel_SST_model_T *const parallel_SST_model_M =
  &parallel_SST_model_M_;

/* Forward declaration for local functions */
static void parallel_SST_mod_emxInit_char_T(emxArray_char_T_parallel_SST__T
  **pEmxArray, int32_T numDimensions);
static void parall_emxEnsureCapacity_char_T(emxArray_char_T_parallel_SST__T
  *emxArray, int32_T oldNumel);
static void parallel_SST_mod_emxFree_char_T(emxArray_char_T_parallel_SST__T
  **pEmxArray);
static void parallel_SST_model_sprintf(real_T varargin_1, real_T varargin_2);
static void parallel_SST_model_sprintf_f(real_T varargin_1, real_T varargin_2);

/* Forward declaration for local functions */
static void parall_emxEnsureCapacity_real_T(emxArray_real_T_parallel_SST__T
  *emxArray, int32_T oldNumel);
static void parallel_SST_mod_emxInit_real_T(emxArray_real_T_parallel_SST__T
  **pEmxArray, int32_T numDimensions);
static void c7_parallel_SST_model_anonFcn1(const captured_var_parallel_SST_mod_T
  *n_dx, const captured_var_parallel_SST_mod_T *dx, const
  captured_var_parallel_SST_mod_T *tau, const captured_var_parallel_SST_mod_T
  *b_T_duct, real_T V, real_T T_in, const emxArray_real_T_parallel_SST__T *y,
  emxArray_real_T_parallel_SST__T *varargout_1);
static void parallel_SST_mod_emxFree_real_T(emxArray_real_T_parallel_SST__T
  **pEmxArray);
static void parallel_SST_binary_expand_op_1(emxArray_real_T_parallel_SST__T *in1,
  const emxArray_real_T_parallel_SST__T *in2);
static void parallel_SST_model_ntrp23(real_T t, real_T t0, const
  emxArray_real_T_parallel_SST__T *b_y0, real_T h, const
  emxArray_real_T_parallel_SST__T *f, emxArray_real_T_parallel_SST__T *y);
static void parallel_SST_model_ode23(const captured_var_parallel_SST_mod_T
  *ode_workspace_n_dx, const captured_var_parallel_SST_mod_T *ode_workspace_dx,
  const captured_var_parallel_SST_mod_T *ode_workspace_tau, const
  captured_var_parallel_SST_mod_T *ode_workspace_T_duct, real_T ode_workspace_V,
  real_T ode_workspace_T_in, const emxArray_real_T_parallel_SST__T *tspan, const
  emxArray_real_T_parallel_SST__T *b_y0, emxArray_real_T_parallel_SST__T
  *varargout_1, emxArray_real_T_parallel_SST__T *varargout_2);
static real_T parallel_SST_m_colMajorFlatIter(const
  emxArray_real_T_parallel_SST__T *x, int32_T vlen);
static void c13_parallel_SST_model_anonFcn1(const
  captured_var_parallel_SST_mod_T *b_n, const captured_var_1_parallel_SST_m_T
  *is_moving_grid, const captured_var_parallel_SST_mod_T *rho, const
  captured_var_parallel_SST_mod_T *V_tot, const captured_var_parallel_SST_mod_T *
  V_TC, const captured_var_parallel_SST_mod_T *Cp, const
  captured_var_parallel_SST_mod_T *b_U, const captured_var_parallel_SST_mod_T *P,
  const captured_var_parallel_SST_mod_T *A, const
  captured_var_parallel_SST_mod_T *b_T_amb, const
  captured_var_parallel_SST_mod_T *b_eps, const captured_var_parallel_SST_mod_T *
  dx, real_T m_top_, real_T m_bottom_, real_T m_down, real_T m_up, real_T T_top,
  real_T T_bottom, const emxArray_real_T_parallel_SST__T *y,
  emxArray_real_T_parallel_SST__T *varargout_1);
static void parallel_SST_binary_expand_op_2(emxArray_real_T_parallel_SST__T *in1,
  const emxArray_real_T_parallel_SST__T *in2);
static void parallel_SST_model_ode23_o(const s_JrTEP38GMfv0hLhSLyVGj_paral_T
  *ode_workspace, const real_T tspan[2], const emxArray_real_T_parallel_SST__T
  *b_y0, emxArray_real_T_parallel_SST__T *varargout_1,
  emxArray_real_T_parallel_SST__T *varargout_2);
static void parallel_SST_model_linspace(real_T d1, real_T d2, real_T b_n,
  emxArray_real_T_parallel_SST__T *y);
static void parallel_SST_m_binary_expand_op(emxArray_real_T_parallel_SST__T *in1,
  const emxArray_real_T_parallel_SST__T *in2, const
  emxArray_real_T_parallel_SST__T *in3);
static real_T parallel_SST_m_blockedSummation(const
  emxArray_real_T_parallel_SST__T *x, int32_T vlen);
static real_T parallel_SST_model_std(const emxArray_real_T_parallel_SST__T *x,
  const emxArray_real_T_parallel_SST__T *varargin_1);
static void parallel_SST_model_minimum(const emxArray_real_T_parallel_SST__T *x,
  real_T *ex, int32_T *idx);
static void parallel_SST_mod_emxInit_char_T(emxArray_char_T_parallel_SST__T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_parallel_SST__T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_parallel_SST__T *)malloc(sizeof
    (emxArray_char_T_parallel_SST__T));
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++)
  {
    emxArray->size[i] = 0;
  }
}

static void parall_emxEnsureCapacity_char_T(emxArray_char_T_parallel_SST__T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0)
  {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++)
  {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize)
  {
    i = emxArray->allocatedSize;
    if (i < 16)
    {
      i = 16;
    }

    while (i < newNumel)
    {
      if (i > 1073741823)
      {
        i = MAX_int32_T;
      }
      else
      {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(char_T));
    if (emxArray->data != NULL)
    {
      memcpy(newData, emxArray->data, sizeof(char_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData)
      {
        free(emxArray->data);
      }
    }

    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void parallel_SST_mod_emxFree_char_T(emxArray_char_T_parallel_SST__T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_parallel_SST__T *)NULL)
  {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_parallel_SST__T *)NULL;
  }
}

/* Function for MATLAB Function: ''3WV_function' (':903:1')' */
static void parallel_SST_model_sprintf(real_T varargin_1, real_T varargin_2)
{
  emxArray_char_T_parallel_SST__T *str;
  int32_T nbytes;
  int32_T tmp;
  nbytes = (int32_T)snprintf(NULL, 0,
    "3-way valve: T_2 (%2.1f) != T_3 (%2.1f), used value is T_2=T_3\n",
    varargin_1, varargin_2) + 1;
  parallel_SST_mod_emxInit_char_T(&str, 2);
  tmp = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = nbytes;
  parall_emxEnsureCapacity_char_T(str, tmp);
  snprintf(&str->data[0], (size_t)nbytes,
           "3-way valve: T_2 (%2.1f) != T_3 (%2.1f), used value is T_2=T_3\n",
           varargin_1, varargin_2);
  parallel_SST_mod_emxFree_char_T(&str);
}

/* Function for MATLAB Function: ''3WV_function' (':903:1')' */
static void parallel_SST_model_sprintf_f(real_T varargin_1, real_T varargin_2)
{
  emxArray_char_T_parallel_SST__T *str;
  int32_T nbytes;
  int32_T tmp;
  nbytes = (int32_T)snprintf(NULL, 0,
    "3-way valve: T_1 (%2.1f) != T_3 (%2.1f), used value is T_1=T_3\n",
    varargin_1, varargin_2) + 1;
  parallel_SST_mod_emxInit_char_T(&str, 2);
  tmp = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = nbytes;
  parall_emxEnsureCapacity_char_T(str, tmp);
  snprintf(&str->data[0], (size_t)nbytes,
           "3-way valve: T_1 (%2.1f) != T_3 (%2.1f), used value is T_1=T_3\n",
           varargin_1, varargin_2);
  parallel_SST_mod_emxFree_char_T(&str);
}

/*
 * Output and update for atomic system:
 *    '3WV_function' (':903:1')
 *    '3WV_function' (':1075:1')
 *    '3WV_function' (':907:1')
 *    '3WV_function' (':904:1')
 */
void parallel_SST_model_uWV_function(real_T rtu_m_1, real_T rtu_T_1, real_T
  rtu_m_2, real_T rtu_T_2, real_T rtu_m_3, real_T rtu_T_3, real_T rtu_merge,
  real_T *rty_m_1_, real_T *rty_T_1_, real_T *rty_m_2_, real_T *rty_T_2_, real_T
  *rty_m_3_, real_T *rty_T_3_, real_T rtp_unknown_T, real_T rtp_unknown_m)
{
  emxArray_char_T_parallel_SST__T *b_str;
  emxArray_char_T_parallel_SST__T *c_str;
  emxArray_char_T_parallel_SST__T *d_str;
  emxArray_char_T_parallel_SST__T *e_str;
  emxArray_char_T_parallel_SST__T *str;
  real_T T_1;
  real_T T_2;
  real_T m_1;
  real_T m_1_;
  real_T m_2;
  real_T m_2_;
  real_T m_3;
  real_T m_3_;
  int32_T nbytes;
  int32_T tmp;
  m_1 = rtu_m_1;
  T_1 = rtu_T_1;
  m_2 = rtu_m_2;
  T_2 = rtu_T_2;
  m_3 = rtu_m_3;

  /* :  if m_1 < 0 */
  if (rtu_m_1 < 0.0)
  {
    /* :  sprintf('3-way valve: m_1 < 0 (m_1=%1.2e), used value is m_1=0\n', m_1); */
    nbytes = (int32_T)snprintf(NULL, 0,
      "3-way valve: m_1 < 0 (m_1=%1.2e), used value is m_1=0\n", rtu_m_1) + 1;
    parallel_SST_mod_emxInit_char_T(&str, 2);
    tmp = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = nbytes;
    parall_emxEnsureCapacity_char_T(str, tmp);
    snprintf(&str->data[0], (size_t)nbytes,
             "3-way valve: m_1 < 0 (m_1=%1.2e), used value is m_1=0\n", rtu_m_1);
    parallel_SST_mod_emxFree_char_T(&str);

    /* :  m_1 = 0; */
    m_1 = 0.0;
  }

  /* :  if m_2 < 0 */
  if (rtu_m_2 < 0.0)
  {
    /* :  sprintf('3-way valve: m_2 < 0 (m_2=%1.2e), used value is m_2=0\n', m_2); */
    nbytes = (int32_T)snprintf(NULL, 0,
      "3-way valve: m_2 < 0 (m_2=%1.2e), used value is m_2=0\n", rtu_m_2) + 1;
    parallel_SST_mod_emxInit_char_T(&b_str, 2);
    tmp = b_str->size[0] * b_str->size[1];
    b_str->size[0] = 1;
    b_str->size[1] = nbytes;
    parall_emxEnsureCapacity_char_T(b_str, tmp);
    snprintf(&b_str->data[0], (size_t)nbytes,
             "3-way valve: m_2 < 0 (m_2=%1.2e), used value is m_2=0\n", rtu_m_2);
    parallel_SST_mod_emxFree_char_T(&b_str);

    /* :  m_2 = 0; */
    m_2 = 0.0;
  }

  /* :  if m_3 < 0 */
  if (rtu_m_3 < 0.0)
  {
    /* :  sprintf('3-way valve: m_3 < 0 (m_3=%1.2e), used value is m_3=0\n', m_3); */
    nbytes = (int32_T)snprintf(NULL, 0,
      "3-way valve: m_3 < 0 (m_3=%1.2e), used value is m_3=0\n", rtu_m_3) + 1;
    parallel_SST_mod_emxInit_char_T(&c_str, 2);
    tmp = c_str->size[0] * c_str->size[1];
    c_str->size[0] = 1;
    c_str->size[1] = nbytes;
    parall_emxEnsureCapacity_char_T(c_str, tmp);
    snprintf(&c_str->data[0], (size_t)nbytes,
             "3-way valve: m_3 < 0 (m_3=%1.2e), used value is m_3=0\n", rtu_m_3);
    parallel_SST_mod_emxFree_char_T(&c_str);

    /* :  m_3 = 0; */
    m_3 = 0.0;
  }

  /* :  m_1_ = 1000; */
  m_1_ = 1000.0;

  /* :  m_2_ = 1000; */
  m_2_ = 1000.0;

  /* :  m_3_ = 1000; */
  m_3_ = 1000.0;

  /* :  T_1_ = 1000; */
  *rty_T_1_ = 1000.0;

  /* :  T_2_ = 1000; */
  *rty_T_2_ = 1000.0;

  /* :  T_3_ = 1000; */
  *rty_T_3_ = 1000.0;

  /* :  if merge */
  parallel_SST_mod_emxInit_char_T(&d_str, 2);
  if (rtu_merge != 0.0)
  {
    /* :  switch unknown_m */
    switch ((int32_T)rtp_unknown_m)
    {
     case 1:
      /* :  case 1 */
      /* :  if m_3 < m_2 */
      if (m_3 < m_2)
      {
        /* :  sprintf('3-way valve: m_3 (%1.2e) < m_2 (%1.2e), used value is m_2=m_3\n', m_3, m_2); */
        nbytes = (int32_T)snprintf(NULL, 0,
          "3-way valve: m_3 (%1.2e) < m_2 (%1.2e), used value is m_2=m_3\n", m_3,
          m_2) + 1;
        tmp = d_str->size[0] * d_str->size[1];
        d_str->size[0] = 1;
        d_str->size[1] = nbytes;
        parall_emxEnsureCapacity_char_T(d_str, tmp);
        snprintf(&d_str->data[0], (size_t)nbytes,
                 "3-way valve: m_3 (%1.2e) < m_2 (%1.2e), used value is m_2=m_3\n",
                 m_3, m_2);

        /* :  m_2 = m_3; */
        m_2 = m_3;
      }

      /* :  m_2_ = m_2; */
      m_2_ = m_2;

      /* :  m_3_ = m_3; */
      m_3_ = m_3;

      /* :  m_1_ = m_3_ - m_2_; */
      m_1_ = m_3 - m_2;
      break;

     case 2:
      /* :  case 2 */
      /* :  if m_3 < m_1 */
      if (m_3 < m_1)
      {
        /* :  sprintf('3-way valve: m_3 (%1.2e) < m_1 (%1.2e), used value is m_1=m_3\n', m_3, m_1); */
        nbytes = (int32_T)snprintf(NULL, 0,
          "3-way valve: m_3 (%1.2e) < m_1 (%1.2e), used value is m_1=m_3\n", m_3,
          m_1) + 1;
        tmp = d_str->size[0] * d_str->size[1];
        d_str->size[0] = 1;
        d_str->size[1] = nbytes;
        parall_emxEnsureCapacity_char_T(d_str, tmp);
        snprintf(&d_str->data[0], (size_t)nbytes,
                 "3-way valve: m_3 (%1.2e) < m_1 (%1.2e), used value is m_1=m_3\n",
                 m_3, m_1);

        /* :  m_1 = m_3; */
        m_1 = m_3;
      }

      /* :  m_1_ = m_1; */
      m_1_ = m_1;

      /* :  m_3_ = m_3; */
      m_3_ = m_3;

      /* :  m_2_ = m_3_ - m_1_; */
      m_2_ = m_3 - m_1;
      break;

     case 3:
      /* :  case 3 */
      /* :  m_1_ = m_1; */
      m_1_ = m_1;

      /* :  m_2_ = m_2; */
      m_2_ = m_2;

      /* :  m_3_ = m_1_ + m_2_; */
      m_3_ = m_1 + m_2;
      break;
    }

    /* :  switch unknown_T */
    switch ((int32_T)rtp_unknown_T)
    {
     case 1:
      /* :  case 1 */
      /* :  if m_1_ == 0 */
      if (m_1_ == 0.0)
      {
        /* :  if T_2 ~= T_3 */
        if (rtu_T_2 != rtu_T_3)
        {
          /* :  sprintf('3-way valve: T_2 (%2.1f) != T_3 (%2.1f), used value is T_2=T_3\n', T_2, T_3); */
          parallel_SST_model_sprintf(rtu_T_2, rtu_T_3);

          /* :  T_2 = T_3; */
          T_2 = rtu_T_3;
        }

        /* :  T_2_ = T_2; */
        *rty_T_2_ = T_2;

        /* :  T_3_ = T_3; */
        *rty_T_3_ = rtu_T_3;

        /* :  T_1_ = T_2; */
        *rty_T_1_ = T_2;
      }
      else
      {
        /* :  else */
        /* :  T_2_ = T_2; */
        *rty_T_2_ = rtu_T_2;

        /* :  T_3_ = T_3; */
        *rty_T_3_ = rtu_T_3;

        /* :  T_1_  = (m_3_ * T_3_ - m_2_ * T_2_ ) / m_1_; */
        *rty_T_1_ = (m_3_ * rtu_T_3 - m_2_ * rtu_T_2) / m_1_;
      }
      break;

     case 2:
      /* :  case 2 */
      /* :  if m_2_ == 0 */
      if (m_2_ == 0.0)
      {
        /* :  if T_1 ~= T_3 */
        if (rtu_T_1 != rtu_T_3)
        {
          /* :  sprintf('3-way valve: T_1 (%2.1f) != T_3 (%2.1f), used value is T_1=T_3\n', T_1, T_3); */
          parallel_SST_model_sprintf_f(rtu_T_1, rtu_T_3);

          /* :  T_1 = T_3; */
          T_1 = rtu_T_3;
        }

        /* :  T_1_ = T_1; */
        *rty_T_1_ = T_1;

        /* :  T_3_ = T_3; */
        *rty_T_3_ = rtu_T_3;

        /* :  T_2_ = T_1; */
        *rty_T_2_ = T_1;
      }
      else
      {
        /* :  else */
        /* :  T_1_ = T_1; */
        *rty_T_1_ = rtu_T_1;

        /* :  T_3_ = T_3; */
        *rty_T_3_ = rtu_T_3;

        /* :  T_2_  = (m_3_ * T_3_ - m_1_ * T_1_ ) / m_2_; */
        *rty_T_2_ = (m_3_ * rtu_T_3 - m_1_ * rtu_T_1) / m_2_;
      }
      break;

     case 3:
      /* :  case 3 */
      /* :  if m_3_ == 0 */
      if (m_3_ == 0.0)
      {
        /* :  T_1_ = T_1; */
        *rty_T_1_ = rtu_T_1;

        /* :  T_2_ = T_2; */
        *rty_T_2_ = rtu_T_2;

        /* :  T_3_ = (T_1_ + T_2_) / 2; */
        *rty_T_3_ = (rtu_T_1 + rtu_T_2) / 2.0;
      }
      else
      {
        /* :  else */
        /* :  T_1_ = T_1; */
        *rty_T_1_ = rtu_T_1;

        /* :  T_2_ = T_2; */
        *rty_T_2_ = rtu_T_2;

        /* :  T_3_  = (m_1_ * T_1_ + m_2_ * T_2_ ) / m_3_; */
        *rty_T_3_ = (m_1_ * rtu_T_1 + m_2_ * rtu_T_2) / m_3_;
      }
      break;
    }
  }
  else
  {
    /* :  else */
    /* :  switch unknown_m */
    switch ((int32_T)rtp_unknown_m)
    {
     case 1:
      /* :  case 1 */
      /* :  m_2_ = m_2; */
      m_2_ = m_2;

      /* :  m_3_ = m_3; */
      m_3_ = m_3;

      /* :  m_1_ = m_2_ + m_3_; */
      m_1_ = m_2 + m_3;
      break;

     case 2:
      /* :  case 2 */
      /* :  if m_1 < m_3 */
      if (m_1 < m_3)
      {
        /* :  sprintf('3-way valve: m_1 (%1.2e) < m_3 (%1.2e), used value is m_3=m_1\n', m_1, m_3); */
        nbytes = (int32_T)snprintf(NULL, 0,
          "3-way valve: m_1 (%1.2e) < m_3 (%1.2e), used value is m_3=m_1\n", m_1,
          m_3) + 1;
        tmp = d_str->size[0] * d_str->size[1];
        d_str->size[0] = 1;
        d_str->size[1] = nbytes;
        parall_emxEnsureCapacity_char_T(d_str, tmp);
        snprintf(&d_str->data[0], (size_t)nbytes,
                 "3-way valve: m_1 (%1.2e) < m_3 (%1.2e), used value is m_3=m_1\n",
                 m_1, m_3);

        /* :  m_3 = m_1; */
        m_3 = m_1;
      }

      /* :  m_1_ = m_1; */
      m_1_ = m_1;

      /* :  m_3_ = m_3; */
      m_3_ = m_3;

      /* :  m_2_ = m_1_ - m_3_; */
      m_2_ = m_1 - m_3;
      break;

     case 3:
      /* :  case 3 */
      /* :  if m_1 < m_2 */
      if (m_1 < m_2)
      {
        /* :  sprintf('3-way valve: m_1 (%1.2e) < m_2 (%1.2e), used value is m_2=m_1\n', m_1, m_2); */
        nbytes = (int32_T)snprintf(NULL, 0,
          "3-way valve: m_1 (%1.2e) < m_2 (%1.2e), used value is m_2=m_1\n", m_1,
          m_2) + 1;
        tmp = d_str->size[0] * d_str->size[1];
        d_str->size[0] = 1;
        d_str->size[1] = nbytes;
        parall_emxEnsureCapacity_char_T(d_str, tmp);
        snprintf(&d_str->data[0], (size_t)nbytes,
                 "3-way valve: m_1 (%1.2e) < m_2 (%1.2e), used value is m_2=m_1\n",
                 m_1, m_2);

        /* :  m_2 = m_1; */
        m_2 = m_1;
      }

      /* :  m_1_ = m_1; */
      m_1_ = m_1;

      /* :  m_2_ = m_2; */
      m_2_ = m_2;

      /* :  m_3_ = m_1_ - m_2_; */
      m_3_ = m_1 - m_2;
      break;
    }

    /* :  switch unknown_T */
    switch ((int32_T)rtp_unknown_T)
    {
     case 1:
      /* :  case 1 */
      /* :  if T_2 ~= T_3 */
      if (rtu_T_2 != rtu_T_3)
      {
        /* :  sprintf('3-way valve: T_2 (%2.1f) != T_3 (%2.1f), used value is T_2=T_3\n', T_2, T_3); */
        parallel_SST_model_sprintf(rtu_T_2, rtu_T_3);

        /* :  T_2 = T_3; */
        T_2 = rtu_T_3;
      }

      /* :  T_2_ = T_2; */
      *rty_T_2_ = T_2;

      /* :  T_3_ = T_3; */
      *rty_T_3_ = rtu_T_3;

      /* :  T_1_ = T_2_; */
      *rty_T_1_ = T_2;
      break;

     case 2:
      /* :  case 2 */
      /* :  if T_1 ~= T_3 */
      if (rtu_T_1 != rtu_T_3)
      {
        /* :  sprintf('3-way valve: T_1 (%2.1f) != T_3 (%2.1f), used value is T_1=T_3\n', T_1, T_3); */
        parallel_SST_model_sprintf_f(rtu_T_1, rtu_T_3);

        /* :  T_1 = T_3; */
        T_1 = rtu_T_3;
      }

      /* :  T_1_ = T_1; */
      *rty_T_1_ = T_1;

      /* :  T_3_ = T_3; */
      *rty_T_3_ = rtu_T_3;

      /* :  T_2_ = T_1_; */
      *rty_T_2_ = T_1;
      break;

     case 3:
      /* :  case 3 */
      /* :  if T_1 ~= T_2 */
      if (rtu_T_1 != rtu_T_2)
      {
        /* :  sprintf('3-way valve: T_1 (%2.1f) != T_2 (%2.1f), used value is T_1=T_2\n', T_1, T_2); */
        nbytes = (int32_T)snprintf(NULL, 0,
          "3-way valve: T_1 (%2.1f) != T_2 (%2.1f), used value is T_1=T_2\n",
          rtu_T_1, rtu_T_2) + 1;
        parallel_SST_mod_emxInit_char_T(&e_str, 2);
        tmp = e_str->size[0] * e_str->size[1];
        e_str->size[0] = 1;
        e_str->size[1] = nbytes;
        parall_emxEnsureCapacity_char_T(e_str, tmp);
        snprintf(&e_str->data[0], (size_t)nbytes,
                 "3-way valve: T_1 (%2.1f) != T_2 (%2.1f), used value is T_1=T_2\n",
                 rtu_T_1, rtu_T_2);
        parallel_SST_mod_emxFree_char_T(&e_str);

        /* :  T_1 = T_2; */
        T_1 = rtu_T_2;
      }

      /* :  T_1_ = T_1; */
      *rty_T_1_ = T_1;

      /* :  T_2_ = T_2; */
      *rty_T_2_ = rtu_T_2;

      /* :  T_3_ = T_1_; */
      *rty_T_3_ = T_1;
      break;
    }
  }

  parallel_SST_mod_emxFree_char_T(&d_str);
  *rty_m_1_ = m_1_;
  *rty_m_2_ = m_2_;
  *rty_m_3_ = m_3_;
}

/*
 * Output and update for atomic system:
 *    'heat_exchanger_function' (':72:5')
 *    'heat_exchanger_function' (':73:5')
 */
void paralle_heat_exchanger_function(real_T rtu_m_1, real_T rtu_m_2, real_T
  rtu_T_1_in, real_T rtu_T_2_in, real_T *rty_T_1_out, real_T *rty_T_2_out,
  real_T *rty_Q, real_T *rty_efficiency, real_T rtp_A, real_T rtp_U)
{
  real_T C_min_tmp;
  real_T C_r;
  real_T NTU;

  /* :  Cp_1 = 4180; */
  /* :  Cp_2 = 4180; */
  /* :  if m_2 <= 0 || m_1 <= 0 || T_1_in == T_2_in */
  if ((rtu_m_2 <= 0.0) || (rtu_m_1 <= 0.0) || (rtu_T_1_in == rtu_T_2_in))
  {
    /* :  efficiency = 1; */
    C_r = 1.0;

    /* :  T_2_out = T_2_in; */
    NTU = rtu_T_2_in;

    /* :  T_1_out = T_1_in; */
    *rty_T_1_out = rtu_T_1_in;

    /* :  Q = 0; */
    C_min_tmp = 0.0;
  }
  else
  {
    /* :  else */
    /* :  C_min = min(m_1 * Cp_1, m_2 * Cp_2); */
    C_min_tmp = fmin(rtu_m_1 * 4180.0, rtu_m_2 * 4180.0);

    /* :  C_max = max(m_1 * Cp_1, m_2 * Cp_2); */
    /* :  C_r = C_min / C_max; */
    C_r = C_min_tmp / fmax(rtu_m_1 * 4180.0, rtu_m_2 * 4180.0);

    /* :  NTU = U*A/C_min; */
    NTU = rtp_U * rtp_A / C_min_tmp;

    /* :  if C_r < 1 */
    if (C_r < 1.0)
    {
      /* :  As = exp(-NTU*(1-C_r)); */
      NTU = exp((1.0 - C_r) * -NTU);

      /* :  efficiency = (1-As)/(1-As*C_r); */
      C_r = (1.0 - NTU) / (1.0 - NTU * C_r);
    }
    else
    {
      /* :  else */
      /* :  efficiency = NTU/(NTU+1); */
      C_r = NTU / (NTU + 1.0);
    }

    /* :  F_min = min(Cp_1*m_1,Cp_2*m_2); */
    /* :  T_2_out = T_2_in + (F_min/(Cp_2*m_2))*efficiency*(T_1_in - T_2_in); */
    NTU = C_min_tmp / (4180.0 * rtu_m_2) * C_r * (rtu_T_1_in - rtu_T_2_in) +
      rtu_T_2_in;

    /* :  Q = Cp_2*m_2*(T_2_out-T_2_in); */
    C_min_tmp = 4180.0 * rtu_m_2 * (NTU - rtu_T_2_in);

    /* :  T_1_out = T_1_in - Q / (m_1 * Cp_1); */
    *rty_T_1_out = rtu_T_1_in - C_min_tmp / (rtu_m_1 * 4180.0);
  }

  *rty_T_2_out = NTU;
  *rty_Q = C_min_tmp;
  *rty_efficiency = C_r;
}

static void parall_emxEnsureCapacity_real_T(emxArray_real_T_parallel_SST__T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0)
  {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++)
  {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize)
  {
    i = emxArray->allocatedSize;
    if (i < 16)
    {
      i = 16;
    }

    while (i < newNumel)
    {
      if (i > 1073741823)
      {
        i = MAX_int32_T;
      }
      else
      {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(real_T));
    if (emxArray->data != NULL)
    {
      memcpy(newData, emxArray->data, sizeof(real_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData)
      {
        free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void parallel_SST_mod_emxInit_real_T(emxArray_real_T_parallel_SST__T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T_parallel_SST__T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_parallel_SST__T *)malloc(sizeof
    (emxArray_real_T_parallel_SST__T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++)
  {
    emxArray->size[i] = 0;
  }
}

/*
 * Function for MATLAB Function: ''thermal_pipe_function' (':71:523')'
 * @(t, y)
 */
static void c7_parallel_SST_model_anonFcn1(const captured_var_parallel_SST_mod_T
  *n_dx, const captured_var_parallel_SST_mod_T *dx, const
  captured_var_parallel_SST_mod_T *tau, const captured_var_parallel_SST_mod_T
  *b_T_duct, real_T V, real_T T_in, const emxArray_real_T_parallel_SST__T *y,
  emxArray_real_T_parallel_SST__T *varargout_1)
{
  real_T varargout_1_tmp;
  real_T varargout_1_tmp_0;
  int32_T i;
  int32_T loop_ub_tmp;
  int32_T scalarLB;
  int32_T vectorUB;

  /* :  @(t, y) ODE(t, y, V, T_in) */
  /* :  out = zeros(n_dx, 1); */
  i = varargout_1->size[0];
  varargout_1->size[0] = (int32_T)n_dx->contents;
  parall_emxEnsureCapacity_real_T(varargout_1, i);
  if ((int32_T)n_dx->contents - 1 >= 0)
  {
    memset(&varargout_1->data[0], 0, (uint32_T)(int32_T)n_dx->contents * sizeof
           (real_T));
  }

  /* :  out(1) =     - (V/dx + 1/tau) * y(1) + 1/tau * T_duct + V * T_in / dx; */
  varargout_1_tmp = 1.0 / tau->contents;
  varargout_1_tmp_0 = -(V / dx->contents + varargout_1_tmp);
  varargout_1_tmp *= b_T_duct->contents;
  varargout_1->data[0] = (varargout_1_tmp_0 * y->data[0] + varargout_1_tmp) + V *
    T_in / dx->contents;

  /* :  for i=2:n_dx */
  loop_ub_tmp = (int32_T)(n_dx->contents - 1.0);
  scalarLB = ((int32_T)(n_dx->contents - 1.0) / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2)
  {
    _mm_storeu_pd(&varargout_1->data[i + 1], _mm_add_pd(_mm_add_pd(_mm_mul_pd
      (_mm_set1_pd(varargout_1_tmp_0), _mm_loadu_pd(&y->data[i + 1])),
      _mm_set1_pd(varargout_1_tmp)), _mm_div_pd(_mm_mul_pd(_mm_set1_pd(V),
      _mm_loadu_pd(&y->data[i])), _mm_set1_pd(dx->contents))));
  }

  for (i = scalarLB; i < loop_ub_tmp; i++)
  {
    /* :  out(i) = - (V/dx + 1/tau) * y(i) + 1/tau * T_duct + V * y(i-1) / dx; */
    varargout_1->data[i + 1] = (y->data[i + 1] * varargout_1_tmp_0 +
      varargout_1_tmp) + V * y->data[i] / dx->contents;
  }
}

static void parallel_SST_mod_emxFree_real_T(emxArray_real_T_parallel_SST__T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_parallel_SST__T *)NULL)
  {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_parallel_SST__T *)NULL;
  }
}

static void parallel_SST_binary_expand_op_1(emxArray_real_T_parallel_SST__T *in1,
  const emxArray_real_T_parallel_SST__T *in2)
{
  emxArray_real_T_parallel_SST__T *in2_0;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  parallel_SST_mod_emxInit_real_T(&in2_0, 1);
  if (in1->size[0] == 1)
  {
    i = in2_0->size[0];
    in2_0->size[0] = in2->size[0];
    parall_emxEnsureCapacity_real_T(in2_0, i);
  }
  else
  {
    i = in2_0->size[0];
    in2_0->size[0] = in1->size[0];
    parall_emxEnsureCapacity_real_T(in2_0, i);
  }

  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in1->size[0] != 1);
  if (in1->size[0] == 1)
  {
    loop_ub = in2->size[0];
  }
  else
  {
    loop_ub = in1->size[0];
  }

  for (i = 0; i < loop_ub; i++)
  {
    in2_0->data[i] = in2->data[i * stride_0_0] / fmax(in1->data[i * stride_1_0],
      1.0);
  }

  loop_ub = in2_0->size[0];
  i = in1->size[0];
  in1->size[0] = in2_0->size[0];
  parall_emxEnsureCapacity_real_T(in1, i);
  if (loop_ub - 1 >= 0)
  {
    memcpy(&in1->data[0], &in2_0->data[0], (uint32_T)loop_ub * sizeof(real_T));
  }

  parallel_SST_mod_emxFree_real_T(&in2_0);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1))
  {
    y = (rtNaN);
  }
  else
  {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1))
    {
      if (tmp == 1.0)
      {
        y = 1.0;
      }
      else if (tmp > 1.0)
      {
        if (u1 > 0.0)
        {
          y = (rtInf);
        }
        else
        {
          y = 0.0;
        }
      }
      else if (u1 > 0.0)
      {
        y = 0.0;
      }
      else
      {
        y = (rtInf);
      }
    }
    else if (tmp_0 == 0.0)
    {
      y = 1.0;
    }
    else if (tmp_0 == 1.0)
    {
      if (u1 > 0.0)
      {
        y = u0;
      }
      else
      {
        y = 1.0 / u0;
      }
    }
    else if (u1 == 2.0)
    {
      y = u0 * u0;
    }
    else if ((u1 == 0.5) && (u0 >= 0.0))
    {
      y = sqrt(u0);
    }
    else if ((u0 < 0.0) && (u1 > floor(u1)))
    {
      y = (rtNaN);
    }
    else
    {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: ''thermal_pipe_function' (':71:523')' */
static void parallel_SST_model_ntrp23(real_T t, real_T t0, const
  emxArray_real_T_parallel_SST__T *b_y0, real_T h, const
  emxArray_real_T_parallel_SST__T *f, emxArray_real_T_parallel_SST__T *y)
{
  __m128d tmp;
  __m128d tmp_0;
  __m128d tmp_1;
  __m128d tmp_2;
  emxArray_real_T_parallel_SST__T *fhBI1;
  emxArray_real_T_parallel_SST__T *fhBI2;
  emxArray_real_T_parallel_SST__T *fhBI3;
  real_T B_idx_1;
  real_T B_idx_2;
  real_T b_s;
  int32_T i;
  int32_T loop_ub;
  int32_T neq_tmp;
  int32_T scalarLB_tmp;
  int32_T vectorUB_tmp;
  neq_tmp = b_y0->size[0];
  parallel_SST_mod_emxInit_real_T(&fhBI1, 1);
  loop_ub = f->size[0];
  i = fhBI1->size[0];
  fhBI1->size[0] = f->size[0];
  parall_emxEnsureCapacity_real_T(fhBI1, i);
  b_s = h * -1.3333333333333333;
  B_idx_2 = h * 1.3333333333333333;
  parallel_SST_mod_emxInit_real_T(&fhBI2, 1);
  i = fhBI2->size[0];
  fhBI2->size[0] = f->size[0];
  parall_emxEnsureCapacity_real_T(fhBI2, i);
  scalarLB_tmp = (f->size[0] / 2) << 1;
  vectorUB_tmp = scalarLB_tmp - 2;
  for (i = 0; i <= vectorUB_tmp; i += 2)
  {
    tmp_1 = _mm_set1_pd(h);
    _mm_storeu_pd(&fhBI1->data[i], _mm_mul_pd(_mm_loadu_pd(&f->data[i]), tmp_1));
    _mm_storeu_pd(&fhBI2->data[i], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&f->data[i]), _mm_set1_pd(b_s)), _mm_mul_pd(_mm_loadu_pd
      (&f->data[f->size[0] + i]), tmp_1)), _mm_mul_pd(_mm_loadu_pd(&f->data
      [(f->size[0] << 1) + i]), _mm_set1_pd(B_idx_2))), _mm_mul_pd(_mm_loadu_pd(
      &f->data[3 * f->size[0] + i]), _mm_set1_pd(-h))));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++)
  {
    fhBI1->data[i] = f->data[i] * h;
    fhBI2->data[i] = ((f->data[f->size[0] + i] * h + f->data[i] * b_s) + f->
                      data[(f->size[0] << 1) + i] * B_idx_2) + f->data[3 *
      f->size[0] + i] * -h;
  }

  b_s = h * 0.55555555555555558;
  B_idx_1 = h * -0.66666666666666663;
  B_idx_2 = h * -0.88888888888888884;
  parallel_SST_mod_emxInit_real_T(&fhBI3, 1);
  i = fhBI3->size[0];
  fhBI3->size[0] = f->size[0];
  parall_emxEnsureCapacity_real_T(fhBI3, i);
  for (i = 0; i <= vectorUB_tmp; i += 2)
  {
    _mm_storeu_pd(&fhBI3->data[i], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&f->data[i]), _mm_set1_pd(b_s)), _mm_mul_pd(_mm_loadu_pd
      (&f->data[f->size[0] + i]), _mm_set1_pd(B_idx_1))), _mm_mul_pd
      (_mm_loadu_pd(&f->data[(f->size[0] << 1) + i]), _mm_set1_pd(B_idx_2))),
      _mm_mul_pd(_mm_loadu_pd(&f->data[3 * f->size[0] + i]), _mm_set1_pd(h))));
  }

  for (i = scalarLB_tmp; i < loop_ub; i++)
  {
    fhBI3->data[i] = ((f->data[f->size[0] + i] * B_idx_1 + f->data[i] * b_s) +
                      f->data[(f->size[0] << 1) + i] * B_idx_2) + f->data[3 *
      f->size[0] + i] * h;
  }

  i = y->size[0];
  y->size[0] = b_y0->size[0];
  parall_emxEnsureCapacity_real_T(y, i);
  b_s = (t - t0) / h;
  loop_ub = (b_y0->size[0] / 2) << 1;
  scalarLB_tmp = loop_ub - 2;
  for (i = 0; i <= scalarLB_tmp; i += 2)
  {
    tmp_1 = _mm_loadu_pd(&fhBI3->data[i]);
    tmp_2 = _mm_set1_pd(b_s);
    tmp = _mm_loadu_pd(&fhBI2->data[i]);
    tmp_0 = _mm_loadu_pd(&fhBI1->data[i]);
    _mm_storeu_pd(&y->data[i], _mm_add_pd(_mm_mul_pd(_mm_add_pd(_mm_mul_pd
      (_mm_add_pd(_mm_mul_pd(tmp_1, tmp_2), tmp), tmp_2), tmp_0), tmp_2),
      _mm_loadu_pd(&b_y0->data[i])));
  }

  for (i = loop_ub; i < neq_tmp; i++)
  {
    y->data[i] = ((fhBI3->data[i] * b_s + fhBI2->data[i]) * b_s + fhBI1->data[i])
      * b_s + b_y0->data[i];
  }

  parallel_SST_mod_emxFree_real_T(&fhBI3);
  parallel_SST_mod_emxFree_real_T(&fhBI2);
  parallel_SST_mod_emxFree_real_T(&fhBI1);
}

/* Function for MATLAB Function: ''thermal_pipe_function' (':71:523')' */
static void parallel_SST_model_ode23(const captured_var_parallel_SST_mod_T
  *ode_workspace_n_dx, const captured_var_parallel_SST_mod_T *ode_workspace_dx,
  const captured_var_parallel_SST_mod_T *ode_workspace_tau, const
  captured_var_parallel_SST_mod_T *ode_workspace_T_duct, real_T ode_workspace_V,
  real_T ode_workspace_T_in, const emxArray_real_T_parallel_SST__T *tspan, const
  emxArray_real_T_parallel_SST__T *b_y0, emxArray_real_T_parallel_SST__T
  *varargout_1, emxArray_real_T_parallel_SST__T *varargout_2)
{
  __m128d tmp;
  __m128d tmp_0;
  __m128d tmp_2;
  __m128d tmp_3;
  emxArray_real_T_parallel_SST__T *f;
  emxArray_real_T_parallel_SST__T *f0;
  emxArray_real_T_parallel_SST__T *tout;
  emxArray_real_T_parallel_SST__T *y;
  emxArray_real_T_parallel_SST__T *ynew;
  emxArray_real_T_parallel_SST__T *yout;
  emxArray_real_T_parallel_SST__T *ystage;
  real_T tmp_1[2];
  real_T absh;
  real_T c;
  real_T c_absx;
  real_T c_c;
  real_T d1;
  real_T d2;
  real_T h;
  real_T num;
  real_T rh;
  real_T tdir;
  real_T tfinal_tmp;
  real_T twidth;
  int32_T Bcolidx;
  int32_T b_exponent;
  int32_T b_ix;
  int32_T e;
  int32_T g;
  int32_T ix;
  int32_T n;
  int32_T neq_tmp;
  int32_T next;
  int32_T nout;
  int32_T nx;
  int32_T ystage_tmp;
  boolean_T Done;
  boolean_T MinStepExit;
  boolean_T NoFailedAttempts;
  static const real_T x[6] =
  {
    0.5, 0.0, 0.75, 0.22222222222222221, 0.33333333333333331,
    0.44444444444444442
  };

  emxArray_real_T_parallel_SST__T b_y0_0;
  int32_T b_y0_1;
  int32_T exitg1;
  int32_T exitg2;
  tfinal_tmp = tspan->data[tspan->size[1] - 1];
  neq_tmp = b_y0->size[1];
  n = b_y0->size[1];
  b_y0_0 = *b_y0;
  b_y0_1 = n;
  b_y0_0.size = &b_y0_1;
  b_y0_0.numDimensions = 1;
  parallel_SST_mod_emxInit_real_T(&f0, 1);
  c7_parallel_SST_model_anonFcn1(ode_workspace_n_dx, ode_workspace_dx,
    ode_workspace_tau, ode_workspace_T_duct, ode_workspace_V, ode_workspace_T_in,
    &b_y0_0, f0);
  parallel_SST_mod_emxInit_real_T(&tout, 2);
  b_ix = tout->size[0] * tout->size[1];
  tout->size[0] = 1;
  n = tspan->size[1];
  tout->size[1] = tspan->size[1];
  parall_emxEnsureCapacity_real_T(tout, b_ix);
  if (n - 1 >= 0)
  {
    memset(&tout->data[0], 0, (uint32_T)n * sizeof(real_T));
  }

  parallel_SST_mod_emxInit_real_T(&yout, 2);
  b_ix = yout->size[0] * yout->size[1];
  yout->size[0] = b_y0->size[1];
  yout->size[1] = tspan->size[1];
  parall_emxEnsureCapacity_real_T(yout, b_ix);
  n = b_y0->size[1] * tspan->size[1];
  if (n - 1 >= 0)
  {
    memset(&yout->data[0], 0, (uint32_T)n * sizeof(real_T));
  }

  nout = 1;
  tout->data[0] = tspan->data[0];
  for (e = 0; e < neq_tmp; e++)
  {
    yout->data[e] = b_y0->data[e];
  }

  h = tfinal_tmp - tspan->data[0];
  twidth = fabs(h);
  absh = fabs(tspan->data[0]);
  twidth = fmin(twidth, fmax(0.1 * twidth, fmax(absh, fabs(tfinal_tmp)) *
    3.5527136788005009E-15));
  if (rtIsInf(absh) || rtIsNaN(absh))
  {
    tdir = (rtNaN);
  }
  else if (absh < 4.4501477170144028E-308)
  {
    tdir = 4.94065645841247E-324;
  }
  else
  {
    frexp(absh, &next);
    tdir = ldexp(1.0, next - 53);
  }

  absh = fmin(twidth, fabs(tspan->data[1] - tspan->data[0]));
  parallel_SST_mod_emxInit_real_T(&ystage, 1);
  next = ystage->size[0];
  ystage->size[0] = b_y0->size[1];
  parall_emxEnsureCapacity_real_T(ystage, next);
  for (next = 0; next < neq_tmp; next++)
  {
    ystage->data[next] = fabs(b_y0->data[next]);
  }

  if (f0->size[0] == ystage->size[0])
  {
    n = f0->size[0];
    next = ystage->size[0];
    ystage->size[0] = f0->size[0];
    parall_emxEnsureCapacity_real_T(ystage, next);
    nx = (f0->size[0] / 2) << 1;
    ix = nx - 2;
    for (e = 0; e <= ix; e += 2)
    {
      tmp_1[0] = fmax(ystage->data[e], 1.0);
      tmp_1[1] = fmax(ystage->data[e + 1], 1.0);
      tmp_2 = _mm_loadu_pd(&f0->data[e]);
      tmp_3 = _mm_loadu_pd(&tmp_1[0]);
      _mm_storeu_pd(&ystage->data[e], _mm_div_pd(tmp_2, tmp_3));
    }

    for (e = nx; e < n; e++)
    {
      ystage->data[e] = f0->data[e] / fmax(ystage->data[e], 1.0);
    }
  }
  else
  {
    parallel_SST_binary_expand_op_1(ystage, f0);
  }

  if (ystage->size[0] == 0)
  {
    rh = 0.0;
  }
  else
  {
    rh = 0.0;
    nx = ystage->size[0];
    for (next = 0; next < nx; next++)
    {
      c_absx = fabs(ystage->data[next]);
      if (rtIsNaN(c_absx))
      {
        rh = (rtNaN);
      }
      else if (c_absx > rh)
      {
        rh = c_absx;
      }
    }
  }

  rh /= 0.080000000000000016;
  if (absh * rh > 1.0)
  {
    absh = 1.0 / rh;
  }

  absh = fmax(absh, 16.0 * tdir);
  rh = tspan->data[0];
  parallel_SST_mod_emxInit_real_T(&y, 1);
  b_ix = y->size[0];
  y->size[0] = b_y0->size[1];
  parall_emxEnsureCapacity_real_T(y, b_ix);
  for (e = 0; e < neq_tmp; e++)
  {
    y->data[e] = b_y0->data[e];
  }

  parallel_SST_mod_emxInit_real_T(&f, 2);
  b_ix = f->size[0] * f->size[1];
  f->size[0] = b_y0->size[1];
  f->size[1] = 4;
  parall_emxEnsureCapacity_real_T(f, b_ix);
  n = b_y0->size[1] << 2;
  if (n - 1 >= 0)
  {
    memset(&f->data[0], 0, (uint32_T)n * sizeof(real_T));
  }

  if (neq_tmp - 1 >= 0)
  {
    memcpy(&f->data[0], &f0->data[0], (uint32_T)neq_tmp * sizeof(real_T));
  }

  if (rtIsNaN(h))
  {
    tdir = (rtNaN);
  }
  else if (h < 0.0)
  {
    tdir = -1.0;
  }
  else
  {
    tdir = (h > 0.0);
  }

  next = 0;
  MinStepExit = false;
  Done = false;
  parallel_SST_mod_emxInit_real_T(&ynew, 1);
  do
  {
    exitg1 = 0;
    c_absx = fabs(rh);
    if (rtIsInf(c_absx) || rtIsNaN(c_absx))
    {
      c_absx = (rtNaN);
    }
    else if (c_absx < 4.4501477170144028E-308)
    {
      c_absx = 4.94065645841247E-324;
    }
    else
    {
      frexp(c_absx, &b_exponent);
      c_absx = ldexp(1.0, b_exponent - 53);
    }

    c_absx *= 16.0;
    absh = fmin(twidth, fmax(c_absx, absh));
    h = tdir * absh;
    c = tfinal_tmp - rh;
    c_c = fabs(c);
    if (1.1 * absh >= c_c)
    {
      h = c;
      absh = c_c;
      Done = true;
    }

    NoFailedAttempts = true;
    do
    {
      exitg2 = 0;
      Bcolidx = 0;
      for (n = 0; n < 2; n++)
      {
        Bcolidx += n;
        b_ix = ystage->size[0];
        ystage->size[0] = neq_tmp;
        parall_emxEnsureCapacity_real_T(ystage, b_ix);
        if (neq_tmp - 1 >= 0)
        {
          memcpy(&ystage->data[0], &y->data[0], (uint32_T)neq_tmp * sizeof
                 (real_T));
        }

        if ((neq_tmp != 0) && (!(h == 0.0)))
        {
          b_ix = Bcolidx;
          e = neq_tmp * n + 1;
          for (nx = 1; neq_tmp < 0 ? nx >= e : nx <= e; nx += neq_tmp)
          {
            c_c = h * x[b_ix];
            g = (nx + neq_tmp) - 1;
            for (ix = nx; ix <= g; ix++)
            {
              ystage_tmp = ix - nx;
              ystage->data[ystage_tmp] += f->data[ix - 1] * c_c;
            }

            b_ix++;
          }
        }

        c7_parallel_SST_model_anonFcn1(ode_workspace_n_dx, ode_workspace_dx,
          ode_workspace_tau, ode_workspace_T_duct, ode_workspace_V,
          ode_workspace_T_in, ystage, f0);
        for (e = 0; e < neq_tmp; e++)
        {
          f->data[e + f->size[0] * (n + 1)] = f0->data[e];
        }
      }

      c_c = rh + h;
      b_ix = ynew->size[0];
      ynew->size[0] = neq_tmp;
      parall_emxEnsureCapacity_real_T(ynew, b_ix);
      if (neq_tmp - 1 >= 0)
      {
        memcpy(&ynew->data[0], &y->data[0], (uint32_T)neq_tmp * sizeof(real_T));
      }

      if ((neq_tmp != 0) && (!(h == 0.0)))
      {
        ix = Bcolidx;
        Bcolidx = (neq_tmp << 1) + 1;
        for (n = 1; neq_tmp < 0 ? n >= Bcolidx : n <= Bcolidx; n += neq_tmp)
        {
          c = x[ix + 2] * h;
          e = (n + neq_tmp) - 1;
          for (nx = n; nx <= e; nx++)
          {
            b_ix = nx - n;
            ynew->data[b_ix] += f->data[nx - 1] * c;
          }

          ix++;
        }
      }

      c7_parallel_SST_model_anonFcn1(ode_workspace_n_dx, ode_workspace_dx,
        ode_workspace_tau, ode_workspace_T_duct, ode_workspace_V,
        ode_workspace_T_in, ynew, f0);
      for (e = 0; e < neq_tmp; e++)
      {
        f->data[e + f->size[0] * 3] = f0->data[e];
      }

      b_ix = ystage->size[0];
      ystage->size[0] = neq_tmp;
      parall_emxEnsureCapacity_real_T(ystage, b_ix);
      nx = (neq_tmp / 2) << 1;
      ix = nx - 2;
      for (n = 0; n <= ix; n += 2)
      {
        tmp_2 = _mm_loadu_pd(&f->data[n]);
        tmp_3 = _mm_loadu_pd(&f->data[f->size[0] + n]);
        tmp = _mm_loadu_pd(&f->data[(f->size[0] << 1) + n]);
        tmp_0 = _mm_loadu_pd(&f->data[3 * f->size[0] + n]);
        _mm_storeu_pd(&ystage->data[n], _mm_add_pd(_mm_add_pd(_mm_add_pd
          (_mm_mul_pd(tmp_2, _mm_set1_pd(-0.069444444444444448)), _mm_mul_pd
           (tmp_3, _mm_set1_pd(0.083333333333333329))), _mm_mul_pd(tmp,
          _mm_set1_pd(0.1111111111111111))), _mm_mul_pd(tmp_0, _mm_set1_pd
          (-0.125))));
      }

      for (n = nx; n < neq_tmp; n++)
      {
        ystage->data[n] = ((f->data[f->size[0] + n] * 0.083333333333333329 +
                            f->data[n] * -0.069444444444444448) + f->data
                           [(f->size[0] << 1) + n] * 0.1111111111111111) +
          f->data[3 * f->size[0] + n] * -0.125;
      }

      if (Done)
      {
        c_c = tfinal_tmp;
      }

      h = c_c - rh;
      n = ystage->size[0];
      c = 0.0;
      for (nx = 0; nx < n; nx++)
      {
        num = fabs(ystage->data[nx]);
        d1 = fabs(y->data[nx]);
        d2 = fabs(ynew->data[nx]);
        if ((d1 > d2) || rtIsNaN(d2))
        {
          if (d1 > 1.0)
          {
            num /= d1;
          }
        }
        else if (d2 > 1.0)
        {
          num /= d2;
        }

        if (num > c)
        {
          c = num;
        }
        else if (rtIsNaN(num))
        {
          c = (rtNaN);
        }
      }

      c *= absh;
      if (!(c <= 0.001))
      {
        if (absh <= c_absx)
        {
          MinStepExit = true;
          exitg2 = 1;
        }
        else
        {
          if (NoFailedAttempts)
          {
            NoFailedAttempts = false;
            absh = fmax(c_absx, fmax(0.5, rt_powd_snf(0.001 / c,
              0.33333333333333331) * 0.8) * absh);
          }
          else
          {
            absh = fmax(c_absx, 0.5 * absh);
          }

          h = tdir * absh;
          Done = false;
        }
      }
      else
      {
        exitg2 = 1;
      }
    }
    while (exitg2 == 0);

    if (MinStepExit)
    {
      exitg1 = 1;
    }
    else
    {
      nx = next;
      while ((nx + 2 <= tspan->size[1]) && ((c_c - tspan->data[nx + 1]) * tdir >=
              0.0))
      {
        nx++;
      }

      ix = nx - next;
      if (ix > 0)
      {
        for (n = next + 2; n <= nx; n++)
        {
          c_absx = tspan->data[n - 1];
          tout->data[n - 1] = c_absx;
          parallel_SST_model_ntrp23(c_absx, rh, y, h, f, f0);
          for (e = 0; e < neq_tmp; e++)
          {
            yout->data[e + yout->size[0] * (n - 1)] = f0->data[e];
          }
        }

        tout->data[nx] = tspan->data[nx];
        if (tspan->data[nx] == c_c)
        {
          for (e = 0; e < neq_tmp; e++)
          {
            yout->data[e + yout->size[0] * nx] = ynew->data[e];
          }
        }
        else
        {
          parallel_SST_model_ntrp23(tspan->data[nx], rh, y, h, f, f0);
          for (e = 0; e < neq_tmp; e++)
          {
            yout->data[e + yout->size[0] * nx] = f0->data[e];
          }
        }

        nout += ix;
        next = nx;
      }

      if (Done)
      {
        exitg1 = 1;
      }
      else
      {
        if (NoFailedAttempts)
        {
          rh = rt_powd_snf(c / 0.001, 0.33333333333333331) * 1.25;
          if (rh > 0.2)
          {
            absh /= rh;
          }
          else
          {
            absh *= 5.0;
          }
        }

        rh = c_c;
        b_ix = y->size[0];
        y->size[0] = neq_tmp;
        parall_emxEnsureCapacity_real_T(y, b_ix);
        b_ix = f0->size[0];
        f0->size[0] = neq_tmp;
        parall_emxEnsureCapacity_real_T(f0, b_ix);
        for (e = 0; e < neq_tmp; e++)
        {
          y->data[e] = ynew->data[e];
          f0->data[e] = f->data[f->size[0] * 3 + e];
          f->data[e] = f0->data[e];
        }
      }
    }
  }
  while (exitg1 == 0);

  parallel_SST_mod_emxFree_real_T(&ystage);
  parallel_SST_mod_emxFree_real_T(&ynew);
  parallel_SST_mod_emxFree_real_T(&f);
  parallel_SST_mod_emxFree_real_T(&y);
  parallel_SST_mod_emxFree_real_T(&f0);
  b_ix = varargout_1->size[0];
  varargout_1->size[0] = nout;
  parall_emxEnsureCapacity_real_T(varargout_1, b_ix);
  if (nout - 1 >= 0)
  {
    memcpy(&varargout_1->data[0], &tout->data[0], (uint32_T)nout * sizeof(real_T));
  }

  parallel_SST_mod_emxFree_real_T(&tout);
  b_ix = varargout_2->size[0] * varargout_2->size[1];
  varargout_2->size[0] = nout;
  varargout_2->size[1] = b_y0->size[1];
  parall_emxEnsureCapacity_real_T(varargout_2, b_ix);
  for (e = 0; e < neq_tmp; e++)
  {
    for (next = 0; next < nout; next++)
    {
      varargout_2->data[next + varargout_2->size[0] * e] = yout->data[yout->
        size[0] * next + e];
    }
  }

  parallel_SST_mod_emxFree_real_T(&yout);
}

/* Function for MATLAB Function: ''thermal_pipe_function' (':71:523')' */
static real_T parallel_SST_m_colMajorFlatIter(const
  emxArray_real_T_parallel_SST__T *x, int32_T vlen)
{
  real_T y;
  int32_T b_k;
  int32_T firstBlockLength;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T xblockoffset;
  if (vlen <= 1024)
  {
    firstBlockLength = vlen;
    lastBlockLength = 0;
    nblocks = 1;
  }
  else
  {
    firstBlockLength = 1024;
    nblocks = vlen / 1024;
    lastBlockLength = vlen - (nblocks << 10);
    if (lastBlockLength > 0)
    {
      nblocks++;
    }
    else
    {
      lastBlockLength = 1024;
    }
  }

  y = x->data[0];
  for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset++)
  {
    y += x->data[xblockoffset - 1];
  }

  for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++)
  {
    real_T bsum;
    int32_T hi;
    xblockoffset = (firstBlockLength - 1) << 10;
    bsum = x->data[xblockoffset];
    if (firstBlockLength == nblocks)
    {
      hi = lastBlockLength;
    }
    else
    {
      hi = 1024;
    }

    for (b_k = 2; b_k <= hi; b_k++)
    {
      bsum += x->data[(xblockoffset + b_k) - 1];
    }

    y += bsum;
  }

  return y;
}

/*
 * Function for MATLAB Function: ''storage_TC_func' (':206:8')'
 * @(t, y)
 */
static void c13_parallel_SST_model_anonFcn1(const
  captured_var_parallel_SST_mod_T *b_n, const captured_var_1_parallel_SST_m_T
  *is_moving_grid, const captured_var_parallel_SST_mod_T *rho, const
  captured_var_parallel_SST_mod_T *V_tot, const captured_var_parallel_SST_mod_T *
  V_TC, const captured_var_parallel_SST_mod_T *Cp, const
  captured_var_parallel_SST_mod_T *b_U, const captured_var_parallel_SST_mod_T *P,
  const captured_var_parallel_SST_mod_T *A, const
  captured_var_parallel_SST_mod_T *b_T_amb, const
  captured_var_parallel_SST_mod_T *b_eps, const captured_var_parallel_SST_mod_T *
  dx, real_T m_top_, real_T m_bottom_, real_T m_down, real_T m_up, real_T T_top,
  real_T T_bottom, const emxArray_real_T_parallel_SST__T *y,
  emxArray_real_T_parallel_SST__T *varargout_1)
{
  __m128d tmp;
  __m128d tmp_0;
  __m128d tmp_1;
  real_T V1p;
  real_T Vn_;
  real_T Vn__tmp;
  real_T varargout_1_tmp;
  real_T varargout_1_tmp_0;
  real_T varargout_1_tmp_1;
  real_T varargout_1_tmp_2;
  real_T varargout_1_tmp_3;
  real_T varargout_1_tmp_4;
  int32_T i;
  int32_T loop_ub_tmp;
  int32_T scalarLB;
  int32_T vectorUB;

  /* :  @(t, y) ODE(t, y, m_top_, m_bottom_, m_down, m_up, T_top, T_bottom) */
  /* :  out = zeros(n+1, 1); */
  i = varargout_1->size[0];
  varargout_1->size[0] = (int32_T)(b_n->contents + 1.0);
  parall_emxEnsureCapacity_real_T(varargout_1, i);
  if ((int32_T)(b_n->contents + 1.0) - 1 >= 0)
  {
    memset(&varargout_1->data[0], 0, (uint32_T)(int32_T)(b_n->contents + 1.0) *
           sizeof(real_T));
  }

  /* :  if is_moving_grid */
  if (is_moving_grid->contents)
  {
    /* :  V1p = (m_bottom_ - m_top_) / rho; */
    V1p = (m_bottom_ - m_top_) / rho->contents;
  }
  else
  {
    /* :  else */
    /* :  V1p = 0; */
    V1p = 0.0;
  }

  /* :  Vn_ = V_tot - (y(n+1) + (n-2) * V_TC); */
  Vn__tmp = y->data[(int32_T)(b_n->contents + 1.0) - 1];
  Vn_ = V_tot->contents - ((b_n->contents - 2.0) * V_TC->contents + Vn__tmp);

  /* :  out(n) = (1 / (rho * Cp * Vn_))*... */
  /* :          ( ... */
  /* :          - rho*Cp*y(n)*(-V1p) ... */
  /* :          + Cp * (m_top_*T_top-m_bottom_*y(n)-m_down*y(n)+m_up*y(n-1)) ... */
  /* :          - U*P*(Vn_/A)*(y(n)-T_amb) ... */
  /* :          + eps * A * (y(n-1) - y(n)) / dx ... */
  /* :          ); */
  varargout_1_tmp = y->data[(int32_T)b_n->contents - 1];
  varargout_1_tmp_0 = y->data[(int32_T)(b_n->contents - 1.0) - 1];
  varargout_1_tmp_1 = b_U->contents * P->contents;
  varargout_1_tmp_2 = b_eps->contents * A->contents;
  varargout_1_tmp_3 = rho->contents * Cp->contents;
  varargout_1_tmp_4 = -rho->contents * Cp->contents;
  varargout_1->data[(int32_T)b_n->contents - 1] = ((((((m_top_ * T_top -
    varargout_1_tmp * m_bottom_) - varargout_1_tmp * m_down) + varargout_1_tmp_0
    * m_up) * Cp->contents + varargout_1_tmp_4 * varargout_1_tmp * -V1p) - Vn_ /
    A->contents * varargout_1_tmp_1 * (varargout_1_tmp - b_T_amb->contents)) +
    (varargout_1_tmp_0 - varargout_1_tmp) * varargout_1_tmp_2 / dx->contents) *
    (1.0 / (varargout_1_tmp_3 * Vn_));

  /* :  for i=2:n-1 */
  loop_ub_tmp = (int32_T)((b_n->contents - 1.0) - 1.0);
  scalarLB = ((int32_T)((b_n->contents - 1.0) - 1.0) / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2)
  {
    tmp = _mm_loadu_pd(&y->data[i]);
    tmp_0 = _mm_loadu_pd(&y->data[i + 1]);
    tmp_1 = _mm_loadu_pd(&y->data[i + 2]);
    _mm_storeu_pd(&varargout_1->data[i + 1], _mm_mul_pd(_mm_add_pd(_mm_sub_pd
      (_mm_mul_pd(_mm_add_pd(_mm_mul_pd(_mm_sub_pd(tmp, tmp_0), _mm_set1_pd(m_up)),
      _mm_mul_pd(_mm_sub_pd(tmp_1, tmp_0), _mm_set1_pd(m_down))), _mm_set1_pd
                  (Cp->contents)), _mm_mul_pd(_mm_set1_pd(varargout_1_tmp_1 *
      dx->contents), _mm_sub_pd(tmp_0, _mm_set1_pd(b_T_amb->contents)))),
      _mm_div_pd(_mm_mul_pd(_mm_add_pd(_mm_sub_pd(tmp_1, _mm_mul_pd(_mm_set1_pd
      (2.0), tmp_0)), tmp), _mm_set1_pd(varargout_1_tmp_2)), _mm_set1_pd
                 (dx->contents))), _mm_set1_pd(1.0 / (varargout_1_tmp_3 *
      V_TC->contents))));
  }

  for (i = scalarLB; i < loop_ub_tmp; i++)
  {
    /* :  out(i) = (1 / (rho * Cp * V_TC)) *... */
    /* :              ( ... */
    /* :              Cp * (m_up * (y(i-1) - y(i)) + m_down * (y(i+1) - y(i))) ... */
    /* :              - U * P * dx * (y(i) - T_amb) ... */
    /* :              + eps * A * (y(i+1) - 2 * y(i) + y(i-1)) / dx ... */
    /* :              ); */
    Vn_ = y->data[i];
    varargout_1_tmp = y->data[i + 1];
    varargout_1_tmp_0 = y->data[i + 2];
    varargout_1->data[i + 1] = ((((Vn_ - varargout_1_tmp) * m_up +
      (varargout_1_tmp_0 - varargout_1_tmp) * m_down) * Cp->contents -
      varargout_1_tmp_1 * dx->contents * (varargout_1_tmp - b_T_amb->contents))
      + ((varargout_1_tmp_0 - 2.0 * varargout_1_tmp) + Vn_) * varargout_1_tmp_2 /
      dx->contents) * (1.0 / (varargout_1_tmp_3 * V_TC->contents));
  }

  /* :  out(1) = (1 / (rho * Cp * y(n+1)))*... */
  /* :          ( ... */
  /* :          - rho*Cp*y(1)*V1p ... */
  /* :          + Cp * (m_bottom_*T_bottom-m_top_*y(1)+m_down*y(2)-m_up*y(1)) ... */
  /* :          - U*P*(y(n+1)/A)*(y(1)-T_amb) ... */
  /* :          + eps * A * (y(2) - y(1)) / dx ... */
  /* :          ); */
  varargout_1->data[0] = ((((((m_bottom_ * T_bottom - m_top_ * y->data[0]) +
    m_down * y->data[1]) - m_up * y->data[0]) * Cp->contents + varargout_1_tmp_4
    * y->data[0] * V1p) - Vn__tmp / A->contents * varargout_1_tmp_1 * (y->data[0]
    - b_T_amb->contents)) + (y->data[1] - y->data[0]) * varargout_1_tmp_2 /
    dx->contents) * (1.0 / (Vn__tmp * varargout_1_tmp_3));

  /* :  out(n+1) = V1p; */
  varargout_1->data[(int32_T)(b_n->contents + 1.0) - 1] = V1p;
}

static void parallel_SST_binary_expand_op_2(emxArray_real_T_parallel_SST__T *in1,
  const emxArray_real_T_parallel_SST__T *in2)
{
  emxArray_real_T_parallel_SST__T *in2_0;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  parallel_SST_mod_emxInit_real_T(&in2_0, 1);
  loop_ub = in1->size[0];
  i = in2_0->size[0];
  in2_0->size[0] = in1->size[0];
  parall_emxEnsureCapacity_real_T(in2_0, i);
  stride_0_0 = (in2->size[0] != 1);
  for (i = 0; i < loop_ub; i++)
  {
    in2_0->data[i] = in2->data[i * stride_0_0] / fmax(in1->data[i], 1.0);
  }

  if (loop_ub - 1 >= 0)
  {
    memcpy(&in1->data[0], &in2_0->data[0], (uint32_T)loop_ub * sizeof(real_T));
  }

  parallel_SST_mod_emxFree_real_T(&in2_0);
}

/* Function for MATLAB Function: ''storage_TC_func' (':206:8')' */
static void parallel_SST_model_ode23_o(const s_JrTEP38GMfv0hLhSLyVGj_paral_T
  *ode_workspace, const real_T tspan[2], const emxArray_real_T_parallel_SST__T
  *b_y0, emxArray_real_T_parallel_SST__T *varargout_1,
  emxArray_real_T_parallel_SST__T *varargout_2)
{
  __m128d tmp;
  __m128d tmp_0;
  __m128d tmp_2;
  __m128d tmp_3;
  emxArray_real_T_parallel_SST__T *f;
  emxArray_real_T_parallel_SST__T *f0;
  emxArray_real_T_parallel_SST__T *tout;
  emxArray_real_T_parallel_SST__T *y;
  emxArray_real_T_parallel_SST__T *ynew;
  emxArray_real_T_parallel_SST__T *yout;
  emxArray_real_T_parallel_SST__T *ystage;
  real_T tmp_1[2];
  real_T absh;
  real_T absx;
  real_T b_absx;
  real_T b_c;
  real_T c_c;
  real_T d1;
  real_T d2;
  real_T h;
  real_T hmax;
  real_T rh;
  real_T tfinal;
  int32_T Bcolidx;
  int32_T b_ia;
  int32_T b_iac;
  int32_T b_ix;
  int32_T chunk;
  int32_T exponent;
  int32_T iy;
  int32_T l;
  int32_T neq_tmp;
  int32_T nout;
  int32_T nx;
  int32_T ystage_tmp;
  boolean_T Done;
  boolean_T MinStepExit;
  boolean_T NoFailedAttempts;
  static const real_T x[6] =
  {
    0.5, 0.0, 0.75, 0.22222222222222221, 0.33333333333333331,
    0.44444444444444442
  };

  int32_T exitg1;
  int32_T exitg2;
  tfinal = tspan[1];
  neq_tmp = b_y0->size[0];
  parallel_SST_mod_emxInit_real_T(&f0, 1);
  c13_parallel_SST_model_anonFcn1(ode_workspace->n,
    ode_workspace->is_moving_grid, ode_workspace->rho, ode_workspace->V_tot,
    ode_workspace->V_TC, ode_workspace->Cp, ode_workspace->U, ode_workspace->P,
    ode_workspace->A, ode_workspace->T_amb, ode_workspace->eps,
    ode_workspace->dx, ode_workspace->m_top_, ode_workspace->m_bottom_,
    ode_workspace->m_down, ode_workspace->m_up, ode_workspace->T_top,
    ode_workspace->T_bottom, b_y0, f0);
  if (b_y0->size[0] == 0)
  {
    b_ix = MAX_int32_T;

    /* Divide by zero handler */
  }
  else
  {
    b_ix = (int32_T)(8192U / (uint32_T)b_y0->size[0]);
  }

  if (b_ix + 1 >= 100)
  {
    chunk = 100;
  }
  else
  {
    chunk = b_ix + 1;
  }

  parallel_SST_mod_emxInit_real_T(&tout, 2);
  b_ia = tout->size[0] * tout->size[1];
  tout->size[0] = 1;
  tout->size[1] = chunk;
  parall_emxEnsureCapacity_real_T(tout, b_ia);
  if (chunk - 1 >= 0)
  {
    memset(&tout->data[0], 0, (uint32_T)chunk * sizeof(real_T));
  }

  parallel_SST_mod_emxInit_real_T(&yout, 2);
  b_ia = yout->size[0] * yout->size[1];
  yout->size[0] = b_y0->size[0];
  yout->size[1] = chunk;
  parall_emxEnsureCapacity_real_T(yout, b_ia);
  nx = b_y0->size[0] * chunk;
  if (nx - 1 >= 0)
  {
    memset(&yout->data[0], 0, (uint32_T)nx * sizeof(real_T));
  }

  nout = 0;
  tout->data[0] = 0.0;
  absh = fabs(tspan[1]);
  hmax = fmin(absh, fmax(0.1 * absh, 3.5527136788005009E-15 * fmax(0.0, absh)));
  absh = fmin(hmax, absh);
  parallel_SST_mod_emxInit_real_T(&ystage, 1);
  b_ia = ystage->size[0];
  ystage->size[0] = b_y0->size[0];
  parall_emxEnsureCapacity_real_T(ystage, b_ia);
  for (Bcolidx = 0; Bcolidx < neq_tmp; Bcolidx++)
  {
    yout->data[Bcolidx] = b_y0->data[Bcolidx];
    ystage->data[Bcolidx] = fabs(b_y0->data[Bcolidx]);
  }

  if (f0->size[0] == ystage->size[0])
  {
    nx = f0->size[0];
    b_ia = ystage->size[0];
    ystage->size[0] = f0->size[0];
    parall_emxEnsureCapacity_real_T(ystage, b_ia);
    Bcolidx = (f0->size[0] / 2) << 1;
    iy = Bcolidx - 2;
    for (b_ix = 0; b_ix <= iy; b_ix += 2)
    {
      tmp_1[0] = fmax(ystage->data[b_ix], 1.0);
      tmp_1[1] = fmax(ystage->data[b_ix + 1], 1.0);
      tmp_2 = _mm_loadu_pd(&f0->data[b_ix]);
      tmp_3 = _mm_loadu_pd(&tmp_1[0]);
      _mm_storeu_pd(&ystage->data[b_ix], _mm_div_pd(tmp_2, tmp_3));
    }

    for (b_ix = Bcolidx; b_ix < nx; b_ix++)
    {
      ystage->data[b_ix] = f0->data[b_ix] / fmax(ystage->data[b_ix], 1.0);
    }
  }
  else
  {
    parallel_SST_binary_expand_op_2(ystage, f0);
  }

  if (ystage->size[0] == 0)
  {
    rh = 0.0;
  }
  else
  {
    rh = 0.0;
    nx = ystage->size[0];
    for (Bcolidx = 0; Bcolidx < nx; Bcolidx++)
    {
      b_absx = fabs(ystage->data[Bcolidx]);
      if (rtIsNaN(b_absx))
      {
        rh = (rtNaN);
      }
      else if (b_absx > rh)
      {
        rh = b_absx;
      }
    }
  }

  rh /= 0.017235477520255074;
  if (absh * rh > 1.0)
  {
    absh = 1.0 / rh;
  }

  absh = fmax(absh, 7.90505033345994E-323);
  b_absx = 0.0;
  parallel_SST_mod_emxInit_real_T(&y, 1);
  b_ia = y->size[0];
  y->size[0] = b_y0->size[0];
  parall_emxEnsureCapacity_real_T(y, b_ia);
  if (neq_tmp - 1 >= 0)
  {
    memcpy(&y->data[0], &b_y0->data[0], (uint32_T)neq_tmp * sizeof(real_T));
  }

  parallel_SST_mod_emxInit_real_T(&f, 2);
  b_ia = f->size[0] * f->size[1];
  f->size[0] = b_y0->size[0];
  f->size[1] = 4;
  parall_emxEnsureCapacity_real_T(f, b_ia);
  nx = b_y0->size[0] << 2;
  if (nx - 1 >= 0)
  {
    memset(&f->data[0], 0, (uint32_T)nx * sizeof(real_T));
  }

  if (neq_tmp - 1 >= 0)
  {
    memcpy(&f->data[0], &f0->data[0], (uint32_T)neq_tmp * sizeof(real_T));
  }

  if (rtIsNaN(tspan[1]))
  {
    rh = (rtNaN);
  }
  else if (tspan[1] < 0.0)
  {
    rh = -1.0;
  }
  else
  {
    rh = (tspan[1] > 0.0);
  }

  MinStepExit = false;
  Done = false;
  parallel_SST_mod_emxInit_real_T(&ynew, 1);
  do
  {
    exitg1 = 0;
    absx = fabs(b_absx);
    if (rtIsInf(absx) || rtIsNaN(absx))
    {
      absx = (rtNaN);
    }
    else if (absx < 4.4501477170144028E-308)
    {
      absx = 4.94065645841247E-324;
    }
    else
    {
      frexp(absx, &exponent);
      absx = ldexp(1.0, exponent - 53);
    }

    absx *= 16.0;
    absh = fmin(hmax, fmax(absx, absh));
    h = rh * absh;
    b_c = tfinal - b_absx;
    c_c = fabs(b_c);
    if (1.1 * absh >= c_c)
    {
      h = b_c;
      absh = c_c;
      Done = true;
    }

    NoFailedAttempts = true;
    do
    {
      exitg2 = 0;
      Bcolidx = 0;
      for (nx = 0; nx < 2; nx++)
      {
        Bcolidx += nx;
        b_ia = ystage->size[0];
        ystage->size[0] = neq_tmp;
        parall_emxEnsureCapacity_real_T(ystage, b_ia);
        if (neq_tmp - 1 >= 0)
        {
          memcpy(&ystage->data[0], &y->data[0], (uint32_T)neq_tmp * sizeof
                 (real_T));
        }

        if (!(h == 0.0))
        {
          b_ix = Bcolidx;
          iy = neq_tmp * nx + 1;
          for (b_iac = 1; neq_tmp < 0 ? b_iac >= iy : b_iac <= iy; b_iac +=
               neq_tmp)
          {
            c_c = h * x[b_ix];
            l = (b_iac + neq_tmp) - 1;
            for (b_ia = b_iac; b_ia <= l; b_ia++)
            {
              ystage_tmp = b_ia - b_iac;
              ystage->data[ystage_tmp] += f->data[b_ia - 1] * c_c;
            }

            b_ix++;
          }
        }

        c13_parallel_SST_model_anonFcn1(ode_workspace->n,
          ode_workspace->is_moving_grid, ode_workspace->rho,
          ode_workspace->V_tot, ode_workspace->V_TC, ode_workspace->Cp,
          ode_workspace->U, ode_workspace->P, ode_workspace->A,
          ode_workspace->T_amb, ode_workspace->eps, ode_workspace->dx,
          ode_workspace->m_top_, ode_workspace->m_bottom_, ode_workspace->m_down,
          ode_workspace->m_up, ode_workspace->T_top, ode_workspace->T_bottom,
          ystage, f0);
        for (b_ix = 0; b_ix < neq_tmp; b_ix++)
        {
          f->data[b_ix + f->size[0] * (nx + 1)] = f0->data[b_ix];
        }
      }

      c_c = b_absx + h;
      b_ia = ynew->size[0];
      ynew->size[0] = neq_tmp;
      parall_emxEnsureCapacity_real_T(ynew, b_ia);
      if (neq_tmp - 1 >= 0)
      {
        memcpy(&ynew->data[0], &y->data[0], (uint32_T)neq_tmp * sizeof(real_T));
      }

      if (!(h == 0.0))
      {
        nx = (neq_tmp << 1) + 1;
        for (b_ix = 1; neq_tmp < 0 ? b_ix >= nx : b_ix <= nx; b_ix += neq_tmp)
        {
          b_c = x[Bcolidx + 2] * h;
          b_iac = (b_ix + neq_tmp) - 1;
          for (iy = b_ix; iy <= b_iac; iy++)
          {
            l = iy - b_ix;
            ynew->data[l] += f->data[iy - 1] * b_c;
          }

          Bcolidx++;
        }
      }

      c13_parallel_SST_model_anonFcn1(ode_workspace->n,
        ode_workspace->is_moving_grid, ode_workspace->rho, ode_workspace->V_tot,
        ode_workspace->V_TC, ode_workspace->Cp, ode_workspace->U,
        ode_workspace->P, ode_workspace->A, ode_workspace->T_amb,
        ode_workspace->eps, ode_workspace->dx, ode_workspace->m_top_,
        ode_workspace->m_bottom_, ode_workspace->m_down, ode_workspace->m_up,
        ode_workspace->T_top, ode_workspace->T_bottom, ynew, f0);
      for (b_ix = 0; b_ix < neq_tmp; b_ix++)
      {
        f->data[b_ix + f->size[0] * 3] = f0->data[b_ix];
      }

      b_ia = ystage->size[0];
      ystage->size[0] = neq_tmp;
      parall_emxEnsureCapacity_real_T(ystage, b_ia);
      Bcolidx = (neq_tmp / 2) << 1;
      iy = Bcolidx - 2;
      for (nx = 0; nx <= iy; nx += 2)
      {
        tmp_2 = _mm_loadu_pd(&f->data[nx]);
        tmp_3 = _mm_loadu_pd(&f->data[f->size[0] + nx]);
        tmp = _mm_loadu_pd(&f->data[(f->size[0] << 1) + nx]);
        tmp_0 = _mm_loadu_pd(&f->data[3 * f->size[0] + nx]);
        _mm_storeu_pd(&ystage->data[nx], _mm_add_pd(_mm_add_pd(_mm_add_pd
          (_mm_mul_pd(tmp_2, _mm_set1_pd(-0.069444444444444448)), _mm_mul_pd
           (tmp_3, _mm_set1_pd(0.083333333333333329))), _mm_mul_pd(tmp,
          _mm_set1_pd(0.1111111111111111))), _mm_mul_pd(tmp_0, _mm_set1_pd
          (-0.125))));
      }

      for (nx = Bcolidx; nx < neq_tmp; nx++)
      {
        ystage->data[nx] = ((f->data[f->size[0] + nx] * 0.083333333333333329 +
                             f->data[nx] * -0.069444444444444448) + f->data
                            [(f->size[0] << 1) + nx] * 0.1111111111111111) +
          f->data[3 * f->size[0] + nx] * -0.125;
      }

      if (Done)
      {
        c_c = tfinal;
      }

      nx = ystage->size[0];
      h = 0.0;
      for (Bcolidx = 0; Bcolidx < nx; Bcolidx++)
      {
        b_c = fabs(ystage->data[Bcolidx]);
        d1 = fabs(y->data[Bcolidx]);
        d2 = fabs(ynew->data[Bcolidx]);
        if ((d1 > d2) || rtIsNaN(d2))
        {
          if (d1 > 1.0)
          {
            b_c /= d1;
          }
        }
        else if (d2 > 1.0)
        {
          b_c /= d2;
        }

        if (b_c > h)
        {
          h = b_c;
        }
        else if (rtIsNaN(b_c))
        {
          h = (rtNaN);
        }
      }

      h *= absh;
      if (!(h <= 1.0E-5))
      {
        if (absh <= absx)
        {
          MinStepExit = true;
          exitg2 = 1;
        }
        else
        {
          if (NoFailedAttempts)
          {
            NoFailedAttempts = false;
            absh = fmax(absx, fmax(0.5, rt_powd_snf(1.0E-5 / h,
              0.33333333333333331) * 0.8) * absh);
          }
          else
          {
            absh = fmax(absx, 0.5 * absh);
          }

          h = rh * absh;
          Done = false;
        }
      }
      else
      {
        exitg2 = 1;
      }
    }
    while (exitg2 == 0);

    if (MinStepExit)
    {
      exitg1 = 1;
    }
    else
    {
      nout++;
      if (nout + 1 > tout->size[1])
      {
        Bcolidx = tout->size[1];
        b_ia = tout->size[0] * tout->size[1];
        tout->size[0] = 1;
        b_ix = tout->size[1] + chunk;
        tout->size[1] = b_ix;
        parall_emxEnsureCapacity_real_T(tout, b_ia);
        b_iac = (uint8_T)chunk;
        b_ia = yout->size[0] * yout->size[1];
        yout->size[1] = b_ix;
        parall_emxEnsureCapacity_real_T(yout, b_ia);
        for (nx = 0; nx < b_iac; nx++)
        {
          b_ia = Bcolidx + nx;
          tout->data[b_ia] = 0.0;
          for (iy = 0; iy < neq_tmp; iy++)
          {
            yout->data[iy + yout->size[0] * b_ia] = 0.0;
          }
        }
      }

      tout->data[nout] = c_c;
      for (nx = 0; nx < neq_tmp; nx++)
      {
        yout->data[nx + yout->size[0] * nout] = ynew->data[nx];
      }

      if (Done)
      {
        exitg1 = 1;
      }
      else
      {
        if (NoFailedAttempts)
        {
          b_absx = rt_powd_snf(h / 1.0E-5, 0.33333333333333331) * 1.25;
          if (b_absx > 0.2)
          {
            absh /= b_absx;
          }
          else
          {
            absh *= 5.0;
          }
        }

        b_absx = c_c;
        b_ia = y->size[0];
        y->size[0] = neq_tmp;
        parall_emxEnsureCapacity_real_T(y, b_ia);
        b_ia = f0->size[0];
        f0->size[0] = neq_tmp;
        parall_emxEnsureCapacity_real_T(f0, b_ia);
        for (b_ix = 0; b_ix < neq_tmp; b_ix++)
        {
          y->data[b_ix] = ynew->data[b_ix];
          f0->data[b_ix] = f->data[f->size[0] * 3 + b_ix];
          f->data[b_ix] = f0->data[b_ix];
        }
      }
    }
  }
  while (exitg1 == 0);

  parallel_SST_mod_emxFree_real_T(&ystage);
  parallel_SST_mod_emxFree_real_T(&ynew);
  parallel_SST_mod_emxFree_real_T(&f);
  parallel_SST_mod_emxFree_real_T(&y);
  parallel_SST_mod_emxFree_real_T(&f0);
  b_ia = varargout_1->size[0];
  varargout_1->size[0] = nout + 1;
  parall_emxEnsureCapacity_real_T(varargout_1, b_ia);
  if (nout >= 0)
  {
    memcpy(&varargout_1->data[0], &tout->data[0], (uint32_T)(nout + 1) * sizeof
           (real_T));
  }

  parallel_SST_mod_emxFree_real_T(&tout);
  b_ia = varargout_2->size[0] * varargout_2->size[1];
  varargout_2->size[0] = nout + 1;
  varargout_2->size[1] = b_y0->size[0];
  parall_emxEnsureCapacity_real_T(varargout_2, b_ia);
  for (b_ix = 0; b_ix < neq_tmp; b_ix++)
  {
    for (chunk = 0; chunk <= nout; chunk++)
    {
      varargout_2->data[chunk + varargout_2->size[0] * b_ix] = yout->data
        [yout->size[0] * chunk + b_ix];
    }
  }

  parallel_SST_mod_emxFree_real_T(&yout);
}

/* Function for MATLAB Function: ''storage_TC_func' (':206:8')' */
static void parallel_SST_model_linspace(real_T d1, real_T d2, real_T b_n,
  emxArray_real_T_parallel_SST__T *y)
{
  real_T tmp[2];
  real_T delta1;
  real_T delta2;
  int32_T c_k;
  int32_T d_tmp;
  if (!(b_n >= 0.0))
  {
    y->size[0] = 1;
    y->size[1] = 0;
  }
  else
  {
    delta1 = floor(b_n);
    c_k = y->size[0] * y->size[1];
    y->size[0] = 1;
    d_tmp = (int32_T)floor(b_n);
    y->size[1] = (int32_T)delta1;
    parall_emxEnsureCapacity_real_T(y, c_k);
    if ((int32_T)delta1 >= 1)
    {
      y->data[(int32_T)delta1 - 1] = d2;
      if (y->size[1] >= 2)
      {
        y->data[0] = d1;
        if (y->size[1] >= 3)
        {
          if (d1 == -d2)
          {
            delta1 = d2 / ((real_T)y->size[1] - 1.0);
            for (c_k = 2; c_k < d_tmp; c_k++)
            {
              y->data[c_k - 1] = (real_T)(((c_k << 1) - y->size[1]) - 1) *
                delta1;
            }

            if (((uint32_T)y->size[1] & 1U) == 1U)
            {
              y->data[y->size[1] >> 1] = 0.0;
            }
          }
          else if (((d1 < 0.0) != (d2 < 0.0)) && ((fabs(d1) >
                     8.9884656743115785E+307) || (fabs(d2) >
                     8.9884656743115785E+307)))
          {
            _mm_storeu_pd(&tmp[0], _mm_div_pd(_mm_set_pd(d2, d1), _mm_sub_pd
              (_mm_set1_pd(y->size[1]), _mm_set1_pd(1.0))));
            delta1 = tmp[0];
            delta2 = tmp[1];
            for (c_k = 0; c_k <= d_tmp - 3; c_k++)
            {
              y->data[c_k + 1] = (((real_T)c_k + 1.0) * delta2 + d1) - ((real_T)
                c_k + 1.0) * delta1;
            }
          }
          else
          {
            delta1 = (d2 - d1) / ((real_T)y->size[1] - 1.0);
            for (c_k = 0; c_k <= d_tmp - 3; c_k++)
            {
              y->data[c_k + 1] = ((real_T)c_k + 1.0) * delta1 + d1;
            }
          }
        }
      }
    }
  }
}

static void parallel_SST_m_binary_expand_op(emxArray_real_T_parallel_SST__T *in1,
  const emxArray_real_T_parallel_SST__T *in2, const
  emxArray_real_T_parallel_SST__T *in3)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  /* MATLAB Function: 'storage_TC_func' (':206:8') */
  if (in3->size[0] == 1)
  {
    i = in1->size[0];
    in1->size[0] = in2->size[0];
    parall_emxEnsureCapacity_real_T(in1, i);
  }
  else
  {
    i = in1->size[0];
    in1->size[0] = in3->size[0];
    parall_emxEnsureCapacity_real_T(in1, i);
  }

  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  if (in3->size[0] == 1)
  {
    loop_ub = in2->size[0];
  }
  else
  {
    loop_ub = in3->size[0];
  }

  for (i = 0; i < loop_ub; i++)
  {
    in1->data[i] = in2->data[i * stride_0_0] * in3->data[i * stride_1_0];
  }

  /* End of MATLAB Function: 'storage_TC_func' (':206:8') */
}

/* Function for MATLAB Function: ''storage_TC_func' (':206:8')' */
static real_T parallel_SST_m_blockedSummation(const
  emxArray_real_T_parallel_SST__T *x, int32_T vlen)
{
  real_T y;
  int32_T b_k;
  int32_T firstBlockLength;
  int32_T xblockoffset;
  if (x->size[0] == 0)
  {
    y = 0.0;
  }
  else if (vlen == 0)
  {
    y = 0.0;
  }
  else
  {
    int32_T lastBlockLength;
    int32_T nblocks;
    if (vlen <= 1024)
    {
      firstBlockLength = vlen;
      lastBlockLength = 0;
      nblocks = 1;
    }
    else
    {
      firstBlockLength = 1024;
      nblocks = vlen / 1024;
      lastBlockLength = vlen - (nblocks << 10);
      if (lastBlockLength > 0)
      {
        nblocks++;
      }
      else
      {
        lastBlockLength = 1024;
      }
    }

    y = x->data[0];
    for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset++)
    {
      y += x->data[xblockoffset - 1];
    }

    for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++)
    {
      real_T bsum;
      int32_T hi;
      xblockoffset = (firstBlockLength - 1) << 10;
      bsum = x->data[xblockoffset];
      if (firstBlockLength == nblocks)
      {
        hi = lastBlockLength;
      }
      else
      {
        hi = 1024;
      }

      for (b_k = 2; b_k <= hi; b_k++)
      {
        bsum += x->data[(xblockoffset + b_k) - 1];
      }

      y += bsum;
    }
  }

  return y;
}

/* Function for MATLAB Function: ''storage_TC_func' (':206:8')' */
static real_T parallel_SST_model_std(const emxArray_real_T_parallel_SST__T *x,
  const emxArray_real_T_parallel_SST__T *varargin_1)
{
  __m128d tmp_1;
  emxArray_real_T_parallel_SST__T *absdiff;
  real_T tmp[2];
  real_T tmp_0[2];
  real_T absdiff_0;
  real_T wsum;
  real_T xbar;
  real_T y;
  int32_T k;
  int32_T kend_tmp;
  int32_T scalarLB_tmp;
  int32_T vectorUB_tmp;
  kend_tmp = x->size[0];
  switch (x->size[0])
  {
   case 0:
    y = (rtNaN);
    break;

   case 1:
    wsum = x->data[0] * varargin_1->data[0];
    if ((!rtIsInf(wsum)) && (!rtIsNaN(wsum)))
    {
      y = 0.0;
    }
    else
    {
      y = (rtNaN);
    }
    break;

   default:
    parallel_SST_mod_emxInit_real_T(&absdiff, 1);
    k = absdiff->size[0];
    absdiff->size[0] = x->size[0];
    parall_emxEnsureCapacity_real_T(absdiff, k);
    scalarLB_tmp = (x->size[0] / 2) << 1;
    vectorUB_tmp = scalarLB_tmp - 2;
    for (k = 0; k <= vectorUB_tmp; k += 2)
    {
      _mm_storeu_pd(&absdiff->data[k], _mm_mul_pd(_mm_loadu_pd(&varargin_1->
        data[k]), _mm_loadu_pd(&x->data[k])));
    }

    for (k = scalarLB_tmp; k < kend_tmp; k++)
    {
      absdiff->data[k] = varargin_1->data[k] * x->data[k];
    }

    wsum = parallel_SST_m_blockedSummation(varargin_1, x->size[0]);
    xbar = parallel_SST_m_blockedSummation(absdiff, x->size[0]) / wsum;
    k = absdiff->size[0];
    absdiff->size[0] = x->size[0];
    parall_emxEnsureCapacity_real_T(absdiff, k);
    for (k = 0; k <= vectorUB_tmp; k += 2)
    {
      _mm_storeu_pd(&tmp_0[0], _mm_sub_pd(_mm_loadu_pd(&x->data[k]), _mm_set1_pd
        (xbar)));
      tmp[0] = fabs(tmp_0[0]);
      tmp[1] = fabs(tmp_0[1]);
      tmp_1 = _mm_loadu_pd(&tmp[0]);
      _mm_storeu_pd(&absdiff->data[k], _mm_mul_pd(_mm_sqrt_pd(_mm_div_pd
        (_mm_loadu_pd(&varargin_1->data[k]), _mm_set1_pd(wsum))), tmp_1));
    }

    for (k = scalarLB_tmp; k < kend_tmp; k++)
    {
      absdiff->data[k] = sqrt(varargin_1->data[k] / wsum) * fabs(x->data[k] -
        xbar);
    }

    y = 0.0;
    wsum = 3.3121686421112381E-170;
    for (k = 0; k < kend_tmp; k++)
    {
      absdiff_0 = absdiff->data[k];
      if (absdiff_0 > wsum)
      {
        xbar = wsum / absdiff_0;
        y = y * xbar * xbar + 1.0;
        wsum = absdiff_0;
      }
      else
      {
        xbar = absdiff_0 / wsum;
        y += xbar * xbar;
      }
    }

    parallel_SST_mod_emxFree_real_T(&absdiff);
    y = wsum * sqrt(y);
    break;
  }

  return y;
}

/* Function for MATLAB Function: ''storage_TC_func' (':206:8')' */
static void parallel_SST_model_minimum(const emxArray_real_T_parallel_SST__T *x,
  real_T *ex, int32_T *idx)
{
  int32_T k;
  int32_T last_tmp;
  last_tmp = x->size[0];
  if (x->size[0] <= 2)
  {
    if (x->size[0] == 1)
    {
      *ex = x->data[0];
      *idx = 1;
    }
    else
    {
      *ex = x->data[x->size[0] - 1];
      if ((x->data[0] > *ex) || (rtIsNaN(x->data[0]) && (!rtIsNaN(*ex))))
      {
        *idx = x->size[0];
      }
      else
      {
        *ex = x->data[0];
        *idx = 1;
      }
    }
  }
  else
  {
    int32_T b_idx;
    if (!rtIsNaN(x->data[0]))
    {
      b_idx = 1;
    }
    else
    {
      boolean_T exitg1;
      b_idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last_tmp))
      {
        if (!rtIsNaN(x->data[k - 1]))
        {
          b_idx = k;
          exitg1 = true;
        }
        else
        {
          k++;
        }
      }
    }

    if (b_idx == 0)
    {
      *ex = x->data[0];
      *idx = 1;
    }
    else
    {
      *ex = x->data[b_idx - 1];
      *idx = b_idx;
      for (k = b_idx + 1; k <= last_tmp; k++)
      {
        real_T x_0;
        x_0 = x->data[k - 1];
        if (*ex > x_0)
        {
          *ex = x_0;
          *idx = k;
        }
      }
    }
  }
}

/* Model step function */
void parallel_SST_model_step(void)
{
  __m128d tmp_0;
  __m128d tmp_1;
  captured_var_1_parallel_SST_m_T is_moving_grid;
  captured_var_parallel_SST_mod_T A;
  captured_var_parallel_SST_mod_T Cp;
  captured_var_parallel_SST_mod_T P;
  captured_var_parallel_SST_mod_T V_TC;
  captured_var_parallel_SST_mod_T V_tot;
  captured_var_parallel_SST_mod_T b_T_air;
  captured_var_parallel_SST_mod_T b_T_amb;
  captured_var_parallel_SST_mod_T b_T_duct;
  captured_var_parallel_SST_mod_T b_T_duct_0;
  captured_var_parallel_SST_mod_T b_T_duct_1;
  captured_var_parallel_SST_mod_T b_T_duct_2;
  captured_var_parallel_SST_mod_T b_U;
  captured_var_parallel_SST_mod_T b_eps;
  captured_var_parallel_SST_mod_T b_n;
  captured_var_parallel_SST_mod_T dx;
  captured_var_parallel_SST_mod_T rho;
  emxArray_real_T_parallel_SST__T y_2;
  emxArray_real_T_parallel_SST__T *a__1;
  emxArray_real_T_parallel_SST__T *tspan;
  emxArray_real_T_parallel_SST__T *x;
  emxArray_real_T_parallel_SST__T *y;
  emxArray_real_T_parallel_SST__T *y_;
  emxArray_real_T_parallel_SST__T *y_0;
  emxArray_real_T_parallel_SST__T *y_1;
  s_JrTEP38GMfv0hLhSLyVGj_paral_T expl_temp;
  real_T tmp[2];
  real_T tmp_2[2];
  real_T Clock_tmp;
  real_T V1_tmp;
  real_T V_var_;
  real_T m_DHW_stor;
  real_T m_bottom_;
  real_T m_bottom__tmp_tmp;
  real_T m_max;
  real_T rtb_T_1__f;
  real_T rtb_T_1__o;
  real_T rtb_T_2__d;
  real_T rtb_T_2__kw;
  real_T rtb_T_2__o;
  real_T rtb_T_3__ix;
  real_T rtb_T_3__p;
  real_T rtb_m_1__n;
  real_T rtb_m_2__f;
  real_T rtb_m_2__g;
  real_T rtb_m_2__o;
  real_T rtb_m_3__b;
  real_T rtb_m_3__c;
  real_T rtb_m_3__p;
  real_T rtb_m_DHW;
  real_T varargin_34;
  real_T varargin_36;
  int32_T loop_ub;
  int32_T loop_ub_0;
  int32_T nx;
  int32_T vectorUB;
  int32_T y_3;
  int32_T y_4;
  int32_T y_5;
  int32_T y_6;
  int32_T y_7;
  int32_T y_idx_0;
  int32_T y_idx_0_0;
  int32_T y_tmp;
  boolean_T loop;

  /* Sum: 'Sum' (':702') incorporates:
   *  Inport: 'm_DHW_recirc' (':1067')
   *  Inport: 'm_DHW_w' (':341')
   */
  rtb_m_DHW = parallel_SST_model_U.m_DHW_recirc + parallel_SST_model_U.m_DHW_w;

  /* Sum: 'Sum1' (':740') incorporates:
   *  Inport: 'm_DHW_sec' (':853')
   */
  m_DHW_stor = parallel_SST_model_U.m_DHW_sec - rtb_m_DHW;

  /* MATLAB Function: '3WV_function' (':903:1') incorporates:
   *  Constant: 'Constant1' (':779')
   *  Delay: 'Delay' (':899')
   *  Delay: 'Delay1' (':900')
   *  Inport: 'm_DHW_3V' (':349')
   *  Inport: 'm_DHW_dir' (':348')
   */
  parallel_SST_model_uWV_function(parallel_SST_model_U.m_DHW_dir,
    parallel_SST_model_DW.Delay_DSTATE, parallel_SST_model_U.m_DHW_3V,
    parallel_SST_model_DW.Delay1_DSTATE, 0.0, 0.0,
    parallel_SST_model_P.Constant1_Value, &rtb_m_1__n, &rtb_T_1__f, &rtb_m_2__g,
    &rtb_T_2__kw, &rtb_m_3__p, &rtb_T_3__ix,
    parallel_SST_model_P.DHWbypassvalve_unknown_T,
    parallel_SST_model_P.DHWbypassvalve_unknown_m);

  /* Outport: 'T_DHW_sec_in' (':432') incorporates:
   *  Delay: 'Delay6' (':890')
   */
  parallel_SST_model_Y.T_DHW_sec_in = parallel_SST_model_DW.Delay6_DSTATE;

  /* Outport: 'efficiency_DHW_HX' (':460') incorporates:
   *  Inport: 'm_DHW_sec' (':853')
   *  MATLAB Function: 'heat_exchanger_function' (':72:5')
   *  Outport: 'Q_DHW_HX' (':443')
   *  Outport: 'T_DHW_sec_in' (':432')
   */
  paralle_heat_exchanger_function(rtb_m_3__p, parallel_SST_model_U.m_DHW_sec,
    rtb_T_3__ix, parallel_SST_model_Y.T_DHW_sec_in,
    &parallel_SST_model_B.T_1_out, &rtb_T_2__kw, &parallel_SST_model_Y.Q_DHW_HX,
    &parallel_SST_model_Y.efficiency_DHW_HX,
    parallel_SST_model_P.DHWheatexchanger_A,
    parallel_SST_model_P.DHWheatexchanger_U);

  /* Outport: 'T_stor_n' (':440') incorporates:
   *  Delay: 'Delay5' (':889')
   */
  parallel_SST_model_Y.T_stor_n = parallel_SST_model_DW.Delay5_DSTATE;

  /* Abs: 'Abs' (':909') incorporates:
   *  Abs: 'Abs1' (':910')
   */
  rtb_m_2__f = fabs(m_DHW_stor);

  /* Switch: 'Switch3' (':870') incorporates:
   *  Outport: 'T_stor_n' (':440')
   */
  if (m_DHW_stor > parallel_SST_model_P.Switch3_Threshold)
  {
    V1_tmp = rtb_T_2__kw;
  }
  else
  {
    V1_tmp = parallel_SST_model_Y.T_stor_n;
  }

  /* Switch: 'Switch2' (':813') incorporates:
   *  Constant: 'Constant5' (':814')
   *  Constant: 'Constant6' (':815')
   */
  if (m_DHW_stor > parallel_SST_model_P.Switch2_Threshold)
  {
    m_bottom_ = parallel_SST_model_P.Constant5_Value;
  }
  else
  {
    m_bottom_ = parallel_SST_model_P.Constant6_Value;
  }

  /* MATLAB Function: '3WV_function' (':906:1') incorporates:
   *  Abs: 'Abs' (':909')
   *  Inport: 'm_DHW_sec' (':853')
   *  Switch: 'Switch2' (':813')
   *  Switch: 'Switch3' (':870')
   */
  parallel_SST_model_uWV_function(parallel_SST_model_U.m_DHW_sec, rtb_T_2__kw,
    rtb_m_2__f, V1_tmp, 0.0, 0.0, m_bottom_, &rtb_m_1__n, &rtb_T_1__f,
    &rtb_m_2__g, &rtb_T_2__d, &rtb_m_3__b, &rtb_T_3__p,
    parallel_SST_model_P.DHWstoragetopvalve_unknown_T,
    parallel_SST_model_P.DHWstoragetopvalve_unknown_m);

  /* Clock: 'Clock' (':70:540') incorporates:
   *  Clock: 'Clock' (':2:540')
   *  Clock: 'Clock' (':1:540')
   *  Clock: 'Clock' (':637:277')
   *  Clock: 'Clock' (':71:540')
   *  Clock: 'Clock' (':206:5')
   */
  Clock_tmp = parallel_SST_model_M->Timing.t[0];

  /* Clock: 'Clock' (':70:540') */
  parallel_SST_model_B.Clock = Clock_tmp;

  /* MATLAB Function: 'thermal_pipe_function' (':70:523') incorporates:
   *  Delay: 'Delay' (':70:541')
   *  Sum: 'Subtract' (':70:542')
   */
  rtb_T_2__d = rtb_m_DHW;
  rtb_m_3__b = parallel_SST_model_B.Clock - parallel_SST_model_DW.Delay_DSTATE_h;
  b_T_duct.contents = parallel_SST_model_P.DHWsupplypipe_T_duct;

  /* :  if isempty(k) */
  if (!parallel_SST_model_DW.k_not_empty_h)
  {
    /* :  e_pipe = 0.007; */
    /* :  D_ext = D + 2 * e_pipe; */
    /* :  if insulation_class == 1 */
    /* :  elseif insulation_class == 4 */
    /* :  k = 1.5 * D_ext + 0.16; */
    parallel_SST_model_DW.k_j = (parallel_SST_model_P.DHWsupplypipe_D + 0.014) *
      1.5 + 0.16;
    parallel_SST_model_DW.k_not_empty_h = true;

    /* :  Cp = 4180; */
    /* :  A = pi * D * D / 4; */
    parallel_SST_model_DW.A_i = 3.1415926535897931 *
      parallel_SST_model_P.DHWsupplypipe_D *
      parallel_SST_model_P.DHWsupplypipe_D / 4.0;

    /* :  rho = 1000; */
    /* :  oldStepSize = -1; */
    /* :  timeIdx = 1; */
    parallel_SST_model_DW.timeIdx_cc = 1.0;

    /* :  tau = (rho * A * Cp) / k; */
    parallel_SST_model_DW.tau_m.contents = 1000.0 * parallel_SST_model_DW.A_i *
      4180.0 / parallel_SST_model_DW.k_j;

    /* :  dt_ = 10; */
    /* :  V_min = m_min / (rho * A); */
    /* :  dx_ = V_min * dt_; */
    /* :  n_dx = floor(L / dx_); */
    parallel_SST_model_DW.n_dx_p.contents = floor
      (parallel_SST_model_P.DHWsupplypipe_L /
       (parallel_SST_model_P.DHWsupplypipe_m_min / (1000.0 *
         parallel_SST_model_DW.A_i) * 10.0));

    /* :  n_dx = max(n_dx, 1); */
    parallel_SST_model_DW.n_dx_p.contents = fmax
      (parallel_SST_model_DW.n_dx_p.contents, 1.0);

    /* :  dx = L / n_dx; */
    parallel_SST_model_DW.dx_g.contents = parallel_SST_model_P.DHWsupplypipe_L /
      parallel_SST_model_DW.n_dx_p.contents;

    /* :  T = ones(1, n_dx) * T_duct; */
    nx = parallel_SST_model_DW.T_k->size[0] * parallel_SST_model_DW.T_k->size[1];
    parallel_SST_model_DW.T_k->size[0] = 1;
    loop_ub = (int32_T)parallel_SST_model_DW.n_dx_p.contents;
    parallel_SST_model_DW.T_k->size[1] = (int32_T)
      parallel_SST_model_DW.n_dx_p.contents;
    parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_k, nx);
    for (y_idx_0 = 0; y_idx_0 < loop_ub; y_idx_0++)
    {
      parallel_SST_model_DW.T_k->data[y_idx_0] = 1.0;
    }

    nx = parallel_SST_model_DW.T_k->size[0] * parallel_SST_model_DW.T_k->size[1];
    parallel_SST_model_DW.T_k->size[0] = 1;
    parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_k, nx);
    loop_ub = parallel_SST_model_DW.T_k->size[1] - 1;
    nx = (parallel_SST_model_DW.T_k->size[1] / 2) << 1;
    vectorUB = nx - 2;
    for (y_idx_0 = 0; y_idx_0 <= vectorUB; y_idx_0 += 2)
    {
      tmp_1 = _mm_loadu_pd(&parallel_SST_model_DW.T_k->data[y_idx_0]);
      _mm_storeu_pd(&parallel_SST_model_DW.T_k->data[y_idx_0], _mm_mul_pd(tmp_1,
        _mm_set1_pd(parallel_SST_model_P.DHWsupplypipe_T_duct)));
    }

    for (y_idx_0 = nx; y_idx_0 <= loop_ub; y_idx_0++)
    {
      parallel_SST_model_DW.T_k->data[y_idx_0] *=
        parallel_SST_model_P.DHWsupplypipe_T_duct;
    }
  }
  else
  {
    /* :  else */
    /* :  timeIdx = timeIdx + 1; */
    parallel_SST_model_DW.timeIdx_cc++;
  }

  /* :  if timeIdx == 1 */
  if (parallel_SST_model_DW.timeIdx_cc == 1.0)
  {
    /* :  stepSize = 30; */
    rtb_m_3__b = 30.0;
  }

  /* :  dt = stepSize; */
  /* :  V_min = dx / dt; */
  /* :  m_min = V_min * rho * A; */
  rtb_T_1__o = parallel_SST_model_DW.dx_g.contents / rtb_m_3__b * 1000.0 *
    parallel_SST_model_DW.A_i;

  /* :  if m < 0 */
  if (rtb_m_DHW < 0.0)
  {
    /* :  fprintf("Thermal pipe: mass flow m=%1.2e kg/s < 0, it is replaced by zero.\n", m); */
    printf("Thermal pipe: mass flow m=%1.2e kg/s < 0, it is replaced by zero.\n",
           rtb_m_DHW);
    fflush(stdout);

    /* :  m = 0; */
    rtb_T_2__d = 0.0;
  }
  else if ((rtb_m_DHW > 0.0) && (rtb_m_DHW <= rtb_T_1__o))
  {
    /* :  elseif (0 < m) && (m <= m_min) */
    /* :  fprintf("Thermal pipe: mass flow m=%1.2e kg/s too small for the meshing (m_min value (for dt=%1.1fs): %1.2e kg/s), " + ... */
    /* :          "it is replaced by zero.\n", m, dt, m_min); */
    printf("Thermal pipe: mass flow m=%1.2e kg/s too small for the meshing (m_min value (for dt=%1.1fs): %1.2e kg/s), it is replaced by zero.\n",
           rtb_m_DHW, rtb_m_3__b, rtb_T_1__o);
    fflush(stdout);

    /* :  m = 0; */
    rtb_T_2__d = 0.0;
  }

  /* :  V = m / (rho * A); */
  /* :  t0 = 0; */
  /* :  tf = stepSize; */
  /* :  tspan = t0:tf; */
  parallel_SST_mod_emxInit_real_T(&tspan, 2);

  /* MATLAB Function: 'thermal_pipe_function' (':70:523') */
  if (rtIsNaN(rtb_m_3__b))
  {
    nx = tspan->size[0] * tspan->size[1];
    tspan->size[0] = 1;
    tspan->size[1] = 1;
    parall_emxEnsureCapacity_real_T(tspan, nx);
    tspan->data[0] = (rtNaN);
  }
  else if (rtb_m_3__b < 0.0)
  {
    tspan->size[0] = 1;
    tspan->size[1] = 0;
  }
  else
  {
    nx = tspan->size[0] * tspan->size[1];
    tspan->size[0] = 1;
    tspan->size[1] = (int32_T)rtb_m_3__b + 1;
    parall_emxEnsureCapacity_real_T(tspan, nx);
    loop_ub = (int32_T)rtb_m_3__b;
    for (y_idx_0 = 0; y_idx_0 <= loop_ub; y_idx_0++)
    {
      tspan->data[y_idx_0] = y_idx_0;
    }
  }

  /* :  options = odeset('RelTol',1e-3, 'AbsTol', 1e-3); */
  /* :  y0 = T; */
  /* :  [~,y] = ode23(@(t, y) ODE(t, y, V, T_in), tspan, y0, options); */
  parallel_SST_mod_emxInit_real_T(&a__1, 1);
  parallel_SST_mod_emxInit_real_T(&y, 2);

  /* MATLAB Function: 'thermal_pipe_function' (':70:523') */
  parallel_SST_model_ode23(&parallel_SST_model_DW.n_dx_p,
    &parallel_SST_model_DW.dx_g, &parallel_SST_model_DW.tau_m, &b_T_duct,
    rtb_T_2__d / (1000.0 * parallel_SST_model_DW.A_i), rtb_T_3__p, tspan,
    parallel_SST_model_DW.T_k, a__1, y);

  /* :  Q = k * L * (mean(y, "all") - T_duct); */
  y_idx_0 = y->size[0] * y->size[1];
  if (y_idx_0 == 0)
  {
    rtb_T_1__f = 0.0;
  }
  else if (y_idx_0 == 0)
  {
    rtb_T_1__f = 0.0;
  }
  else
  {
    y_2 = *y;
    y_3 = y_idx_0;
    y_2.size = &y_3;
    y_2.numDimensions = 1;
    rtb_T_1__f = parallel_SST_m_colMajorFlatIter(&y_2, y_idx_0);
  }

  /* :  T_out = mean(y(:, end)); */
  /* :  T = y(end, :); */
  y_tmp = y->size[0];
  nx = parallel_SST_model_DW.T_k->size[0] * parallel_SST_model_DW.T_k->size[1];
  parallel_SST_model_DW.T_k->size[0] = 1;
  loop_ub = y->size[1];
  parallel_SST_model_DW.T_k->size[1] = y->size[1];
  parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_k, nx);
  for (y_idx_0_0 = 0; y_idx_0_0 < loop_ub; y_idx_0_0++)
  {
    parallel_SST_model_DW.T_k->data[y_idx_0_0] = y->data[(y->size[0] * y_idx_0_0
      + y_tmp) - 1];
  }

  /* Clock: 'Clock' (':71:540') */
  parallel_SST_model_B.Clock_o = Clock_tmp;

  /* MATLAB Function: 'thermal_pipe_function' (':71:523') incorporates:
   *  Delay: 'Delay' (':71:541')
   *  Inport: 'm_DHW_recirc' (':1067')
   *  Sum: 'Subtract' (':71:542')
   */
  rtb_T_2__d = parallel_SST_model_U.m_DHW_recirc;
  rtb_m_3__b = parallel_SST_model_B.Clock_o -
    parallel_SST_model_DW.Delay_DSTATE_f;
  b_T_duct_0.contents = parallel_SST_model_P.DHWreturnpipe_T_duct;

  /* :  if isempty(k) */
  if (!parallel_SST_model_DW.k_not_empty_f)
  {
    /* :  e_pipe = 0.007; */
    /* :  D_ext = D + 2 * e_pipe; */
    /* :  if insulation_class == 1 */
    /* :  elseif insulation_class == 4 */
    /* :  k = 1.5 * D_ext + 0.16; */
    parallel_SST_model_DW.k_h = (parallel_SST_model_P.DHWreturnpipe_D + 0.014) *
      1.5 + 0.16;
    parallel_SST_model_DW.k_not_empty_f = true;

    /* :  Cp = 4180; */
    /* :  A = pi * D * D / 4; */
    parallel_SST_model_DW.A_j = 3.1415926535897931 *
      parallel_SST_model_P.DHWreturnpipe_D *
      parallel_SST_model_P.DHWreturnpipe_D / 4.0;

    /* :  rho = 1000; */
    /* :  oldStepSize = -1; */
    /* :  timeIdx = 1; */
    parallel_SST_model_DW.timeIdx_p = 1.0;

    /* :  tau = (rho * A * Cp) / k; */
    parallel_SST_model_DW.tau.contents = 1000.0 * parallel_SST_model_DW.A_j *
      4180.0 / parallel_SST_model_DW.k_h;

    /* :  dt_ = 10; */
    /* :  V_min = m_min / (rho * A); */
    /* :  dx_ = V_min * dt_; */
    /* :  n_dx = floor(L / dx_); */
    parallel_SST_model_DW.n_dx.contents = floor
      (parallel_SST_model_P.DHWreturnpipe_L /
       (parallel_SST_model_P.DHWreturnpipe_m_min / (1000.0 *
         parallel_SST_model_DW.A_j) * 10.0));

    /* :  n_dx = max(n_dx, 1); */
    parallel_SST_model_DW.n_dx.contents = fmax
      (parallel_SST_model_DW.n_dx.contents, 1.0);

    /* :  dx = L / n_dx; */
    parallel_SST_model_DW.dx.contents = parallel_SST_model_P.DHWreturnpipe_L /
      parallel_SST_model_DW.n_dx.contents;

    /* :  T = ones(1, n_dx) * T_duct; */
    nx = parallel_SST_model_DW.T_p->size[0] * parallel_SST_model_DW.T_p->size[1];
    parallel_SST_model_DW.T_p->size[0] = 1;
    loop_ub_0 = (int32_T)parallel_SST_model_DW.n_dx.contents;
    parallel_SST_model_DW.T_p->size[1] = (int32_T)
      parallel_SST_model_DW.n_dx.contents;
    parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_p, nx);
    for (y_idx_0_0 = 0; y_idx_0_0 < loop_ub_0; y_idx_0_0++)
    {
      parallel_SST_model_DW.T_p->data[y_idx_0_0] = 1.0;
    }

    nx = parallel_SST_model_DW.T_p->size[0] * parallel_SST_model_DW.T_p->size[1];
    parallel_SST_model_DW.T_p->size[0] = 1;
    parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_p, nx);
    loop_ub_0 = parallel_SST_model_DW.T_p->size[1] - 1;
    nx = (parallel_SST_model_DW.T_p->size[1] / 2) << 1;
    vectorUB = nx - 2;
    for (y_idx_0_0 = 0; y_idx_0_0 <= vectorUB; y_idx_0_0 += 2)
    {
      tmp_1 = _mm_loadu_pd(&parallel_SST_model_DW.T_p->data[y_idx_0_0]);
      _mm_storeu_pd(&parallel_SST_model_DW.T_p->data[y_idx_0_0], _mm_mul_pd
                    (tmp_1, _mm_set1_pd
                     (parallel_SST_model_P.DHWreturnpipe_T_duct)));
    }

    for (y_idx_0_0 = nx; y_idx_0_0 <= loop_ub_0; y_idx_0_0++)
    {
      parallel_SST_model_DW.T_p->data[y_idx_0_0] *=
        parallel_SST_model_P.DHWreturnpipe_T_duct;
    }
  }
  else
  {
    /* :  else */
    /* :  timeIdx = timeIdx + 1; */
    parallel_SST_model_DW.timeIdx_p++;
  }

  /* :  if timeIdx == 1 */
  if (parallel_SST_model_DW.timeIdx_p == 1.0)
  {
    /* :  stepSize = 30; */
    rtb_m_3__b = 30.0;
  }

  /* :  dt = stepSize; */
  /* :  V_min = dx / dt; */
  /* :  m_min = V_min * rho * A; */
  rtb_T_1__o = parallel_SST_model_DW.dx.contents / rtb_m_3__b * 1000.0 *
    parallel_SST_model_DW.A_j;

  /* :  if m < 0 */
  if (parallel_SST_model_U.m_DHW_recirc < 0.0)
  {
    /* :  fprintf("Thermal pipe: mass flow m=%1.2e kg/s < 0, it is replaced by zero.\n", m); */
    printf("Thermal pipe: mass flow m=%1.2e kg/s < 0, it is replaced by zero.\n",
           parallel_SST_model_U.m_DHW_recirc);
    fflush(stdout);

    /* :  m = 0; */
    rtb_T_2__d = 0.0;
  }
  else if ((parallel_SST_model_U.m_DHW_recirc > 0.0) &&
           (parallel_SST_model_U.m_DHW_recirc <= rtb_T_1__o))
  {
    /* :  elseif (0 < m) && (m <= m_min) */
    /* :  fprintf("Thermal pipe: mass flow m=%1.2e kg/s too small for the meshing (m_min value (for dt=%1.1fs): %1.2e kg/s), " + ... */
    /* :          "it is replaced by zero.\n", m, dt, m_min); */
    printf("Thermal pipe: mass flow m=%1.2e kg/s too small for the meshing (m_min value (for dt=%1.1fs): %1.2e kg/s), it is replaced by zero.\n",
           parallel_SST_model_U.m_DHW_recirc, rtb_m_3__b, rtb_T_1__o);
    fflush(stdout);

    /* :  m = 0; */
    rtb_T_2__d = 0.0;
  }

  /* :  V = m / (rho * A); */
  /* :  t0 = 0; */
  /* :  tf = stepSize; */
  /* :  tspan = t0:tf; */
  if (rtIsNaN(rtb_m_3__b))
  {
    nx = tspan->size[0] * tspan->size[1];
    tspan->size[0] = 1;
    tspan->size[1] = 1;
    parall_emxEnsureCapacity_real_T(tspan, nx);
    tspan->data[0] = (rtNaN);
  }
  else if (rtb_m_3__b < 0.0)
  {
    tspan->size[0] = 1;
    tspan->size[1] = 0;
  }
  else
  {
    nx = tspan->size[0] * tspan->size[1];
    tspan->size[0] = 1;
    tspan->size[1] = (int32_T)rtb_m_3__b + 1;
    parall_emxEnsureCapacity_real_T(tspan, nx);
    loop_ub_0 = (int32_T)rtb_m_3__b;
    for (y_idx_0_0 = 0; y_idx_0_0 <= loop_ub_0; y_idx_0_0++)
    {
      tspan->data[y_idx_0_0] = y_idx_0_0;
    }
  }

  /* :  options = odeset('RelTol',1e-3, 'AbsTol', 1e-3); */
  /* :  y0 = T; */
  /* :  [~,y] = ode23(@(t, y) ODE(t, y, V, T_in), tspan, y0, options); */
  parallel_SST_mod_emxInit_real_T(&y_1, 1);

  /* MATLAB Function: 'thermal_pipe_function' (':70:523') */
  nx = y_1->size[0];
  y_1->size[0] = y->size[0];
  parall_emxEnsureCapacity_real_T(y_1, nx);
  for (y_idx_0_0 = 0; y_idx_0_0 < y_tmp; y_idx_0_0++)
  {
    y_1->data[y_idx_0_0] = y->data[(loop_ub - 1) * y->size[0] + y_idx_0_0];
  }

  parallel_SST_mod_emxInit_real_T(&y_0, 2);

  /* MATLAB Function: 'thermal_pipe_function' (':71:523') incorporates:
   *  MATLAB Function: 'thermal_pipe_function' (':70:523')
   */
  parallel_SST_model_ode23(&parallel_SST_model_DW.n_dx,
    &parallel_SST_model_DW.dx, &parallel_SST_model_DW.tau, &b_T_duct_0,
    rtb_T_2__d / (1000.0 * parallel_SST_model_DW.A_j),
    parallel_SST_m_colMajorFlatIter(y_1, y->size[0]) / (real_T)y->size[0], tspan,
    parallel_SST_model_DW.T_p, a__1, y_0);

  /* :  Q = k * L * (mean(y, "all") - T_duct); */
  y_idx_0_0 = y_0->size[0] * y_0->size[1];
  if (y_idx_0_0 == 0)
  {
    rtb_m_2__g = 0.0;
  }
  else if (y_idx_0_0 == 0)
  {
    rtb_m_2__g = 0.0;
  }
  else
  {
    y_2 = *y_0;
    y_4 = y_idx_0_0;
    y_2.size = &y_4;
    y_2.numDimensions = 1;
    rtb_m_2__g = parallel_SST_m_colMajorFlatIter(&y_2, y_idx_0_0);
  }

  /* :  T_out = mean(y(:, end)); */
  y_tmp = y_0->size[1];
  loop_ub = y_0->size[0];
  nx = y_1->size[0];
  y_1->size[0] = y_0->size[0];
  parall_emxEnsureCapacity_real_T(y_1, nx);
  for (loop_ub_0 = 0; loop_ub_0 < loop_ub; loop_ub_0++)
  {
    y_1->data[loop_ub_0] = y_0->data[(y_tmp - 1) * y_0->size[0] + loop_ub_0];
  }

  rtb_T_2__d = parallel_SST_m_colMajorFlatIter(y_1, y_0->size[0]) / (real_T)
    y_0->size[0];

  /* :  T = y(end, :); */
  nx = parallel_SST_model_DW.T_p->size[0] * parallel_SST_model_DW.T_p->size[1];
  parallel_SST_model_DW.T_p->size[0] = 1;
  parallel_SST_model_DW.T_p->size[1] = y_0->size[1];
  parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_p, nx);
  for (loop_ub_0 = 0; loop_ub_0 < y_tmp; loop_ub_0++)
  {
    parallel_SST_model_DW.T_p->data[loop_ub_0] = y_0->data[(y_0->size[0] *
      loop_ub_0 + loop_ub) - 1];
  }

  /* MATLAB Function: '3WV_function' (':1075:1') incorporates:
   *  Constant: 'Constant7' (':1076')
   *  Inport: 'T_cold' (':347')
   *  Inport: 'm_DHW_recirc' (':1067')
   *  Inport: 'm_DHW_w' (':341')
   */
  parallel_SST_model_uWV_function(parallel_SST_model_U.m_DHW_recirc, rtb_T_2__d,
    parallel_SST_model_U.m_DHW_w, parallel_SST_model_U.T_cold, 0.0, 0.0,
    parallel_SST_model_P.Constant7_Value, &rtb_m_3__b, &rtb_T_1__o, &rtb_m_2__o,
    &rtb_T_2__o, &rtb_m_3__c, &rtb_m_1__n,
    parallel_SST_model_P.DHWcoldwaterrefill_unknown_T,
    parallel_SST_model_P.DHWcoldwaterrefill_unknown_m);

  /* Switch: 'Switch' (':225') */
  if (m_DHW_stor > parallel_SST_model_P.Switch_Threshold)
  {
    /* Switch: 'Switch' (':225') */
    rtb_T_1__o = rtb_T_2__kw;
  }
  else
  {
    /* Switch: 'Switch' (':225') */
    rtb_T_1__o = rtb_m_1__n;
  }

  /* End of Switch: 'Switch' (':225') */

  /* Clock: 'Clock' (':206:5') */
  parallel_SST_model_B.Clock_h = Clock_tmp;

  /* MATLAB Function: 'storage_TC_func' (':206:8') incorporates:
   *  Delay: 'Delay' (':206:6')
   *  Sum: 'Subtract' (':206:7')
   */
  rtb_m_2__o = m_DHW_stor;
  rtb_m_3__b = parallel_SST_model_B.Clock_h -
    parallel_SST_model_DW.Delay_DSTATE_l;
  b_n.contents = parallel_SST_model_P.DHWstorage_n;
  b_U.contents = parallel_SST_model_P.DHWstorage_U;
  b_eps.contents = parallel_SST_model_P.DHWstorage_eps;
  b_T_amb.contents = parallel_SST_model_P.DHWstorage_T_amb;

  /* :  assert(mod(n, 2)); */
  /* :  A = pi * (D ^ 2) / 4 ; */
  A.contents = parallel_SST_model_P.DHWstorage_D *
    parallel_SST_model_P.DHWstorage_D * 3.1415926535897931 / 4.0;

  /* :  P = pi * D; */
  P.contents = 3.1415926535897931 * parallel_SST_model_P.DHWstorage_D;

  /* :  V_tot = A * H; */
  rtb_T_2__o = A.contents * parallel_SST_model_P.DHWstorage_H;
  V_tot.contents = rtb_T_2__o;

  /* :  n_TC = n-2; */
  rtb_T_2__o = b_n.contents - 2.0;

  /* :  V_var_ = (V_var /100) * V_tot; */
  V_var_ = parallel_SST_model_P.DHWstorage_V_var / 100.0 * V_tot.contents;

  /* :  V_fixed = V_tot - V_var_; */
  rtb_m_3__c = V_tot.contents - V_var_;

  /* :  V_TC = V_fixed / n_TC; */
  V_TC.contents = rtb_m_3__c / rtb_T_2__o;

  /* :  dx = V_TC / A; */
  rtb_m_3__c = V_TC.contents / A.contents;
  dx.contents = rtb_m_3__c;

  /* :  V_min_ = (V_min / 100) * V_tot; */
  rtb_m_3__c = parallel_SST_model_P.DHWstorage_V_min / 100.0 * V_tot.contents;

  /* :  if isempty(V1) */
  if (!parallel_SST_model_DW.V1_not_empty)
  {
    /* :  V1 = V_var_/2; */
    V1_tmp = V_var_ / 2.0;
    parallel_SST_model_DW.V1 = V1_tmp;
    parallel_SST_model_DW.V1_not_empty = true;

    /* :  Vn = V_var_/2; */
    parallel_SST_model_DW.Vn = V1_tmp;

    /* :  T_init = [20, zeros(1, n_TC), 55]; */
    nx = parallel_SST_model_DW.T_init->size[0] *
      parallel_SST_model_DW.T_init->size[1];
    parallel_SST_model_DW.T_init->size[0] = 1;
    parallel_SST_model_DW.T_init->size[1] = (int32_T)rtb_T_2__o + 2;
    parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_init, nx);
    parallel_SST_model_DW.T_init->data[0] = 20.0;
    y_tmp = (int32_T)rtb_T_2__o;
    if ((int32_T)rtb_T_2__o - 1 >= 0)
    {
      memset(&parallel_SST_model_DW.T_init->data[1], 0, (uint32_T)(int32_T)
             rtb_T_2__o * sizeof(real_T));
    }

    parallel_SST_model_DW.T_init->data[(int32_T)rtb_T_2__o + 1] = 55.0;

    /* :  for idx=1:n_TC */
    for (loop_ub_0 = 0; loop_ub_0 < y_tmp; loop_ub_0++)
    {
      /* :  T_init(idx+1) = 20 + (idx/(n_TC+1)) * (55-20); */
      parallel_SST_model_DW.T_init->data[loop_ub_0 + 1] = ((real_T)loop_ub_0 +
        1.0) / (rtb_T_2__o + 1.0) * 35.0 + 20.0;
    }

    /* :  T_mid = T_init(fix(n/2)+1); */
    V_var_ = b_n.contents / 2.0;
    parallel_SST_model_DW.T_mid = parallel_SST_model_DW.T_init->data[(int32_T)
      (trunc(V_var_) + 1.0) - 1];

    /* :  T_avg = T_mid; */
    parallel_SST_model_DW.T_avg = parallel_SST_model_DW.T_mid;

    /* :  oldStepSize = -1; */
    /* :  timeIdx = 1; */
    parallel_SST_model_DW.timeIdx_f = 1.0;
  }
  else
  {
    /* :  else */
    /* :  timeIdx = timeIdx + 1; */
    parallel_SST_model_DW.timeIdx_f++;
  }

  /* :  if timeIdx == 1 */
  if (parallel_SST_model_DW.timeIdx_f == 1.0)
  {
    /* :  stepSize = 30; */
    rtb_m_3__b = 30.0;
  }

  /* :  t0 = 0; */
  /* :  tf = stepSize; */
  /* :  dt = tf - t0; */
  /* :  Cp = 4180; */
  Cp.contents = 4180.0;

  /* :  rho = 1000; */
  rho.contents = 1000.0;

  /* Outport: 'T_stor_out' (':448') incorporates:
   *  MATLAB Function: 'storage_TC_func' (':206:8')
   */
  /* :  T_out = 0; */
  parallel_SST_model_Y.T_stor_out = 0.0;

  /* Outport: 'T_stor_avg' (':449') incorporates:
   *  MATLAB Function: 'storage_TC_func' (':206:8')
   */
  /* :  T_avg_ = 0; */
  parallel_SST_model_Y.T_stor_avg = 0.0;

  /* Outport: 'T_stor_mid' (':450') incorporates:
   *  MATLAB Function: 'storage_TC_func' (':206:8')
   */
  /* :  T_mid_ = 0; */
  parallel_SST_model_Y.T_stor_mid = 0.0;

  /* Outport: 'T_stor_std' (':451') incorporates:
   *  MATLAB Function: 'storage_TC_func' (':206:8')
   */
  /* :  T_std_ = 0; */
  parallel_SST_model_Y.T_stor_std = 0.0;

  /* Outport: 'T_stor_half' (':452') incorporates:
   *  MATLAB Function: 'storage_TC_func' (':206:8')
   */
  /* :  T_half = 0; */
  parallel_SST_model_Y.T_stor_half = 0.0;

  /* Outport: 'T_stor_1' (':453') incorporates:
   *  MATLAB Function: 'storage_TC_func' (':206:8')
   */
  /* :  T1 = 0; */
  parallel_SST_model_Y.T_stor_1 = 0.0;

  /* MATLAB Function: 'storage_TC_func' (':206:8') */
  /* :  Tn = 0; */
  V_var_ = 0.0;

  /* :  loop = true; */
  loop = true;

  /* :  while loop */
  tmp[0] = 0.0;
  tmp[1] = rtb_m_3__b;
  V1_tmp = 0.5 * parallel_SST_model_P.DHWstorage_H;
  parallel_SST_mod_emxInit_real_T(&y_, 2);
  parallel_SST_mod_emxInit_real_T(&x, 1);

  /* MATLAB Function: 'storage_TC_func' (':206:8') */
  while (loop)
  {
    /* :  m_top_ = 0; */
    /* :  m_bottom_ = 0; */
    /* :  m_up = 0; */
    /* :  m_down = 0; */
    /* :  cond = m_top > 0; */
    loop = (rtb_m_2__o > 0.0);

    /* :  condA = (V1 <= V_min_ | T_mid < T_avg); */
    /* :  condB = (Vn <= V_min_ | T_mid > T_avg); */
    /* :  if cond */
    if (loop)
    {
      /* :  m_top_ = m_top; */
      V_var_ = rtb_m_2__o;

      /* :  m_bottom_  = 0; */
      m_bottom_ = 0.0;

      /* :  T_top  = T_in; */
      varargin_34 = rtb_T_1__o;

      /* :  T_bottom   = -10000; */
      varargin_36 = -10000.0;

      /* :  if condA */
      if ((parallel_SST_model_DW.V1 <= rtb_m_3__c) ||
          (parallel_SST_model_DW.T_mid < parallel_SST_model_DW.T_avg))
      {
        /* :  is_moving_grid = false; */
        is_moving_grid.contents = false;

        /* :  m_down  = m_top_; */
        m_max = rtb_m_2__o;

        /* :  m_up    = 0; */
        m_bottom__tmp_tmp = 0.0;

        /* :  m_top = 0; */
        rtb_m_2__o = 0.0;
      }
      else
      {
        /* :  else */
        /* :  is_moving_grid = true; */
        is_moving_grid.contents = true;

        /* :  m_max = V1*rho/dt; */
        m_max = parallel_SST_model_DW.V1 * rho.contents / rtb_m_3__b;

        /* :  if m_top_ > m_max */
        if (rtb_m_2__o > m_max)
        {
          /* :  m_top = m_top_ - 0.99 * m_max; */
          rtb_m_2__o -= 0.99 * m_max;

          /* :  fprintf("Storage tank: net flow m_top=%1.2e kg/s is too large for volume V1=%2.2f m3. ", m_top_, V1); */
          printf("Storage tank: net flow m_top=%1.2e kg/s is too large for volume V1=%2.2f m3. ",
                 V_var_, parallel_SST_model_DW.V1);
          fflush(stdout);

          /* :  m_top_ = 0.99 * m_max; */
          V_var_ = 0.99 * m_max;

          /* :  fprintf("Storage tank: the function will be called first with %1.2e kg/s and then with %1.2e kg/s.", m_top_, m_top); */
          printf("Storage tank: the function will be called first with %1.2e kg/s and then with %1.2e kg/s.",
                 V_var_, rtb_m_2__o);
          fflush(stdout);
        }
        else
        {
          /* :  else */
          /* :  m_top = 0; */
          rtb_m_2__o = 0.0;
        }

        /* :  m_down = 0; */
        m_max = 0.0;

        /* :  m_up = 0; */
        m_bottom__tmp_tmp = 0.0;
      }
    }
    else
    {
      /* :  else */
      /* :  m_top_ = 0; */
      V_var_ = 0.0;

      /* :  m_bottom_  = - m_top; */
      m_bottom__tmp_tmp = -rtb_m_2__o;
      m_bottom_ = -rtb_m_2__o;

      /* :  T_top = -10000; */
      varargin_34 = -10000.0;

      /* :  T_bottom = T_in; */
      varargin_36 = rtb_T_1__o;

      /* :  if condB */
      if ((parallel_SST_model_DW.Vn <= rtb_m_3__c) ||
          (parallel_SST_model_DW.T_mid > parallel_SST_model_DW.T_avg))
      {
        /* :  is_moving_grid = false; */
        is_moving_grid.contents = false;

        /* :  m_down  = 0; */
        m_max = 0.0;

        /* :  m_up    = m_bottom_; */
        m_bottom__tmp_tmp = -rtb_m_2__o;

        /* :  m_top = 0; */
        rtb_m_2__o = 0.0;
      }
      else
      {
        /* :  else */
        /* :  is_moving_grid = true; */
        is_moving_grid.contents = true;

        /* :  m_max = Vn*rho/dt; */
        m_max = parallel_SST_model_DW.Vn * rho.contents / rtb_m_3__b;

        /* :  if m_bottom_ > m_max */
        if (-rtb_m_2__o > m_max)
        {
          /* :  m_top = - (m_bottom_ - 0.99 * m_max); */
          rtb_m_2__o = -(-rtb_m_2__o - 0.99 * m_max);

          /* :  fprintf("Storage tank: net flow m_bottom=%1.2e kg/s is too large for volume Vn=%2.2f m3. ", m_bottom_, Vn); */
          printf("Storage tank: net flow m_bottom=%1.2e kg/s is too large for volume Vn=%2.2f m3. ",
                 m_bottom__tmp_tmp, parallel_SST_model_DW.Vn);
          fflush(stdout);

          /* :  m_bottom_ = 0.99 * m_max; */
          m_bottom_ = 0.99 * m_max;

          /* :  fprintf("Storage tank: the function will be called first with %1.2e kg/s and then with %1.2e kg/s.", m_bottom_, -m_top); */
          printf("Storage tank: the function will be called first with %1.2e kg/s and then with %1.2e kg/s.",
                 m_bottom_, -rtb_m_2__o);
          fflush(stdout);
        }
        else
        {
          /* :  else */
          /* :  m_top = 0; */
          rtb_m_2__o = 0.0;
        }

        /* :  m_down = 0; */
        m_max = 0.0;

        /* :  m_up = 0; */
        m_bottom__tmp_tmp = 0.0;
      }
    }

    /* :  tspan = [t0, tf]; */
    /* :  options = odeset('RelTol',1e-5, 'AbsTol', 1e-5); */
    /* :  y0 = [T_init'; V1]; */
    /* :  [~,y] = ode23(@(t, y) ODE(t, y, m_top_, m_bottom_, m_down, m_up, T_top, T_bottom), tspan, y0, options); */
    expl_temp.T_bottom = varargin_36;
    expl_temp.T_top = varargin_34;
    expl_temp.m_up = m_bottom__tmp_tmp;
    expl_temp.m_down = m_max;
    expl_temp.m_bottom_ = m_bottom_;
    expl_temp.m_top_ = V_var_;
    expl_temp.dx = &dx;
    expl_temp.eps = &b_eps;
    expl_temp.T_amb = &b_T_amb;
    expl_temp.A = &A;
    expl_temp.P = &P;
    expl_temp.U = &b_U;
    expl_temp.Cp = &Cp;
    expl_temp.V_TC = &V_TC;
    expl_temp.V_tot = &V_tot;
    expl_temp.rho = &rho;
    expl_temp.is_moving_grid = &is_moving_grid;
    expl_temp.n = &b_n;
    nx = y_1->size[0];
    y_1->size[0] = parallel_SST_model_DW.T_init->size[1] + 1;
    parall_emxEnsureCapacity_real_T(y_1, nx);
    loop_ub = parallel_SST_model_DW.T_init->size[1];
    if (loop_ub - 1 >= 0)
    {
      memcpy(&y_1->data[0], &parallel_SST_model_DW.T_init->data[0], (uint32_T)
             loop_ub * sizeof(real_T));
    }

    y_1->data[parallel_SST_model_DW.T_init->size[1]] = parallel_SST_model_DW.V1;
    parallel_SST_model_ode23_o(&expl_temp, tmp, y_1, a__1, y);

    /* :  y_ = zeros(n, 3); */
    y_tmp = (int32_T)b_n.contents;
    nx = y_->size[0] * y_->size[1];
    y_->size[0] = y_tmp;
    y_->size[1] = 3;
    parall_emxEnsureCapacity_real_T(y_, nx);
    loop_ub = (int32_T)b_n.contents * 3;
    if (loop_ub - 1 >= 0)
    {
      memset(&y_->data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
    }

    /* :  y_(:, 1) = y(end,1:n)'; */
    loop_ub = y->size[0];
    for (loop_ub_0 = 0; loop_ub_0 < y_tmp; loop_ub_0++)
    {
      y_->data[loop_ub_0] = y->data[(y->size[0] * loop_ub_0 + loop_ub) - 1];
    }

    /* :  V1 = y(end, n+1); */
    parallel_SST_model_DW.V1 = y->data[(((int32_T)(b_n.contents + 1.0) - 1) *
      y->size[0] + y->size[0]) - 1];

    /* :  Vn = V_tot - (V1 + (n-2) * V_TC); */
    parallel_SST_model_DW.Vn = V_tot.contents - ((b_n.contents - 2.0) *
      V_TC.contents + parallel_SST_model_DW.V1);

    /* :  y_(1,2) = V1; */
    y_->data[y_->size[0]] = parallel_SST_model_DW.V1;

    /* :  y_(n,2) = Vn; */
    loop_ub = (int32_T)b_n.contents - 1;
    y_->data[loop_ub + y_->size[0]] = parallel_SST_model_DW.Vn;

    /* :  y_(2:n-1,2) = V_TC; */
    V_var_ = b_n.contents - 1.0;
    if (V_var_ < 2.0)
    {
      nx = 0;
      loop_ub_0 = 0;
    }
    else
    {
      nx = 1;
      loop_ub_0 = (int32_T)V_var_;
    }

    vectorUB = loop_ub_0 - nx;
    for (loop_ub_0 = 0; loop_ub_0 < vectorUB; loop_ub_0++)
    {
      y_->data[(nx + loop_ub_0) + y_->size[0]] = V_TC.contents;
    }

    /* :  x1 = 0.5 * V1 / A; */
    y_->data[y_->size[0] << 1] = 0.5 * parallel_SST_model_DW.V1 / A.contents;

    /* :  xn = H - 0.5 * Vn / A; */
    y_->data[loop_ub + (y_->size[0] << 1)] = parallel_SST_model_P.DHWstorage_H -
      0.5 * parallel_SST_model_DW.Vn / A.contents;

    /* :  y_(1,3) = x1; */
    /* :  y_(n,3) = xn; */
    /* :  y_(2:n-1,3) = linspace(V1 / A + dx / 2, H - Vn/A - dx/2, n_TC); */
    if (V_var_ < 2.0)
    {
      nx = 0;
      loop_ub_0 = 0;
    }
    else
    {
      nx = 1;
      loop_ub_0 = (int32_T)V_var_;
    }

    V_var_ = dx.contents / 2.0;
    parallel_SST_model_linspace(parallel_SST_model_DW.V1 / A.contents + V_var_,
      (parallel_SST_model_P.DHWstorage_H - parallel_SST_model_DW.Vn / A.contents)
      - V_var_, rtb_T_2__o, tspan);
    vectorUB = loop_ub_0 - nx;
    for (loop_ub_0 = 0; loop_ub_0 < vectorUB; loop_ub_0++)
    {
      y_->data[(nx + loop_ub_0) + (y_->size[0] << 1)] = tspan->data[loop_ub_0];
    }

    /* :  T_avg = mean(y_(:, 1), Weights=y_(:, 2)); */
    nx = a__1->size[0];
    a__1->size[0] = y_tmp;
    parall_emxEnsureCapacity_real_T(a__1, nx);
    for (loop_ub_0 = 0; loop_ub_0 < y_tmp; loop_ub_0++)
    {
      a__1->data[loop_ub_0] = y_->data[loop_ub_0 + y_->size[0]];
    }

    if (y_->size[0] == a__1->size[0])
    {
      nx = x->size[0];
      x->size[0] = y_tmp;
      parall_emxEnsureCapacity_real_T(x, nx);
      nx = (y_tmp / 2) << 1;
      vectorUB = nx - 2;
      for (loop_ub_0 = 0; loop_ub_0 <= vectorUB; loop_ub_0 += 2)
      {
        tmp_1 = _mm_loadu_pd(&y_->data[loop_ub_0]);
        tmp_0 = _mm_loadu_pd(&a__1->data[loop_ub_0]);
        _mm_storeu_pd(&x->data[loop_ub_0], _mm_mul_pd(tmp_1, tmp_0));
      }

      for (loop_ub_0 = nx; loop_ub_0 < y_tmp; loop_ub_0++)
      {
        x->data[loop_ub_0] = y_->data[loop_ub_0] * a__1->data[loop_ub_0];
      }
    }
    else
    {
      parallel_SST_m_binary_expand_op(x, y_, a__1);
    }

    parallel_SST_model_DW.T_avg = parallel_SST_m_blockedSummation(x, x->size[0])
      / parallel_SST_m_blockedSummation(a__1, a__1->size[0]);

    /* :  T_mid = y_(fix(n/2)+1, 1); */
    V_var_ = b_n.contents / 2.0;
    parallel_SST_model_DW.T_mid = y_->data[(int32_T)(trunc(V_var_) + 1.0) - 1];

    /* :  T_init(:) = y_(:, 1); */
    y_tmp = parallel_SST_model_DW.T_init->size[1];
    nx = parallel_SST_model_DW.T_init->size[0] *
      parallel_SST_model_DW.T_init->size[1];
    parallel_SST_model_DW.T_init->size[0] = 1;
    parallel_SST_model_DW.T_init->size[1] = y_tmp;
    parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_init, nx);
    if (y_tmp - 1 >= 0)
    {
      memcpy(&parallel_SST_model_DW.T_init->data[0], &y_->data[0], (uint32_T)
             y_tmp * sizeof(real_T));
    }

    /* Outport: 'T_stor_1' (':453') */
    /* :  T1 = T_init(1); */
    parallel_SST_model_Y.T_stor_1 = parallel_SST_model_DW.T_init->data[0];

    /* :  Tn = T_init(n); */
    V_var_ = parallel_SST_model_DW.T_init->data[loop_ub];

    /* :  if cond */
    if (loop)
    {
      /* Outport: 'T_stor_out' (':448') */
      /* :  T_out =  T1; */
      parallel_SST_model_Y.T_stor_out = parallel_SST_model_DW.T_init->data[0];
    }
    else
    {
      /* Outport: 'T_stor_out' (':448') */
      /* :  else */
      /* :  T_out  = Tn; */
      parallel_SST_model_Y.T_stor_out = V_var_;
    }

    /* Outport: 'T_stor_avg' (':449') */
    /* :  T_avg_ = T_avg; */
    parallel_SST_model_Y.T_stor_avg = parallel_SST_model_DW.T_avg;

    /* Outport: 'T_stor_mid' (':450') */
    /* :  T_mid_ = T_mid; */
    parallel_SST_model_Y.T_stor_mid = parallel_SST_model_DW.T_mid;

    /* :  T_std_ = std(y_(:, 1), y_(:,2)); */
    loop_ub = y_->size[0];
    nx = a__1->size[0];
    a__1->size[0] = y_->size[0];
    parall_emxEnsureCapacity_real_T(a__1, nx);
    nx = y_1->size[0];
    y_1->size[0] = y_->size[0];
    parall_emxEnsureCapacity_real_T(y_1, nx);

    /* :  [~, idx_x_half] = min(abs(y_(:,3)-0.5*H)); */
    nx = x->size[0];
    x->size[0] = y_->size[0];
    parall_emxEnsureCapacity_real_T(x, nx);
    nx = (y_->size[0] / 2) << 1;
    vectorUB = nx - 2;
    for (loop_ub_0 = 0; loop_ub_0 <= vectorUB; loop_ub_0 += 2)
    {
      tmp_1 = _mm_loadu_pd(&y_->data[loop_ub_0]);
      _mm_storeu_pd(&a__1->data[loop_ub_0], tmp_1);
      tmp_1 = _mm_loadu_pd(&y_->data[loop_ub_0 + y_->size[0]]);
      _mm_storeu_pd(&y_1->data[loop_ub_0], tmp_1);
      tmp_1 = _mm_loadu_pd(&y_->data[(y_->size[0] << 1) + loop_ub_0]);
      _mm_storeu_pd(&x->data[loop_ub_0], _mm_sub_pd(tmp_1, _mm_set1_pd(V1_tmp)));
    }

    for (loop_ub_0 = nx; loop_ub_0 < loop_ub; loop_ub_0++)
    {
      a__1->data[loop_ub_0] = y_->data[loop_ub_0];
      y_1->data[loop_ub_0] = y_->data[loop_ub_0 + y_->size[0]];
      x->data[loop_ub_0] = y_->data[(y_->size[0] << 1) + loop_ub_0] - V1_tmp;
    }

    /* Outport: 'T_stor_std' (':451') */
    parallel_SST_model_Y.T_stor_std = parallel_SST_model_std(a__1, y_1);
    y_tmp = x->size[0];
    nx = a__1->size[0];
    a__1->size[0] = x->size[0];
    parall_emxEnsureCapacity_real_T(a__1, nx);
    for (loop_ub_0 = 0; loop_ub_0 < y_tmp; loop_ub_0++)
    {
      a__1->data[loop_ub_0] = fabs(x->data[loop_ub_0]);
    }

    parallel_SST_model_minimum(a__1, &m_bottom_, &nx);

    /* Outport: 'T_stor_half' (':452') */
    /* :  T_half = y_(idx_x_half,1); */
    parallel_SST_model_Y.T_stor_half = y_->data[nx - 1];

    /* :  loop = (m_top ~= 0); */
    loop = (rtb_m_2__o != 0.0);
  }

  parallel_SST_mod_emxFree_real_T(&x);
  parallel_SST_mod_emxFree_real_T(&y_);

  /* MATLAB Function: 'storage_TC_func' (':206:8') */
  /* :  T_all = T_init'; */
  parallel_SST_model_DW.SFunction_DIMS9 = parallel_SST_model_DW.T_init->size[1];
  parallel_SST_model_B.Tn = V_var_;

  /* Switch: 'Switch4' (':874') incorporates:
   *  Outport: 'T_stor_1' (':453')
   */
  if (m_DHW_stor > parallel_SST_model_P.Switch4_Threshold)
  {
    V1_tmp = parallel_SST_model_Y.T_stor_1;
  }
  else
  {
    V1_tmp = rtb_m_1__n;
  }

  /* Switch: 'Switch1' (':794') incorporates:
   *  Constant: 'Constant' (':795')
   *  Constant: 'Constant4' (':796')
   */
  if (m_DHW_stor > parallel_SST_model_P.Switch1_Threshold)
  {
    m_bottom_ = parallel_SST_model_P.Constant4_Value;
  }
  else
  {
    m_bottom_ = parallel_SST_model_P.Constant_Value;
  }

  /* MATLAB Function: '3WV_function' (':905:1') incorporates:
   *  Switch: 'Switch1' (':794')
   *  Switch: 'Switch4' (':874')
   */
  parallel_SST_model_uWV_function(rtb_m_DHW, rtb_m_1__n, rtb_m_2__f, V1_tmp, 0.0,
    0.0, m_bottom_, &rtb_m_3__b, &rtb_m_2__o, &rtb_T_2__o, &rtb_m_3__c, &V_var_,
    &parallel_SST_model_B.T_3_,
    parallel_SST_model_P.DHWstoragebottomvalve_unknown_T,
    parallel_SST_model_P.DHWstoragebottomvalve_unknown_m);

  /* Outport: 'T_stor_in' (':880') */
  parallel_SST_model_Y.T_stor_in = rtb_T_1__o;

  /* Outport: 'T_out' (':430') */
  parallel_SST_model_Y.T_out = rtb_m_1__n;

  /* Outport: 'T_DHW_out' (':429') */
  parallel_SST_model_Y.T_DHW_out = rtb_T_2__d;

  /* MATLAB Function: 'thermal_pipe_function' (':70:523') incorporates:
   *  MATLAB Function: 'thermal_pipe_function' (':71:523')
   */
  _mm_storeu_pd(&tmp_2[0], _mm_mul_pd(_mm_sub_pd(_mm_div_pd(_mm_set_pd
    (rtb_T_1__f, rtb_m_2__g), _mm_set_pd(y_idx_0, y_idx_0_0)), _mm_set_pd
    (parallel_SST_model_P.DHWsupplypipe_T_duct,
     parallel_SST_model_P.DHWreturnpipe_T_duct)), _mm_mul_pd(_mm_set_pd
    (parallel_SST_model_DW.k_j, parallel_SST_model_DW.k_h), _mm_set_pd
    (parallel_SST_model_P.DHWsupplypipe_L, parallel_SST_model_P.DHWreturnpipe_L))));

  /* Outport: 'Q_DHW_return' (':458') */
  parallel_SST_model_Y.Q_DHW_return = tmp_2[0];

  /* Outport: 'Q_DHW_supply' (':457') */
  parallel_SST_model_Y.Q_DHW_supply = tmp_2[1];

  /* Outport: 'T_DHW_in' (':607') */
  parallel_SST_model_Y.T_DHW_in = rtb_T_3__p;

  /* Outport: 'T_DHW_sec_out' (':431') */
  parallel_SST_model_Y.T_DHW_sec_out = rtb_T_2__kw;

  /* Outport: 'T_DHW_prim_out' (':434') */
  parallel_SST_model_Y.T_DHW_prim_out = parallel_SST_model_B.T_1_out;

  /* MATLAB Function: '3WV_function' (':907:1') incorporates:
   *  Constant: 'Constant2' (':766')
   *  Delay: 'Delay2' (':894')
   *  Delay: 'Delay7' (':896')
   *  Inport: 'm_SH_3V' (':344')
   *  Inport: 'm_SH_dir' (':340')
   */
  parallel_SST_model_uWV_function(parallel_SST_model_U.m_SH_dir,
    parallel_SST_model_DW.Delay2_DSTATE, parallel_SST_model_U.m_SH_3V,
    parallel_SST_model_DW.Delay7_DSTATE, 0.0, 0.0,
    parallel_SST_model_P.Constant2_Value, &rtb_T_1__f, &rtb_m_2__g, &rtb_m_2__f,
    &rtb_T_3__p, &rtb_T_2__kw, &rtb_m_1__n,
    parallel_SST_model_P.SHbypassvalve_unknown_T,
    parallel_SST_model_P.SHbypassvalve_unknown_m);

  /* Clock: 'Clock' (':1:540') */
  parallel_SST_model_B.Clock_c = Clock_tmp;

  /* MATLAB Function: 'thermal_pipe_function' (':1:523') incorporates:
   *  Delay: 'Delay' (':1:541')
   *  Sum: 'Subtract' (':1:542')
   */
  rtb_T_2__d = rtb_T_2__kw;
  rtb_m_3__b = parallel_SST_model_B.Clock_c -
    parallel_SST_model_DW.Delay_DSTATE_o;
  b_T_duct_1.contents = parallel_SST_model_P.SHsupplypipe_T_duct;

  /* :  if isempty(k) */
  if (!parallel_SST_model_DW.k_not_empty)
  {
    /* :  e_pipe = 0.007; */
    /* :  D_ext = D + 2 * e_pipe; */
    /* :  if insulation_class == 1 */
    /* :  elseif insulation_class == 4 */
    /* :  k = 1.5 * D_ext + 0.16; */
    parallel_SST_model_DW.k = (parallel_SST_model_P.SHsupplypipe_D + 0.014) *
      1.5 + 0.16;
    parallel_SST_model_DW.k_not_empty = true;

    /* :  Cp = 4180; */
    /* :  A = pi * D * D / 4; */
    parallel_SST_model_DW.A_b = 3.1415926535897931 *
      parallel_SST_model_P.SHsupplypipe_D * parallel_SST_model_P.SHsupplypipe_D /
      4.0;

    /* :  rho = 1000; */
    /* :  oldStepSize = -1; */
    /* :  timeIdx = 1; */
    parallel_SST_model_DW.timeIdx_c = 1.0;

    /* :  tau = (rho * A * Cp) / k; */
    parallel_SST_model_DW.tau_h4.contents = 1000.0 * parallel_SST_model_DW.A_b *
      4180.0 / parallel_SST_model_DW.k;

    /* :  dt_ = 10; */
    /* :  V_min = m_min / (rho * A); */
    /* :  dx_ = V_min * dt_; */
    /* :  n_dx = floor(L / dx_); */
    parallel_SST_model_DW.n_dx_l.contents = floor
      (parallel_SST_model_P.SHsupplypipe_L /
       (parallel_SST_model_P.SHsupplypipe_m_min / (1000.0 *
         parallel_SST_model_DW.A_b) * 10.0));

    /* :  n_dx = max(n_dx, 1); */
    parallel_SST_model_DW.n_dx_l.contents = fmax
      (parallel_SST_model_DW.n_dx_l.contents, 1.0);

    /* :  dx = L / n_dx; */
    parallel_SST_model_DW.dx_ij.contents = parallel_SST_model_P.SHsupplypipe_L /
      parallel_SST_model_DW.n_dx_l.contents;

    /* :  T = ones(1, n_dx) * T_duct; */
    nx = parallel_SST_model_DW.T_m->size[0] * parallel_SST_model_DW.T_m->size[1];
    parallel_SST_model_DW.T_m->size[0] = 1;
    loop_ub = (int32_T)parallel_SST_model_DW.n_dx_l.contents;
    parallel_SST_model_DW.T_m->size[1] = (int32_T)
      parallel_SST_model_DW.n_dx_l.contents;
    parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_m, nx);
    for (y_idx_0 = 0; y_idx_0 < loop_ub; y_idx_0++)
    {
      parallel_SST_model_DW.T_m->data[y_idx_0] = 1.0;
    }

    nx = parallel_SST_model_DW.T_m->size[0] * parallel_SST_model_DW.T_m->size[1];
    parallel_SST_model_DW.T_m->size[0] = 1;
    parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_m, nx);
    loop_ub = parallel_SST_model_DW.T_m->size[1] - 1;
    nx = (parallel_SST_model_DW.T_m->size[1] / 2) << 1;
    vectorUB = nx - 2;
    for (y_idx_0 = 0; y_idx_0 <= vectorUB; y_idx_0 += 2)
    {
      tmp_1 = _mm_loadu_pd(&parallel_SST_model_DW.T_m->data[y_idx_0]);
      _mm_storeu_pd(&parallel_SST_model_DW.T_m->data[y_idx_0], _mm_mul_pd(tmp_1,
        _mm_set1_pd(parallel_SST_model_P.SHsupplypipe_T_duct)));
    }

    for (y_idx_0 = nx; y_idx_0 <= loop_ub; y_idx_0++)
    {
      parallel_SST_model_DW.T_m->data[y_idx_0] *=
        parallel_SST_model_P.SHsupplypipe_T_duct;
    }
  }
  else
  {
    /* :  else */
    /* :  timeIdx = timeIdx + 1; */
    parallel_SST_model_DW.timeIdx_c++;
  }

  /* :  if timeIdx == 1 */
  if (parallel_SST_model_DW.timeIdx_c == 1.0)
  {
    /* :  stepSize = 30; */
    rtb_m_3__b = 30.0;
  }

  /* :  dt = stepSize; */
  /* :  V_min = dx / dt; */
  /* :  m_min = V_min * rho * A; */
  rtb_T_1__o = parallel_SST_model_DW.dx_ij.contents / rtb_m_3__b * 1000.0 *
    parallel_SST_model_DW.A_b;

  /* :  if m < 0 */
  if (rtb_T_2__kw < 0.0)
  {
    /* :  fprintf("Thermal pipe: mass flow m=%1.2e kg/s < 0, it is replaced by zero.\n", m); */
    printf("Thermal pipe: mass flow m=%1.2e kg/s < 0, it is replaced by zero.\n",
           rtb_T_2__kw);
    fflush(stdout);

    /* :  m = 0; */
    rtb_T_2__d = 0.0;
  }
  else if ((rtb_T_2__kw > 0.0) && (rtb_T_2__kw <= rtb_T_1__o))
  {
    /* :  elseif (0 < m) && (m <= m_min) */
    /* :  fprintf("Thermal pipe: mass flow m=%1.2e kg/s too small for the meshing (m_min value (for dt=%1.1fs): %1.2e kg/s), " + ... */
    /* :          "it is replaced by zero.\n", m, dt, m_min); */
    printf("Thermal pipe: mass flow m=%1.2e kg/s too small for the meshing (m_min value (for dt=%1.1fs): %1.2e kg/s), it is replaced by zero.\n",
           rtb_T_2__kw, rtb_m_3__b, rtb_T_1__o);
    fflush(stdout);

    /* :  m = 0; */
    rtb_T_2__d = 0.0;
  }

  /* :  V = m / (rho * A); */
  /* :  t0 = 0; */
  /* :  tf = stepSize; */
  /* :  tspan = t0:tf; */
  if (rtIsNaN(rtb_m_3__b))
  {
    nx = tspan->size[0] * tspan->size[1];
    tspan->size[0] = 1;
    tspan->size[1] = 1;
    parall_emxEnsureCapacity_real_T(tspan, nx);
    tspan->data[0] = (rtNaN);
  }
  else if (rtb_m_3__b < 0.0)
  {
    tspan->size[0] = 1;
    tspan->size[1] = 0;
  }
  else
  {
    nx = tspan->size[0] * tspan->size[1];
    tspan->size[0] = 1;
    tspan->size[1] = (int32_T)rtb_m_3__b + 1;
    parall_emxEnsureCapacity_real_T(tspan, nx);
    loop_ub = (int32_T)rtb_m_3__b;
    for (y_idx_0 = 0; y_idx_0 <= loop_ub; y_idx_0++)
    {
      tspan->data[y_idx_0] = y_idx_0;
    }
  }

  /* :  options = odeset('RelTol',1e-3, 'AbsTol', 1e-3); */
  /* :  y0 = T; */
  /* :  [~,y] = ode23(@(t, y) ODE(t, y, V, T_in), tspan, y0, options); */
  parallel_SST_model_ode23(&parallel_SST_model_DW.n_dx_l,
    &parallel_SST_model_DW.dx_ij, &parallel_SST_model_DW.tau_h4, &b_T_duct_1,
    rtb_T_2__d / (1000.0 * parallel_SST_model_DW.A_b), rtb_m_1__n, tspan,
    parallel_SST_model_DW.T_m, a__1, y);

  /* :  Q = k * L * (mean(y, "all") - T_duct); */
  y_idx_0 = y->size[0] * y->size[1];
  if (y_idx_0 == 0)
  {
    rtb_T_1__f = 0.0;
  }
  else if (y_idx_0 == 0)
  {
    rtb_T_1__f = 0.0;
  }
  else
  {
    y_2 = *y;
    y_5 = y_idx_0;
    y_2.size = &y_5;
    y_2.numDimensions = 1;
    rtb_T_1__f = parallel_SST_m_colMajorFlatIter(&y_2, y_idx_0);
  }

  /* :  T_out = mean(y(:, end)); */
  y_tmp = y->size[1];
  loop_ub = y->size[0];
  nx = y_1->size[0];
  y_1->size[0] = y->size[0];
  parall_emxEnsureCapacity_real_T(y_1, nx);
  for (y_idx_0_0 = 0; y_idx_0_0 < loop_ub; y_idx_0_0++)
  {
    y_1->data[y_idx_0_0] = y->data[(y_tmp - 1) * y->size[0] + y_idx_0_0];
  }

  rtb_m_2__f = parallel_SST_m_colMajorFlatIter(y_1, y->size[0]) / (real_T)
    y->size[0];

  /* :  T = y(end, :); */
  nx = parallel_SST_model_DW.T_m->size[0] * parallel_SST_model_DW.T_m->size[1];
  parallel_SST_model_DW.T_m->size[0] = 1;
  parallel_SST_model_DW.T_m->size[1] = y->size[1];
  parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_m, nx);
  for (y_idx_0_0 = 0; y_idx_0_0 < y_tmp; y_idx_0_0++)
  {
    parallel_SST_model_DW.T_m->data[y_idx_0_0] = y->data[(y->size[0] * y_idx_0_0
      + loop_ub) - 1];
  }

  /* Clock: 'Clock' (':637:277') */
  parallel_SST_model_B.Clock_hf = Clock_tmp;

  /* MATLAB Function: 'thermal_emitters_function' (':637:65') incorporates:
   *  Delay: 'Delay' (':637:278')
   *  Sum: 'Subtract' (':637:279')
   */
  rtb_T_2__d = rtb_T_2__kw;
  rtb_m_3__b = parallel_SST_model_B.Clock_hf -
    parallel_SST_model_DW.Delay_DSTATE_i;
  b_T_air.contents = parallel_SST_model_P.SHthermalemitters_T_air;

  /* :  if isempty(tau) */
  if (!parallel_SST_model_DW.tau_not_empty)
  {
    /* :  Cp = 4180; */
    /* :  rho = 1000; */
    /* :  A = pi * D * D / 4; */
    parallel_SST_model_DW.A = 3.1415926535897931 *
      parallel_SST_model_P.SHthermalemitters_D *
      parallel_SST_model_P.SHthermalemitters_D / 4.0;

    /* :  oldStepSize = -1; */
    /* :  timeIdx = 1; */
    parallel_SST_model_DW.timeIdx = 1.0;

    /* :  tau = rho*D*Cp / (4*U); */
    parallel_SST_model_DW.tau_not_empty = true;
    parallel_SST_model_DW.tau_n.contents = 1000.0 *
      parallel_SST_model_P.SHthermalemitters_D * 4180.0 / (4.0 *
      parallel_SST_model_P.SHthermalemitters_U);

    /* :  dt_ = 10; */
    /* :  V_min_tube = (m_min / (rho * A)) / (n_tubes * n_radiators); */
    /* :  dx_ = V_min_tube * dt_; */
    /* :  n_dx = floor(L / dx_); */
    parallel_SST_model_DW.n_dx_jn.contents = floor
      (parallel_SST_model_P.SHthermalemitters_L /
       (parallel_SST_model_P.SHthermalemitters_m_min / (1000.0 *
         parallel_SST_model_DW.A) /
        (parallel_SST_model_P.SHthermalemitters_n_tubes *
         parallel_SST_model_P.SHthermalemitters_n_radiators) * 10.0));

    /* :  n_dx = max(n_dx, 1); */
    parallel_SST_model_DW.n_dx_jn.contents = fmax
      (parallel_SST_model_DW.n_dx_jn.contents, 1.0);

    /* :  dx = L / n_dx; */
    parallel_SST_model_DW.dx_k.contents =
      parallel_SST_model_P.SHthermalemitters_L /
      parallel_SST_model_DW.n_dx_jn.contents;

    /* :  T = ones(1, n_dx) * T_air; */
    nx = parallel_SST_model_DW.T->size[0] * parallel_SST_model_DW.T->size[1];
    parallel_SST_model_DW.T->size[0] = 1;
    loop_ub = (int32_T)parallel_SST_model_DW.n_dx_jn.contents;
    parallel_SST_model_DW.T->size[1] = (int32_T)
      parallel_SST_model_DW.n_dx_jn.contents;
    parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T, nx);
    for (y_idx_0_0 = 0; y_idx_0_0 < loop_ub; y_idx_0_0++)
    {
      parallel_SST_model_DW.T->data[y_idx_0_0] = 1.0;
    }

    nx = parallel_SST_model_DW.T->size[0] * parallel_SST_model_DW.T->size[1];
    parallel_SST_model_DW.T->size[0] = 1;
    parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T, nx);
    loop_ub = parallel_SST_model_DW.T->size[1] - 1;
    nx = (parallel_SST_model_DW.T->size[1] / 2) << 1;
    vectorUB = nx - 2;
    for (y_idx_0_0 = 0; y_idx_0_0 <= vectorUB; y_idx_0_0 += 2)
    {
      tmp_1 = _mm_loadu_pd(&parallel_SST_model_DW.T->data[y_idx_0_0]);
      _mm_storeu_pd(&parallel_SST_model_DW.T->data[y_idx_0_0], _mm_mul_pd(tmp_1,
        _mm_set1_pd(parallel_SST_model_P.SHthermalemitters_T_air)));
    }

    for (y_idx_0_0 = nx; y_idx_0_0 <= loop_ub; y_idx_0_0++)
    {
      parallel_SST_model_DW.T->data[y_idx_0_0] *=
        parallel_SST_model_P.SHthermalemitters_T_air;
    }

    /* :  fprintf("Thermal emitters: meshing created %d nodes.\n", int32(n_dx)); */
    if (parallel_SST_model_DW.n_dx_jn.contents < 2.147483648E+9)
    {
      y_idx_0_0 = (int32_T)parallel_SST_model_DW.n_dx_jn.contents;
    }
    else
    {
      y_idx_0_0 = MAX_int32_T;
    }

    printf("Thermal emitters: meshing created %d nodes.\n", y_idx_0_0);
    fflush(stdout);
  }
  else
  {
    /* :  else */
    /* :  timeIdx = timeIdx + 1; */
    parallel_SST_model_DW.timeIdx++;
  }

  /* :  if timeIdx == 1 */
  if (parallel_SST_model_DW.timeIdx == 1.0)
  {
    /* :  stepSize = 30; */
    rtb_m_3__b = 30.0;
  }

  /* :  dt = stepSize; */
  /* :  V_min_tube = dx / dt; */
  /* :  m_min = V_min_tube * n_tubes * n_radiators * rho * A; */
  rtb_T_1__o = parallel_SST_model_DW.dx_k.contents / rtb_m_3__b *
    parallel_SST_model_P.SHthermalemitters_n_tubes *
    parallel_SST_model_P.SHthermalemitters_n_radiators * 1000.0 *
    parallel_SST_model_DW.A;

  /* :  if timeIdx == 3 */
  if (parallel_SST_model_DW.timeIdx == 3.0)
  {
    /* :  fprintf("Thermal emitters: m_min=%1.2e kg/s (for dt=%1.1fs).\n", m_min, dt); */
    printf("Thermal emitters: m_min=%1.2e kg/s (for dt=%1.1fs).\n", rtb_T_1__o,
           rtb_m_3__b);
    fflush(stdout);
  }

  /* :  if m < 0 */
  if (rtb_T_2__kw < 0.0)
  {
    /* :  fprintf("Thermal emitters: mass flow m=%1.2e kg/s < 0, it is replaced by zero.\n", m); */
    printf("Thermal emitters: mass flow m=%1.2e kg/s < 0, it is replaced by zero.\n",
           rtb_T_2__kw);
    fflush(stdout);

    /* :  m = 0; */
    rtb_T_2__d = 0.0;
  }
  else if ((rtb_T_2__kw > 0.0) && (rtb_T_2__kw <= rtb_T_1__o))
  {
    /* :  elseif (0 < m) && (m <= m_min) */
    /* :  fprintf("Thermal emitters: mass flow m=%1.2e kg/s too small for the meshing (m_min value (for dt=%1.1fs): %1.2e kg/s), " + ... */
    /* :          "it is replaced by zero.\n", m, dt, m_min); */
    printf("Thermal emitters: mass flow m=%1.2e kg/s too small for the meshing (m_min value (for dt=%1.1fs): %1.2e kg/s), it is replaced by zero.\n",
           rtb_T_2__kw, rtb_m_3__b, rtb_T_1__o);
    fflush(stdout);

    /* :  m = 0; */
    rtb_T_2__d = 0.0;
  }

  /* :  V = m / (rho * A * n_tubes * n_radiators); */
  /* :  t0 = 0; */
  /* :  tf = dt; */
  /* :  tspan = t0:tf; */
  if (rtIsNaN(rtb_m_3__b))
  {
    nx = tspan->size[0] * tspan->size[1];
    tspan->size[0] = 1;
    tspan->size[1] = 1;
    parall_emxEnsureCapacity_real_T(tspan, nx);
    tspan->data[0] = (rtNaN);
  }
  else if (rtb_m_3__b < 0.0)
  {
    tspan->size[0] = 1;
    tspan->size[1] = 0;
  }
  else
  {
    nx = tspan->size[0] * tspan->size[1];
    tspan->size[0] = 1;
    tspan->size[1] = (int32_T)rtb_m_3__b + 1;
    parall_emxEnsureCapacity_real_T(tspan, nx);
    loop_ub = (int32_T)rtb_m_3__b;
    for (y_idx_0_0 = 0; y_idx_0_0 <= loop_ub; y_idx_0_0++)
    {
      tspan->data[y_idx_0_0] = y_idx_0_0;
    }
  }

  /* :  options = odeset('RelTol',1e-3, 'AbsTol', 1e-3); */
  /* :  y0 = T; */
  /* :  [~,y] = ode23(@(t, y) ODE(t, y, V, T_in), tspan, y0, options); */
  parallel_SST_model_ode23(&parallel_SST_model_DW.n_dx_jn,
    &parallel_SST_model_DW.dx_k, &parallel_SST_model_DW.tau_n, &b_T_air,
    rtb_T_2__d / (1000.0 * parallel_SST_model_DW.A *
                  parallel_SST_model_P.SHthermalemitters_n_tubes *
                  parallel_SST_model_P.SHthermalemitters_n_radiators),
    rtb_m_2__f, tspan, parallel_SST_model_DW.T, a__1, y_0);

  /* :  Q = n_radiators * n_tubes * U * pi * D * L * (mean(y, "all") - T_air); */
  y_idx_0_0 = y_0->size[0] * y_0->size[1];
  if (y_idx_0_0 == 0)
  {
    rtb_m_2__g = 0.0;
  }
  else if (y_idx_0_0 == 0)
  {
    rtb_m_2__g = 0.0;
  }
  else
  {
    y_2 = *y_0;
    y_6 = y_idx_0_0;
    y_2.size = &y_6;
    y_2.numDimensions = 1;
    rtb_m_2__g = parallel_SST_m_colMajorFlatIter(&y_2, y_idx_0_0);
  }

  /* :  T_out = mean(y(:, end)); */
  y_tmp = y_0->size[1];
  loop_ub = y_0->size[0];
  nx = y_1->size[0];
  y_1->size[0] = y_0->size[0];
  parall_emxEnsureCapacity_real_T(y_1, nx);
  for (loop_ub_0 = 0; loop_ub_0 < loop_ub; loop_ub_0++)
  {
    y_1->data[loop_ub_0] = y_0->data[(y_tmp - 1) * y_0->size[0] + loop_ub_0];
  }

  rtb_T_3__p = parallel_SST_m_colMajorFlatIter(y_1, y_0->size[0]) / (real_T)
    y_0->size[0];

  /* :  T = y(end, :); */
  nx = parallel_SST_model_DW.T->size[0] * parallel_SST_model_DW.T->size[1];
  parallel_SST_model_DW.T->size[0] = 1;
  parallel_SST_model_DW.T->size[1] = y_0->size[1];
  parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T, nx);
  for (loop_ub_0 = 0; loop_ub_0 < y_tmp; loop_ub_0++)
  {
    parallel_SST_model_DW.T->data[loop_ub_0] = y_0->data[(y_0->size[0] *
      loop_ub_0 + loop_ub) - 1];
  }

  parallel_SST_mod_emxFree_real_T(&y_0);

  /* Clock: 'Clock' (':2:540') */
  parallel_SST_model_B.Clock_b = Clock_tmp;

  /* MATLAB Function: 'thermal_pipe_function' (':2:523') incorporates:
   *  Delay: 'Delay' (':2:541')
   *  Sum: 'Subtract' (':2:542')
   */
  rtb_T_2__d = rtb_T_2__kw;
  rtb_m_3__b = parallel_SST_model_B.Clock_b -
    parallel_SST_model_DW.Delay_DSTATE_m;
  b_T_duct_2.contents = parallel_SST_model_P.SHreturnpipe_T_duct;

  /* :  if isempty(k) */
  if (!parallel_SST_model_DW.k_not_empty_b)
  {
    /* :  e_pipe = 0.007; */
    /* :  D_ext = D + 2 * e_pipe; */
    /* :  if insulation_class == 1 */
    /* :  elseif insulation_class == 4 */
    /* :  k = 1.5 * D_ext + 0.16; */
    parallel_SST_model_DW.k_o = (parallel_SST_model_P.SHreturnpipe_D + 0.014) *
      1.5 + 0.16;
    parallel_SST_model_DW.k_not_empty_b = true;

    /* :  Cp = 4180; */
    /* :  A = pi * D * D / 4; */
    parallel_SST_model_DW.A_k = 3.1415926535897931 *
      parallel_SST_model_P.SHreturnpipe_D * parallel_SST_model_P.SHreturnpipe_D /
      4.0;

    /* :  rho = 1000; */
    /* :  oldStepSize = -1; */
    /* :  timeIdx = 1; */
    parallel_SST_model_DW.timeIdx_m = 1.0;

    /* :  tau = (rho * A * Cp) / k; */
    parallel_SST_model_DW.tau_h.contents = 1000.0 * parallel_SST_model_DW.A_k *
      4180.0 / parallel_SST_model_DW.k_o;

    /* :  dt_ = 10; */
    /* :  V_min = m_min / (rho * A); */
    /* :  dx_ = V_min * dt_; */
    /* :  n_dx = floor(L / dx_); */
    parallel_SST_model_DW.n_dx_j.contents = floor
      (parallel_SST_model_P.SHreturnpipe_L /
       (parallel_SST_model_P.SHreturnpipe_m_min / (1000.0 *
         parallel_SST_model_DW.A_k) * 10.0));

    /* :  n_dx = max(n_dx, 1); */
    parallel_SST_model_DW.n_dx_j.contents = fmax
      (parallel_SST_model_DW.n_dx_j.contents, 1.0);

    /* :  dx = L / n_dx; */
    parallel_SST_model_DW.dx_i.contents = parallel_SST_model_P.SHreturnpipe_L /
      parallel_SST_model_DW.n_dx_j.contents;

    /* :  T = ones(1, n_dx) * T_duct; */
    nx = parallel_SST_model_DW.T_o->size[0] * parallel_SST_model_DW.T_o->size[1];
    parallel_SST_model_DW.T_o->size[0] = 1;
    loop_ub = (int32_T)parallel_SST_model_DW.n_dx_j.contents;
    parallel_SST_model_DW.T_o->size[1] = (int32_T)
      parallel_SST_model_DW.n_dx_j.contents;
    parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_o, nx);
    for (loop_ub_0 = 0; loop_ub_0 < loop_ub; loop_ub_0++)
    {
      parallel_SST_model_DW.T_o->data[loop_ub_0] = 1.0;
    }

    nx = parallel_SST_model_DW.T_o->size[0] * parallel_SST_model_DW.T_o->size[1];
    parallel_SST_model_DW.T_o->size[0] = 1;
    parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_o, nx);
    loop_ub = parallel_SST_model_DW.T_o->size[1] - 1;
    nx = (parallel_SST_model_DW.T_o->size[1] / 2) << 1;
    vectorUB = nx - 2;
    for (loop_ub_0 = 0; loop_ub_0 <= vectorUB; loop_ub_0 += 2)
    {
      tmp_1 = _mm_loadu_pd(&parallel_SST_model_DW.T_o->data[loop_ub_0]);
      _mm_storeu_pd(&parallel_SST_model_DW.T_o->data[loop_ub_0], _mm_mul_pd
                    (tmp_1, _mm_set1_pd(parallel_SST_model_P.SHreturnpipe_T_duct)));
    }

    for (loop_ub_0 = nx; loop_ub_0 <= loop_ub; loop_ub_0++)
    {
      parallel_SST_model_DW.T_o->data[loop_ub_0] *=
        parallel_SST_model_P.SHreturnpipe_T_duct;
    }
  }
  else
  {
    /* :  else */
    /* :  timeIdx = timeIdx + 1; */
    parallel_SST_model_DW.timeIdx_m++;
  }

  /* :  if timeIdx == 1 */
  if (parallel_SST_model_DW.timeIdx_m == 1.0)
  {
    /* :  stepSize = 30; */
    rtb_m_3__b = 30.0;
  }

  /* :  dt = stepSize; */
  /* :  V_min = dx / dt; */
  /* :  m_min = V_min * rho * A; */
  rtb_T_1__o = parallel_SST_model_DW.dx_i.contents / rtb_m_3__b * 1000.0 *
    parallel_SST_model_DW.A_k;

  /* :  if m < 0 */
  if (rtb_T_2__kw < 0.0)
  {
    /* :  fprintf("Thermal pipe: mass flow m=%1.2e kg/s < 0, it is replaced by zero.\n", m); */
    printf("Thermal pipe: mass flow m=%1.2e kg/s < 0, it is replaced by zero.\n",
           rtb_T_2__kw);
    fflush(stdout);

    /* :  m = 0; */
    rtb_T_2__d = 0.0;
  }
  else if ((rtb_T_2__kw > 0.0) && (rtb_T_2__kw <= rtb_T_1__o))
  {
    /* :  elseif (0 < m) && (m <= m_min) */
    /* :  fprintf("Thermal pipe: mass flow m=%1.2e kg/s too small for the meshing (m_min value (for dt=%1.1fs): %1.2e kg/s), " + ... */
    /* :          "it is replaced by zero.\n", m, dt, m_min); */
    printf("Thermal pipe: mass flow m=%1.2e kg/s too small for the meshing (m_min value (for dt=%1.1fs): %1.2e kg/s), it is replaced by zero.\n",
           rtb_T_2__kw, rtb_m_3__b, rtb_T_1__o);
    fflush(stdout);

    /* :  m = 0; */
    rtb_T_2__d = 0.0;
  }

  /* :  V = m / (rho * A); */
  /* :  t0 = 0; */
  /* :  tf = stepSize; */
  /* :  tspan = t0:tf; */
  if (rtIsNaN(rtb_m_3__b))
  {
    nx = tspan->size[0] * tspan->size[1];
    tspan->size[0] = 1;
    tspan->size[1] = 1;
    parall_emxEnsureCapacity_real_T(tspan, nx);
    tspan->data[0] = (rtNaN);
  }
  else if (rtb_m_3__b < 0.0)
  {
    tspan->size[0] = 1;
    tspan->size[1] = 0;
  }
  else
  {
    nx = tspan->size[0] * tspan->size[1];
    tspan->size[0] = 1;
    tspan->size[1] = (int32_T)rtb_m_3__b + 1;
    parall_emxEnsureCapacity_real_T(tspan, nx);
    loop_ub = (int32_T)rtb_m_3__b;
    for (loop_ub_0 = 0; loop_ub_0 <= loop_ub; loop_ub_0++)
    {
      tspan->data[loop_ub_0] = loop_ub_0;
    }
  }

  /* :  options = odeset('RelTol',1e-3, 'AbsTol', 1e-3); */
  /* :  y0 = T; */
  /* :  [~,y] = ode23(@(t, y) ODE(t, y, V, T_in), tspan, y0, options); */
  parallel_SST_model_ode23(&parallel_SST_model_DW.n_dx_j,
    &parallel_SST_model_DW.dx_i, &parallel_SST_model_DW.tau_h, &b_T_duct_2,
    rtb_T_2__d / (1000.0 * parallel_SST_model_DW.A_k), rtb_T_3__p, tspan,
    parallel_SST_model_DW.T_o, a__1, y);
  parallel_SST_mod_emxFree_real_T(&a__1);
  parallel_SST_mod_emxFree_real_T(&tspan);

  /* MATLAB Function: 'thermal_pipe_function' (':2:523') */
  /* :  Q = k * L * (mean(y, "all") - T_duct); */
  loop_ub_0 = y->size[0] * y->size[1];
  if (loop_ub_0 == 0)
  {
    rtb_T_2__d = 0.0;
  }
  else if (loop_ub_0 == 0)
  {
    rtb_T_2__d = 0.0;
  }
  else
  {
    y_2 = *y;
    y_7 = loop_ub_0;
    y_2.size = &y_7;
    y_2.numDimensions = 1;
    rtb_T_2__d = parallel_SST_m_colMajorFlatIter(&y_2, loop_ub_0);
  }

  /* :  T_out = mean(y(:, end)); */
  y_tmp = y->size[1];
  loop_ub = y->size[0];
  nx = y_1->size[0];
  y_1->size[0] = y->size[0];
  parall_emxEnsureCapacity_real_T(y_1, nx);
  for (nx = 0; nx < loop_ub; nx++)
  {
    y_1->data[nx] = y->data[(y_tmp - 1) * y->size[0] + nx];
  }

  parallel_SST_model_B.T_out = parallel_SST_m_colMajorFlatIter(y_1, y->size[0]) /
    (real_T)y->size[0];
  parallel_SST_mod_emxFree_real_T(&y_1);

  /* MATLAB Function: 'thermal_pipe_function' (':2:523') */
  /* :  T = y(end, :); */
  nx = parallel_SST_model_DW.T_o->size[0] * parallel_SST_model_DW.T_o->size[1];
  parallel_SST_model_DW.T_o->size[0] = 1;
  parallel_SST_model_DW.T_o->size[1] = y->size[1];
  parall_emxEnsureCapacity_real_T(parallel_SST_model_DW.T_o, nx);
  for (nx = 0; nx < y_tmp; nx++)
  {
    parallel_SST_model_DW.T_o->data[nx] = y->data[(y->size[0] * nx + loop_ub) -
      1];
  }

  parallel_SST_mod_emxFree_real_T(&y);

  /* MATLAB Function: '3WV_function' (':904:1') incorporates:
   *  Constant: 'Constant3' (':787')
   *  Inport: 'm_DHW_dir' (':348')
   *  Inport: 'm_SH_dir' (':340')
   */
  parallel_SST_model_uWV_function(parallel_SST_model_U.m_SH_dir,
    parallel_SST_model_B.T_out, parallel_SST_model_U.m_DHW_dir,
    parallel_SST_model_B.T_1_out, 0.0, 0.0, parallel_SST_model_P.Constant3_Value,
    &rtb_m_3__b, &rtb_T_1__o, &rtb_m_2__o, &rtb_T_2__o, &rtb_m_3__c, &V_var_,
    parallel_SST_model_P.SHDHWreturnvalve_unknown_T,
    parallel_SST_model_P.SHDHWreturnvalve_unknown_m);

  /* Outport: 'T_sec_in' (':428') */
  parallel_SST_model_Y.T_sec_in = V_var_;

  /* Outport: 'efficiency_primary_HX' (':459') incorporates:
   *  Inport: 'T_prim_in' (':346')
   *  Inport: 'm_prim' (':345')
   *  MATLAB Function: 'heat_exchanger_function' (':73:5')
   *  Outport: 'Q_primary_HX' (':442')
   *  Outport: 'T_prim_out' (':437')
   */
  paralle_heat_exchanger_function(parallel_SST_model_U.m_prim, rtb_m_3__c,
    parallel_SST_model_U.T_prim_in, V_var_, &parallel_SST_model_Y.T_prim_out,
    &parallel_SST_model_B.T_2_out, &parallel_SST_model_Y.Q_primary_HX,
    &parallel_SST_model_Y.efficiency_primary_HX,
    parallel_SST_model_P.Primaryheatexchanger_A,
    parallel_SST_model_P.Primaryheatexchanger_U);

  /* Outport: 'T_sec_out' (':438') */
  parallel_SST_model_Y.T_sec_out = parallel_SST_model_B.T_2_out;

  /* Outport: 'm_sec' (':455') */
  parallel_SST_model_Y.m_sec = rtb_m_3__c;

  /* Outport: 'T_SH_out' (':435') */
  parallel_SST_model_Y.T_SH_out = parallel_SST_model_B.T_out;

  /* Outport: 'Q_SH_return' (':447') incorporates:
   *  MATLAB Function: 'thermal_pipe_function' (':2:523')
   */
  parallel_SST_model_Y.Q_SH_return = (rtb_T_2__d / (real_T)loop_ub_0 -
    parallel_SST_model_P.SHreturnpipe_T_duct) * (parallel_SST_model_DW.k_o *
    parallel_SST_model_P.SHreturnpipe_L);

  /* Outport: 'T_SH_emitter_out' (':439') */
  parallel_SST_model_Y.T_SH_emitter_out = rtb_T_3__p;

  /* Outport: 'Q_SH' (':441') incorporates:
   *  MATLAB Function: 'thermal_emitters_function' (':637:65')
   */
  parallel_SST_model_Y.Q_SH = parallel_SST_model_P.SHthermalemitters_n_radiators
    * parallel_SST_model_P.SHthermalemitters_n_tubes *
    parallel_SST_model_P.SHthermalemitters_U * 3.1415926535897931 *
    parallel_SST_model_P.SHthermalemitters_D *
    parallel_SST_model_P.SHthermalemitters_L * (rtb_m_2__g / (real_T)y_idx_0_0 -
    parallel_SST_model_P.SHthermalemitters_T_air);

  /* Outport: 'Q_SH_supply' (':446') incorporates:
   *  MATLAB Function: 'thermal_pipe_function' (':1:523')
   */
  parallel_SST_model_Y.Q_SH_supply = (rtb_T_1__f / (real_T)y_idx_0 -
    parallel_SST_model_P.SHsupplypipe_T_duct) * (parallel_SST_model_DW.k *
    parallel_SST_model_P.SHsupplypipe_L);

  /* Outport: 'T_SH_emitter_in' (':614') */
  parallel_SST_model_Y.T_SH_emitter_in = rtb_m_2__f;

  /* Outport: 'T_SH_in' (':436') */
  parallel_SST_model_Y.T_SH_in = rtb_m_1__n;

  /* Outport: 'm_SH' (':456') */
  parallel_SST_model_Y.m_SH = rtb_T_2__kw;

  /* Outport: 'T_DHW_prim_in' (':433') */
  parallel_SST_model_Y.T_DHW_prim_in = rtb_T_3__ix;

  /* Outport: 'm_DHW_prim' (':454') */
  parallel_SST_model_Y.m_DHW_prim = rtb_m_3__p;

  /* Outport: 'm_DHW_stor' (':1073') */
  parallel_SST_model_Y.m_DHW_stor = m_DHW_stor;

  /* Outport: 'm_DHW' (':445') */
  parallel_SST_model_Y.m_DHW = rtb_m_DHW;

  /* Update for Delay: 'Delay' (':899') */
  parallel_SST_model_DW.Delay_DSTATE = parallel_SST_model_B.T_2_out;

  /* Update for Delay: 'Delay1' (':900') */
  parallel_SST_model_DW.Delay1_DSTATE = parallel_SST_model_B.T_1_out;

  /* Update for Delay: 'Delay6' (':890') */
  parallel_SST_model_DW.Delay6_DSTATE = parallel_SST_model_B.T_3_;

  /* Update for Delay: 'Delay5' (':889') */
  parallel_SST_model_DW.Delay5_DSTATE = parallel_SST_model_B.Tn;

  /* Update for Delay: 'Delay' (':70:541') */
  parallel_SST_model_DW.Delay_DSTATE_h = parallel_SST_model_B.Clock;

  /* Update for Delay: 'Delay' (':71:541') */
  parallel_SST_model_DW.Delay_DSTATE_f = parallel_SST_model_B.Clock_o;

  /* Update for Delay: 'Delay' (':206:6') */
  parallel_SST_model_DW.Delay_DSTATE_l = parallel_SST_model_B.Clock_h;

  /* Update for Delay: 'Delay2' (':894') */
  parallel_SST_model_DW.Delay2_DSTATE = parallel_SST_model_B.T_2_out;

  /* Update for Delay: 'Delay7' (':896') */
  parallel_SST_model_DW.Delay7_DSTATE = parallel_SST_model_B.T_out;

  /* Update for Delay: 'Delay' (':1:541') */
  parallel_SST_model_DW.Delay_DSTATE_o = parallel_SST_model_B.Clock_c;

  /* Update for Delay: 'Delay' (':637:278') */
  parallel_SST_model_DW.Delay_DSTATE_i = parallel_SST_model_B.Clock_hf;

  /* Update for Delay: 'Delay' (':2:541') */
  parallel_SST_model_DW.Delay_DSTATE_m = parallel_SST_model_B.Clock_b;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  parallel_SST_model_M->Timing.t[0] =
    ((time_T)(++parallel_SST_model_M->Timing.clockTick0)) *
    parallel_SST_model_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [60.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 60.0, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    parallel_SST_model_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void parallel_SST_model_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)parallel_SST_model_M, 0,
                sizeof(RT_MODEL_parallel_SST_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&parallel_SST_model_M->solverInfo,
                          &parallel_SST_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&parallel_SST_model_M->solverInfo, &rtmGetTPtr
                (parallel_SST_model_M));
    rtsiSetStepSizePtr(&parallel_SST_model_M->solverInfo,
                       &parallel_SST_model_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&parallel_SST_model_M->solverInfo, (&rtmGetErrorStatus
      (parallel_SST_model_M)));
    rtsiSetRTModelPtr(&parallel_SST_model_M->solverInfo, parallel_SST_model_M);
  }

  rtsiSetSimTimeStep(&parallel_SST_model_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&parallel_SST_model_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&parallel_SST_model_M->solverInfo, false);
  rtsiSetSolverName(&parallel_SST_model_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(parallel_SST_model_M, &parallel_SST_model_M->Timing.tArray[0]);
  parallel_SST_model_M->Timing.stepSize0 = 60.0;

  /* block I/O */
  (void) memset(((void *) &parallel_SST_model_B), 0,
                sizeof(B_parallel_SST_model_T));

  /* states (dwork) */
  (void) memset((void *)&parallel_SST_model_DW, 0,
                sizeof(DW_parallel_SST_model_T));

  /* external inputs */
  (void)memset(&parallel_SST_model_U, 0, sizeof(ExtU_parallel_SST_model_T));

  /* external outputs */
  (void)memset(&parallel_SST_model_Y, 0, sizeof(ExtY_parallel_SST_model_T));

  /* InitializeConditions for Delay: 'Delay' (':899') */
  parallel_SST_model_DW.Delay_DSTATE =
    parallel_SST_model_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: 'Delay1' (':900') */
  parallel_SST_model_DW.Delay1_DSTATE =
    parallel_SST_model_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: 'Delay6' (':890') */
  parallel_SST_model_DW.Delay6_DSTATE =
    parallel_SST_model_P.Delay6_InitialCondition;

  /* InitializeConditions for Delay: 'Delay5' (':889') */
  parallel_SST_model_DW.Delay5_DSTATE =
    parallel_SST_model_P.Delay5_InitialCondition;

  /* InitializeConditions for Delay: 'Delay' (':70:541') */
  parallel_SST_model_DW.Delay_DSTATE_h =
    parallel_SST_model_P.Delay_InitialCondition_o;

  /* InitializeConditions for Delay: 'Delay' (':71:541') */
  parallel_SST_model_DW.Delay_DSTATE_f =
    parallel_SST_model_P.Delay_InitialCondition_k;

  /* InitializeConditions for Delay: 'Delay' (':206:6') */
  parallel_SST_model_DW.Delay_DSTATE_l =
    parallel_SST_model_P.Delay_InitialCondition_o4;

  /* InitializeConditions for Delay: 'Delay2' (':894') */
  parallel_SST_model_DW.Delay2_DSTATE =
    parallel_SST_model_P.Delay2_InitialCondition;

  /* InitializeConditions for Delay: 'Delay7' (':896') */
  parallel_SST_model_DW.Delay7_DSTATE =
    parallel_SST_model_P.Delay7_InitialCondition;

  /* InitializeConditions for Delay: 'Delay' (':1:541') */
  parallel_SST_model_DW.Delay_DSTATE_o =
    parallel_SST_model_P.Delay_InitialCondition_j;

  /* InitializeConditions for Delay: 'Delay' (':637:278') */
  parallel_SST_model_DW.Delay_DSTATE_i =
    parallel_SST_model_P.Delay_InitialCondition_l;

  /* InitializeConditions for Delay: 'Delay' (':2:541') */
  parallel_SST_model_DW.Delay_DSTATE_m =
    parallel_SST_model_P.Delay_InitialCondition_jr;
  parallel_SST_mod_emxInit_real_T(&parallel_SST_model_DW.T_k, 2);

  /* SystemInitialize for MATLAB Function: 'thermal_pipe_function' (':70:523') */
  parallel_SST_model_DW.k_not_empty_h = false;
  parallel_SST_mod_emxInit_real_T(&parallel_SST_model_DW.T_p, 2);

  /* SystemInitialize for MATLAB Function: 'thermal_pipe_function' (':71:523') */
  parallel_SST_model_DW.k_not_empty_f = false;
  parallel_SST_mod_emxInit_real_T(&parallel_SST_model_DW.T_init, 2);

  /* SystemInitialize for MATLAB Function: 'storage_TC_func' (':206:8') */
  parallel_SST_model_DW.V1_not_empty = false;
  parallel_SST_mod_emxInit_real_T(&parallel_SST_model_DW.T_m, 2);

  /* SystemInitialize for MATLAB Function: 'thermal_pipe_function' (':1:523') */
  parallel_SST_model_DW.k_not_empty = false;
  parallel_SST_mod_emxInit_real_T(&parallel_SST_model_DW.T, 2);

  /* SystemInitialize for MATLAB Function: 'thermal_emitters_function' (':637:65') */
  parallel_SST_model_DW.tau_not_empty = false;
  parallel_SST_mod_emxInit_real_T(&parallel_SST_model_DW.T_o, 2);

  /* SystemInitialize for MATLAB Function: 'thermal_pipe_function' (':2:523') */
  parallel_SST_model_DW.k_not_empty_b = false;
}

/* Model terminate function */
void parallel_SST_model_terminate(void)
{
  parallel_SST_mod_emxFree_real_T(&parallel_SST_model_DW.T_k);
  parallel_SST_mod_emxFree_real_T(&parallel_SST_model_DW.T_p);
  parallel_SST_mod_emxFree_real_T(&parallel_SST_model_DW.T_init);
  parallel_SST_mod_emxFree_real_T(&parallel_SST_model_DW.T_m);
  parallel_SST_mod_emxFree_real_T(&parallel_SST_model_DW.T);
  parallel_SST_mod_emxFree_real_T(&parallel_SST_model_DW.T_o);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
