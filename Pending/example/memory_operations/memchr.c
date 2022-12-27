/*

 const void * memchr ( const void * ptr, int value, size_t num );
 void * memchr (       void * ptr, int value, size_t num );

 Locate character in block of memory
 Searches within the first num bytes of the block of memory pointed by ptr for the first occurrence of value (interpreted as an unsigned char), and returns a pointer to it.

 Both value and each of the bytes checked on the the ptr array are interpreted as unsigned char for the comparison.

 Parameters
 ptr
 Pointer to the block of memory where the search is performed.
 value
 Value to be located. The value is passed as an int, but the function performs a byte per byte search using the unsigned char conversion of this value.
 num
 Number of bytes to be analyzed.
 size_t is an unsigned integral type.

 Return Type
 A pointer to the first occurrence of value in the block of memory pointed by ptr.
 typecast to (char*) is required
 If the value is not found, the function returns a null pointer.

 */

/* memchr example */
#include <stdio.h>
#include <string.h>

int main() {
	char *pch;
	char str[] = "Example string";
	pch = (char*) memchr(str, 'p', strlen(str));
	if (pch != NULL)
		printf("'p' found at position %d.\n", pch - str + 1);
	else
		printf("'p' not found.\n");
	return 0;
}
