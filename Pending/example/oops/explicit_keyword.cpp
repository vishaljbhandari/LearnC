// gcc -Wall -Wextra -Werror -lstdc++ -lm explicit_keyword.cpp
#include <iostream>

using namespace std;

class Complex1 {
private:
	double real;
	double imag;

public:
	// Default constructor
	Complex1(double r = 0.0, double i = 0.0) :
			real(r), imag(i) {
	}

	// A method to compare two Complex numbers
	bool operator ==(Complex1 rhs) {
		return (real == rhs.real && imag == rhs.imag) ? true : false;
	}
};

/*

 As discussed in this GFact, in C++, if a class has a constructor which can be called with a single argument,
 then this constructor becomes conversion constructor because
 such a constructor allows conversion of the single argument to the class being constructed.

 We can avoid such implicit conversions as these may lead to unexpected results.
 We can make the constructor explicit with the help of explicit keyword.

 */

class Complex2 {
private:
	double real;
	double imag;

public:
	// Default constructor
	explicit Complex2(double r = 0.0, double i = 0.0) :
			real(r), imag(i) {
	}

	// A method to compare two Complex numbers
	bool operator==(Complex2 rhs) {
		return (real == rhs.real && imag == rhs.imag) ? true : false;
	}
};

class Complex3 {
private:
	double real;
	double imag;

public:
	// Default constructor
	explicit Complex3(double r = 0.0, double i = 0.0) :
			real(r), imag(i) {
	}

	// A method to compare two Complex numbers
	bool operator==(Complex3 rhs) {
		return (real == rhs.real && imag == rhs.imag) ? true : false;
	}
};

int main() {

	// a Complex1 object
	Complex1 com1(3.0, 0.0);

	if (com1 == 3.0)
		cout << "Same" << endl;
	else
		cout << "Not Same" << endl;

	// a Complex object
	Complex2 com2(3.0, 0.0);

	/*
	 if (com2 == 3.0)
	 cout << "Same" << endl;
	 else
	 cout << "Not Same" << endl;

	 */
	// Output: Compiler Error
	// no match for 'operator==' in 'com1 == 3.0e+0'


	// We can still typecast the double values to Complex, but now we have to explicitly typecast it.
	// a Complex object
	Complex3 com3(3.0, 0.0);

	if (com3 == (Complex3) 3.0)
		cout << "Same" << endl;
	else
		cout << "Not Same" << endl;

	return 0;
}
