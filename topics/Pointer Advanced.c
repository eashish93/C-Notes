/* ------- Pointer - 1 Illustration ------- */


// Declaration
//-----------------------------------
int *a; 	// Declare pointer to int
int * 	a;	// Same as above (free form)
int *a, b, c;	// Declare only `a` to be pointer to int, `b and c` are simple integer
char *msg = "string literal";	// pointer to char; (constant cannot be modify);
char const *msg = "better use with const because string literal can't modify"; // if you don't use with const, then it gives warning in C++.
	// or
char *msg;
msg = "string literal";

typedef int* ptr_t
ptr_t a, b, c;	// Declare all to be pointer to int

#define int* ptr_t	// wrong
#define ptr_t int* // right
ptr_t a, b, c;	 // Declare only a to be pointer to int



// Size of a Pointer
//----------------------------
	/*
	On 32-bit system size of pointer is 4, (whether it is pointer to char or int).
		On 64-bit, it is 8.
	
	It means that in array of pointer to char (i.e., char *a[] = {"strings", "strings2"}), every
	new strings literal has an address equal to `previous address + size of pointer` 
	Suppose "strings" has address 123456, so "strings2" has an address of 123460


	*/

// Constants 
//-----------------------------------
int const a = 15;
	// or
const int a = 15;

int const *pci;	// is a pointer to constant integer. You cannot change the value to which it points
				// also called low-level const in C++
/** Example: **/
	int c = 15, d = 10;
	int const *pci = &c;
	*pci = 10;	// Error: assignment of read-only location, because this directly modifies &c which prohibited due
				// to low-level const.
	pci = &d; 	// valid, because now we assign new address (and then we can't do this *pci = 10)

int *const pci; // is a constant pointer to int. You cannot change the pointer value (cannot change the address), but integer value can be modified.
				// also called top-level const in C++.
/** Example: **/
	int c = 15, d = 10;
	int *const pci = &c;
	pci = &d;	// Error: assignment of read-only variable
	*pci = d; 	// valid, 
	*pci = 100; // valid also

int const *const pci; 	// It combine both of above
const int *const pci; // same as above
/** Example */
	int const *const pci = &c; // valid
	pci = &d; *pci = d; // not valid both.



#define N 50		// This can be used anywhere, also in declaring the size of arrays.
int const N = 50;	// This cannot be used in size of arrays.
typedef N 50;		// Wrong
enum {N = 50};		// Works same as define directive, but #define is preferred. Use this, if you define grouping of variables.




// Each location in memory is identified by a unique address.
// Each location is memory contains a value.

/** Example **/ 
// -- Basically, we can call `a` as 0th level pointer, and `pt` as 1st level pointer.
// The C language gives us a `& and *` operator for assigning and accessing address and values respectively.
// In `int *pt = &a;` `pt` gives the address of `a` and `*pt` gives the content of `a`.
// Also, `pt` has it own address in memory, which can be seen by `&` operator.
int *pt; 	// pt -> is the pointer to int, which is not initialized and has contain arbitrary address.
			// &pt -> also contain arbitrary address (it's own address).
int a;		// a -> uninitialized and contain arbitrary address (sometimes we called it a garbage value).
			// &a -> container arbitrary address. (it's own address)
pt = &a;	// Here, `pt and &a` both contain same address which is arbitrary
pt = a;		// illegal, (gives warning), but now `pt and a` bot contain same arbitrary address.
			// Check it by printf("%p\t%p\t%p", pt, a, &a);




// Uninitialized Pointer
//-------------------------------------
// Pointer variable takes only address as its value, which simple variable take a value.
int *ptr = 12;	// Here ptr -> has value 12, which is the address (compiler gives a warning). We know `ptr` points to some address. 
				// and in that address, 12 is stored.
				// We can access it by `printf("%d", ptr);` gives warning, but print 12.
int *pt;
*pt = 12;		// [Gives Error]. Here `pt` is uninitialized, and we store `12` to the address where `pt` indirects, but
				// `pt` has arbitrary address of something that can be somewhere which is not inside in the program memory
				// (outside of the memory). So pointer cannot indirect it.
				// In short: [We cannot access those address by indirection, which is not in the scope of current program memory 
				// 			  because of OS restriction and mainly compiler restriction.]
				// Sometimes, pointer contain legal address which is in the scope.
