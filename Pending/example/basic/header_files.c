#include "header_files.h"
// MAX, SIZE and data are defined in the header file

int main() {
	struct data stuff[SIZE];
	int x;

	/* seed randomizer */
	srand((unsigned) time(NULL));

	for (x = 0; x < SIZE; x++) {
		stuff[x].a = rand() % MAX + 1;
		stuff[x].b = rand() % 26 + 'A';
	}

	for (x = 0; x < SIZE; x++) {
		printf("%d\n", stuff[x].a);
		printf("%d\n", stuff[x].b);
	}

	return (0);
}
