#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int value;
	struct node *next;
} Node;


int main(void) {
	Node x;
	// First we assign, NULL to first.
	Node *first = NULL;
	// Then we completely assign a new blank structure to new_node;
	Node *new_node = &x;
	// Then we fill the integer value in "value" by pointing new_node.
	new_node->value = 10;
	// Now in "next" we fill first, which is initially NULL
	new_node->next = first;
	// Now at this stage structure "x" contains value 10 and NULL, and we assign "x" to first by new_node. We can directly assign "x" to first (think it, why we haven't).
	first = &x;
	// Same procedure....
	Node y;
	new_node = &y;
	new_node->value = 20;
	new_node->next = first;
	first = new_node;
	printf("%d", new_node->value);

	return 0;
}


// Now if we have to insert 100 list, we have to declare 100 structure variables or single array structures. But doing it in structure-array way has 
// disadvantages with respect to doing the same in dynamic-allocation way(or pointer way) which you'll learn when you have some experience with it.
// Here's a way to do that, in this value is printed in the reverse way.
/***
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int value;
	struct NODE *link;
} Node;

int main(void) {
	Node *root, *connector = NULL;
	root = malloc(sizeof(Node));
	root->link = connector;
	root->value = 5;
	connector = root;

	root = malloc(sizeof(Node));
	root->link = connector;
	root->value = 10;
	connector = root;


}
***/


/****
Here is the second version and in this, output is printed in the same way.

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int value;
	struct NODE *next;
} Node;

int main(void) {
	Node *root, *connector;
	connector = malloc(sizeof(Node));
	connector->value = 5;
	connector->next = NULL;
	root = connector;

	connector->next = malloc(sizeof(Node));
	connector->next->value = 10;
	connector = connector->next;
	connector->next = NULL;

	connector->next = malloc(sizeof(Node));
	connector->next->value = 15;
	connector = connector->next;
	connector->next = NULL;

	while(root != NULL) {
		printf("%d\n", root->value); 
		root = root->next;
	}


	return 0;

}
****/