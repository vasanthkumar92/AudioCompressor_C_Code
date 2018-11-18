#ifndef VPA_DRC_SINGLEBAND_API_H
#define VPA_DRC_SINGLEBAND_API_H

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
 //void VPA_DRC_SingleBand_API(const struct0_T DRC_B1_Param, const float
 // drcDataIn[256], float Fs, float init,float StreamChang, float drcDataOut[256]);

void VPA_DRC_SingleBand_API(const struct0_T DRC_B1_Param, float drcDataIn[256], float Fs, float init, float StreamChang, float drcDataOut[256],int Bypass);

#endif
