/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*         Demo Project         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *file;

typedef struct {
	char name[11];
	char type;
	float weight;
	int length, hp, number;
} Car;

void strSub(char s1[], char s2[], int start, int length);
void printArray(Car car[10], int);
void totalCars(Car car[10], int);
void totalHP(Car car[10], int);
void totalLength(Car car[10], int);


int main() {
	int i = 0;
	char temp[50],type,temp2[50];
	Car car[10];
	file = fopen("traindata.txt", "r");
	while (!feof(file)) {
		fgets(temp, 50, file);
		strncpy(car[i].name, temp, 10);
		car[i].name[10] = '\0';
		strSub(temp2, temp, 10, 1);
		car[i].type = temp2[0];
		strSub(temp2, temp, 12, 5);
		car[i].weight = atof(temp2);
		strSub(temp2, temp, 18, 2);
		car[i].length = atoi(temp2);
		strSub(temp2, temp, 21, 2);
		car[i].hp = atoi(temp2);
		strSub(temp2, temp, 24, 3);
		car[i].number = atoi(temp2);
		i++;
	}

	printArray(car, i);
	totalCars(car, i);
	totalLength(car, i);
	totalHP(car, i);

	system("pause");
	return 0;
}

void strSub(char s1[], char s2[], int start, int length) {
	int i;
	for (i = 0; i < length; ++i)
		s1[i] = s2[start + i];
	s1[i] = 0;
}

void printArray(Car car[10], int num) {
	for (int i = 0; i < num; i++) {
		printf("The car is: %s\tType: %c\tWeight: %5.2f\tLength: %d\tHorsepower: %2d Number in Train: %d\n", car[i].name, car[i].type, car[i].weight, car[i].length, car[i].hp, car[i].number);
	}
}

void totalCars(Car car[10], int num) {
	int total = 0;
	for (int i = 0; i < num; i++) {
		total += car[i].number;
	}
	printf("There are %d cars in the train\n", total);
}

void totalHP(Car car[10], int num) {
	int total = 0;
	for (int i = 0; i < num; i++) {
		total += car[i].hp*car[i].number;
	}
	printf("The total horsepower needed to pull this train is: %d\n", total);
	printf("The number of engines needed to pull the train is: %d\n", (int)ceil(((float)total) / 1000));
}

void totalLength(Car car[10], int num) {
	int total = 0;
	for (int i = 0; i < num; i++) {
		total += car[i].length;
	}
	printf("The total length of the train is: %d\n", total);
}