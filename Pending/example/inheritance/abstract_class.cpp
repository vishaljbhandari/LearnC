// gcc -Wall -Wextra -Werror -lstdc++ -lm abstract_class.cpp

#include<iostream>
using namespace std;

// A pure virtual function (or abstract function) in C++ is a virtual function for which we don’t have implementation, we only declare it.
// A pure virtual function is declared by assigning 0 in declaration. The part =0 is called pure-specifier.
// It makes the virtual function a "pure" and the class an "abstract".
// A class is abstract if it has at least one pure virtual function.

class Test1	// Abstract Class
{
public:
	virtual void show() = 0;// Pure Virtual Function, No Function Body, Assigned with = 0
};

class Test2     // An Abstract Class
{
	int a;
public:
	virtual void show() = 0;    // Pure Virtual Function
};

class Test3 {    // An Abstract Class
	int a;
public:
	virtual void show() = 0;    // Pure Virtual Function
	virtual void npvf_show();
	void np_show() {
		cout << "Non Virtual Function\n";
	}
};

class Test4 {	// Not an Abstract Class
public:
	virtual void show(); // Not a Pure Virtual Function
};

// An abstract class can have constructors.
class Test5 {	// An Abstract Class
public:
	Test5(int i) {
		cout << "Test5, Abstract Class, Constructor " << i << endl;
	}
	virtual void show() = 0; // Pure Virtual Function
};

// If we do not override the pure virtual function in derived class, then derived class also becomes abstract class.
namespace abstract_example {
class Base {
public:
	virtual void show() = 0;
	virtual void print() = 0;
};

class Basic {
	int var;
public:
	virtual void show() = 0;
	virtual void print() = 0;
};
// Derived1 class is also an abstract class, as It is inheriting abstract class without overriding pure virtual function
class Derived1: public Base {
};
// show(pure virtual function of base abstract class) is not overridden in derived

// Derived2 class is not abstract class, as it has overridden pure virtual function of base class
// A pure virtual function is implemented by classes which are derived from a Abstract class
class Derived2: public Base {
public:
	void show() {
		cout << "In Derived \n";
	} // overridden pure virtual function of abstract base class
	void print() {
		cout << "In Derived \n";
	} // overridden pure virtual function of abstract base class
};
}

class sample {

};

int main(void) {
	// Test1 t1;  // Compilation Error, As Test1 is Abstract class, it has a Pure Virtual Function
	// Test2 t2;  // Compilation Error, As Test1 is Abstract class, it has a Pure Virtual Function
	// Test3 t3;  // Compilation Error, As Test1 is Abstract class, it has a Pure Virtual Function

	/*
	 Test4 t4; // This will Give Error, Because Pure Virtual Function is not assigned with Zero.
	 // It will give following error {(.text._ZN5Test4C2Ev[_ZN5Test4C5Ev]+0xf):
	 // abstract_class.cpp:(.text+0xa): undefined reference to `vtable for Test4'
	 // undefined reference to `vtable focollect2: ld returned 1 exit status } collect2: ld returned 1 exit status }
	 */

	// Test5 t5;  // Compilation Error, As Test1 is Abstract class, it has a Pure Virtual Function
	// Compilation error, cannot declare variable ‘d’ to be of abstract type ‘abstract_example::Derived1’
	// Cannot declare variable of an abstract class
	// abstract_example::Derived1 d; // Derived1 class is also an abstract class, as It is inheriting abstract class without overriding pure virtual function
	// We can have pointers and references of abstract class type, with reference of derived classes overriding pure virtual functions
	abstract_example::Base *bp = new abstract_example::Derived2();
	bp->show();

	// Size of simple class
	cout << "Size of sample class - " << sizeof(sample) << endl;// will give 1 byte
	// size of abstract class without any data variables
	cout << "Size of abstract class - " << sizeof(abstract_example::Base)
			<< endl;// will give 4 or 8 byte for all virtual functions, size of virtual table pointer
	// size of abstract class with other data members
	cout << "Size of abstract class with members - "
			<< sizeof(abstract_example::Basic) << endl;	// 4 or 8 + size of data members (8+8) in this case
	// for all virtual functions .. only one virtual pointer table pointer will be added by compiler into class
	return 0;
}

/*	CONCEPTS
 *	--------
 *	1. Abstract classes cannot be instantiated
 *	2. Because these classes are logically incomplete class
 *	3. You have to add implementation or characters to these classes, by inheriting them to some other class.
 *	4. Constructor of an Abstract class gets called during object chaining.
 *	5. We can never directly create an object of Abstract class even if it contains a Constructor and all methods are implemented.
 */
