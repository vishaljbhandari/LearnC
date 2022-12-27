// gcc -Wall -Wextra -Werror -lstdc++ nullptr.cpp
#include <cstdio>
#include<iostream>
using namespace std;

//#ifndef NULL
//#define NULL 0 /* standard C++ definition */
//#endif

#ifndef NULL
#define NULL (0LL) /* common C++ definition */
#endif

void f(int i) {
	printf("the int is %d\n", i);
}

void f(const char *s) {
	printf("the pointer is %p\n", s);
}

int main() {
	// f(NULL);	// error: call of overloaded 'fun(NULL)' is ambiguous
	// NULL is typically defined as (void *)0 and conversion of NULL to integral types is allowed.
	// So the function call fun(NULL) becomes ambiguous.

	int *ptr = nullptr;
	if (ptr) {
		cout << "true";
	} else {
		cout << "false";
	}

	cout << endl << "-----------------" << endl;
	int *iptr1;		// uninitialized pointer
	cout << iptr1 << endl; // this will give error in different compilers, as uninitialized pointers can not be used/read/accessed any where. if not error then it will give absurd results.

	int *iptr2 = nullptr;
	cout << iptr2 << endl; // this will also give error, as it is trying to read null pointer	// read access violation, if not then it will give zero value ( depends on compiler

	int *iptr3 = nullptr;
	*iptr3 = 7;	// this will give error, as it is trying to write into a null pointer // write access violation // as there is not address so cant write anything.

	return 0;
}
