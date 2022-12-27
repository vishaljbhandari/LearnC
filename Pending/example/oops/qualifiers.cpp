// gcc -Wall -Wextra -Werror -lstdc++ -lm qualifiers.cpp
#include <iostream>
using namespace std;

class S {
public:
	int static_value() {
		static int x = 7;
		return ++x;
	}
};

int func() {
	int x = 7;
	return ++x;
}

int main() {
	int i = 42;
	cout << "The integer is	" << i << endl;
	int j = func();
	cout << "The integer is	" << j << endl;
	S s;
	int k = s.static_value();
	cout << "The integer is	" << k << endl;

	j = func();
	cout << "The integer is	" << j << endl;

	k = s.static_value();
	cout << "The integer is	" << k << endl;
	return 0;
}
