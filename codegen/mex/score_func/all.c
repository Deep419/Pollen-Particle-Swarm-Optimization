/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * all.c
 *
 * Code generation for function 'all'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "score_func.h"
#include "all.h"

/* Function Definitions */
boolean_T all(const emxArray_real_T *a)
{
  boolean_T p;
  int32_T i3;
  int32_T k;
  boolean_T exitg1;
  p = true;
  i3 = a->size[0] << 2;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i3 - 1)) {
    if ((!muDoubleScalarIsInf(a->data[k])) && (!muDoubleScalarIsNaN(a->data[k])))
    {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  return p;
}

/* End of code generation (all.c) */
