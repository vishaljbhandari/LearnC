/*
 Operator precedence determines the grouping of terms in an expression and decides how an expression is evaluated. Certain operators have higher precedence than others; for example, the multiplication operator has a higher precedence than the addition operator.

 For example, x = 7 + 3 * 2; here, x is assigned 13, not 20 because operator * has a higher precedence than +, so it first gets multiplied with 3*2 and then adds into 7.

 Here, operators with the highest precedence appear at the top of the table, those with the lowest appear at the bottom. Within an expression, higher precedence operators will be evaluated first.

 Category Operator Associativity
 Postfix () [] -> . ++ - - Left to right
 Unary + - ! ~ ++ - - (type)* & sizeof Right to left
 Multiplicative * / % Left to right
 Additive + - Left to right
 Shift << >> Left to right
 Relational < <= > >= Left to right
 Equality == != Left to right
 Bitwise AND & Left to right
 Bitwise XOR ^ Left to right
 Bitwise OR | Left to right
 Logical AND && Left to right
 Logical OR || Left to right
 Conditional ?: Right to left
 Assignment = += -= *= /= %=>>= <<= &= ^= |= Right to left
 Comma , Left to right

 */

#include <stdio.h>

int main() {

	int a = 20;
	int b = 10;
	int c = 15;
	int d = 5;
	int e;

	e = (a + b) * c / d;      // ( 30 * 15 ) / 5
	printf("Value of (a + b) * c / d is : %d\n", e);

	e = ((a + b) * c) / d;      // (30 * 15 ) / 5
	printf("Value of ((a + b) * c) / d is  : %d\n", e);

	e = (a + b) * (c / d);      // (30) * (15/5)
	printf("Value of (a + b) * (c / d) is  : %d\n", e);

	e = a + (b * c) / d;      //  20 + (150/5)
	printf("Value of a + (b * c) / d is  : %d\n", e);

	return 0;
}
