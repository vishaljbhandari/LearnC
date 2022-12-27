// gcc -lm -lstdc++ switch.cpp
// or
// g++ switch.cpp

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	cout << "All features will remain same as of C" << endl;

	const int ONE = 1;
	const int TWO = 2;
	const int THREE = 3;
	const int FOUR = 4;

	int x = 3;
	switch (x) {
	case ONE:
		puts("one");
		break;
	case TWO:
		puts("two");
		break;
	case THREE:
		puts("three");
		break;
	case FOUR:
		puts("four");
		break;
	default:
		puts("default");
		break;
	}
}
