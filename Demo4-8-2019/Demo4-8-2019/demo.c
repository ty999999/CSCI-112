/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*         Demo Project         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//prototype
void LoadItUp(int[]);
int AddItUp(int[]);
int mysearch(int[], int, int);

int main() {
	//declare an array
	/*int students[] = { 1602, 43, 1024, 72, 1 };*/
	int students[5];
	/*students[0] = 1602;
	students[1] = 43;
	students[2] = 5;
	students[3] = 28;
	students[4] = 708;*/

	LoadItUp(students);



	printf("The value in the students array at position 3 is: %d\n", students[2]);

	printf("The total of all elemnts in the array is: %d\n", AddItUp(students));
	int answer = mysearch(students, 28, 5);
	if (answer == -1)
		printf("The value was not found\n");
	else
		printf("The value was found at position %d\n", answer);


	system("pause");
	return 0;
}

void LoadItUp(int scoresArray[]) {
	for (int i = 0; i < 5; i++) {
		printf("Please enter a number for this element of tbe array: \n");
		scanf("%d", &scoresArray[i]);
	}
}

int AddItUp(int adding[]) {
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += adding[i];
	}
	return total;
}

int mysearch(int search[],int find,int count) {
	int found = 0, where, i = 0;
	while (!found && i < count) {
		if (search[i] == find)
			found = 1;
		else
			i++;
	}

	if(found)
		where = i;
	else
		where = -1;
	return where;
}