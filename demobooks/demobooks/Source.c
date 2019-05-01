/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project #     */
/*         Demo Project         */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Allows use of a struct like a regular object
typedef struct {
	char author[20];
	int pages;
	float price;
	int copies;
	int yearPublished;
} Book;

//Set up book structure
//struct Book {
//	char author[20];
//	int pages;
//	float price;
//	int copies;
//	int yearPublished;
//};

//prototype of calculating value of a book
float CalcInv(Book *book);

float printAllBooks(Book books[], int);

int main() {

	//Declare a book
	Book book;
	float value;
	strcpy(book.author, "Jim Kjelgaard");
	book.pages = 224;
	book.price = 23.95;
	book.copies = 10;
	book.yearPublished = 1945;
	value = CalcInv(&book);

	printf("The total value of the inventory is: %5.2f\n", value);


	//Declare several books
	Book manyBooks[3];

	//load the array of books
	strcpy(manyBooks[0].author, "Ernest Hemmingway");
	manyBooks[0].pages = 551;
	manyBooks[0].price = 29.50;
	manyBooks[0].copies = 90;
	manyBooks[0].yearPublished = 1939;
	
	strcpy(manyBooks[1].author, "William Faulkner");
	manyBooks[1].pages = 239;
	manyBooks[1].price = 59.50;
	manyBooks[1].copies = 20;
	manyBooks[1].yearPublished = 1925;

	strcpy(manyBooks[2].author, "Harper Lee");
	manyBooks[2].pages = 281;;
	manyBooks[2].price = 69.50;
	manyBooks[2].copies = 10;
	manyBooks[2].yearPublished = 1960;

	printf("The total value is: %.2f\n", printAllBooks(manyBooks, 3));

	system("pause");
	return 0;
}

float CalcInv(Book *book) {
	float value;
	value = book->price * book->copies;
	return value;
}

float printAllBooks(Book books[], int num) {
	float total = 0.0;
	printf("\n");
	for (int i = 0; i < num; i++) {
		printf("Book #%d\n", i + 1);
		printf("Author: %s\n", books[i].author);
		printf("Pages: %d\n", books[i].pages);
		printf("Price: %.2f\n", books[i].price);
		printf("Copies: %d\n", books[i].copies);
		printf("Year Published: %d\n", books[i].yearPublished);
		printf("\n");
		total += books[i].price*books[i].copies;
	}

	return total;
}