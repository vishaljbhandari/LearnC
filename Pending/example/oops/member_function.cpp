// gcc -Wall -Wextra -Werror -lstdc++ -lm member_function.cpp
#include <iostream>
using namespace std;

class A {
	int _value = 0;
public:
	void setv(const int a) {
		_value = a;
	}
	;
	int getv() {
		return _value;
	}
	;
};

int main() {
	A a;
	a.setv(42);
	cout << "a is " << a.getv() << endl;

	A *atr = new A();
	atr->setv(4);
	cout << "a is " << atr->getv() << endl;
	return 0;
}
