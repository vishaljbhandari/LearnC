// gcc -lm passing_pointer.c
#include <stdio.h>

void pass_pointer_address_func(int *alpha) {
	*alpha += *alpha;
}

void pass_pointer_address() {
	int *a, b;

	b = 25;
	a = &b;
	printf("Value before: %d\n", *a);
	pass_pointer_address_func(a);
	printf("Value after: %d\n", *a);
}

void pass_pointer_func(int *alpha) {
	*alpha += *alpha;
}

void pass_pointer() {
	int a = 2;

	printf("Value before: %d\n", a);
	pass_pointer_func(&a);
	printf("Value after: %d\n", a);
}

void three(float a, float *b, float *c) {
	*b = a / 3.0;
	*c = a / 7.0;
}

void pass_pointer_addresses() {
	float x, y;
	printf("Before Function\n20 / 3 = %.1f\n", x);
	printf("20 / 7 = %.1f\n", y);
	three(20.0, &x, &y);
	printf("After Function\n20 / 3 = %.1f\n", x);
	printf("20 / 7 = %.1f\n", y);
}

void pass_array_read_by_subscript_f(char s[]) {
	s[1] = '1';
}

void pass_array_read_by_subscript() {
	char pet[] = "cot";

	puts(pet);
	pass_array_read_by_subscript_f(pet);
	puts(pet);
}

void pass_array_read_by_pointer_f(char *s) {
	*(s + 2) = '2';
}

void pass_array_read_by_pointer() {
	char pet[] = "cot";

	puts(pet);
	pass_array_read_by_pointer_f(pet);
	puts(pet);
}

int main() {
	pass_pointer();
	pass_pointer_address();
	pass_pointer_addresses();
	pass_array_read_by_subscript();
	pass_array_read_by_pointer();
	return 0;
}
