#include <stdio.h>

void arrays() {
	int x, array[] = { 11, 13, 17, 19, 25 };
	char *veeps[5] = { "Adams", "Jefferson", "Burr", "Clinton", "Gerry" };

	for (x = 0; x < 5; x++) {
		printf("Element %d: %d\n", x + 1, array[x]);
	}

	for (x = 0; x < 5; x++)
		printf("%s\n", veeps[x]);
}

void array_pointer_arithmatics() {
	int x, *aptr, array[] = { 11, 13, 17, 19, 25, 47, 36 };

	aptr = array; /* no & needed for an array */

	printf("Address of array = %p\n", array);
	printf("Address of aptr = %p\n", aptr);
	printf("First element is %d\n", *aptr);
	printf("5th element is %d\n", *aptr + 5);
	printf("First element plus 5 is %d\n", (*aptr) + 5);

	for (x = 0; x < 7; x++) {
		printf("Element %d: %d\n", x + 1, *aptr);
		aptr++;
	}

	int *pt, twos[5] = { 2, 4, 6, 8, 10 };
	pt = twos;

	for (x = 0; x < 5; x++) {
		printf("%p = %p\n", pt + x, &twos[x]);
	}

	printf("%d\n", twos[0]);
	printf("%d\n", twos[1]);
	printf("%d\n", twos[2]);
	printf("%d\n", twos[3]);
	printf("%d\n", twos[4]);

	printf("%d\n", *(pt + 0));
	printf("%d\n", *(pt + 1));
	printf("%d\n", *(pt + 2));
	printf("%d\n", *(pt + 3));
	printf("%d\n", *(pt + 4));

}

void array_pointer_arithmatics_dereferanced() {
	char *veeps[5] = { "Adams", "Jefferson", "Burr", "Clinton", "Gerry" };
	int x;

	for (x = 0; x < 5; x++)
		printf("%s\n", *(veeps + x));
	for (x = 0; x < 5; x++)
		printf("%c\n", **(veeps + x));
	for (x = 0; x < 5; x++)
		printf("%c\n", *(*(veeps + x) + 1));
}

int main() {
	arrays();
	array_pointer_arithmatics();
	array_pointer_arithmatics_dereferanced();
	return (0);
}
