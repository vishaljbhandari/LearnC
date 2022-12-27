// gcc -Wall -Wextra -Werror -lstdc++ -lm inheritance.cpp
#include<iostream>
#include<stdlib.h>
using namespace std;

class Base {
	int i1, *ip1;
	char c1, *cp1;
public:
	Base() {
		i1 = 1;
		c1 = 'a';
		ip1 = &i1;
		cp1 = &c1;
	}
	void printBase() {
		cout << "printBase function of Base class" << endl;
		cout << "i1 = " << i1 << ", c1 = " << c1 << ", ip1 = " << *ip1
				<< ", cp1 = " << *cp1 << endl;
		cout << "sizeof(i1) = " << sizeof(i1) << ", sizeof(c1) = " << sizeof(c1)
				<< endl;
		cout << "sizeof(cp1) = " << sizeof(cp1) << ", sizeof(ip1) = "
				<< sizeof(ip1) << endl;
	}
};

class Derived: private Base {
	int i1, *ip1;
	char c1, *cp1;
public:
	Derived() {
		i1 = 11;
		c1 = 'A';
		ip1 = &i1;
		cp1 = &c1;
	}
	void printDerived() {
		cout << "printDerived function of Derived class" << endl;
		cout << "i1 = " << i1 << ", c1 = " << c1 << ", ip1 = " << *ip1
				<< ", cp1 = " << *cp1 << endl;
		cout << "sizeof(i1) = " << sizeof(i1) << ", sizeof(c1) = " << sizeof(c1)
				<< endl;
		cout << "sizeof(cp1) = " << sizeof(cp1) << ", sizeof(ip1) = "
				<< sizeof(ip1) << endl;
		printBase(); // Calling base function, in absence of overriding function of Derived class
	}
	/*
	 void printBase() {
	 cout << "Overriding printBase function of Base class" << endl;
	 } 	// Overriding printBase function of Base class
	 */
};

int main() {
	cout << "Using Base class & objects" << endl;
	Base b1, *b2 = new Base();
	b1.printBase();
	b2->printBase();
	cout << "Size Of Base Object is " << sizeof(b1) << endl;
	cout << "Size Of Base Object Pointer is " << sizeof(b2) << endl;
	delete b2;

	cout << endl << "Using Derived class & objects" << endl;
	Derived d1, *d2 = new Derived();
	d1.printDerived();
	d2->printDerived();
	cout << "Size Of Derived Object is " << sizeof(d1) << endl;
	cout << "Size Of Derived Object Pointer is " << sizeof(d2) << endl;
	delete d2;
	return 0;
}
