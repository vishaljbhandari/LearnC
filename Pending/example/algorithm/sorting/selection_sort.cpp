// C++ program for implementation of selection sort

/*
 Selection Sort
 The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.
 The algorithm maintains two subarrays in a given array.

 1) The subarray which is already sorted.
 2) Remaining subarray which is unsorted.

 In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

 Time Complexity: O(n2) as there are two nested loops.

 Auxiliary Space: O(1)
 The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.

 */

#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n) {
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++) {
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}

/* Function to print an array */
void printArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver program to test above functions
int main() {
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

// This is code is contributed by rathbhupendra
