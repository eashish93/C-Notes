#include <stdio.h>
#include <string.h>

int main(void) {
	/* String Library Functions */
	size_t strlen(char const *str);
	char *strcpy(char *dest, char const *src);	// `dest` is returned. (including the terminating null character).
	char *strcat(char *dest, char const *src);
	// Appends a copy of the source string to the destination string. The terminating null character in destination is overwritten 
	// by the first character of source, and a null-character is included at the end of the new string formed by the concatenation of both in destination.
	// Note: strcat finds the null character in the `dest`, if it doesn't find then it do some nasty things. For eg: 
	/*
		char *str = malloc(80);
		strcat(str, "some string");	// not good

		// first put `\0` character in str.
		*str = '\0';
		strcat(str, "some string"); // That's good print --> "some string"
		or you can use first strcpy() and then strcat()

		// Alternate way: 
		char *first = "ashish";
		char *second = "rawat";
		size_t len1 = strlen(first),
		len2 = strlen(second);
		char *s = malloc(len1+ len2 + 2);
		sprintf(s, "%s %s", first, second);
	 */
	// Or use memcpy
	int strcmp(char const *lhs, char const *rhs);

	char *strncpy(char *dest, char const *src, size_t len);		// Also note that, if you pass sizeof(str) to len, (in case if str is not array like s[n])
																// then it wrong, because str is not known at compiled time as str is pointed to first
																// character in the string.
																// Also no null character is appended at the end if `src` is longer than `dest`.
																// Also if you specify `len` less than `src` then no `nul` is appended at the end.	
																// So you can write like this: `strncpy(dest, src, SIZE); dest[SIZE-1] = '\0';`
																// From the example: (don't do it like that)
																/*
																	#define MAX_CHAR 25
																	char line[MAX_LINE];
																	fgets(line, MAX_LINE+10, stdin);	// Don't do it, instead do MAX_LINE only
																	printf("%s", line);	// It print full string input by fgets(), 
																	// But what about this
																	fgets(line, MAX_LINE+100, stdin);
																	printf("%s", line);	// Error.
																	// So, first is output full string because it takes extra characters in temporary memory.
																	// But in second case `100` is big, so it doesn't take it.
																 */
	char *strncat(char *dest, char const *src, size_t len);		// It append null character at the end.
	int strncmp(char const *dest, char const *src, size_t len);


	// Find the first occurence of the character ch in the byte string pointed to by str. Returns NULL, if not found
	char *strchr(char const *str, int ch);
	// Same as above, but finds from last
	char *strrchr(char const *str, int ch);

	// Instead of searching for one specific character, it looks for the first existance of any of a group of character.
	char *strpbrk(char const *str, char const *group);	

	// This function finds the first place in s1 where the entire string s2 begins and returns a pointer to this location. Returns NULL, if not found
	char *strstr(char const *s1, char const *s2);


	// Returns the number of characters starting from the beginning of str that match any of these characters.
	size_t strspn(char const *dest, char const *group);		// See Page - 253 Pointers in C

	// Returns the length of the maximum initial segment of the byte string pointed to by dest, 
	// that consists of only the characters not found in byte string pointed to by group.
	size_t strcspn(char const *dest, char const *group);


	// See the book - Page 254
	char *strtok(char *src, char const *sep);


// From <stdlib.h>
	// Important functions - from <stdlib.h>
	long int strtol(const char* str, char** endptr, int base); 		// convert string to long integer - robust and powerful
	// endptr - if strtol unable to convert the string (in case if "string like this") then, it stores reference to first character of `str` in endptr.
	// base: if this is `0`, the base used is determined by the format in the sequence.
	// 	So you can check like this:
	/**
	  int main() {
		  char* end;
		  int res_help = strtol("help", &end, 10);

		  if (!*end)		// if it is not '\0' character. Note, strtol automatically set to nul pointer if conversion failed.
		    printf("Converted successfully\n");
		  else
		    printf("Conversion error, non-convertible part: %s", end);

		  return 0;


		int main () {
		  char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
		  char * pEnd;
		  long int li1, li2, li3, li4;
		  li1 = strtol (szNumbers,&pEnd,10);
		  li2 = strtol (pEnd,&pEnd,16);
		  li3 = strtol (pEnd,&pEnd,2);
		  li4 = strtol (pEnd,NULL,0);
		  printf ("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);
		  return 0;

		  // The decimal equivalents are: 2001, 6340800, -3624224 and 7340031
		}
	}
	 */
	unsigned long int strtoul(const char* str, char **endptr, int base);	

	double strtod(const char* str, char **endptr);

	int atoi(const char* str);		// convert string to integer - faster than strtol, but no error reporting.
	long int atol(const char *str);
	double atof(const char* str);
	// Better use strtol for most purpose, and use atoi for performance critical conditions
	// 
	// 
}