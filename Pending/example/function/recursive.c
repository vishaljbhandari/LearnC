#include <stdio.h>


void recurse(int v) {
	int a;
	for (a = 0; a < v; a++)
		putchar('-');
	puts("-> Wind-up!");
	if (v == 10)
		return;
	recurse(v + 1);
	for (a = 0; a < v; a++)
		putchar('-');
	puts("-< Unwinding");
}

int factorial(int f) {
	if (f == 1)
		return (f);
	return (f * factorial(f - 1));
}

void find_factorial(int a) {
	int b;
	if (a < 1) {
		printf("%d is not a positive value\n", a);
		return;
	}
	b = factorial(a);

	printf("The factorial of %d! is %d\n\n", a, b);
}

int main() {
	find_factorial(5);
	recurse(5);
	return (0);
}

