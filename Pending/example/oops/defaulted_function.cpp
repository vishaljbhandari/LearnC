// gcc -lstdc++ -lm defaulted_function.cpp
#include <iostream>
using namespace std;

class A {
public:

	// A user-defined parameterized constructor
	A(int x) {
		cout << "This is a parameterized constructor";
	}
	// As any parameterized constructor is defined by user, Compiler does not provide default constructor

	// Using the default specifier to instruct
	// the compiler to create the default
	// implementation of the constructor.
	A() = default;		// Default function is explicitly specified

	// Limitation of defaulted functions

	// Error, func is not a special member function.
	// int func() = default;

	// Error, constructor B(int, int) is not
	// a special member function.
	// A(int, int) = default;

	// Error, constructor B(int=0)
	// has a default argument.
	// A(int = 0) = default;

};

/*
 * Explicitly defaulted function declaration is a new form of function declaration
 * that is introduced into the C++11 standard which allows you to append the ‘=default;’
 * specifier to the end of a function declaration to declare that function as an explicitly defaulted function.
 * This makes the compiler generate the default implementations for explicitly defaulted functions,
 * which are more efficient than manually programmed function implementations.
 */

int main() {
	// executes using defaulted constructor
	A a;	// ALlowed as a function is defined as default

	// uses parameterized constructor
	A x(1);
	return 0;
}
