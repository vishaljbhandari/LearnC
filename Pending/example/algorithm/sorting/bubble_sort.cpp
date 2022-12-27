/*
 Bubble Sort
 Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.


 Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.

 Best Case Time Complexity: O(n). Best case occurs when array is already sorted.

 Auxiliary Space: O(1)

 Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.

 Sorting In Place: Yes

 Stable: Yes

 */

// C++ program for implementation of Bubble sort
#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/*
 How to implement it recursively?
 Recursive Bubble Sort has no performance/implementation advantages, but can be a good question to check one’s understanding of Bubble Sort and recursion.

 If we take a closer look at Bubble Sort algorithm, we can notice that in first pass, we move largest element to end (Assuming sorting in increasing order). In second pass, we move second largest element to second last position and so on.

 Recursion Idea.

 Base Case: If array size is 1, return.
 Do One Pass of normal Bubble Sort. This pass fixes last element of current subarray.
 Recur for all elements except last of current subarray.

 */

// A function to implement bubble sort
void bubbleSortRecursive(int arr[], int n) {
	// Base case
	if (n == 1)
		return;

	// One pass of bubble sort. After
	// this pass, the largest element
	// is moved (or bubbled) to end.
	for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			swap(arr[i], arr[i + 1]);

	// Largest element is fixed,
	// recur for remaining array
	bubbleSort(arr, n - 1);
}

// An optimized version of Bubble Sort

/*
 Optimized Implementation:
 The above function always runs O(n^2) time even if the array is sorted. It can be optimized by stopping the algorithm if inner loop didn’t cause any swap.
 */

void bubbleSortOptimized(int arr[], int n) {
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break
		if (swapped == false)
			break;
	}
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

/* Function to print an array */
void printArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main() {
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);

	// bubbleSortOptimized(arr, n);
	// bubbleSortRecursive(arr, n);

	return 0;
}

// This code is contributed by rathbhupendra
