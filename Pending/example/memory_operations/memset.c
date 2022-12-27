/*

 memset
 void * memset ( void * ptr, int value, size_t num );
 Fill block of memory
 Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).

 Parameters
 ptr
 Pointer to the block of memory to fill.
 value
 Value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
 num
 Number of bytes to be set to the value.
 size_t is an unsigned integral type.

 Return Value
 ptr is returned.

 */

/* memset example */
#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "almost every programmer should know memset!";
	memset(str, '-', 6);
	puts(str);

	char str1[] = "0123456789";
	memset(str1 + 3, '-', 3);
	puts(str1);
	return 0;
}
