/*

 It compares the first count characters of the arrays pointed to by buf1 and buf2.
 Syntax:

 int memcmp(const void *buf1, const void *buf2, size_t count);

 Return Value: it returns an integer.
 Parameters:
 buf1 : Pointer to block of memory.
 buf2 : Pointer to block of memory.
 count : Maximum numbers of bytes to compare.
 Return Value is interpreted as :
 Value                                Meaning
 Less than zero                       buf1 is less than buf2.
 Zero                                 buf1 is equal to buf2.
 Greater than zero                    buf1 is greater than buf2.

 */

// gcc -Wall -Wextra -Werror -lstdc++ memcmp.cpp

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char buff1[] = "Welcome to GeeksforGeeks";
	char buff2[] = "Hello Geeks ";

	int a = memcmp(buff1, buff2, sizeof(buff1));

	if (a > 0)
		cout << buff1 << " is greater than " << buff2;
	else if (a < 0)
		cout << buff1 << "is less than " << buff2;
	else
		cout << buff1 << " is the same as " << buff2;

	// Lets extract remaining string of buff2
	cout << endl << buff1 + sizeof(buff2) + 1 << endl;
	return 0;
}
