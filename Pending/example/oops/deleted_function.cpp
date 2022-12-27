// C++ program to disable the usage of
// copy-constructor using delete operator
// gcc -lstdc++ -lm deleted_function.cpp

#include <iostream>
using namespace std;

/*
 Prior to C++ 11, the operator delete had only one purpose, to deallocate a memory that has been allocated dynamically.
 */

/*
 The C++ 11 standard introduced another use of this operator, which is:
 To disable the usage of a member function.
 This is done by appending the =delete; specifier to the end of that function declaration.

 Any member function whose usage has been disabled by using the ‘=delete’ specifier is known as an explicitly deleted function.

 Although not limited to them, but this is usually done to implicit functions.
 The following examples exhibit some of the tasks where this feature comes handy:
 */

class A {
public:
	A(int x) :
			m(x) {
	}

	// Default constructor is deleted
	A() = delete;
	// Default Object creation is prevented/disabled

	// Delete the copy constructor
	A(const A&) = delete;
	// Copy constructor is disabled
	// Copying of object is prevented/disabled

	// Delete the copy assignment operator
	A& operator=(const A&) = delete;
	// Assignment operator function is disabled
	// Object assignment is prevented/disabled

	// Declare the conversion constructor as a
	// deleted function. Without this step,
	// even though A(double) isn't defined,
	// the A(int) would accept any double value
	// for it's argument and convert it to an int
	A(double) = delete;

	int m;
};

// It is very important to note that A deleted function is implicitly inline.
// A deleted definition of a function must be the first declaration of the function.
// In other words, the following way is the correct way of declaring a function as deleted
// function declaration - delete
// C(C& a) = delete; 	// Correct usage of delete [With in inline class definition]
// C::C() = delete		// Incorrect usage, outside of class block as non inline function

int main() {
	A a1(1), a2(2), a3(3);	// Allowed as single argument constructor is defined

	// Error, the usage of the object creation
	// A a;	// Not allowed as default constructor is deleted

	// Error, the usage of the copy
	// assignment operator is disabled/deleted
	// a2;

	// Error, the usage of the copying object
	// copy constructor is disabled/deleted
	// a3 = A(a2);

	// Error, conversion from
	// double to class A is disabled/deleted
	// A A2(100.1);
	return 0;
}

/*
What are the advantages of explicitly deleting functions?

>> Deleting of special member functions provides a cleaner way of preventing the compiler from generating special member functions that we don’t want. (As demonstrated in ‘Disabling copy constructors’ example).
>> Deleting of normal member function or non-member functions prevents problematic type promotions from causing an unintended function to be called (As demonstrated in ‘Disabling undesirable argument conversion’ example).

*/
