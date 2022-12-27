// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
using namespace std;

//Works only for homogeneous data types
template<typename T>
void show_list(initializer_list<T> args) {
	for (const auto &x : args) {
		cout << x << " ";
	}
}

// To handle base case of below recursive
// Variadic function Template
void print() {
	cout << "I am empty function and "
			"I am called at last.\n";
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template<typename T, typename ... Types>
void print(T var1, Types ... var2) {
	cout << var1 << endl;

	print(var2...);
}

// Driver code
int main() {
	print(1, 2, 3.14, "Pass me any "
			"number of arguments", "I will print\n");

	show_list( { 1, 2.5, 3, 4 });

	return 0;
}
