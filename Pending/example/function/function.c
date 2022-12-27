# include <stdio.h>

int mul(int x, int y) {
	int p;
	p = x * y;
	return (p);
}

int multiplication() {
	int a, b, c;
	a = 5;
	b = 10;
	c = mul(a, b);
	printf("multiplication of %d and %d is %d", a, b, c);
}

double power(int x, int y) {
	double p;
	p = 1.0; /* x to power zero */

	if (y >= 0)
		while (y--) /* computes positive powers */
			p *= x;
	else
		while (y++) /* computes negative powers */
			p /= x;
	return (p); /* returns double type */

}

void return_double() {
	int x = 5, y = 6; /*input data */

	printf("%d to power %d is %f\n", x, y, power(x, y));
}

void printline(char ch, int len);
int value(float, float, int);

void printline(char ch, int len) {
	int i;
	for (i = 1; i <= len; i++)
		printf("%c", ch);
	printf("\n");
}
int value(float p, float r, int n) /* default return type */
{
	int year;
	float sum;
	sum = p;
	year = 1;
	while (year <= n) {
		sum = sum * (1 + r);
		year = year + 1;
	}
	return (sum); /* returns int part of sum */
}

int main() {
	multiplication();
	return_double();
	printf("%d\n", value(1.5, 5.6, 8));
	printline('t', 12);
	return 0;
}
