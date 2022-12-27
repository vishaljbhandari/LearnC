#include <iostream>
#include <stdio.h>
using namespace std;
#define DEBUG

#define MIN(a,b) (((a)<(b)) ? a : b)

#ifndef CONDITIONAL_H_
#define CONDITIONAL_H_

#ifdef _NUMBER
#  undef _NUMBER
#endif

#ifdef _FOO
#  define _NUMBER 47
#else
#  define _NUMBER 2
#endif

#endif /* CONDITIONAL_H_ */

#include <time.h>

#define COUNT 10

#define GREETING "\nHowdy do!"

// macro definition
#define LIMIT 5

// macro with parameter
#define AREA(l, b) (l * b)

int main() {
	int i, j;

	i = 100;
	j = 30;

#ifdef DEBUG
	cerr << "Trace: Inside main function" << endl;
#endif

#if 0		// Always evaluated to false
			// Equivalent to comment
	/* This is commented part */
	cout << MKSTR(HELLO C++) << endl;
#endif

	cout << "The minimum is " << MIN(i, j) << endl;

#ifdef DEBUG
	cerr << "Trace: Coming out of main function" << endl;
#endif

	printf("Number is %d\n", _NUMBER);

	int a;

	srand((unsigned) time(NULL));
	for (a = 0; a < 10; a++)
		printf("%3d ", rand() % 100 + 1);
	putchar('\n');

	srand((unsigned) time(NULL));
	for (a = 0; a < COUNT; a++)
		printf("%3d ", rand() % 100 + 1);
	putchar('\n');

	for (int i = 0; i < LIMIT; i++) {
		std::cout << i << "\n";
	}

	int l1 = 10, l2 = 5, area;
	area = AREA(l1, l2);
	std::cout << "Area of rectangle is: " << area;

	puts(GREETING);
	return 0;
}
