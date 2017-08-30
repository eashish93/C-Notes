// Variable length array - an Example (C99, but work in gcc before C99) (and work in C++ too)

int main(void) {
	int n;
	scanf("%d", &n);
	int arr[n];

	int i;
	for(i = 0; i < n; i++) {
		arr[i] = 10+i;
	}
	for(i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}