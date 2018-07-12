/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bboxOverlapRatio.h
 *
 * Code generation for function 'bboxOverlapRatio'
 *
 */

#ifndef BBOXOVERLAPRATIO_H
#define BBOXOVERLAPRATIO_H

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
extern void b_bboxOverlapRatio(const emlrtStack *sp, const emxArray_real_T
  *varargin_1, const emxArray_real_T *varargin_2, emxArray_real_T *overlapRatio);
extern void bboxOverlapRatio(const emlrtStack *sp, const real_T varargin_1[4],
  const emxArray_real_T *varargin_2, emxArray_real_T *overlapRatio);
extern void validateAndParseInputsCodegen(const emlrtStack *sp, const
  emxArray_real_T *varargin_1, const emxArray_real_T *varargin_2);

#endif

/* End of code generation (bboxOverlapRatio.h) */
