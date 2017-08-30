#include <stdio.h>

int hypo(int a, int b) {
	int square(int x) {return x*x;};
	return square(a) + square(b);
}

int main(void) {
	printf("%d", hypo(3, 4));

	return 0;
}