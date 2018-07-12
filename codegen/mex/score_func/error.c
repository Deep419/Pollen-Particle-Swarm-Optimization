/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error.c
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "score_func.h"
#include "error.h"

/* Variable Definitions */
static emlrtRTEInfo ob_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "error",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\error.m"/* pName */
};

/* Function Definitions */
void b_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2018a(sp, &ob_emlrtRTEI, "MATLAB:nologicalnan",
    "MATLAB:nologicalnan", 0);
}

void error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2018a(sp, &ob_emlrtRTEI,
    "Coder:toolbox:reshape_emptyReshapeLimit",
    "Coder:toolbox:reshape_emptyReshapeLimit", 0);
}

/* End of code generation (error.c) */
