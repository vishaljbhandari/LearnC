/*
 Operator Description Example
 & Binary AND Operator copies a bit to the result if it exists in both operands. (A & B) = 12, i.e., 0000 1100
 | Binary OR Operator copies a bit if it exists in either operand. (A | B) = 61, i.e., 0011 1101
 ^ Binary XOR Operator copies the bit if it is set in one operand but not both. (A ^ B) = 49, i.e., 0011 0001
 ~ Binary One's Complement Operator is unary and has the effect of 'flipping' bits. (~A ) = ~(60), i.e,. 1100 0011
 << Binary Left Shift Operator. The left operands value is moved left by the number of bits specified by the right operand. A << 2 = 240 i.e., 1111 0000
 >> Binary Right Shift Operator. The left operands value is moved right by the number of bits specified by the right operand. A >> 2 = 15 i.e., 0000 1111

 */

#include <stdio.h>

int main() {

	unsigned int a = 60; /* 60 = 0011 1100 */
	unsigned int b = 13; /* 13 = 0000 1101 */
	int c = 0;

	c = a & b; /* 12 = 0000 1100 */
	printf("Line 1 - Value of c is %d\n", c);

	c = a | b; /* 61 = 0011 1101 */
	printf("Line 2 - Value of c is %d\n", c);

	c = a ^ b; /* 49 = 0011 0001 */
	printf("Line 3 - Value of c is %d\n", c);

	c = ~a; /*-61 = 1100 0011 */
	printf("Line 4 - Value of c is %d\n", c);

	c = a << 2; /* 240 = 1111 0000 */
	printf("Line 5 - Value of c is %d\n", c);

	c = a >> 2; /* 15 = 0000 1111 */
	printf("Line 6 - Value of c is %d\n", c);
	return 0;
}
