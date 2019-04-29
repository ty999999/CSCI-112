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

	//Tries to open file and throws an error if it can't
	if (!(file = fopen("input.txt", "r"))) {
		printf("fiftyrandom.txt could not be opened for input.");
		system("pause");
		exit(1);
	}

	//Clears the console
	system("clear");

	//Fills the container array with the data in the text file
	for (int i = 0; i<INDEX || !feof(file); i++) {
		fscanf(file, "%d\n", &container[i]);
	}

	//sorts the array
	for (int j = 1; j < INDEX; j++) {
		for (int i = 0; i < INDEX - j; i++) {
			//checks if container[i] is smaller than the following number
			if (container[i] > container[i + 1]) {
				//switches container[i] and container[i+1]
				temp = container[i];
				container[i] = container[i + 1];
				container[i + 1] = temp;
			}
		}
	}

	//prints the header
	printf("Daniel Murdock\n-------------------------------------\n");

	//prints the data from container
	for (int k = 0; k < INDEX; k++) {
		printf("The value is: %d\n", container[k]);
	}

	fclose(file);

	system("pause");
	return 0;
}