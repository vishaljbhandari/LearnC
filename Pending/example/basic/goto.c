#include <stdio.h>

/*
 Syntax1        |   Syntax2
 going downward    going upward
 ------------------------------
 goto label;    |    label:
 .              |    .
 .              |    .
 .              |    .
 label:         |    goto label;

 */
int main() {
	int n;

	if (n == 1) {
		goto end;
		// goto should be conditional
	}
	// goto in loop
	for (n = 0; n <= 10; ++n) {
		if (n == 10)
			goto end;
		// goto should be conditional
		// control jumping to label
		printf("%d\n", n);
	}
	printf("outside of loop\n");
	end: printf("after goto end label");
	return 0;
}
