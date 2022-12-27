#include<stdio.h>

void main() {
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
