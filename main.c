#include <stdio.h>
#include "list.h"

int main (void) {
	
	FILE *numbers;

	do { // get a filename from the user and open the file
		printf("Input path to source file:\n");
		char fname[180];
		scanf("%s",fname);
		numbers = fopen(fname,"rt");
	} while (errno != 0);


	fclose(numbers);
	return 0;
}

