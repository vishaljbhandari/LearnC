/*
 Operator Description Example
 sizeof() Returns the size of a variable. sizeof(a), where a is integer, will return 4.
 & Returns the address of a variable. &a; returns the actual address of the variable.
 * Pointer to a variable. *a;
 ? : Conditional Expression. If Condition is true ? then value X : otherwise value Y

 */

#include <stdio.h>

int main() {

	int a = 4;
	short b;
	double c;
	int *ptr;

	/* example of sizeof operator */
	printf("Line 1 - Size of variable a = %d\n", sizeof(a));
	printf("Line 2 - Size of variable b = %d\n", sizeof(b));
	printf("Line 3 - Size of variable c= %d\n", sizeof(c));

	/* example of & and * operators */
	ptr = &a; /* 'ptr' now contains the address of 'a'*/
	printf("value of a is  %d\n", a);
	printf("*ptr is %d.\n", *ptr);

	/* example of ternary operator */
	a = 10;
	b = (a == 1) ? 20 : 30;
	printf("Value of b is %d\n", b);

	b = (a == 10) ? 20 : 30;
	printf("Value of b is %d\n", b);

	return 0;
}
