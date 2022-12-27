// g++ -Wall -Wextra -Werror function_object_functors.cpp
#include <iostream>
using namespace std;

class MultBy {
	int mult;
public:
	MultBy(int n) :
			mult(n) {
		cout << "Constructor Call " << n << endl;
	}
	int operator ()(int n) {
		cout << "[Functors Call] ";
		return mult * n;
	}
};

int main() {
	// Constructor Calls
	puts("Constructor Calls");
	MultBy times4(4);
	MultBy times10(10);
	MultBy times15(15);

	// Function Object Calls
	// Functors are objects that can be treated as though they are a function or function pointer.
	puts("\nFunctors Calls");
	cout << "times4(5) is " << times4(5) << endl;
	cout << "times4(15) is " << times4(15) << endl;
	cout << "times10(5) is " << times10(5) << endl;
	cout << "times10(15) is " << times10(15) << endl;
	cout << "times15(5) is " << times15(5) << endl;
	cout << "times15(15) is " << times15(15) << endl;
	return 0;
}
