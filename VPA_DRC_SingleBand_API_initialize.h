#ifndef VPA_DRC_SINGLEBAND_API_INITIALIZE_H
#define VPA_DRC_SINGLEBAND_API_INITIALIZE_H

/* Include Files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "AudioCompressor_API_types.h"

/* Function Declarations */
extern void VPA_DRC_SingleBand_API_initialize(const struct0_T *param_Band1, compressor *dRC_Band1, const float drcDataIn[256], float Fs, float init, float StreamChang, float drcDataOut[256]);

#endif

