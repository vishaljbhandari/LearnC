#include <stdio.h>

int is_capital_case(int ch) {
	if (ch < 'A' || ch > 'Z')
		return (0);
	else
		return (1);
}

int is_non_capital_case(int ch) {
	if (ch < 'a' || ch > 'z')
		return (0);
	else
		return (1);
}

int main() {
	int c;
	do {
		c = getchar();
		if (is_capital_case(c)) {
			printf("Capital Case : %s\n", (char) c);
		} else if (is_non_capital_case(c)) {
			printf("Non Capital Case : %s\n", (char) c);
		} else {
			printf("Not a alphabet\n", (char) c);
		}
	} while (c != '\n');

	return (0);
}

