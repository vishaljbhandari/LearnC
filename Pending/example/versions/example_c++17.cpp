/*

 C++17
 From Wikipedia, the free encyclopedia
 Jump to navigationJump to search
 Not to be confused with C17 (C standard revision).
 C++17 is a revision of the ISO/IEC 14882 standard for the C++ programming language.


 Contents
 1	History
 2	Removed
 3	New features
 3.1	Language
 3.2	Library
 4	Compiler support
 5	Library support
 6	See also
 7	References
 History
 Before the C++ Standards Committee fixed a 3-year release cycle, C++17's release date was uncertain. In that time period, the C++17 revision was also called C++1z, following C++0x or C++1x for C++11 and C++1y for C++14. The C++17 specification reached the Draft International Standard (DIS) stage in March 2017.[1][2] This DIS was unanimously approved, with only editorial comments,[3] and the final standard was published in December 2017.[4] Few changes were made to the C++ Standard Template Library, although some algorithms in the <algorithm> header were given support for explicit parallelization and some syntactic enhancements were made.

 Removed
 This revision of C++ not only added new features but also removed a few.

 Removal of trigraphs.[5][6]
 Removal of some deprecated types and functions from the standard library, including std::auto_ptr, std::random_shuffle, and old function adaptors.[7][8] These were superseded in C++11 by improved facilities such as std::unique_ptr, std::shuffle, std::bind, and lambdas.
 Removal of the (formerly deprecated) use of the keyword register as a storage class specifier.[9] This keyword is now reserved and unused.
 New features
 C++17 introduced many new features. The following lists may be incomplete.

 Language
 Making the text message for static_assert optional[10]
 Allow typename (as an alternative to class) in a template template parameter[11]
 New rules for auto deduction from braced-init-list[12][7]
 Nested namespace definitions, e.g., namespace X::Y { … } instead of namespace X { namespace Y { … } }[7][13]
 Allowing attributes for namespaces and enumerators[14][15]
 New standard attributes [[fallthrough]], [[maybe_unused]] and [[nodiscard]][16]
 UTF-8 (u8) character literals[14][17] (UTF-8 string literals have existed since C++11; C++17 adds the corresponding character literals for consistency, though as they are restricted to a single byte they can only store ASCII)
 Hexadecimal floating-point literals[18][19]
 Constant evaluation for all non-type template arguments[14][20]
 Fold expressions, for variadic templates[14][21]
 A compile-time static if with the form if constexpr(expression)[22]
 Structured binding declarations, allowing auto [a, b] = getTwoReturnValues();[23]
 Initializers in if and switch statements[24]
 copy-initialization and direct-initialization of objects of type T from prvalue expressions of type T (ignoring top-level cv-qualifiers) shall result in no copy or move constructors from the prvalue expression. See copy elision for more information.
 Some extensions on over-aligned memory allocation[25]
 Class template argument deduction (CTAD), introducing constructor deduction guides, eg. allowing std::pair(5.0, false) instead of requiring explicit constructor arguments types std::pair<double, bool>(5.0, false) or an additional helper template function std::make_pair(5.0, false).[26][27]
 Inline variables, which allows the definition of variables in header files without violating the one definition rule. The rules are effectively the same as inline functions
 __has_include, allowing the availability of a header to be checked by preprocessor directives[28]
 Value of __cplusplus changed to 201703L[29]
 Exception specifications were made part of the function type[30]
 Library
 Most of Library Fundamentals TS I, including:[31][32]
 std::string_view, a read-only non-owning reference to a character sequence or string-slice[33]
 std::optional, for representing optional objects, a data type that may not always be returned by a given algorithm with support for non-return
 std::any, for holding single values of any type
 std::uncaught_exceptions, as a replacement of std::uncaught_exception in exception handling[34][14]
 New insertion functions try_emplace and insert_or_assign for std::map and std::unordered_map key-value associative data structures[35][36]
 Uniform container access: std::size, std::empty and std::data[36][37]
 Definition of "contiguous iterators"[36][38]
 A file system library based on boost::filesystem[39]
 Parallel versions of STL algorithms[40]
 Additional mathematical special functions, including elliptic integrals and Bessel functions[41]
 std::variant, a tagged union container[42]
 std::byte, allowing char to be replaced for data types intending to model a byte of data as a byte rather than a character[43]
 Logical operator traits: std::conjunction, std::disjunction and std::negation[44]
 Compiler support
 GCC has had almost complete support for C++17 language features since version 7. Some library features are still not supported.[45]
 Clang 5 and later implement all the features of C++17.[46]
 Visual Studio 2017 15.7 (MSVC 19.14) supports almost all of C++17.[47][48]
 Library support
 libstdc++ since version 9.1 has complete support for c++17 (8.1 without Parallelism TS and referring to C99 instead of C11) [49]
 libc++ as of version 9 has partial support for c++17, with the remainder "in progress" [50]
 MSVC Standard Library since 19.15 complete support for c++17 except for "Elementary String Conversions" and referring to C99 instead of C11.[51]
 See also

 */

#include <stdio.h>

int main(void) {
	printf("Hello C99 %d\n", __STDC_VERSION__);

	return 0;
}

