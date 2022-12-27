// gcc -Wall -Wextra -Werror -lstdc++ -lm dynamic_memory_allocation.cpp
#include<iostream>
#include<stdio.h>
using namespace std;

constexpr size_t count = 100;

class A {
	int _a;
public:
	A(int i = 0) :
			_a(i) {
		cout << "Constructor called" << endl;
	}
	~A() {
		cout << "Destructor called" << endl;
	}
	int get_a() {
		return _a;
	}
};

void using_new_with_class() {
	cout << "allocating space for one A object" << endl;
	A *aptr = new (nothrow) A(5);
	if (aptr == nullptr) {
		cerr << "new A failed." << endl;
		return;
	}
	cout << "aptr->a() " << aptr->get_a() << endl;

	delete aptr;
	cout << "space for A object deleted" << endl;

	int *ip;
	printf("allocate space for %lu int items at *ip with new\n", count);
	try {
		ip = new int[count];
		if (ip == NULL) {
			cerr << "new failed." << endl;
			return;
		}
		for (int i = 0; i < (int) count; i++) {
			ip[i] = i;
		}
		for (int i = 0; i < (int) count; i++) {
			printf("%d:%d ", i, ip[i]);
			if ((i > 0 && i % 25 == 0) || i == count - 1)
				cout << endl;
		}
	} catch (std::bad_alloc &ba) {
		fprintf(stderr, "Cannot allocate memory (%s)\n", ba.what());
		return;
	}

	delete[] ip;
	cout << "space at *ip deleted" << endl << endl;
}

void using_new() {
	int value = 5, *ptr;
	ptr = new int();
	if (ptr == NULL) {
		cout << "Failed to allocated memory" << endl;
		return;
	}
	// Declaration of pointer and dynamic allocation
	// Initialized with zero
	cout << "Value : " << *ptr << endl;
	cout << "Location : " << ptr << endl;
	cout << "Pointer Location : " << &ptr << endl;
	cout << endl;
	delete ptr;

	ptr = new int(value);
	if (ptr == NULL) {
		cout << "Failed to allocated memory" << endl;
		return;
	}
	// Initialized with value
	cout << "Value : " << *ptr << endl;
	cout << "Location : " << ptr << endl;
	cout << "Pointer Location : " << &ptr << endl;
	delete ptr;

	int *itr = new int[value + 1];	// array of integer pointer
	if (itr == NULL) {
		cout << "Failed to allocated memory" << endl;
		return;
	}
	for (int i = 0; i <= value; i++) {
		cout << (i + 1) << "th position is allocated at " << &itr[i]
				<< " with value " << itr[i] << endl;
	}
	delete[] itr;
	cout << endl;

	int ROW = 2, COL = 3;
	double **pval = new double*[ROW]; // Allocate memory array of size ROW for rows
	if (pval == NULL) {
		cout << "Failed to allocated memory" << endl;
		return;
	}
	for (int i = 0; i < ROW; i++) {		// Now allocate memory for columns
		pval[i] = new double[COL];// Allocate memory array of size COL for cols
		if (pval[i] == NULL) {
			cout << "Failed to allocated memory" << endl;
			return;
		}
		cout << (i + 1) << "th row is allocated at " << &pval[i] << endl;
		for (int j = 0; j < COL; j++) {
			cout << (j + 1) << "@" << &pval[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < ROW; i++) {
		delete[] pval[i];		// Deleting each column array
	}
	delete[] pval;				// Deleting row array
	cout << endl;
}

void using_malloc() {
	int value = 5, *ptr;
	ptr = (int*) malloc(sizeof(int));
	if (ptr == NULL) {
		cout << "Failed to allocated memory" << endl;
		return;
	}
// Declaration of pointer and dynamic allocation
// Initialized with garbage
	cout << "Value : " << *ptr << endl;
	cout << "Location : " << ptr << endl;
	*ptr = value;
// Initialized with value
	cout << "Value : " << *ptr << endl;
	cout << "Location : " << ptr << endl;
	free(ptr);

	int *itr = (int*) malloc(sizeof(int) * value);
	if (itr == NULL) {
		cout << "Failed to allocated memory" << endl;
		return;
	}
	for (int i = 0; i < value; i++) {
		cout << (i + 1) << "th position is allocated at " << &itr[i]
				<< " with value " << itr[i] << endl;
	}
	for (int x = 0; x < value; x++) {
		*(itr + x) = 10 * (x + 1);
	}
	cout << "Values populated..	" << endl;
	for (int i = 0; i < value; i++) {
		cout << (i + 1) << "th position is allocated at " << &itr[i]
				<< " with value " << itr[i] << endl;
	}
	free(itr);
	cout << endl;
}

void using_calloc() {
	int value = 5, *ptr;
	cout << "ptr = (int*) calloc(1, sizeof(int));" << endl;
	ptr = (int*) calloc(1, sizeof(int));
	if (ptr == NULL) {
		cout << "Failed to allocated memory" << endl;
		return;
	}
// Declaration of pointer and dynamic allocation
// Initialized with garbage
	cout << "Value : " << *ptr << endl;
	cout << "Location : " << ptr << endl;
	*ptr = value;
// Initialized with value
	cout << "Value : " << *ptr << endl;
	cout << "Location : " << ptr << endl;
	free(ptr);

	cout << "int *itr = (int*) calloc(value, sizeof(int)); with value = ["
			<< value << "]" << endl;
	int *itr = (int*) calloc(value, sizeof(int));
	if (itr == NULL) {
		cout << "Failed to allocated memory" << endl;
		return;
	}
	for (int i = 0; i < value; i++) {
		cout << (i + 1) << "th position is allocated at " << &itr[i]
				<< " with value " << itr[i] << endl;
	}
	free(itr);
	cout << endl;
}

void allocation() {
	double *pvalue = NULL; 			// Pointer initialized with null
	pvalue = new double;   			// Request memory for the variable
	*pvalue = 29494.99;     		// Store value at allocated address
	cout << "pvalue:" << *pvalue << endl;
	delete pvalue;         			// free up the memory.

	// delete and free only work for the memory allocated dynamically.
	// using delete or free with pointer pointing to non dynamic memory, will give segmentation fault.
	int i = 5;
	int *is = &i;	// is pointing to a local memory
	int *id = new int(5);	// id pointing to dynamic memory
	// delete is;	// does not work, segmentation fault, try to release a non dynamic memory
	delete id;		// works, try to delete dynamic memory

	A *myBoxArray = new A[4]; // Allocating array of objects of size 4 with new operator
// Each time while creating object, Constructor will be called
	delete[] myBoxArray; 		// Deleting array
// For each time while deleting object, Destructor will be called
}

int main() {
	using_new();
	using_malloc();
	using_calloc();
	using_new_with_class();
	allocation();

// for checking memory leak
	/*
	 cout << "Below code will give memory leak issue" << endl;
	 int ptr = new int();
	 */
// delete ptr;
	return 0;
}

