/** Declaration for Structures, Unions and Enumerations  **/

// Syntax	
	struct tag { member-list } variable-list;

// Without Tag 
	struct {
		int a;
		char b;
		float c;
	} x, y; 	// one or more variables


// With Tag
	struct SIMPLE {
		int a;
		char b;
		float c;
	} x; 		
	// Now we can define more variables with this tag 
	struct SIMPLE y, z;


// Another way with typedef 
	typedef struct {
		int a;
		char b;
		float c;
	} Simple;
	// Define it like that:
	Simple y, z;		// Simple now use as a type name rather than structure tag


// Structure inside structures
	struct COMPLEX {
		float f;
		int a[20];
		long *lp;
		struct SIMPLE s;
		struct SIMPLE sa[10];
		struct elem {
			int len2;
		} s;
	};
	// Note here, `struct elem` is not hidden inside COMPLEX, it doesn't have block scope, so we access directly
		s.len2 = 10; 
	// Access members like that;
		// First declare a variable
		struct COMPLEX comp;
		// Now access it
		comp.a; 	comp.s.a;
		// Another access example
		comp.sa[4].c;	// access the SIMPLE structure of array[4]


// Arrow operator
	struct COMPLEX *cp;  // when we have a pointer, note that we have to initialize it (i.e., give address)
	// Access members like that;
		(*cp).f;  
		// or using arrow operator 
		cp->f;	// left operand must be a pointer

		cp->s // access the structure SIMPLE

// Self referencial Structures (but valid is pointer only)
		struct SELF_REF {
			int a;
			struct SELF_REF *b;	// don't use `struct SELF_REF b`. It is invalid
			int c;
		};

	// Using typdef
		typedef struct SELF_REF_TAG {
			int a;
			struct SELF_REF_TAG *b;	// not SELF_REF *b; because SELF_REF is not yet defined inside
			int c;
		} SELF_REF;

// Structure Initialization
	struct init {
		int a;
		short b[10];
		Simple c;
	} x = {
		10,
		{12, 3, 4, 6},
		{25, 'x', 1.9}
	};



// An illustration of Structure and Pointers

typedef struct {
	int a;
	short b[2];
} Ex2;

typedef struct EX {
	int a;
	char b[3];
	Ex2 c;
	struct EX *d;	// Note in order to access this structure `struct EX *d`, we can't use simple variable. 
					// Just like we can't use simple variable for pointer to int.
} Ex;

Ex x = {10, "Hi", {5, {-1, 25} }, 0};
Ex *px = &x;
// Accessing the member
px->a;	// is equivalent to (*px).a  or x.a
// The expression px->a is used when you have a pointer to a structure but don't know its name.

int *pi = &px->a;	// Now pi has address of x.a;

// Accessing a pointer member
Ex 	y;
x.d = &y;
// Now we can evaluate *px->d and it contains whole new blank structure.
// Use offsetof(type, member) macro to determine the actual position of a member in a structure. (defined in stddef.h)




// Structure as Function Arguments
//-----------------------------------------
	// A structure variable is a scalar and thus it is legal to pass a structure as an 
	// argument to a function, but this technique is often inappropriate.
typedef struct {
	char product[20];
	int quality;
	float unitPrice;
	float totalAmount;
} Transaction;

// Method - 1 - bad
void print_receipt(Transaction trans) {
	printf("%s\n", trans.product);
	printf("%d @ %.2f total %.2f\n", trans.quality, trans.unitPrice, trans.totalAmount);
}
// Called like this: print_receipt(current_trans);
// It it inefficient because size of Transaction is 32 bytes, which is copied into stack and later discarded.

// Method - 2 - good
void print_receipt(Transaction *trans) { // use const keyword, to disable modifying structure
	printf("%s\n", trans->product);
	printf("%d @ %.2f total %.2f\n", trans->quality, trans->unitPrice, trans->totalAmount);
}
// called like this: print_receipt(&current_trans);
// Here's a pointer to the structure is passed. The pointer is smaller (4 bytes) and therefore more efficient to push on the stack.

