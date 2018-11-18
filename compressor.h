
#ifndef COMPRESSOR_H
#define COMPRESSOR_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "AudioCompressor_API_types.h"

extern void compressor_compressor(compressor **obj, float varargin_2, float
	varargin_4, float varargin_6, float varargin_8, float varargin_10, float
	varargin_14);
/* Function Declarations */
extern void compressor_computeGain(const compressor *obj, const float xG[256],
  float G[256]);

#endif
