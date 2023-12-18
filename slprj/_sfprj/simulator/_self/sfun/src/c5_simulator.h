#ifndef __c5_simulator_h__
#define __c5_simulator_h__

/* Forward Declarations */
#ifndef typedef_c5_cell_0
#define typedef_c5_cell_0

typedef struct c5_tag_lfyg79q6Kpk0jaJgYJuk8C c5_cell_0;

#endif                                 /* typedef_c5_cell_0 */

#ifndef typedef_c5_cell_wrap_1
#define typedef_c5_cell_wrap_1

typedef struct c5_tag_uwJsGEKtvfiUxcdf0z0AYH c5_cell_wrap_1;

#endif                                 /* typedef_c5_cell_wrap_1 */

#ifndef typedef_c5_s_WSTEAPgNJmllMDXoFTifcF
#define typedef_c5_s_WSTEAPgNJmllMDXoFTifcF

typedef struct c5_tag_WSTEAPgNJmllMDXoFTifcF c5_s_WSTEAPgNJmllMDXoFTifcF;

#endif                                 /* typedef_c5_s_WSTEAPgNJmllMDXoFTifcF */

#ifndef typedef_c5_s_MY3jsqmREaTzOC09vCGedD
#define typedef_c5_s_MY3jsqmREaTzOC09vCGedD

typedef struct c5_tag_MY3jsqmREaTzOC09vCGedD c5_s_MY3jsqmREaTzOC09vCGedD;

#endif                                 /* typedef_c5_s_MY3jsqmREaTzOC09vCGedD */

/* Type Definitions */
#ifndef struct_c5_tag_lfyg79q6Kpk0jaJgYJuk8C
#define struct_c5_tag_lfyg79q6Kpk0jaJgYJuk8C

struct c5_tag_lfyg79q6Kpk0jaJgYJuk8C
{
  char_T f1[5];
  char_T f2[6];
  char_T f3[6];
  char_T f4[6];
};

#endif                                 /* struct_c5_tag_lfyg79q6Kpk0jaJgYJuk8C */

#ifndef typedef_c5_cell_0
#define typedef_c5_cell_0

typedef struct c5_tag_lfyg79q6Kpk0jaJgYJuk8C c5_cell_0;

#endif                                 /* typedef_c5_cell_0 */

#ifndef struct_c5_tag_uwJsGEKtvfiUxcdf0z0AYH
#define struct_c5_tag_uwJsGEKtvfiUxcdf0z0AYH

struct c5_tag_uwJsGEKtvfiUxcdf0z0AYH
{
  char_T f1[4];
};

#endif                                 /* struct_c5_tag_uwJsGEKtvfiUxcdf0z0AYH */

#ifndef typedef_c5_cell_wrap_1
#define typedef_c5_cell_wrap_1

typedef struct c5_tag_uwJsGEKtvfiUxcdf0z0AYH c5_cell_wrap_1;

#endif                                 /* typedef_c5_cell_wrap_1 */

#ifndef struct_c5_tag_WSTEAPgNJmllMDXoFTifcF
#define struct_c5_tag_WSTEAPgNJmllMDXoFTifcF

struct c5_tag_WSTEAPgNJmllMDXoFTifcF
{
  c5_cell_0 _data;
};

#endif                                 /* struct_c5_tag_WSTEAPgNJmllMDXoFTifcF */

#ifndef typedef_c5_s_WSTEAPgNJmllMDXoFTifcF
#define typedef_c5_s_WSTEAPgNJmllMDXoFTifcF

typedef struct c5_tag_WSTEAPgNJmllMDXoFTifcF c5_s_WSTEAPgNJmllMDXoFTifcF;

#endif                                 /* typedef_c5_s_WSTEAPgNJmllMDXoFTifcF */

#ifndef struct_c5_tag_MY3jsqmREaTzOC09vCGedD
#define struct_c5_tag_MY3jsqmREaTzOC09vCGedD

struct c5_tag_MY3jsqmREaTzOC09vCGedD
{
  c5_cell_wrap_1 _data;
};

#endif                                 /* struct_c5_tag_MY3jsqmREaTzOC09vCGedD */

#ifndef typedef_c5_s_MY3jsqmREaTzOC09vCGedD
#define typedef_c5_s_MY3jsqmREaTzOC09vCGedD

typedef struct c5_tag_MY3jsqmREaTzOC09vCGedD c5_s_MY3jsqmREaTzOC09vCGedD;

#endif                                 /* typedef_c5_s_MY3jsqmREaTzOC09vCGedD */

#ifndef typedef_SFc5_simulatorInstanceStruct
#define typedef_SFc5_simulatorInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c5_sfEvent;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_simulator;
  uint8_T c5_JITStateAnimation[1];
  uint8_T c5_JITTransitionAnimation[1];
  int32_T c5_IsDebuggerActive;
  int32_T c5_IsSequenceViewerPresent;
  int32_T c5_SequenceViewerOptimization;
  int32_T c5_IsHeatMapPresent;
  void *c5_RuntimeVar;
  uint32_T c5_mlFcnLineNumber;
  void *c5_fcnDataPtrs[2];
  char_T *c5_dataNames[2];
  uint32_T c5_numFcnVars;
  uint32_T c5_ssIds[2];
  uint32_T c5_statuses[2];
  void *c5_outMexFcns[2];
  void *c5_inMexFcns[2];
  uint8_T c5_uv[921600];
  uint8_T c5_b_uv[921600];
  CovrtStateflowInstance *c5_covrtInstance;
  void *c5_fEmlrtCtx;
  uint8_T (*c5_image)[2764800];
  uint8_T (*c5_image_gray)[921600];
} SFc5_simulatorInstanceStruct;

#endif                                 /* typedef_SFc5_simulatorInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_simulator_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_simulator_get_check_sum(mxArray *plhs[]);
extern void c5_simulator_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
