#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main (void) {
	
	FILE *numbers;

	head = 0; // initialize head of list

	do { // get a filename from the user and open the file
		printf("Input path to source file: ");
		char fname[180];
		scanf("%s",fname);
		numbers = fopen(fname,"rt");
	} while (numbers == 0);

	int number; // holds each number to be added or deleted
	while (fscanf(numbers,"%d\n",&number) == 1) {
		add(number); // add numbers to list
	}

	prettyPrint(); // print numbers which have been added

	int keep_deleting;
	do {
		keep_deleting = 0; // default to not continuing
		printf("Input a number to be deleted from the list: ");
		scanf("%d",&number);

		printf("attempting to delete number... ");
		int has_been_deleted = delete(number);
		if (has_been_deleted) printf("NUMBER WAS DELETED\n");
		else printf("NUMBER WAS NOT FOUND\n");

		prettyPrint(); // show that numbers have been deleted

		char delete_another[20];
		printf("Would you like to delete another number? ");
		scanf("%s",delete_another);
		if (!strcmp(delete_another,"yes") ||
			!strcmp(delete_another,"YES") ||
			!strcmp(delete_another,"Yes") ||
			!strcmp(delete_another,"y") ||
			!strcmp(delete_another,"Y")) keep_deleting = 1;
		// need to do the above cases manually
		// since, for some reason, "yES" and "yeS"
		// aren't supposed to match : (

	} while (keep_deleting);

	fclose(numbers);
	return 0;
}

