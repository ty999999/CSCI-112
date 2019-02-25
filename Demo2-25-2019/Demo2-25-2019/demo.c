/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*         Demo Project         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int arrayinput();

void arrayoutput(int scores[], int size);

float arrayaverage(int scores[], int size);

/*void input();

void output(int s1, int s2, int s3);

float average(int s1, int s2, int s3);*/

int main() {

	return arrayinput();

}

int arrayinput() {
	//declares the scores variables

	int scores[] = { 0, 0, 0 };
	int size = sizeof(scores) / sizeof(scores[0]);

	for (int i = 0; i < size; i++) {
		printf("Please enter a score: ");
		scanf("%d", &scores[i]);
	}

	arrayoutput(scores, size);

	system("pause");
	
	return 0;
}

void arrayoutput(int scores[], int size) {
	//Prints the results of the average function
	printf("\nThe average is %7.3f\n\n", arrayaverage(scores, size));
}

float arrayaverage(int scores[], int size) {
	float average = 0;
	for (int i = 0; i < size; i++) {
		average += scores[i];
	}

	average /= size;
	return average;
}

/*void input() {
	int score1 = 0, score2 = 0, score3 = 0;

	//Gets the values for the scores from the user
	printf("Please enter the first score: ");
	scanf("%d", &score1);
	printf("Please enter the second score: ");
	scanf("%d", &score2);
	printf("Please enter the third score: ");
	scanf("%d", &score3);
	
	output(score1, score2, score3);
}

float average(int s1, int s2, int s3) {
	float average = s1 + s2 + s3;
	average /= 3;
	return average;
}

void output(int s1, int s2, int s3) {
	//Prints the results of the average function
	printf("\nThe average is %7.3f\n\n", average(s1, s2, s3));
}*/