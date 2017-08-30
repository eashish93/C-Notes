// Typedef operator
// See this: http://stackoverflow.com/questions/1591361/understanding-typedefs-for-function-pointers-in-c-examples-hints-and-tips-ple?rq=1

typedef int * intPtr; 
// Usage:
	// intPtr a, b, c, d, e;	// Declare all the variables to pointer to int.
#define intPtr int*	
	// intPtr a, b, c, d, e;	// Declare only `a` to be a pointer to int.
	
// Example - 2
typedef void int_void(int);
// usage
	// int_void test;	// prototype declaration, equivalent to : void test(int);
						// It means typedef first substitute `void` by `int_void` and all other remains same
	// test(5);			// now use it
	// void test(int abc) {};		// declaration of function



// Example - 3 (function pointer)
// usage:
	int add(int a, int b) {
		return (a+b);
	} 
	int mult(int a, int b) {
		return a*b;
	}

	typedef int (*math_func)(int, int);	// declaration of function pointer

	int main(void) {
		math_func addition = &add;	// typedef substitute `int` to `math_func`, then we use `math_func addition(int, int)` = &add;
		math_func multiply = &mult;	// equivalent to int (*multiply)(int, int) = &mult;

		int c = addition(11, 11);	// calling function
		c = multiply(11, 12);	// calling function
	}



// Example - 4
// Taking the signal handler function of c.
extern void (*signal(int sig, void(*func)(int))) (int);

// We can write it as
typedef void (*SignalHandler)(int signum);

// then we can declare signal as:
extern SignalHandler signal(int sign, SignalHandler handler);



// Example - 5 (multiple typedefs)
// ===============================
typedef double wages;
typedef wages base, *p; 	// base is a synonym for double, p for double*. 