int a;	// Suppose its address `2685843`, now we can store by using this also:
*(int*)2685843 = 14;	// printf("%d", a); => 14




// Pointer to Pointer (or pointer to a "pointer to a int")
//--------------------------------------------------------
int a = 12;		// printf("%d", a); => 12
int *b = &a;	// printf("%d", *b); => 12
int **c = &b;	// printf("%d", **c); => 12
				// printf("%d", *c);  => //  address of a i.e., `&a`

// **[Note]** --> We cannot obtain the address of a variable declared with `register`.
// **[Note]** --> We cannot use `&a or &b or &c` as L-value, because the compiler doesn't have any way of knowing.



// Conversions
//-------------------------------------------
// `char` and short is always converted to int 
// float always promoted to `double`
/** Example **/
	char ch = 'a';
	int a = 12, total;
	total = ch + a;	// => 109;




// Consider the following declaration:
	int strlen(char *str);
	int strlen(char str[]);
// Both are equivalent and both correct. But the more correct is the pointer version. 
// Also, sizeof(str) produce the size of a pointer to a character, not the size of the array.

// When initializing an array that is local to a function(or block), think carefully about 
// whether it should be reinitialized each time the function is entered. If the answer is no,
// then declare the array `static` so that the initialization can be performed once before
// the program begins.




// String literal vs Character array vs Character constants
//---------------------------------------------------------
// A null character ('\0') (whose bits are all zero) is represented by `0` in integer.
// A character constant ('0') is represented by `48` in integer
char ch = 'a';	// A character constant, represented by an integer.
char *str = "abc";	// A string literal (in memory `a b c \0`). Cannot be modified.
					// str --> has the address where `a` is stored.
					// Note that: `abc` has consequtive address, so str+1, has address of `b` and so on.
char str[] = "abc";	// A character array (in memory `a b c \0`)
char ch = "abc"[2];	// ch -> stored the value 'c';




// Arrays - Single and Multi-dimensional (with casting)
//-------------------------------------------------

// Consider this:
int a[10];
int *ptr = &a[0]; 
	//or
int *ptr = a;	// because a == &*(a+0);
// Now, we know that a[0], a[1], .... are all scalars and here's how a == &*(a+0);
// If we take int b = a[0] which is equal to *(a+0), first points to that location
// and by using `&` operator, we get that address.
// So it points to the first element of the array.
// It's type is `int*`

// Now, what `&a` points to?
// It points to the entire array, it's type is `int(*)[]`. 
// But note that, `a or &a[0] and &a` points to the same address.
int *ptr2 = (int*)&a;	// Right
int *ptr3 = &a;		// Wrong: Incompatible pointer type.




// For Two Dimensional Array
int c[10][20];
int *ptr2 = &c[0][0];  // or c[0] are equal
					   // Also, `c` and &c[0] are equal
// Consider this:
// c --> points to array of 20 integer of 0th row.
// (c + 1) --> (or `&c[1]`) - points to array of 20 integer of 1st row
// Does it legal? 
int *ptr = &c[0]; // Wrong, because `c` is a pointer to array of 20 integer
				  // and `ptr` is a pointer to integer only
// Using cast can help to avoid warning and parse it correctly

int *ptr = (int*)&c[0]; // or (int*)c;	// because first it takes to the address of array of c[0] then 
						// casting make it to point to this address of c[0][0];
printf("%d", *ptr);	// ==> the value of c[0][0];
printf("%d", *(int*)&c[0]);	// or *(int*)c;


// or better way is to define like that:
int (*p)[20] = c;
	// or
int p[][20] = c;

// **[Note]**: What is the type of &a in 2d-array?
// &a is of int(*)[][]. We cannot cast it to int *ptr = (int*)&a; 
// a or &a[0] is of int(*)[]
// &a[0][0] or *a is of int*;

// But in array of pointer to char `&a[0] or a` is of type (char**)


// ***[Note]***: In 1D-Array, a or &a[0] and &a have same address
// In 2d-Array, a or &a[0], &a[0][0] or *a and &a have same addresses.




// Void Pointer (Generic Pointer) & casting
//-------------------------------------

