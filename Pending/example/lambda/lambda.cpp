#include <cstdio>
#include <locale>
#include <typeinfo>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;

/*
 C++ 11 introduced lambda expression to allow us write an inline function which can be used for short snippet of code
 that are not going to be reuse and not worth naming.

 [ capture clause ] (parameters) -> return-type {
 definition of method
 }

 Generally return-type in lambda expression are evaluated by compiler itself
 and we don’t need to specify that explicitly and -> return-type part can be ignored
 but in some complex case as in conditional statement, compiler can’t make out the return type and we need to specify that.
 Various uses of lambda expression with standard function are given below

 A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope.
 We can capture external variables from enclosing scope by three ways :
 Capture by reference
 Capture by value
 Capture by both (mixed capture)

 Syntax used for capturing variables :
 [&] : capture all external variable by reference
 [=] : capture all external variable by value
 [a, &b] : capture a by value and b by reference

 A lambda with empty capture clause [ ] can access only those variable which are local to it.

 */

constexpr size_t _maxlen = 128;

class fupper {
	char lastc;
public:
	fupper() :
			lastc(0) {
	}
	char operator()(char c) {
		if (lastc == ' ' || lastc == 0) {
			lastc = c;
			return toupper(c);
		} else {
			lastc = c;
			return tolower(c);
		}
	}
};

class ftitle {
	char lastc;
public:
	ftitle() :
			lastc(0) {
	}
	char operator()(const char &c) {
		const char r = (lastc == ' ' || lastc == 0) ? toupper(c) : tolower(c);
		lastc = c;
		return r;
	}
};

int main() {
	char cstr[] = "big light in sky slated to appear in east";
	transform(cstr, cstr + strnlen(cstr, _maxlen), cstr, ftitle());
	puts(cstr);

	char lastc = 0;
	transform(cstr, cstr + strnlen(cstr, _maxlen), cstr,
			[&lastc](const char &c) -> char {
				const char r =
						(lastc == ' ' || lastc == 0) ? toupper(c) : tolower(c);
				lastc = c;
				return r;
			});
	puts(cstr);

	string str(cstr);
	transform(str.begin(), str.end(), str.begin(), fupper());
	cout << str << endl;

	return 0;
}
