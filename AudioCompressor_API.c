/* Include Files */
#include "rt_nonfinite.h"
#include "main.h"
#include "compressor.h"
#include "CompressorBase.h"
#include "AudioCompressor_API.h"
#include "AudioCompressor_API_Process.h"
#include "AudioCompressor_API_initialize.h"
/* Function Definitions */

/*
 * Global variable for drc band parameters
 * global  drc_Band_instance
 * Arguments    : const struct0_T *DRC_B1_Param
 *                const float drcDataIn[256]
 *                float Fs
 *                float init
 *                float drcDataOut[256]
 * Return Type  : void
 */
compressor drc_Band_instance;

void AudioCompressor_API(const struct0_T DRC_B1_Param, const float drcDataIn[256],
  float Fs, float init, float drcDataOut[256])
{
  
  (void)init;

  float drcBufferout_2[256];
  
  /* Initialization routine of the compressor should be called only once */
  AudioCompressor_API_initialize(&DRC_B1_Param, &drc_Band_instance, Fs, init);
 
  /* AudioCompressor_API_Process : Main process of the audio compression  */
  /* Input Parameters: */
  /* drc_Band_instance : Compressor instance */
  /* drcDataIn         : Input samples of the audio */
  /* Output Parameters: */
  /* drcDataOut        : Processed output data */

  AudioCompressor_API_Process(&drc_Band_instance, drcDataIn, drcDataOut, drcBufferout_2);
}
