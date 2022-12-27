// Segmentation fault
// The program can access some piece of memory which is not owned by it
// which can cause crashing of program such as segmentation fault.

// Program to demonstrate
// accessing array out of bounds
#include <stdio.h>
int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	printf("arr [0] is %d\n", arr[0]);
	printf("arr[10] is %d\n", arr[10]);

	// allocation memory to out of bound
	// element
	arr[10] = 11;
	printf("arr[10] is %d\n", arr[10]);
	return 0;
}
