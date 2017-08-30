/*** ---------------- COMMAND LINE ARGUMENTS --------------- ***/
/**
	When we run a program, we'll often need to supply arguments with information. (for eg: In UNIX `ls -l remind.c`) - a file name, or a switch
	the modifies the behavior.
**/
/** The main function is called with two optional arguments:
	1. argc -- Count the number of arguments
	2. argv -- points to the values of the arguments. (array of pointers)
			   argv[0] points to the name of the program, while argv[1] through argv[argc-1] point to 
			   the remaining command line arguments.
			   argv[argc] -- points always to `NULL` pointer.
 **/
//**** Note that, the names `argc` and `argv` are frequently used, but they could be called "fred" and "ginger" if 
// **** you so desired, though the program would be harder to read.

int main(int argc, char *argv[]);
// or
int main(int argc, char **argv);		// or you may change the name also--> int main(int num, char **str);

// If the user enters 
cc -c -O main.c insert.c -o test

// then argc == 7, and argv points to first string in the list. (Here `cc`)


// [[Example]]

int main(int argc, char **argv) {
	// Ignores the first argument and print the arguments until `NULL` pointer is reached.
	// So if user enters `a abc def`. It will print
		// abc
		// def
	while(*++argv != NULL) {
		printf("%s\n", *argv);
	}
	return 0;
}