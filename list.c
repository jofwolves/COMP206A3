#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int val;
	struct node *next;
} NODE;

NODE *head;

#define NEW_NODE (NODE *) malloc(sizeof(NODE))

void add (int val) {
	if (head == 0) {
		head = NEW_NODE;
		head->next = 0;
	}

	NODE *crt = head;
	while (crt->next != 0) crt = crt->next;
	
	NODE *new_node = NEW_NODE;
	crt->next = new_node;
	new_node->val = val;
	new_node->next = 0;
}

#undef NEW_NODE

void prettyPrint (void) {
	printf("Contents of list:\n\n");
	
	NODE *crt = head;
	while (crt != 0) {
		printf("%d\n",crt->val);
		crt = crt->next;
	}
	printf("\n");
}

NODE* find (int val) {
	NODE *crt = head;
	while (crt != 0) {
		if (crt->val == val) break; // val has been found
		crt = crt->next;
	}
	return crt; // already holds 0 if val is not found
}

int delete (int val) {
	NODE *out = find(val);
	//printf("%d\t",out->val); // DEBUG
	if (out == 0) return 0; // node not found
	
	NODE *crt = head;
	while (crt->next->val != val) crt = crt->next;
	//printf("%d\n",crt->val); // DEBUG
	// now crt->next is now the same as out
	crt->next = out->next; // re-link
	free(out);

	return 1; // this is backwards.
}

