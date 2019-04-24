/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*        Oh My Strings         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	char entered[50], finish[30], insert[50], *temp1, *temp2, copy[50];
	
	//Gets the strings from the user
	printf("Enter Palomar College: ");
	gets(entered);
	strcpy(copy, entered);
	printf("Enter string to insert: ");
	gets(insert);

	//Displays the strings that were recieved from the user
	printf("String is: %s\nString to insert is: %s\n", entered, insert);

	//breaks the entered string into two seperate strings
	temp1 = strtok(copy, " ");
	temp2 = strtok(NULL, "");

	//Copies the value of the entered string's first word to the final string
	strcpy(finish, temp1);

	//Adds a space between words
	strcat(finish, " ");

	//appends the remaining words to the final string
	strcat(finish, insert);
	strcat(finish, " ");
	strcat(finish, temp2);

	//Displays the final string
	printf("%s\n", finish);

	system("pause");
	return 0;
}