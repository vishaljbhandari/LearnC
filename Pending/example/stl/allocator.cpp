// C++ program for illustration
// of std::allocator() function
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// Allocators are objects responsible for encapsulating memory management.
// std::allocator is used when you want to separate allocation and do construction in two steps.
// It is also used when separate destruction and deallocation is done in two steps.

/*

Member functions
(constructor)
	creates a new allocator instance
(public member function)
(destructor)
	destructs an allocator instance
(public member function)
address
(deprecated in C++17)(removed in C++20)
	obtains the address of an object, even if operator& is overloaded
(public member function)
allocate
	allocates uninitialized storage
(public member function)
deallocate
	deallocates storage
(public member function)
max_size
(deprecated in C++17)(removed in C++20)
	returns the largest supported allocation size
(public member function)
construct
(deprecated in C++17)(removed in C++20)
	constructs an object in allocated storage
(public member function)
destroy
(deprecated in C++17)(removed in C++20)
	destructs an object in allocated storage
(public member function)

*/

int main() {

	// allocator for integer values
	allocator<int> myAllocator;	// this myAllocator object will manage all kind of memory operations of int pointers

	// Allocation Step - allocate space for five ints
	int *arr = myAllocator.allocate(5);	// give me 5 memory space for integers
	// above is similar to int *arr = new int[5];

	// Constructor Step - construct arr[0] and arr[3]
	myAllocator.construct(arr, 100);
	arr[3] = 10;

	cout << arr[3] << endl;
	cout << arr[0] << endl;

	// Deallocation Step - deallocate space for five ints
	myAllocator.deallocate(arr, 5);	// deallocated memory location from arr to 5th location	// similar to delete arr

	// allocator for string values
	allocator < string > myStringAllocator;

	// allocate space for three strings
	string *str = myStringAllocator.allocate(3);

	// construct these 3 strings
	myStringAllocator.construct(str, "Geeks");
	myStringAllocator.construct(str + 1, "for");
	myStringAllocator.construct(str + 2, "Geeks");

	cout << str[0] << str[1] << str[2] << endl;

	// destroy these 3 strings
	// .destroy(pointer) function of allocator class - used to call destruction of object pointed by pointer
	myStringAllocator.destroy(str);// destroy/delete string pointed by str		// similar to delete str[0]
	myStringAllocator.destroy(str + 1);	// similar to delete str[1]
	myStringAllocator.destroy(str + 2);	// similar to delete str[2]

	// deallocate space for 3 strings
	myStringAllocator.deallocate(str, 3);		//	similar to delete str[]

	// Declaration comparisons

	vector<int>::iterator itr;// Declaring "int" iterator object		// type vector<int>::iterator	(Also Initialized, As its an object)
	allocator<int> alcr;	// Declaring "int" allocator			// type allocator<int>		(Also Initialized, As its an object)
	int *iptr;			// Declaring "int" pointer				// type int *
	vector<int> vtr;	// Declaring "int" vector				// type vector<int>			(Also Initialized, As its an object)
	vector<int> *vptr;	// Declaring "int" vector pointer		// vector<int> *

	// Initialization & Destroying comparisons
	{
		int *iptr = new int[5]; 					// Initializing "int" pointer				// type int *
		vector<int> *vptr = new vector<int>();		// Initializing "vector<int> *" pointer
		delete iptr;
		delete vptr;
	}

	// Use comparisons
	{
		vector<int> vtr;	// Declaring "int" vector				// type vector<int>			(Also Initialized, As its an object)
		vector<int> *vptr = new vector<int>();	// Declaring "int" vector pointer		// vector<int> *

		allocator<int> alcr;	// Declaring "int" allocator			// type allocator<int>		(Also Initialized, As its an object)
		int *iptr = new int();			// Declaring "int" pointer				// type int *


		vector<int>::iterator itr = vtr.begin();	// Use
		vector<int>::iterator itr2 = vptr->begin();
		iptr = alcr.allocate(1);		// one memory of int type to integer pointer

		alcr.deallocate(iptr, 1);
		delete iptr;
		delete vptr;

	}

	return 0;
}
