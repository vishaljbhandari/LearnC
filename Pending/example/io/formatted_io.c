#include <stdio.h>
#include <ctype.h>

void int_printing() {
	int a = 123;

	puts("The %d placeholder, no width specification:");
	printf("%d\n", a);
	puts("8-character width:");
	printf("%8d\n", a);
	printf("%8d\n", a * 10);
	printf("%8d\n", a * 100);
	puts("Left-justified 8-character width:");
	printf("%-8d\n", a);
	printf("%-8d\n", a * 10);
	printf("%-8d\n", a * 100);
	puts("8-character width padded with zeros:");
	printf("%08d\n", a);
	printf("%08d\n", a * 10);
	printf("%08d\n", a * 100);
}

void float_printing() {
	float a = 1234.5678;

	puts("Placeholder %f, no width specification:");
	printf("%f\n", a);
	puts("Width of 15 characters, %15f:");
	printf("%15f\n", a);
	puts("Width of 6 characters, 1 decimal place, %6.1f");
	printf("%6.1f\n", a);
	puts("No width, limit to 2 decimal places, %.2f");
	printf("%.2f\n", a);
}

void char_printing() {
	char string[] = "Deadly spiders!";

	puts("String displayed with %s:");
	printf("%s\n", string);
	puts("String displayed in a 24-character width:");
	printf("%24s\n", string);
	puts("24-character width, left-justified:");
	printf("%-24s\n", string);
	puts("24-character width, 6-character truncated:");
	printf("%24.6s\n", string);
	puts("24-character width, 6-character truncated, left-justified:");
	printf("%-24.6s\n", string);
}

void double_printing() {
	double avogadro = 6.022e23;

	puts("Large value with %f:");
	printf("%f\n", avogadro);
	puts("With the %e and %E placeholders:");
	printf("%e\n", avogadro);
	printf("%E\n", avogadro);
	puts("With %g and %G:");
	printf("%g\n", avogadro);
	printf("%G\n", avogadro);
}

void special_printing() {
	int x, o;
	printf("Printing Hects\n");
	for (x = 0x1; x <= 0x10; x++)
		printf("0x%X = %d\n", x, x);
	printf("\nPrinting Octal\n");
	for (o = 01; o <= 010; o++)
		printf("0%O = %d\n", o, o);

	printf("\nPrinting Annotation\n");
	printf("%f\n", 2.5E6);
	printf("%f\n", 2.5e-6);
}

void io() {
	char input[10];

	printf("Your name? ");
	scanf("%s", input);
	printf("Pleased to meet you, %s!\n", input);
}

void formatted_io() {
	char input[10];

	printf("Your name? ");
	scanf("%9s", input);
	printf("Pleased to meet you, %s!\n", input);
}

void formatted_fio() {
	char input[10];

	printf("Your name? ");
	fgets(input, 10, stdin);
	printf("Pleased to meet you, %s!\n", input);
}

void formatted_fio_for() {
	char input[10];
	int i;

	printf("Your name? ");
	fgets(input, 10, stdin);
	/* repace the newline in the buffer with the null character */
	for (i = 0; i < 10; i++) {
		if (input[i] == '\n')
			input[i] = '\0';
	}
	printf("Pleased to meet you, %s!\n", input);
}

void character_types() {
	char character;
	printf("Press any key\n");
	character = getchar();
	if (isalpha(character) > 0)
		printf("The character is a letter.");
	else if (isdigit(character) > 0)
		printf("The character is a digit.");
	else
		printf("The character is not alphanumeric.");
}

void scanf_input() {
	int a;
	float b;
	char c;
	printf("Enter values of a, b and c\n");
	if (scanf("%d %f %c", &a, &b, &c) == 3)
		printf("a = %d  b = %f   c = %c\n", a, b, c);
	else
		printf("Error in input.\n");
}

void case_conversion() {
	char alphabet;
	printf("Enter an alphabet");
	putchar('\n'); /* move to next line */
	alphabet = getchar();
	if (islower(alphabet))
		putchar(toupper(alphabet));
	else
		putchar(tolower(alphabet));
}

