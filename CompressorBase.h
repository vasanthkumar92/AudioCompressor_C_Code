
#ifndef COMPRESSORBASE_H
#define COMPRESSORBASE_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "AudioCompressor_API_types.h"

/* Function Declarations */
extern float rt_powf_snf(float u0, float u1);

extern void CompressorBase_stepImpl(compressor *obj, const float x[256], float
  y[256], float G[256]);

#endif

