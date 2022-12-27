// gcc -Wall -Wextra -Werror -lstdc++ -lm typecast_string.cpp
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

class cString {
private:
	char *str;
	int len;
public:
	cString(char const *st) {		// it should receive as  const char pointer
		len = strlen(st);
		str = new char[len + 1];
		strcpy(str, st);
		cout << str << endl;
		cout << "Implicit type conversion with parameterized constructor"
				<< endl;
	}
	operator char *() {
		cout << "Type conversion function called" << endl;
		return str;
	}
};

int main() {
	char *p;
	cString cs("SANJEET"); //Basic string To string Class;
	// with signature cString(char *st), it is not allowed as ISO C++ forbids converting a string constant to ‘char*’
	p = (char*) cs;
	cout << p << endl;
	return 0;
}
