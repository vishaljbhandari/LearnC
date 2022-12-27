#include <stdio.h>
#include <stdlib.h>

int return_as_int(int x, int y) {
	if (x > y)
		return (x);
	return (y);
}

char return_as_char(void) {
	return ('A');
}

float return_as_float(float a, float b, float c) {
	float p;
	p = a * b * c;
	return (p);
}

int* create_int_array(int size) {
	int x, *arr;
	arr = (int*) malloc(sizeof(int) * size);
	if (arr == NULL) {
		puts("Unable to allocate memory");
		exit(1);
	}
	return (arr);
}

void prepare_int_array(int *arr, int size) {
	int index;
	for (index = 0; index < size; index++)
		*(arr + index) = (index + 1) * 10;
}

void print_int_array(int *arr, int size) {
	int index;
	puts("Integer array content");
	for (index = 0; index < size; index++)
		printf("%d - > %d\n", index, *(arr + index));
}

char* create_char_array(int size) {
	int x;
	char *c, *arr;
	arr = (char*) malloc(sizeof(char) * size);
	if (arr == NULL) {
		puts("Unable to allocate memory");
		exit(1);
	}
	return (arr);
}

void prepare_char_array(char *arr, int size) {
	int index;
	for (index = 0; index < size; index++)
		*(arr + index) = index + 65;
}

void print_char_array(char *arr, int size) {
	int index;
	puts("Char array content");
	for (index = 0; index < size; index++)
		printf("%d - > %c\n", index, *(arr + index));
}

int main() {
	char grade;
	float a, x, y, z;
	int p, q;
	int *i_arr, i_size;
	char *c_arr, c_size;

	printf("Two integers 55, 75");
	p = 55;
	q = 75;
	if (p == return_as_int(p, q))
		printf("Value %d is larger.\n", p);
	else
		printf("Value %d is larger.\n", q);

	grade = return_as_char();
	printf("On this test you received an %c.\n", return_as_char);

	printf("Type three numbers, separated by spaces: ");
	scanf("%f %f %f", &x, &y, &z);
	a = return_as_float(x, y, z);
	printf("%f * %f * %f = %f\n", x, y, z, a);

	i_size = 10;
	i_arr = create_int_array(i_size);
	prepare_int_array(i_arr, i_size);
	print_int_array(i_arr, i_size);

	c_size = 26;
	c_arr = create_char_array(c_size);
	prepare_char_array(c_arr, c_size);
	print_char_array(c_arr, c_size);

	return (0);
}

