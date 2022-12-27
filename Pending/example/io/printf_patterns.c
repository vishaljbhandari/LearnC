#include<stdio.h>
#include<string.h>
void more() {
	int i, n;
	char str[10] = "apple";
	printf("enter the no of rows\t");
	scanf("%d", &n);
	printf("\n----------------------------------\n");
	for (i = 1; i <= n; i++)
		printf("%5.*s%-5.*s\n", i, str, i, str);
	printf("----------------------------------\n");

	for (i = 5; i >= 1; i--)
		printf("%5.*s%-5.*s\n", i, str, i, str);
	printf("----------------------------------\n");

	for (i = 1; i <= n; i++)
		printf("%-5.*s%5.*s\n", i, str, i, str);
	printf("----------------------------------\n");

	for (i = 5; i >= 1; i--)
		printf("%-5.*s%5.*s\n", i, str, i, str);
	printf("----------------------------------\n");

	for (i = 1; i <= n; i++)
		printf("%-5.*s\n", i, str);
	printf("----------------------------------\n");

	for (i = 1; i <= n; i++)
		printf("%5.*s\n", i, str);
	printf("----------------------------------\n");

	for (i = 5; i >= 1; i--)
		printf("%-5.*s\n", i, str);
	printf("----------------------------------\n");

	for (i = 5; i >= 1; i--)
		printf("%5.*s\n", i, str);
	printf("----------------------------------\n");

}

void main() {
	int i, n;
	char str[10] = "apple";
	printf("enter the no of rows\t");
	scanf("%d", &n);
	printf("\n----------------------------------\n");
	for (i = 1; i <= n; i++)
		printf("%5.*s%-5.*s\n", i, str, i, str);
	for (i = 4; i >= 1; i--)
		printf("%5.*s%-5.*s\n", i, str, i, str);
	printf("----------------------------------\n");
	for (i = 1; i <= n; i++)
		printf("%-5.*s%5.*s\n", i, str, i, str);
	for (i = 4; i >= 1; i--)
		printf("%-5.*s%5.*s\n", i, str, i, str);
	printf("----------------------------------\n");
	for (i = 5; i >= 1; i--)
		printf("%-5.*s%5.*s\n", i, str, i, str);
	for (i = 2; i <= n; i++)
		printf("%-5.*s%5.*s\n", i, str, i, str);
	printf("----------------------------------\n");
	for (i = 5; i >= 1; i--)
		printf("%5.*s%-5.*s\n", i, str, i, str);
	for (i = 2; i <= n; i++)
		printf("%5.*s%-5.*s\n", i, str, i, str);
	printf("----------------------------------\n");
	more();
}

