
#ifndef POWER_H
#define POWER_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "AudioCompressor_API_types.h"

/* Function Declarations */
extern void power(const float a_data[], const int a_size[1], float y_data[], int
                  y_size[1]);

#endif
