/* Include files */

#include "simulator_sfun.h"
#include "c5_simulator.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtRSInfo c5_emlrtRSI = { 48, /* lineNo */
  "rgb2gray",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\images\\rgb2gray.m"/* pathName */
};

static emlrtRSInfo c5_b_emlrtRSI = { 4,/* lineNo */
  "MATLAB Function2",                  /* fcnName */
  "#simulator:104"                     /* pathName */
};

/* Function Declarations */
static void initialize_c5_simulator(SFc5_simulatorInstanceStruct *chartInstance);
static void initialize_params_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance);
static void mdl_start_c5_simulator(SFc5_simulatorInstanceStruct *chartInstance);
static void mdl_terminate_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance);
static void mdl_setup_runtime_resources_c5_simulator
  (SFc5_simulatorInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c5_simulator
  (SFc5_simulatorInstanceStruct *chartInstance);
static void enable_c5_simulator(SFc5_simulatorInstanceStruct *chartInstance);
static void disable_c5_simulator(SFc5_simulatorInstanceStruct *chartInstance);
static void sf_gateway_c5_simulator(SFc5_simulatorInstanceStruct *chartInstance);
static void ext_mode_exec_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance);
static void c5_update_jit_animation_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance);
static void c5_do_animation_call_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance);
static void set_sim_state_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void initSimStructsc5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance);
static void initSubchartIOPointersc5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance);
static void c5_emlrt_marshallIn(SFc5_simulatorInstanceStruct *chartInstance,
  const mxArray *c5_b_image_gray, const char_T *c5_identifier, uint8_T c5_y
  [921600]);
static void c5_b_emlrt_marshallIn(SFc5_simulatorInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, uint8_T c5_y
  [921600]);
static uint8_T c5_c_emlrt_marshallIn(SFc5_simulatorInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_simulator, const char_T *c5_identifier);
static uint8_T c5_d_emlrt_marshallIn(SFc5_simulatorInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_slStringInitializeDynamicBuffers(SFc5_simulatorInstanceStruct
  *chartInstance);
static void c5_chart_data_browse_helper(SFc5_simulatorInstanceStruct
  *chartInstance, int32_T c5_ssIdNumber, const mxArray **c5_mxData, uint8_T
  *c5_isValueTooBig);
static void init_dsm_address_info(SFc5_simulatorInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc5_simulatorInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_simulator(SFc5_simulatorInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_simulator = 0U;
}

static void initialize_params_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c5_simulator(SFc5_simulatorInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c5_simulator
  (SFc5_simulatorInstanceStruct *chartInstance)
{
  static const uint32_T c5_decisionTxtEndIdx = 0U;
  static const uint32_T c5_decisionTxtStartIdx = 0U;
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)&c5_chart_data_browse_helper);
  chartInstance->c5_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c5_RuntimeVar,
    &chartInstance->c5_IsDebuggerActive,
    &chartInstance->c5_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c5_mlFcnLineNumber, &chartInstance->c5_IsHeatMapPresent, 0);
  covrtCreateStateflowInstanceData(chartInstance->c5_covrtInstance, 1U, 0U, 1U,
    19U);
  covrtChartInitFcn(chartInstance->c5_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c5_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c5_decisionTxtStartIdx, &c5_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c5_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c5_covrtInstance, "", 4U, 0U, 1U, 0U, 0U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U,
                     "eML_blk_kernel", 0, -1, 82);
}

static void mdl_cleanup_runtime_resources_c5_simulator
  (SFc5_simulatorInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c5_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c5_covrtInstance);
}

static void enable_c5_simulator(SFc5_simulatorInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_simulator(SFc5_simulatorInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c5_simulator(SFc5_simulatorInstanceStruct *chartInstance)
{
  int32_T c5_i;
  int32_T c5_i1;
  chartInstance->c5_JITTransitionAnimation[0] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c5_i = 0; c5_i < 2764800; c5_i++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 0U, (real_T)
                      (*chartInstance->c5_image)[c5_i]);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c5_covrtInstance, 4U, 0, 0);
  rgb2gray_tbb_uint8(&(*chartInstance->c5_image)[0], 921600.0,
                     &(*chartInstance->c5_image_gray)[0], true);
  c5_do_animation_call_c5_simulator(chartInstance);
  for (c5_i1 = 0; c5_i1 < 921600; c5_i1++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 1U, (real_T)
                      (*chartInstance->c5_image_gray)[c5_i1]);
  }
}

