/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "score_func.h"
#include "sum.h"
#include "score_func_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "score_func_data.h"

/* Variable Definitions */
static emlrtRSInfo kb_emlrtRSI = { 9,  /* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 64, /* lineNo */
  "sumprod",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 177,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 195,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 9,/* lineNo */
  1,                                   /* colNo */
  "sum",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 134,/* lineNo */
  13,                                  /* colNo */
  "combineVectorElements",             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pName */
};

/* Function Definitions */
void sum(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T k;
  int32_T vstride;
  uint32_T sz[2];
  int32_T j;
  boolean_T overflow;
  int32_T xoffset;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &lb_emlrtRSI;
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    for (k = 0; k < 2; k++) {
      sz[k] = (uint32_T)x->size[k];
    }

    k = y->size[0];
    y->size[0] = (int32_T)sz[0];
    emxEnsureCapacity_real_T1(&b_st, y, k, &eb_emlrtRTEI);
    j = (int32_T)sz[0];
    for (k = 0; k < j; k++) {
      y->data[k] = 0.0;
    }
  } else {
    c_st.site = &eb_emlrtRSI;
    vstride = x->size[0];
    k = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_real_T1(&c_st, y, k, &fb_emlrtRTEI);
    d_st.site = &mb_emlrtRSI;
    overflow = (x->size[0] > 2147483646);
    if (overflow) {
      e_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (j = 0; j < vstride; j++) {
      y->data[j] = x->data[j];
    }

    d_st.site = &fb_emlrtRSI;
    overflow = ((!(2 > x->size[1])) && (x->size[1] > 2147483646));
    if (overflow) {
      e_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 2; k <= x->size[1]; k++) {
      xoffset = (k - 1) * vstride;
      d_st.site = &nb_emlrtRSI;
      for (j = 0; j < vstride; j++) {
        y->data[j] += x->data[xoffset + j];
      }
    }
  }
}

/* End of code generation (sum.c) */
