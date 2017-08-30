// Conversion Specifier %m.pX or %-m.pX

/* m => indicate the minimum field width and specifies the minimum no of characters to print. For eg:
   p => has different meaning for X
*/


/*
#include <stdio.h>

int main()
{
	int n;
	float f;
	double d;
	char s[100];

	// input an integer 
	scanf("%d", &n);
	// print an integer, no formatting 
	printf("%d\n", n);
	// print an integer, padded on left with spaces to total 6 chars (i.e., if integer width is less than 6)
	printf("%6d\n", n);
	// print an integer, padded on right with spaces to total 6 chars 
	printf("%-6d\n", n);
	// print an integer, padded on left with zeroes to total 6 chars 
	printf("%.6d\n", n);

	// input a string (whitespace delineated) 
	scanf("%s", s);
	// print a string, no formatting 
	printf("%s\n", s);
	// print a string, padded with spaces on left to 20 chars 
	printf("%20s\n", s);
	// print a string, padded with spaces on right to 20 chars 
	printf("%-20s\n", s);
	// print a string, truncated after 3 chars 
	printf("%.3s\n", s);

	// input a single precision floating point number 
	scanf("%f", &f);
	// print a float, default precision is 6 places 
	printf("%f\n", f);
	// input a double precision floating point number 
	scanf("%lf", &d);
	// print a double, default precision is 6 places 
	printf("%f\n", d);
	// print a double, 2 places of precision 
	printf("%.2f\n", d);
	// print a double, 2 places of precision, padded with space to 10 
	printf("%10.2f\n", d);
	// print a double, use exponential notation if more than 3 digits 
	printf("%.3g\n", d);
	// Display a floating point in exponential format (scientific notation). p indicates (%m.pX) (X - is d, f, e, g)
	// how many digits should appear after the decimal point. 
	printf("%e", d);



	// In scanf(), `m` specifies the maximum no of character to store
	scanf("%2d", &n); // store only 2 character and neglect other character. Note that scanf() doesn't store whitespace.
	scanf(" %2d", &n); // It skip whitespace before inserting character 
}

*/