// Example - 2
	// Method - 1 - worst
	Transaction compute_total(Transaction trans) {
		trans.totalAmount = trans.quality*trans.unitPrice;
		return trans;
	}
	//called like this :  current_trans = compute_total(current_trans);
	// Here a structure is copied twice, first a copy of the argument is passed and modified. Then a copy of the 
	// modified structure is returned.

	// Method - 2 - good
	float compute_total(Transaction trans) {
		return trans.quality*trans.unitPrice;
	}
	// called like this: current_trans.totalAmount = compute_total(current_trans);

	// Method - 3 - best (using a pointer)
	void compute_total(Transaction *trans) {
		trans->totalAmount = trans->quality*trans->unitPrice;
	}
	// called like this: compute_total(&current_trans);
	// Directly modified the structure, so better performance.

// **[NOTE]**: Always pass pointer to structure, pass structure only when your structure is small.


// Important Example - Linked List
//----------------------------------
typedef struct _RSList {
	struct _RSList *link;
	void *data;
} RSList;

RSList* r_sListPrepend(RSList *list, void *data) {
	RSList *newNode = _new();	// here _new() is malloc(sizeof(RSList));
	newNode->data = data;
	newNode->link = list;
	return newNode;
}

// call it like this 
RSList *list = NULL;	
// Behind the scene
/*	
	`list` assigned, `newNode` which contains the address of whole new structure (in the form `&newStructure`)
	so, when we do this `newNode->data`, we are doing `(*&newStructure).data` or (*newNode).data`
*/
list = r_sListPrepend(list, "abc");
list = r_sListAppend(list, 1);

// You may think that this method is inefficient, but it's not. Although this return structure, but 
// if we remove return type then we have to add `list = newNode` line to above (this line doesn't work without double pointer, `*list = newNode`)
// So, here call with or without double pointer is equally efficient. So it's better to not use double pointer in this case, as it confuse the code.
// But you can use double pointer (**) to remove return type. And then it will be called like this:
	r_sListPrepend(&list, "abc");
// **[Note]** RSList is a global structure variable, so everything we done inside functions, it directly modify structure whether it return value or not.
	// But it also to be note that, we have passed copy of `list` in r_sListPrepend`, and in this function `newNode` already passed the end of link so
	// there is no way to access the data we added in the struct. That's in this case either return the node or use double pointer.
	// However suppose we have a case like below, then we can access the data:
void append(RSList *list, int value) {
	RSList *newNode = _new();
	RSList *last = list;
	newNode->data = value;
	newNode->link = NULL;
	if(list) {
		while(last->link) {
			last = last->link;
		}
		last->link = newNode;
	}
	// won't work, reason below:
	// else {
	// 	list = newNode;
	// }
}
	// Here we have already added some value previously, suppose with method Push(&root, 10);
	int main() {
		RSList *root = NULL;
		Push(&root, 10);
		append(root, 15);
		printf("%d", root->link->link->data);
	}

	// Note you have to add some value previously, otherwise it won't work. Here's why:
	/*
		Suppose RSList *root = NULL (initially, nothing was added), then at the first call of append,
		you assign `root` to `list`, Now, `list` is equal to NULL, so else part runs (in comment).
		Now what you do basically is assigning `newnode` to the `list` which has nothing but `root`
		which in turn has NULL (address of 0) and we know we cannot assign value at the address of NULL (i.e., (void*)0)

		However, when added values previously (your `root` is not NULL), it assign `newNode` in last->link not in `last` or in `list`,
		which already assign some value previously,

		Also, beginner often confuse with assigning to `list` and `list->link`. Here's an example:
		int main(void) {
			// First Example - See carefully
			Node *tmp = BuildOneTwoThree();	// {1, 2, 3};
			tmp = tmp->link;
			printf("%d", tmp->value);	// 2;
			tmp = tmp->link;
			printf("%d", tmp->value);	// 3;

			// Second example - Now see this
			Node *root = BuildOneTwoThree();	 {1, 2, 3};
			Node *ptr = root;
			ptr = ptr->link;
			printf("%d", ptr->value);	// 2;
			ptr = root;
			printf("%d", ptr->value);	// 1;

			// additional
			ptr = ptr->link;
			ptr->value = 5;		// {1, 5, 3};
			printf("%d", root->link->value);	// 5;
		}
		// Did you see the difference in above two example. In both, after `BuildOneTwoThree()`, `tmp` and `root` variable intialize two times,
		// but in first it forwarded`, and in second example it's not.

	*/




