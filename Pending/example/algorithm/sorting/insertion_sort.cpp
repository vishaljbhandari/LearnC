// C++ program for insertion sort
#include <bits/stdc++.h>
using namespace std;

/*
 Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.
 Algorithm
 // Sort an arr[] of size n
 insertionSort(arr, n)
 Loop from i = 1 to n-1.
 ……a) Pick element arr[i] and insert it into sorted sequence arr[0…i-1]

 Time Complexity: O(n*2)

 Auxiliary Space: O(1)

 Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.

 Algorithmic Paradigm: Incremental Approach

 Sorting In Place: Yes

 Stable: Yes

 Online: Yes

 Uses: Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.


 How to implement Insertion Sort for Linked List?
 Below is simple insertion sort algorithm for linked list.

 1) Create an empty sorted (or result) list
 2) Traverse the given list, do following for every node.
 ......a) Insert current node in sorted way in sorted or result list.
 3) Change head of given linked list to head of sorted (or result) list.

 */

/*
 How to implement it recursively?
 Recursive Insertion Sort has no performance/implementation advantages, but can be a good question to check one’s understanding of Insertion Sort and recursion.

 If we take a closer look at Insertion Sort algorithm, we keep processed elements sorted and insert new elements one by one in the inserted array.

 Recursion Idea.

 Base Case: If array size is 1 or smaller, return.
 Recursively sort first n-1 elements.
 Insert last element at its correct position in sorted array.
 */

// Recursive function to sort an array using
// insertion sort
void insertionSortRecursive(int arr[], int n) {
	// Base case
	if (n <= 1)
		return;

	// Sort first n-1 elements
	insertionSortRecursive(arr, n - 1);

	// Insert last element at its correct position
	// in sorted array.
	int last = arr[n - 1];
	int j = n - 2;

	/* Move elements of arr[0..i-1], that are
	 greater than key, to one position ahead
	 of their current position */
	while (j >= 0 && arr[j] > last) {
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = last;
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) {
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		 greater than key, to one position ahead
		 of their current position */
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array of size n
void printArray(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

/* Driver code */
int main() {
	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	// insertionSortRecursive(arr, n);

	return 0;
}

// This is code is contributed by rathbhupendra
