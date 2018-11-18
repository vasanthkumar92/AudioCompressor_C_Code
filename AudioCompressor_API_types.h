#ifndef AUDIOCOMPRESSOR_API_TYPES_H
#define AUDIOCOMPRESSOR_API_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3

typedef struct {
  unsigned int f1[8];
} cell_wrap_3;

#endif                                 /*typedef_cell_wrap_3*/

#ifndef typedef_compressor
#define typedef_compressor

typedef struct {
  int isInitialized;
  boolean_T TunablePropsChanged;
  cell_wrap_3 inputVarSize[1];
  float pSampleRateDialog;
  float Threshold;
  float AttackTime;
  float ReleaseTime;
  double pNumChannels;
  float pAlphaA;
  float pAlphaR;
  float pLevelDetectionState;
  float MakeUpGain;
  float KneeWidth;
  float pMakeUpGain;
  float Ratio;
} compressor;

#endif                                 /*typedef_compressor*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  float Threshold;
  float comp_ratio;
  float KneeWidth;
  float AttackTime;
  float ReleaseTime;
  float MakeUpGain;
} struct0_T;

#endif                                 /*typedef_struct0_T*/
#endif

