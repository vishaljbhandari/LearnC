// gcc -lstdc++ -lm constructor.cpp
#include <iostream>
using namespace std;

class Box {
	// Implicit Default Public Constructor, provided by compiler, in absence of explicit default constructor
};

class Box0 {
	Box0() {
	}		// Private Constructor
public:
};

class Box1 {
public:
	Box1() {
	}	// Explicit Public Default Constructor
};

class Box2 {
	Box2() {
	}		// Explicit Private Default Constructor
};

class Box3 {
	int length;    // Length of a box
public:
	Box3(int d) {
		length = d;
	}	// Parameterized Constructor
};

class Box4 {
	int x;
	Box4() {
		x = 0;
	}
public:
	Box4(int x) :
			x(x) {
		Box4 b;	// Allowed, default argument constructor is private, and this constructor call is with in class scope only.
	}
	static void create(int x) {
		Box4 b;	// Allowed, default argument constructor is private, and this constructor call is with in class scope only.
	}

	void makeObj() {
		Box4 b;	// Allowed, default argument constructor is private, and this constructor call is with in class scope only.
	}
};

int main() {
	Box box; // can be initiated, default Constructor is provided by compiler
	Box1 box1;      // can be initiated, default Constructor is written by user
	// Box2 box2; // can not be initiated, default Constructor is written but is private
	// Box3 box3; // can not be initiated, no default Constructor written and provided by compiler as user has written a Constructor, which expects only one argument.
	Box3 box3(5); // can be initialized, as single argument Constructor is available

	// How to call private constructor
	// By other public constructor
	Box4 b4(5);	// b4 will be created as single argument constructor is public

	// By static functions (public)
	Box4::create(5);		// calls public static function

	// By other public functions
	Box4 b5(5);
	b5.makeObj();

	return 0;
}
