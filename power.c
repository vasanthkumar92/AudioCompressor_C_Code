/* Include Files */
#include "rt_nonfinite.h"
#include "AudioCompressor_API.h"
#include "power.h"

/* Function Definitions */

/*
 * Arguments    : const float a_data[]
 *                const int a_size[1]
 *                float y_data[]
 *                int y_size[1]
 * Return Type  : void
 */
void power(const float a_data[], const int a_size[1], float y_data[], int
           y_size[1])
{
  int k;
  y_size[0] = (short)a_size[0];
  for (k = 0; k + 1 <= (short)a_size[0]; k++) {
    y_data[k] = a_data[k] * a_data[k];
  }
}

