/*
 Operator	Description	Example
 &&	Called Logical AND operator. If both the operands are non-zero, then the condition becomes true.	(A && B) is false.
 ||	Called Logical OR Operator. If any of the two operands is non-zero, then the condition becomes true.	(A || B) is true.
 !	Called Logical NOT Operator. It is used to reverse the logical state of its operand. If a condition is true, then Logical NOT operator will make it false.
 */

#include <stdio.h>

int main() {

	int a = 5;
	int b = 20;
	int c;

	if (a && b) {
		printf("Line 1 - Condition is true\n");
	}

	if (a || b) {
		printf("Line 2 - Condition is true\n");
	}

	/* lets change the value of  a and b */
	a = 0;
	b = 10;

	if (a && b) {
		printf("Line 3 - Condition is true\n");
	} else {
		printf("Line 3 - Condition is not true\n");
	}

	if (!(a && b)) {
		printf("Line 4 - Condition is true\n");
	}
	return 0;
}
