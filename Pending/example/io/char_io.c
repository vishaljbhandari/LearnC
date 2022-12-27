#include <stdio.h>

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

void main() {
	single_getchar();
	seperate_getchar();
	continued_getchar();
	continued_getc();
	continued_putchar();
	continued_putc();
	looped_getchar();
}
