// gcc -lstdc++ -lm function_pointer.cpp

#include <iostream>
using namespace std;

void Print(int count, char ch) {
	for (int i = 0; i < count; ++i) {
		cout << ch;
	}
	cout << endl;
}

int fun(int x, char y){
	int z = 5;
	cout << y << " " << x << endl;
	return z;
}
void EndMessage() {
	cout << "End of program" << endl;
}

int main() {
	//Register a handler. This handler will be invoked after main returns
	atexit(EndMessage);

	Print(5, '#');	// Conventional call

	void (*pfn)(int, char) = Print;
	//One way to invoke function pointer
	(*pfn)(8, '@');		// Calling using function pointer
						// as (*pfn) is address of "Print" function

	//Another way to invoke function pointer
	pfn(5, '+');	// function way

	// FUnction pointer for fun

	int (*qfn)(int, char) = fun;

	int x = (*qfn)(5, 'W');
	cout << x << " qfn function" << endl;

	cout << "end of main" << endl;
	return 0;
}
