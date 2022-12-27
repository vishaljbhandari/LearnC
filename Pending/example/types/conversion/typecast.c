// gcc -lm typecast.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	int a = 10, b = 3, p = 5, *m, x, r[5];
	float c, proot;
	c = a / b; // integer type will be applied on a/b (result = 3) then for assignment implicit type conversation to float will happen as 3.00
	printf("%d/%d = %.2f\n", a, b, c);

	proot = sqrt(p);
	printf("The square root of %d is %f\n", p, proot);

	m = (int*) malloc(16 * sizeof(int)); // type conversion from void* to int* type

	a = 100;
	b = 7;

	printf("%d / %d = %d\n", a, b, a / b); // integer type will be applied on a/b fractional part will be trimmed out

	return (0);
}
