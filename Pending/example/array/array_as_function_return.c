#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate(void) {
	static int array[10];
	int x;

	srand((unsigned) time(NULL));
	for (x = 0; x < 10; x++)
		array[x] = rand() % 100 + 1;

	return (array);
}

template <class T>
T* generate(void) {
	static T array[10];
	int x;
	for (x = 0; x < 10; x++)
		array[x] = x + 1;

	return (array);
}

int main() {
	int x, *array;

	puts("Here are 10 random numbers:");
	array = generate();
	for (x = 0; x < 10; x++)
		printf(" %3d", array[x]);
	putchar('\n');

	return (0);
}
