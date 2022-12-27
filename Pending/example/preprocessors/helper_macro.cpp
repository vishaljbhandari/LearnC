// gcc -Wall -Wextra -Werror -lstdc++ helper_macro.cpp
#include <iostream>
using namespace std;

int main() {
	cout << "Value of __LINE__ : " << __LINE__ << endl;	// Line number in source code
	cout << "Value of __FILE__ : " << __FILE__ << endl;	// File name of source code
	cout << "Value of __DATE__ : " << __DATE__ << endl;	// Date when this line was executed
	cout << "Value of __TIME__ : " << __TIME__ << endl;	// Time when this line was executed

	return 0;
}
