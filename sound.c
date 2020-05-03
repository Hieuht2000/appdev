#include <stdio.h>
#include <math.h>
#include "sound.h"
#include "screen.h"
#include "comm.h"

// function definitions
WAVheader readwavhdr(FILE *fp){
	WAVheader myh;
	fread(&myh, sizeof(myh), 1, fp);
	return myh;
}

void displaywavhdr(WAVheader h){
	for(int i=0; i<4; i++)
		printf("%c", h.chunkID[i]);
	printf("\n");
	printf("Chunk size: %d\n", h.chunkSize);
	printf("Number of channels: %d\n", h.numChannels);
	printf("Sample rate:  %d\n", h.sampleRate);
	printf("Bits per sample: %d\n", h.bitsPerSample);
	double duration;
	duration =(double)  h.subchunk2Size/h.byteRate;
	printf("Duratuion: %f seconds\n", duration);
}

void wavdata(WAVheader h, FILE *fp)
{
	// For samoke rate 16000sps, we need to  read 2000 samples to calculate
	// "fast" decibel value. A decibel value is always calculated by RMS
	// (ROOT MEAN SQUARE) formula
	short samples[SIZE];
	int peaks = 0, flag = 0 ;
	double maxdb = 0.0;
	for(int i=0; i < BARS; i++)
	{
		fread(samples, sizeof(samples), 1, fp);
		double sum = 0.0 ;
		for(int k=0 ; k<SIZE ; k++)
		{
			sum = sum + samples[k]*samples[k];
		}
		double dB = 20*log10(sqrt(sum/SIZE));
#ifdef SDEBUG
		printf("db[%d] = %f\n", i+1, dB);
#else
		if(dB > 70)
		{
			setfgcolor(RED);
			if( flag == 0){
				flag==1;
				peaks++;
			}
		}
		else
		{
	 		setfgcolor(WHITE);
		    flag = 0;
		}
		drawbar(i+1, (int)dB/3);
		gotoXY(1,1);
		setfgcolor(CYAN);
		printf("Sample rate:%d\n", SAMPLERATE);
		setfgcolor(MAGENTA);
		printf("Duration: %.3f\n", (double)  h.subchunk2Size / h.byteRate);
		setfgcolor(YELLOW);
		printf("Peaks: %d\n", peaks);
#endif
		if(dB>maxdb){
			maxdb = dB;
		}
	}
	
	char postdata[100];
	sprintf(postdata, "peaks=%d&maxdb=%f\n", peaks, maxdb);
	sendpost(URL, postdata);
}
