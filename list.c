#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int val;
	struct node *next;
} NODE;

typedef struct node NODE;

// avoid passing to each function manually
NODE *head;

#define NEW_NODE (NODE *) malloc(sizeof(NODE))
void add (int val) {
	if (head == 0) {     // need to make a
		head = NEW_NODE; // new list from
		head->val = val; // scratch if head
		head->next = 0;  // isn't initialized
	}
	else {
		NODE *crt = head; // get to the end
		while (crt->next != 0) crt = crt->next;
	
		// make a new node
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
	//printf("entering find()... "); // DEBUG
	NODE *crt = head;
	while (crt != 0) {
		if (crt->val == val) break; // val has been found
		crt = crt->next;
	}
	return crt; // already holds 0 if val is not found
}

int delete (int val) {
	//printf("entering delete()... "); // DEBUG
	NODE *out = find(val);
	if (out == 0) return 0; // node not found

	if (head->val == val) { // need to point
		NODE *temp = head;  // head to the second
		head = head->next;  // node before deleating
		free(temp);         // the previous head
	}
	else {
		NODE *crt = head;
		while (crt->next->val != val) crt = crt->next;
		// crt->next is now the same as out
		crt->next = out->next; // re-link
		free(out);
	}
	return 1; // this is backwards. come on now.
}

