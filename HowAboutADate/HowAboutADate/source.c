
/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*         Demo Project         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int dateCheck(char);
int valid(int, int);

int main() {

	char date[15] = "00/00/0000";

	//Retrieves the date from the user
	printf("Please enter the date in MM/DD/YYYY format: ");
	gets(date);
	
	//Checks to see if the date is valid and displays result
	if (dateCheck(date))
		printf("That date is valid\n");
	else
		printf("That date is not valid\n");

	system("pause");
	return 0;
}

//Function to check to see if the given date is valid
int dateCheck(char *date) {
	int boolean, imonth, iday, iyear;
	char *day, *month, *year;

	//Breaks the single entered string into differing day, month, and year variables
	month = strtok(date, "/");
	day = strtok(NULL, "/");
	year = strtok(NULL, "");

	//Converts values of day, month, and year variables to integers
	imonth = atoi(month);
	iday = atoi(day);
	iyear = atoi(year);

	//Initial check to make sure that year and month are valid
	if (valid(imonth, 12) || valid(iyear, 9999)) 
		return 0;
	else {
		//Checks to see if the month is an odd month (has an odd number of days)
		if (imonth % 2 == 1) {
			//Checks validity of the day
			return valid(iday, 31);
		} else {
			//Checks to see if the month is february, requiring a leap year check
			if (imonth == 2) {
				//Checks to see if it is a leap year
				if (iyear % 4 == 0) {
					return valid(iday, 29);
				} else {
					return valid(iday, 28);
				}
			}
			//If month isn't february, checks if date is valid for regular even month
			//since returns are in the if statement, an else statement is not needed to make sure this runs only if not february
			return valid(iday, 30);
		}
	}
}

//simple function to simplify validity checks
//if the entered value is less than 1 or is greater than the indicated check, it returns false, otherwise it returns true
int valid(int value, int check) {
	if (value > check || value < 1)
		return 0;
	else
		return 1;
}