
// this file will be use to test functions in screen.c

#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void)
{
	FILE *fp = fopen("test.wav", "r"); // open the wav file in read-only mode
	WAVheader h = readwavhdr(fp);
	displaywavhdr(h);
	clearscreen();
	wavdata(h, fp);
	fclose(fp);
	getchar();
}
