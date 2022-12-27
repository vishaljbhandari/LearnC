#include <stdio.h>

/*
Assignment operators
used to assigning value to a variable.

The left side operand of the assignment operator is a variable.
The right side operand of the assignment operator is a value.
The value on the right side must be of the same data-type of the variable on the left side otherwise the compiler will raise an error.


Different types of assignment operators are shown below:
 = 	: This is the simplest assignment operator. This operator is used to assign the value on the right to the variable on the left.

Shorthand Assignment Operator

+=	: x = x + a
-=	: x = x - a
*=	: x = x * a
/=	: x = x / a

== is not any type of assignment operator

*/

int main() {
	int a = 25;

	printf("The value of a is %d\n", a);
	a = a + 5;
	printf("The value of a is %d\n", a);
	a = a - 5;
	printf("The value of a is %d\n", a);
	a = a * 5;
	printf("The value of a is %d\n", a);
	a = a / 5;
	printf("The value of a is %d\n", a);

	a = 25;

	printf("The value of a is %d\n", a);
	a += 5;
	printf("The value of a is %d\n", a);
	a -= 5;
	printf("The value of a is %d\n", a);
	a *= 5;
	printf("The value of a is %d\n", a);
	a /= 5;
	printf("The value of a is %d\n", a);

	int v = 0;

	printf("v equals %d\n", v);

	/* Addition */
	v = v + 20;
	printf("v + 20 equals %d\n", v);

	/* Subtraction */
	v = v - 2;
	printf("v - 2 equals %d\n", v);

	/* Division */
	v = v / 3;
	printf("v / 3 equals %d\n", v);

	/* Multiplication */
	v = v * 4;
	printf("v * 4 equals %d\n", v);

	/* Modulus */
	v = v % 7;
	printf("v %% 7 equals %d\n", v);

	return (0);
}
