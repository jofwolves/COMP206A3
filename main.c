#include <stdio.h>
#include <stdlib.h>

int main (void) {
	
	FILE *numbers;

	do { // get a filename from the user and open the file
		printf("Input path to source file:\n");
		char fname[180];
		scanf("%s",fname);
		numbers = fopen(fname,"rt");
	} while (errno != 0);

	int number; // holds each number to be added or deleted
	while (fscanf(numbers,"%d\n",&number) == 1) {
		add(number); // add numbers to list
	}

	prettyPrint(); // print numbers which have been added

	do {
		int keep_deleting = 0;
		printf("Input a number to be deleted from the list:\n");
		scanf("%d",&number);

		has_been_deleted = delete(number);
		if (has_been_deleted) printf("NUMBER WAS DELETED");
		else printf("NUMBER WAS NOT FOUND");

		prettyPrint();

		char delete_another[20];
		printf("Would you like to delete another number?");
		scanf("%s",delete_another);
		if (!strcmp(delete_another,"yes") ||
			!strcmp(delete_another,"YES") ||
			!strcmp(delete_another,"Yes") ||
			!strcmp(delete_another,"y") ||
			!strcmp(delete_another,"Y")) keep_deleting = 1;

	} while (keep_deleting);

	fclose(numbers);
	return 0;
}

