/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*         Pop Project 1        */
/*        MoWe  CSCI 112        */
/********************************/

/*I believe the included picture is the one that you asked me to send to you the other day*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


//Allows the desired Nitrogen coverage to be changed at a later date
#define NITROGEN_POUNDS 1.0
#define AREA 1000

//Prototype for the calculate function
float calculate(int l, int w, float p);

int main() {

	//Initialization of the variables
	int length = 0, width = 0;
	float pounds = 0.0, percent = 0.0;

	//Asks the user to enter the desired parameters
	printf("Please enter the length of your lawn in feet: ");
	scanf("%d", &length);

	printf("Please enter the width of your lawn in feet: ");
	scanf("%d", &width);

	printf("Please enter the percentage of nitrogen in the fertilizer: ");
	scanf("%f", &percent);

	//Assigns the value of pounds to the value returned by the calculate function
	pounds = calculate(length, width, percent);

	//Displays a message indicating how many pounds of fertilizer will be needed to cover the lawn
	//in the specified density of Nitrogen
	printf("\nThe number of pounds of %0.0f%% fertilizer you need to have every %d square \n", percent, AREA);
	printf("feet covered with %1.1f pound of Nitrogen is %1.2flbs.\n\n", NITROGEN_POUNDS, pounds);

	system("pause");
	return 0;
}

//The calculate function takes the length, width, and percentage as input and then calculates
//how many pounds of fertilizer are required
float calculate(int l, int w, float p) {
	//Initializes the local variables used by the function
	int sqrft = 0;
	float pounds = 0.0;

	//Converts the entered percentage into decimal form and then calculates how many pounds of fertilizer
	//are needed to cover the lawn
	p /= 100;
	sqrft = l * w;
	pounds = sqrft * NITROGEN_POUNDS / AREA;
	pounds = pounds / p;

	//Returns the number of pounds needed to cover the lawn
	return pounds;
}