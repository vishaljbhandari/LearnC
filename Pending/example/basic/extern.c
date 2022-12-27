#include <stdio.h>

/*
 External variables are also known as global variables. These variables are defined outside the function and are available globally throughout the function execution. The “extern” keyword is used to declare and define the external variables.

 The keyword [ extern “C” ] is used to declare functions in C++ which is implemented and compiled in C language. It uses C libraries in C++ language.

 The following is the syntax of extern.

 extern datatype variable_name;     // variable declaration using extern
 extern datatype func_name();       // function declaration using extern

 Here,

 datatype − The datatype of variable like int, char, float etc.

 variable_name − This is the name of variable given by user.

 func_name − The name of function.
 */

int x;

extern int y = 32;
// warning: ‘y’ initialized and declared ‘extern’
/*

 above is a coding style warning - the code is valid, but extremely
 unidiomatic for C since "extern" is generally expected to mean that the
 declaration is not providing a definition of the object.  Following static
 by extern, though valid, is also a C feature of doubtful value.

 */

extern int data[];

void initializeData(void) {
	int x;

	for (x = 0; x < 5; x++)
		data[x] = x;
	puts("* Data initialized *");
}

void displayData(void) {
	int x;

	printf("Data Set:\n");
	for (x = 0; x < 5; x++)
		printf("%2d\t", data[x]);
	putchar('\n');
}

void manipulateData(void) {
	int x;

	for (x = 0; x < 5; x++)
		data[x] *= 2; /* double x */
	puts("* Data manipulated *");
}

int z = 8;

void f(void) {
	x = -1;
	printf("In function f() x = %d\n", x);
}

int main() {
	extern int z;
	printf("The value of extern variables y and z : %d,%d\n", y, z);
	y = 15;
	printf("The value of modified extern variable y : %d\n", y);

	x = 0;
	printf("In the main() function x = %d\n", x);
	f();
	printf("In the main() function x = %d\n", x);

	initializeData();
	displayData();
	manipulateData();

	return (0);
}

