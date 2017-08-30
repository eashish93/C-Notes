/**
 * BIT TWIDDLING TRICKS 
 * ==============================================
 */

/**
 10 			- 2
 100 			- 4
 1000			- 8
 10000			- 16
 100000			- 32
 1000000		- 64
 10000000		- 128
 etc...
**/


/** Extract/Test the first bit from the integer **/
	// Example:
	int k = 13;
	printf("%d", k & 1);	// This will extract the 0th bit from the k
	// Explaination
	/**
	 * 13 is 1101
	 * 	     0001
	 * 	    ------
	 * 	     0001		// This will extract the 0th bit
	 */


/** Determine if number is even or odd **/
	// Example:
	 if((n & 1) == 0) 
	 	printf("even");
	 else
	 	printf("odd");
	// Explanation
	/**
	 * As before, it will extract the first bit, and by this bit we can know that if number is even or odd
	 * Because only 0th bit will determine (if it is 1 then odd, else even). Think?
	 */


/** Extract/Test the nth bit from the integer **/
	// Example:
	 if(x & (1 << n)) 
	 	printf("nth-bit is 1");
	 else 
	 	printf("nth-bit is 0");
	// Explanation:
	/**
	 * 13 is 1101. And we have to check 2nd bit, so 13 & (1 << 2)
	 * 	  1101
	 * 	   100
	 * 	 ------
	 * 	  0100
	 * 	 ------		
	 * 	 So, 2nd bit is 1 or we can say 2nd bit is set
	 */



/** Set the nth-bit i.e., make it 1 **/
	// Example:
	int y = x | (1 << n)
	// Explanation:
	/**
	 * 13 is 1101. And we have to set 2nd bit, so 13 | (1 << 2)
	 *   1101
	 *    100
	 *   -----
	 *   1101		// No change, bet 2nd bit already on (or 1)
	 *
	 *  Now, try for 1st bit, so 13 & (1 << 1)
	 *  	1101
	 *  	  10
	 *  	----
	 *  	1111	// Now 1st bit is ON
	 */
	// If otherwise, we want to set it to zero if it already set to 1. then we XOR(^) operator. eg: 13 ^ (1 << n).
	// This is also called toggling of bit (x ^ (1 << n))
	



/** Unset the nth-bit. i.e., Turns on all the bits except nth-bit **/
	// Example:
	 int y = x & ~(1<<n)
	// Explanation:
	/**
	    01111111    (127 in decimal)
	&   11101111    (~(1<<4))
	    --------
	    01101111
	**/



/** Turn off the rightmost (i.e., first 1 bit from the right) 1-bit in a word, producing 0 if none **/
    // Formula: 
    int y = x & (x-1)
    /** Example 
    	1011000	 (88 in decimal)
    &  (1011000
    -   0000001)
    	-------
		1010000
    **/


/** Turn off the rightmost 0-bit in a word **/
	// Formula
	int y = x | (x + 1)
	/** Example 
	    1101
	 +     1
	    ----
	 	1110
	 &  1101
	    ----
	    1100
	    ----
		Adding `1` to any word, transform righmost 1's in a zero and first rightmost 0 in a 1.
	**/



/**
 * Basic Theorems
 */

// De-morgan's law (first two)
(X & Y & Z ...)` == X` | Y` | Z` ...   // Eg: ~(x & y) = ~x | ~y
(X | Y | Z ...)` == X` & Y` & Z` ...  // Eg: ~(x | y) = ~x & ~y


~(x + 1) = ~x - 1
~(x - 1) = ~x + 1
~(x^y) = ~x^y
~-x = x - 1
-~x = x + 1
~(x + y) = ~x - y
~(x - y) = ~x + y
-x = ~x + 1 = ~(x - 1)
~x = -x - 1
x + y = x - ~y - 1
	  = (x ^ y) + 2(x & y)
	  = (x | y) + (x & y)
	  = 2(x | y) - (x ^ y)
x - y = x + ~y + 1
	  = (x ^ y) - 2(~x & y)
	  = (x & ~y) - (~x & y)
	  = 2(x & ~y) - (x ^ y)
x^y = (x | y) - (x & y)

