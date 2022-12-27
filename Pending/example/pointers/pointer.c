#include <stdio.h>
#include <math.h>

void exchange(int *a, int *b) {
	int t = *a; /* Assign the value at address a to t */
	*a = *b; /* put b into a */
	*b = t; /* put t into b */
}

struct invent {
	char *name[20];
	int number;
	double price;
};

void main() {
	int x = 10, y, z;
	int *ptr = &x;
	y = *ptr;
	printf("Value of x is %d\n\n", x);
	printf("%d is stored at addr %u\n", x, &x);
	printf("%d is stored at addr %u\n", *&x, &x);
	printf("%d is stored at addr %u\n", *ptr, ptr);
	printf("%d is stored at addr %u\n", y, &*ptr);
	printf("%u is stored at addr %u\n", ptr, &ptr);
	printf("%d is stored at addr %u\n", y, &y);
	*ptr = 25;
	printf("Now x = %d\n", x);

	x = 100;
	y = 200;
	printf("Before exchange  : x = %d   y = %d\n\n", x, y);
	exchange(&x, &y); /* call */
	printf("After exchange   : x = %d   y = %d\n\n", x, y);

	char *name = "DELHI";
	int length;
	char *cptr = name;
	printf("name : %s\n", name);
	while (*cptr != '\0') {
		printf("%c is stored at address %u\n", *cptr, cptr);
		cptr++;
	}
	length = cptr - name;
	printf("\nLength of the string = %d\n", length);

	struct invent product[3], *sptr;
	printf("INPUT---\n");
	for (sptr = product; sptr < product + 3; sptr++) {
		scanf("%s %d %lf", sptr->name, &sptr->number, &sptr->price);
	}
	printf("\nOUTPUT--\n");
	for (sptr = product; sptr < product + 3; sptr++) {
		printf("%-20s %5d %10.2f\n", sptr->name, sptr->number, sptr->price);
	}

	int a = 12, b = 4, *p1, *p2;
	p1 = &a;
	p2 = &b;
	x = *p1 * *p2 - 6;
	y = 4 * -*p2 / *p1 + 10;
	printf("\nAddress of a = %u\n", p1);
	printf("Address of b = %u\n", p2);
	printf("\n");
	printf("a = %d, b = %d\n", a, b);
	printf("x = %d, y = %d\n", x, y);
	*p2 = *p2 + 3;
	*p1 = *p2 - 5;
	z = *p1 * *p2 - 6;
	printf("\na = %d, b = %d,", a, b);
	printf(" z = %d\n", z);

	int *pointer, i = 0, sum = 0;
	int arr[5] = { 5, 9, 6, 3, 7 };
	pointer = arr; /* initializing with base address of x */
	printf("Element   Value   Address\n\n");
	while (i < 5) {
		printf("arr[%d]       %d       %u\n", i, *pointer, pointer);
		sum = sum + *pointer; /* accessing array element  */
		i++, pointer++; /* incrementing pointer     */
	}
	printf("\nSum    =  %d\n", sum);
	printf("\n&x[0]  =  %u\n", &arr[0]);
	printf("\np      =  %u\n", pointer);
}
