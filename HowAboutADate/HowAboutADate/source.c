
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
int toint(char);

int main() {

	char date[15] = "00/00/0000";

	printf("Please enter the date in MM/DD/YYYY format: ");
	scanf("%s", date);
	if (dateCheck(date))
		printf("That date is valid\n");
	else
		printf("That date is not valid\n");
	system("pause");
	return 0;
}

int dateCheck(char *date) {
	int boolean, imonth, iday, iyear;
	char *day, *month, *year;

	month = strtok(date, "/");
	day = strtok(NULL, "/");
	year = strtok(NULL, "");
	imonth = toint(month[0]) * 10 + toint(month[1]);
	iday = toint(day[0]) * 10 + toint(day[1]);
	iyear = toint(year[0]) * 1000 + toint(year[1]) * 100 + toint(year[2]) * 10 + toint(year[3]);

	if (imonth < 1 || imonth > 12 || iday < 0 || iyear < 0 || iyear>9999) 
		return 0;
	else {
		if (imonth % 2 == 1) {
			return valid(iday, 31);
		} else {
			if (imonth == 2) {
				if (iyear % 4 == 0) {
					return valid(iday, 29);
				} else {
					return valid(iday, 28);
				}
			}
			return valid(iday, 30);
		}
	}
}

int valid(int value, int check) {
	if (value > check)
		return 0;
	else
		return 1;
}

int toint(char val) {
	return (val - 48);
}