#include <stdio.h>

int main() {
	int a, b;
	for (a = 0; a < 2; a++)
		puts("I must do this 2 times"); // by default only one line is conditional to loop statement
	// if loop has only one statement line then there is no need of braces

	for (a = 0; a < 2; a++) {
		puts("I must do this 2 times");
	}
	// braces are added to block multiple statements and imcrease readability

	// adding multiple loop control variables

	for (a = 1, b = 10; a <= 2; a++, b--) {
		printf("Hello\n");
	}

	// Characters with loop
	for (b = 0; b < a; b++)
		putchar('-');
	putchar('\n');

	// below are infinite loops
	/*
	 for (;;) {
	 printf("This loop will run forever.\n");
	 }

	 while (1) {
	 printf("This loop will run forever.\n");
	 }

	 do {
	 printf("This loop will run forever.\n");
	 } while (1);
	 */

	// infinite loops with break statement
	while (1) {
		puts("Here I go...!");
		a++;
		if (a > 10)
			break;
	}

	// entry control while loops
	// count up loop
	a = 0;
	while (a < 10) {
		puts("I must do this 10 times");
		a++;
	}

	// count down loop

	a = 10;
	while (a >= 0) {
		printf("Countdown: %d!\n", a);
		a--;
	}

	// exit control do while loop
	a = 10;
	do {
		puts("Here we go!");
		a--;
	} while (a > 0);

	b = 0;
	while (b < a) {
		putchar('-');
		b++;
	}
	putchar('\n');

	// for loop with break statement
	b = 15;
	for (a = 0; a < b; a++) {
		printf("I must do this %d times\n", b);
		if (a == 9)
			break;
	}

	int row;
	char column;
	// nested for loop
	for (row = 1; row <= 10; row++) {
		for (column = 'A'; column <= 'J'; column++) {
			printf("%2d%c   ", row, column);
		}
		putchar('\n');
	}

	// nested while loop
	row = 1;
	while (row <= 10) {
		column = 'A';
		while (column <= 'J') {
			printf("%2d%c   ", row, column);
			column++;
		}
		putchar('\n');
		row++;
	}

	for (a = 1, b = 10; a <= 10; a++, b--)
		printf("%2d %2d\n", a, b);

	b = 10;
	for (a = 1; a < 10; a++) {
		printf("%2d %2d\n", a, b);
		b--;
	}

	b = 10;
	a = 1;
	for (; a < 10;) {
		printf("%2d %2d\n", a, b);
		b--;
		a++;
	}

	int ich;
	puts("Type 0 to end:");
	while (1) {
		ich = getchar();
		if (ich == '0')
			break;
		putchar(ich);
	}

	a = 0;
	while (1) {
		a++;
		printf("%d\n", a);
		if (a < 10)
			continue;
		a++;
		if (a > 20)
			break;
	}

	char ch = 'A';
	do {
		putchar(ch);
		ch++;
	} while (ch != 'Z');
	putchar('\n');

	for (a = 1; a <= 20; a++)
		printf("%d\n", a);

	b = -10;
	while (b <= 10) {
		printf("%d\n", b);
		b = b + 2;
	}

	// continue statement
	for (int j = 0; j <= 8; j++) {
		if (j == 4) {
			/* The continue statement is encountered when
			 * the value of j is equal to 4.
			 */
			continue;
		}
		/* This print statement would not execute for the
		 * loop iteration where j ==4  because in that case
		 * this statement would be skipped.
		 */
		printf("%d ", j);
	}

}
