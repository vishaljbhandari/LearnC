// jump.c by Bill Weinman <http://bw.org/>
#include <stdio.h>

void a() {
	puts("this is a()");
}
void b() {
	puts("this is b()");
}
void c() {
	puts("this is c()");
}
void d() {
	puts("this is d()");
}
void e() {
	puts("this is e()");
}
void (*funcs[])() = {a, b, c, d, e, NULL };

	int jump(char *s) {
		char code = s[0];
		if (code == 'q' || code == 'Q')
			return 0;

		// get the length of the funcs array
		int func_length;
		for (func_length = 0; funcs[func_length] != NULL; func_length++)
			;

		unsigned int i = (int) code - '0';
		i--;		// list is zero-based
		if ((i < 0) || (i > 8)) {
			puts("invalid choice");
			return 1;
		}

		if (i < func_length) {
			funcs[i]();
			return 1;
		} else {
			puts("invalid choice");
			return 1;
		}
	}

	int prompt() {
		puts("Choose an option:");
		puts("1. Function a()");
		puts("2. Function b()");
		puts("3. Function c()");
		puts("4. Function d()");
		puts("5. Function e()");
		puts("Q. Quit.");
		printf(">> ");
		char *response;
		size_t numchars = 1;
		response = fgetln(stdin, &numchars);

		return jump(response);
	}

	int main() {
		while (prompt()) {
		}
		puts("\nDone.");
		return 0;
	}