static void ext_mode_exec_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_update_jit_animation_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_do_animation_call_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static const mxArray *get_sim_state_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance)
{
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(2, 1), false);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", *chartInstance->c5_image_gray, 3, 0U,
    1U, 0U, 2, 720, 1280), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y",
    &chartInstance->c5_is_active_c5_simulator, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  int32_T c5_i;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
                      "image_gray", chartInstance->c5_uv);
  for (c5_i = 0; c5_i < 921600; c5_i++) {
    (*chartInstance->c5_image_gray)[c5_i] = chartInstance->c5_uv[c5_i];
  }

  chartInstance->c5_is_active_c5_simulator = c5_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 1)), "is_active_c5_simulator");
  sf_mex_destroy(&c5_u);
  sf_mex_destroy(&c5_st);
}

static void initSimStructsc5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSubchartIOPointersc5_simulator(SFc5_simulatorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

const mxArray *sf_c5_simulator_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static void c5_emlrt_marshallIn(SFc5_simulatorInstanceStruct *chartInstance,
  const mxArray *c5_b_image_gray, const char_T *c5_identifier, uint8_T c5_y
  [921600])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_image_gray), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_b_image_gray);
}

static void c5_b_emlrt_marshallIn(SFc5_simulatorInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, uint8_T c5_y
  [921600])
{
  int32_T c5_i;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), chartInstance->c5_b_uv, 1, 3, 0U,
                1, 0U, 2, 720, 1280);
  for (c5_i = 0; c5_i < 921600; c5_i++) {
    c5_y[c5_i] = chartInstance->c5_b_uv[c5_i];
  }

  sf_mex_destroy(&c5_u);
}

static uint8_T c5_c_emlrt_marshallIn(SFc5_simulatorInstanceStruct *chartInstance,
  const mxArray *c5_b_is_active_c5_simulator, const char_T *c5_identifier)
{
  emlrtMsgIdentifier c5_thisId;
  uint8_T c5_y;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_simulator), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_simulator);
  return c5_y;
}

