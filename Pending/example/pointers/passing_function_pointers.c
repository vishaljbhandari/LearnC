// gcc -lm passing_function_pointers.c
#include <stdio.h>
#include  <math.h>

#define  PI  3.1415926

double y(double);
double cos(double);
void table(double (*f)(), double, double, double);

int main() {
	printf("Table of y(x) = 2*x*x-x+1\n\n");
	table(y, 0.0, 2.0, 0.5);
	printf("\nTable of cos(x)\n\n");
	table(cos, 0.0, PI, 0.5);
	return 0;
}

void table(double (*f)(), double min, double max, double step) {
	double a, value;
	for (a = min; a <= max; a += step) {
		value = (*f)(a);
		printf("%5.2f  %10.4f\n", a, value);
	}
}

double y(double x) {
	return (2 * x * x - x + 1);
}
