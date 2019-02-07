/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project 2     */
/*          Heart  Lab          */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	int BPS = 1, totalYears = 50;
	int BPM = 0, BPHour = 0, BPDay = 0, BPYear = 0, BTotal = 0;

	FILE *file;
	file = fopen("csis.txt", "w");

	BPM = BPS * 60;
	BPHour = BPM * 60;
	BPDay = BPHour * 24;
	BPYear = BPDay * 365;
	BTotal = BPYear * totalYears;

	printf("Assuming an average rate of one beat per second, a human heart will \nhave beat %d times after 50 years.\n", BTotal);
	fprintf(file, "Total Beats: %d\n", BTotal);

	fclose(file);

	system("pause");
	return 0;
}