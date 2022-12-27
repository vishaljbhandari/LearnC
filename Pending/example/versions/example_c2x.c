
/*
 C2x
 C2x is an informal name for the next (after C18) major C language standard revision.
 It is not expected to be voted on until 2021.
 It adds a new principle to the "Original Principles" of C:

 "Application Programming Interfaces (APIs) should be self-documenting when possible.
 In particular, the order of parameters in function declarations should be arranged such that the size of an array appears before the array.
 The purpose is to allow Variable-Length Array (VLA) notation to be used.
 This not only makes the code's purpose clearer to human readers, but also makes static analysis easier.
 Any new APIs added to the Standard should take this into consideration."


 Features - Among proposed features:
 single-argument _Static_assert
 C++11 style attribute syntax
 extended binary floating-point arithmetic, decimal floating-point arithmetic
 memccpy(), strdup(), strndup() - similar to functions found in the POSIX and SVID C extensions
 char8_t type, in the same vein as char16_t and char32_t added in C11. (proposal N2231)

 Support
 The GCC 9 compiler has -std=c2x option to support this standard, as does Clang 9.0.

 */
