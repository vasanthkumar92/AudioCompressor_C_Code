#ifndef AUDIOCOMPRESSOR_API_H
#define AUDIOCOMPRESSOR_API_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "AudioCompressor_API_types.h"

/* Function Declarations */
extern void AudioCompressor_API(const struct0_T DRC_B1_Param, const float
  drcDataIn[256], float Fs, float init, float drcDataOut[256]);

#endif

