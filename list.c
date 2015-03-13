#include "list.h"

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

void prettyPrint (void) {
	printf("Contents of list:\n")
	
	NODE *crt = head;
	while (crt != 0) {
		printf("%d\n",crt->val);
		crt = crt->next;
	}
	printf("\n");
}

int delete (int val) {
	NODE *out = find(val);
	if (out == 0) return 1; // node not found
	
	node *crt = head;
	
	return 0;
}

struct NODE *find (int val) {
	NODE *crt = head;
	while (crt != 0) {
		if (crt->val == val) break; // val has been found
		else crt = crt->next;
	}
	return crt; // holds 0 if val is not found
}

