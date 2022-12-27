#include <iostream>
#include <stdint.h>
using namespace std;

union ipv4A {
	struct {
		uint8_t a;
		uint8_t b;
		uint8_t c;
		uint8_t d;
	} bytes;
	uint32_t int32;
};

union ipv4B {
	uint32_t i32;
	struct {
		uint8_t a;
		uint8_t b;
		uint8_t c;
		uint8_t d;
	} octets;
};

int main() {
	union ipv4A addr1;
	addr1.bytes = { 192, 168, 0, 96 };
	printf("%d.%d.%d.%d - (%08x)\n", addr1.bytes.a, addr1.bytes.b,
			addr1.bytes.c, addr1.bytes.d, addr1.int32);

	union ipv4B addr2;
	addr2.octets = { 192, 168, 73, 42 };
	printf("addr is %d.%d.%d.%d is %08x\n", addr2.octets.a, addr2.octets.b,
			addr2.octets.c, addr2.octets.d, addr2.i32);
	return 0;
}
