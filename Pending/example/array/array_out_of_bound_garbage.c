// Access non allocated location of memory
// The program can access some piece of memory which is owned by it
// Program to demonstrate
// accessing array out of bounds

#include <stdio.h>
int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	printf("arr [0] is %d\n", arr[0]);

	// arr[10] is out of bound
	printf("arr[10] is %d\n", arr[10]);
	return 0;
}

// Result - Garbage Value

// Stay inside the bounds of the array in C programming while using arrays to avoid any such errors.
// C++ however offers the std::vector class template, which does not require to perform bounds checking.
// A vector also has the std::at() member function which can perform bounds-checking.
