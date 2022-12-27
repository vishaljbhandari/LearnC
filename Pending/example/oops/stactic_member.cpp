// gcc -lstdc++ -lm stactic_member.cpp
#include<iostream>
using namespace std;

class master {
	int a, b;
	static void printstatic();

public:
	master() {
		a = b = 0;
	}
	static int st;
	static int sdata;
	void getdata();
	void printdata();
	void increment();
	static void staticdouble();
};

int master::st = 10;
int master::sdata = 5;

void master::getdata() {
	cout << "Data members" << endl << "a : ";
	cin >> a;
	cout << "b : ";
	cin >> b;
	cout << endl;
}

void master::printdata() {
	cout << "Data members...." << endl << "a : " << a << "  b : " << b << endl;
	printstatic();
}

void master::printstatic() {
	cout << "Static data member..." << endl << "st : " << st << endl << endl;
}

void master::increment() {
	a++;
	b++;
	staticdouble();
}

void master::staticdouble() {
	st *= 2;
	sdata++;
}

int main() {
	master m1;
	int x = 5;
	cout << "Input data....." << endl;
	m1.getdata();
	cout << "Inside loop..... " << endl << endl;
	for (int i = 0; i < x; i++) {
		cout << "i : " << i << endl;
		m1.increment();
		m1.printdata();
	}
	cout << "After loop static member double ..." << endl;
	master::staticdouble();
	m1.printdata();
	return 0;
}
