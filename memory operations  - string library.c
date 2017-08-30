// Memory perform string operations
// From <string.h>
// 
// These are useful in cases where string is terminated with a null byte, because at first nul byte string stop performing operations.
/*
 For eg: char *s = "abcdef0lpn   sf as\0sdfdf";
 char str[20]; strcpy(str, s);		// Output: abcdef0lpn   sf as
 */

// Note that, these functions perform operations on bytes. (i.e. if destination and source are array of type int, 
// then you can write `num` like sizeof(source))

// You can also copy structures with these functions, which is not possible with other `str---` functions


void *memcpy(void *destination, const void *source, size_t num);
// Copies the values of `num` bytes from the location pointed by `source` directly to the memory block pointed by `destination`.
// The function doesn't check for any terminating null characters in `source`- it always copies exactly `num` bytes.
// Don't forget `num` size to be `num + 1` (+1 for terminating null bytes);

/*
	struct {
		char name[40];
		int age, 
	} person, person_copy;

	int main() {
		char myname[] = "Pierre de fermat";
		// using memcpy to copy string: 
		  memcpy ( person.name, myname, strlen(myname)+1 );
		  person.age = 46;

		 // using memcpy to copy structure: 
	    memcpy ( &person_copy, &person, sizeof(person) );

	    printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age );

	}
	// Output ::  person_copy: Pierre de Fermat, 46 
 */

void *memmove(void *destination, const void *source, size_t num);
// Perform similar operation like `memcpy` except it allows its source and destination to overlap.


int memcmp(const void *ptr1, const void *ptr2, size_t num);
// compares the length bytes of memory beginning at ptr1 to the bytes beginning at ptr2. The values are compared byte by byte
// as unsigned chararacters.

void *memchr(const void *ptr, int value, size_t num);
// Searches within the first num bytes of the block of memory pointed by ptr for the first occurence of value (interpreted as 
// unsigned char) and returns a pointer to it.


void *memset(void *ptr, int value, size_t num);
// Sets the first `num` bytes of the block of memory pointed by `ptr` to the specified `value`.
// For eg: memset(buffer, 0, SIZE); intialize the first SIZE bytes of the buffer to zero.

/*
 int main (){
  char str[] = "almost every programmer should know memset!";
  memset (str,'-',6);
  puts (str);
}
// Output:: ------ every programmer should know memset!
 */