void coversion_specifiers() {
	char address[80];
	printf("Enter address\n");
	scanf("%[a-z ]", address);
	printf("%-80s\n\n", address);

	char address1[80];

	printf("Enter address\n");
	scanf("%[^\n]", address1);
	printf("%-80s", address1);
}

void input_real_number() {
	float x, y;
	double p, q;
	printf("\nFormatted Real Number [Input]\n");
	printf("Values of x and y:");
	scanf("%f %e", &x, &y);
	printf("\n");
	printf("x = %f\ny = %f\n\n", x, y);
	printf("Values of p and q:");
	scanf("%lf %lf", &p, &q);
	printf("\np = %lf\nq = %e", p, q);
	printf("\n\np = %.12lf\nq = %.12e", p, q);
}

void formatted_real_output() {
	printf("\nFormatted Real Number [Output]\n");
	double y = 98.7654;
	printf("%7.4f\n", y);
	printf("%f\n", y);
	printf("%7.2f\n", y);
	printf("%-7.2f\n", y);
	printf("%07.2f\n", y);
	printf("%*.*f", 7, 2, y);
	printf("\n");
	printf("%10.2e\n", y);
	printf("%12.4e\n", -y);
	printf("%-10.2e\n", y);
	printf("%e\n", y);
}

void formatted_string_output() {
	printf("\nFormatted String [Output]\n");
	char x = 'A';
	static char name[20] = "ANIL KUMAR GUPTA";

	printf("OUTPUT OF CHARACTERS\n\n");
	printf("%c\n%3c\n%5c\n", x, x, x);
	printf("%3c\n%c\n", x, x);
	printf("\n");

	printf("OUTPUT OF STRINGS\n\n");
	printf("%s\n", name);
	printf("%20s\n", name);
	printf("%20.10s\n", name);
	printf("%.5s\n", name);
	printf("%-20.10s\n", name);
	printf("%5s\n", name);
}

void formatted_integer_output() {
	int m = 12345;
	long n = 987654;
	printf("\nFormatted Integer Number [Output]\n");
	printf("%d\n", m);
	printf("%10d\n", m);
	printf("%010d\n", m);
	printf("%-10d\n", m);
	printf("%10ld\n", n);
	printf("%10ld\n", -n);
}

void formatted_integer_input() {
	int a, b, c, x, y, z;
	int p, q, r;
	printf("\nFormatted Integer Number [Input]\n");
	printf("Enter three integer numbers\n");
	scanf("%d %*d %d", &a, &b, &c);
	printf("%d %d %d \n\n", a, b, c);

	printf("Enter two 4-digit numbers\n");
	scanf("%2d %4d", &x, &y);
	printf("%d %d\n\n", x, y);

	printf("Enter two integers\n");
	scanf("%d %d", &a, &x);
	printf("%d %d \n\n", a, x);

	printf("Enter a nine digit number\n");
	scanf("%3d %4d %3d", &p, &q, &r);
	printf("%d %d %d \n\n", p, q, r);

	printf("Enter two three digit numbers\n");
	scanf("%d %d", &x, &y);
	printf("%d %d", x, y);
}

void formatted_string_input() {
	char name1[15], name2[15], name3[15];
	printf("Enter the 1st String\n");
	scanf("%15c", name1);
	printf("1st String\n\n%15s\n\n", name1);
	printf("Enter the 2nd String\n");
	scanf("%s", name2);
	printf("2nd String\n\n%15s\n\n", name2);
	printf("Enter the 3rd String\n");
	scanf("%15s", name3);
	printf("3rd String\n\n%15s\n\n", name3);
}

void main() {

	int_printing();
	float_printing();
	char_printing();
	double_printing();
	special_printing();

	io();
	formatted_io();
	formatted_fio();
	formatted_fio_for();

	character_types();
	case_conversion();
	scanf_input();
	coversion_specifiers();
	input_real_number();

	formatted_real_output();
	formatted_string_output();
	formatted_integer_output();
	formatted_integer_input();
	formatted_string_input();

}
