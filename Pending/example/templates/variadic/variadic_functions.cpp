#include <iostream>
#include <cstdarg>
using namespace std;

/*
 Defined in header <cstdarg>

 Variadic functions are functions (e.g. printf) which take a variable number of arguments.

 To declare a variadic function, an ellipsis is used as the last parameter,
 e.g. int printf(const char* format, ...);

 See Variadic arguments for additional detail on the syntax, automatic argument conversions and the alternatives.

 To access the variadic arguments from the function body, the following library facilities are provided:

 va_start : enables access to variadic function arguments (function macro)
 va_arg : accesses the next variadic function argument (function macro)
 va_copy :  makes a copy of the variadic function arguments (function macro)
 va_end :  ends traversal of the variadic function arguments (function macro)
 va_list :  holds the information needed by va_start, va_arg, va_end, and va_copy (typedef)

 */

void simple_printf(const char *fmt...) {
	va_list args;
	va_start(args, fmt);

	while (*fmt != '\0') {
		if (*fmt == 'd') {
			int i = va_arg(args, int);
			cout << i << endl;
		} else if (*fmt == 'c') {
			// note automatic conversion to integral type
			int c = va_arg(args, int);
			cout << static_cast<char>(c) << endl;
		} else if (*fmt == 'f') {
			double d = va_arg(args, double);
			cout << d << endl;
		}
		++fmt;
	}

	va_end(args);
}

int main() {
	simple_printf("dcff", 3, 'a', 1.999, 42.5);
	cout << endl;
	simple_printf("dcff", 3, 1.999, 42.5, 4, 58, 47, 2.65, false);
	return 0;
}
