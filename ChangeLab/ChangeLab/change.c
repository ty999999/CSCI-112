/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #4    */
/*          Change Lab          */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//Creates the file pointer
FILE *file;

int main() {

	//Declares cost, total, and the denominations while setting them to their intial value
	float cost = 21.17, total = 100.00;
	int twenty = 0, ten = 0, five = 0, one = 0, quarter = 0, dime = 0, nickel = 0, penny = 0;

	//Opens the text file change.txt and assigns it to the file pointer
	file = fopen("change.txt", "w");

	//Calculates the number of each denomination by setting the number of pennies to the difference between cost and total
	//and dividing the number of pennies by the cent value of each denomination and then setting the number of pennies to
	//the remainder of the division
	penny = (total - cost) * 100;
	twenty = penny / 2000;
	penny %= 2000;
	ten = penny / 1000;
	penny %= 1000;
	five = penny / 500;
	penny %= 500;
	one = penny / 100;
	penny %= 100;
	quarter = penny / 25;
	penny %= 25;
	dime = penny / 10;
	penny %= 10;
	nickel = penny / 5;
	penny %= 5;

	//Prints the results of the calculation to the command line
	printf("%8s: %6.2f\n%8s: %6.2f\n----------------\n", "Cost", cost, "Tendered", total);
	printf("%8s: %d\n%8s: %d\n%8s: %d\n%8s: %d\n%8s: %d\n", "Twenty", twenty, "Ten", ten, "Five", five, "One", one, "Quarter", quarter);
	printf("%8s: %d\n%8s: %d\n%8s: %d\n", "Dime", dime, "Nickel", nickel, "Penny", penny);

	//Prints the results of the calculation to the opened file
	fprintf(file, "%8s: %6.2f\n%8s: %6.2f\n----------------\n", "Cost", cost, "Tendered", total);
	fprintf(file, "%8s: %d\n%8s: %d\n%8s: %d\n%8s: %d\n%8s: %d\n", "Twenty", twenty, "Ten", ten, "Five", five, "One", one, "Quarter", quarter);
	fprintf(file, "%8s: %d\n%8s: %d\n%8s: %d", "Dime", dime, "Nickel", nickel, "Penny", penny);
	
	//Closes the file
	fclose(file);

	system("pause");
	return 0;
}