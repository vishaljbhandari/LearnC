// gcc -Wall -Wextra -Werror -lstdc++ -lm virtual_pointer.cpp
#include<iostream>
using namespace std;

class Base {
public:
	virtual void show() {
		cout << "Base class - Local Function - virtual show" << endl;
	}
	void np_show() {
		cout << "Base class - Local Function - np_show" << endl;
	}
	void show0() {
		cout << "Base class - Local Function - show0" << endl;
	}
	virtual void print() {
		cout << "Base class - Local Function - virtual print" << endl;
	}
};

class Derived1: public Base {
public:
	void show() {
		cout << "Derived1 class - Overridden function of Base class - show"
				<< endl;
	}
	void show1() {
		cout << "Derived1 class - Local Function - display" << endl;
	}
};

class Derived2: public Derived1 {
public:
	void show() {
		cout << "Derived2 class - Overridden function of Base class - show"
				<< endl;
	}
	void show2() {
		cout << "Derived2 class - Local Function - show2" << endl;
	}
};

int main() {
	cout << "Calls by Base class pointer with Base class reference" << endl;
	Base *bp1 = new Base;
	bp1->np_show();	// Using base class pointer we can call normal function as well.
	bp1->show();// Using base class pointer we can call virtual function, which is overridden  [BASE CLASS VERSION WILL BE CALLED]
	bp1->print();// Using base class pointer we can call virtual function, which is not overridden

	cout << endl;
	cout << "Calls by Base class pointer with Derived1 class reference" << endl;
	Base *bp = new Derived1;
	bp->show(); // RUN-TIME POLYMORPHISM, Instead of calling Base Class Function, it is calling Derived Class Function  [DERIVED CLASS VERSION WILL BE CALLED]
	bp->np_show();

	cout << endl;
	cout << "Calls by Derived1 class pointer with Derived1 class reference"
			<< endl;
	Derived1 *dp1 = new Derived1();
	dp1->print();

	cout << endl;
	cout << "Calls by Derived1 class pointer with Derived2 class reference"
			<< endl;
	Derived1 *dp2 = new Derived2;
	dp2->show1();
	dp2->show0();
	dp2->show();
	return 0;
}
