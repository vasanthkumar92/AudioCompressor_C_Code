#include "rt_nonfinite.h"
#include "VPA_DRC_SingleBand_API.h"
//#include "SystemCore.h"
#include "compressor.h"
#include "CompressorBase.h"
#include "VPA_DRC_SingleBand_API_initialize.h"
#include "main.h"
#include "VPA_DRC_SingleBand_API_Process.h"


/* Function Definitions */

/*
 * global  dRC_Band1
 *
 *  if(init == 1)
 * Arguments    : const struct0_T *param_Band1
 *                const float drcDataIn[256]
 *                float Fs
 *                float init
 *                float drcDataOut[256]
 * Return Type  : void
 */

extern compressor dRC_Band1;

void VPA_DRC_SingleBand_API(const struct0_T DRC_B1_Param, float drcDataIn[256], float Fs, float init, float StreamChang, float drcDataOut[256],int Bypass)
{
	if (Bypass == 1)
	{
		int i;

		for (i = 0; i < 256; i++)
		{
			drcDataOut[i] = drcDataIn[i];
		}

	}
	else
	{
		float drcBufferout_2[256];

		VPA_DRC_SingleBand_API_initialize(&DRC_B1_Param, &dRC_Band1, drcDataIn, Fs, init, StreamChang, drcDataOut);

		VPA_DRC_SingleBand_API_Process(&dRC_Band1, drcDataIn, drcDataOut, drcBufferout_2);
	}

}
