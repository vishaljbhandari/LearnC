#include <stdio.h>
#include <ctype.h>

	void Pattern1() {
		int i, n;
		char str[10] = "apple";
		printf("enter the no of rows\t");
		scanf_s("%d", &n);
		printf("\n----------------------------------\n");
		for (i = 1; i <= n; i++)
			printf("%5.*s%-5.*s\n", i, str, i, str);
		for (i = 4; i >= 1; i--)
			printf("%5.*s%-5.*s\n", i, str, i, str);
		printf("----------------------------------\n");
		for (i = 1; i <= n; i++)
			printf("%-5.*s%5.*s\n", i, str, i, str);
		for (i = 4; i >= 1; i--)
			printf("%-5.*s%5.*s\n", i, str, i, str);
		printf("----------------------------------\n");
		for (i = 5; i >= 1; i--)
			printf("%-5.*s%5.*s\n", i, str, i, str);
		for (i = 2; i <= n; i++)
			printf("%-5.*s%5.*s\n", i, str, i, str);
		printf("----------------------------------\n");
		for (i = 5; i >= 1; i--)
			printf("%5.*s%-5.*s\n", i, str, i, str);
		for (i = 2; i <= n; i++)
			printf("%5.*s%-5.*s\n", i, str, i, str);
		printf("----------------------------------\n");
	}

	void Pattern2() {
		int i, n;
		char str[10] = "apple";
		printf("enter the no of rows\t");
		scanf_s("%d", &n);
		printf("\n----------------------------------\n");
		for (i = 1; i <= n; i++)
			printf("%5.*s%-5.*s\n", i, str, i, str);
		printf("----------------------------------\n");

		for (i = 5; i >= 1; i--)
			printf("%5.*s%-5.*s\n", i, str, i, str);
		printf("----------------------------------\n");

		for (i = 1; i <= n; i++)
			printf("%-5.*s%5.*s\n", i, str, i, str);
		printf("----------------------------------\n");

		for (i = 5; i >= 1; i--)
			printf("%-5.*s%5.*s\n", i, str, i, str);
		printf("----------------------------------\n");

		for (i = 1; i <= n; i++)
			printf("%-5.*s\n", i, str);
		printf("----------------------------------\n");

		for (i = 1; i <= n; i++)
			printf("%5.*s\n", i, str);
		printf("----------------------------------\n");

		for (i = 5; i >= 1; i--)
			printf("%-5.*s\n", i, str);
		printf("----------------------------------\n");

		for (i = 5; i >= 1; i--)
			printf("%5.*s\n", i, str);
		printf("----------------------------------\n");
	}


	void single_getchar() {
		int ch;
		printf("single_getchar\n");
		printf("Type a character: ");
		ch = getchar();
		printf("Character '%c' received\n", ch);
	}

	void seperate_getchar() {
		int ch1, ch2;
		printf("\nseperate_getchar\n");
		printf("Type a character: ");
		ch1 = getchar();
		printf("Type a character: ");
		ch2 = getchar();
		printf("Characters '%c' and '%c' received\n", ch1, ch2);

		printf("\nType two letters\n");
		printf("[your letters will immediately printed back on screen]\n");
		ch1 = getchar();
		putchar(ch1);
		ch2 = getchar();
		putchar(ch2);
	}

	void continued_getchar() {
		int ch1, ch2;
		printf("\ncontinued_getchar\n");
		printf("Type two characters: ");
		ch1 = getchar();
		ch2 = getchar();
		printf("Characters '%c' and '%c' received.\n", ch1, ch2);
		printf("You typed '");
		putchar(ch1);
		printf("' and '");
		putchar(ch2);
		printf("\n");
	}

	void continued_getc() {
		int ch1, ch2;
		printf("\ncontinued_getc\n");
		printf("Type two characters: ");
		ch1 = getc(stdin);
		ch2 = getc(stdin);
		printf("Characters '%c' and '%c' received.\n", ch1, ch2);
	}

	void continued_putchar() {
		printf("\ncontinued_putchar..\n");
		putchar('H');
		putchar('e');
		putchar('l');
		putchar('l');
		putchar('o');
		putchar('\n');
	}

	void continued_putc() {
		printf("\ncontinued_putc..\n");
		putc('H', stdout);
		putc('i', stdout);
		putc('\n', stdout);
	}

	void looped_getchar() {
		int a;
		printf(
			"\nlooped_getchar\nKeep of typing letters, All will be printed back\n");
		printf("To exit/break, enter'A'\n");
		while (1) {
			a = getchar();
			if (a == 'A')
				break;
			putchar(a);
		}
	}

	void GetChar() {
		int i = 65;  // integer type i keeps the value of 65
		char c = 'A'; // char type c stores 'a' indirectly its stores ascii value of A as 65

		printf("\t\t-------------------------------------\t\t\n");
		printf("\t\tint i=65\tand\tchar c='A'\n");
		printf("\t\t-----------------------------\t\t\n");
		printf("\tREPRESENTATION OF INPUT DATA IN DIFFERENT FORMATS...\n");
		printf("\t\t-----------------------------\t\t\n");

		printf("\nputchar('A')\t:\t");
		putchar('A');
		printf("\tdirectly print 'A'");

		printf("\n\nputchar('*')\t:\t");
		putchar('*');
		printf("\tdirectly print '*'");

		printf("\n\nputchar(A)\t:\t");
		// putchar(A);
		printf("error\tundefine symbol A not in ' ' not an ascii value");

		printf("\n\nputchar('i')\t:\t");
		putchar('i');
		printf("\tdirectly print 'i'");

		printf("\n\nputchar(i)\t:\t");
		putchar(i);
		printf("\ti stores 65 that is ascii code of A");

		printf("\n\nputchar('A')\t:\t");
		putchar('A');
		printf("\tdirectly print 'A'");

		printf("\n\nputchar(65)\t:\t");
		putchar(65);
		printf("\t65 directly acts as ascii code of A");

		printf("\n\nputchar('65')\t:\t");
		putchar('65');
		printf("\tonly first character is treated as output");

		printf("\n\nputchar('6524')\t:\t");
		// putchar('6524');
		printf("error\tonly 2 characters are allowed");

		printf("\n\nputchar('1')\t:\t");
		putchar('1');
		printf("\tdirectly print '1'");

		printf("\n\nputchar(1)\t:\t");
		putchar(1);
		printf("\tbecause ascii code of this symbol 1");

		printf("\n\nputchar(i+3)\t:\t");
		putchar(i + 3);
		printf("\tsum of ascii codes is 68 thats ascii code of D");

		printf("\n\nputchar('A'+3)\t:\t");
		putchar('A' + 3);
		printf("\tsum of ascii codes is 68 thats ascii code of D");

		printf("\n\nputchar('w'+3)\t:\t");
		putchar('w' + 3);
		printf("\tsum of ascii codes is 122 thats ascii code of z");

		printf("\n\nputchar('A+3')\t:\t");
		//  putchar('A+3');
		printf("error\tchar const must contain 1 or 2 character");

		printf("\n\nputchar(c)\t:\t");
		putchar(c);
		printf("\tchar variable c contains 'A'");

		printf("\n\nputchar('c+3')\t:\t");
		//putchar('c+3');
		printf("error\tchar const must contain 1or 2 character");

		printf("\n\nputchar(c+3)\t:\t");
		putchar(c + 3);
		printf("\tsum of ascii codes is 68 thats ascii code of D");

		printf("\n\nputchar(500)\t:\t");
		putchar(300);
		printf("\tLSB byte generates ascii code of this character");

		printf("\n\n");
	}

	void PrintF() {
		/*


specifier	Output	Example
d or i	Signed decimal integer	392
u	Unsigned decimal integer	7235
o	Unsigned octal	610
x	Unsigned hexadecimal integer	7fa
X	Unsigned hexadecimal integer (uppercase)	7FA
f	Decimal floating point, lowercase	392.65
F	Decimal floating point, uppercase	392.65
e	Scientific notation (mantissa/exponent), lowercase	3.9265e+2
E	Scientific notation (mantissa/exponent), uppercase	3.9265E+2
g	Use the shortest representation: %e or %f	392.65
G	Use the shortest representation: %E or %F	392.65
a	Hexadecimal floating point, lowercase	-0xc.90fep-2
A	Hexadecimal floating point, uppercase	-0XC.90FEP-2
c	Character	a
s	String of characters	sample
p	Pointer address	b8000000
n	Nothing printed.
The corresponding argument must be a pointer to a signed int.
The number of characters written so far is stored in the pointed location.
%	A % followed by another % character will write a single % to the stream.	%


*/

		printf("Characters: %c %c \n", 'a', 65);
		printf("Decimals: %d %ld\n", 1977, 650000L);
		printf("Preceding with blanks: %10d \n", 1977);
		printf("Preceding with zeros: %010d \n", 1977);
		printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100,
			100);
		printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
		printf("Width trick: %*d \n", 5, 10);
		printf("%s \n", "A string");
	}


	void Example1() {
		char name[32];
		char last[] = "passed the challenge!";
		char buffer[64];
		int ch, a;

		/* fetch input */
		printf("What is your name? ");
		/* initialize a to 0, the first element of the array */
		a = 0;
		/* the test condition is the character returned from
		 the getchar() function; It ends on the newline */
		while ((ch = getchar()) != '\n') {
			name[a] = ch; /* store the character input */
			a++; /* increment the array index */
			if (a == 31) /* check for buffer overflow; the 31st element is the last */
				break; /* cancel on a full buffer */
		}
		name[a] = '\0'; /* cap the array (string) with a null character */

		/* process the strings */
		printf("Buffer [%s] length %d\n", buffer, strlen(buffer));
		strcpy(buffer, name);
		printf("Buffer [%s] length %d\n", buffer, strlen(buffer));
		strcat(buffer, " ");
		printf("Buffer [%s] length %d\n", buffer, strlen(buffer));
		strcat(buffer, last);
		printf("Buffer [%s] length %d\n", buffer, strlen(buffer));


		single_getchar();
		seperate_getchar();
		continued_getchar();
		continued_getc();
		continued_putchar();
		continued_putc();
		looped_getchar();

	}

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
		scanf_s("%s", input, (unsigned int)sizeof(input));
		printf("Pleased to meet you, %s!\n", input);
	}

	void formatted_io() {
		char input[10];

		printf("Your name? ");
		scanf_s("%9s", input, (unsigned int)sizeof(input));
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
		if (scanf_s("%d %f %c", &a, &b, &c) == 3)
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
		scanf_s("%[a-z ]", address, (unsigned int)sizeof(address));
		printf("%-80s\n\n", address);

		char address1[80];

		printf("Enter address\n");
		scanf_s("%[^\n]", address1, (unsigned int)sizeof(address1));
		printf("%-80s", address1);
	}

	void input_real_number() {
		float x, y;
		double p, q;
		printf("\nFormatted Real Number [Input]\n");
		printf("Values of x and y:");
		scanf_s("%f %e", &x, &y);
		printf("\n");
		printf("x = %f\ny = %f\n\n", x, y);
		printf("Values of p and q:");
		scanf_s("%lf %lf", &p, &q);
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
		scanf_s("%d", &a);
		scanf_s("%d", &b);
		scanf_s("%d", &c);
		printf("%d %d %d \n\n", a, b, c);

		printf("Enter two 4-digit numbers\n");
		scanf_s("%2d %4d", &x, &y);
		printf("%d %d\n\n", x, y);

		printf("Enter two integers\n");
		scanf_s("%d %d", &a, &x);
		printf("%d %d \n\n", a, x);

		printf("Enter a nine digit number\n");
		scanf_s("%3d %4d %3d", &p, &q, &r);
		printf("%d %d %d \n\n", p, q, r);

		printf("Enter two three digit numbers\n");
		scanf_s("%d %d", &x, &y);
		printf("%d %d", x, y);
	}

	void formatted_string_input() {
		char name1[15], name2[15], name3[15];
		printf("Enter the 1st String\n");
		scanf_s("%15c", name1, (unsigned int)sizeof(name1));
		printf("1st String\n\n%15s\n\n", name1);
		printf("Enter the 2nd String\n");
		scanf_s("%s", name2, (unsigned int)sizeof(name2));
		printf("2nd String\n\n%15s\n\n", name2);
		printf("Enter the 3rd String\n");
		scanf_s("%15s", name3, (unsigned int)sizeof(name3));
		printf("3rd String\n\n%15s\n\n", name3);
	}

	void PrintFPatterns() {
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
