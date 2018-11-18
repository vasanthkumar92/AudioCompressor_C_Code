/* Include Files */
#include "rt_nonfinite.h"
#include "AudioCompressor_API.h"
#include "compressor.h"
#include "power.h"
#include "abs.h"

/* Function Definitions */

/*
 * Arguments    : const compressor *obj
 *                const float xG[256]
 *                float G[256]
 * Return Type  : void
 */

void compressor_compressor(compressor **obj, float varargin_2, float varargin_4,
	float varargin_6, float varargin_8, float varargin_10, float varargin_14)
{
	boolean_T flag;
	(*obj)->pNumChannels = -1.0;
	(*obj)->isInitialized = 0;
	flag = ((*obj)->isInitialized == 1);
	if (flag)
	{
		(*obj)->TunablePropsChanged = true;
	}

	(*obj)->Threshold = varargin_2;
	flag = ((*obj)->isInitialized == 1);
	if (flag)
	{
		(*obj)->TunablePropsChanged = true;
	}

	(*obj)->Ratio = varargin_4;
	flag = ((*obj)->isInitialized == 1);
	if (flag)
	{
		(*obj)->TunablePropsChanged = true;
	}

	(*obj)->KneeWidth = varargin_6;
	flag = ((*obj)->isInitialized == 1);
	if (flag)
	{
		(*obj)->TunablePropsChanged = true;
	}

	(*obj)->AttackTime = varargin_8;
	flag = ((*obj)->isInitialized == 1);
	if (flag)
	{
		(*obj)->TunablePropsChanged = true;
	}

	(*obj)->ReleaseTime = varargin_10;
	flag = ((*obj)->isInitialized == 1);
	if (flag)
	{
		(*obj)->TunablePropsChanged = true;
	}

	(*obj)->pSampleRateDialog = varargin_14;
}


void compressor_computeGain(const compressor *obj, const float xG[256], float G
  [256])
{
  float W;
  float R;
  float T;
  int trueCount;
  int i;
  int partialTrueCount;
  boolean_T ind2;
  boolean_T b_ind2[256];
  short tmp_data[256];
  float b_data[256];
  float xG_data[256];
  float y;
  short b_tmp_data[256];
  int xG_size[1];
  int b_size[1];
  W = obj->KneeWidth;
  R = obj->Ratio;
  T = obj->Threshold;
  trueCount = 0;
  for (i = 0; i < 256; i++) {
    G[i] = xG[i];
    ind2 = (2.0F * (xG[i] - T) > W);
    if (ind2) {
      trueCount++;
    }

    b_ind2[i] = ind2;
  }

  partialTrueCount = 0;
  for (i = 0; i < 256; i++) {
    if (b_ind2[i]) {
      tmp_data[partialTrueCount] = (short)(i + 1);
      partialTrueCount++;
    }
  }

  for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++) {
    b_data[partialTrueCount] = (xG[tmp_data[partialTrueCount] - 1] - T) / R;
  }

  partialTrueCount = 0;
  for (i = 0; i < 256; i++) {
    if (b_ind2[i]) {
      G[i] = T + b_data[partialTrueCount];
      partialTrueCount++;
    }
  }

  if (W != 0.0F) {
    for (i = 0; i < 256; i++) {
      b_data[i] = xG[i] - T;
    }

    b_abs(b_data, xG_data);
    trueCount = 0;
    for (i = 0; i < 256; i++) {
      ind2 = (2.0F * xG_data[i] <= W);
      if (ind2) {
        trueCount++;
      }

      b_ind2[i] = ind2;
    }

    partialTrueCount = 0;
    for (i = 0; i < 256; i++) {
      if (b_ind2[i]) {
        b_tmp_data[partialTrueCount] = (short)(i + 1);
        partialTrueCount++;
      }
    }

    y = W / 2.0F;
    R = 1.0F / R - 1.0F;
    xG_size[0] = trueCount;
    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      xG_data[partialTrueCount] = (xG[b_tmp_data[partialTrueCount] - 1] - T) + y;
    }

    power(xG_data, xG_size, b_data, b_size);
    y = 2.0F * W;
    i = b_size[0];
    for (partialTrueCount = 0; partialTrueCount < i; partialTrueCount++) {
      b_data[partialTrueCount] = R * b_data[partialTrueCount] / y;
    }

    partialTrueCount = 0;
    for (i = 0; i < 256; i++) {
      if (b_ind2[i]) {
        G[i] = xG[i] + b_data[partialTrueCount];
        partialTrueCount++;
      }
    }
  }

  for (partialTrueCount = 0; partialTrueCount < 256; partialTrueCount++) {
    G[partialTrueCount] -= xG[partialTrueCount];
  }
}

