/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bboxOverlapRatio.c
 *
 * Code generation for function 'bboxOverlapRatio'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "score_func.h"
#include "bboxOverlapRatio.h"
#include "score_func_emxutil.h"
#include "any.h"
#include "validateattributes.h"
#include "score_func_data.h"

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = { 153, /* lineNo */
  "bboxOverlapRatio",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 156, /* lineNo */
  "bboxOverlapRatio",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 137, /* lineNo */
  "bboxOverlapRatio",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 141, /* lineNo */
  "bboxOverlapRatio",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pathName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 141,/* lineNo */
  29,                                  /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 141,/* lineNo */
  50,                                  /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 73,/* lineNo */
  5,                                   /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 78,/* lineNo */
  5,                                   /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 141,/* lineNo */
  1,                                   /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

/* Function Definitions */
void b_bboxOverlapRatio(const emlrtStack *sp, const emxArray_real_T *varargin_1,
  const emxArray_real_T *varargin_2, emxArray_real_T *overlapRatio)
{
  emxArray_real_T *bboxA;
  int32_T i4;
  int32_T loop_ub;
  emxArray_real_T *bboxB;
  emxArray_real_T *x2BboxA;
  emxArray_real_T *y2BboxA;
  emxArray_real_T *x2BboxB;
  emxArray_real_T *y2BboxB;
  emxArray_real_T *areaA;
  emxArray_real_T *areaB;
  int32_T m;
  int32_T n;
  real_T w;
  real_T h;
  int32_T i5;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &bboxA, 2, &g_emlrtRTEI, true);
  i4 = bboxA->size[0] * bboxA->size[1];
  bboxA->size[0] = varargin_1->size[0];
  bboxA->size[1] = 4;
  emxEnsureCapacity_real_T(sp, bboxA, i4, &g_emlrtRTEI);
  loop_ub = varargin_1->size[0] * varargin_1->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    bboxA->data[i4] = varargin_1->data[i4];
  }

  emxInit_real_T(sp, &bboxB, 2, &h_emlrtRTEI, true);
  i4 = bboxB->size[0] * bboxB->size[1];
  bboxB->size[0] = varargin_2->size[0];
  bboxB->size[1] = 4;
  emxEnsureCapacity_real_T(sp, bboxB, i4, &h_emlrtRTEI);
  loop_ub = varargin_2->size[0] * varargin_2->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    bboxB->data[i4] = varargin_2->data[i4];
  }

  st.site = &s_emlrtRSI;
  validateAndParseInputsCodegen(&st, bboxA, bboxB);
  emxInit_real_T1(sp, &x2BboxA, 1, &j_emlrtRTEI, true);
  emxInit_real_T1(sp, &y2BboxA, 1, &k_emlrtRTEI, true);
  emxInit_real_T1(sp, &x2BboxB, 1, &l_emlrtRTEI, true);
  emxInit_real_T1(sp, &y2BboxB, 1, &n_emlrtRTEI, true);
  emxInit_real_T1(sp, &areaA, 1, &o_emlrtRTEI, true);
  emxInit_real_T1(sp, &areaB, 1, &p_emlrtRTEI, true);
  if ((bboxA->size[0] == 0) || (bboxB->size[0] == 0)) {
    i4 = overlapRatio->size[0] * overlapRatio->size[1];
    overlapRatio->size[0] = bboxA->size[0];
    overlapRatio->size[1] = bboxB->size[0];
    emxEnsureCapacity_real_T(sp, overlapRatio, i4, &cb_emlrtRTEI);
    loop_ub = bboxA->size[0] * bboxB->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      overlapRatio->data[i4] = 0.0;
    }
  } else {
    st.site = &t_emlrtRSI;
    i4 = bboxA->size[0];
    loop_ub = bboxA->size[0];
    if (i4 != loop_ub) {
      emlrtSizeEqCheck1DR2012b(i4, loop_ub, &f_emlrtECI, &st);
    }

    loop_ub = bboxA->size[0];
    i4 = x2BboxA->size[0];
    x2BboxA->size[0] = loop_ub;
    emxEnsureCapacity_real_T1(&st, x2BboxA, i4, &j_emlrtRTEI);
    for (i4 = 0; i4 < loop_ub; i4++) {
      x2BboxA->data[i4] = bboxA->data[i4] + bboxA->data[i4 + (bboxA->size[0] <<
        1)];
    }

    i4 = bboxA->size[0];
    loop_ub = bboxA->size[0];
    if (i4 != loop_ub) {
      emlrtSizeEqCheck1DR2012b(i4, loop_ub, &e_emlrtECI, &st);
    }

    loop_ub = bboxA->size[0];
    i4 = y2BboxA->size[0];
    y2BboxA->size[0] = loop_ub;
    emxEnsureCapacity_real_T1(&st, y2BboxA, i4, &k_emlrtRTEI);
    for (i4 = 0; i4 < loop_ub; i4++) {
      y2BboxA->data[i4] = bboxA->data[i4 + bboxA->size[0]] + bboxA->data[i4 +
        bboxA->size[0] * 3];
    }

    i4 = bboxB->size[0];
    loop_ub = bboxB->size[0];
    if (i4 != loop_ub) {
      emlrtSizeEqCheck1DR2012b(i4, loop_ub, &d_emlrtECI, &st);
    }

    loop_ub = bboxB->size[0];
    i4 = x2BboxB->size[0];
    x2BboxB->size[0] = loop_ub;
    emxEnsureCapacity_real_T1(&st, x2BboxB, i4, &l_emlrtRTEI);
    for (i4 = 0; i4 < loop_ub; i4++) {
      x2BboxB->data[i4] = bboxB->data[i4] + bboxB->data[i4 + (bboxB->size[0] <<
        1)];
    }

    i4 = bboxB->size[0];
    loop_ub = bboxB->size[0];
    if (i4 != loop_ub) {
      emlrtSizeEqCheck1DR2012b(i4, loop_ub, &c_emlrtECI, &st);
    }

    loop_ub = bboxB->size[0];
    i4 = y2BboxB->size[0];
    y2BboxB->size[0] = loop_ub;
    emxEnsureCapacity_real_T1(&st, y2BboxB, i4, &n_emlrtRTEI);
    for (i4 = 0; i4 < loop_ub; i4++) {
      y2BboxB->data[i4] = bboxB->data[i4 + bboxB->size[0]] + bboxB->data[i4 +
        bboxB->size[0] * 3];
    }

    i4 = bboxA->size[0];
    loop_ub = bboxA->size[0];
    if (i4 != loop_ub) {
      emlrtSizeEqCheck1DR2012b(i4, loop_ub, &b_emlrtECI, &st);
    }

    loop_ub = bboxA->size[0];
    i4 = areaA->size[0];
    areaA->size[0] = loop_ub;
    emxEnsureCapacity_real_T1(&st, areaA, i4, &o_emlrtRTEI);
    for (i4 = 0; i4 < loop_ub; i4++) {
      areaA->data[i4] = bboxA->data[i4 + (bboxA->size[0] << 1)] * bboxA->data[i4
        + bboxA->size[0] * 3];
    }

    i4 = bboxB->size[0];
    loop_ub = bboxB->size[0];
    if (i4 != loop_ub) {
      emlrtSizeEqCheck1DR2012b(i4, loop_ub, &emlrtECI, &st);
    }

    loop_ub = bboxB->size[0];
    i4 = areaB->size[0];
    areaB->size[0] = loop_ub;
    emxEnsureCapacity_real_T1(&st, areaB, i4, &p_emlrtRTEI);
    for (i4 = 0; i4 < loop_ub; i4++) {
      areaB->data[i4] = bboxB->data[i4 + (bboxB->size[0] << 1)] * bboxB->data[i4
        + bboxB->size[0] * 3];
    }

    i4 = overlapRatio->size[0] * overlapRatio->size[1];
    overlapRatio->size[0] = bboxA->size[0];
    overlapRatio->size[1] = bboxB->size[0];
    emxEnsureCapacity_real_T(&st, overlapRatio, i4, &db_emlrtRTEI);
    loop_ub = bboxA->size[0] * bboxB->size[0];
    for (i4 = 0; i4 < loop_ub; i4++) {
      overlapRatio->data[i4] = 0.0;
    }

    for (m = 0; m < bboxA->size[0]; m++) {
      for (n = 0; n < bboxB->size[0]; n++) {
        i4 = bboxA->size[0];
        loop_ub = m + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i4))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &j_emlrtBCI, &st);
        }

        i4 = bboxB->size[0];
        loop_ub = n + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i4))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &i_emlrtBCI, &st);
        }

        i4 = bboxA->size[0];
        loop_ub = m + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i4))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &h_emlrtBCI, &st);
        }

        i4 = bboxB->size[0];
        loop_ub = n + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i4))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &g_emlrtBCI, &st);
        }

        i4 = x2BboxA->size[0];
        loop_ub = m + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i4))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &f_emlrtBCI, &st);
        }

        i4 = x2BboxB->size[0];
        loop_ub = n + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i4))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &e_emlrtBCI, &st);
        }

        i4 = y2BboxA->size[0];
        loop_ub = m + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i4))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &d_emlrtBCI, &st);
        }

        i4 = y2BboxB->size[0];
        loop_ub = n + 1;
        if (!((loop_ub >= 1) && (loop_ub <= i4))) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &c_emlrtBCI, &st);
        }

        w = muDoubleScalarMin(x2BboxA->data[m], x2BboxB->data[n]) -
          muDoubleScalarMax(bboxA->data[m], bboxB->data[n]);
        if (!(w <= 0.0)) {
          h = muDoubleScalarMin(y2BboxA->data[m], y2BboxB->data[n]) -
            muDoubleScalarMax(bboxA->data[m + bboxA->size[0]], bboxB->data[n +
                              bboxB->size[0]]);
          if (!(h <= 0.0)) {
            i4 = areaA->size[0];
            loop_ub = m + 1;
            if (!((loop_ub >= 1) && (loop_ub <= i4))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &b_emlrtBCI, &st);
            }

            i4 = areaB->size[0];
            loop_ub = n + 1;
            if (!((loop_ub >= 1) && (loop_ub <= i4))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &emlrtBCI, &st);
            }

            i4 = overlapRatio->size[0];
            loop_ub = 1 + m;
            if (!((loop_ub >= 1) && (loop_ub <= i4))) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i4, &n_emlrtBCI, &st);
            }

            i4 = overlapRatio->size[1];
            i5 = 1 + n;
            if (!((i5 >= 1) && (i5 <= i4))) {
              emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &n_emlrtBCI, &st);
            }

            overlapRatio->data[(loop_ub + overlapRatio->size[0] * (i5 - 1)) - 1]
              = w * h / muDoubleScalarMin(areaA->data[m], areaB->data[n]);
          }
        }
      }
    }
  }

  emxFree_real_T(sp, &areaB);
  emxFree_real_T(sp, &areaA);
  emxFree_real_T(sp, &y2BboxB);
  emxFree_real_T(sp, &x2BboxB);
  emxFree_real_T(sp, &y2BboxA);
  emxFree_real_T(sp, &x2BboxA);
  emxFree_real_T(sp, &bboxB);
  emxFree_real_T(sp, &bboxA);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void bboxOverlapRatio(const emlrtStack *sp, const real_T varargin_1[4], const
                      emxArray_real_T *varargin_2, emxArray_real_T *overlapRatio)
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emxArray_boolean_T *b_varargin_2;
  int32_T i2;
  emxArray_real_T *x2BboxB;
  emxArray_real_T *y2BboxB;
  emxArray_real_T *areaB;
  real_T areaA;
  int32_T n;
  real_T w;
  real_T h;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &s_emlrtRSI;
  b_st.site = &u_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  d_st.site = &x_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if ((!muDoubleScalarIsInf(varargin_1[k])) && (!muDoubleScalarIsNaN
         (varargin_1[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &qb_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:bboxOverlapRatio:expectedFinite", 3, 4, 5, "input");
  }

  if ((varargin_1[2] <= 0.0) || (varargin_1[3] <= 0.0)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &pb_emlrtRTEI,
      "vision:visionlib:invalidBboxHeightWidth",
      "vision:visionlib:invalidBboxHeightWidth", 0);
  }

  emxInit_boolean_T(&b_st, &b_varargin_2, 1, &ab_emlrtRTEI, true);
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  validateattributes(&c_st, varargin_2);
  k = varargin_2->size[0];
  i2 = b_varargin_2->size[0];
  b_varargin_2->size[0] = k;
  emxEnsureCapacity_boolean_T(&b_st, b_varargin_2, i2, &ab_emlrtRTEI);
  for (i2 = 0; i2 < k; i2++) {
    b_varargin_2->data[i2] = (varargin_2->data[i2 + (varargin_2->size[0] << 1)] <=
      0.0);
  }

  c_st.site = &y_emlrtRSI;
  if (any(&c_st, b_varargin_2)) {
    p = true;
  } else {
    k = varargin_2->size[0];
    i2 = b_varargin_2->size[0];
    b_varargin_2->size[0] = k;
    emxEnsureCapacity_boolean_T(&b_st, b_varargin_2, i2, &bb_emlrtRTEI);
    for (i2 = 0; i2 < k; i2++) {
      b_varargin_2->data[i2] = (varargin_2->data[i2 + varargin_2->size[0] * 3] <=
        0.0);
    }

    c_st.site = &y_emlrtRSI;
    if (any(&c_st, b_varargin_2)) {
      p = true;
    } else {
      p = false;
    }
  }

  emxFree_boolean_T(&b_st, &b_varargin_2);
  if (p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &pb_emlrtRTEI,
      "vision:visionlib:invalidBboxHeightWidth",
      "vision:visionlib:invalidBboxHeightWidth", 0);
  }

  if (varargin_2->size[0] == 0) {
    i2 = overlapRatio->size[0] * overlapRatio->size[1];
    overlapRatio->size[0] = 1;
    overlapRatio->size[1] = 0;
    emxEnsureCapacity_real_T(sp, overlapRatio, i2, &cb_emlrtRTEI);
  } else {
    emxInit_real_T1(sp, &x2BboxB, 1, &l_emlrtRTEI, true);
    st.site = &t_emlrtRSI;
    i2 = varargin_2->size[0];
    k = varargin_2->size[0];
    if (i2 != k) {
      emlrtSizeEqCheck1DR2012b(i2, k, &d_emlrtECI, &st);
    }

    k = varargin_2->size[0];
    i2 = x2BboxB->size[0];
    x2BboxB->size[0] = k;
    emxEnsureCapacity_real_T1(&st, x2BboxB, i2, &l_emlrtRTEI);
    for (i2 = 0; i2 < k; i2++) {
      x2BboxB->data[i2] = varargin_2->data[i2] + varargin_2->data[i2 +
        (varargin_2->size[0] << 1)];
    }

    emxInit_real_T1(&st, &y2BboxB, 1, &n_emlrtRTEI, true);
    i2 = varargin_2->size[0];
    k = varargin_2->size[0];
    if (i2 != k) {
      emlrtSizeEqCheck1DR2012b(i2, k, &c_emlrtECI, &st);
    }

    k = varargin_2->size[0];
    i2 = y2BboxB->size[0];
    y2BboxB->size[0] = k;
    emxEnsureCapacity_real_T1(&st, y2BboxB, i2, &n_emlrtRTEI);
    for (i2 = 0; i2 < k; i2++) {
      y2BboxB->data[i2] = varargin_2->data[i2 + varargin_2->size[0]] +
        varargin_2->data[i2 + varargin_2->size[0] * 3];
    }

    emxInit_real_T1(&st, &areaB, 1, &p_emlrtRTEI, true);
    areaA = varargin_1[2] * varargin_1[3];
    i2 = varargin_2->size[0];
    k = varargin_2->size[0];
    if (i2 != k) {
      emlrtSizeEqCheck1DR2012b(i2, k, &emlrtECI, &st);
    }

    k = varargin_2->size[0];
    i2 = areaB->size[0];
    areaB->size[0] = k;
    emxEnsureCapacity_real_T1(&st, areaB, i2, &p_emlrtRTEI);
    for (i2 = 0; i2 < k; i2++) {
      areaB->data[i2] = varargin_2->data[i2 + (varargin_2->size[0] << 1)] *
        varargin_2->data[i2 + varargin_2->size[0] * 3];
    }

    i2 = overlapRatio->size[0] * overlapRatio->size[1];
    overlapRatio->size[0] = 1;
    overlapRatio->size[1] = varargin_2->size[0];
    emxEnsureCapacity_real_T(&st, overlapRatio, i2, &db_emlrtRTEI);
    k = varargin_2->size[0];
    for (i2 = 0; i2 < k; i2++) {
      overlapRatio->data[i2] = 0.0;
    }

    for (n = 0; n < varargin_2->size[0]; n++) {
      i2 = varargin_2->size[0];
      k = n + 1;
      if (!((k >= 1) && (k <= i2))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i2, &i_emlrtBCI, &st);
      }

      i2 = varargin_2->size[0];
      k = n + 1;
      if (!((k >= 1) && (k <= i2))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i2, &g_emlrtBCI, &st);
      }

      i2 = x2BboxB->size[0];
      k = n + 1;
      if (!((k >= 1) && (k <= i2))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i2, &e_emlrtBCI, &st);
      }

      i2 = y2BboxB->size[0];
      k = n + 1;
      if (!((k >= 1) && (k <= i2))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i2, &c_emlrtBCI, &st);
      }

      w = muDoubleScalarMin(1.0 + varargin_1[2], x2BboxB->data[n]) -
        muDoubleScalarMax(1.0, varargin_2->data[n]);
      if (!(w <= 0.0)) {
        h = muDoubleScalarMin(1.0 + varargin_1[3], y2BboxB->data[n]) -
          muDoubleScalarMax(1.0, varargin_2->data[n + varargin_2->size[0]]);
        if (!(h <= 0.0)) {
          i2 = areaB->size[0];
          k = n + 1;
          if (!((k >= 1) && (k <= i2))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i2, &emlrtBCI, &st);
          }

          i2 = overlapRatio->size[1];
          k = 1 + n;
          if (!((k >= 1) && (k <= i2))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i2, &n_emlrtBCI, &st);
          }

          overlapRatio->data[overlapRatio->size[0] * (k - 1)] = w * h /
            muDoubleScalarMin(areaA, areaB->data[n]);
        }
      }
    }

    emxFree_real_T(&st, &areaB);
    emxFree_real_T(&st, &y2BboxB);
    emxFree_real_T(&st, &x2BboxB);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void validateAndParseInputsCodegen(const emlrtStack *sp, const emxArray_real_T
  *varargin_1, const emxArray_real_T *varargin_2)
{
  emxArray_boolean_T *b_varargin_1;
  int32_T loop_ub;
  int32_T i6;
  boolean_T guard1 = false;
  boolean_T b1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &b_varargin_1, 1, &ab_emlrtRTEI, true);
  st.site = &u_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  validateattributes(&b_st, varargin_1);
  loop_ub = varargin_1->size[0];
  i6 = b_varargin_1->size[0];
  b_varargin_1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(&st, b_varargin_1, i6, &ab_emlrtRTEI);
  for (i6 = 0; i6 < loop_ub; i6++) {
    b_varargin_1->data[i6] = (varargin_1->data[i6 + (varargin_1->size[0] << 1)] <=
      0.0);
  }

  guard1 = false;
  b_st.site = &y_emlrtRSI;
  if (any(&b_st, b_varargin_1)) {
    guard1 = true;
  } else {
    loop_ub = varargin_1->size[0];
    i6 = b_varargin_1->size[0];
    b_varargin_1->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T(&st, b_varargin_1, i6, &bb_emlrtRTEI);
    for (i6 = 0; i6 < loop_ub; i6++) {
      b_varargin_1->data[i6] = (varargin_1->data[i6 + varargin_1->size[0] * 3] <=
        0.0);
    }

    b_st.site = &y_emlrtRSI;
    if (any(&b_st, b_varargin_1)) {
      guard1 = true;
    }
  }

  if (guard1) {
    emlrtErrorWithMessageIdR2018a(&st, &pb_emlrtRTEI,
      "vision:visionlib:invalidBboxHeightWidth",
      "vision:visionlib:invalidBboxHeightWidth", 0);
  }

  st.site = &v_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  validateattributes(&b_st, varargin_2);
  loop_ub = varargin_2->size[0];
  i6 = b_varargin_1->size[0];
  b_varargin_1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(&st, b_varargin_1, i6, &ab_emlrtRTEI);
  for (i6 = 0; i6 < loop_ub; i6++) {
    b_varargin_1->data[i6] = (varargin_2->data[i6 + (varargin_2->size[0] << 1)] <=
      0.0);
  }

  b_st.site = &y_emlrtRSI;
  if (any(&b_st, b_varargin_1)) {
    b1 = true;
  } else {
    loop_ub = varargin_2->size[0];
    i6 = b_varargin_1->size[0];
    b_varargin_1->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T(&st, b_varargin_1, i6, &bb_emlrtRTEI);
    for (i6 = 0; i6 < loop_ub; i6++) {
      b_varargin_1->data[i6] = (varargin_2->data[i6 + varargin_2->size[0] * 3] <=
        0.0);
    }

    b_st.site = &y_emlrtRSI;
    if (any(&b_st, b_varargin_1)) {
      b1 = true;
    } else {
      b1 = false;
    }
  }

  emxFree_boolean_T(&st, &b_varargin_1);
  if (b1) {
    emlrtErrorWithMessageIdR2018a(&st, &pb_emlrtRTEI,
      "vision:visionlib:invalidBboxHeightWidth",
      "vision:visionlib:invalidBboxHeightWidth", 0);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (bboxOverlapRatio.c) */
