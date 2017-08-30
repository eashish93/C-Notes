/*
	#include <time.h> - Describe timer function and its types
 */

// Types
clock_t		// Representing clock tick counts.
time_t 		// Capable of representing times
			// For historical reasons, it is generally implemented as an integral value representing the number of 
			// seconds elapsed since 00:00 hours, Jan 1, 1970 UTC (i.e., a unix timestamp). 
size_t 		// Also in this library
struct tm   // structure containing a calender date and time broken down into its components. Containing nine members of type int(in any order).
			
	// Member 			// Range/Meaning
	tm_sec				0-59
	tm_min				0-59
	tm_hour				0-23
	tm_mday				1-31
	tm_mon				0-11
	tm_year				// since 1900
	tm_wday				0-6  // Days since sunday
	tm_yday				0-365
	tm_isdst			// Daylight Saving Time flag
						// The Daylight Saving Time flag (tm_isdst) is greater than zero if Daylight Saving Time is in effect,
						// zero if Daylight Saving Time is not in effect, and less than zero if the information is not available.

// Macros constants
CLOCKS_PER_SEC		// Clock tick per second
NULL			// Also defined in this


// Time Manipulation
clock_t clock(void);	// Returns the processor time consumed by the program.
						// The value returned is expressed in clock ticks.
// Note that, to measure the actual processing time of a program, you should call this function two times, at the start and at the end.
// For eg: 

/*
	int main ()
	{
	  clock_t t;
	  int f;
	  t = clock();
	  printf ("Calculating...\n");
	  f = frequency_of_primes (99999);
	  printf ("The number of primes lower than 100,000 is: %d\n",f);
	  t = clock() - t;
	  printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
	  	// or
	  	printf("Executed ms: %f", (float)t);	// return in milliseconds (microseconds timer is not in C)
	  return 0;
	}
 */

time_t time(time_t *timer);		// Get the current calender time as a value of type time_t.
								// Returned value is in number of seconds.
								
/**
 * Example:
 	time_t timer;
 	time(&timer);	// Get current time, same as timer = time(NULL);
 */

double difftime(time_t end, time_t beginning);	// Calculates the difference in seconds between beginning and end.
time_t mktime(struct tm *timeptr);	// Returns the value of type time_t that represents the local time described by 
									// the tm structure pointed by timeptr (which may be modified).


// Time conversion
struct tm *localtime(const time_t *timer);	// A pointer to a tm structure with its members filled with the values that 
											// correspond to the local time representation of timer.
struct tm *gmtime(const time_t *timer);		// Same as above but return GMT timezone

char *asctime(const struct tm *timeptr);	// Convert tm structure to human readable string  Www Mmm dd hh:mm:ss yyyy

char *ctime(const time_t *timer);			// Conver time_t value to human readable string
											// Equivalent to asctime(localtime(timer));
											
size_t strftime(char* ptr, size_t maxsize, const char* format,
                 const struct tm* timeptr);
	// See Reference for formats 		// Format time as string





// Pseudo random number generators
void srand(unsigned int seed);		// The pseudo-random number generator is initialized using the argument passed as seed.
									// seed: An integer value
									// Two different initializations with the same seed will generate the same succession of results in subsequent calls to rand.
									// If seed is set to 1, the generator is reinitialized to its initial value and produces the same 
									// values as before any call to rand or srand.
// In order to generate random-like numbers, srand is usually initialized to some distinctive runtime value, 
// like the value returned by function time (declared in header <ctime>). This is distinctive enough for most trivial randomization needs
// Usually like this: srand(time(NULL));
l
int rand(void);		// Returns a pseudo-random integral number in the range between 0 and RAND_MAX.
/*
	A typical way to generate trivial pseudo-random numbers in a determined range using rand is to use the modulo 
	of the returned value by the range span and add the initial value of the range:
	v1 = rand() % 100;         // v1 in the range 0 to 99
	v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
	v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014 
 */

// Macros
RAND_MAX	// This value is library-dependent, but is guaranteed to be at least 32767 on any standard library implementation.