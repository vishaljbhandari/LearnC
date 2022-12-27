/*
 The C Preprocessor is not a part of the compiler, but is a separate step in the compilation process.
 In simple terms, a C Preprocessor is just a text substitution tool and it instructs the compiler to do required pre-processing before the actual compilation.
 We'll refer to the C Preprocessor as CPP.

 All preprocessor commands begin with a hash symbol (#).
 It must be the first nonblank character, and for readability, a preprocessor directive should begin in the first column.
 The following section lists down all the important preprocessor directives −

 #define : Substitutes a preprocessor macro.
 #include : Inserts a particular header from another file.
 #undef : Undefines a preprocessor macro.
 #ifdef : Returns true if this macro is defined.
 #ifndef : Returns true if this macro is not defined.
 #if : Tests if a compile time condition is true.
 #else : The alternative for #if.
 #elif : #else and #if in one statement.
 #endif : Ends preprocessor conditional.
 #error : Prints error message on stderr.
 #pragma : Issues special commands to the compiler, using a standardized method.


 Predefined Macros
 ANSI C defines a number of macros. Although each one is available for use in programming, the predefined macros should not be directly modified.

 __DATE__  The current date as a character literal in "MMM DD YYYY" format.
 __TIME__  The current time as a character literal in "HH:MM:SS" format.
 __FILE__  This contains the current filename as a string literal.
 __LINE__  This contains the current line number as a decimal constant.
 __STDC__  Defined as 1 when the compiler complies with the ANSI standard.

 */

#include <stdio.h>

int main() {

#define MAX_ARRAY_LENGTH 20
// This directive tells the CPP to replace instances of MAX_ARRAY_LENGTH with 20. Use #define for constants to increase readability.

#include <stdio.h>
// #include "myheader.h"
// These directives tell the CPP to get stdio.h from System Libraries and add the text to the current source file.
// The next line tells CPP to get myheader.h from the local directory and add the content to the current source file.

#undef  FILE_SIZE
#define FILE_SIZE 42
// It tells the CPP to undefine existing FILE_SIZE and define it as 42.

#ifndef MESSAGE
#define MESSAGE "You wish!"
#endif
// It tells the CPP to define MESSAGE only if MESSAGE isn't already defined.

#ifdef DEBUG
	/* Your debugging statements here */
#endif
// It tells the CPP to process the statements enclosed if DEBUG is defined.
// This is useful if you pass the -DDEBUG flag to the gcc compiler at the time of compilation.
// This will define DEBUG, so you can turn debugging on and off on the fly during compilation.

	printf("File :%s\n", __FILE__);
	printf("Date :%s\n", __DATE__);
	printf("Time :%s\n", __TIME__);
	printf("Line :%d\n", __LINE__);
	printf("ANSI :%d\n", __STDC__);

	// The Macro Continuation(\) Operator
	// A macro is 	normally confined to a single line
	// The macro continuation operator (\) is used to continue a macro that is too long for a single line.

#define  message_for(a, b)  \
	   printf(#a " and " #b ": We love you!\n")

	/*
	 The Stringize (#) Operator
	 The stringize or number-sign operator ( '#' ), when used within a macro definition, converts a macro parameter into a string constant. This operator may be used only in a macro having a specified argument or parameter list. For example −
	 */

#define  message_for(a, b)  \
   printf(#a " and " #b ": We love you!\n")

	message_for(Carole, Debra);

	/*
	 The Token Pasting (##) Operator
	 The token-pasting operator (##) within a macro definition combines two arguments.
	 It permits two separate tokens in the macro definition to be joined into a single token.
	 */

#define tokenpaster(n) printf ("token" #n " = %d", token##n)

	int token34 = 40;
	tokenpaster(34);

	/*
	 The Defined() Operator
	 The preprocessor defined operator is used in constant expressions to determine if an identifier is defined using #define.
	 If the specified identifier is defined, the value is true (non-zero). If the symbol is not defined, the value is false (zero).
	 */

#if !defined (MESSAGE)
 #define MESSAGE "You wish!"
 #endif

	printf("Here is the message: %s\n", MESSAGE);

	/*
	 Parameterized Macros
	 One of the powerful functions of the CPP is the ability to simulate functions using parameterized macros
	 Macros with arguments must be defined using the #define directive before they can be used.
	 The argument list is enclosed in parentheses and must immediately follow the macro name.
	 Spaces are not allowed between the macro name and open parenthesis.
	 */

#define MAX(x,y) ((x) > (y) ? (x) : (y))

	printf("Max between 20 and 10 is %d\n", MAX(10, 20));

	return 0;
}
