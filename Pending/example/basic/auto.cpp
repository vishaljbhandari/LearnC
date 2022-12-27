// gcc -lstdc++ -lm auto.cpp
#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

int Sum(int x, int y) {
	return x + y;
}

int main(int argc, char **argv) {
	int i = 47;
	const char *cstr = "this is a c-string";
	string sclass = string("this is a string class string");

	auto str = string("this is a string class string");
	decltype(str) y;

	cout << "type of i is " << typeid(i).name() << endl;
	cout << "type of cstr is " << typeid(cstr).name() << endl;
	cout << "type of sclass is " << typeid(sclass).name() << endl;
	cout << "type of x is " << typeid(str).name() << endl;
	cout << "type of y is " << typeid(y).name() << endl;

	std::vector<int> alpha { 1, 2, 3 };
	// auto beta { 1, 2, 3 }; // error: initializer for variable 'beta' with type 'auto' contains multiple expressions
	auto gamma = { 1, 2, 3 }; // can do this, but... wrong type
	auto delta = std::vector<int> { 1, 2, 3 };
	std::vector<int> epsilon;
	// auto zeta; // error: declaration of variable 'zeta' with deduced type 'auto' requires an initializer

	int i_array[] = { 1, 2, 3, 4, 5 };
	for (auto i : i_array) {
		printf("i is %d\n", i);
	}

	//One of my favorite features of C++11 ;)
	auto au_i = 10;
	auto au_j = 5;
	auto au_sum = au_i + 4.3f;

	auto result = Sum(au_i, au_j);
	static auto sa_y = 2;
	const int ci_x = 10;
	//Works with qualifiers
	const auto var = ci_x;
	//Deduced to reference
	auto &var1 = ci_x;

	//Deduced to a pointer. * is not necessary
	auto *ptr = &ci_x;

	auto x = string("this is a string");
	printf("x is %s\n", x.c_str());
	if (typeid(x) == typeid(string))
		puts("x is string");

	vector<int> vi = { 1, 2, 3, 4, 5 };
	for (vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
		printf("int is %d\n", *it);
	}

	int ages[3];
	ages[1] = 18;
	ages[2] = 21;
	ages[3] = 35;

	int total(0);
	for (auto age : ages) {
		total += age;
	}
	cout << "Total = " << total << endl;

	return 0;
}
