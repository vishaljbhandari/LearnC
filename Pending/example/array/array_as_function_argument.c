// gcc -Wall -Wextra -Werror -lm array_as_function_argument.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10

void populate(int *int_array) {	// Receive as integer pointer variable
	int x;
	srand((unsigned) time(NULL));
	for (x = 0; x < SIZE; x++) {
		int_array[x] = rand() % 100 + 1;
	}
}

void showArray(int *int_array) {	// Receive as integer pointer variable
	int x;
	for (int x = 0; x < SIZE; x++) {
		printf(" %3d", int_array[x]);
	}
	putchar('\n');
}

void sortArray(int *int_array) {
	int inner, outer, temp;
	for (inner = 0; inner < SIZE; inner++) {
		for (outer = inner + 1; outer < SIZE; outer++) {
			if (int_array[inner] > int_array[outer]) {
				temp = int_array[inner];
				int_array[inner] = int_array[outer];
				int_array[outer] = temp;
			}
		}
	}
}
float mean(float float_array[], int n) {
	float sum = 0.0;
	int i;
	for (i = 0; i < n; i++) {
		sum += float_array[i];
	}
	return i == 0 ? 0.0 : sum / (float) n;
}

float std_dev(float a[], int n) {
	int i;
	float x, sum = 0.0;
	x = mean(a, n);
	for (i = 0; i < n; i++)
		sum += (x - a[i]) * (x - a[i]);
	return (sqrt(sum / (float) n));
}

int main() {
	int numbers[SIZE], i;

	/* populate the array */
	populate(numbers);

	/* Display the unsorted array */
	puts("Unsorted array:");

	/* Sort the array */
	sortArray(numbers);

	/* Display the sorted array */
	puts("Sorted array:");
	showArray(numbers);

	float value[SIZE];

	printf("Enter %d float values\n", SIZE);
	for (i = 0; i < SIZE; i++) {
		scanf("%f", &value[i]);
	}
	printf("Std.deviation is %f\n", std_dev(value, SIZE));
	return 0;
}
