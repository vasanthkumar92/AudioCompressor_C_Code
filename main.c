/*************************************************************************/
/* Include Files */
#include "stdio.h"
#include "main.h"
#include "AudioCompressor_API.h"


/****** Global Variables for the Audio Compressor ******/
#define FRAME_SIZE_MONO 256

float drcDataIn[FRAME_SIZE_MONO];
float drcDataOut[FRAME_SIZE_MONO];
short int DRC_OPbuffMono[FRAME_SIZE_MONO];

FILE *infile;
FILE *outfile, *outfilewav;


/* Function Declarations for getdata */
static void VPA_DRC_API_GetData_Input(float result[FRAME_SIZE_MONO]);


/* Function Definition for getdata */
static void VPA_DRC_API_GetData_Input(float result[FRAME_SIZE_MONO])
{
	int idx0;
	short int buff16 = 0;

	for (idx0 = 0; idx0 < FRAME_SIZE_MONO; idx0++) {
		int l = fread(&buff16, 2, 1, infile);
		//Fixed to float conversion
		result[idx0] = (float)buff16 *3.0517578125e-05;
	}
}



/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  float Fs;
  float init = 1.0;
  
  /* Compressor Parameters in a structure */
  struct0_T DRC_B1_Param;

  /* Tunable Parameters */
  DRC_B1_Param.Threshold = -24;
  DRC_B1_Param.comp_ratio = 4;
  DRC_B1_Param.AttackTime = 1e-3;
  DRC_B1_Param.ReleaseTime = 10e-3;
  DRC_B1_Param.KneeWidth = 0;
  DRC_B1_Param.MakeUpGain = 0;

  /*****************************************************************/
 

  /* Reading the wave file */
  fopen_s(&infile, "file_example_WAV_1MG_mono.wav", "rb");			
  fopen_s(&outfilewav, "file_example_WAV_1MG_mono_Output.wav", "wb");

  /* Metadata for the wave file */
  header_p meta = (header_p)malloc(sizeof(header));
  fread(meta, 1, sizeof(header), infile);
  Fs = meta->sample_rate;

  /* Loop runs till end of the file */
  while ((!feof(infile)))
  {
	  /* DataIN to Input buffer with chunk size 256*/
	  VPA_DRC_API_GetData_Input(drcDataIn);

	  /*Main AudioCompressor API */
	  AudioCompressor_API(DRC_B1_Param, drcDataIn, Fs, init, drcDataOut);
	  
	  init = 0.0;

	  /* Dataout to output buffer*/
	  for (int i = 0; i < 256; i++) {
		  DRC_OPbuffMono[i] = drcDataOut[i] * 32768;

	  }

	  /* Writing the data to the file for bit matching */
	  fwrite(DRC_OPbuffMono, 2, FRAME_SIZE_MONO, outfilewav);

  }
  return 0;
}
