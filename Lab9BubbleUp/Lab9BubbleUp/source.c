/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #9    */
/*        Bubble Up Lab         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define INDEX 50

FILE *file;

int main() {

	int container[INDEX], temp = 0;

	if (!(file = fopen("input.txt", "r"))) {
		printf("fiftyrandom.txt could not be opened for input.");
		system("pause");
		exit(1);
	}

	system("clear");

	for (int i = 0; i<INDEX || !feof(file); i++) {
		fscanf(file, "%d\n", &container[i]);
	}

	for (int j = 1; j < INDEX; j++) {
		for (int i = 0; i < INDEX - j; i++) {
			if (container[i] > container[i + 1]) {
				temp = container[i];
				container[i] = container[i + 1];
				container[i + 1] = temp;
			}
		}
	}

	printf("Daniel Murdock\n-------------------------------------\n");

	for (int k = 0; k < INDEX; k++) {
		printf("The value is: %d\n", container[k]);
	}

	fclose(file);

	system("pause");
	return 0;
}