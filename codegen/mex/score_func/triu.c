/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * triu.c
 *
 * Code generation for function 'triu'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "score_func.h"
#include "triu.h"
#include "eml_int_forloop_overflow_check.h"
#include "score_func_data.h"

/* Variable Definitions */
static emlrtRSInfo gb_emlrtRSI = { 48, /* lineNo */
  "triu",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\triu.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 47, /* lineNo */
  "triu",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\triu.m"/* pathName */
};

/* Function Definitions */
void triu(const emlrtStack *sp, emxArray_real_T *x)
{
  int32_T m;
  int32_T istart;
  int32_T jstart;
  int32_T ncolsm1;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  m = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0) || (0 >= x->size[0])) {
  } else {
    istart = 1;
    jstart = muIntScalarMin_sint32(1, x->size[1]);
    ncolsm1 = x->size[1] - jstart;
    if (x->size[0] - 1 < ncolsm1) {
      jstart = (jstart + x->size[0]) - 1;
    } else {
      jstart += ncolsm1;
    }

    st.site = &hb_emlrtRSI;
    if ((!(1 > jstart)) && (jstart > 2147483646)) {
      b_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (ncolsm1 = 1; ncolsm1 <= jstart; ncolsm1++) {
      st.site = &gb_emlrtRSI;
      if ((!(istart > m)) && (m > 2147483646)) {
        b_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (i = istart; i <= m; i++) {
        x->data[(i + x->size[0] * (ncolsm1 - 1)) - 1] = 0.0;
      }

      istart++;
    }
  }
}

/* End of code generation (triu.c) */
