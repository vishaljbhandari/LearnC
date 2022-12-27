// gcc -lstdc++ -lm pointers.c
#include <stdio.h>

void pointers() {
	int alpha, i;
	int *ptr;

	alpha = 99;
	ptr = &alpha;
	i = *ptr;
	printf("The content of variable alpha is %d\n", alpha);
	printf("The address of variable alpha is %p\n", &alpha);
	printf("The content of memory address %p is %d\n", ptr, *ptr);
	printf("The content of i %d\n", i);
	*ptr = 66;
	printf("The content of variable alpha is %d\n", alpha);
	printf("The content of memory address %p is %d\n", ptr, *ptr);

	printf("Memory address of ptr is %p\n", ptr);
	printf("Memory address of ptr+1 is %p\n", ptr + 1);
	printf("The content of next(+1) memory address %p is %d\n", ptr + 1,
			*ptr + 1);

	float price = 99.98, *fptr;
	fptr = &price;
	printf("The price is $%.2f stored at %p\n", price, fptr);
	*fptr = 99.99;
	printf("The price is $%.2f stored at %p\n", price, fptr);
}

void character_pointers() {
	char a, b, c, *px;

	a = 'A'; /* assign 'A' to variable a */
	px = &a; /* set pointer px to the address of a */
	b = *px; /* assign variable b to the value addressed by pointer px */
	px = &c; /* set pointer px to the address of c */
	*px = 'Z'; /* assign the value addressed by pointer px to 'Z' */

	printf("Character Pointers - %c %c %c\n", a, b, c);

	char *string = "Greetings from the digital realm!";
	while (*string != '\0') {
		putchar(*string);
		string++;
	}
	printf("\n");
	char strings[] = "Greetings from the digital realm!";
	char *s;

	s = strings;
	while (*s) {
		putchar(++*s);
		s++;
	}
	printf("\n");
}

void pointer_arrays() {
	int twos[5] = { 2, 4, 6, 8, 10 };
	int *pt;
	char alpha[] = "abcd";
	char *pa;
	double duos[5] = { 2.2, 4.4, 6.6, 8.8, 10.1 };
	double *dpt;

	pt = twos;
	printf("%p\n", pt);
	printf("%p\n", pt + 1);

	pa = alpha;
	printf("%p\n", pa);
	printf("%p\n", pa + 1);

	dpt = duos;
	printf("%p\n", dpt);
	printf("%p\n", dpt + 1);

	int values[] = { 0xF, 0xFF, 0xFFF, 0xFFFF, 0xFFFFF };
	int *p, x;

	p = values;
	for (x = 0; x < 5; x++) {
		printf("%X\n", *p);
		p++;
	}
}

void pointer_size() {
	char *string = "Greetings from the digital realm!";
	char strings[] = "Greetings from the digital realm!";

	printf("Size of variable storage:\n");
	printf("char\t%lu\n", sizeof(char));
	printf("int\t%lu\n", sizeof(int));
	printf("float\t%lu\n", sizeof(float));
	printf("double\t%lu\n", sizeof(double));
	// printf("char[]\t%lu\n", sizeof(char[]));	// invalid application of ‘sizeof’ to incomplete type ‘char[]’

	printf("Size of pointer variable storage:\n");
	printf("char\t%lu\n", sizeof(char*));
	printf("int\t%lu\n", sizeof(int*));
	printf("float\t%lu\n", sizeof(float*));
	printf("double\t%lu\n", sizeof(double*));
	printf("char* string\t%lu\n", sizeof(string));
	printf("char[] string\t%lu\n", sizeof(strings));
}

int main() {
	pointers();
	character_pointers();
	pointer_size();
	pointer_arrays();
	return 0;
}
