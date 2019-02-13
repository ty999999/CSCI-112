/********************************/
/*  Programmer: Daniel Murdock  */
/*     Project: C Project 3     */
/*          Metals Lab          */
/*        MoWe  CSCI 112        */
/********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

FILE *file;

int main() {

	//Opens the file MetalWeights
	file = fopen("MetalWeights", "w");

	//Creates variables for both the densities of the metals as well as the weight
	//of a person made of that metal.  All metal names use their Periodic Table symbol
	float Al = 168.48, Cu = 559.87, Au = 1206.83, Pb = 707.96, Mg = 108.51, 
		Pt = 1339.2, Zn = 445.3, height = 1.76;

	float wAl = 0, wCu = 0, wAu =0, wPb = 0, wMg = 0, wPt = 0, wZn = 0;

	//Calculates the weight of a person made of the specific metal
	wAl = Al * height;
	wCu = Cu * height;
	wAu = Au * height;
	wPb = Pb * height;
	wMg = Mg * height;
	wPt = Pt * height;
	wZn = Zn * height;

	//Prints the results on the console
	printf("%15s\t\t\tWeight per cubic foot\n", "Metal");
	printf("----------------------------------------------------------------------\n");
	printf("%15s\t\t\t%14.2f\n", "Aluminum", wAl);
	printf("%15s\t\t\t%14.2f\n", "Copper", wCu);
	printf("%15s\t\t\t%14.2f\n", "Gold", wAu);
	printf("%15s\t\t\t%14.2f\n", "Lead", wPb);
	printf("%15s\t\t\t%14.2f\n", "Magnesium", wMg);
	printf("%15s\t\t\t%14.2f\n", "Platinum", wPt);
	printf("%15s\t\t\t%14.2f\n", "Zinc", wZn);

	//Writes the results to the text file MetalWeights
	fprintf(file, "%15s\t\t\tWeight per cubic foot\n", "Metal");
	fprintf(file, "----------------------------------------------------------------------\n");
	fprintf(file, "%15s\t\t\t%14.2f\n", "Aluminum", wAl);
	fprintf(file, "%15s\t\t\t%14.2f\n", "Copper", wCu);
	fprintf(file, "%15s\t\t\t%14.2f\n", "Gold", wAu);
	fprintf(file, "%15s\t\t\t%14.2f\n", "Lead", wPb);
	fprintf(file, "%15s\t\t\t%14.2f\n", "Magnesium", wMg);
	fprintf(file, "%15s\t\t\t%14.2f\n", "Platinum", wPt);
	fprintf(file, "%15s\t\t\t%14.2f\n", "Zinc", wZn);

	//Closes the file MetalWeights
	fclose(file);

	system("pause");
	return 0;
}