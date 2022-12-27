#include <iostream>
using namespace std;

// noexcept operator (since C++11)

// The noexcept operator performs a compile-time check that returns true if an expression is declared to not throw any exceptions.

// It can be used within a function template's noexcept specifier to declare that the function will throw exceptions for some types but not others.


void Test(int x) noexcept(false) {
	cout << x << endl;
	// throw x;
}

int Sum(int x, int y) noexcept(noexcept(Test(x))) {
	Test(x);
	return x + y;
}

class A {
public:
	// Destructors are implicitly noexcept(true) in C++11
	~A() {
		throw 3;
	}
};

int main() {
	A a;
	try {
		// bool alpha manipulator prints 0 & 1 as false & true
		cout << boolalpha << noexcept (a.~A()) << endl;
	} catch (int x) {
		cout << x << endl;
	}

	try {
		Sum(3, 5);
		//Other statements
	} catch (int x) {
		cout << x << endl;
	}
	return 0;
}
