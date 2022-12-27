// gcc -lm -lstdc++ initialization.cpp
#include <iostream>
using namespace std;

int main() {

	/*
	 C++ 98 ways to initialize variables
	 Scalar types with = or ()
	 Array type with {}
	 */
	// scalar type
	int myI;		// UnInitializied
	int myInt = 10; // Initialization with Declaration // Direct initialization
	float myFloat = 54.2;	// Direct initialization
	long myLong = 54222451455;	// Direct initialization
	std::string str("C++ 98");	// Direct initialization
	int myIntg(5); 	// Direct initialization

	// Array type
	int myArray[] = { 1, 2, 3, 4 };
	char charArray1[3] = { 'a', 'b', '\0' };	// Aggregated Initialization
	char charArray2[8] = { "Hello" };	// Aggregated Initialization

	// Copy initialization - > where while initializing variables temporary copies of values are created.
	// Example
	int myInteger = 0; // this is a copy Initialization where copy of value 0 is created
	char arr1[5] = { '\0' }; // copy of value \0' is created
	char arr2[5] = { 'a', 'b', '\0' }; // copies of  'a', 'b', '\0'  are created
	char arr3[8] = { "Hello" };	// copy of"abc" is created

	/*
	 C++ 11 introduced UNiform Initialization ------------------------------
	 // Uniform Initialization USING {} FOR ALL TYPES

	 Advantages -
	 Uniform syntax for all types
	 Enforces initialization for all types
	 Prevent bugs while initialization using compiler
	 It prevents narrowing conversions (Assigning date from higher size data type to lower size data types example float to int etc)


	 */

	int b1 { }; // value initialization // direct initialization	// initialized with default value
	int b2(3);
	// value initialization // direct initialization	// initialized with 3 value
	// int b(); 	// is not initialization, this looks like function declaration // called as Most vexing parse
	float fl { 76.5 };

	// for arrays

	int i_array1[8] { }; // [] for size which is 8, and {} for initialization, in case values are missing, it will initialize with default values
	int i_array2[8] { 1, 2, 3, 4, 5, 6, 7, 8 }; // [] for size which is 8, and {} for initialization
	char c_array1[8] { "zbcdefg" };	// one character is left for null character	// as string
	char c_array2[8] { 'a', 'b', 'c', 'd', 'e', 'f', 'g', '\0' };// as character

	// uniform initialization for heap variables (pointers etc)
	int *p = new int;	// this is uninitialized
	int *q = new int { }; // this is initialized , with default value NULL

	int *p1 = new int[8]; 	// int  pointer of 8 size but uninitialized
	int *p2 = new int[8] { }; // int  pointer of 8 size and initialized with NULL values

	char *c1 = new char[8];	// character pointer of 8 size but uninitialized
	char *c2 = new char[8] { "Hello" }; //	int  pointer of 8 size and initialized with "Hello" values  // this was not allowed earlier

	// It prevents narrowing conversions (Assigning date from higher size data type to lower size data types example float to int etc)
	float f { };
	int i { f }; // Narrowing conversation, compiler error

	return 0;
}

/*
 1) Value Initialization =>
 type obj{};
 2) Direct Initialization =>
 type obj{value};
 3) Copy Initialization =>
 type obj = value;

 // Copy initialization should be avoided with user defined objects. as it create shallow copies

-----------------
 With C++11, everything can be initialized in much the same way.

 Initialization of dynamically allocated arrays:

 int *pi = new int[5]{1, 2, 3, 4, 5};

 Initialization of an array member variable:

 class A {
 int arr[3];
 public:
 A(int x, int y, int z) : arr{x, y, z} { };
 };

 Initialization of a STL container:

 std::vector v1{1, 2};

 Implicitly initialize objects to return:

 return {foo, bar};

 Implicitly initialize a function parameter:

 f({foo, bar});



 */

