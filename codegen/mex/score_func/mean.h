/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.h
 *
 * Code generation for function 'mean'
 *
 */

#ifndef MEAN_H
#define MEAN_H

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
extern real_T b_mean(const emlrtStack *sp, const emxArray_real_T *x);
extern real_T mean(const emlrtStack *sp, const emxArray_real_T *x);

#endif

/* End of code generation (mean.h) */
