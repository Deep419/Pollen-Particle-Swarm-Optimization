/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * score_func.c
 *
 * Code generation for function 'score_func'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "score_func.h"
#include "score_func_emxutil.h"
#include "mean.h"
#include "eml_int_forloop_overflow_check.h"
#include "error.h"
#include "bboxOverlapRatio.h"
#include "rdivide.h"
#include "sum.h"
#include "triu.h"
#include "score_func_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7,     /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 19,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 21,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 42,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 55,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 56,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 57,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 58,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 60,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 65,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 66,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 68,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 72,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 87,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 89,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 90,  /* lineNo */
  "score_func",                        /* fcnName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 22,  /* lineNo */
  "reshape",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 54,  /* lineNo */
  "reshape",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 98, /* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 290,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 13, /* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 19, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 49, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 128,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 259,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 331,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 432,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 431,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 428,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 12, /* lineNo */
  "toLogicalCheck",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 41, /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 153,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 377,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 397,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 18, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 23,  /* lineNo */
  1,                                   /* colNo */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 82,/* lineNo */
  5,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 91,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 58,/* lineNo */
  27,                                  /* colNo */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 98,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 57,/* lineNo */
  9,                                   /* colNo */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 65,/* lineNo */
  1,                                   /* colNo */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 331,/* lineNo */
  14,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 89,/* lineNo */
  23,                                  /* colNo */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 153,/* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 41,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 90,/* lineNo */
  17,                                  /* colNo */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 19,/* lineNo */
  1,                                   /* colNo */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 58,/* lineNo */
  1,                                   /* colNo */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 33,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 387,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 77,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 61,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 46,/* lineNo */
  19,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 61,/* lineNo */
  15,                                  /* colNo */
  "reshape",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"/* pName */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  47,                                  /* colNo */
  "param_overlap_iou",                 /* aName */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  45,                                  /* colNo */
  "param_overlap_iou",                 /* aName */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  26,                                  /* colNo */
  "params",                            /* aName */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  90,                                  /* lineNo */
  30,                                  /* colNo */
  "max_row_wise",                      /* aName */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  5,                                   /* colNo */
  "ar_score",                          /* aName */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  9,                                   /* colNo */
  "ar_score",                          /* aName */
  "score_func",                        /* fName */
  "C:\\Research\\pollen\\particle-swarm-pollen\\score_func.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void score_func(const emlrtStack *sp, real_T r, real_T c, const emxArray_real_T *
                gt, real_T verify, const emxArray_real_T *params, real_T s_data[],
                int32_T s_size[2])
{
  real_T numBoxes;
  real_T varargin_1[2];
  int32_T nx;
  int32_T idx;
  boolean_T exitg1;
  real_T ndbl;
  int32_T i0;
  int32_T n;
  int32_T num[2];
  int32_T maxdimlen;
  emxArray_real_T *inside_score;
  real_T dv0[4];
  int32_T sz[2];
  emxArray_real_T b_params;
  real_T b_inside_score;
  emxArray_real_T *param_overlap_iou;
  real_T avg_ar_score;
  int32_T i1;
  int32_T b_sz[2];
  int32_T c_sz[2];
  emxArray_real_T c_params;
  real_T apnd;
  uint32_T absa;
  emxArray_real_T *b_param_overlap_iou;
  emxArray_real_T *x2BboxA;
  emxArray_real_T *c_inside_score;
  emxArray_real_T *param_overlap_means;
  emxArray_real_T *bboxA;
  real_T scores_idx_1;
  emxArray_real_T *bboxB;
  emxArray_real_T *gt_param_iou;
  emxArray_real_T *x2BboxB;
  emxArray_real_T *y2BboxB;
  emxArray_real_T *areaA;
  emxArray_real_T *areaB;
  boolean_T overflow;
  int32_T b_gt_param_iou[1];
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_int32_T *r0;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  numBoxes = (real_T)params->size[1] / 4.0;

  /*  img = zeros(r,c,'uint8'); */
  st.site = &emlrtRSI;
  varargin_1[0] = numBoxes;
  varargin_1[1] = 4.0;
  nx = params->size[1];
  b_st.site = &q_emlrtRSI;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 2)) {
    if (varargin_1[idx] != muDoubleScalarFloor(varargin_1[idx])) {
      emlrtErrorWithMessageIdR2018a(&b_st, &mb_emlrtRTEI,
        "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector",
        "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
        MIN_int32_T, 12, MAX_int32_T);
      exitg1 = true;
    } else {
      idx++;
    }
  }

  ndbl = 1.0;
  for (idx = 0; idx < 2; idx++) {
    if (varargin_1[idx] <= 0.0) {
      ndbl = 0.0;
    } else {
      ndbl *= varargin_1[idx];
    }
  }

  if (!(ndbl <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &lb_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      "Coder:MATLAB:pmaxsize", 0);
  }

  for (i0 = 0; i0 < 2; i0++) {
    num[i0] = (int32_T)varargin_1[i0];
  }

  n = 1;
  if (params->size[1] > 1) {
    n = params->size[1];
  }

  maxdimlen = muIntScalarMax_sint32(nx, n);
  if (num[0] > maxdimlen) {
    b_st.site = &r_emlrtRSI;
    error(&b_st);
  }

  if (4 > maxdimlen) {
    b_st.site = &r_emlrtRSI;
    error(&b_st);
  }

  if (num[0] << 2 != params->size[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &nb_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  emxInit_real_T(&st, &inside_score, 2, &v_emlrtRTEI, true);

  /*  color = jet(numBoxes); */
  /*  I = insertShape(img,'rectangle',params,'color',color*255,'LineWidth',3); */
  /*  imshow(insertShape(I,'rectangle',gt,'color','green','LineWidth',3)); */
  /*  1. Make sure params boxes are inside image */
  /*  inside_score = visionBboxIntersectByMin([1 1 r c],params); */
  dv0[0] = 1.0;
  dv0[1] = 1.0;
  dv0[2] = r;
  dv0[3] = c;
  sz[0] = (int32_T)numBoxes;
  sz[1] = 4;
  b_params = *params;
  b_params.size = (int32_T *)&sz;
  b_params.numDimensions = 1;
  st.site = &b_emlrtRSI;
  bboxOverlapRatio(&st, dv0, &b_params, inside_score);
  st.site = &c_emlrtRSI;
  b_inside_score = 1.0 - mean(&st, inside_score);
  i0 = inside_score->size[0] * inside_score->size[1];
  inside_score->size[0] = 1;
  emxEnsureCapacity_real_T(sp, inside_score, i0, &emlrtRTEI);
  i0 = inside_score->size[0] * inside_score->size[1];
  inside_score->size[1] = (int32_T)numBoxes;
  emxEnsureCapacity_real_T(sp, inside_score, i0, &emlrtRTEI);
  idx = (int32_T)numBoxes;
  for (i0 = 0; i0 < idx; i0++) {
    inside_score->data[i0] = 1.0;
  }

  nx = 0;
  while (nx <= (int32_T)numBoxes - 1) {
    i0 = (int32_T)numBoxes;
    i1 = 1 + nx;
    if (!(i1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &m_emlrtBCI, sp);
    }

    /*  Linear Function */
    i0 = inside_score->size[1];
    i1 = 1 + nx;
    if (!(i1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &p_emlrtBCI, sp);
    }

    inside_score->data[i1 - 1] = -1.0101010101010102 * (muDoubleScalarMin
      (params->data[nx + ((int32_T)numBoxes << 1)], params->data[nx + (int32_T)
       numBoxes * 3]) / muDoubleScalarMax(params->data[nx + ((int32_T)numBoxes <<
      1)], params->data[nx + (int32_T)numBoxes * 3])) + 1.0101010101010102;

    /* Guassian Function 1 */
    /*      ar_score(i) = 1.271988*exp(-((ar-(-0.1128002))^2)/(2*0.1626162^2)); */
    /* Guassian Function 2 */
    /*      ar_score(i) = 1.235046*exp(-((ar-(-0.04674503))^2)/(2*0.07193964^2)); */
    /*  high score for ar more than 5, less than 0.2, width less than 100 and height less than 100 */
    /*      if ar > 5 || ar < 0.2 || */
    if ((params->data[nx + (num[0] << 1)] < 100.0) || (params->data[nx + num[0] *
         3] < 100.0)) {
      i0 = inside_score->size[1];
      i1 = 1 + nx;
      if (!(i1 <= i0)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &q_emlrtBCI, sp);
      }

      inside_score->data[i1 - 1] = 1000.0;
    }

    nx++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_real_T(sp, &param_overlap_iou, 2, &w_emlrtRTEI, true);
  st.site = &d_emlrtRSI;
  avg_ar_score = mean(&st, inside_score);

  /* calc area = area(polyshape(bbox2points(params(1,:)))); */
  /* calc intersction area = rectint(params(1,:),params(3,:)); */
  /*  2 Minimize Proposed box Overlap : range [0 1] */
  /*  for i=1:size(params,1) */
  /*      img(params(i,1):params(i,1)+params(i,3),params(i,1):params(i,1)+params(i,3))=img(params(i,1):params(i,1)+params(i,3),params(i,1):params(i,1)+params(i,3))+1; */
  /*  end */
  /*  param_overlap_iou = visionBboxIntersectByMin(params,params); */
  b_sz[0] = (int32_T)numBoxes;
  b_sz[1] = 4;
  c_sz[0] = (int32_T)numBoxes;
  c_sz[1] = 4;
  b_params = *params;
  b_params.size = (int32_T *)&b_sz;
  b_params.numDimensions = 1;
  c_params = *params;
  c_params.size = (int32_T *)&c_sz;
  c_params.numDimensions = 1;
  st.site = &e_emlrtRSI;
  b_bboxOverlapRatio(&st, &b_params, &c_params, param_overlap_iou);
  st.site = &f_emlrtRSI;
  triu(&st, param_overlap_iou);
  st.site = &g_emlrtRSI;
  if ((real_T)param_overlap_iou->size[0] - 1.0 < 1.0) {
    i0 = inside_score->size[0] * inside_score->size[1];
    inside_score->size[0] = 1;
    inside_score->size[1] = 0;
    emxEnsureCapacity_real_T(&st, inside_score, i0, &b_emlrtRTEI);
  } else if ((real_T)param_overlap_iou->size[0] - 1.0 == (real_T)
             param_overlap_iou->size[0] - 1.0) {
    ndbl = (real_T)param_overlap_iou->size[0] - 1.0;
    i0 = inside_score->size[0] * inside_score->size[1];
    inside_score->size[0] = 1;
    inside_score->size[1] = (int32_T)-(1.0 - ndbl) + 1;
    emxEnsureCapacity_real_T(&st, inside_score, i0, &c_emlrtRTEI);
    idx = (int32_T)-(1.0 - ndbl);
    for (i0 = 0; i0 <= idx; i0++) {
      inside_score->data[inside_score->size[0] * i0] = ndbl - (real_T)i0;
    }
  } else {
    b_st.site = &ib_emlrtRSI;
    ndbl = muDoubleScalarFloor((1.0 - ((real_T)param_overlap_iou->size[0] - 1.0))
      / -1.0 + 0.5);
    apnd = ((real_T)param_overlap_iou->size[0] - 1.0) + -ndbl;
    absa = (uint32_T)muDoubleScalarAbs((real_T)param_overlap_iou->size[0] - 1.0);
    if (muDoubleScalarAbs(1.0 - apnd) < 4.4408920985006262E-16 * (real_T)
        muIntScalarMax_uint32(absa, 1U)) {
      ndbl++;
      apnd = 1.0;
    } else if (1.0 - apnd > 0.0) {
      apnd = ((real_T)param_overlap_iou->size[0] - 1.0) + -(ndbl - 1.0);
    } else {
      ndbl++;
    }

    n = (int32_T)ndbl;
    i0 = inside_score->size[0] * inside_score->size[1];
    inside_score->size[0] = 1;
    inside_score->size[1] = n;
    emxEnsureCapacity_real_T(&b_st, inside_score, i0, &e_emlrtRTEI);
    if (n > 0) {
      inside_score->data[0] = (real_T)param_overlap_iou->size[0] - 1.0;
      if (n > 1) {
        inside_score->data[n - 1] = apnd;
        maxdimlen = (n - 1) / 2;
        c_st.site = &jb_emlrtRSI;
        for (idx = 1; idx < maxdimlen; idx++) {
          inside_score->data[idx] = ((real_T)param_overlap_iou->size[0] - 1.0) +
            -(real_T)idx;
          inside_score->data[(n - idx) - 1] = apnd - (-(real_T)idx);
        }

        if (maxdimlen << 1 == n - 1) {
          inside_score->data[maxdimlen] = (((real_T)param_overlap_iou->size[0] -
            1.0) + apnd) / 2.0;
        } else {
          inside_score->data[maxdimlen] = ((real_T)param_overlap_iou->size[0] -
            1.0) + -(real_T)maxdimlen;
          inside_score->data[maxdimlen + 1] = apnd - (-(real_T)maxdimlen);
        }
      }
    }
  }

  if (1.0 > (real_T)param_overlap_iou->size[0] - 1.0) {
    idx = 0;
  } else {
    i0 = param_overlap_iou->size[0];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &l_emlrtBCI, sp);
    }

    i0 = param_overlap_iou->size[0];
    idx = (int32_T)((real_T)param_overlap_iou->size[0] - 1.0);
    if (!((idx >= 1) && (idx <= i0))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i0, &k_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &b_param_overlap_iou, 2, &d_emlrtRTEI, true);
  maxdimlen = param_overlap_iou->size[1];
  i0 = b_param_overlap_iou->size[0] * b_param_overlap_iou->size[1];
  b_param_overlap_iou->size[0] = idx;
  b_param_overlap_iou->size[1] = maxdimlen;
  emxEnsureCapacity_real_T(sp, b_param_overlap_iou, i0, &d_emlrtRTEI);
  for (i0 = 0; i0 < maxdimlen; i0++) {
    for (i1 = 0; i1 < idx; i1++) {
      b_param_overlap_iou->data[i1 + b_param_overlap_iou->size[0] * i0] =
        param_overlap_iou->data[i1 + param_overlap_iou->size[0] * i0];
    }
  }

  emxFree_real_T(sp, &param_overlap_iou);
  emxInit_real_T1(sp, &x2BboxA, 1, &j_emlrtRTEI, true);
  emxInit_real_T1(sp, &c_inside_score, 1, &f_emlrtRTEI, true);
  st.site = &h_emlrtRSI;
  sum(&st, b_param_overlap_iou, x2BboxA);
  i0 = c_inside_score->size[0];
  c_inside_score->size[0] = inside_score->size[1];
  emxEnsureCapacity_real_T1(sp, c_inside_score, i0, &f_emlrtRTEI);
  idx = inside_score->size[1];
  emxFree_real_T(sp, &b_param_overlap_iou);
  for (i0 = 0; i0 < idx; i0++) {
    c_inside_score->data[i0] = inside_score->data[inside_score->size[0] * i0];
  }

  emxFree_real_T(sp, &inside_score);
  emxInit_real_T1(sp, &param_overlap_means, 1, &x_emlrtRTEI, true);
  emxInit_real_T(sp, &bboxA, 2, &g_emlrtRTEI, true);
  st.site = &h_emlrtRSI;
  rdivide(&st, x2BboxA, c_inside_score, param_overlap_means);
  st.site = &i_emlrtRSI;
  scores_idx_1 = b_mean(&st, param_overlap_means);

  /*  3 Maximize GT Coverage : range [0 1] */
  /*  gt_param_iou = visionBboxIntersectByMin(gt,params); */
  st.site = &j_emlrtRSI;
  i0 = bboxA->size[0] * bboxA->size[1];
  bboxA->size[0] = gt->size[0];
  bboxA->size[1] = 4;
  emxEnsureCapacity_real_T(&st, bboxA, i0, &g_emlrtRTEI);
  idx = gt->size[0] * gt->size[1];
  for (i0 = 0; i0 < idx; i0++) {
    bboxA->data[i0] = gt->data[i0];
  }

  emxInit_real_T(&st, &bboxB, 2, &h_emlrtRTEI, true);
  i0 = bboxB->size[0] * bboxB->size[1];
  bboxB->size[0] = (int32_T)numBoxes;
  bboxB->size[1] = 4;
  emxEnsureCapacity_real_T(&st, bboxB, i0, &h_emlrtRTEI);
  idx = (int32_T)numBoxes << 2;
  for (i0 = 0; i0 < idx; i0++) {
    bboxB->data[i0] = params->data[i0];
  }

  b_st.site = &s_emlrtRSI;
  validateAndParseInputsCodegen(&b_st, bboxA, bboxB);
  emxInit_real_T(&st, &gt_param_iou, 2, &i_emlrtRTEI, true);
  emxInit_real_T1(&st, &x2BboxB, 1, &l_emlrtRTEI, true);
  emxInit_real_T1(&st, &y2BboxB, 1, &n_emlrtRTEI, true);
  emxInit_real_T1(&st, &areaA, 1, &o_emlrtRTEI, true);
  emxInit_real_T1(&st, &areaB, 1, &p_emlrtRTEI, true);
  if ((bboxA->size[0] == 0) || (bboxB->size[0] == 0)) {
    i0 = gt_param_iou->size[0] * gt_param_iou->size[1];
    gt_param_iou->size[0] = bboxA->size[0];
    gt_param_iou->size[1] = bboxB->size[0];
    emxEnsureCapacity_real_T(&st, gt_param_iou, i0, &i_emlrtRTEI);
    idx = bboxA->size[0] * bboxB->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      gt_param_iou->data[i0] = 0.0;
    }
  } else {
    b_st.site = &t_emlrtRSI;
    i0 = bboxA->size[0];
    i1 = bboxA->size[0];
    if (i0 != i1) {
      emlrtSizeEqCheck1DR2012b(i0, i1, &f_emlrtECI, &b_st);
    }

    idx = bboxA->size[0];
    i0 = x2BboxA->size[0];
    x2BboxA->size[0] = idx;
    emxEnsureCapacity_real_T1(&b_st, x2BboxA, i0, &j_emlrtRTEI);
    for (i0 = 0; i0 < idx; i0++) {
      x2BboxA->data[i0] = bboxA->data[i0] + bboxA->data[i0 + (bboxA->size[0] <<
        1)];
    }

    i0 = bboxA->size[0];
    i1 = bboxA->size[0];
    if (i0 != i1) {
      emlrtSizeEqCheck1DR2012b(i0, i1, &e_emlrtECI, &b_st);
    }

    idx = bboxA->size[0];
    i0 = param_overlap_means->size[0];
    param_overlap_means->size[0] = idx;
    emxEnsureCapacity_real_T1(&b_st, param_overlap_means, i0, &k_emlrtRTEI);
    for (i0 = 0; i0 < idx; i0++) {
      param_overlap_means->data[i0] = bboxA->data[i0 + bboxA->size[0]] +
        bboxA->data[i0 + bboxA->size[0] * 3];
    }

    i0 = bboxB->size[0];
    i1 = bboxB->size[0];
    if (i0 != i1) {
      emlrtSizeEqCheck1DR2012b(i0, i1, &d_emlrtECI, &b_st);
    }

    idx = bboxB->size[0];
    i0 = x2BboxB->size[0];
    x2BboxB->size[0] = idx;
    emxEnsureCapacity_real_T1(&b_st, x2BboxB, i0, &l_emlrtRTEI);
    for (i0 = 0; i0 < idx; i0++) {
      x2BboxB->data[i0] = bboxB->data[i0] + bboxB->data[i0 + (bboxB->size[0] <<
        1)];
    }

    i0 = bboxB->size[0];
    i1 = bboxB->size[0];
    if (i0 != i1) {
      emlrtSizeEqCheck1DR2012b(i0, i1, &c_emlrtECI, &b_st);
    }

    idx = bboxB->size[0];
    i0 = y2BboxB->size[0];
    y2BboxB->size[0] = idx;
    emxEnsureCapacity_real_T1(&b_st, y2BboxB, i0, &n_emlrtRTEI);
    for (i0 = 0; i0 < idx; i0++) {
      y2BboxB->data[i0] = bboxB->data[i0 + bboxB->size[0]] + bboxB->data[i0 +
        bboxB->size[0] * 3];
    }

    i0 = bboxA->size[0];
    i1 = bboxA->size[0];
    if (i0 != i1) {
      emlrtSizeEqCheck1DR2012b(i0, i1, &b_emlrtECI, &b_st);
    }

    idx = bboxA->size[0];
    i0 = areaA->size[0];
    areaA->size[0] = idx;
    emxEnsureCapacity_real_T1(&b_st, areaA, i0, &o_emlrtRTEI);
    for (i0 = 0; i0 < idx; i0++) {
      areaA->data[i0] = bboxA->data[i0 + (bboxA->size[0] << 1)] * bboxA->data[i0
        + bboxA->size[0] * 3];
    }

    i0 = bboxB->size[0];
    i1 = bboxB->size[0];
    if (i0 != i1) {
      emlrtSizeEqCheck1DR2012b(i0, i1, &emlrtECI, &b_st);
    }

    idx = bboxB->size[0];
    i0 = areaB->size[0];
    areaB->size[0] = idx;
    emxEnsureCapacity_real_T1(&b_st, areaB, i0, &p_emlrtRTEI);
    for (i0 = 0; i0 < idx; i0++) {
      areaB->data[i0] = bboxB->data[i0 + (bboxB->size[0] << 1)] * bboxB->data[i0
        + bboxB->size[0] * 3];
    }

    i0 = gt_param_iou->size[0] * gt_param_iou->size[1];
    gt_param_iou->size[0] = bboxA->size[0];
    gt_param_iou->size[1] = bboxB->size[0];
    emxEnsureCapacity_real_T(&b_st, gt_param_iou, i0, &i_emlrtRTEI);
    idx = bboxA->size[0] * bboxB->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      gt_param_iou->data[i0] = 0.0;
    }

    for (idx = 0; idx < bboxA->size[0]; idx++) {
      for (n = 0; n < bboxB->size[0]; n++) {
        i0 = bboxA->size[0];
        i1 = idx + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &j_emlrtBCI, &b_st);
        }

        i0 = bboxB->size[0];
        i1 = n + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &i_emlrtBCI, &b_st);
        }

        i0 = bboxA->size[0];
        i1 = idx + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &h_emlrtBCI, &b_st);
        }

        i0 = bboxB->size[0];
        i1 = n + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &g_emlrtBCI, &b_st);
        }

        i0 = x2BboxA->size[0];
        i1 = idx + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &f_emlrtBCI, &b_st);
        }

        i0 = x2BboxB->size[0];
        i1 = n + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &e_emlrtBCI, &b_st);
        }

        i0 = param_overlap_means->size[0];
        i1 = idx + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &d_emlrtBCI, &b_st);
        }

        i0 = y2BboxB->size[0];
        i1 = n + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &c_emlrtBCI, &b_st);
        }

        ndbl = muDoubleScalarMin(x2BboxA->data[idx], x2BboxB->data[n]) -
          muDoubleScalarMax(bboxA->data[idx], bboxB->data[n]);
        if (!(ndbl <= 0.0)) {
          apnd = muDoubleScalarMin(param_overlap_means->data[idx], y2BboxB->
            data[n]) - muDoubleScalarMax(bboxA->data[idx + bboxA->size[0]],
            bboxB->data[n + bboxB->size[0]]);
          if (!(apnd <= 0.0)) {
            i0 = areaA->size[0];
            i1 = idx + 1;
            if (!((i1 >= 1) && (i1 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &b_emlrtBCI, &b_st);
            }

            i0 = areaB->size[0];
            i1 = n + 1;
            if (!((i1 >= 1) && (i1 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &emlrtBCI, &b_st);
            }

            i0 = gt_param_iou->size[0];
            i1 = 1 + idx;
            if (!((i1 >= 1) && (i1 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &n_emlrtBCI, &b_st);
            }

            i0 = gt_param_iou->size[1];
            maxdimlen = 1 + n;
            if (!((maxdimlen >= 1) && (maxdimlen <= i0))) {
              emlrtDynamicBoundsCheckR2012b(maxdimlen, 1, i0, &n_emlrtBCI, &b_st);
            }

            gt_param_iou->data[(i1 + gt_param_iou->size[0] * (maxdimlen - 1)) -
              1] = ndbl * apnd / muDoubleScalarMin(areaA->data[idx], areaB->
              data[n]);
          }
        }
      }
    }
  }

  emxFree_real_T(&st, &areaB);
  emxFree_real_T(&st, &areaA);
  emxFree_real_T(&st, &y2BboxB);
  emxFree_real_T(&st, &x2BboxB);
  emxFree_real_T(&st, &bboxB);
  emxFree_real_T(&st, &bboxA);
  emxFree_real_T(&st, &param_overlap_means);
  st.site = &k_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  c_st.site = &pb_emlrtRSI;
  d_st.site = &qb_emlrtRSI;
  if (!(gt_param_iou->size[1] >= 1)) {
    emlrtErrorWithMessageIdR2018a(&d_st, &kb_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &rb_emlrtRSI;
  f_st.site = &sb_emlrtRSI;
  g_st.site = &tb_emlrtRSI;
  idx = gt_param_iou->size[0];
  absa = (uint32_T)gt_param_iou->size[0];
  i0 = x2BboxA->size[0];
  x2BboxA->size[0] = (int32_T)absa;
  emxEnsureCapacity_real_T1(&g_st, x2BboxA, i0, &m_emlrtRTEI);
  if (gt_param_iou->size[0] >= 1) {
    h_st.site = &wb_emlrtRSI;
    overflow = (gt_param_iou->size[0] > 2147483646);
    if (overflow) {
      i_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }

    for (nx = 0; nx < idx; nx++) {
      x2BboxA->data[nx] = gt_param_iou->data[nx];
    }

    h_st.site = &vb_emlrtRSI;
    for (maxdimlen = 1; maxdimlen < gt_param_iou->size[1]; maxdimlen++) {
      h_st.site = &ub_emlrtRSI;
      for (nx = 0; nx < idx; nx++) {
        overflow = ((!muDoubleScalarIsNaN(gt_param_iou->data[nx +
          gt_param_iou->size[0] * maxdimlen])) && (muDoubleScalarIsNaN
          (x2BboxA->data[nx]) || (x2BboxA->data[nx] < gt_param_iou->data[nx +
          gt_param_iou->size[0] * maxdimlen])));
        if (overflow) {
          x2BboxA->data[nx] = gt_param_iou->data[nx + gt_param_iou->size[0] *
            maxdimlen];
        }
      }
    }
  }

  st.site = &l_emlrtRSI;
  ndbl = 1.0 - b_mean(&st, x2BboxA);

  /*  4 Minimize Grain Cut : range [0 1] */
  b_gt_param_iou[0] = gt_param_iou->size[0] * gt_param_iou->size[1];
  b_params = *gt_param_iou;
  b_params.size = (int32_T *)&b_gt_param_iou;
  b_params.numDimensions = 1;
  st.site = &m_emlrtRSI;
  apnd = b_mean(&st, &b_params);
  emxFree_real_T(sp, &gt_param_iou);
  if (apnd < (real_T)gt->size[0] / ((real_T)gt->size[0] * numBoxes)) {
    apnd = 100.0;
  }

  /*  if cut_mean ~= 0 */
  /*      cut_mean = cut_mean / (size(gt,1)/(size(gt,1)*numBoxes)); */
  /*  end */
  /*  5 Maximize Box Size : range [0 1] */
  /*  s = (.1 * scores(1)) + (.5* scores(2)) + (.2* scores(3)) + (.3 * scores(4)); */
  s_size[0] = 1;
  s_size[1] = 1;
  s_data[0] = (((0.9 * b_inside_score + 0.1 * avg_ar_score) + 10.0 *
                scores_idx_1) + 2.0 * ndbl) + 10.0 * apnd;
  st.site = &n_emlrtRSI;
  if (muDoubleScalarIsNaN(verify)) {
    b_st.site = &xb_emlrtRSI;
    b_error(&b_st);
  }

  if (verify != 0.0) {
    s_size[0] = 1;
    s_size[1] = 2;
    for (i0 = 0; i0 < 2; i0++) {
      s_data[i0] = 0.0;
    }

    emxInit_boolean_T(sp, &x, 1, &q_emlrtRTEI, true);
    st.site = &o_emlrtRSI;
    i0 = x->size[0];
    x->size[0] = x2BboxA->size[0];
    emxEnsureCapacity_boolean_T(&st, x, i0, &q_emlrtRTEI);
    idx = x2BboxA->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      x->data[i0] = (x2BboxA->data[i0] != 0.0);
    }

    emxInit_int32_T(&st, &ii, 1, &y_emlrtRTEI, true);
    b_st.site = &yb_emlrtRSI;
    nx = x->size[0];
    c_st.site = &ac_emlrtRSI;
    idx = 0;
    i0 = ii->size[0];
    ii->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(&c_st, ii, i0, &r_emlrtRTEI);
    d_st.site = &bc_emlrtRSI;
    overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
    if (overflow) {
      e_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    maxdimlen = 1;
    exitg1 = false;
    while ((!exitg1) && (maxdimlen <= nx)) {
      if (x->data[maxdimlen - 1]) {
        idx++;
        ii->data[idx - 1] = maxdimlen;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          maxdimlen++;
        }
      } else {
        maxdimlen++;
      }
    }

    if (!(idx <= x->size[0])) {
      emlrtErrorWithMessageIdR2018a(&c_st, &jb_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (x->size[0] == 1) {
      if (idx == 0) {
        i0 = ii->size[0];
        ii->size[0] = 0;
        emxEnsureCapacity_int32_T(&c_st, ii, i0, &s_emlrtRTEI);
      }
    } else {
      if (1 > idx) {
        i0 = 0;
      } else {
        i0 = idx;
      }

      d_st.site = &cc_emlrtRSI;
      overflow = !(ii->size[0] != 1);
      if (overflow) {
        overflow = false;
        if (i0 != 1) {
          overflow = true;
        }

        if (overflow) {
          overflow = true;
        } else {
          overflow = false;
        }
      } else {
        overflow = false;
      }

      e_st.site = &dc_emlrtRSI;
      if (overflow) {
        emlrtErrorWithMessageIdR2018a(&e_st, &ib_emlrtRTEI,
          "Coder:FE:PotentialVectorVector", "Coder:FE:PotentialVectorVector", 0);
      }

      i1 = ii->size[0];
      ii->size[0] = i0;
      emxEnsureCapacity_int32_T(&c_st, ii, i1, &s_emlrtRTEI);
    }

    emxFree_boolean_T(&c_st, &x);
    s_data[0] = (real_T)ii->size[0] / (real_T)gt->size[0];
    idx = x2BboxA->size[0] - 1;
    maxdimlen = 0;
    emxFree_int32_T(sp, &ii);
    for (nx = 0; nx <= idx; nx++) {
      if (x2BboxA->data[nx] != 0.0) {
        maxdimlen++;
      }
    }

    emxInit_int32_T(sp, &r0, 1, &t_emlrtRTEI, true);
    i0 = r0->size[0];
    r0->size[0] = maxdimlen;
    emxEnsureCapacity_int32_T(sp, r0, i0, &t_emlrtRTEI);
    maxdimlen = 0;
    for (nx = 0; nx <= idx; nx++) {
      if (x2BboxA->data[nx] != 0.0) {
        r0->data[maxdimlen] = nx + 1;
        maxdimlen++;
      }
    }

    maxdimlen = x2BboxA->size[0];
    i0 = c_inside_score->size[0];
    c_inside_score->size[0] = r0->size[0];
    emxEnsureCapacity_real_T1(sp, c_inside_score, i0, &u_emlrtRTEI);
    idx = r0->size[0];
    for (i0 = 0; i0 < idx; i0++) {
      i1 = r0->data[i0];
      if (!((i1 >= 1) && (i1 <= maxdimlen))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, maxdimlen, &o_emlrtBCI, sp);
      }

      c_inside_score->data[i0] = x2BboxA->data[i1 - 1];
    }

    emxFree_int32_T(sp, &r0);
    st.site = &p_emlrtRSI;
    s_data[1] = b_mean(&st, c_inside_score);
  }

  emxFree_real_T(sp, &c_inside_score);
  emxFree_real_T(sp, &x2BboxA);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (score_func.c) */
