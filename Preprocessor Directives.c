// Preprocessor Examples

// Tip : Avoid side effects such as ++ or -- in macros
// **[Caution]** Don't put semicolons at the end

#define DEBUG  		// It define DEBUG to true

#define MAX(x, y) 	((x) > (y) ? (x): (y))		// All macro definitions that evaluate numeric expression should be parenthesized in this
												// manner to avoid unexpected interactions with operators in the arguments or with
												// operators adjacent to where the macro is used.

// **[Caution]** 
/*
	#define DOUBLE(x) 	(x) + (x)

	printf("%d\n", 10*DOUBLE(5));		// Look like it print 10, but it not (print 55), because
										// when it evaluate it looks like this
										// 10*(5) + (5) 	== 55

	So, put parenthesis will avoid the problem
	#define DOUBLE(x) ((x) + (x))

*/

// An interesting pair of macros
	#define repeat		do
	#define until(x)	while(!(x))
/*
	repeat {
		statements;
	} until(i >= 10);

	The preprocessor substitute the following code
	do {
		statements;
	} while(! (i >=10));
*/

#define TOUPPER(c)	('a' <= (c) && (c) <= 'z'? (c) - 'a' + 'A': (c))

#define PRINT_INT(n)	printf("%d\n", n)

#define ECHO(s)			\
		do {
			gets(s);	\
			puts(s);	\
		} while(0);





// Macro vs Functions 
//------------------------------------------
/*
	1. Macro makes the program both smaller and faster than using a functions
	2. Macro are typeless, it can used for any type (long, int, float, char etc...)
	3. It is not possible to have pointer to macro.
	4. The disadvantage to using is that a copy of the code is inserted into the function each time it is called.
		Unless, macro is very short, using macros can greatly increase the size of the program.

	// This cannot be accomplish by function
	#define MALLOC(n, type)	\
		( (type*)malloc( (n)*sizeof(type) ) )
*/




// # operator - it will convert macro argument into string
//---------------------------------------------------------

#define PRINT_INT(n)	printf(#n " = %d\n", n)		// Example: PRINT_INT(i/j); will become printf("i/j" " = %d\n", i/j);



// ## operator - token paster
//------------------------------------------
#define MK_ID(n)	i##n

// Example:
	int MK_ID(1), MK_ID(2), MK_ID(3);
	// After preprocessing, it becomes
	int i1, i2, i3;




// Variation of max using ##
//-------------------------------
#define GENERIC_MAX(type) 			\
type type##_max(type x, type y) 	\
{
	return x > y ? x: y;
}



// #undef macro
//------------------------------
#undef N 		// This will undefine `N` if it is defined previously, else no effect




// Predefined Macros
//--------------------------------

__LINE__		// Line number of file being compiled
__FILE__		// Name of file being compiled
__DATE__		// Date of compilation (in the form "Mmm dd yyyy")
__TIME__		// Time of compilation (in the form "hh: mm: ss")
__STDC__		// Return 1 if the compiler conforms to the C standard (C89 or C99 or C11)

// Example:
	printf("Compiled on %s at %s\n", __DATE__, __TIME__);
	// Result
	// Compiled on DEC 23 2012 at 22:18:48

	#define CHK_ZERO(divisor)		\
		if(divisor == 0)	\
			printf("*** Attempt to divide by zero on line %d "	\
					"of file %s ***\n",__LINE__, __FILE__)




// Additional C99 Macros
//------------------------------------
__STDC__HOSTED__			// 1 if this is a hosted implementation (i.e. we use API of UNIX, Microsoft); 0 if it is freestanding
__STDC__VERSION__			// Version of C standard support

// Others are __STDC_IEC_559__ , __STDC_IEC_559_COMPLEX__ , __STDC_ISO_10646__

#define MK_STR(x)	#x
// Example
	char empty_string[] = MK_STR();
	// After preprocessing
	char empty_string[] = "";		// because # is a strigize operator

#define JOIN(x, y, z) 	x##y##z

// Example
int JOIN(a, b, c), JOIN(a, b), JOIN(a, ,c), JOIN(,,c);
// After preprocessing
int abc, ab, ac, c;		// The missing argument were replaced by placemarker tokens




// Additional C99 debegger function
//---------------------------------------------
__func__		// Every function has to access the __func__ identifier, so its useful for debugging





// COnditional Compilation
//------------------------------------------
#if DEBUG 		// This says, if DEBUG is defined previously then process, 
 // process

#if defined DEBUG  // or if defined(DEBUG)
// Alternate way 
#ifdef	DEBUG

#ifndef DEBUG 		// is same as #if !defined DEBUG

#elif  constant-expression  // similar to else-if stamements

#endif

