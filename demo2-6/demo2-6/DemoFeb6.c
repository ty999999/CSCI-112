/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*         Demo Project         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	//Assume that there are 3250 miles across the United States
	//This program will determine the number of hours to cross the US at 50 miles per hour
	//The algorithm is number of miles divided by 50

	int distance = 3250, speed = NULL, hours = 0, minutes = 0, seconds = 0;
	int run = 1;
	
	//Asks the user to enter how many miles were travelled and how fast they were travelling
	printf("Please enter how many miles you traveled: ");
	scanf("%d", &distance);
	printf("Please enter how fast you traveled: ");
	scanf("%d", &speed);
	
	//Calculates how many hours, minutes, and seconds it took the user to travel the specified distance at the
	//specified speed
	system("pause");
	hours = distance / speed;
	minutes = distance % speed;
	seconds = minutes % 60;

	//Displays the values of how many hours, minutes, and seconds it took the user to travel
	printf("The time you spent traveling was %d hours, %d minutes, and %d seconds.\n",hours, minutes, seconds);

	//Demonstrates how to properly cast a variable to a different data type
	printf("\n\n%f\n", (double) distance / speed);

	system("pause");
	return 0;
}