// When a variable is declared as being a pointer to type `void` it is known as generic pointer.
// Since, we cannot have a variable of type `void`, the pointer will not point to any data 
// and therefore cannot be deferenced and cannot do pointer arithmetic. You have to cast it back for this.
// This is very useful when you want a pointer to point to data of different types at different times.
// `void*` can be converted to `any pointer type without explicit cast`. You have to only cast when you deference it.
// However, in most of the code, you'll find casting (even when no deferencing (like in glib qsort implementation)).
// This is done to make compatibility with C++.
// As we know, pointer only take address and `void*` can take any data type address, so whatever is stored in it is only
// a address. That's why `void*` is used for storing multiple data types.
// sizeof(void) -- is illegal. However, GCC print 1.
/** Example -- 1 **/
int main() {
	int i = 5;
	char ch = 'a';
	char *str = "hello";
	void *data;
	data = &i;  // Can be converted (and take) to any data type without explicit cast. (you see example of malloc, calloc etc...)
	printf("The [data] points to the integer %d\n", *(int*)data);	// first cast, then deference

	data = &ch;
	printf("The [data] points to the character %c\n", *(char*)data);	

	data = str;
	printf("%s", (char*)data);	// without cast gives only warning for this, because here deferencing is not done.

	int *ptr;
	ptr = data; 	// valid; (without cast)
	printf("But this is not valid: %d", *data); // cast it before deferencing *(int*)data
	printf("This is valid: %d", *ptr); // Only if data point to some address.

	void *data2 = 42;	// wrong, void pointer points to nothing



	// Example - 2 (assigning void to double pointer and vice-versa)
	int k = 3;
	int *a = &k;
	void *p = a;	// Right  (it works simply as `int *p = a`)
	printf("%d", *(int*)p); 	// Now cast to deference it.
	// But now see this:
	void *l = &a;	// If `l` is int, then this is absolutely wrong. But in this case, this is right as void can be converted to any pointer (data) type 
					// without explicit cast. Here it works as `int **l = &a`.
	printf("%d", **(int**)l);	// 3, 	(not *(int**)l --> this print the address)

	//// Example - 3 ////	
	int k = 3;
	int *l = &k;
	void *a = &l;	 // int **a = &l (automatic conversion); (if you do void *a = l, then you can't do int **c = &a, because `a` is automatically convert
					// to **a to match the type of `c`)
	int **c = a;	// now, int **c = a, (where int **a)
	printf("%d", **c);


	// Another example (a trick to save integer value and use it as like address) - See below also 
	int d = 5;
	int *ptr =(int*)d;	// or (void*)d;
	printf("%d", ptr);	// 5;
	// what we done above is cast to pointer to int (to save the value of d), 
	// Now `(int*)d` means `ptr` stores the address `d` which is `5` not address of `d` where `5` stored.
	// This means it `5` refers to the address. 
	// (i.e., we actually store the address to use it as a value).
	
	// Note: The above trick, is only limit to 32 bit integers (because size of pointer is 4).
	// Also size of pointer >= size of integer
	
	// This is useful when you want to save the integer and don't want to use *(int*)d, to print the value.
	// (See glib documentation (linked list))
}

/** Second Example - Very Important **/
	bool find_char(void *str, char value) {	// Note this line, we cannot use char *str here, (this only takes address)
											// If you do, then you have to cast `a` to `(char*)a`
		// For each string in the list
		char *strings = (char*)str;	// Here we cast because, str has type char(*)[] 
									// (but note casting is not neccessary here as void* automatically do it.)
		while(strings != NULL) {	
			// Look at each character in the string to see if it is the one we want.
			while(*strings != '\0')
				if(*strings++ == value)
					return true;
			strings++;
		}
		return false;
	}
	// Test
	int main(void) {
		char *a[] = {"foo", "bar", "john", "amit", "rohit", "ashish", NULL};
		find_char(a, 'a')?printf("true"):printf("false");	// This `a` (also a[0]) contain the address of "foo" and have type char(*)[] (for `a` only)
															// &a[0][0] or `a[0]` is of type char(*)
		return 0;
	}

/** -----Example 3--------- **/
int compareInts(void const *a, void const *b) {
	if(*(int*)a == *(int*)b)		// here we cast (necessary here) because we do pointer arithmetic here and also we use indirection here.
		return 0;
	else 
		return 1;
}

