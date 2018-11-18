/* Include Files */
#include "rt_nonfinite.h"
#include "AudioCompressor_API_initialize.h"
#include "compressor.h"
/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void AudioCompressor_API_initialize(const struct0_T *param_Band1, compressor *drc_Band_instance, float Fs, float init)
{
	rt_InitInfAndNaN(8U);
	float varargout_2[256];
	float B;
	if( init == 1.0 )

	compressor_compressor(&drc_Band_instance, param_Band1->Threshold,
			param_Band1->comp_ratio, param_Band1->KneeWidth,
			param_Band1->AttackTime, param_Band1->ReleaseTime, Fs);

	if (drc_Band_instance->isInitialized != 1) {
		drc_Band_instance->isInitialized = 1;
		drc_Band_instance->pLevelDetectionState = 0.0F;
		Fs = drc_Band_instance->pSampleRateDialog;
		if (drc_Band_instance->AttackTime != 0.0F) {
			B = drc_Band_instance->AttackTime * Fs;
			drc_Band_instance->pAlphaA = (float)exp(-2.19722462F / B);
		}
		else {
			drc_Band_instance->pAlphaA = 0.0F;
		}

		if (drc_Band_instance->ReleaseTime != 0.0F) {
			B = drc_Band_instance->ReleaseTime * Fs;
			drc_Band_instance->pAlphaR = (float)exp(-2.19722462F / B);
		}
		else {
			drc_Band_instance->pAlphaR = 0.0F;
		}

		drc_Band_instance->pNumChannels = 1.0;
		drc_Band_instance->pMakeUpGain = drc_Band_instance->MakeUpGain;
		drc_Band_instance->TunablePropsChanged = false;
		drc_Band_instance->pLevelDetectionState = 0.0F;
		Fs = drc_Band_instance->pSampleRateDialog;
		if (drc_Band_instance->AttackTime != 0.0F) {
			B = drc_Band_instance->AttackTime * Fs;
			drc_Band_instance->pAlphaA = (float)exp(-2.19722462F / B);
		}
		else {
			drc_Band_instance->pAlphaA = 0.0F;
		}

		if (drc_Band_instance->ReleaseTime != 0.0F) {
			B = drc_Band_instance->ReleaseTime * Fs;
			drc_Band_instance->pAlphaR = (float)exp(-2.19722462F / B);
		}
		else {
			drc_Band_instance->pAlphaR = 0.0F;
		}
	}

	if (drc_Band_instance->TunablePropsChanged) {
		drc_Band_instance->TunablePropsChanged = false;
		Fs = drc_Band_instance->pSampleRateDialog;
		if (drc_Band_instance->AttackTime != 0.0F) {
			B = drc_Band_instance->AttackTime * Fs;
			drc_Band_instance->pAlphaA = (float)exp(-2.19722462F / B);
		}
		else {
			drc_Band_instance->pAlphaA = 0.0F;
		}

		if (drc_Band_instance->ReleaseTime != 0.0F) {
			B = drc_Band_instance->ReleaseTime * Fs;
			drc_Band_instance->pAlphaR = (float)exp(-2.19722462F / B);
		}
		else {
			drc_Band_instance->pAlphaR = 0.0F;
		}

		drc_Band_instance->pMakeUpGain = drc_Band_instance->MakeUpGain;
	}
}
