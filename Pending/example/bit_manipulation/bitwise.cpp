// g++ -Wall -Wextra -Werror bitwise.cpp
#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

struct preferences {
	bool likesMusic :1;
	bool hasHair :1;
	bool hasInternet :1;
	bool hasDinosaur :1;
	unsigned int numberOfChildren :4;
};

// unsigned 8-bit to string
const char* u8_to_cstr(const uint8_t &x) {
	static char buf[sizeof(x) * 8 + 1];
	for (char &c : buf)
		c = 0; // reset buffer
	char *bp = buf;
	for (uint8_t bitmask = 0b10000000; bitmask; bitmask >>= 1) {
		*(bp++) = x & bitmask ? '1' : '0';
	}
	return buf;
}

int main() {
	struct preferences homer;
	homer.likesMusic = true;
	homer.hasHair = false;
	homer.hasInternet = true;
	homer.hasDinosaur = false;
	homer.numberOfChildren = 3;

	printf("sizeof int: %ld bits\n", sizeof(int) * 8);
	printf("sizeof homer: %ld bits\n", sizeof(homer) * 8);

	if (homer.likesMusic)
		printf("homer likes music\n");
	if (homer.hasHair)
		printf("homer has hair\n");
	if (homer.hasInternet)
		printf("homer has net\n");
	if (homer.hasDinosaur)
		printf("homer has a dino\n");
	printf("homer has %d children\n", homer.numberOfChildren);

	uint8_t x = 5;
	uint8_t y = 10;
	uint8_t z = x | y;

	printf("x is %s\n", u8_to_cstr(x));
	printf("y is %s\n", u8_to_cstr(y));
	printf("result is %s\n", u8_to_cstr(z));

	int i = 5;
	long int li = 1234567890;
	const char *s = "This is a string.";
	printf("i is %d, li is %ld, s is %s\n", i, li, s);
	return 0;
}
