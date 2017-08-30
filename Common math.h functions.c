// Important Math functions - for full see reference

	// absolute value
	double fabs(double x);
	double abs(double x), long double abs(long double x), float abs(float x);		// Note that, all the below function have these three types

	// Trigonometric functions
	double sin(double arg);		// where arg in radians
	double cos(double arg);
	double tan(double arg);
	double asin(double arg);		// arcsin i.e. inverse of sin
	double acos(double arg);
	double atan(double arg);
	double atan2(double y, double x);	// C99
	// Similar for hyperbolic functions: sinh, cosh, tanh, asinh, acosh, atanh


	// Power functions
	double sqrt(double arg);
	double pow(double base, double exp);
	double hypot(double x, double y);	// C99	- hypotenuse function


	// Exponential functions
	double exp(double arg);		// return e[euler, 2.7182818] raised to the given power arg
	double log(double arg);		// natural logarithm base e
	double log10(double arg);	// base 10 logarithm
	double log2(double arg);	// base 2 logarithm, C99
	double exp2(double arg);	// return 2 raised to the given power(2 power x);


	// Nearest integer floating point operations
	double ceil(double arg);
	double floor(double arg);

	// Max and min functions - C99
	double fdim(double x, double y);	// Positive difference between x and y
	double fmax(double x, double y);
	double fmin(double x, double y);

	// Basic operations (macros)
	isfinite(x)			// returns whether x is finite
	isinf(x)			// returns whether x if infinity
	isnan(x)			// returns whether x is not-a-number (not-a-number is 0/0 or negative square root)
	signbit(x)	
	isnormal(x)
	

// Other Integer arithmetics - From <stdlib.h>
int abs(int n);		
long int abs(long int n);
long long int llabs(long long int n);		// From C99

div_t div(int n, int denom);
ldiv_t div(long int n, long int denom);
lldiv_t div(long long int n, long long int denom);



// Macros
INFINITY
NAN
