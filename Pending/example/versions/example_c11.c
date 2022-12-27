/*
 ISO/IEC 9899:2011
 Known as C11(formerly C1X) (also called as C standard revision)
 Not to be confused with C++11.
 C11 (formerly C1X) is an informal name
 It replaced C99 (standard ISO/IEC 9899:1999)
 It has been superseded by C18 (standard ISO/IEC 9899:2018).

 C11 mainly standardizes features already supported by common contemporary compilers, and includes a detailed memory model to better support multiple threads of execution. Due to delayed availability of conforming C99 implementations, C11 makes certain features optional, to make it easier to comply with the core language standard.[2][3]

 The final draft, N1570, was published in April 2011.
 The new standard passed its final draft review on October 10, 2011
 and was officially ratified by ISO and published as ISO/IEC 9899:2011 on December 8, 2011,
 with no comments requiring resolution by participating national bodies.


 A standard macro __STDC_VERSION__ is defined with value 201112L to indicate that C11 support is available.
 Some features of C11 are supported by the GCC starting with version 4.6.
 Clang starting with version 3.1
 IBM XL C starting with version 12.1


 Changes from C99
 The standard includes several changes to the C99 language and library specifications, such as

 1) Alignment specification (_Alignas specifier, _Alignof operator, aligned_alloc function, <stdalign.h> header file)
 2) The _Noreturn function specifier and the <stdnoreturn.h> header file
 3) Type-generic expressions using the _Generic keyword. For example, the following macro cbrt(x) translates to cbrtl(x), cbrt(x) or cbrtf(x) depending on the type of x:
 #define cbrt(x) _Generic((x), long double: cbrtl,  default: cbrt, float: cbrtf)(x)
 4) Multi-threading support (_Thread_local storage-class specifier, <threads.h> header including thread creation/management functions, mutex, condition variable and thread-specific storage functionality, as well as <stdatomic.h>[10] for atomic operations supporting the C11 memory model).
 5) Improved Unicode support based on the C Unicode Technical Report ISO/IEC TR 19769:2004 (char16_t and char32_t types for storing UTF-16/UTF-32 encoded data, including conversion functions in <uchar.h> and the corresponding u and U string literal prefixes, as well as the u8 prefix for UTF-8 encoded literals).[11]
 6) Removal of the gets function, deprecated in the previous C language standard revision, ISO/IEC 9899:1999/Cor.3:2007(E).
 7) Bounds-checking interfaces (Annex K).
 8) Analyzability features (Annex L).
 9) More macros for querying the characteristics of floating point types, concerning subnormal floating point numbers and the number of decimal digits the type is able to store.
 10) Anonymous structures and unions, useful when unions and structures are nested, e.g. in struct T { int tag; union { float x; int n; }; };.
 11) Static assertions, which are evaluated during translation at a later phase than #if and #error, when types are understood by the translator.
 12) An exclusive create-and-open mode ("…x" suffix) for fopen. This behaves like O_CREAT|O_EXCL in POSIX, which is commonly used for lock files.
 13) The quick_exit function as a third way to terminate a program, intended to do at least minimal deinitialization if termination with exit fails.
 14) A new timespec_get function and corresponding structure in <time.h> with a degree of POSIX compatibility.
 15) Macros for the construction of complex values (partly because real + imaginary*I might not yield the expected value if imaginary is infinite or NaN).

 */

#include <stdio.h>

int main(void) {
	printf("Hello C11 %d\n", __STDC_VERSION__);

	return 0;
}

