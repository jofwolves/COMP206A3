#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int val;
	struct node *next;
} NODE;

typedef struct node NODE;

NODE *head;

#define NEW_NODE (NODE *) malloc(sizeof(NODE))
void add (int val) {
	if (head == 0) {
		head = NEW_NODE;
		head->val = val;
		head->next = 0;
	}
	else {
		NODE *crt = head;
		while (crt->next != 0) crt = crt->next;
	
		NODE *new_node = NEW_NODE;
		crt->next = new_node;
		new_node->val = val;
		new_node->next = 0;
	}
	return;
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
	return;
}

NODE* find (int val) {
	printf("entering find()... "); // DEBUG
	NODE *crt = head;
	while (crt != 0) {
		if (crt->val == val) break; // val has been found
		crt = crt->next;
	}
	return crt; // already holds 0 if val is not found
}

int delete (int val) {
	printf("entering delete()... "); // DEBUG
	NODE *out = find(val);
	if (out == 0) return 0; // node not found

	if (head->val == val) {
		NODE *temp = head;
		head = head->next;
		free(temp);
	}
	else {
		NODE *crt = head;
		while (crt->next->val != val) crt = crt->next;
		// crt->next is now the same as out
		crt->next = out->next; // re-link
		free(out);
	}
	return 1; // this is backwards.
}

