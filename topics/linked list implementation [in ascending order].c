#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int value;
	struct NODE *next;
} Node;

int main(void) {
	Node *root = NULL;
	Node *tail;
	Node *node;
	int n;
	for(n = 1; n < 5; n++) {
		Node *node = malloc(sizeof(Node));	// If you not define Node *node here, then you have to define node = node->next at the end of the loop
		node->value = n;
		node->next = NULL;
		if(root == NULL)
			root = node;
		else 
			tail->next = node;
		tail = node;
	}
	tail = root;
	while(tail != NULL) {
		printf("%d\n", tail->value);
		tail = tail->next;
	}


	/**
	Note: If you do this, then it will destroy the root and you cannot again traverse the list

		while(root != NULL) {
		printf("%d\n", root->value);
		root = root->next;
	}
	**/


	return 0;

}