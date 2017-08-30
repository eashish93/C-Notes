#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10
#define WORD_LEN 20

// Prototypes
void getline(char *str, int n);
void insertion_sort(char *a[], int n);		// Better use **a for array of strings

int main(void) {
	char *words[MAX_WORDS];
	char word[WORD_LEN];
	int i = 0, num_elements;
	for(;;) {
		printf("Enter a word: ");
		getline(word, WORD_LEN);
		if(word[0] == '\n')
			break;

		words[i] = malloc(strlen(word) + 1);
		strcpy(words[i], word);
		i++;
	}
	num_elements = i;
	insertion_sort(words, num_elements)	;	// Note: you can't write sizeof(words)/sizeof(words[0]) because length of dynamically allocated array in not calculated in c;

	printf("In sorted order: \n");
	for(i = 0; i < num_elements; i++) {
		printf("%s", words[i]);
	}
	return 0;
}

void getline(char *str, int n) {
	int ch;
	while(isspace(ch = getchar()) && ch != '\n');
	while(--n > 0 && ch != EOF && ch != '\n') {
		*str++ = ch;
		ch = getchar();
	}
	if(ch == '\n')
		*str++ = ch;
	*str = '\0';
}

void insertion_sort(char *a[], int n) {
	char *key;
	int i, j;
	for(i = 1; i < n; i++) {
		key = a[i];
		j = i - 1;
		while(j >= 0 && strcmp(a[j], key) >= 0) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}		
}
