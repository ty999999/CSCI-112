/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*         Demo Project         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int F = 0, C = 0;

	//Asks the user to enter a Fahrenheit temperature and then assigns it to the F variable
	printf("Please enter the temperature in degrees Fahrenheit: ");
	scanf("%d", &F);

	//Performs the calculation to convert Fahrenheit to Celsius
	C = (F - 32) / 1.8;

	//Displays the resulting temperature in degrees Celsius
	printf("The temperature is %d degrees Celsius.\n", C);


	system("pause");
	return 0;
}