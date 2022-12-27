// gcc -Wall -Wextra -Werror -lm -o strcpy strcpy.cpp -lstdc++
#include <iostream>
#include <string.h>
using namespace std;

// char* strcpy(char* destination, const char* source);

int main() {
	char name[60];
	cout << name << endl;
	cout << strlen(name) << endl;
	cout << strlen("Bilbo ") << endl;
	strcpy(name, "Bilbo ");
	cout << name << endl;
	cout << strlen(name) << endl;

	return 0;
}
