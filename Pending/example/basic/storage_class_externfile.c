// this file must be compiled with storage_class_extern.c  like
// gcc storage_class_extern.c  storage_class_externfile.c
#include <stdio.h>

extern int count;

void write_extern(void) {
	printf("count is %d\n", count);
}
