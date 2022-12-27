/*
 Operator Description Example
 == Checks if the values of two operands are equal or not. If yes, then the condition becomes true. (A == B) is not true.
 != Checks if the values of two operands are equal or not. If the values are not equal, then the condition becomes true. (A != B) is true.
 > Checks if the value of left operand is greater than the value of right operand. If yes, then the condition becomes true. (A > B) is not true.
 < Checks if the value of left operand is less than the value of right operand. If yes, then the condition becomes true. (A < B) is true.
 >= Checks if the value of left operand is greater than or equal to the value of right operand. If yes, then the condition becomes true. (A >= B) is not true.
 <= Checks if the value of left operand is less than or equal to the value of right operand. If yes, then the condition becomes true. (A <= B) is true.

 */

#include <stdio.h>

int main() {

	int a = 21;
	int b = 10;
	int c;

	if (a == b) {
		printf("Line 1 - a is equal to b\n");
	} else {
		printf("Line 1 - a is not equal to b\n");
	}

	if (a < b) {
		printf("Line 2 - a is less than b\n");
	} else {
		printf("Line 2 - a is not less than b\n");
	}

	if (a > b) {
		printf("Line 3 - a is greater than b\n");
	} else {
		printf("Line 3 - a is not greater than b\n");
	}

	/* Lets change value of a and b */
	a = 5;
	b = 20;

	if (a <= b) {
		printf("Line 4 - a is either less than or equal to  b\n");
	}

	if (b >= a) {
		printf("Line 5 - b is either greater than  or equal to b\n");
	}
	return 0;
}
