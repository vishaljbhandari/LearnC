#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	char *fruit[10], buffer[32];
	int x;

	for (x = 0; x < 10; x++) {
		/* read the string to get its length */
		printf("Enter fruit #%d: ", x + 1);
		fgets(buffer, 32, stdin);

		/* allocate memory based on the string size */
		fruit[x] = (char*) malloc(strlen(buffer) + 1);
		if (fruit[x] == NULL) {
			puts("Memory allocation failed");
			exit(1);
		}

		/* copy the string's address */
		strcpy(fruit[x], buffer);
	}

	/* display the strings */
	for (x = 0; x < 10; x++) {
		printf("%s", fruit[x]);
		puts(fruit[x]);
	}

	return (0);
}

