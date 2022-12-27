#include <stdio.h>
#include <string.h>

int main() {
	char first[] = "I would like to go ";
	char second[] = "from here to there";
	char buffer[50];

	char input[64]; /* 63 characters plus null */
	int len;
	char *cstr;

	printf("first : %s, %d\n", first, strlen(first));
	printf("Second : %s, %d\n", second, strlen(second));
	strcpy(buffer, first);
	printf("After copy, buffer : %s, %d\n", buffer, strlen(buffer));
	strcat(buffer, " ");
	printf("After copy, buffer : %s, %d\n", buffer, strlen(buffer));
	strcat(buffer, second);
	printf("After copy, buffer : %s, %d\n", buffer, strlen(buffer));
	puts(buffer);

	printf("Enter String : ");
	fgets(input, 64, stdin);
	input[strcspn(input, "\n")] = 0;// to remove trailing new line character from input
	len = strlen(input);
	printf("input : %s, %d\n", input, strlen(input));
	printf("output : %s, %d\n", input, strlen(input));

	printf("Enter String : ");
	scanf("%[^\n]s", cstr);
	printf("cstr %s, %d\n", cstr, strlen(cstr));
	return 0;
}
