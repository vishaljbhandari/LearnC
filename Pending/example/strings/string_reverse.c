#include<stdio.h>
#include<string.h>

void main() {
	int i, j, k;
	char str[10], rev[10];
	scanf("%s", &str);
	for (i = 0; str[i]; i++) {
	}
	k = i;
	printf("Length: %d\n", k);
	for (i = k - 1, j = 0; i >= 0; i--, j++) {
		rev[j] = str[i];
	}
	rev[j] = '\0';
	printf("Reverse : %s\n", rev);
}
