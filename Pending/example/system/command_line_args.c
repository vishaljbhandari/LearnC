#include <stdio.h>

int main(int argc, char **argv) {
	printf("There were %d command line arguments\n", argc);
	printf("This program is named %s\n", argv[0]);

	int x;

	if (argc < 2)
		puts("No extra arguments found");
	else {
		for (x = 1; x < argc; x++)
			printf("Argument %d is %s\n", x, argv[x]);		// accessing using subscript way
	}

	int x1;

	if (argc < 2)
		puts("No extra arguments found");
	else {
		for (x1 = 1; x1 < argc; x1++)
			printf("Argument %d is %s\n", x1, *(argv + x1));		// accessing using pointer arithmetic way
	}

	return (0);
}
