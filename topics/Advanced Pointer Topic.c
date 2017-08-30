/** -------------  Advanced Declarations ------------- **/
// Use cdecl for (c gibberish - google it)

int f;		// An integer
int *f;		// An pointer to integer
int * f, g;	// same as `int *f, g;  i.e. declare `f` to be a pointer to integer and `g` is a integer
int  *f();	// declare `f as a function returning pointer to int`
int (*f)();	// pointer to function returning int
int *(*f)();	// pointer to function returning pointer to int

// Now consider arrays (note function cannot return array but it can return pointer to arrays, i.e. it always return scalar values)
int f[];	// an array of int (but array size is missing)
int *f[]; 	// an array of pointer to int
int f()[];	// **[Illegal]** function returning an array of int (but this is illegal, because function cannot return array of integer)
int f[]();	// **[This also illegal.]**
int (*f[])();	// Legal, array of pointer to function returning int
int *(*f[])();	// Legal, array of pointer to function that return pointer to int.
int (*f())[];		// **[legal]**, function returning pointer to array of int



/** ------------- Pointer to Functions ------------------- **/
 // i.e., int (*pf)();

// Declaring and Initializing pointer to functions
// It is important to have a prototype for function prior to the intialization.
int f(int);
int (*pf)(int) = &f;  // or int (*pf)(int) = f;  // *** because the compiler always convert function names to function pointers ***
					  // or statement form; int (*pf)(int);		pf = &f;

// After it is declared and initialized, there are three ways to call the function
	int ans;
	ans = f(25);
	ans = (*pf)(25);
	ans = pf(25);

/** Note, compiler always convert function names to function pointers. So, in first `f` is converted to a pointer to function
 	the pointer specifies where the function is located. The function call operator then invokes the function by executing
	the code beginning at this address.
**/

/** The second statement applies indirection to pf, which convert ``function pointer to function name``. But this is not necessary, 
	because compiler always convert function name to function pointer. That's why third is also valid. **/

/** The third statement, indirection is not needed because the compiler wants a pointer to function anyway. (as we can assign pf = f) **/

/***** Note: You can apply indirection or address to normal function also. Below all are true ****/
	// ans = (&f)(25);
	// ans = (*f)(25);
	// ans = (**f)(25);	// any level of indirection
// All are valid because, `f` always return `int` in this case.



/** ------------- Callback functions ------------------- **/
// Suppose I have insertionSort algorithm, which sort array of integers, but I want it to be sort array of strings also. How do it sort?.
// The answer is to pass pointer to function that recieves the argument in a `void *` parameter.
	// `void *` -> a pointer to something whose type we don't know.
	// Also, they must be cast to correct type.

// Full Example:
	typedef struct NODE {
		struct NODE *link;
		void *value;		// Note : this must be casted in main() program.
	} Node;

Node *searchList(Node *node, void const *val, int (*compare)(void const*, void const*)) {
	// callback can also be written like this, int compare(void const*, void const*);
	// But first one is more clear in the sense.

	while(node != NULL) {
		if(compare(&node->value, val) == 0) 
			break;
		node = node->link;
	}
	return node;
}

int compareInts(void const *a, void const *b) {
	if(*(int*)a == *(int*)b)		// here we cast because we do pointer arithmetic here and also we use indirection here.
		return 0;
	else 
		return 1;
}

// Used like this:
	// desiredNode = searchList(root, &desiredValue, compareInts); 	// Here, how it works
		// First root -> is the node we assign in main() function
		// desiredValue is the int value, we give the address to void const *val = desiredValue;
		// No casting is necessary, because it is already done by compareInts function inside searchList. But is better to cast.
		// because we don't know what code is inside searchList.
		// we assign `compareInts` to `compare` function.
	


// For strings
// #include <string.h>
// desiredNode = searchList(root, "desiredValue", strcmp);
// Note compiler issue warning because its arguments are declared as char* rather than void*




/** ------------- Hash Tables ------------------- **/
	// int (*f[])();		// i.e., array of pointer to Functions

double add(double, double);
double sub(double, double);
double mul(double, double);
double div(double, double);

double (*oper_func[])(double, double) = {add, sub, mul, div};

// Now 	use it like this
result = oper_func[index](op1, op2);		// where index - 0, 1, 2, 3...


// Without this, we use it like that in switch statement 
switch(oper) {
	case 1: add(); break;
	case 2: sub(); break;
	case 3: mul(); break;
	case 4: div(); break;
}




/** ------------- Advanced String Literals ------------------- **/
// What about this expression
"xyz" + 1; // Computes the sum of pointer value plus one. So it direct to `y`
*"abc";		// The result is to print 'a' character 
*("adc" + 1);	// Print 'd', second character
"xyz"[2];		// Print the 'z' character, 3rd character


void mystery(int n) {	// a value in the range 0 to 100
	n += 5;
	n /= 10;
	printf("%s\n", "**********" + 10 - n);
}
// Print `*` based on the value supplied, 0 for 0, 1 for 1, 10 for 10.
// Its faster than traditional loop.
