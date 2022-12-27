#include <cstdio>
#include <cstdarg>	// Required for variadic


// Variadic functions : functions (e.g. printf) which take a variable number of arguments.

// The declaration of a variadic function uses an ellipsis as the last parameter, e.g. int printf(const char* format, ...);
// See variadic arguments for additional detail on the syntax and automatic argument conversions.


/*
Accessing the variadic arguments from the function body uses the following library facilities:

Macros ( Defined in header <stdarg.h> )
va_start : enables access to variadic function arguments

va_arg : accesses the next variadic function argument

va_copy : (C99) : makes a copy of the variadic function arguments

va_end : ends traversal of the variadic function arguments


Type
va_list : holds the information needed by va_start, va_arg, va_end, and va_copy
(typedef)

*/

// first argument is int count of remaining args
// ... remaining args are doubles for average


double average(const int count, ...)
{
    va_list ap;
    int i;
    double total = 0.0;
    
    va_start(ap, count);
    for(i = 0; i < count; ++i) {
        total += va_arg(ap, double);
    }
    va_end(ap);
    return total / count;
}

// works like printf, format plus args
int message(const char * fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int rc = vfprintf(stdout, fmt, ap);
    puts("");
    va_end(ap);
    return rc;
}

int main() {
    message("This is a message");
    message("Average: %lf", average(5, 25.0, 35.7, 50.1, 127.6, 75.0));
    return 0;
}

// How Linking Happends ?
