

/* Include Files */
#include "rt_nonfinite.h"
#include "AudioCompressor_API.h"
#include "AudioCompressor_API_Process.h"
#include "CompressorBase.h"
#include "compressor.h"

/* Function Declarations */
static void CompressorBase_detectLevel(compressor *obj, const float x[256],
  float yout[256]);
//static float rt_powf_snf(float u0, float u1);

/* Function Definitions */

/*
 * Arguments    : compressor *obj
 *                const float x[256]
 *                float yout[256]
 * Return Type  : void
 */


float rt_powf_snf(float u0, float u1)
{
	float y;
	float f5;
	float f6;
	if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
		y = ((real32_T)rtNaN);
	}
	else {
		f5 = (float)fabs(u0);
		f6 = (float)fabs(u1);
		if (rtIsInfF(u1)) {
			if (f5 == 1.0F) {
				y = 1.0F;
			}
			else if (f5 > 1.0F) {
				if (u1 > 0.0F) {
					y = ((real32_T)rtInf);
				}
				else {
					y = 0.0F;
				}
			}
			else if (u1 > 0.0F) {
				y = 0.0F;
			}
			else {
				y = ((real32_T)rtInf);
			}
		}
		else if (f6 == 0.0F) {
			y = 1.0F;
		}
		else if (f6 == 1.0F) {
			if (u1 > 0.0F) {
				y = u0;
			}
			else {
				y = 1.0F / u0;
			}
		}
		else if (u1 == 2.0F) {
			y = u0 * u0;
		}
		else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
			y = (float)sqrt(u0);
		}
		else if ((u0 < 0.0F) && (u1 >(float)floor(u1))) {
			y = ((real32_T)rtNaN);
		}
		else {
			y = (float)pow(u0, u1);
		}
	}

	return y;
}


static void CompressorBase_detectLevel(compressor *obj, const float x[256],
  float yout[256])
{
  float y[257];
  float alphaA;
  float alphaR;
  int i;
  memset(&y[0], 0, 257U * sizeof(float));
  y[0] = obj->pLevelDetectionState;
  alphaA = obj->pAlphaA;
  alphaR = obj->pAlphaR;
  for (i = 0; i < 256; i++) {
    if (x[i] <= y[i]) {
      y[i + 1] = alphaA * y[i] + (1.0F - alphaA) * x[i];
    } else {
      y[i + 1] = alphaR * y[i] + (1.0F - alphaR) * x[i];
    }

    yout[i] = y[i + 1];
  }

  obj->pLevelDetectionState = y[256];
}

/*
 * Arguments    : float u0
 *                float u1
 * Return Type  : float
 */

/*
 * Arguments    : compressor *obj
 *                const float x[256]
 *                float y[256]
 *                float G[256]
 * Return Type  : void
 */
void CompressorBase_stepImpl(compressor *obj, const float x[256], float y[256],
  float G[256])
{
  int k;
  float b_G[256];
  float b_y;
  for (k = 0; k < 256; k++) {
    b_y = (float)fabs(x[k]);
    if (!(b_y > 1.1920929E-7F)) {
      b_y = 1.1920929E-7F;
    }

    b_G[k] = 20.0F * (float)log10(b_y);
  }

  compressor_computeGain(obj, b_G, G);
  memcpy(&b_G[0], &G[0], sizeof(float) << 8);
  CompressorBase_detectLevel(obj, b_G, G);
  for (k = 0; k < 256; k++) {
    b_y = G[k] + obj->pMakeUpGain;
    G[k] = b_y;
  }

  for (k = 0; k < 256; k++) {
    y[k] = x[k] * rt_powf_snf(10.0F, G[k] / 20.0F);
  }
}


