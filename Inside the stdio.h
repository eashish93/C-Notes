// Inside stdio.h library

// MACROS
FOPEN_MAX // Represents the minimum no of files that can be open simultaneously. It's value is greater than 7
FILENAME_MAX 	// An integer that indicates how large a character array should be to hold the longes legal file name that the implementation supports.
EOF 	// Macro of type int that expands into a negative integral constant expression (generally -1)
NULL	// A NULL pointer
BUFSIZ 	// This macro constant expands to an integral expression with the size of the buffer used by the setbuf function.
L_tmpnam	// Minimum length for temporary file name
TMP_MAX 	// This macro expands to the minimum number of unique temporary file names that are guaranteed to be possible to generate using tmpnam.
			// This value cannot be lower than 25.


// Types
FILE 		// A pointer type containing information to control a stream
fpos_t		// This type of object is used to specify a position within a file. An object of this type is capable of specifying uniquely any position within a file.
size_t		// unsigned integer type (also defined in <stdlib.h>, <stddef.h>, <string.h>, <time.h>, <wchar.h>)


// Formatted Input/Output
	// format specifier has following prototype `%[*][width][length]specifier` (for inputs only, like scanf(), fscanf()) where:
		// * - (optional) indicating data to be read but not store
		// width - (optional) max number of character to read (for eg: scanf("%3d", &n))
		// length - (optional) one of hh, h, l, ll, j, z, t, L
		// specifier - for eg: i, u, d, c, o, f, e, g etc... (see book)	
	// format specifier for outputs `%[flags][width][.precision][length]specifier` (see cplusplus.com)
// Output																// Input
// Return value: Number of items of the argument list successfully filled/print.
int fprintf(FILE *stream, const char *format, ...);						int fscanf(FILE *stream, const char *format, ...);	
int printf(const char *format, ...);									int scanf(const char *format, ...);
// The content is stored in `str` buffer as a string pointed by `format` arguments.
// Convert the `format` into string and stored them in `str` (with max size `n` for snprintf)
// If the resulting string would be longer than n-1 characters, the remaining characters are discarded and not stored, 
// but counted for the value returned by the function. Terminating null character is automatically appended after the content written.
int sprintf(char *str, const char *format, ...);						int sscanf(char *str, const char *format, ...);
																		// Same as scanf() but reading from `str` instead of stdin
int snprintf(char *str, size_t n, const char *format, ...);		// Don't use sprintf, instead use `snprintf`

/**
 * Example:
	char str[80];
	snprintf(str, 80, "%d %s", 3, "Ashish");	// convert the `3` to string and store them in str. Also, "Ashish" is already a string, 
												// so it stores in same format.
 */

// V-family of printf/scanf
	int vprintf(const char* format, va_list arg);
	// Write formatted data from variable argument list to stream
	int vfprintf(FILE *stream, const char* format, va_list arg);		// This is the core of printf() function
	// Write formatted data from variable argument list to string
	int vsprintf(char *s, const char *format, va_list arg);
	// Write formatted data from variable argument list to sized buffer
	int vsnprintf (char * s, size_t n, const char * format, va_list arg);	
// See vscanf()/vsscanf()/vfscanf()	 --- C99 in Reference

// Character input/output
	// Streams are stdin (mostly keyboard), stdout (terminal or screen), stderr
// Output																// Input
	// Read/Write character from stream
	// In all the functions below, you see argument `stream`, if you specify `stdin` to it. It will read/write input to terminal or screen. But if 
	// you specify FILE pointer which are returned by `fopen` or `freopen` or `tmpfile` call, it will read/write input from there not from the screen.
int fputc(int ch, FILE *stream);										int fgetc(FILE *stream);	
	// Read/Write string from Streams 									// fgetc() and getc() are equivalent, except getc() may be implemented as macros.
	// `putc` and `fputc` are equivalent, 
	// except that putc may be implemented as a macro
char *fgets(char *str, int num, FILE *stream);							int fputs(const char *str, FILE *stream );
	// Read/Write character from stdin
	// Read until a newline or EOF is found (either one)
	// *[Note]* A newline is included in stream, so buffer is X+2 bytes long (one for nul and other for newline)
	// Return funciton str, or NULL if no character is read.
	// Sometimes we don't want newline, so the one way is to use ungetc() after it.
	// It returns pointer to str, so that you can switch to this in next call.
	// Always use the correct buffer size (don't depend when on wrong buffer, it will create undefined behavior).
	// If using loops, like: 
	/*
		char str[12];	// +2 for `\0` and `\n`.
		while(fgets(str, 10, stdin)) { // It works.
		   fputs(str, stdout);
		}
		// After first loop, `str` doesn't point to end, because, you don't return to it.
		// Consider this also:
			fgets(str, 10, stdin);
			fputs(str, stdout);
			printf("\n%c", *str);
			fgets(str, 10, stdin);
			fputs(str, stdout);
			printf("\n%c", *str);

			fgets(str, 10, stdin);
			fputs(str, stdout);
			printf("\n%c", *str);
			// Input: 
			ashish rawat.
			// Output: 
			Print first `ashish r`, then `a` and then `awat`, `w`.

			// From this we learn that, when called from loop, it doesn't matter whether the size is 10 or 5 (must be always less than given array). Because,
			// the remaining string is called next time in loop and so on. But suppose your line length is 40 and you specify 20, then it will read this in two
			// calls and then it break the line into two line which is not what you wanted.
			// Other thing, you want to note is that, if you do this: 
			// `strPtr = fgets(strPtr, sizeof(str), stdin)`. and then read it in next call, it will break after filling the whole array, because you 
			// return a pointer to that point and in next call, it will start from that. (so don't do this in loops unless you know what you are doing).
	 */

