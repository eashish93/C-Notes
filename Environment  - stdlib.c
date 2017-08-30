// Environment - stdlib.h

void abort(void);
// Abort the current process, producing an abnormal program termination. It is same as if calling raise(SIGABRT);
// The program is terminated without destroying any object and without calling any of the functions passed to atexit or at_quick_exit

void exit(int status);	// where status is 0(EXIT_SUCCESS), 1 (EXIT_FAILURE)
// Terminates the process normally, performing the regular cleanup for terminating programs.
// It is normally equivalent to return n. In `main` function, program terminates and `n` is returned to the OS.
// While in other function `return` statement usually return value, while `exit` terminate the function and also the program.

void _Exit(int status);		// In Linux (_exit() system call is equivalent to this)
// Terminates the process normally but without performing any of the regular cleanup tasks for terminating processes.

_Noreturn void quick_exit(int status);
// Terminates the process normally. No additional cleanup tasks are performed. Although C streams are closed/flushed and files
// opens with tmpfile are removed depends on the particular system.
// If a program calls both exit and quick_exit, or quick_exit more than once, it causes undefined behavior.

int atexit(void (*func)(void));
// Set function to be executed on exit.

int at_quick_exit(void (*func)(void));
// Set function to be executed on quick exit


// External Variables (char **environ; // it contains list of all name=value of environment list, setting this to NULL clear all the environment list)
char *getenv(const char *name);
// C-string containing the name of the requested variable. Depending on the platform, this may either be case sensitive or not.
// A null pointer returned if such environment variable does not exist.
int putenv(char *string);	// where `string` is of the form `name=value`.

// You can use `#define _GNU_SOURCE` to get extras functions as mentioned in SUSV3 specification.	

int system(const char *command);
// Invokes the command processor to execute a command.
// For eg: the following line invokes the `dir` command of MS-DOS. `system("dir")`
