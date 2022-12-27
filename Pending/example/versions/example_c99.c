/*
 ISO/IEC 9899:1999
 C99 (previously known as C9X)
 It extends the previous version (C90) with new features for the language and the standard library,
 and helps implementations make better use of available computer hardware,
 such as IEEE 754-1985 floating-point arithmetic, and compiler technology.
 The C11 version of the C programming language standard, published in 2011, replaces C99.


 History
 After ANSI produced the official standard for the C programming language in 1989, which became an international standard in 1990, the C language specification remained relatively static for some time, while C++ continued to evolve, largely during its own standardization effort. Normative Amendment 1 created a new standard for C in 1995, but only to correct some details of the 1989 standard and to add more extensive support for international character sets. The standard underwent further revision in the late 1990s, leading to the publication of ISO/IEC 9899:1999 in 1999, which was adopted as an ANSI standard in May 2000. The language defined by that version of the standard is commonly referred to as "C99". The international C standard is maintained by the working group ISO/IEC JTC1/SC22/WG14.

 Design
 C99 is, for the most part, backward compatible with C89, but it is stricter in some ways.

 In particular, a declaration that lacks a type specifier no longer has int implicitly assumed. The C standards committee decided that it was of more value for compilers to diagnose inadvertent omission of the type specifier than to silently process legacy code that relied on implicit int. In practice, compilers are likely to display a warning, then assume int and continue translating the program.

 C99 introduced several new features, many of which had already been implemented as extensions in several compilers:

 inline functions
 intermingled declarations and code: variable declaration is no longer restricted to file scope or the start of a compound statement (block), facilitating static single assignment form
 several new data types, including long long int, optional extended integer types, an explicit boolean data type, and a complex type to represent complex numbers
 variable-length arrays (although subsequently relegated in C11 to a conditional feature that implementations are not required to support)
 flexible array members
 support for one-line comments beginning with //, as in BCPL, C++ and Java
 new library functions, such as snprintf
 new headers, such as <stdbool.h>, <complex.h>, <tgmath.h>, and <inttypes.h>
 type-generic math (macro) functions, in <tgmath.h>, which select a math library function based upon float, double, or long double arguments, etc.
 improved support for IEEE floating point
 designated initializers (for example, initializing a structure by field names: struct point p = { .x = 1, .y = 2 };)[5]
 compound literals (for instance, it is possible to construct structures in function calls: function((struct x) {1, 2}))[6]
 support for variadic macros (macros with a variable number of arguments)
 restrict qualification allows more aggressive code optimization, removing compile-time array access advantages previously held by FORTRAN over ANSI C[7]
 universal character names, which allows user variables to contain other characters than the standard character set
 keyword static in array indices in parameter declarations[8]
 Parts of the C99 standard are included in the current version of the C++ standard, including integer types, headers, and library functions. Variable-length arrays are not among these included parts because C++'s Standard Template Library already includes similar functionality.


 */

#include <stdio.h>

int main(void) {
	printf("Hello C99 %d\n", __STDC_VERSION__);

	return 0;
}
