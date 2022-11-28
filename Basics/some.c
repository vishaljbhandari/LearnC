# include <stdio.h>

void InputOutput() {
	// int variable declaration
	int artifacts;		// single variable declaration
	int rooms, paintings, sculptures;	// multiple variable declaration
	printf("This museum has %d artifacts\n", artifacts);
	// variable initialization
	rooms = 12;
	paintings = 16;
	sculptures = 4;
	artifacts = rooms * (paintings + sculptures);
	printf("This museum has %d artifacts\n", artifacts);

	float x, p;		// float
	double y, q;	// double
	unsigned k;		// unsigned // default int
	int m = 54321;	// declaration with initialization
	long int n = 1234567890;
	x = 1.234567890000;
	y = 9.87654321;
	k = 54321;
	p = q = 1.0;
	// printing variables
	printf("m = %d\n", m);
	printf("n = %ld\n", n);
	printf("x = %.12lf\n", x);
	printf("x = %f\n", x);
	printf("y = %.12lf\n", y);
	printf("y = %lf\n", y);
	printf("k = %u  p = %f  q = %.12lf\n\n", k, p, q);

	char a;
	int b;
	float c;
	double d;
	a = 'A';
	b = 2;
	c = 0.25;
	d = 2.5e6;
	printf("a is %c\n", a);
	printf("b is %d\n", b);
	printf("c = %.12lf\n", c);
	printf("c = %f\n", c);
	printf("d is %f\n", d);
	d = 2500000.0;
	printf("d is %f\n", d);
	printf("d = %.12lf\n", d);

	char ca, cb, cc, cd, ce;
	ca = 'H';
	cb = 'e';
	cc = 'l';
	cd = 'o';
	ce = '\n';
	printf("%c%c%c%c%c%c", ca, cb, cc, cc, cd, ce);

	float unknown;
	// printf("The value of %f is unknown\n", unknown);// use before initialization of variable	// ERROR

	// printing memory location
	puts("Memory locations\n");
	printf("A is at %p\n", &a);
	printf("B is at %p\n", &b);
	printf("C is at %p\n", &c);

	char cx, cy, cz;
	cx = 'A';
	cy = 'B';
	cz = 'C';
	printf("It's as easy as %c%c%c\n", cx, cy, cz);

	int alpha;		// Declaration
	alpha = 27;		// Initialization
	int beta = 25;	// Declaration & Initialization
	printf("Integer variable alpha holds the value %d\n", alpha);
	printf("Variable alpha occupies %lu bytes of storage\n", sizeof(alpha));
	printf("And it sits at address %p\n", &alpha);

	float pi = 22.00 / 7.0;
	printf("The ancients calculated PI as %f.\n", pi);

	// size of variables
	int ia = 5;
	printf("The value of ia is %d\n", ia);
	printf("An int variable occupies %lu bytes of storage\n", sizeof(ia));
	char ch_a;
	short sh_b;
	int int_c;
	long lng_d;
	float flt_e;
	double dbl_f;
	printf("A char variable occupies %lu bytes of storage\n", sizeof(ch_a));
	printf("A short variable occupies %lu bytes of storage\n", sizeof(sh_b));
	printf("An int variable occupies %lu bytes of storage\n", sizeof(int_c));
	printf("A long variable occupies %lu bytes of storage\n", sizeof(lng_d));
	printf("A float variable occupies %lu bytes of storage\n", sizeof(flt_e));
	printf("A double variable occupies %lu bytes of storage\n", sizeof(dbl_f));

	char string[] = "Hello!";
	int buffer[10];
	printf("string array 'string' uses %lu bytes\n", sizeof(string));
	printf("int buffer 'buffer' uses %lu bytes\n", sizeof(buffer));

	// structure variable
	struct stuff {
		int a;
		float b;
		char c[32];
	};
	printf("The structure 'stuff' occupies %lu bytes of storage\n",
		sizeof(struct stuff));

}
