// Error Handling - See Chapter 24- C. Modern Approach

#include <assert.h> 
	void assert(scalar expression);
	// If the argument expression of this macro compares to zero( i.e. false), a message is written to the 
	// standard error device and `abort` is called, terminating the program execution
#define NDEBUG	 // is a macro which disable all assert function. Include at the beginning of the <assert.h>
// Return => Assertion failed: expression, file filename, line line number


#include <errno.h>
	//`errno` is a macro whose value is of integer type. If value of errno is non-zero, then an error occurs
	// Example:
		errno = 0;
		y = sqrt(x);
		if(errno != 0) {
			fprintf(stderr, "sqrt error; program terminated.\n");
			exit(1);
		}
		// Note that, it is important to store zero before the call of errno, because library function never clear errno.
		// The functions of the standard library may set `errno` to any value and these values are represented by constants listed below.
		// Here standard libary list only three constants but there are more than this for other environments. See SUSV3 specification

		EDOM: Domain Error
		ERANGE: Range Error
		EILSEQ: Illegal Sequence

/** End **/




void perror(const char *s);			// From <stdio.h>
	// Example:
		#include <stdio.h>

		int main ()
		{
		  FILE * pFile;
		  pFile=fopen ("unexist.ent","rb");
		  if (pFile==NULL)
		    perror ("The following error occurred");
		  else
		    fclose (pFile);
		  return 0;
		}
		// Output=> The following error occured: No such file or directory
		// Here After perror string, "No such file or directory" is implemention defined



char *strerror(int errnum);			// From <string.h> , argument is usually one of the values of `errno`
	// When passed error code, strerror returns a pointer to a string describing the error. For example, the call
	// puts(strerror(EDOM)); 
	// might print
	// Numerical argument out of domain

	// `strerror` is closely related to the `perror` function. The error message that perror displays is the same message that strerror
	// would return if passed `errno` as its argument




#include <signal.h>

// Functions
void (*signal(int sig, void(*func)(int)))(int);
int raise(int sig);

// Type
sig_atomic_t


// Macro Constants - See UNIX implementation for additional macros

// int(signals)
	SIGABRT - Signal Abort
	SIGFPE - Signal floating-point exception
	SIGILL - Signal Illegal Instruction
	SIGINT - Signal Interupt
	SIGTERM - Signal Terminate
	SIGSEGV - Signal Segmentation Violation

// functions(handlers)
	SIG_DFL - Default Handling
	SIG_IGN - Ignore Signal
	SIG_ERR - Special return value indicating failure




#include <setjmp.h>

	// setjmp() and longjmp() are useful for dealing with errors and interrupts encountered in a low-level subroutine of a program.
// Functions
	void longjmp(jmp_buf env, int val);

// Macro - Note that it's macro
	int setjmp(jmp_buf env);

/*
	This macro with functional form fills env with information about the current state 
	of the calling environment in that point of code execution, so that it can be restored by a later call to longjmp.
	Calling longjmp with the information stored in env restores this same state and returns the control to that same 
	point (the call to setjmp), which is evaluated as a particular non-zero value.
 */

	// may return more than once,  A first time, on its direct invocation; In this case it always returns zero.
	// When longjmp is called with the information set to env, the macro returns again; this time it returns the 
	// value passed to longjmp as second argument if this is different from zero, or 1 if it is zero.

// Types
	jmp_buf		// This is an array type capable of storing the information of a calling environment to be restored later.


// We can use `setjmp` to jump from one function to another function without returning(which can't be possible to `goto')
// `setjmp` marks a place in a program; `longjmp` can then be used to return to that place later.
// Returning to the point of the `setjmp` is done by calling `longjmp` passing it the same `jmp_buf` type variable that
// we passed to `setjmp`.

	// Example:
	/*
		jump_buf env;
		int val;
		val = setjmp(env);
		if(val) {
			fprintf(stderr, "Error %d happened", val);
			exit(val);
		}
		longjmp(env, 101);	// signaling an error
		return 0;
	 */
	// Output: Error 101 happened