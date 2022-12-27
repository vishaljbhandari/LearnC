#include <cstdio>
#include <cstring>
#include <cerrno> //This header is part of the error handling library.

int main() {
	printf("errno is: %d\n", errno);
	printf("Erasing file foo.bar\n");
	remove("foo.bar");
	printf("errno is: %d\n", errno);
	// errno is a preprocessor macro used for error indication. It expands to a static (until C++11) thread-local (since C++11) modifiable lvalue of type int.
	perror("Cannot erase file");
	return 0;
}
