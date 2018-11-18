#ifndef AUDIOCOMPRESSOR_API_PROCESS_H
#define AUDIOCOMPRESSOR_API_PROCESS_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "AudioCompressor_API_types.h"

/* Function Declarations */
extern void AudioCompressor_API_Process(compressor *drc_Band_instance, const
  float drcDataIn[256], float drcDataOut[256], float drcBufferout_2[256]);

#endif

