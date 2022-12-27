#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void minus10(int *v) {
	*v = *v - 10;
}

char* encrypt(char *input) {
	char *output = (char*) malloc((strlen(input) + 1) * sizeof(char));
	int x = 0;

	while (*input) {
		if (isalpha(*input))
			output[x] = *input + 1;
		else
			output[x] = *input;
		x++;
		input++;
	}

	return (output);
}

char* longer(char *s1, char *s2) {
	if (strlen(s1) > strlen(s2))
		return (s1);
	else
		return (s2);
}

void shouting(char *input) {
	while (*input) {
		*input = toupper(*input);
		input++;
	}
}

int main() {
	// pass by pointer and return new value by pointer
	char *instructions = "Deliver the package to Berlin";
	puts("Original String");
	puts(instructions);
	puts("Encrypted String");
	printf("%s\n", encrypt(instructions));

	// pass by pointer and modify in function body
	int value = 100;
	printf("Value is %d\n", value);
	minus10(&value);
	printf("Value is %d\n", value);

	// pass by char array and return by char array
	char string1[] = "Constantinople";
	char string2[] = "Byzantium";
	char *result;
	result = longer(string1, string2);
	printf("String '%s' is longer.\n", result);

	char string[64];
	printf("Type some text: ");
	fgets(string, 64, stdin);
	printf("You typed:\n%s\n", string);
	shouting(string);
	printf("If you were shouting, you'd type:\n%s\n", string);

	return (0);
}
