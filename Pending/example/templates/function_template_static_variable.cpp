// gcc -lstdc++ -lm function_template_static_variable.cpp
#include <iostream>

using namespace std;

// Each instantiation of function template has its own copy of local static variables.
// For example, in the following program there are two instances: void fun(int ) and void fun(double ). So two copies of static variable i exist.

template<typename T>
void fun(const T &x) {
	static int i = 10;
	cout << ++i;
	return;
}

int main() {
	fun<int>(1);  // prints 11
	cout << endl;
	fun<int>(2);  // prints 12
	cout << endl;
	fun<double>(1.1); // prints 11
	cout << endl;
	return 0;
}
