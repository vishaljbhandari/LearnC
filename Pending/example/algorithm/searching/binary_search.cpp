#include <bits/stdc++.h>
using namespace std;
// Using recursive function

// Primary Condition: Array must be sorted

/*
 Binary Search: Search a sorted array
 by repeatedly dividing the search interval in half.
 Begin with an interval covering the whole array.
 If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
 Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.
 */

/*
 Time Complexity:
 The time complexity of Binary Search can be written as

 T(n) = T(n/2) + c
 The above recurrence can be solved either using Recurrence T ree method or Master method. It falls in case II of Master Method and solution of the recurrence is Theta(Logn).

 Auxiliary Space: O(1) in case of iterative implementation.
 In case of recursive implementation, O(Logn) recursion call stack space.
 */

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
	int value = 10;
	int size = sizeof(array) / sizeof(array[0]);
	int result = recursiveBinarySearch(array, 0, size - 1, value);
	(result == -1) ?
			cout << "Element is not present in array" << endl :
			cout << "Element is present at index " << result << endl;

	result = iterativeBinarySearch(array, 0, size - 1, value);
	(result == -1) ?
			cout << "Element is not present in array" << endl :
			cout << "Element is present at index " << result << endl;
	return 0;
}
