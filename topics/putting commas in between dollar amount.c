#include <stdio.h>
#include <string.h>


void dollars(char *dst, char const *src) {	// src point to the characters to be formatted(assumption: these are all digits)
	if(dst == NULL || src == NULL) 
		return;
	int len = strlen(src);
	*dst++ = '$';

	if(len >= 3) {
		int i;
		for(i = len - 2; i > 0;) {
			*dst++ = *src++;
			if(--i > 0 && i % 3 == 0) 	
				*dst++ = ',';
		}
	}
	else
		*dst++ = '0';

	*dst++ = '.';
	*dst++ = len < 2 ? '0' : *src++;
	*dst++ = len < 1 ? '0' : *src;
	*dst = 0;

}

int main(void) {
	char dest[20];
	char *src = "12345678";
	dollars(dest, src);
	printf("%s", dest);

}