#include <stdio.h>
#include <ctype.h>

#define N 80

void getline(char *str, int n) {
	int ch;		// Int not char because it will large enough to hold EOF as EOF is any signed integer which is implementation defined
	/** 
		**This loop check for EOF, and newline. It terminate at newline and print only those character which are under n. 
		**Don't put n-- instead of --n because then there will be no space for nul character and therefore it is not considered as a string.
		** You can also check (and skip) for whitespace before beginning of the string using isspace() function.
	 **/
	while(--n > 0 && (ch = getchar()) != EOF && ch != '\n')
		*str++ = ch;
	if(ch == '\n')
		*str++ = ch;
	*str = '\0';
}

int main(void) {
	char ch[N];
	int i;
	int n_cntrl;
	int n_space;
	int n_digit;
	int n_alpha;
	int n_alnum;
	int n_lower;
	int n_upper;
	int n_punct;
	int n_print;
	int n_graph;
	int total;
	getline(ch, N);
	n_cntrl = n_space = n_digit = n_lower = n_upper = n_alpha = n_alnum = n_punct = n_print = n_graph = total = 0;
	for(i = 0; i < N; i++) {
		++total;
		if(iscntrl(ch[i]))
			++n_cntrl;
		if(isspace(ch[i]))
			++n_space;
		if(isdigit(ch[i]))
			++n_digit;
		if(isalpha(ch[i]))
			++n_alpha;
		if(isalnum(ch[i]))
			++n_alnum;
		if(islower(ch[i]))
			++n_lower;
		if(isupper(ch[i]))
			++n_upper;
		if(ispunct(ch[i]))
			++n_punct;
		if(isprint(ch[i]))
			++n_print;
		if(isgraph(ch[i]))
			++n_graph;
	}

	// Print the results

	if(total == 0)
		printf("No characters in the input!\n");
	else {
		printf("%.3f%% cntrl\n", (double)n_cntrl*100/total);
		printf("%.3f%% space\n", (double)n_space*100/total);
		printf("%.3f%% digit\n", (double)n_digit*100/total);
		printf("%.3f%% alpha\n", (double)n_alpha*100/total);
		printf("%.3f%% alphanumeric\n", (double)n_alnum*100/total);
		printf("%.3f%% lowercase\n", (double)n_lower*100/total);
		printf("%.3f%% uppercase\n", (double)n_upper*100/total);
		printf("%.3f%% punctuation\n", (double)n_punct*100/total);
		printf("%.3f%% print character\n", (double)n_print*100/total);
		printf("%.3f%% graph\n", (double)n_graph*100/total);
	}
}