/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * score_func_initialize.c
 *
 * Code generation for function 'score_func_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "score_func.h"
#include "score_func_initialize.h"
#include "_coder_score_func_mex.h"
#include "score_func_data.h"

/* Function Definitions */
void score_func_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "Video_and_Image_Blockset", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (score_func_initialize.c) */
