#ifndef COMPRESSORBAS_H
#define COMPRESSORBAS_H

/* Include Files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "AudioCompressor_API_types.h"
#include "VPA_DRC_SingleBand_API_Process.h"

/* Function Declarations */
extern void VPA_DRC_SingleBand_API_Process(compressor *obj, const float x[256], float
	y[256], float G[256]);

#endif

