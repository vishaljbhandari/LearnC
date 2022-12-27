// gcc -lm maths.c
#include<stdio.h>
#include<math.h>

# define PERIOD	10
# define PRINCIPAL	5000.00
# define   PI      3.1416
# define   MAX     180

# define    N   100
# define    A   2

int main() {
	int a = 20, b = 5, c = 0, d = 0, p = 0;
	float n = 6.2, m = 3.1, x, y, z, amount;

	printf("Simple Integer Arithmetic\n");
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%d * %d = %d\n", a, b, a / b);
	p = 25 / 5 * 2 + 3;
	printf("5 / 5 * 2 + 3 = %d\n", p);
	a = +50;
	b = -10;
	printf("%d + %d = %d\n", a, b, a + b);
	a = 50;
	b = 10;
	printf("%d + %d = %d\n", +a, -b, +a + -b);
	a = 10;
	b = a;
	printf("a is %d, b is %d\n", a, b);
	a++;
	b--;
	printf("a is %d, b is %d\n", a, b);
	a = 10;
	b = a;
	printf("a is %d, b is %d\n", a++, b--);
	printf("a is %d, b is %d\n", a, b);
	int x1;
	for (x1 = 1; x1 <= 10; x1++) {
		a = x1 % 2;
		printf("%2d %% 2 = %d\n", x1, a);
	}
	a = 15;
	b = 10;
	printf("a = %d  b = %d  c = %d\n", a, b, c);
	c = ++a - b;
	printf("c = ++a - b\na = %d  b = %d  c = %d\n", a, b, c);
	d = b++ + a;
	printf("d = b++ + a\na = %d  b = %d  d = %d\n", a, b, d);

	printf("a/b = %d\n", a / b);
	printf("a%%b = %d\n", a % b);
	printf("a *= b = %d\n", a *= b);
	printf("(c > d) ? 1 : 0 = %d\n", (c > d) ? 1 : 0);
	printf("(c < d) ? 1 : 0 = %d\n", (c < d) ? 1 : 0);

	printf("\nSimple Float Arithmetic\n");
	printf("%f + %f = %f\n", n, m, n + m);
	printf("%f - %f = %f\n", n, m, n - m);
	printf("%f * %f = %f\n", n, m, n * m);
	printf("%f / %f = %f\n", n, m, n / m);
	printf("%f to the %f power = %f\n", n, m, pow(n, m));
	printf("The square root of %f is %f\n", n, sqrt(n));
	printf("The square root of %f is %f\n", m, sqrt(m));
	printf("a = %d\n", a);
	printf("b = a / 2.0 = %f\n", b);
	printf("c = b * 4 = %d\n", c);

	a = 9;
	b = 12;
	c = 3;
	printf("x = %, b = %d, c = %d\n", x, y, z);
	x = a - b / 3 + c * 2 - 1;
	y = a - b / (3 + c) * (2 - 1);
	z = a - (b / (3 + c) * 2) - 1;
	printf("x = a - b / 3 + c * 2 - 1 = %f\n", x);
	printf("y = a - b / (3 + c) * (2 - 1) = %f\n", y);
	printf("z = a - (b / (3 + c) * 2) - 1 = %f\n", z);
	amount = 30.75 + 75.35;
	printf("amount = 30.75 + 75.35 = %5.2f\n", amount);

	double dbl;

	for (dbl = 0.0; dbl < 20.0; dbl += 1.0) {
		printf("%.0f\n", pow(2.0, dbl));
	}

	dbl = 4294967296.0;

	while (dbl >= 2.0) {
		printf("%.f\n", dbl);
		dbl = sqrt(dbl);
	}

	double hours = 3.1, age = 14.8;

	// printf("I parked for %g hours, so I got %g hours charged.\n",hours,/*fill in*/);
	// printf("Jake is %g years old, so he's %g.\n\n",age,/*fill in*/);
	// printf("I parked for %g hours, so I stayed a little longer than %g hours.\n",
	// 		hours,/*fill in*/);
	// printf("Jake is %g years old, so he's practically %g.\n",age,/*fill in*/);

	double dl = -5.6;
	printf("dl = %g, ceil(dl)=%g, floor(dl)=%g, trunc(dl)=%g, round(dl)=%g\n",
			dl, ceil(dl), floor(dl), trunc(dl), round(dl));

	double A_x, A_y, B_radius, B_angle;
	printf("Enter X coordinate of Point A: ");
	scanf("%lf", &A_x);
	printf("Enter Y coordinate of Point A: ");
	scanf("%lf", &A_y);

	printf("Point A is represented in polar coordinates as (%g, %g deg)\n\n",
			hypot(A_x, A_y), atan2(A_y, A_x) * 180.0 / PI);

	printf("Enter Radius of Point B: ");
	scanf("%lf", &B_radius);
	printf("Enter Angle of Point B in Degrees: ");
	scanf("%lf", &B_angle);

	printf("Point B is represented in Cartesian coordinates as (%g, %g)\n\n",
			B_radius * cos(B_angle * PI / 180.0),
			B_radius * sin(B_angle * PI / 180.0));

	float summ, numb, term;
	int count = 1;

	summ = 0;
	printf("Enter value of numb\n");
	scanf("%f", &numb);
	term = 1.0 / numb;
	while (count <= numb) {
		summ = summ + term;
		count++;
	}
	printf("Sum = %f\n", summ);

	float fsum = 0;
	int inn;
	for (inn = 1; inn <= 10; ++inn) {
		fsum = fsum + 1 / (float) inn;
		printf("%6.4f = %6.4f + 1 / (float) %2d = %6.4f\n", fsum, fsum, inn,
				fsum);
	}

	int angle;
	float xf1, yf1;
	angle = 0;
	while (angle <= MAX) {
		xf1 = (PI / MAX) * angle;
		yf1 = cos(xf1);
		printf("%15d %13.4f\n", angle, yf1);
		angle = angle + 10;
	}
	printf("%15d %13.4f\n", angle, yf1);

	int year;
	float value, inrate;
	amount = PRINCIPAL;
	inrate = 0.11;
	year = 0;
	while (year <= PERIOD) {
		printf("%2d		%8.2f\n", year, amount);
		value = amount + inrate * amount;
		year = year + 1;
		amount = value;
	}
	printf("%2d		%8.2f\n", year, amount);

	int aint = A;
	while (aint < N) {
		printf("%d\n", aint);
		aint *= aint;
	}
}

