// scanf Format Codes
	// A format specifier for scanf follows this prototype:
	%[*][width][qualifiers]specifier

	// In brackets are optional
	// * : Indicates the data is to be read from the stream but ignored.
	// width: non-negative integer. It limits the number of input characters that will be read in order
	// 		  to convert this value.
	// qualifiers: One of hh, l, ll, j, z, t, L
	// specifier:
		/*
			c 			--- character
			i, d 		--- int (i determines the base of the value by its first character)
			u, o, x 	--- unsigned, o for octal, x - for hexadecimal
			e, f, g		--- float
			s 			--- string
			[xxx]		--- A number of characters specified between the brackets is only read ( dash (-) is not a character)
							eg: %[abc] -- read only from set including a, b and c
								%[a-z] -- specifies the range of characters. ( some compiler may not support this range)
			[^xxx]		--- Same as above but not between the brackets
			p  			--- Pointer address, A sequence of characters representing a pointer.
			n  			--- no input is consumed. %n conversions are not counted
			%			--- This code matches a single % in the input, which is discarded.
		*/
	


// printf format Codes
	// A format specifier for printf follows this prototype:
	%[flags][width][.precision][qualifiers]specifier

	/* 
	specifier			Output																	Example
	d or i				Signed decimal integer													392
	u					Unsigned decimal integer												7235
	o					Unsigned octal															610
	x					Unsigned hexadecimal integer											7fa
	X					Unsigned hexadecimal integer (uppercase)								7FA
	f					Decimal floating point, lowercase										392.65
	F					Decimal floating point, uppercase										392.65
	e					Scientific notation (mantissa/exponent), lowercase						3.9265e+2
	E					Scientific notation (mantissa/exponent), uppercase						3.9265E+2
	g					Use the shortest representation: %e or %f								392.65
	G					Use the shortest representation: %E or %F								392.65
	a					Hexadecimal floating point, lowercase									-0xc.90fep-2
	A					Hexadecimal floating point, uppercase									-0XC.90FEP-2
	c					Character																a
	s					String of characters													sample
	p					Pointer address															b8000000
	n					Same above (in scanf)	
	%					A % followed by another % character will write a single % to the stream.	%
	 */
	

	/**
	 * Flags: 
	 * 		`-`, `+`, 	-- Left justify and right justify (default is right)
	 * 		`[spaces]`, -- Padded with spaces
	 * 		`#`, 		-- See doc
	 * 		`0`			-- Left-pads the number with zeroes instead of spaces, 
	 * 						eg: printf("%05d", 22);		// print 00022
	 * 						   or you can use printf("%.5d", 22);	// print same as above 00022
	 */
	
	/**
	 * Width: 
	 * 	 `number`: Minimum number of characters to be printed. If the value to be printed is shorter than this number, 
	 * 	           the result is padded with blank spaces. The value is not truncated even if the result is larger.
	 */
	
	/**
	 * Precision:
	 * 	  `.number`	: For integer specifiers(d, i, u, o, x, X), it specifies the minimum number of digits to be written. If value 
	 * 				  to be written is shorter than this `number`, the result is padded with zeroes.
	 * 				  For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6).
	 * 				  For g and G specifiers: This is the maximum number of significant digits to be printed
	 * 				  For s: this is the maximum number of characters to be printed.
	 * 				  
	 *    `.*` : 	  The precision is not specified in the format string, but as an additional integer value argument preceding the 
	 *    			  argument that has to be formatted.
	 * 				  
	 */