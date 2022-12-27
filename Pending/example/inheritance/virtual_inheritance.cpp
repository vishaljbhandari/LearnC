// gcc -Wall -Wextra -Werror -lstdc++ -lm virtual_inheritance.cpp
#include<iostream>
using namespace std;

class Base {
	int x;
	int a;
public:
	Base() {
		x = 5;
		cout << "Base class Constructor " << x << endl;
		print();
	}
	Base(int x) :
			x(x) {
		cout << "Base class Parameterized Constructor " << x << endl;
		print();
	}
	virtual void pvf_print() = 0; // This is pure virtual function, This function has to be defined in Derived class
	virtual void print() {
		cout << "Base class member function - virtual print " << x << endl;
	}
	void np_show() {
		cout << "Base class member function - non virtual np_show " << x
				<< endl;
	}
};

class Derived: public Base {
	int x;
public:
	Derived() {
		cout << "Derived class Constructor " << x << endl;
		print();
	}
	void pvf_print() {
		cout
				<< "Derived class Overriding Base class member function - pure virtual pvf_print "
				<< x << endl;
	}
	void print() {
		cout
				<< "Derived class Overriding Base class member function - virtual print "
				<< x << endl;
	}
};

namespace object_slicing {
// In C++, a derived class object(not pointers) can be assigned to a base class object, but the other way is not possible.
// base class must be a complete type (not an abstract class)

/*
 We can avoid above unexpected behavior with the use of pointers or references.
 Object slicing doesn’t occur when pointers or references to objects are passed as function arguments since a pointer or reference of any type takes same amount of memory.
 For example, if we change the global method myfunc() in the above program to following, object slicing doesn’t happen.

 Derived derivedObject;
 Base &obj = derivedObject;		// Not an object slicing
 Derived *dptr = new Derived();
 Base *bptr = dptr;				// Not an object slicing

 */

/*
 // Object slicing can be prevented by making the base class function pure virtual there by disallowing object creation.
 // It is not possible to create the object of a class which contains a pure virtual method.

 Derived d_slice;
 Base sliced = d_slice; // Slicing can not happen as Base class is abstract class

 // if base class is abstract then derived can not slice a base class object;
 */

class Base {
protected:
	int i;
public:
	Base(int a) {
		i = a;
	}
	virtual void display() {
		cout << "I am Base class object, i = " << i << endl;
	}
};

class Derived: public Base {
	int j;
public:
	Derived(int a, int b) :
			Base(a) {
		j = b;
	}
	void display() {
		cout << "I am Derived class object, i = " << i << ", j = " << j << endl;
	}
};

void example() {
	Base b(33);
	Derived d(45, 54);
	Base obj = d;
	d.display();
	obj.display();
}

}

int main() {
	// Base *bptr = new Base(); // Base class pointer can not be created of Base class type, because Base class is an abstract class
	/*
	 Base b;	// Base class object can not be created, because Base class is an abstract class
	 b.np_show();
	 b.print();
	 b.pvf_print();
	 */
	Base *b1 = new Derived();   // Base class pointer of Derived class reference
	b1->print();     // calling normal base class function by Base class pointer
	b1->pvf_print();        		// function call by Base class pointer
	b1->np_show();

	Derived *d1 = new Derived();    // normal pointer of Derived class type
	d1->print();            		// function call by Derived class pointer
	d1->pvf_print();        		// function call by Derived class pointer
	d1->np_show();

	Derived d;
	d.print();
	d.pvf_print();
	d.np_show();

	// Calling base virtual function

	// Calling derived virtual function

	// Down casting

	// Up casting

	// Object Slicing = Base and Derived class objects assignment
	object_slicing::example();

	// Using base class pointer we can call virtual function, which is overridden  [BASE CLASS VERSION WILL BE CALLED]

	// Using base class pointer we can call virtual function, which is not overridden

	// RUN-TIME POLYMORPHISM, Instead of calling Base Class Function, it is calling Derived Class Function  [DERIVED CLASS VERSION WILL BE CALLED]

	return 0;
}

