#include <stdio.h>
#include <ctype.h>



int main(void) {
    int num;
    char exprsn;
    scanf("%d", &num);    // Newline is necessary because exprsn stops at first newline character
    // or use getchar() here or use `%` modifier or use `%*` (suppression character, i.e, read the character but doesn't include it). See Book for details
    // because white-space characters is consume by %c, %s, % specifier of scanf().
    // If you use getchar() here, then suppose your input is like `1[space][\n]`  (here [space] refers to ' ' and newline to `enter`)
    // then [space] will be consumed by getchar(), and newline will be consumed by next call to scanf() with a `%s` or `%c` modifier
    while(num--) {
    scanf("%c", &exprsn);	// If you don't include newline or getchar() above, then it will consume by this
    // Use getchar(); here, others doesn't work (it's the loop)
    // scanf("%c[^\n]", &exprsn);   works only one time.
    printf("%c\n", exprsn);
    }
    return 0;

    /*
        Another thing:
        char *str;
        scanf("%[^1234567890]", str);       // Doesn't read character from 0-9
        scanf("%d[1234567890]", str);       // Read character from 0-9 only.
    */
}


/**
    Additional Problems where I have found these traps
    See C-9-P-8 (game of craps) - K.N. King

**/

/** 
    perfect way to use when reading character is :
    scanf("%c", &ch);
    getchar();

    or

    ch = getchar();
    getchar();

    or
    scanf("%[^\n]%*c", &ch);     // This also works best, for strings also. Mainly for storing strings.
                                // (Read all character not including newline, and %*c specifies ignores last character)
    scanf("%27[^\n]%*c", str);     // read character until newline, and store only 27 characters

    or (a simplified version of above)
    scanf("%c%*c", &ch);        // (another best) works for character only (ignores last character whatever it is)

    Whether it is in loop or not, it works as expected.
    The following works only once (so not for when scanf() is in loop)
    scanf("%c[^\n]", &ch);
    or
    scanf("%c%*", &ch);
    or 
    scanf("%c%", &ch);

**/