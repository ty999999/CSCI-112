/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #6    */
/*        Water Bill Lab        */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

FILE *csis;

//Prototype of the cost function
float cost(int g);

int main() {
	//Initialization of all variables in main
	int start = 0, end = 0, galls = 0;
	float bill = 0.0;

	//Opens the file csis.txt for writing
	csis = fopen("csis.txt", "w");

	//Asks the user to enter the starting and ending meter readings
	printf("Please enter the starting meter reading: ");
	scanf("%d", &start);
	printf("Please enter the ending meter reading: ");
	scanf("%d", &end);

	//Calculates how many gallons were used
	galls = end - start;

	//Passes the number of gallons used to the cost function and sets the bill equal to the result
	bill = cost(galls);

	//Sends the number of gallons used and the cost to the console and writes them to the file
	printf("You used %d gallons of water and it cost you $%.2f\n", galls, bill);
	fprintf(csis, "Gallons: %d\nCost: $%.2f", galls, bill);

	//Closes the file
	fclose(csis);

	system("pause");
	return 0;
}

//Function for calculating the cost the bill
float cost(int g) {

	//Checks to see which usage the tier the customer is in and multiplies the gallons used by that tier's price per gallon
	//Since the tiers are consecutivea lower limit is not needed in the if statements because those scenarios
	//would be caught by the previous statement
	if (g < 1000) {
		return g * 0.05;
	}
	else if (g <= 9999) {
		return g * 0.15;
	}
	else if (g < 99000) {
		return g * .20;
	}
	else {
		return (float) g;
	}
}