#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void displayArray(int *numbers) {
	int x;
	for (x = 0; x < SIZE; x++)
		printf(" %3d", numbers[x]);
	putchar('\n');
}

int compare(const void *a, const void *b) {
	return (*(int*) a - *(int*) b);
}

void qsort_function() {
	// Sort an array of any type. The parameters are, base
	// address of array, size of array and pointer to
	// comparator function
	// void qsort(void *base, size_t num, size_t size, int (*comparator)(const void*, const void*));

	int numbers[SIZE], x;

	/* populate the array */
	srand((unsigned) time(NULL));
	for (x = 0; x < SIZE; x++)
		numbers[x] = rand() % 100 + 1;

	/* Display the unsorted array */
	puts("Unsorted array:");
	displayArray(numbers);

	qsort(numbers, SIZE, sizeof(int), compare);

	/* Display the sorted array */
	puts("Sorted array:");
	displayArray(numbers);
}

void sort_function() {
	int numbers[SIZE], x, outer, inner, temp;

	/* populate the array */
	srand((unsigned) time(NULL));
	for (x = 0; x < SIZE; x++)
		numbers[x] = rand() % 100 + 1;

	/* Display the unsorted array */
	puts("Unsorted array:");
	displayArray(numbers);

	/* Sort the array */
	for (outer = 0; outer < SIZE; outer++)
		for (inner = outer + 1; inner < SIZE; inner++) {
			if (numbers[outer] > numbers[inner]) {
				temp = numbers[inner];
				numbers[inner] = numbers[outer];
				numbers[outer] = temp;
			}
		}

	/* Display the sorted array */
	puts("Sorted array:");
	displayArray(numbers);
}

int main() {
	sort_function();
	puts("\n");
	qsort_function();
	return (0);
}
