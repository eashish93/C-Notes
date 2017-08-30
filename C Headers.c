
/* C Common Headers */

#include <assert.h>			// void assert(scalar expression)
#include <errno.h>			// C errors (defines macro -- errno, EDOM, ERANGE, ELLSEQ)
#include <ctype.h>
#include <float.h>
#include <iso646.h>			// Defines (macro:-- and, and_eq, etc... (equivalent to operators))
#include <locale.h>
#include <limits.h>			// define macros like INT_MAX, INT_MIN, LONG_MAX, etc..
#include <complex.h>
#include <math.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>			// Algorithms: qsort, bsearch
#include <stdio.h>			// Types: size_t, NULL, EOF
#include <time.h>
#include <stddef.h>			// Types and macros: ptrdiff_t, size_t, max_align_t, offsetof
#include <stdint.h> 		// C99 (defines types like intmax_t, int8_t, intptr_t, int_fast32_t etc...)
// here is a good tutorial on <inttypes.h>
// http://h21007.www2.hp.com/portal/site/dspp/menuitem.863c3e4cbcdc3f3515b49c108973a801/?jumpid=reg_R1002_USEN&ciid=a868e67018695110VgnVCM100000275d6e10RCRD#AUTO3
#include <inttypes.h>		// C99 - It also include <stdint.h> 
#include <wchar.h>			// C99
#include <wctype.h>			// C99
#include <tgmath.h>			// C99
#include <fenv.h> 			// C99
#include <uchar.h>			// C11		(for Unicode character support)
#include <stdaligh.h>		// C11
#include <stdatomic.h>		// C11
#

// Preprocessors

#if
#ifdef
#ifndef
#else
#elif
#endif
#include
#define
#undef
#warning
#error
#line


// To continue a directive to the next line, we must end the current line with a \ character. For eg:

/*
#define DISK_CAPACITY 		(SIDES *			\
							 TRACK_PER_SEC*		\
							 SECTOR_PER_TRACK*	\
							 BYTES_PER_SECTOR)

*/


// Predefined Macros - Search google for this

__LINE__		// Line number of file being compiled
__FILE__		// Name of file being compiled
__DATE__		// Date of compilation (in the form "Mmm dd yyyy")
__TIME__		// Time of compilation (in the form "hh: mm: ss")
__STDC__		// 1 if the compiler conforms to the C standard (C89 or C99 or C11)
__cpluscplus	// This macro test whether the C++ compiler is in use - GCC macro
__func__
__ASSEMBLER__

// Additional C99 Macros

__STDC__HOSTED__			// 1 if this is a hosted implementation (i.e. we use API of UNIX, Microsoft); 0 if it is freestanding
__STDC__VERSION__			// Version of C standard support

// Others are __STDC_IEC_559__ , __STDC_IEC_559_COMPLEX__ , __STDC_ISO_10646__





// Include files other than `.h` extension. The compiler doesn't care about the extension of the file you're including, 
// so things like ".h", ".hpp", ".hxx", ".hh", ".inl", ".inc", etc. are a simple convention, to make it clear what the files is supposed to contain.
// So, you can define whatever in it. Example:
// Suppose you define a function in `.inc` file
	/*
		int add(a, b) {
		return a+b;
		}

		So, it works if you compile it with main file. This means compiler doesn't care about the type of extension it can be whatever. But standard suggest
		that you can define function prototypes in a `.h` extension file. 

		Some people use of `.inc` or `.inl` file extension to define inline function or some characters constant. It can be useful too.
		Also, file with no extension also work.
		In linux implementation, you'll see this type of file `.inc` or `.inl`
	 */
See this: http://stackoverflow.com/questions/1208028/significance-of-a-inl-file-in-c