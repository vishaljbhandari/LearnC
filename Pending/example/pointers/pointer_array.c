#include <stdio.h>

int main() {

	int f1[5] = { 13, 21, 34, 55, 89 };
	int x1;

	for (x1 = 0; x1 < 5; x1++)
		printf("%d\n", f1[x1]);

	int f2[5] = { 13, 21, 34, 55, 89 };
	int x2;
	int *pf2;

	pf2 = f2;
	for (x2 = 0; x2 < 5; x2++) {
		printf("%d\n", *pf2);
		pf2++;
	}

	int f3[5] = { 13, 21, 34, 55, 89 };
	int x3;
	int *pf3;

	pf3 = f3;
	printf("Base address = %p\n", pf3);
	printf("Size of int = %lu\n", sizeof(int));
	for (x3 = 0; x3 < 5; x3++) {
		printf("%p %d\n", pf3, *pf3);
		pf3++;
	}

	int f[5] = { 13, 21, 34, 55, 89 };
	int x;
	int *pf;

	pf = f;
	for (x = 0; x < 5; x++) {
		printf("%d\n", *(pf + x));
	}

	return (0);
}

