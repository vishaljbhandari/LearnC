/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;

/*
 QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.

 Always pick first element as pivot.
 Always pick last element as pivot (implemented below)
 Pick a random element as pivot.
 Pick median as pivot.
 The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.


 Analysis of QuickSort
 Worst Case: The worst case occurs when the partition process always picks greatest or smallest element as pivot.
 If we consider above partition strategy where last element is always picked as pivot,
 the worst case would occur when the array is already sorted in increasing or decreasing order.
 The solution of above recurrence is \theta(n2).



 Best Case: The best case occurs when the partition process always picks the middle element as pivot. Following is recurrence for best case.
 The solution of above recurrence is \theta(nLogn).

 Average Case:
 Solution of above recurrence is also O(nLogn)

 Although the worst case time complexity of QuickSort is O(n2) which is more than many other sorting algorithms like Merge Sort and Heap Sort,
 QuickSort is faster in practice, because its inner loop can be efficiently implemented on most architectures, and in most real-world data.
 QuickSort can be implemented in different ways by changing the choice of pivot, so that the worst case rarely occurs for a given type of data.
 However, merge sort is generally considered better when data is huge and stored in external storage.

 Is QuickSort stable?
 The default implementation is not stable. However any sorting algorithm can be made stable by considering indexes as comparison parameter.

 Is QuickSort In-place?
 As per the broad definition of in-place algorithm it qualifies as an in-place sorting algorithm as it uses extra space only for storing recursive function calls but not for manipulating the input.

 */

// A utility function to swap two elements
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
 the pivot element at its correct position in sorted
 array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right
 of pivot */
int partition(int arr[], int low, int high) {
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high - 1; j++) {
		// If current element is smaller than the pivot
		if (arr[j] < pivot) {
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
 low --> Starting index,
 high --> Ending index */
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		/* pi is partitioning index, arr[p] is now
		 at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code
int main() {
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

// This code is contributed by rathbhupendra
