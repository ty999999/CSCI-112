/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #7    */
/*           Fish Fry           */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	//Declares variables
	int gph = 0;
	float galls = 500.0;

	//Gets how many gallons of water per hour is to be added to the tank
	printf("Please enter additional water added per hour: ");
	scanf("%d", &gph);

	//For loop for calculating how many hours have elapsed, how much water is left, and whether or not the fish have died
	for (int hrs = 1; hrs <= 24 && galls >= 100.0; hrs++) {
		printf("\n The volume is %.2f gallons after %d hours.", galls = galls * .9 + gph /*calculates how many gallons are left*/, hrs);
		if (galls < 100.0) printf("\nThe fish dies after %d hours.", hrs); //Checks to see if there is still enough water in the tank
	}

	printf("\n");
	system("pause");
	return 0;
}