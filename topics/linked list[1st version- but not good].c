#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} Node;

Node *add_to_list(Node *list, int n) {
	Node *new_node;
	new_node = malloc(sizeof(Node));
	if(new_node == NULL) {
		printf("Error: malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}
	new_node->value = n;
	new_node->next = list;
	return new_node;
}

Node *read_numbers(void) {
	Node *first = NULL;
	int n;
	printf("Enter a series of integers (0 to terminate): ");
	for(;;) {
		scanf("%d", &n);
		if(n == 0)
			return first;
		first = add_to_list(first, n);
	}
}


Node *search_list(Node *list, int n) {
	while(list != NULL && list->value != n) 
		list = list->next;
	return list;
}

Node *delete_from_list(Node *list, int n) {
 	Node *cur, *prev;
 	for(cur = list, prev = NULL; 
 		cur != NULL && cur->value != n;
 		prev = cur, cur = cur->next
 	   );

 	if(cur == NULL)
 		return list; 	// n was not found
 	if(prev == NULL)
 		list = list->next; // n is in the first node
 	else
 		prev->next = cur->next; // n is in some other node
 	free(cur);
 	return list;

}