#else
// Example
/*
#ifdef WIN32    // or #if WIN32
 ......
#elif defined(MAC_OS) // or #elif MAC_OS
 ......
#elif defined(LINUX)  // or #elif LINUX
 ......
#endif
*/

 /*
 // Writing programs that can be compiled with different compilers
 #if __STDC__
 	.....
 #else
 	.....
 #endif
 */




// Macros with a variable number of arguments - C99 Feature
//---------------------------------------------------------
 	// Example - 1
 	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 	/*
 		eprintf("%s:%d", input_file, lineno);
 		Output: fprintf(stderr, "%s:%d", input_file, lineno);
 	*/
 	// Example - 2
 	#define TEST(condition, ...) ( (condition)?	\
 		printf("Passed Test: %s\n", #condition): \
 		printf(__VA_ARGS__))
// The `...` known as ellipses, goes at the end of macro parameter list, preceded by 
// ordinary parameters(if any). `__VA_ARGS__` is a special identifier that represent
// the all arguments that correspond to the ellipses.
 	/*
 		TEST(voltage <= max_voltage, 
 			"Voltage %d exceeds %d\n", voltage, max_voltage);
 		Output: 
 		((voltage <= max_voltage) ? 
 		printf("Passed test: %s\n", "voltage <= max_voltage") :
 		printf("Voltage %d exceeds %d\n", voltage, max_voltage));
 	*/





// Miscellaneous Directive 
//-------------------------------------
// #error directive
#error int type is too small
	//produce the following (differ by compiler)
// Error directive: int type is too small

// #line directive (has two forms)
#line n
// where n is an integer representing line no
#line n "file"
/*
 Example:
 Suppose that following directive appear at the beginning of the file `foo.c`
 #line 10 "bar.c"
 Let's say the compiler detects an error on line 5 of foo.c. Then the error message
 will refer to line 13 of file `bar.c` not line 5 of file `foo.c`
 (why line 13, because directive occupies line 1 of `foo.c`, so renumbering of foo.c begins
 at line 2, which is treated as line 10 of bar.c)
*/

// #pragma directive and _Pragma operator (See Book)




// File Inclusion (multiple header files)
//-----------------------------------------
// We know that, if a header file is included (say 10 times) in other source
// file, then it is compiled ten 10 times. But note that runtime efficiency 
// is not affected.
// It is better to use several header file, each containing the declarations
// appropriate for a particular function or module, than to put all of the 
// declarations for a program in one giant header file.

/* ----- Sharing function prototypes ----- */
// Suppose that a source file contains a call of a function `f` that's defined
// in another file `foo.c`. Calling `f` without declaring prototype is risky. 
// Without prototype, compiler assumes that `f's` return type is `int` and the 
// number of parameters matches the number of arguments in the call of `f`.
// Also, if the compiler has not seen prototype before, then:
//  --> `float is converted to double`
// 	--> `char and short are converted to int`
/* **[Caution]** (undefined behaviour)
	int main(void) {
		double x = 3.0;
		printf("%d", square(x));
	}

	int square(int n) {
		return n*n;
	}

*/
/**[Note]**: Always make sure that compiler have seen a prototype prior to function call **/

/** ----- Protecting Header Files ----- **/
	// If a source file includes the same header file twice, compilation error may result.
	// Suppose a `file1.h` include `file3.h`, `file2.h` include `file3.h` and `prog.c` include
	// both `file1.h` and `file2.h`. When `prog.c` is compiled, `file3.h` is compiled twice.
	// Though including same header file doesn't always cause compilation error.
	// If a file contain macro definitions, prototypes or variable declaration we can't get 
	// compilation error. But if it contain type definition, we'll get error.
	// So, protect your header file with the declarations below:
#ifndef BOOLEAN_H
#define BOOLEAN_H
	#define TRUE 1
	#define FALSE 0
	typedef int Bool
#endif
// When this file is included, the BOOLEAN_H macro won't be defined, so the preprocessor will
// allow the lines between #ifndef and #endif. But if defined, then preprocessor will remove 
// definition between #ifndef and #endif.
// The name BOOLEAN_H doesn't matter.





// C++ Compatibility
//-------------------------------
// The macro `__cplusplus` is predefined by C++ implementations and can be used in source
// files meant to be used in both C and C++ environments.
// For compatibility with standard C, tranditional C and C++, test the environment like this:
#ifdef __cplusplus
	/** It's a C++ compilation **/
#else                            	// or elif defined __STDC__
#ifdef __STDC__  	
	/** It's a standard C compilation **/
#else
	/** It's a non-standard C compilation **/
#endif
#endif

// or without traditional C, 
#if defined(__cplusplus)
	/** It's a C++ compilation **/
#else
	// standard C
#endif



// Simple Macro vs Parametrized Macro
//-------------------------------------
#define N 100 		// This is called simple macro
#define MAX(x, y) ((x) > (y) ? (x) : (y))		// This is called parametrized macro
