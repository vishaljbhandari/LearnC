#include <stdio.h>

char* binString(unsigned short n) {
	static char bin[17];
	int x;
	for (x = 0; x < 16; x++) {
		bin[x] = n & 0x8000 ? '1' : '0';
		n <<= 1;
	}
	bin[16] = '\0';

	return (bin);
}

void main() {
	unsigned short a, b, c, d, e, f, g;
	a = 0xAAAA;
	b = 0x00FF;

	printf("%04X - %s\n", a, binString(a));
	printf("%04X - %s\n", b, binString(b));
	c = a & b;
	printf("  a & b : %04X - %s\n", c, binString(c));
	d = a | b;
	printf("  a | b : %04X - %s\n", d, binString(d));
	e = a ^ b;
	printf("  a ^ b : %04X - %s\n", c, binString(e));
	f = ~a;
	printf("  ~a    : %04X - %s\n", b, binString(f));

	int x;

	a = 0x0003;
	for (x = 0; x < 16; x++) {
		printf("%04X - %s\n", a, binString(a));
		a = a << 1;
	}

	int k = 1;
	while (k < 33000) {
		printf("%d\n", k);
		k = k << 1;
	}

	int l = 1000000;
	while (l > 0) {
		printf("%d\n", l);
		l = l >> 1;
	}
}
