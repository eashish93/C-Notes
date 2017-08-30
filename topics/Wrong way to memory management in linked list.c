#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _SingleList {
	struct _SingleList *link;
	int data;
} SingleList;


SingleList *prepend(SingleList *list, int data) {
	SingleList a;
	SingleList *newNode = &a;
	newNode->data = data;
	newNode->link = list;
	return newNode;
}

int main(void) {
	SingleList *list = NULL;
	list = prepend(list, 10);
	printf("%d", list->data); // 10

	list = prepend(list, 20);
	printf("\n%d", list->link->data);	// 20

	list = prepend(list, 30);
	printf("\n%d", list->data);	// 30

	list = prepend(list, 40);	
	printf("\n%d", list->data);	// 40

	list = prepend(list, 50);	
	printf("\n%d", list->data);	// 50
	printf("\n%d", list->link->data);	// any value
	printf("\n%d", list->link->link->data);	// error

	// So it means that, when you call `prepend` function first time it assign `data 10` to address of `a`, next time you call it creates `a` and assigned the data
	// value. So, the last call value works there.
	// So this is wrong.

}