int putc(int ch, FILE *stream);											int getc(FILE *stream);		
	// Read/Write string from/to stdin									// getc(stdin) is equivalent to getchar();
int getchar(void);	/* Equivalent to getc(stdin); */					int putchar(int ch);
	// Read/Write character from stream - Same as fputc, fgetc except it is implemented as macro in some environments
int puts(const char *str);												char *gets(char *str); // don't use this
	// Ungets character from stream 									// Reads characters from the standard input (stdin) and stores them 
																		// as a C string into str until a newline character or the end-of-file is reached.
int ungetc(int ch, FILE *stream);



// Direct Input/Output (used to read binary blocks of data, although with care we can use it with text data as well)
// ptr -> Pointer to a block of memory with a size of at least (size*count) bytes, converted to a void*.
// Returns the number of elements acutally read or written (not bytes)
// size is the number of bytes in each element (for char 1, for int sizeof(int) etc...)
// count is the number of elements to be read or written each one with a size bytes long.
// stream is the pointer to the FILE object that specifies an input stream.
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);


// File Access
FILE *fopen(char const *filename, char const *mode); // Where mode is:
// Return NULL if fopen fails and errno is set to error code.
// Adding `+` to above modes opens the file for update, and both reading and writing are allowed on the stream.
// r  - open for reading
// w  - open for writing (file need not exist)
// a  - open for appending (file need not exist)
// r+ - open for reading and writing, start at beginning (file must exist)
// w+ - open for reading and writing (overwrite file) (create a file if doesn't exist)
// a+ - open for reading and writing (append if file exists)
// Adding `b` to mode, file is for binary (for eg: 'rb'-- read a binary file, 'wb' -- write to binary file, 'rb+'-- read and write to binary).


FILE *freopen(char const *filename, char const *mode, FILE *stream);
// It is used to open( or reopen) a specific stream on a file. The last argument may be a stream that was previously returned by `fopen` or one of the following
// 'stdin', 'stdout', 'stderr'.
// The function first attempts to close the stream. It then opens the stream with given file and mode. If fails, the NULL returned
int fclose(FILE *stream);
// Return 0 if succeeds, else EOF.

int fflush(FILE *stream);
// Calling fflush forces the stream to written immediately (which cannot be possible with printf()).
// Always call fflush after printf() while debugging because printf() sometimes doesn't show up the screen immediately.

void setbuf(FILE *stream, char *buffer);
int setvbuf(FILE *stream, char *buffer, int mode, size_t size);



// Operations on files
int remove(const char *filename);
// Removes the file
int rename(const char *oldname, char const *newname);
// Rename the filename
FILE *tmpfile(void);
// This function creates a file that is removed automatically when the file is closed or the program terminates. The file is opened with mode `wb+`
char *tmpnam(char *str);
// Generates a temporary file names.



// Error Handling
void clearerr(FILE *stream);		// Clear error indicators
int feof(FILE *stream);			// Check end-of-file indicator
int ferror(FILE *stream);
void perror(const char *s);		// Prints the string you give it followed by a string that describes the current value of errno.


// File Positioning 
fgetpos, fseek, fsetpos, ftell, rewind ===== See Reference

long ftell(FILE *stream);		// Returns the current position in the stream,
								// On binary this value is the number of bytes the current position is from the beginning of the file.
int fseek(FILE *stream, long offset, int from);		// Allows to seek on a stream. This operation changes the current position at which
													// the next read or write occurs. Seeking beyond the end of the file and writing extends the file.
/*
 	from is one of the following
 	SEEK_SET , SEEK_CUR, SEEK_END

 	fseek(fd, 0, SEEK_SET); // Start of file 
	fseek(fd, 0, SEEK_END); // Next byte after the end of the file 
	fseek(fd, -1, SEEK_END); // Last byte of file 
	fseek(fd, -10, SEEK_CUR); // Ten bytes prior to current location 
	fseek(fd, 10000, SEEK_END); // 10001 bytes past last byte of file 
 */


void rewind(FILE *stream);	// Set the read/write pointer back to the beginning on the indicated stream

// Alternative to ftell and fseek
int fgetpos(FILE *stream, fpos_t *position);	//
int fsetpos(FILE *stream, fpos_t const *position);