/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #8    */
/*       Checking Account       */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

FILE *fpIn;
FILE *fpOut;

void outputHeaders();
void initialBalance(double, double*, double*, double*);
void deposit(double, double*, double*, int*, double*);
void check(double, double*, double*, int*, double*);
void outputSummary(int, double, int, double, double, double, double);

int main() {

	char code;
	double amount, service, balance;
	double amtCheck, amtDeposit, openBalance, closeBalance;
	int numCheck, numDeposit;

	if (!(fpIn = fopen("account.txt", "r"))) {
		printf("account.txt could not be opened for input.");
		exit(1);
	}
	if (!(fpOut = fopen("csis.txt", "w"))) {
		printf("csis.txt could not be opened for output.");
		exit(1);
	}

	amount = 0.0;
	service = 0.0;
	balance = 0.0;
	amtCheck = 0.0;
	amtDeposit = 0.0;
	openBalance = 0.0;
	closeBalance = 0.0;
	numCheck = 0;
	numDeposit = 0;

	outputHeaders();

	while (!feof(fpIn)) {
		fscanf(fpIn, "%c %lf\n", &code, &amount);
		if (code == 'I') {
			initialBalance(amount, &balance, &service, &openBalance);
		}
		else if (code == 'D') {
			deposit(amount, &balance, &service, &numDeposit, &amtDeposit);
		}
		else {
			check(amount, &balance, &service, &numCheck, &amtCheck);
		}
	}

	closeBalance = balance - service;
	outputSummary(numDeposit, amtDeposit, numCheck, amtCheck, openBalance, service, closeBalance);
	fclose(fpIn);
	fclose(fpOut);

	system("pause");
	return 0;
}

void outputHeaders() {
	printf("%-18s%10s%10s%10s\n", "Transaction", "Deposit", "Check", "Balance");
	printf("%-18s%10s%10s%10s\n", "-----------", "-------", "-----", "-------");
}

void initialBalance(double amount, double *balance, double *service, double *openBalance) {
	*balance = amount;
	*openBalance = amount;
	*service += 3.0;
	printf("%-18s%10s%10s%10.2lf\n", "Initial Balance", "", "", *balance);
}

void deposit(double amount, double *balance, double *service, int *numDeposit, double *amtDeposit) {
	*balance += amount;
	*amtDeposit += amount;
	*numDeposit += 1;
	*service += .03;
	printf("%-18s%10.2lf%10s%10.2lf\n", "Deposit", amount, "", *balance);
}

void check(double amount, double *balance, double *service, int *numCheck, double *amtCheck) {
	*balance -= amount;
	*amtCheck += amount;
	*numCheck += 1;
	*service += .06;
	if (*balance < 0.0)
		*service += 5.0;
	printf("%-18s%10s%10.2lf%10.2lf\n", "Check", "", amount, *balance);
}

void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance) {
	printf("\n%21s: %d\n", "Total number deposits", numDeposit);
	printf("%21s: %.2lf\n\n", "Total amount deposits", amtDeposit);

	printf("%21s: %d\n", "Total number checks", numCheck);
	printf("%21s: %.2lf\n\n", "Total amount checks", amtCheck);

	printf("%21s: %.2lf\n\n", "Total service charge", service);

	printf("%21s: %.2lf\n", "Opening balance", openBalance);
	printf("%21s: %.2lf\n", "Closing balance", closeBalance);

}