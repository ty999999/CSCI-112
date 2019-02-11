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

	//creates a file variable and then sets it to the file csis.txt
	FILE *file;
	file = fopen("csis.txt", "w");

	//performs calculations from beats per second to beats per year and then calculates how many beats
	//occurred after 50 years
	BPM = BPS * 60;
	BPHour = BPM * 60;
	BPDay = BPHour * 24;
	BPYear = BPDay * 365;
	BTotal = BPYear * totalYears;

	//displays the result and then writes the result to the text file
	printf("Assuming an average rate of one beat per second, a human heart will \nhave beat %d times after 50 years.\n", BTotal);
	fprintf(file, "Total Beats: %d\n", BTotal);

	//closes and pushes changes to the fileB
	fclose(file);

	system("pause");
	return 0;
}