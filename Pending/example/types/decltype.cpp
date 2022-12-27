// gcc -Wall -Wextra -Werror -lstdc++ -lm decltype.cpp
#include <iostream>
#include <string>
#include <typeinfo>
#include<tuple>
#include <vector>
using namespace std;

int main() {
	int i = 47;
	const char *cstr = "this is a c-string";
	string strobj("this is a string class string");

	auto x = string("this is a string class string");
	decltype(x) y;

	cout << "type of i is " << typeid(i).name() << endl;
	cout << "type of cstr is " << typeid(cstr).name() << endl;
	cout << "type of strobj is " << typeid(strobj).name() << endl;
	cout << "type of x is " << typeid(x).name() << endl;
	cout << "type of y is " << typeid(y).name() << endl;

	tuple<int, string, int> tpl;
	decltype(tpl) typ_tpl;
	cout << "type of y is " << " " << typeid(typ_tpl).name() << endl;

	vector<int>::iterator itr;
	decltype(itr) typ_itr;
	cout << "type of y is " << " " << typeid(typ_itr).name() << endl;

	vector<string>::iterator str;
	decltype(str) typ_str;
	cout << "type of y is " << " " << typeid(typ_str).name() << endl;

	return 0;
}
