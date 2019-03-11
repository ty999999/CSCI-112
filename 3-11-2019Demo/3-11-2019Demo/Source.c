/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*         Demo Project         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	//demonstrate if/else logic for increasing values
	//cost scale
	//1-5 items cost 5.00 per item
	//6-10 items cost 4.00 per item
	//11-20 items cost 3.00 per item
	//over 20 items cost 2.00 per item

	//declare variable
	float total = 0.0;
	int numItems = 0;

	//get input from user
	printf("Please enter the number of items you wish ");
	scanf("%d", &numItems);

	//calculate total
	if (numItems <= 5 && numItems>0)
		total = numItems * 5.00;
	else if (numItems <= 10)
		total = numItems * 4.00;
	else if (numItems <= 20)
		total = numItems * 3.00;
	else
		total = numItems * 2.00;

	int counter = 0;
	for (; counter < 10; counter++) {
		printf("It Worked\n");
	}

	//display the total
	printf("The total is: %.2f\n", total);

	system("pause");
	return 0;
}