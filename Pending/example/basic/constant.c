#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEMS 10
#define greetings1 "Constant Expression"

#define INPUT_MAX 16

int main() {
	// to make any variable constant, just place const keyword before that declaration
	const int xx = 5;
	const float fl = 5.4;
	const char* ctr = NULL;
	const char *ctrString = "Hello";
	char input[INPUT_MAX];

	printf("%d squared is %d\n", xx, xx * xx);
	// xx = 10;	// not allowed to modify
	printf("%d squared is %d\n", xx, xx * xx);

	printf("Instructions: ");
	fgets(input, INPUT_MAX, stdin);
	puts("Thank you! Here are your instructions:");
	puts(input);

	putchar('H');
	putchar('e');
	putchar('l');
	putchar('l');
	putchar('o');
	putchar('\n');

	int a = 4 + 5;
	printf("4 + 5 = %d\n", a);
	const char greetings[] = "String literal";

	puts(greetings);
	puts(greetings1);

	int x, r[5];

	srand((unsigned) time(NULL));

	for (x = 0; x < 5; x++)
		r[x] = rand() % 10 + 1;

	printf("Here are your %d random values:\n", 5);
	for (x = 0; x < 5; x++)
		printf("%3d\n", r[x]);

	const int n = 5;
	int r1[n];

	srand((unsigned) time(NULL));

	for (x = 0; x < n; x++)
		r1[x] = rand() % 10 + 1;

	printf("Here are your %d random values:\n", n);
	for (x = 0; x < n; x++)
		printf("%3d\n", r1[x]);

	int r2[ITEMS];

	srand((unsigned) time(NULL));

	for (x = 0; x < ITEMS; x++)
		r2[x] = rand() % 10 + 1;

	printf("Here are your %d random values:\n", ITEMS);
	for (x = 0; x < ITEMS; x++)
		printf("%3d\n", r2[x]);

	const char b = 'Z';

	a = 16;
	printf("Here is the value of A: %d\n", a);
	printf("Here is the value of B: %c\n", b);

	a = 16;
	char cb = 'Z';

	printf("Here is the value of A: %d\n", a);
	printf("Here is the value of cb: %c\n", cb);

	return (0);
}

