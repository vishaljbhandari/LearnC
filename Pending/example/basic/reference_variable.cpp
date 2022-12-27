// gcc -lm -lstdc++ reference_variable.cpp
#include<iostream>
#include<stdio.h>
using namespace std;

/*
 A reference variable is an alias, that is, another name for an already existing variable.
 Reference is another name of a variable not of a address
 Once a reference is initialized with a variable, either the variable name or the reference name may be used to refer to the variable.

 References vs Pointers (Differences)
 1) You cannot have NULL references. You must always be able to assume that a reference is connected to a legitimate piece of storage.
 2) Once a reference is initialized to an object, it cannot be changed to refer to another object. Pointers can be pointed to another object at any time.
 3) A reference must be initialized when it is created. Pointers can be initialized at any time. without referenced(variable which is being referenced) variable reference variable has not existance

 Creating References in C++
 Think of a variable name as a label attached to the variable's location in memory.
 You can then think of a reference as a second label attached to that memory location.
 Therefore, you can access the contents of the variable through either the original variable name or the reference.

 int i = 17;
 We can declare reference variables for i as follows.
 int& r = i;
 or
 int &i

 Read the & in these declarations as reference.
 Read the first declaration as "r is an integer reference initialized to i"
 Read the second declaration as "s is a double reference initialized to d".

 */

// function receiving reference of an int variable from caller function
void fun(int &x) {		// x is a reference variable
	cout << "function with reference variables is called" << endl;
	x = x + 10;   // value changed
}

// Passing parameters by references in C++
// function definition to swap the values.
void swap(int &x, int &y) {
	//  in case of pass by references, null check is not required, because variable can not be a nullptr, they may have default value. and reference can be of any variable only
	int temp;
	temp = x; /* save the value at address x */
	x = y; /* put y into x */
	y = temp; /* put x into y */

	return;
}

// Returning values by reference in C++
double vals[] = { 10.1, 12.6, 33.1, 24.1, 50.0 };

double& setValues(int i) {
	return vals[i];   // return a reference to the ith element
}

// When returning a reference, be careful that the object being referred to does not go out of scope.
// So it is not legal to return a reference to local var. But you can always return a reference on a static variable.

int& func() {
	int q;
	//! return q; // Compile time error, as q is local variable, its memory is from local stack section, outside function q memory does not exist
	static int x;
	return x;     // Safe, x lives outside this scope, as memory is not from stack memory
}

int main() {
	// declare simple variables
	int i;
	double d;

	// declare reference variables
	int &r = i;
	double &s = d;

	i = 5;
	cout << "Value of i : " << i << endl;
	cout << "Size of i : " << sizeof(i) << endl;
	cout << "Value of i reference : " << r << endl;
	cout << "Size of i reference : " << sizeof(r) << endl;

	d = 11.7;
	cout << "Value of d : " << d << endl;
	cout << "Size of d : " << sizeof(d) << endl;
	cout << "Value of d reference : " << s << endl;
	cout << "Size of d reference : " << sizeof(s) << endl;

	// References used as function argument lists.
	cout << endl << "References used as function argument lists" << endl;

	int a = 100;
	int b = 200;

	cout << "Before swap, value of a :" << a << endl;
	cout << "Before swap, value of b :" << b << endl;

	/* calling a function to swap the values.*/
	swap(a, b);

	cout << "After swap, value of a :" << a << endl;
	cout << "After swap, value of b :" << b << endl;

	// References used as function return values.
	cout << endl << "References used as function return values" << endl;

	cout << "Value before change" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "vals[" << i << "] = ";
		cout << vals[i] << endl;
	}

	setValues(1) = 20.23; // change 2nd element
	setValues(3) = 70.8;  // change 4th element

	cout << "Value after change" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "vals[" << i << "] = ";
		cout << vals[i] << endl;
	}

	// int &ref = 1; 	// this is not allowed, as constant literal value can not be assigned to non constant reference

	const int &ref1 = 1; 	// this is allowed, constant literal value can be assigned to cont reference variable

	// int &ref2 = NULL;		// not allowed, a reference can not be a NULL
	// int &ref3 = nullptr;		// not allowed, a reference can not be a nullptr

	return 0;
}
