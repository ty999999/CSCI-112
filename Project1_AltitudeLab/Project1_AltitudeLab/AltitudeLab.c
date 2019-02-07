/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project 1     */
/*         Altitude Lab         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	// determines how far away from an airport a pilot needs to start descending based on their altitude,
	//speed, and assuming the standard descent rate of 500 feet per minute

	int RATE = 500, alt = 0, mph = 0;
	double min = 0.0, miles = 0.0, mpm = 0.0;

	//Asks the user to enter their speed and their altitude
	printf("Please enter your speed in miles per hour: ");
	scanf("%d", &mph);
	printf("Please enter your altitude in feet: ");
	scanf("%d", &alt);

	//Converts the planes speed from miles per hour to miles per minute
	mpm = (double) mph / 60;

	//Determines how many minutes are needed to descend at 500 fpm
	min = alt / RATE;

	//Calculates how many miles from the airport the pilot should start descending
	miles = min * mpm;

	//Displays how far away from the airport the pilot should start descending
	printf("You should start descending %7.3f miles from the airport.\n", miles);
	

	system("pause");
	return 0;
}