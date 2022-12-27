#include <stdio.h>

int main() {
	int a;
	printf("Type a value: ");
	scanf("%d", &a);
	if (a < 10) {
		puts("You typed a value less than 10");
	}
	puts("Thank you");

	if (a < 10) {
		puts("You typed a value less than 10");
		a -= 5;
		printf("The value is now %d\n", a);
	}
	puts("Thank you");

	a = 1;
	// if in while loop
	while (a <= 7) {
		if (a == 5)
			break;
		a++;
	}

	// if else
	int b = 1;
	printf("Enter value 1: ");
	scanf("%d", &a);
	printf("Enter value 2: ");
	scanf("%d", &b);
	if (a > b)
		printf("%d is greater than %d\n", a, b);
	else
		printf("%d is greater than %d\n", b, a);

	// if else if else
	printf("Enter value 1: ");
	scanf("%d", &a);
	printf("Enter value 2: ");
	scanf("%d", &b);
	if (a > b)
		printf("%d is greater than %d\n", a, b);
	else if (b > a)
		printf("%d is greater than %d\n", b, a);
	else
		printf("%d is equal to %d\n", a, b);

	// if else if else if .. else ladder
	char ch;
	printf("Type a character: ");
	scanf("%c", &ch);
	if (ch >= 'a' && ch <= 'z')
		puts("You typed a lowercase letter");
	else if (ch >= 'A' && ch <= 'Z')
		puts("You typed an uppercase letter");
	else if (ch >= '0' && ch <= '9')
		puts("You typed a number");
	else if (ch == ' ')
		puts("You typed a space");
	else
		printf("You typed the %c symbol\n", ch);

	// if with equality
	printf("Select item 1, 2, or 3: ");
	scanf("%d", &a);
	if (a == 1)
		puts("This is the first item");
	else if (a == 2)
		puts("This is the second item");
	else if (a == 3)
		puts("This is the third item");
	else
		puts("Invalid choice!");

	// single line if statement, without braces
	a = 5;
	if (a < 10)
		printf("inside if - %d is greater than 10.\n", a); // this line is conditional
	printf("outside if\n");		// this line is not conditional, outside of if

	// if block, with multiple lines
	b = 6;
	if (b < 10) {
		printf("You typed %d.\n", b);
		printf("%d is greater than 10.\n", b);
	}

	// nested if else
	b = 6;
	if (b < 10) {
		a = 7;
		if (a < 10) {
			printf("a is less than 10 : %d.\n", a);
		}
		printf("You typed %d.\n", b);
		printf("%d is greater than 10.\n", b);
	}

	return 0;
}
