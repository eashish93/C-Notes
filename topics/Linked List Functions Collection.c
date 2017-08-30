#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct NODE {
	int data;
	struct NODE *next;
} Node;

void Push(Node **headRef, int newData) {
	Node *newNode = malloc(sizeof(Node));
	newNode->data = newData;	// put in the data;
	newNode->next = *headRef;	// list
	*headRef = newNode;
}

// Build and return the list {1, 2, 3}
Node *BuildOneTwoThree(void) {
	Node *head = NULL;
	Push(&head, 3);
	Push(&head, 2);
	Push(&head, 1);

	return head;
}

int Length(Node *head) {
	int count = 0;
	Node *current = head;
	while(current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

/**
=======================================
		Linked list Problems
=======================================
**/

// Problem - 1

int Count(Node *head, int searchFor) {
	int count = 0;
	while(head != NULL) {
		if(head->data == searchFor)
			++count;
		head = head->next;

	}
	return count;
}

void CountTest(void) {
	Node *myList = BuildOneTwoThree();
	int count = Count(myList, 2);
	printf("%d", count);
}

// Problem - 2

int GetNth(Node *head, int index) {
	int count = 0;
	while(head != NULL) {
		if(count++ == index) 
			return head->data;
		head = head->next;
	}
	assert(0);		// Use of assert function
}

void GetNthTest() {
	Node *myList = BuildOneTwoThree();
	int lastNode = GetNth(myList, 2);
	printf("%d", lastNode);
}

// Problem - 3

void DeleteList(Node **headRef) {
	Node *nxt;
	while(*headRef != NULL) {
		nxt = (*headRef)->next;
		free(*headRef);
		*headRef = nxt;
	}
	*headRef = NULL;
}


void DeleteListTest() {
	Node *myList = BuildOneTwoThree();	// build {1, 2, 3}
	DeleteList(&myList);		// Deletes the three nodes and sets myList to NULL
	printf("%d", myList->data);	// Tester
}

// Problem - 4

int Pop(Node **headRef) {
	Node *head;
	int result;

	head = *headRef;
	assert(head != NULL);

	result = head->data; 	// Pull out the data before the node is deleted;

	*headRef = head->next;
	free(head);

	return result;
}

void PopTest() {
	Node *head = BuildOneTwoThree();
	int a = Pop(&head);
	int b = Pop(&head);
	int c = Pop(&head);
	int len = Length(head);
	printf("%d %d %d", a, b, c);
}

// Problem - 5

void InsertNth(Node **headRef, int index, int data) {
	int count = 0;
	if(index == 0)		// Special case
		Push(headRef, data);
	else {
		Node *current = *headRef;
		while(++count != index) {
			assert(current != NULL);
			current = current->next;
		}
		if(count == index) 
			Push(&(current->next), data);
 	}
}

void InsertNthTest() {
	Node *head = NULL;	// Start with an empty list
	InsertNth(&head, 0, 13); 		// build {13}
	InsertNth(&head, 1, 42);		// build {13, 42}
	InsertNth(&head, 1, 5);			// build {13, 5, 42}

	printf("%d\n", head->next->data);
	printf("%d", head->next->next->data);

}

// Problem - 6

void SortedInsert(Node **headRef, Node *newNode) {
	if(*headRef == NULL || (*headRef)->data >= newNode->data) {
		newNode->next = *headRef;
		*headRef = newNode;
	}
	else {
		Node *current = *headRef;
		while(current->next != NULL && current->next->data < newNode->data) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void SortedInsertTest() {
	Node *head = BuildOneTwoThree();
	Node *newNode = malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = 4;
	SortedInsert(&head, newNode);
	while(head != NULL) {
		printf("%d\n", head->data);
		head = head->next;
	}
}

// Problem - 7

void InsertSort(Node **headRef) {
	Node *result = NULL;
	Node *current = *headRef;
	Node *nxt;
	while(current != NULL) {
		nxt = current->next;
		SortedInsert(&result, current);
		current = nxt;
	}
	*headRef = result;
}

// Problem - 8

void Append(Node **aRef, Node **bRef) {
	if(*aRef == NULL) // Special case
		*aRef = *bRef;
	else {
		Node *current = *aRef;
		while(current->next != NULL) {		// Don't do current != NULL here, 
			current = current->next;
		}
		current->next = *bRef;
	}

	*bRef = NULL;	// NULL the original b, since it has been appended above
}

void AppendTest() {
	Node *a = BuildOneTwoThree();
	Node *b;
	Push(&b, 4);
	Append(&a, &b);
	printf("%d", a->data);
	printf("%d", a->next->data);
	printf("%d", a->next->next->data);
	printf("%d", a->next->next->next->data);

}

// Problem - 9

void FrontBackSplit(Node *source, Node **frontRef, Node **backRef) {
	int len = Length(source);
	int i;
	Node *current = source;
	if(len < 2) {
		*frontRef = source;
		*backRef = NULL;
	}
	else {
		int hopCount = (len-1)/2;
		for(i = 0; i < hopCount; i++) 
			current = current->next;

		*frontRef = source;
		*backRef = current->next;
		current->next = NULL;
	}
}

void FrontBackSplitTest() {
	Node *source = BuildOneTwoThree();
	Push(&source, 5);
	Push(&source, 4);
	Node *front, *back;
	FrontBackSplit(source, &front, &back);
	
	while(front != NULL) {
		printf("%d\n", front->data);
		front = front->next;
	}

	while(back != NULL) {
		printf("%d\n", back->data);
		back = back->next;
	}
}

int main(void) {
	FrontBackSplitTest();
}