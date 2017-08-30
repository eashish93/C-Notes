
// Header file <limits.h>
CHAR_BIT	Number of bits in a char object (byte)	8 or greater*
SCHAR_MIN	Minimum value for an object of type signed char	-127 (-2^7+1) or less*
SCHAR_MAX	Maximum value for an object of type signed char	127 (2^7-1) or greater*
UCHAR_MAX	Maximum value for an object of type unsigned char	255 (2^8-1) or greater*
CHAR_MIN	Minimum value for an object of type char	either SCHAR_MIN or 0
CHAR_MAX	Maximum value for an object of type char	either SCHAR_MAX or UCHAR_MAX
MB_LEN_MAX	Maximum number of bytes in a multibyte character, for any locale	1 or greater*
SHRT_MIN	Minimum value for an object of type short int	-32767 (-2^15+1) or less*
SHRT_MAX	Maximum value for an object of type short int	32767 (2^15-1) or greater*
USHRT_MAX	Maximum value for an object of type unsigned short int	65535 (2^16-1) or greater*
INT_MIN		Minimum value for an object of type int	-32767 (-2^15+1) or less*
INT_MAX		Maximum value for an object of type int	32767 (2^15-1) or greater*
UINT_MAX	Maximum value for an object of type unsigned int	65535 (2^16-1) or greater*
LONG_MIN	Minimum value for an object of type long int	-2147483647 (-2^31+1) or less*
LONG_MAX	Maximum value for an object of type long int	2147483647 (2^31-1) or greater*
ULONG_MAX	Maximum value for an object of type unsigned long int	4294967295 (2^32-1) or greater*
LLONG_MIN	Minimum value for an object of type long long int	-9223372036854775807 (-2^63+1) or less*
LLONG_MAX	Maximum value for an object of type long long int	9223372036854775807 (2^63-1) or greater*
ULLONG_MAX	Maximum value for an object of type unsigned long long int	18446744073709551615 (2^64-1) or greater*


// Header file <stdint.h>

SIZE_MAX	Maximum value of size_t	(2^64-1), or higher