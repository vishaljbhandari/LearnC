// memcpy() is used to copy a block of memory from a location to another. It is declared in string.h

// Copies "numBytes" bytes from address "from" to address "to"
// void * memcpy(void *to, const void *from, size_t numBytes);

#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "Geeks";
	char str2[] = "Quiz";

	puts("str1 before memcpy ");
	puts(str1);

	/* Copies contents of str2 to sr1 */
	memcpy(str1, str2, sizeof(str2));

	puts("\nstr1 after memcpy ");
	puts(str1);

	return 0;
}
