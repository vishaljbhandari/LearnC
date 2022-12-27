/*
 The static Storage Class
 The static storage class instructs the compiler to keep a local variable in existence during the life-time of the program instead of creating and destroying it each time it comes into and goes out of scope.
 Therefore, making local variables static allows them to maintain their values between function calls.

 The static modifier may also be applied to global variables.
 When this is done, it causes that variable's scope to be restricted to the file in which it is declared.

 In C programming, when static is used on a global variable, it causes only one copy of that member to be shared by all the objects of its class.

 */
#include <stdio.h>

/* function declaration */
void func(void);

static int count = 5; /* global variable */

int main() {

	while (count--) {
		func();
	}

	return 0;
}

/* function definition */
void func(void) {

	static int i = 5; /* local static variable */
	i++;

	printf("i is %d and count is %d\n", i, count);
}
