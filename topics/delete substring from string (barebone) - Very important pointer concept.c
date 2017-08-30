#include <stdio.h>
#include <stdbool.h>

bool delSubStr(char *str, char const *substr) {

}

int main(void) {
	char str[] = "ABCDE";
	char *substr = "CD";
	char *ptr = str;
	*ptr++;
	*ptr++;
	char *temp = ptr;
	*ptr++;
	*ptr++;
	*temp++ = *ptr++;
	*temp = '\0';
	printf("%s", str);
}