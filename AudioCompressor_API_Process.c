/* Include Files */
#include "rt_nonfinite.h"
#include "AudioCompressor_API.h"
#include "AudioCompressor_API_Process.h"
#include "CompressorBase.h"
#include "compressor.h"

/* Function Declarations */
static void CompressorBase_detectLevel(compressor *obj, const float x[256],
	float yout[256]);

/* Function Definitions */

/*
* Arguments    : compressor *obj
*                const float x[256]
*                float yout[256]
* Return Type  : void
*/
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
		}
		else {
			y[i + 1] = alphaR * y[i] + (1.0F - alphaR) * x[i];
		}

		yout[i] = y[i + 1];
	}

	obj->pLevelDetectionState = y[256];
}


/* Function Definitions */

/*
 * Arguments    : compressor *drc_Band_instance
 *                const float drcDataIn[256]
 *                float drcDataOut[256]
 * Return Type  : void
 */


void AudioCompressor_API_Process(compressor *obj, const float
  x[256], float y[256], float G[256])
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
