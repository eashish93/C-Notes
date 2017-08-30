#include <stdio.h>
#include <string.h>

static char const *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", NULL};
static char const *sDigits[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", NULL};
static char const *tens[] = {"", "Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", NULL};
static char const *magnitudes[] = {"", "Hundred", "Thousand", "Million", "Billion", "Quadrillion", "Quintillion", NULL};

int main(void) {
	char sAmount[100];
	int number;

	int nHundred, nTen, nOne;
	printf("%d", 990%10);


}