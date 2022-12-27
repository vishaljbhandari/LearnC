// gcc -lm -lstdc++ typeid.cpp
#include <iostream>
#include <typeinfo>
using namespace std;

/*
 Queries information of a type.
 Used where the dynamic type of a polymorphic object must be known and for static type identification.

 The header <typeinfo> must be included before using typeid (if the header is not included, every use of the keyword typeid makes the program ill-formed.)
 The typeid expression is an lvalue expression which refers to an object with static storage duration, of the polymorphic type const std::type_info or of some type derived from it.

 */

// typeid( type )	(1)
// typeid( expression )	(2)
struct A {
};
struct B {
};

struct A1 {
	int x;
};
struct B1 {
	int x;
};

A1 a;
B1 b;

int main() {
	struct A a1;
	struct A a2;
	struct B b1;
	struct B b2;

	if (typeid(a1) == typeid(struct A)) {
		cout << "same" << endl;
	} else {
		cout << "different" << endl;
	}

	if (typeid(a) == typeid(A1)) {
		puts("same");
	} else {
		puts("different");
	}

	long n = 42;
	auto fp = [](const auto &n) -> auto {
		return n * 4;
	};
	auto x = fp(n);

	cout << "value of x: " << x << " type of x: " << typeid(x).name() << endl;

	return 0;
}