// Important Example - 2 [A confustion in linked list]
//------------------------------------------------------
	int main(void) {
	Node *root = BuildOneTwoThree();	// {1, 2, 3}
	Node *tmp = root;
	Node *root2 = BuildFourFiveSix();	// {4, 5, 6}
	
	tmp = tmp->link;
	// tmp = tmp->link;		// Now points to structure where `2` is stored
	printf("%d", tmp->value);	// 2;

	tmp = root2;	// Now we assign the `root2` in tmp, not in `tmp->link`
	// `tmp` contains {4, 5, 6}
	// By using double pointer you can assign to `*temp`
	printf("%d", tmp->value);	// 4;

	tmp = root;	// reset, now tmp contains {1, 2, 3}
	tmp->link = root2; // now tmp contains {1, 2, 3, 4, 5, 6}
	printf("%d", tmp->value);	// 1;
	printf("%d", tmp->link->link->link->value); // 4

}





// Bit Fields 
//-----------------------------------
	// Program that are intended to be portable should avoid bit fields

struct CHAR {
	unsigned ch : 7;
	unsigned font : 6;
	unsigned size : 19;
};
struct CHAR ch1;
// See more on book;

// Use a union to represent different values
struct _Variable {
	enum { INT, FLOAT, STRING } type;
	union {
		int i;
		float f; 
		char *s;
	} value;
};



// ENUMERATIONS
enum suit {
	CLUBS, DIAMONDS, HEARTS, SPADES
};


// initialization of enum constants
enum suit {
	CLUBS = 5, DIAMONDS = 6, HEARTS, SPADES = 10
} s1;	// variable is s1

// Also, variables also declared just like for struct and unions but of little (or no) use becuase enums can be accessed directly without
// variables like `#define` directive For eg: `printf("%d", CLUBS); 
// enum suit s2, s3;    
/*
	CLUBS = 5;
	DIAMONDS = 6;
	HEARTS = 2;	// Default
	SPADES = 10;
 */

// Question is what is the use of variables declaration in enums ?
/*
	1. You can use `++` operator to iterate through the list of enums, but it breaks if enums constant is initialized.
	2. In some compilers, you can only assign one of the enumerated constants.
	3. Better readability:
		// Example
		void Cards(enum suit sk);	// is better
		// than this
		void Cards(int sk);
 */
// You can use like this:
s1 = CLUBS;		// Note, here enums are directly access without using something like sk.CLUBS
				// It's almost useless and work like `#define` directive in C. But in C++, enums are useful.
if(s1 != DIAMONDS) {
	s1 = HEARTS;
}
// But all of these can be achieved through `int` ofcourse
// *** So, defining a variables for enums is mostly useless. ***

//**** Note: You cannot use enums like `s1.CLUBS`. It's wrong ****
// *** Because in C, enums are not strongly typed, so naming of enums is of no use ***
// See this: http://gnuvince.wordpress.com/2009/09/08/enums-in-c/

// Example
enum color {
	RED, GREEN, BLUE
};
enum color2 {
	RED, YELLOW, BLACK
};

// Cause error: because `RED` was previously declared.

// enums are integer constants, you cannot do
enum funny_number { n1 = 4.4, n2 = 4.6};	// wrong: `4.4` and `4.6` are of type float, only `int` values are recognized


// Returning enums from functions in C
enum tokens {
	NUMBER = 'n'
}
enum tokens scan(int a) {
	return a;
}
printf("%d", scan(10));	// 10;