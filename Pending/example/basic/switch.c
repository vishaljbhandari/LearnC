#include <stdio.h>
#include<stdlib.h>

int main() {
	int input;
	printf("Type a value (1,2,3): ");
	scanf("%d", &input);
	// switch case with integer
	switch (input) {
	case 1:
		puts("Red");
		break;
	case 2:
		puts("Green");
		break;
	case 3:
		puts("Blue");
		break;
	default:
		puts("Invalid input");
	}
	fflush(stdin);	// to clear standard input buffer

	char a = 'A';
	// switch case with characters
	switch (a) {
	case 'A':
		puts("Excellent choice!");
		break;
	case 'B':
		puts("This is the most common choice.");
		break;
	case 'C':
		puts("I question your decision.");
		break;
	default:
		puts("That's not a valid choice.");
	}

	// without break statement
	switch (a) {
	case 'A':
		puts("Excellent choice!");
	case 'B':
		puts("This is the most common choice.");
	case 'C':
		puts("I question your decision.");
	default:
		puts("That's not a valid choice.");
	}
	// all cases will be printed

	// without break statement
	a = 'B';
	switch (a) {
	case 'A':
		puts("Excellent choice!");
	case 'B':
		puts("This is the most common choice.");
	case 'C':
		puts("I question your decision.");
	default:
		puts("That's not a valid choice.");
	}
	// control will enter from case 'B' and all following cases will be printed

	// entry into switch block with default case
	a = 'Z';
	switch (a) {
	case 'A':
		puts("Excellent choice!");
	default:
		puts("That's not a valid choice.");
	case 'B':
		puts("This is the most common choice.");
	case 'C':
		puts("I question your decision.");
	}
	// no matching case so default case will be executed
	// control will enter from default case and all following cases will be printed

	return 0;
}
