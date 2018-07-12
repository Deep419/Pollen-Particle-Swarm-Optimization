/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * score_func.h
 *
 * Code generation for function 'score_func'
 *
 */

#ifndef SCORE_FUNC_H
#define SCORE_FUNC_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "score_func_types.h"

/* Function Declarations */
extern void score_func(const emlrtStack *sp, real_T r, real_T c, const
  emxArray_real_T *gt, real_T verify, const emxArray_real_T *params, real_T
  s_data[], int32_T s_size[2]);

#endif

/* End of code generation (score_func.h) */
