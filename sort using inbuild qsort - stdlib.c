#include <stdio.h>
#include <stdlib.h>

int compare(void const *a, void const *b) {
	int const *pa = a;
	int const *pb = b;

	return *pa > *pb ? 1: *pa < *pb ? -1: 0;		// if-elseif-else

	// or directly
	return *(int*)a > *(int*)b ? 1: *(int*)a < *(int*)b ? -1: 0;
}

int main(void) {
	int *arr, 
		n_values, 
		i;

	// See how many numbers there will be
	printf("How many values are there? ");
	if(scanf("%d", &n_values) != 1 || n_values <= 0) {
		printf("Illegal number of values.\n");
		exit(EXIT_FAILURE);
	}

	arr = malloc(n_values*sizeof(int));
	if(arr == NULL) {
		printf("Can't get memory");
		exit(1);
	}

	for(i = 0; i < n_values; i++) {
		printf("? ");
		if(scanf("%d", arr + i) != 1) {
			printf("Error reading value #%d\n", i);
			exit(1);
		}
	}

	// Sort the values
	qsort(arr, n_values, sizeof(int), compare);

	// Print them out
	for(i = 0; i < n_values; i++) 
		printf("%d\n", arr[i]);

	// Free the memory
	free(arr);
	return EXIT_SUCCESS;
}