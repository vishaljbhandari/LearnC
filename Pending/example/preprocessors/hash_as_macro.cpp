// gcc -Wall -Wextra -Werror -lstdc++ hash_as_macro.cpp
#include <iostream>
using namespace std;

#define concat(a, b) a ## b
// The ## operator is used to concatenate two tokens

#define MKSTR( x ) #x
// The # operator causes a replacement-text token to be converted to a string surrounded by quotes.

int main() {
	int xy = 100;

	cout << concat(x, y) << endl;
	// This converted into a concatenated string "xy"
	// cout << xy << endl;

	cout << MKSTR(HELLO C++) << endl;

	return 0;
}
