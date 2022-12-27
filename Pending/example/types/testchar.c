#include <stdio.h>
#include <ctype.h>

void isalpha_check() {
	char ch, string[] = "Nifty TEXT! 123\n";
	int x;

	for (x = 0; (ch = string[x]) != '\0'; x++) {
		if (isalpha(ch))
			putchar('_');
		else
			putchar(ch);
	}
}

void isdigit_check() {
	char ch, string[] = "Nifty TEXT! 123\n";
	int x;

	for (x = 0; (ch = string[x]) != '\0'; x++) {
		if (isdigit(ch))
			putchar('_');
		else
			putchar(ch);
	}
}

void isupper_check() {
	char ch, string[] = "Nifty TEXT! 123\n";
	int x;

	for (x = 0; (ch = string[x]) != '\0'; x++) {
		if (isupper(ch))
			putchar('_');
		else
			putchar(ch);
	}
}

void islower_check() {
	char ch, string[] = "Nifty TEXT! 123\n";
	int x;

	for (x = 0; (ch = string[x]) != '\0'; x++) {
		if (islower(ch))
			putchar('_');
		else
			putchar(ch);
	}
}

void to_upper() {
	char ch, string[] = "stop shouting at me!\n";
	int x;

	for (x = 0; (ch = string[x]) != '\0'; x++) {
		putchar(toupper(ch));
	}
}

void main() {
	to_upper();

	isalpha_check();
	isdigit_check();
	isupper_check();
	islower_check();
}
