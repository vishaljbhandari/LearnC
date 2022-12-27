#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL 100000000.0

int random_scale(int scale) {
	int x, random = 0;

	for (x = 0; x < scale; x++) {
		random = rand() % scale;
	}
	return random;
}

int random_seed(int scale, unsigned seed) {
	int x, random = 0;
	if (seed == 0) {
		srand((unsigned) time(NULL));
	} else {
		srand(seed);
	}
	for (x = 0; x < scale; x++) {
		random = rand() % scale + 1;
	}
	return random;
}

int randomizer(u_int32_t SEED) {
	u_int32_t random;
	srand(time(0));
	u_int32_t hits = 0;
	while (SEED--) {
		random = rand() % 1000 + 1;
		if (random <= 500)
			hits++;
	}
	return (int) random;
}

float normalizer(u_int32_t SEED) {
	u_int32_t random;
	srand(time(0));
	u_int32_t hits = 0;
	while (SEED--) {
		random = rand() % 1000 + 1;
		if (random <= 500)
			hits++;
	}
	return hits / TOTAL;
}

int main() {
	printf("Random 10 => %d\n", random_scale(10));
	printf("Random 100 => %4d\n", random_scale(100));

	printf("Random Seed 100, 100 => %4d\n", random_seed(100, 100));
	printf("Random Seed 100, 0 => %4d\n", random_seed(100, 0));

	printf("Randomizer => %4d\n", randomizer(TOTAL));
	printf("Randomizer => %f\n", normalizer(TOTAL));

	return 0;
}
