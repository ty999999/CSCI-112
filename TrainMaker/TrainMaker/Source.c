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

//Creates the struct of type Car
typedef struct {
	char name[11];
	char type;
	float weight;
	int length, hp, number;
} Car;

//Prototype of functions
void strSub(char s1[], char s2[], int start, int length);
void printArray(Car car[10], int);
void totalCars(Car car[10], int);
void totalHP(Car car[10], int);
void totalLength(Car car[10], int);

int main() {
	int i = 0;
	char input[50], temp[50];
	Car car[10];

	//Opens file
	if (!(file = fopen("traindata.txt", "r"))) {
		printf("traindata.txt could not be opened for input.");
		system("pause");
		exit(1);
	}
	
	//While the end of the file is not reached, read the line it's on, seperate the data, and put the data in the array
	for (; !feof(file); i++) {
		fgets(input, 50, file);
		strncpy(car[i].name, input, 10);
		car[i].name[10] = '\0';
		strSub(temp, input, 10, 1);
		car[i].type = temp[0];
		strSub(temp, input, 12, 5);
		car[i].weight = atof(temp);
		strSub(temp, input, 18, 2);
		car[i].length = atoi(temp);
		strSub(temp, input, 21, 2);
		car[i].hp = atoi(temp);
		strSub(temp, input, 24, 3);
		car[i].number = atoi(temp);
	}

	//Sends the information to the console
	printArray(car, i);
	totalCars(car, i);
	totalLength(car, i);
	totalHP(car, i);

	//closes the file
	fclose(file);

	system("pause");
	return 0;
}

//Slight modification of stegman's strSub function that is formatted more like the built in string functions (ordered destination->source instead of source->destination)
void strSub(char s1[], char s2[], int start, int length) {
	int i;
	for (i = 0; i < length; ++i)
		s1[i] = s2[start + i];
	s1[i] = 0;
}

//Prints the data in the array
void printArray(Car car[10], int num) {
	for (int i = 0; i < num; i++) {
		printf("The car is: %s\tType: %c\tWeight: %5.2f\tLength: %d\tHorsepower: %2d Number in Train: %d\n", car[i].name, car[i].type, car[i].weight, car[i].length, car[i].hp, car[i].number);
	}
}

//Calculates the total number of cars and displays it on the console
void totalCars(Car car[10], int num) {
	int total = 0;
	for (int i = 0; i < num; i++) {
		total += car[i].number;
	}
	printf("There are %d cars in the train\n", total);
}

//Calculates the total horsepower required as well as the number of locomotives needed to pull the train and displays it on the console
void totalHP(Car car[10], int num) {
	int total = 0;
	for (int i = 0; i < num; i++) {
		total += car[i].hp*car[i].number;
	}
	printf("The total horsepower needed to pull this train is: %d\n", total);
	printf("The number of engines needed to pull the train is: %d\n", (int)ceil(((float)total) / 1000));
}

//Calculates the total length of the train and displays it on the console
void totalLength(Car car[10], int num) {
	int total = 0;
	for (int i = 0; i < num; i++) {
		total += car[i].number*car[i].length;
	}
	printf("The total length of the train is: %d\n", total);
}