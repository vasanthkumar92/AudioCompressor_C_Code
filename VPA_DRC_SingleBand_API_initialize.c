#include "rt_nonfinite.h"
#include "VPA_DRC_SingleBand_API.h"
#include "VPA_DRC_SingleBand_API_initialize.h"
//#include "SystemCore.h"
#include "compressor.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void VPA_DRC_SingleBand_API_initialize(const struct0_T *param_Band1, compressor *dRC_Band1,const float drcDataIn[256], float Fs, float init, float StreamChang, float drcDataOut[256])
{
    rt_InitInfAndNaN(8U);
	boolean_T flag;
	float unusedU0[256];
	float B;
	
	if (init == 1.0) {
		compressor_compressor(&dRC_Band1, param_Band1->Threshold,
			param_Band1->comp_ratio, param_Band1->KneeWidth,
			param_Band1->AttackTime, param_Band1->ReleaseTime, Fs);
		flag = (dRC_Band1->isInitialized == 1);
		if (flag)
		{
			dRC_Band1->TunablePropsChanged = true;
		}

		dRC_Band1->MakeUpGain = param_Band1->MakeUpGain;
		/*  end */

	///////////////////////////////////////SystemCore_parenReference initialization/////////////////////////////////
		
		if (dRC_Band1->isInitialized != 1) 
		{
			dRC_Band1->isInitialized = 1;
			if (StreamChang == 1.0)
			{
				dRC_Band1->pLevelDetectionState = 0.0F;
			}

			Fs = dRC_Band1->pSampleRateDialog;
			if (dRC_Band1->AttackTime != 0.0F) {
				B = dRC_Band1->AttackTime * Fs;
				dRC_Band1->pAlphaA = (float)exp(-2.19722462F / B);
			}
			else {
				dRC_Band1->pAlphaA = 0.0F;
			}

			if (dRC_Band1->ReleaseTime != 0.0F) {
				B = dRC_Band1->ReleaseTime * Fs;
				dRC_Band1->pAlphaR = (float)exp(-2.19722462F / B);
			}
			else {
				dRC_Band1->pAlphaR = 0.0F;
			}

			dRC_Band1->pNumChannels = 1.0;
			dRC_Band1->pMakeUpGain = dRC_Band1->MakeUpGain;
			dRC_Band1->TunablePropsChanged = false;
			if (StreamChang == 1.0)
			{
				dRC_Band1->pLevelDetectionState = 0.0F;
			}
			
			Fs = dRC_Band1->pSampleRateDialog;
			if (dRC_Band1->AttackTime != 0.0F) {
				B = dRC_Band1->AttackTime * Fs;
				dRC_Band1->pAlphaA = (float)exp(-2.19722462F / B);
			}
			else {
				dRC_Band1->pAlphaA = 0.0F;
			}

			if (dRC_Band1->ReleaseTime != 0.0F) {
				B = dRC_Band1->ReleaseTime * Fs;
				dRC_Band1->pAlphaR = (float)exp(-2.19722462F / B);
			}
			else {
				dRC_Band1->pAlphaR = 0.0F;
			}
		}

		if (dRC_Band1->TunablePropsChanged) {
			dRC_Band1->TunablePropsChanged = false;
			Fs = dRC_Band1->pSampleRateDialog;
			if (dRC_Band1->AttackTime != 0.0F) {
				B = dRC_Band1->AttackTime * Fs;
				dRC_Band1->pAlphaA = (float)exp(-2.19722462F / B);
			}
			else {
				dRC_Band1->pAlphaA = 0.0F;
			}

			if (dRC_Band1->ReleaseTime != 0.0F) {
				B = dRC_Band1->ReleaseTime * Fs;
				dRC_Band1->pAlphaR = (float)exp(-2.19722462F / B);
			}
			else {
				dRC_Band1->pAlphaR = 0.0F;
			}

			dRC_Band1->pMakeUpGain = dRC_Band1->MakeUpGain;
		}
	}

}
















