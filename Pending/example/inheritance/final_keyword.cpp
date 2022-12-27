// gcc -lstdc++ -lm final_keyword.cpp

#include <iostream>
using namespace std;

// Sometimes you don’t want to allow derived class to override the base class’ virtual function.
// C++ 11 allows built-in facility to prevent overriding of virtual function using final specifier.

class Base {
public:
	virtual void myfun() final { // This function can be overridden , Derived class can not redefined this function
		// final keyword should be used with virtual keyword
		cout << "myfun() in Base" << endl;
	}
};
class Derived: public Base {
	// /*
	void myfun() { // Compilation Error, As myFun function is declared as final in Base class
		cout << "myfun() in Derived" << endl;
	}
	// */
};

// final specifier in C++ 11 can also be used to prevent inheritance of class / struct.
// If a class or struct is marked as final then it becomes non inheritable and it cannot be used as base class/struct.

class Parent final { // Parent class is marked as final, this class can not be inherited
};

// class Child: public Parent {  }; // Compilation error, as Parent class is marked as final, Child can not inherit Parent class

int main() {
	Derived d;
	Base &b = d;
	b.myfun();

	int final = 20;	// final is not a key word in c++ 11, there fore it can be used as identifier, compiler will check the context, where it is used and assume the meaning
	cout << final << endl;
	return 0;
}
