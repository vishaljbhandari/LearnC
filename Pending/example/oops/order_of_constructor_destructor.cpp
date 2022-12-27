// gcc -Wall -Wextra -Werror -lstdc++ -lm order_of_constructor_destructor.cpp
#include<iostream>
using namespace std;

class Base {
public:
	Base() {
		cout << "Default constructor of Base..." << endl;
	}
	Base(int n) {
		cout << "Single Argument constructor of Base... " << n << endl;
	}
	Base(int a, int b) {
		cout << "Two Argument constructor of Base... " << a << " " << b << endl;
	}
	~Base() {
		cout << "Default destructor of Base..." << endl;
	}
};

class Derived: public Base {
public:
	Derived() {
		// Whenever the derived class’s default constructor is called, the base class’s default constructor is called automatically.
		cout << "Default constructor of Derived..." << endl;

		// Base(1);
		// The parameterized constructor of base class cannot be called in default constructor of sub class, it should be called in the parameterized constructor of sub class.
	}
	Derived(int n) {
		cout << "Single Argument constructor of Derived... " << n << endl;
	}
	Derived(int a, int b) :
			Base(a) {
		// To call the parameterized constructor of base class inside the parameterized constructor of sub class, we have to mention it explicitly.
		cout << "Two Argument constructor of Derived... " << a << " " << b
				<< endl;
	}
	~Derived() {
		cout << "Default destructor of Derived..." << endl;
	}
};

// Destructors in C++ are called in the opposite order of that of Constructors

int main() {
	cout << endl << "Case 1" << endl;
	Derived D1(5, 10);
	cout << endl << "Case 2" << endl;
	Derived D2(5);
	cout << endl << "Case 3" << endl;
	Derived D3();
	Derived D4;
	cout << endl << "------" << endl;
	return 0;
}
