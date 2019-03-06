/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #5    */
/*         Large Small          */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

FILE *csis;

//Prototype for the compare function
void compare();

int main() {
	csis = fopen("csis.txt", "w");
	for (int i = 1; i <= 4; ++i) {
		compare();
	}
	fclose(csis);
	return 0;
}

void compare() {
	//Initializes the variables
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, max = 0, min = 0;

	//Asks the user to enter four numbers
	printf("Please enter four numbers:\n");
	scanf("%d%d%d%d", &num1, &num2, &num3, &num4);

	//Checks to see which number is the smallest
	if (num1 < num2 && num1 < num3 && num1 < num4) {
		min = num1;

		//Checks to see which number is the largest
		//Since this is a nested if statement within the check for the smallest number, we know the
		//minimum number and can therefore exclude it from consideration for the largest
		if (num4 > num3 && num4 > num2) {
			max = num4;
		}
		else if (num3 > num4 && num3 > num2) {
			max = num3;
		}
		else
			max = num2;
	} //Repeats the above if statement and compound statement for each of the remaining numbers
	else if (num2 < num1 && num2 < num3 && num2 < num4) {
		min = num2;
		if (num4 > num3 && num4 > num1) {
			max = num4;
		}
		else if (num3 > num4 && num3 > num1) {
			max = num3;
		}
		else
			max = num1;
	}else if (num3 < num2 && num3 < num1 && num3 < num4) {
		min = num3;
		if (num4 > num1 && num4 > num2) {
			max = num4;
		}
		else if (num1 > num4 && num1 > num2) {
			max = num1;
		}
		else
			max = num2;
	}
	else {
		min = num4;
		if (num1 > num3 && num1 > num2) {
			max = num1;
		}
		else if (num3 > num1 && num3 > num2) {
			max = num3;
		}
		else
			max = num2;
	}

	//Displays the results on the console and saves them to the file
	printf("Maximum: %d\nMinimum: %d\n", max, min);
	fprintf(csis, "Maximum: %d\nMinimum: %d\n", max, min);
}