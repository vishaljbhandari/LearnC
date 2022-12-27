#include <bits/stdc++.h>
using namespace std;

// Array must be sorted
// array should be large, suitable for large array

int binarySearch(int array[], int start, int end, int value) {
	if (end >= start) {
		int mid = start + (end - start) / 2;

		// If the element is present at the middle
		// itself
		if (array[mid] == value)
			return mid;

		// If element is smaller than mid, then it
		// can only be present n left subarray
		if (array[mid] > value)
			return binarySearch(array, start, mid - 1, value);

		// Else the element can only be present
		// in right subarray
		return binarySearch(array, mid + 1, end, value);
	}

	// We reach here when element is not present
	// in array
	return -1;
}

/*

 Exponential search involves two steps:
 1) Find range where element is present
 2) Do Binary Search in above found range.

 How to find the range where element may be present?
 The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until last element of a subarray is not greater.
 Once we find an index i (after repeated doubling of i), we know that the element must be present between i/2 and i (Why i/2? because we could not find a greater value in previous iteration)

 Time Complexity : O(Log n)
 Auxiliary Space : The above implementation of Binary Search is recursive and requires O(Log n) space. With iterative Binary Search, we need only O(1) space.

 Applications of Exponential Search:

 Exponential Binary Search is particularly useful for unbounded searches, where size of array is infinite. Please refer Unbounded Binary Search for an example.
 It works better than Binary Search for bounded arrays, and also when the element to be searched is closer to the first element.
 */

// Returns position of first occurrence of
// x in array
int exponentialSearch(int array[], int size, int value) {
	// If x is present at first location itself
	if (array[0] == value)
		return 0;

	// Find range for binary search by
	// repeated doubling
	int step = 1;
	while (step < size && array[step] <= value)
		step = step * 2;

	//  Call binary search for the found range.
	return binarySearch(array, step / 2, min(step, size), value);
}

// Driver code
int main(void) {
	int array[] = { 2, 3, 4, 10, 40 };
	int size = sizeof(array) / sizeof(array[0]);
	int value = 10;
	int result = exponentialSearch(array, size, value);
	(result == -1) ?
			printf("Element is not present in array") :
			printf("Element is present at index %d\n", result);
	return 0;
}
