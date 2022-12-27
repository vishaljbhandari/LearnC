#include<iostream>
using namespace std;

struct s1 {
	int a;
};

struct s2 {
	int a;
};

union u1 {
	int a;
	char ch;
};

class c1 {
	int n;
};

class c2 {
	int y;
	virtual void fun() {
	}
	virtual void test() {
	}
};

class c3 {
	virtual void fun() {
	}
	virtual void test() {
	}
};

class c4 {
	virtual void fun() {
	}
};

class c5 {
	void fun() {
	}
};

class c6 : public c1{
	int y;
};

int main() {
	cout << sizeof(s1) << endl;
	cout << sizeof(s2) << endl;
	cout << sizeof(u1) << endl;
	cout << sizeof(c1) << endl;
	cout << sizeof(c2) << endl;
	cout << sizeof(c3) << endl;
	cout << sizeof(c4) << endl;
	cout << sizeof(c5) << endl;
	cout << sizeof(c6) << endl;
	return 0;
}
