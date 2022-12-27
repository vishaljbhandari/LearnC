// gcc -lm -lstdc++ pointer.cpp
#include <stdio.h>
#include <iostream>
using namespace std;

void* func(void *vp) {
	return vp;
}

// Pointer points to another type
// Holds memory address of another type variable
// It can be used to direct access of variable pointing to.
// Need not to be initialized during declaration, but it is a good practice to initialize it with value to NULL to avoid accessing dangling locations.
// Declared with * operator

// Address of Operator &
// Whenever this & operator is applied to any variable, it extract the address of that variable
// Address extracted and passed by this operator can be stored only in a pointer variable of similar type of variable.

int main() {
	int *p1; 		// single pointer  declaration without initialization
	int *p2, *p3, *p4, p5; // multiple pointers declaration in single statement without initialization
	// in above line p5 is not a pointer, it is a normal integer as it is declared without *

	int i1;
	float f1;
	double d1;

	cout << &i1; 	// this will print address of integer variable i1;

	int *iu1 = &i1; // extracting address of i1 integer variable and passing it to same integer pointer.
	float *fu1 = &f1; // extracting address of f1 float variable and passing it to same float pointer.

	fu1 = &i1; // this will give error, as float pointer can not hold address of integer variable.
	// to point types of different type variables, use void pointers

	int value = 10;
	cout << value << endl;
	int *vtr = &value;
	cout << *vtr << endl;
	// delete vtr;		// can not be deleted, as memory pointed by vtr is not dynamically allocated, its a pointing memory belongs from local memory

	int *ptr = nullptr;	// pointer is allocated nullptr, this pointer is not allocated any memory
	int *nptr = NULL;	// similer to int* ptr = nullptr;
	// cout << *ptr << endl;	// segmentation fault (core dumped) // access of unallocated memory
	// *ptr = 5;	// segmentation fault (core dumped) // access of unallocated memory
	// cout << *ptr << endl;
	// delete ptr;	// deleting an unallocated pointer, nothing to delete/release memory

	int *itr = new int(75);
	cout << itr << " - " << *itr << endl;
	float *ftr = new float(75.25);
	cout << ftr << " - " << *ftr << endl;

	int arr[5] = { 1, 2, 3, 4, 5 };
	int *atr = arr;
	printf("pointer is %p, 1st value is %d\n", atr, *atr);
	atr++;
	printf("pointer is %p, 2nd value is %d\n", atr, *atr);
	atr--;
	printf("pointer is %p, 1st value is %d\n", atr, *atr);
	atr = atr + 3;
	printf("pointer is %p, 4th value is %d\n", atr, *atr);

	const char *const_char = "1234";	// not a dynamic memory allocation
	int *const_char_ptr = (int*) func((void*) const_char);
	// delete const_char_ptr;	// will give error as it does not contain any dynamic memory.
	// const_char_ptr contains address of const_char, which is not a dynamic memory

	printf("Char string %08x\n", *const_char_ptr);

	ptr = new int(42);	// pointer is assigned with value
	cout << ptr << " - " << *ptr << endl;
	delete ptr;	// releasing / deleting single pointer / memory, with checking null pointer condition
	cout << ptr << " - " << *ptr << endl;// Dereferencing 'ptr' after it is deallocated / released [deallocuse]
	int j = *ptr;// Dereferencing 'ptr' after it is deallocated / released [deallocuse]
	cout << ptr << " - " << *ptr << endl;// Dereferencing 'ptr' after it is deallocated / released [deallocuse]

	// Pointer initialization to null
	int *point = NULL;
	// Request memory for the variable using new operator
	point = new (nothrow) int;
	if (point == NULL)
		cout << "allocation of memory failed" << endl;
	else {
		// Store value at allocated address
		*point = 29;
		cout << "Value of point : " << *point << endl;
	}

	// Request block of memory of size n
	int count = 5;
	int *pointer_arr = new (nothrow) int[count];

	if (pointer_arr == NULL)
		cout << "allocation of memory failed" << endl;
	else {
		for (int i = 0; i < count; i++)
			pointer_arr[i] = i + 1;

		cout << "Value store in block of memory: ";
		for (int i = 0; i < count; i++)
			cout << pointer_arr[i] << " ";
	}
	cout << endl;

	cout << "de-allocation of pointer memory with null check" << endl;
	if (point != NULL) {
		delete point;
	}
	cout << "de-allocation of multiple pointer memory" << endl;
	delete itr, ftr; // deleting multiple pointers in one statement, does not work properly
	// in this case only itr will be deleted, ftr will be left un deleted
	delete ftr;	// not a double delete, as previous delete does not delete it

	cout << "de-allocation of pointer array/block memory" << endl;
	// delete pointer_arr; // incorrect delete, as it is an array pointer, it should be deleted with delete[]
	delete[] pointer_arr;

	int *index = new int(5);
	cout << index << " - " << *index << endl;
	int *iterator = new int[10];
	*iterator = 1;		// like iterator[0]=1
	cout << iterator << " - " << *iterator << " - " << iterator[0] << endl;
	*(iterator + 1) = 2; 	// like iterator[1]=2
	cout << iterator + 1 << " - " << *(iterator + 1) << " - " << iterator[1]
			<< endl;
	cout << iterator[1] << endl;
	*(iterator + 3) = 4;
	cout << iterator[4] + 2 << endl;

	delete index;
	delete[] iterator;

	int *myptr = new int(4);
	delete myptr;	// deleting allocated memory
	// delete myptr;	// deleting already allocated memory // double delete // Segmentation fault (core dumped)

	int *myitr = (int*) malloc(5);
	free(myitr);		// freeing allocated memory
	// free(myitr);	// Segmentation fault (core dumped)

	int *null_pointer = nullptr;
	// cout << *null_pointer << endl;	// this will crash the program as it is trying to read value stored at address as nullptr.
	// you can not access value stored at NULL address

	return 0;
}

