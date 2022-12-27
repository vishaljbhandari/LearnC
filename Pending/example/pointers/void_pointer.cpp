// gcc -lstdc++ -lm void_pointer.cpp
// A void pointer is a pointer that has no associated data type with it.
// A void pointer can hold address of any type and can be typcasted to any type.
// These kind of pointers are used to point different types of variables.

#include<stdio.h>
#include <cstdlib>

int main() {

	int a = 10;
	char b = 'x';



	void *ptr = &a;  // void pointer holds address of int 'a'
	ptr = &b; // void pointer holds address of char 'b'

	// Advantages of void pointers:
	// 1) malloc() and calloc() return void * type and this allows these functions to be used to allocate memory of any data type (just because of void *)

	// Note that malloc() returns void * which can be
	// typecasted to any type like int *, char *, ..
	void *vptr = malloc(sizeof(int) * 5);// malloc(), calloc(), realloc() returns void * pointer
	// int *iptr1 = malloc(sizeof(int) * 5);// compiler error, invalid conversion from ‘void*’ to ‘int*’
	int *iptr2 = (int*) malloc(sizeof(int) * 5);// with typecast, returned pointer can be assigned to any pointer type

	// 2) void pointers in C are used to implement generic functions in C. For example compare function which is used in qsort().
	// void qsort (void* base, size_t num, size_t size, int (*comparator)(const void*,const void*));

	// 3) void pointers cannot be dereferenced.

	a = 10;
	// *ptr = &a;	// Compiler Error: 'void*' is not a pointer-to-object type
	// printf("%d", *ptr);	// Compiler Error: 'void*' is not a pointer-to-object type

	a = 10;
	void *ptr4 = &a;
	printf("%d", *(int*) ptr4);

	// 4) The C standard doesn’t allow pointer arithmetic with void pointers. As pointer's scaling factor is unknown
	// However, in GNU C it is allowed by considering the size of void is 1.
	int arr[2] = { 1, 2 };
	void *ptr5 = &arr;
	// ptr5++;		// ptr = ptr + 1	// compiler warning: ISO C++ forbids incrementing a pointer of type ‘void*’
	// ptr5 = ptr5 + sizeof(int);// ptr = size of integer	// compiler warning: pointer of type ‘void *’ used in arithmetic
	printf("%d\n", *(int*) ptr5);
	return 0;
}
