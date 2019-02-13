/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*        Color  Changer        */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

FILE *myfile;

int main() {

	myfile = fopen("tempfile.txt", "w");
	int fah;
	float cel;
	char answer;

	system("COLOR B2");
	printf("Enter temp in degrees F ");
	scanf("%d", &fah);
	cel = (5 / 9.0) * (fah - 32);
	system("COLOR 0F");
	printf("Converted temp is: %f\n", cel);
	scanf("%c", &answer);

	system("pause");
	return 0;
}