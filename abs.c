
/* Include Files */
#include "rt_nonfinite.h"
#include "AudioCompressor_API.h"
#include "abs.h"

/* Function Definitions */

/*
 * Arguments    : const float x[256]
 *                float y[256]
 * Return Type  : void
*/
void b_abs(const float x[256], float y[256])
{
  int k;
  for (k = 0; k < 256; k++) {
    y[k] = (float)fabs(x[k]);
  }
}
