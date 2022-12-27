// gcc -Wall -Wextra -Werror -lm -o strcat strcat.cpp -lstdc++
#include <iostream>
#include <string.h>
using namespace std;

// char *strcat(char *destination, const char *source)

int main() {
	char name[60];
	cout << name << endl;
	cout << strlen(name) << endl;
	cout << strlen("Baggins") << endl;
	strcat(name, "Baggins");
	cout << name << endl;
	cout << strlen(name) << endl;
	return 0;
}
