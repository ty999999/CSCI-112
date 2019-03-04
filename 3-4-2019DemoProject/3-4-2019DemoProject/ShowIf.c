/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*         Demo Project         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	printf("Welcome to decision central\n\n");
	int age = 0;
	char dead = 'n';

	printf("\nAre you dead? y/n: ");
	scanf(" %c", &dead);
	switch (dead) {
		case 'n': {
			printf("How old are you? ");
			scanf("%d", &age);

			if (age >= 65)
				printf("Congrats! You're old enough to retire!\n");
			printf("The value in age is: %d\n", age);
		};
		case 'y': {
			printf("You're ded\n");
		};
	}

	system("pause");
	return 0;
}