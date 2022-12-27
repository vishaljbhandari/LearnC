// gcc -Wall -Wextra -Werror -lm -o character_array character_array.cpp -lstdc++
// Link with shared libraries(stdc++) using -l option

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Character sequences
// Character Array

int main() {
	char myword[4];
	myword[0] = 'B';
	myword[1] = 'y';
	myword[2] = 'e';
	myword[3] = '\0';

	char myword1[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << strlen(myword1) << endl;

	char myword2[] = "Hello";
	cout << strlen(myword2) << endl;

	/*
	 char myword3[4];
	 myword3 = "Bye";
	 */		// this is not allowed as for
	char myword4[] = "Bye";
	cout << strlen(myword4) << endl;

	cout << myword << endl;
	cout << myword1 << endl;
	cout << myword2 << endl;
	cout << myword4 << endl;

	char myntcs[] = "some text";
	cout << myntcs << endl;          	// printed as a library string
	std::string mystring = myntcs;  	// convert c-string to string
	cout << mystring << endl;          	// printed as a library string
	cout << mystring.c_str() << endl;  	// printed as a c-string

	char cstr[] = "String";
	cout << cstr << endl;
	printf("The string is: %s\n", cstr);
	for (unsigned int i = 0; cstr[i]; i++) {
		printf("%02d: %c\n", i, cstr[i]);
	}

	return 0;
}
