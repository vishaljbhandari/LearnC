#include<stdio.h>
int main() {
	int a = 2, b = 4;
	float x = 5, y = 6;
	printf("a = %d, b = %d\n", a, b);
	if (a > b) {
		printf("a is greater than b\n");
	} else {
		printf("b is greater than a\n");
	}
	printf("x = %2.2f, y = %2.2f\n", x, y);
	if (x > y) {
		printf("x is greater than y\n");
	} else {
		printf("y is greater than x\n");
	}
	x = 6;
	printf("x = %2.2f, y = %2.2f\n", x, y);
	if (x == y) {
		printf("x is equal to y\n");
	} else {
		printf("x is not equal to y\n");
	}
	x = 6.0;
	printf("x = %2.2f, y = %2.2f\n", x, y);
	if (x == y) {
		printf("x is equal to y\n");
	} else {
		printf("x is not equal to y\n");
	}
	x = 6.0f;
	printf("x = %2.2f, y = %2.2f\n", x, y);
	if (x == y) {
		printf("x is equal to y\n");
	} else {
		printf("x is not equal to y\n");
	}
	return 0;
}
