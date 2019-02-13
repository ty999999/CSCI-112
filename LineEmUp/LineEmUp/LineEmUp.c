/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*         Demo Project         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

FILE *foodpointer;

int main() {

	printf("Item %-14s %12.2f\n", "Pizza", 23.98 * 6);
	printf("Item %-14s %12.2f\n", "Hot Dogs", 0.99 * 3);
	printf("Item %-14s %12.2f\n", "Ceaser Salad", 4.19 * 5);

	foodpointer = fopen("foodfile", "w");

	fprintf(foodpointer, "Item %-14s %12.2f\n", "Pizza", 23.98 * 6);
	fprintf(foodpointer, "Item %-14s %12.2f\n", "Hot Dogs", 0.99 * 3);
	fprintf(foodpointer, "Item %-14s %12.2f\n", "Ceaser Salad", 4.19 * 5);

	fclose(foodpointer);

	system("pause");
	return 0;
}