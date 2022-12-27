#include <stdio.h>
#include <ctype.h>

void char_check(char acter) {
	if (isalpha(acter))
		printf("Alpha [%c]\n", acter);
	else if (isdigit(acter))
		printf("Digit [%c]\n", acter);
	else
		printf("Other [%c]\n", acter);
}

// void char_check() // c is not having function overloading
void char_test() {
	char acter = getchar();
	if (isalpha(acter))
		putchar(acter);
	else if (isdigit(acter))
		putchar(acter);
	else
		putchar('0');
}

void int_as_char() {
	int ch = 'a';

	printf("Int as char printing\n");
	printf("Original %c\n", ch);
	printf("Lowercase %c\n", tolower(ch));		// Lower Conversion
	printf("Uppercase %c\n", toupper(ch));		// Upper Conversion
	printf("Original %c\n", ch);
}

void char_as_char() {
	char ch = 'a';

	printf("Char as char printing\n");
	printf("Original %c\n", ch);
	printf("Lowercase %c\n", tolower(ch));		// Lower Conversion
	printf("Uppercase %c\n", toupper(ch));		// Upper Conversion
	printf("Original %c\n", ch);

	printf("Char as int printing\n");
	printf("Original %d\n", ch);
	printf("Lowercase %d\n", tolower(ch));		// Lower Conversion
	printf("Uppercase %d\n", toupper(ch));		// Upper Conversion
	printf("Original %d\n", ch);
}

int main() {
	int_as_char();
	char_as_char();

	char_check('a');
	char_check('A');
	char_check('#');
	char_check('5');
	char_check('0');
	return 0;
}
