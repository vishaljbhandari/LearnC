// gcc -lstdc++ -lm function_calls.cpp
// difference between call by value and call by reference
#include<iostream>
#include<stdio.h>
using namespace std;

// Received as copy of actual argument
void by_value(int a, int b) {
	a = a / 5;
	b = a / 2;
	cout << "Inside fxn a is : " << a << " &a : " << &a << endl;
	cout << "Inside fxn b is : " << b << " &b : " << &b << endl;
}

// Received  as reference/alias of actual argument
void by_refer(int &a, int &b) {
	a = 400;
	b = 700;
	cout << "Inside fxn a is : " << a << " &a : " << &a << endl;
	cout << "Inside fxn b is : " << b << " &b : " << &b << endl;
}

// Received  as pointer/address of actual argument
void by_pointer(int *a, int *b) {
	*a = 400;
	*b = 700;
	cout << "Inside fxn *a is : " << *a << " a : " << a << " &a : " << &a
			<< endl;
	cout << "Inside fxn *b is : " << *b << " b : " << b << " &b : " << &b
			<< endl;
}

int main() {
	int a = 20, b = 26;
	cout << "Call by value" << endl;
	cout << "Before calling fxn a is : " << a << " &a : " << &a << endl;
	cout << "Before calling fxn b is : " << b << " &b : " << &b << endl;
	by_value(a, b);
	cout << "After calling fxn a is : " << a << " &a : " << &a << endl;
	cout << "After calling fxn b is : " << b << " &b : " << &b << endl;
	cout << "Call by value passes copies of actual arguments" << endl;
	cout << "Actual values are not changed" << endl << endl;

	a = 20;
	b = 26;
	cout << "Call by reference" << endl;
	cout << "Before calling fxn a is : " << a << " &a : " << &a << endl;
	cout << "Before calling fxn b is : " << b << " &b : " << &b << endl;
	by_refer(a, b);
	cout << "After calling fxn a is : " << a << " &a : " << &a << endl;
	cout << "After calling fxn b is : " << b << " &b : " << &b << endl;
	cout << "Call by value passes references of actual arguments" << endl;
	cout << "Actual values are changed" << endl << endl;

	a = 20;
	b = 26;
	cout << "Call by pointer" << endl;
	cout << "Before calling fxn a is : " << a << " &a : " << &a << endl;
	cout << "Before calling fxn b is : " << b << " &b : " << &b << endl;
	by_pointer(&a, &b);
	cout << "After calling fxn a is : " << a << " &a : " << &a << endl;
	cout << "After calling fxn b is : " << b << " &b : " << &b << endl;
	cout << "Call by value passes pointers of actual arguments" << endl;
	cout << "Actual values are changed" << endl;

	return (0);
}
