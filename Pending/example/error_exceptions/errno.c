#include <stdio.h>
#include <errno.h>

void main() {
	printf("errno is: %d\n", errno);
	printf("Erasing file foo.bar\n");
	remove("foo.bar");
	printf("errno is: %d\n", errno);
	perror("Cannot erase file");

}
