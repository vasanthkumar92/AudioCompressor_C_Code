#ifndef AUDIOCOMPRESSOR_API_INITIALIZE_H
#define AUDIOCOMPRESSOR_API_INITIALIZE_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "AudioCompressor_API_types.h"

/* Function Declarations */
extern void AudioCompressor_API_initialize(const struct0_T *param_Band1, compressor *drc_Band_instance, float Fs, float init);

#endif
