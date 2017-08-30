// Bitwise Operations
// For More: 1) http://graphics.stanford.edu/~seander/bithacks.html
//			 2) http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/

	<<			left shift  (equivalent to multiplication by 2) 
	>>			right shift (equivalent to division by 2) 

	/*
		Example: 
		unsigned short i, j;
		i = 13			(binary 0000000000001101)
		j = i << 2		(binary 0000000000110100)  (equal to 52) (i.e. multiply by 2 two times)
		j = i >> 2		(binary 0000000000000011)  (equal to 3) (i.e. divide by 2 two times 13/4 == 3)
		// Note: Shifting is much faster than actual multiplication or division.
		Note: i >>= 2 is same as i = i >> 2,
			  i <<= 2 is same as i = i << 2
	 */
	/** WARNING ** -- Beware of shift like this: **/
			  a << -5
		// What does it mean? It is undefined. (on some machine it shift left 27 bits). So avoid this
	
	~		unary operator (bitwise complement)
	& 		bitwise and
	^		bitwise exclusive or (XOR)
	|		bitwise inclusive or (OR) (PIPE)


// `~` operator produces the complement of its operand, with zeros replaced by ones and ones replaced by zeros.
// `&` operator performs boolean `and` operation on all corresponding bits in its two operands.
// `^` and `|` operators are similar (both performs a Boolean `or` operation on the bits in their operands);
// however, `^` produces 0 whenever both operands have a `1` bit, whereas `|` produces 1.

	/*
		Example:
		0 ^ 0 = 0;      0 | 0 = 0;
		0 ^ 1 = 1;		0 | 1 = 1;
		1 ^ 0 = 1;      1 | 0 = 1;
		1 ^ 1 = 0; 	    1 | 1 = 1;
	 */
// Also note that these boolean bitwise operators checks on both operands not on single operands.
// (i.e. in the case of a || b, it checks for one of a or b, but in case of a | b, it checks for both a and b)


/* example */
	unsigned short i, j, k;
	i = 21;		// (binary : 0000000000010101)
	j = 56;		// (binary : 0000000000111000)
	k = ~i;		// k is now 65514 (binary : 1111111111101010)
	k = i & j;  // k is now 16	  (binary : 0000000000010000)
	k = i ^ j;  // k is now 45    (binary : 0000000000101101)
	k = i | j;	// k is now 61    (binary : 0000000000111101)
	
Precedence
	Highest   ~
			  &
			  ^
    Lowest	  |


/**
 * -------------------- Important tricks ----------------------
 */

/** 
 * Sometimes, you see the constant define as 
 * 0100, 0200, 0400 -- these are 64, 128, 256 in decimal (by converting from octal to decimal)
 */