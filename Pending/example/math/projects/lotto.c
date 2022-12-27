#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 51
#define BALLS 6

int main() {
	int lottoball[COUNT];
	int x, draw, b;

	srand((unsigned) time(NULL));
	for (x = 0; x < COUNT; x++)
		lottoball[x] = 0;

	draw = 0;
	while (draw < BALLS) {
		b = rand() % COUNT;
		if (lottoball[b] == 0) {
			lottoball[b] = 1;
			draw++;
		}
	}

	puts("Winning Lotto Numbers:");
	for (x = 0; x < COUNT; x++) {
		if (lottoball[x] == 1) {
			printf("%3d", x + 1);
		}
	}
	putchar('\n');

	return (0);
}

