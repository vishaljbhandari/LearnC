// gcc -Wall -Wextra -Werror -lstdc++ -lm function_overriding.cpp

// Function Overriding (achieved at run time)
// It is the redefinition of base class function in its derived class with same signature i.e return type and parameters.
// It can only be done in derived class.

#include<iostream>
using namespace std;

class BaseClass {
public:
	virtual void Display() {
		cout << "\nThis is Display() method"
				" of BaseClass";
	}
	void Show() {
		cout << "\nThis is Show() method "
				"of BaseClass";
	}
};

class DerivedClass: public BaseClass {
public:
	// Overriding method - new working of
	// base class's display method
	void Display() {
		cout << "\nThis is Display() method"
				" of DerivedClass";
	}
};

// Driver code
int main() {
	DerivedClass dr;
	BaseClass &bs = dr;
	bs.Display();
	dr.Show();
}

/*
 Function Overloading VS Function Overriding

 >> Inheritance: Overriding of functions occurs when one class is inherited from another class. Overloading can occur without inheritance.
 >> Function Signature:
 	 FOR - Overloaded, functions must differ in function signature ie either number of parameters or type of parameters should differ.
 	 FOR - Overriding, function signatures must be same.
 >> Scope of functions: Overridden functions are in different scopes; whereas overloaded functions are in same scope.
 >> Behavior of functions: Overriding is needed when derived class function has to do some added or different job than the base class function. Overloading is used to have same name functions which behave differently depending upon parameters passed to them.


 Overriding Virtual Functions -



 Overriding Special Functions -

 */
