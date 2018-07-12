/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * validateattributes.c
 *
 * Code generation for function 'validateattributes'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "score_func.h"
#include "validateattributes.h"
#include "validatesize.h"
#include "all.h"
#include "score_func_data.h"

/* Variable Definitions */
static emlrtRTEInfo rb_emlrtRTEI = { 15,/* lineNo */
  37,                                  /* colNo */
  "validatesize",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatesize.m"/* pName */
};

/* Function Definitions */
void validateattributes(const emlrtStack *sp, const emxArray_real_T *a)
{
  boolean_T b0;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &x_emlrtRSI;
  b0 = all(a);
  if (!b0) {
    emlrtErrorWithMessageIdR2018a(&st, &qb_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:bboxOverlapRatio:expectedFinite", 3, 4, 5, "input");
  }

  st.site = &x_emlrtRSI;
  if (!size_check(a)) {
    emlrtErrorWithMessageIdR2018a(&st, &rb_emlrtRTEI,
      "Coder:toolbox:ValidateattributesincorrectSize",
      "MATLAB:bboxOverlapRatio:incorrectSize", 3, 4, 5, "Input");
  }
}

/* End of code generation (validateattributes.c) */
