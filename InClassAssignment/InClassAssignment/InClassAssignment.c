/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*     In-Class  Assignment     */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

float calcBill(float yrd);

int main() {

	char run = 'y';
	float yrdsOrdered = 0.0, bill = 0.0;

	while (run=='y' || run == 'Y') {
	
		printf("Welcome to Concrete Calculator\n\n");
		printf("Please enter the number of yards of concrete you want: ");
		scanf(" %f", &yrdsOrdered);

		bill = calcBill(yrdsOrdered);

		printf("The net bill is: $%0.2f\n\n", bill);

		printf("Would you linke to enter another order? (y/n) ");
		scanf(" %c", &run);

		printf("\n\n\n");
	}

	system("pause");
	return 0;
}

float calcBill(float yrd) {

	float bill = 0.0;

	if (yrd >= 8.0) 
		bill = yrd * 49.5;
	else if (yrd < 3) 
		bill = yrd * 55.5 + 25;
	else if (yrd == 0) 
		bill = 0;
	else
		bill = yrd * 55.5;

	return bill;
}