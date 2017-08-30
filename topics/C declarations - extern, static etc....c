/** 
---------------  C Declarations --------------------
**/

// C Declarations fall into three categories:
/*
	Storage classes: `auto`, `static`, `extern` and `register`
	Type Qualifiers: `const`, `volatile` and C99 `restrict`
	Type specifier: void, char, short, int, long, float, double, signed, unsigned.
	Function specifier(C99): `inline`
*/

// auto 
//-------------------
	// It is the default storage class for variables that belongs to a block.
	// In C++11, it's meaning is different (just like var in javascript)


// static
//-------------------
	// When used outside a block, it specifies that a variable has internal linkage.
	// When used inside a block, `static` changes the variable storage duration from automatic to static.
	// `static` hides a variable/function inside the file in which it is declared. (when declare like a global variable).
	// static variable is initialized only once. See recus() example below:
	// static variable or array is initialized to zero, if not initialized. Eg: `static int a[10]`. All the `a[]` array have value zero.
	/*
		Example: 
		int i;
		static int j;
		// In file1.c 
			void foo1() {
				/* has access to i and j
			}
		// In file2.c
			void foo2() {
				/* has access to i only.
			}
	*/
	// Static used to make the program more efficient and for information hiding
		/*
		 	Example:
		 	// Each time this, function is called, the characters `0123456789ABCDEF` will be copied into
		 	// the hex_chars array to initialize it;
		 	char digit_to_hex(int digit) {
				const char hex_chars[16] = "0123456789ABCDEF";
				return hex_chars[digit];
		 	}
		 	// Now make the array static
	 		char digit_to_hex(int digit) {
				static const char hex_chars[16] = "0123456789ABCDEF";
				return hex_chars[digit];
		 	}
		 	// Since static variables are initialized only once, we've improved the speed of `digit_to_hex`

		 	int recus() {
				static int a = 3;	// never terminates if declared not static
				if(a == 10) 
					return 1;
				a++;
				printf("%d\t", a);
				recus();
			}
			recus();	// 4 5 6 7 8 9 10
			// Now in this function if a == 10, the recus() function return, but if however `a` is declared not `static` then the recus() function
			// never terminates.
		*/
	// Functions declared with static in one file cannot be called by other file.
		/*	
			Example:
			static int g(int i);
			// not called by other file, but a function pointer is used for calling.
		*/



// extern
//-------------------
	// When variables are declared, compiler set aside space for it
	int i;	// set space for it.
	extern int i;	// extern informs the compiler that i is defined elsewhere in the program.
					// so no need to allocate space for it.
	/*
		Example:
		File : file_common.h
			extern int errno;

		File: file1.c
			#include "file_common.h"
			int errno;
			// Some Code 

		File: file2.c
			#include "file_common.h"
			int errno;
			// Some code

		Now if both file1.c and file2.c is compiled, they will both point to the same errno.
		If we declare without `extern` then each file have separate copies of errno. This is a 
		problem, as `errno` is supposed to be constant over all linked files.
	*/
	// `extern` doesn't have effect on functions. (as this is default for functions).



// register
//-------------------
	// Using this tells the compiler to store the variable in a register. (see book)



// inline  (C99)
//--------------------
	// For making function faster, see book
	// mostly used with `static` qualifiers



// volatile (See book - it's for low-level programming)
//---------------------
// See this: http://stackoverflow.com/questions/246127/why-is-volatile-needed-in-c




// typedef - not a type but a way to declare your own types
/**
 * Example:
 	typedef int Stack;	// declares Stack of type `int`
 	// It's useful for information hiding
 */



// C99 Designated Initializers
int a[15] = { [2] = 29, [0] = 3, [14] = 48};



// Note:
	// This is possible in C++ not in C
	const int size = 15;
	int a[size] = {1, 2, 3, 4, 0};

	// But this is:
	int a[size];	// no initialization
	a[0] = 3;
