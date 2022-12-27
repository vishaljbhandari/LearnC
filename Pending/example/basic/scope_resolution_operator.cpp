// gcc -lm -lstdc++ scope_resolution_operator.cpp

#include<iostream>
#include<stdio.h>
using namespace std;

int a = 20; // global declaration of integer variable a, global version of variable a

/*
 The :: (scope resolution) operator is used to get hidden names due to variable scopes so that you can still use them.
 The scope resolution operator can be used as both unary and binary.
 You can use the unary scope operator if a namespace scope or global scope name is hidden by a particular declaration of an equivalent name during a block or class.

 its usage
 1) To access a global variable when there is a local variable with same name
 2) To define a function outside a class.
 3) To access a class’s static variables.
 4) In case of multiple Inheritance
 5) For namespace (std::cout)
 6) Refer to a class inside another class : If same variable name exists in two ancestor classes, we can use scope resolution operator to distinguish.
 A::x and B::x to refer same variable name of different classes


 For example, if you have a global variable of name my_var and a local variable of name my_var, to access global my_var, you'll need to use the scope resolution operator.

 */

int my_var = 5;

class X {
public:
	static int count;
	void fun();
};
int X::count = 10;  // define static data member
// You can also use the scope resolution operator to use class names or class member names.
// If a class member name is hidden, you can use it by prefixing it with its class name and the class scope operator.

// defining a class function out side of a class
void X::fun() {
	cout << "inside X class fun function " << endl;
}

class outside {
public:
	int x;
	class inside {
	public:
		int x;
		static int y;
		int foo();

	};
};
int outside::inside::y = 5;

int main(void) {

	cout << "global " << ::my_var << ", global : " << my_var << endl;
	// before local version .. all references will point to global version
	int my_var = 0;
	cout << "global " << ::my_var << ", local : " << my_var << endl;

	::my_var = 1;  // accessing global scoped version
	my_var = 2;    // accessing local scoped version

	cout << "global " << ::my_var << ", local : " << my_var << endl;

	X obj;
	obj.fun();

	int X = 0;   // hides class type X
	cout << X::count << endl;   // use static member of class X

	outside A;		// outer class
	outside::inside B;	// inner class

	std::cout << "End" << std::endl;

	return 0;
}
