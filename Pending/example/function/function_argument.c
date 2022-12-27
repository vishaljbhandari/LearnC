#include <stdio.h>

void arguments_two(char, int);

void f_arguments_two() {
	int x;

	for (x = 1; x < 11; x++)
		arguments_two('*', x * 2);
}

void arguments_two(char c, int count) {
	int x;

	for (x = 0; x < count; x++)
		putchar(c);
	putchar('\n');
}

void arguments_three(float a, float b, float c) {
	float p;

	p = a * b * c;
	printf("%f * %f * %f = %f\n", a, b, c, p);
}

void f_arguments_three() {
	float x, y, z;

	printf("Type three numbers, separated by spaces: ");
	scanf("%f %f %f", &x, &y, &z);
	arguments_three(x, y, z);
}

void arguments_one(int count) {
	int x;

	for (x = 0; x < count; x++)
		puts("Nevermore!");
}

void f_arguments_one() {
	int a, b;

	a = 1;
	b = 5;

	puts("At first the raven was like:");
	arguments_one(a);
	puts("But then he was all:");
	arguments_one(b);
}

int main() {
	f_arguments_one();
	f_arguments_two();
	f_arguments_three();
	return 0;
}
