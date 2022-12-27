#include <stdio.h>

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

int main() {
	printf("Characters: %c %c \n", 'a', 65);
	printf("Decimals: %d %ld\n", 1977, 650000L);
	printf("Preceding with blanks: %10d \n", 1977);
	printf("Preceding with zeros: %010d \n", 1977);
	printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100,
			100);
	printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	printf("Width trick: %*d \n", 5, 10);
	printf("%s \n", "A string");
	return 0;
}
