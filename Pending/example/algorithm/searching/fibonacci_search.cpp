// C program for Fibonacci Search
#include <stdio.h>

/*
 Fibonacci Search is a comparison-based technique that uses Fibonacci numbers to search an element in a sorted array.

 Similarities with Binary Search:

 Works for sorted arrays
 A Divide and Conquer Algorithm.
 Has Log n time complexity.
 Differences with Binary Search:

 Fibonacci Search divides given array in unequal parts
 Binary Search uses division operator to divide range. Fibonacci Search doesn’t use /, but uses + and -. The division operator may be costly on some CPUs.
 Fibonacci Search examines relatively closer elements in subsequent steps. So when input array is big that cannot fit in CPU cache or even in RAM, Fibonacci Search can be useful.

 */

// Utility function to find minimum of two elements
int min(int x, int y) {
	return (x <= y) ? x : y;
}

/* Returns index of x if present,  else returns -1 */
int fibMonaccianSearch(int array[], int value, int size) {
	/* Initialize fibonacci numbers */
	int fibMMm2 = 0;   // (m-2)'th Fibonacci No.
	int fibMMm1 = 1;   // (m-1)'th Fibonacci No.
	int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci

	/* fibM is going to store the smallest Fibonacci
	 Number greater than or equal to n */
	while (fibM < size) {
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	// Marks the eliminated range from front
	int offset = -1;

	/* while there are elements to be inspected. Note that
	 we compare arr[fibMm2] with x. When fibM becomes 1,
	 fibMm2 becomes 0 */
	while (fibM > 1) {
		// Check if fibMm2 is a valid location
		int i = min(offset + fibMMm2, size - 1);

		/* If x is greater than the value at index fibMm2,
		 cut the subarray array from offset to i */
		if (array[i] < value) {
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}

		/* If x is greater than the value at index fibMm2,
		 cut the subarray after i+1  */
		else if (array[i] > value) {
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		/* element found. return index */
		else
			return i;
	}

	/* comparing the last element with x */
	if (fibMMm1 && array[offset + 1] == value)
		return offset + 1;

	/*element not found. return -1 */
	return -1;
}

/* driver function */
int main(void) {
	int array[] = { 10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100 };
	int size = sizeof(array) / sizeof(array[0]);
	int value = 85;
	printf("Found at index: %d\n", fibMonaccianSearch(array, value, size));
	return 0;
}