static uint8_T c5_d_emlrt_marshallIn(SFc5_simulatorInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_b_u;
  uint8_T c5_y;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_b_u, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_b_u;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_slStringInitializeDynamicBuffers(SFc5_simulatorInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_chart_data_browse_helper(SFc5_simulatorInstanceStruct
  *chartInstance, int32_T c5_ssIdNumber, const mxArray **c5_mxData, uint8_T
  *c5_isValueTooBig)
{
  (void)chartInstance;
  *c5_mxData = NULL;
  *c5_isValueTooBig = 0U;
  switch (c5_ssIdNumber) {
   case 4U:
    *c5_isValueTooBig = 1U;
    break;

   case 5U:
    *c5_isValueTooBig = 1U;
    break;
  }
}

static void init_dsm_address_info(SFc5_simulatorInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_simulatorInstanceStruct *chartInstance)
{
  chartInstance->c5_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c5_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c5_image = (uint8_T (*)[2764800])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_image_gray = (uint8_T (*)[921600])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c5_simulator_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1523543049U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3659039458U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(377644085U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1812838055U);
}

mxArray *sf_c5_simulator_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2grayBuildable"));
  return(mxcell3p);
}

mxArray *sf_c5_simulator_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("rgb2gray_tbb_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c5_simulator_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_simulator(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPhDBxMDABqQ4IEwwYIXyGaFijHBxFri4AhCXVBakgsSLi5I9U4B0XmIumJ9YWuG"
    "Zl5YPNt+CAWE+GxbzGZHM54SKQ8AHe8r0iziA9Dsg6WfBop8LSb8AlJ+Zm5ieGp9elFgJEedjQN"
    "Dku0fBgTL9EPs9CPhHDM0/IH5mcXxicklmWWp8sml8cWZuaU5iSX4Rwl8Av90bYA=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_simulator_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "szg0mWr7HUDoGBt6W6HxaOD";
}

static void sf_opaque_initialize_c5_simulator(void *chartInstanceVar)
{
  initialize_params_c5_simulator((SFc5_simulatorInstanceStruct*)
    chartInstanceVar);
  initialize_c5_simulator((SFc5_simulatorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_simulator(void *chartInstanceVar)
{
  enable_c5_simulator((SFc5_simulatorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_simulator(void *chartInstanceVar)
{
  disable_c5_simulator((SFc5_simulatorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_simulator(void *chartInstanceVar)
{
  sf_gateway_c5_simulator((SFc5_simulatorInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_simulator(SimStruct* S)
{
  return get_sim_state_c5_simulator((SFc5_simulatorInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_simulator(SimStruct* S, const mxArray *st)
{
  set_sim_state_c5_simulator((SFc5_simulatorInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c5_simulator(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_simulatorInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_simulator_optimization_info();
    }

    mdl_cleanup_runtime_resources_c5_simulator((SFc5_simulatorInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c5_simulator(void *chartInstanceVar)
{
  mdl_start_c5_simulator((SFc5_simulatorInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc5_simulatorInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c5_simulator(void *chartInstanceVar)
{
  mdl_terminate_c5_simulator((SFc5_simulatorInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_simulator(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_simulator((SFc5_simulatorInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSubchartIOPointersc5_simulator((SFc5_simulatorInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c5_simulator_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrtWFtv40QUnkalYpel2ge0CAmJfeQFqSzaZSUQ2+a2DWpphdNW4qWa2Cf2KOMZ71xyWSHeeeO",
    "JV/4CP4OfwM/gCSHxwhnbyYY0NJ4Eyi7CkuOM7W/OOd+c25hsdY4JHrt4fvcOITt4fR3PGimO18",
    "rx1txZ3N8mn5bjr98gJJQRxCAC2++zMfE7hE1PqaKpJv6HoCl8CVpya5gUHdGX1bFM9EGBCHGCT",
    "CrjJVez1HImBm0rQidZXyQsTIJEWh7VcUIanQg++Su5mTWnKLHJFISmDRCZREkbJ21O4+tZUGbU",
    "SCAcaJt6c6XBBDZzpupjyw3LOLTGEHaENhRZ0CvsDQw10DBjP5KdvTqYomWacUZFda4TqgPI0Ds",
    "MnGUR/p5Yg+xVwoYJVaYOCR2CPmKDXLoUUEk60/h2jwlqpGKUt1LecLNVtPeUo43HGBLcd43Q3r",
    "oCOsgkE8YzIII28twStMehCT0be8oN4Jl10XDOYATKb337DTkERWM4EX4652vUGudOOYuliljDU",
    "jin6iBE39UQ+eUNDDodUHRH6OI0XljIKe7ormJD9A3fXNdx4b9WrrNp4f16LWwutzUEb7+ayW2H",
    "okE5137YrsyOYAg8l9+khq6BLeR7gLVmUVeid7hs45mxrGAYCSW2IUXEqnvlcAGVF7YvsEhVgLP",
    "UhQFESPNM9dlEq+LIaiPTBqac5tFRRXlXsR1hQPVpCJVrjKJMAyqc+5Wn3IhpF0iIRpZMbmXlGY",
    "oYXAtKdN+K5kiqAXLsW8xecOUiwQ8NUYyJ2UCe5Fro3eeU24o6pzrG+EH3ONOYZf3kItbFz1rgk",
    "IYJRK5yMg7HmGdxgqpLrF3JP0Brh8xMmqBDxbKqkWQxoWPRdSx1JxmciYGQI9FWMg3KzusavwLA",
    "rEGVYCKuYwlXkzYqX01rBc+6eXb3bXIcz9Rw2nO+8RQEVkNnq+saaIhR1RLYIqNCm2AD9hybGKG",
    "ZNlioJ0WpL+qe69/3yYv+fXtJ/35nrn+/W47Dh5d5K+v6nOk8e3Pz3KmwD6iCI1dwZIabXt+fw2",
    "8tkUvmrovybtWu17OG/7aW8PTmgpztBdzOlKtPfv/+yQ/fmN63nw9+tY9/2kT+jzW/fdZuOX532",
    "i/NsvPwSgJz7x6u8IO3F/zAjfXzeC+9UB8fnjXl07p5dPHocExPmsX6rNC3tqDv9P5916Nh8Oa5",
    "QIWdqNyvuTG1xT7Czf94Tt+dFXzcmvMnQn55shn+rf0qcXN7ga/bea3GRHgZKzq56sfr63N/fzN",
    "8tfW/t2DPvbyHv6QuU8PlnzPC7t8Qb744csO4V0XP/3n55+2rUu9uGkduGLepfb51/FV/f++afE",
    "sW3r/7EtuxeF23n3vZ7PqZ+PVb75Xjz2bfERoJ49GSnUz5GDcb/WVP/yP+/Zsnf9P+suX4Kz84f",
    "/XRgaB8gluXYmtY3j5V7rvh7JECqpfvD/+NerLJvmrERCRH+oMPHzx8sEl9+gNJQxkh",
    ""
  };

  static char newstr [1493] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c5_simulator(SimStruct *S)
{
  const char* newstr = sf_c5_simulator_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2533047052U));
  ssSetChecksum1(S,(1954455359U));
  ssSetChecksum2(S,(1800046946U));
  ssSetChecksum3(S,(3359143414U));
}

static void mdlRTW_c5_simulator(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c5_simulator(SimStruct *S)
{
  SFc5_simulatorInstanceStruct *chartInstance;
  chartInstance = (SFc5_simulatorInstanceStruct *)utMalloc(sizeof
    (SFc5_simulatorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc5_simulatorInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_simulator;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_simulator;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c5_simulator;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c5_simulator;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c5_simulator;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_simulator;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_simulator;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_simulator;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_simulator;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_simulator;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_simulator;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_simulator;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c5_JITStateAnimation,
    chartInstance->c5_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c5_simulator(chartInstance);
}

void c5_simulator_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c5_simulator(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_simulator(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_simulator(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_simulator_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
