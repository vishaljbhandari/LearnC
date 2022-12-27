// gcc -lstdc++ -lm stl_array.cpp
#include <iostream>
#include <array>		// Header file for array stl container
#include <string>
using namespace std;

/*
 Thin wrapper over c-style static array
 Internally there is a c style static array template class

 Advantage STL-Array(Over static array) -> it supports iterator, it knows its size, Provide Random Access, Can't Grow, Fixed Size

 array<type, size> array_object; // declaration of array STL object

Its internal array is a fixed size standard c-array, can not grow at run time

Container properties
	Sequence - Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.
	Contiguous storage - The elements are stored in contiguous memory locations, allowing constant time random access to elements. Pointers to an element can be offset to access other elements.
	Fixed-size aggregate - The container uses implicit constructors and destructors to allocate the required space statically. Its size is compile-time constant. No memory or time overhead.

Array data can be accessed using subscript operator or iterators

 */

// print the elements of the array
template<typename T, size_t N>
void printArray(array<T, N> &arr) {
	// for(auto &index : arr ) 		// using auto keyword
	for (T &index : arr)
		cout << index << " ";
	cout << endl;
}

// simple print function
void message(const char *str) {
	cout << "simple print function called" << endl;
	cout << str << endl;
}

// simple template print function
template<typename T>
void message(const char *str, const T &value) {
	cout << "template print function called" << endl;
	cout << str << ": " << value << endl;
}

int main() {
	// Initializer list
	message("initializer list for array");
	array<int, 5> array1 = { 1, 2, 3, 4, 5 }; // Uniform Initialization Constructor is called

	// this array type would be "array<int, 5>"

	// This creates an integer static array of 5 element size inside
	// Array<array_type, size> array_object = initialization or new statement and values are initialized
	printArray(array1);

	// Default Constructor
	message("default constructor");
	array < string, 5 > array2;		// Default Constructor is called
	array2 = { "one", "two", "three" };
	printArray (array2);

	// Check the size
	message("size of array1", (int) array1.size());
	message("size of array2", (int) array2.size());

	// Check the max size
	message("max size of array2", (int) array2.max_size());
	message("max size of array2", (int) array2.max_size());

	// size() and max_size() both returns same values, both are same

	// front() function
	message("first element of array2", array2.front());
	message("last element of array2", array2.back());

	// Access Elements
	message("array1 element 3 is", array1[3]);//	[] operator overloaded inside array class
	message("array2 element 2 is", array2[2]);
	message("array1 element 3 is", array1.at(3));// at() function of inside array class
	message("array2 element 2 is", array2.at(2));

	// Direct access data, get pointer to the internal data array
	// External pointer can access data of array directly
	int *iptr1 = array1.data();
	for (size_t index = 0; index < array1.size(); ++index) {
		cout << "element " << index << " is " << *iptr1++ << endl;
		cout << "element " << index << " is " << array1[index] << endl;
		cout << "element " << index << " is " << array1.at(index) << endl;
	}

	string *iptr2 = array2.data();
	for (size_t index = 0; index < array2.size(); ++index) {
		cout << "element " << index << " is " << *iptr2++ << endl;
	}

	// looping using iterator
	array<int, 5>::iterator int_iterator = array1.begin();		// array type and iterator type should be same
	while (int_iterator != array1.end()) {
		cout << *int_iterator++ << " ";		// first dereference then increment
	}
	cout << endl;

	// looping using range based for loop
	for (int &value : array1) {
		cout << value << " ";
	}
	cout << endl;

	array1.fill(10);	// fill/copy all elements of array with 10 value
	printArray(array1);

	array<int, 5> array3 = { 1, 2, 3, 4, 5 };

	cout << "Before Swap " << endl;
	cout << "Array 1 " << endl;
	printArray(array1);
	cout << "Array 3 " << endl;
	printArray(array3);

	array1.swap(array3);		// both array must be of same type

	// swaps array array1 and array3
	cout << "After Swap " << endl;
	cout << "Array 1 " << endl;
	printArray(array1);
	cout << "Array 3 " << endl;
	printArray(array3);

	// Clearing array
	// cout << "Array 1 cleared" << endl;
	// array1.clear();	// this function is not available
	// printArray(array1);

	if (array1.empty()) {
		cout << "Array 1 is empty " << endl;
	} else {
		cout << "Array 1 is not empty " << endl;
	}

	return 0;
}
