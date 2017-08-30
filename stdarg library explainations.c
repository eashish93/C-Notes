#include <stdio.h>
#include <stdarg.h>

/* 
Type
va_list	// used to store a variable number of arguments.

Function like Macros
void va_start(va_list ap, paramN);	// This is necessary, because it initialize ap to retrieve the additional arguments after paramN;
									// then this ap is used in `va_arg` to retrieve arguments in each subsequent calls to `va_arg`
type va_arg(va_list ap, type);		// return additional argument after paramN in each subsequent calls.
									// type - can be any (float, int, double, char, char*, int* et...)
									// Note that: `va_arg` doesn't automatically determine whether it is last or not. You have to design function in 
									// such a way that `va_arg` automatically closed. `printf` function determine by their total no of specifier.
void va_end(va_list ap);		// To clean up the list which stored in variable `ap` (is a must, otherwise bad thing happens)
void va_copy(va_list dest, va_list src);


where
ap -> Uninitialized object of type va_list which stores the parameter of function definition.
After the call, it carries the information needed to retrieve the additional arguments using va_arg.
If ap has already been passed as first argument to a previous call to va_start or va_copy, it shall be passed to va_end before calling this function.

paramN -> Name of the last named parameter in the function definition. The arguments extracted by subsequent calls to va_arg are those after paramN.



// Also note that, if va_list is initialized by other function, then it can be used in another function to retrieve the list. Eg:
char str[100];
int func1(char *format, ...) {
	va_list argList;
	va_start(argList, format);
	vsprintf(str, format, argList);	
	va_end(argList);
}

// Now this `func1` behave like `sprintf` function.



See Ch - 26 for More details.

C Programming - K.N. King
*/


int max_int(int n, ...) {		/* n must be atleast 1 */
	va_list ap;			// va_list is a type just like int, float, etc...
	int i, current, largest;

	va_start(ap, n);	// initialization of ap
	largest = va_arg(ap, int);	// next argument after `n` of type int.

	for(i = 1, i < n; i++) {
		current = va_arg(ap, int);
		if(current > largest)
			largest = current;
	}

	va_end(ap);
	return largest;
}


// Note: we can put ellipses `...` if we are not using it. Eg;
// Valid
int add(int a, ...) {
	return a;
}


int main(void) {
	printf("%f", average(2, 2, 3));

}