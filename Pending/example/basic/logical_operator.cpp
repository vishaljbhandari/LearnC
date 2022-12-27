// vi gcc -lm -lstdc++ logical_operator.cpp
#include <iostream>
using namespace std;

int main() {
	cout << "1 & 1 is " << (1 & 1) << endl;
	cout << "1 | 1 is " << (1 | 1) << endl;
	cout << "1 ^ 1 is " << (1 ^ 1) << endl;
	cout << "255 << 2 is " << (255 << 2) << endl;
	cout << "255 >> 2 is " << (255 >> 2) << endl;
	cout << "~255 is " << ~(unsigned int) 255 << endl;
	return 0;
}
