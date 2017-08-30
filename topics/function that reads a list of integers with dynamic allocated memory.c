/** 
This function allocates an array and reallocates it as necessary using a fixed increment. 
The increment DELTA can be tuned to balance efficiency against wasted memory.
**/

#include <stdio.h>
#include <stdlib.h>

#define DELTA 100

int *readints(void) {
	int *array;
	int size;
	int count;
	int value;

	// Get the initial array, large enough to hold DELTA values;

	size = DELTA;
	array = malloc((size+1)*sizeof(int));		// Note size+1 instead of size to allow room for NULL character.
	if(array == NULL)
		return NULL;

	// Get values from the standard input

	count = 0;
	while(scanf("%d", &value) == 1) {
		count += 1;
		if(count > size) {
			size += DELTA;
			array = realloc(array, (size+1)*sizeof(int));
			if(array == NULL)
				return NULL;
		}
		array[count] = value;
	}

	// Resize the array to the exact size, then store the count and return the array.
	// This never makes the array bigger and so should never fail. (check it anyway!)

	if(count < size) {
		array = realloc(array, (count+1)*sizeof(int));
		if(array == NULL)
			return NULL;
	}
	array[0] = count;
	return array;
}