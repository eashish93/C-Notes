#include <stdio.h>
#include <stdlib.h>

// Memory Management

// Here `void*` means a pointer variable which can be cast to the desired type of data pointer in order to be dereferenceable.

// Allocates a block of size bytes of memory, returning a pointer to the beginning of the block.
// The content of the newly allocated memory is not initialized, remaining with indeterminate values.
void* malloc(size_t size);
// Also note, allocating (say 1 or 2 etc.. byte) to malloc automatically allocate (1600-1700 bytes or more). This is because malloc allocates memory
// from the heap (using sbrk() see MAN). Compiler doesn't throw error in C (even in C++, using C++). So, be careful and allocate the proper
// size. 
// Note that when using these void* pointer types, you have to make casting in order to work in C++. Otherwise, C++ compiler throws error.
/*
 Here's an example
 int *a = malloc(10*sizeof(int));	// valid C, but invalid C++
 int *a = (int*)malloc(10*sizeof(int));	// valid C, C++
*/

// The argument to free must either be NULL or a value that was previously returned from malloc, calloc, or realloc. 
// Passing a NULL argument to free has no effect
void free(void* ptr);

// Allocates a block of memory for an array of num elements, each of them `size` bytes long and initializes all its bits to zero.
// The effective results is the allocation of a zero-initalized memory block of `(num*size)` bytes.
void* calloc(size_t num, size_t size);
// On success, a pointer to the memory block allocated by the function or null pointer returned.
// Calloc takes the number of elements desired and number of bytes in each element. From these values it computes the total numbers of bytes need.
// Eg: num - 2, size - 4, so total allocation is 2*4 = 8 bytes, and all its bits set to zero.

// Change the size of the memory block pointed to by ptr.
void* realloc(void* ptr, size_t size);	// size is the new size of whole memory block, not size you want to add to previous
// Return a pointer to the reallocated memory block, which may be either the same as ptr or a new location
// Return value is useful to store the data from that new location. 
// If the block is made larger its old content remain unchanged and additional memory is added to the end of the block.
// If the block is made smaller memory is taken off from the end.
// If the original block can't be resized, realloc will allocate a different block of the right size and copy the contents of the old block
// to the new one.
//*** If first argument is NULL, it behaves same as malloc. ***
// Example: buffer = realloc(buffer, 10);	// reallocates 10 bytes.



int main(void) {
	// Malloc Example
	int *pi;

	// Allocates 100 bytes of memory to pi;
	// On a machine with 4-bytes integers, the memory will be treated as an array of 25 integers
	pi = malloc(100);		
	if(pi == NULL) {
		printf("Out of memory!\n");
		exit(EXIT_FAILURE);
	}

	// Here is another way to assign memory to malloc
	pi = malloc(25 * sizeof(int));
}


// Algorithms
void *bsearch(const void* key, const void* base, size_t num, size_t size, int (*compar)(const void*, const void*));
	// key: the key to search for

// Sorts the `num` elements of the array pointed by base, each element size bytes long, using the `compar` function to determine the order.
void qsort(void *base, size_t num, size_t size, int (*compar)(const void*, const void*));
// For array of pointer `size` is 4 bytes (i.e., size of pointer)

// compare: pointer to a function that compare two elements.
/*
** This function is called repeatedly by qsort to compare two elements. It shall follow the following prototype:
	
 	int compar (const void* p1, const void* p2);
*/
 	// The above function usually written like this:

int compareMyType (const void * a, const void * b) {
  if ( *(MyType*)a <  *(MyType*)b ) return -1;
  if ( *(MyType*)a == *(MyType*)b ) return 0;
  if ( *(MyType*)a >  *(MyType*)b ) return 1;
}