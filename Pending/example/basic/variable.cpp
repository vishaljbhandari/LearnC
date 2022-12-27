// gcc -lm -lstdc++ variable.cpp
#include <iostream>
using namespace std;

/*
 C++ Variables
 Variables are containers for storing data values.

 In C++, there are different types of variables (defined with different keywords), for example:

 int - stores integers (whole numbers), without decimals, such as 123 or -123
 double - stores floating point numbers, with decimals, such as 19.99 or -19.99
 char - stores single characters, such as 'a' or 'B'. Char values are surrounded by single quotes
 string - stores text, such as "Hello World". String values are surrounded by double quotes
 bool - stores values with two states: true or false
 */

int main() {

	int myNum = 10;
	cout << myNum << endl;
	myNum = 15;
	cout << myNum << endl;

	myNum = 5;               // Integer (whole number without decimals)
	double myFloatNum = 5.99;    // Floating point number (with decimals)
	char myLetter = 'D';         // Character
	string myText = "Hello";     // String (text)
	bool myBoolean = true;       // Boolean (true or false)

	int x = 5;
	int y = 6;
	int sum = x + y;
	cout << sum;

	int uninitialized;	// assigning unassigned variable to itself
	if (uninitialized = uninitialized) {
		cout << "Hello uninitialized " << uninitialized << endl;
	}

	int initialized = 5;	// assigning unassigned variable to itself
	if (initialized = initialized) {
		cout << "Hello uninitialized " << initialized << endl;
	}

	register int reg;
	cout << reg << endl;
	// auto int au;		// auto is keyword in c++ for auto type, no auto int type is available
	int au;
	cout << au << endl;

	return 0;
}
