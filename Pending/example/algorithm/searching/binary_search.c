// C program to implement recursive Binary Search
#include <stdio.h>

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int recursiveBinarySearch(int array[], int start, int end, int value) {
	if (end >= start) {
		int mid = start + (end - start) / 2;

		// If the element is present at the middle
		// itself
		if (array[mid] == value)
		return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (array[mid] > value)
		return recursiveBinarySearch(array, start, mid - 1, value);

		// Else the element can only be present
		// in right subarray
		return recursiveBinarySearch(array, mid + 1, end, value);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

// A iterative binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int iterativeBinarySearch(int array[], int start, int end, int value) {
	while (start <= end) {
		int mid = start + (end - start) / 2;

		// Check if x is present at mid
		if (array[mid] == value)
			return mid;

		// If x greater, ignore left half
		if (array[mid] < value)
			start = mid + 1;

		// If x is smaller, ignore right half
		else
			end = mid - 1;
	}
	return -1;
}

int main(void) {
	int array[] = { 2, 3, 4, 10, 40 };
	int size = sizeof(array) / sizeof(array[0]);
	int value = 10;
	int result = recursiveBinarySearch(array, 0, size - 1, value);
	(result == -1) ?
			printf("Element is not present in array\n") :
			printf("Element is present at index %d\n", result);

	result = iterativeBinarySearch(array, 0, size - 1, value);
	(result == -1) ?
			printf("Element is not present in array\n") :
			printf("Element is present at index %d\n", result);
	return 0;
}
