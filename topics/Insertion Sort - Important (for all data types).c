#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// void insertionSort(int a[], int n) {
// 	int i, j, key;
// 	for(i = 1; i < n; i++) {
// 		key = a[i];
// 		j = i - 1;
// 		while(a[j] > key && j >= 0) {
// 			a[j+1] = a[j];
// 			j--;
// 		}
// 		a[j+1] = key;
// 	}
// }

#define N 10

void swap(void *a, void *b, size_t size) {
	char *__a = a, *__b = b;	
	do {
		char __tmp = *__a;
		*__a++ = *__b;
		*__b++ = __tmp;
	} while(--size > 0);

}

void insertionSort(void *base, size_t num, size_t size, 
					int(*comp)(const void*, const void*)) {
	int i, j;
	for(i = 1; i < num; i++) {
		j = i - 1;
		while(j >= 0 && comp(base+j*size, base+(j+1)*size) > 0) {
			// printf("test\t");
			swap(base+(j+1)*size, base+(j*size), size);
			j--;
		}
	}
}
int compare(void const *a, void const *b) {
	int const *pa = a;
	int const *pb = b;

	return *pa > *pb ? 1: *pa < *pb ? -1: 0;		// if-elseif-else
}


int strComp(const void *a, const void *b) {
	return strcmp(*(const char**)a, (const char**)b);	// because we pass array of pointer, not pointer to char
														// (const char*)a valid if we only want to compare their address, but string literal resides
														// at a address of `prev-address + 4`.
}
int main(void) {
	int arr[N] = {5, 3, 2, 234, 23, 124, 233, 502, 3, 55};
	insertionSort(arr, N, sizeof(int), compare);
	int i;
	for(i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}

	// char *a[] = {" Hello " , " This " , "is ", "Sorting ", "Example"};
	// insertionSort(a, 5, sizeof(char*), strComp);
	// qsort(a, 5, sizeof(char*), strComp);

	// // printf("%p\t", arr);
	// // swap(arr, arr+1, sizeof(int));
	// // printf("%p", arr);
	// 	int i;
	// for(i = 0; i < 5; i++) {
	// 	printf("%s\n", a[i]);
	// }
	// void *base = arr;
	// int const *z = base;
	
}