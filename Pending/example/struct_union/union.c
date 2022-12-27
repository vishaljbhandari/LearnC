#include <stdio.h>

void union_use() {
	union storage {
		char a;
		int b;
	} reg;

	reg.a = 'A';
	printf("reg.a stores %c\n", reg.a);

	reg.b = 1346;
	printf("reg.b stores %d\n", reg.b);
}

void union_use_share() {
	union storage {
		char a;
		int b;
	} reg;

	reg.a = 'A';
	printf("reg.a stores %c\n", reg.a);

	reg.b = 1346;
	printf("reg.b stores %d\n", reg.b);
	printf("reg.a stores %c\n", reg.a);
}

int main() {
	union_use();
	union_use_share();
	return (0);
}
