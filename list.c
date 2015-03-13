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

}

BOOLEAN delete (int val) {

}

struct NODE *find (int val) {

}