/** ------- Example 4 - Very Important ----------- **/
// Swap function to swap any type of data using generic pointers
void swap(void *a, void *b, size_t size) {
	char *__a = a, *__b = b;	// Because we use deferencing later, so need conversion here.
	do {
		char __tmp = *__a;
		*__a++ = *__b;
		*__b++ = __tmp;
	} while(--size > 0);

}
// Things to note in this example: 
/*
	1. `a and b` must be of same type (i.e., either both int, char, struct etc...)
	2. Third argument `size` take the size of data type (i.e., for int sizeof(int))
	3. We can do this also `void swap(char *a, char *b, size_t size)` but user will think of `char` data type only. So not recommended
	4. We use double-dash inside function with the same name. This is the way of writing private variables in OOP
 // ---- How it works ----
 	Suppose we have two large variables `unsigned int c = 12345678, d = 9848848` for swapping. Now, 
 	here's how it is done. `swap(&c, &d, sizeof(int))`. sizeof(int) is 4 and sizeof(char) is 1.
 	So, inside the function, char increment byte until `size` argument is equal to zero and in 
 	each byte it transfer the value of variable `c and d` (1 byte only takes upto 3 digits (non-negative and < 128) numbered value).

	Also, you can swap string literal. Note string literal are not modified, only its address are swapped.
	char *a[] = {"ashish", "golu", "jayant", "himani", "shivam"};
	swap(&a[0], &a[1], sizeof(char));		// or swap(a, a+1, sizeof(char*));

*/

// Another way to write swap function using defined directive (taken from glibc qsort)
/*
#define SWAP(a, b, size)						      \
  do									      \
    {									      \
      register size_t __size = (size);					      \
      register char *__a = (a), *__b = (b);				      \
      do								      \
	{								      \
	  char __tmp = *__a;						      \
	  *__a++ = *__b;						      \
	  *__b++ = __tmp;						      \
	} while (--__size > 0);						      \
    } while (0)

*/
/** [NOTE]** This cannot be called without casting, because here void* (generic) pointer is not used **/
	swap((char*)&a[0], (char*)&a[1], sizeof(char));		// cast it with the char* or also (void*) is valid because in function it
														// converted to char*
// Note that: If sizeof(int) == 4*sizeof(char); (32-bit system), then when do this:
	int c = 123456;
	char *d = (char*)&c;
	printf("%p\t%p\t%p\t%p", (d), (d+1), (d+2), (d+3));	// Print the address of total int (let address be 10, 11, 12, 13)
	printf("\n%p", &c);	// print the first address only. (now it points to 10 only)




// We can cast an integer to `pointer to int` but this result to program termination 
// because of accessing address which is not permitted by program memory.
int num = 8;
int *ptr = (int*)num;		// or (void*)num   ---- also valid

// Casting a pointer to int and then back to pointer has never been considered a good practice.
// Note, also this is different from casting to and from void pointer.
// Also, you can use union instead of int, to represent multiple data types.
// Example of casting:
ptr = &num;
printf("Before %p\n", ptr);
int tmp = (int)ptr;
ptr = (int*)tmp;
printf("After: %p\n",ptr);

// To Access a special address of video memory (an example only);
#define VIDEO_BASE 0xB8000
int *video = (int*)VIDEO_BASE;	// Assign the video address
*video = 'A';		// Store 'A' character in that address.

// Another Example:
int a; 	// Suppose it's address is 0028FF18 (in hexa-decimal) or 2686744 (in decimal format) (Use '%p', for hexa-decimal)
int *pt = (int*)0x28FF18;  // or (int*)2686744
*pt = 'A';	// Put that character in that address;
printf("%d", *pt);	// Print 97 (in ASCII code)
printf("%d", a);	// 97




// Little Endian and Big Endian
//------------------------------------------
	// Endians refers to the order of bytes in a unit of memory. Two types are Little and Big Endian.
	// Little Endian, refers to least significant byte is stored in the lowest address of the four bytes.
	// Big Endian is opposite of little Endian.

// Example - to determine endian of a machine
int num = 0x0028FF18;
char *pc = (char*)&num;
for(int i = 0; i < 4; i++) {
	printf("%p: %2x\n", pc, (char)*pc++);
}