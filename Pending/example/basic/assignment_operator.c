/*
 Operator Description Example
 = Simple assignment operator. Assigns values from right side operands to left side operand C = A + B will assign the value of A + B to C
 += Add AND assignment operator. It adds the right operand to the left operand and assign the result to the left operand. C += A is equivalent to C = C + A
 -= Subtract AND assignment operator. It subtracts the right operand from the left operand and assigns the result to the left operand. C -= A is equivalent to C = C - A
 *= Multiply AND assignment operator. It multiplies the right operand with the left operand and assigns the result to the left operand. C *= A is equivalent to C = C * A
 /= Divide AND assignment operator. It divides the left operand with the right operand and assigns the result to the left operand. C /= A is equivalent to C = C / A
 %= Modulus AND assignment operator. It takes modulus using two operands and assigns the result to the left operand. C %= A is equivalent to C = C % A
 <<= Left shift AND assignment operator. C <<= 2 is same as C = C << 2
 >>= Right shift AND assignment operator. C >>= 2 is same as C = C >> 2
 &= Bitwise AND assignment operator. C &= 2 is same as C = C & 2
 ^= Bitwise exclusive OR and assignment operator. C ^= 2 is same as C = C ^ 2
 |= Bitwise inclusive OR and assignment operator. C |= 2 is same as C = C | 2

 */

#include <stdio.h>

int main() {

	int a = 21;
	int c;

	c = a;
	printf("Line 1 - =  Operator Example, Value of c = %d\n", c);

	c += a;
	printf("Line 2 - += Operator Example, Value of c = %d\n", c);

	c -= a;
	printf("Line 3 - -= Operator Example, Value of c = %d\n", c);

	c *= a;
	printf("Line 4 - *= Operator Example, Value of c = %d\n", c);

	c /= a;
	printf("Line 5 - /= Operator Example, Value of c = %d\n", c);

	c = 200;
	c %= a;
	printf("Line 6 - %= Operator Example, Value of c = %d\n", c);

	c <<= 2;
	printf("Line 7 - <<= Operator Example, Value of c = %d\n", c);

	c >>= 2;
	printf("Line 8 - >>= Operator Example, Value of c = %d\n", c);

	c &= 2;
	printf("Line 9 - &= Operator Example, Value of c = %d\n", c);

	c ^= 2;
	printf("Line 10 - ^= Operator Example, Value of c = %d\n", c);

	c |= 2;
	printf("Line 11 - |= Operator Example, Value of c = %d\n", c);

	return 0;
}
