/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * score_func_data.c
 *
 * Code generation for function 'score_func_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "score_func.h"
#include "score_func_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131466U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "score_func",                        /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 4093231316U, 3755654364U, 1605221666U, 2449470297U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo s_emlrtRSI = { 59,         /* lineNo */
  "bboxOverlapRatio",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pathName */
};

emlrtRSInfo t_emlrtRSI = { 78,         /* lineNo */
  "bboxOverlapRatio",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pathName */
};

emlrtRSInfo x_emlrtRSI = { 70,         /* lineNo */
  "validateattributes",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 21,        /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo eb_emlrtRSI = { 134,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

emlrtRSInfo fb_emlrtRSI = { 193,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combineVectorElements.m"/* pathName */
};

emlrtRTEInfo g_emlrtRTEI = { 59,       /* lineNo */
  6,                                   /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtRTEInfo h_emlrtRTEI = { 59,       /* lineNo */
  13,                                  /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtRTEInfo j_emlrtRTEI = { 176,      /* lineNo */
  1,                                   /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtRTEInfo k_emlrtRTEI = { 177,      /* lineNo */
  1,                                   /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtRTEInfo l_emlrtRTEI = { 181,      /* lineNo */
  1,                                   /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtRTEInfo n_emlrtRTEI = { 182,      /* lineNo */
  1,                                   /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtRTEInfo o_emlrtRTEI = { 185,      /* lineNo */
  1,                                   /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtRTEInfo p_emlrtRTEI = { 186,      /* lineNo */
  1,                                   /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtBCInfo emlrtBCI = { -1,           /* iFirst */
  -1,                                  /* iLast */
  213,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo b_emlrtBCI = { -1,         /* iFirst */
  -1,                                  /* iLast */
  213,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo c_emlrtBCI = { -1,         /* iFirst */
  -1,                                  /* iLast */
  196,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo d_emlrtBCI = { -1,         /* iFirst */
  -1,                                  /* iLast */
  196,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo e_emlrtBCI = { -1,         /* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo f_emlrtBCI = { -1,         /* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo g_emlrtBCI = { -1,         /* iFirst */
  -1,                                  /* iLast */
  194,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo h_emlrtBCI = { -1,         /* iFirst */
  -1,                                  /* iLast */
  194,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo i_emlrtBCI = { -1,         /* iFirst */
  -1,                                  /* iLast */
  193,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m",/* pName */
  0                                    /* checkKind */
};

emlrtBCInfo j_emlrtBCI = { -1,         /* iFirst */
  -1,                                  /* iLast */
  193,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m",/* pName */
  0                                    /* checkKind */
};

emlrtECInfo emlrtECI = { -1,           /* nDims */
  186,                                 /* lineNo */
  9,                                   /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtECInfo b_emlrtECI = { -1,         /* nDims */
  185,                                 /* lineNo */
  9,                                   /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtECInfo c_emlrtECI = { -1,         /* nDims */
  182,                                 /* lineNo */
  11,                                  /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtECInfo d_emlrtECI = { -1,         /* nDims */
  181,                                 /* lineNo */
  11,                                  /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtECInfo e_emlrtECI = { -1,         /* nDims */
  177,                                 /* lineNo */
  11,                                  /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtECInfo f_emlrtECI = { -1,         /* nDims */
  176,                                 /* lineNo */
  11,                                  /* colNo */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m"/* pName */
};

emlrtBCInfo n_emlrtBCI = { -1,         /* iFirst */
  -1,                                  /* iLast */
  213,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bboxOverlapRatio",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\vision\\vision\\bboxOverlapRatio.m",/* pName */
  0                                    /* checkKind */
};

emlrtRTEInfo qb_emlrtRTEI = { 13,      /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

/* End of code generation (score_func_data.c) */
