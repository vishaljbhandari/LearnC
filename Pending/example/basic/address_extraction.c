#include <stdio.h>

int main() {
	char a;
	double b;
	float c;
	int d;

	printf("Address of char variable 'a':\t%p\n", &a);
	printf("Address of double variable 'b':\t%p\n", &b);
	printf("Address of float variable 'c':\t%p\n", &c);
	printf("Address of int variable 'd':\t%p\n", &d);

	int a1, *ptra;

	ptra = &a1;
	printf("Address of a1 = %p\n", &a1);
	printf("Pointer ptra = %p\n", ptra);

	int a2[10], *ptra2;

	ptra2 = a2;
	printf("Address of a2 = %p\n", a2);
	printf("Address of a2 = %p\n", &a2);
	printf("Pointer ptra2 = %p\n", ptra2);

	return (0);
}

