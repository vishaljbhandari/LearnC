#include <stdio.h>

void incshow(char array[]) {	// accepting array in function
	int x;
	for (x = 0; x < 6; x++) {
		array[x]++;
		putchar(array[x]);
	}
}
void incshow_c(char a) {	// Accepting array element in function
	a++;
	putchar(a);
}

int main() {
	int index;

	// Character Array Initialization, As string
	char text[] = "I am a string!";
	puts(text);

	char fixed_size_text[20] = "I am a fixed string!";
	puts(fixed_size_text);

	// warning: initializer-string for array of chars is too long
	char fixed_size_text_less_size[20] = "I am a fixed too long string!";
	puts(fixed_size_text_less_size);

	// Inputing character array
	char input_char_array[10];
	printf("Type something less than 10 character long[Without Space]: ");
	scanf("%9s", input_char_array);
	printf("You typed: %s\n", input_char_array);

	// Inputing character array in same variable
	printf("Type something different and less than 10 character long[Without Space]: ");
	scanf("%9s", input_char_array);
	printf("You typed: %s\n", input_char_array);

	// Inputing longer character array
	printf("Type something more than 10 character long[Without Space]: ");
	scanf("%s", input_char_array);
	printf("You typed: %s\n", input_char_array);

	// Character Array Initialization, As individual characters
	// text[] = { 'H', 'i', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0' };	// Error, this version of re-initialization is not allowed
	// text[10] = { 'H', 'i', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0' };	// Error, version of re-initialization is not allowed
	char string[] = { 'H', 'i', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0' };
	puts(string);


	// Iterate character array using loop
	for (index = 0; text[index] != '\0'; index++) {
		putchar(text[index]);
	}

	// Accessing array elements using subscript
	printf("\nValue at 5th position : %c\n", text[4]);

	// Altering array elements using subscript
	printf("Before: %s\n", text);
	text[0] = 'c';
	printf("After: %s\n", text);

	// Passing array element to function
	for (index = 0; index < 6; index++)
		incshow_c(text[index]);
	putchar('\n');

	// Passing array to function
	incshow(text);
	putchar('\n');

	return 0;
}
