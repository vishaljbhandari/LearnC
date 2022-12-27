#include <stdio.h>
/*
 A storage class defines the scope (visibility) and life-time of variables and/or functions within a C Program. They precede the type that they modify. We have four different storage classes in a C program −

 auto
 register
 static
 extern
 */
/*
 The auto Storage Class
 The auto storage class is the default storage class for all local variables.
 */

int main() {
	int i_month;
	auto int ai_month;
	printf("int variable: %d\n", i_month);
	printf("auto int variable: %d\n", ai_month);
	// auto variables are by default initialized by default values
	return 0;
}
// The example above defines two variables with in the same storage class. 'auto' can only be used within functions, i.e., local variables.
