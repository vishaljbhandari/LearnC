#include <stdio.h>
#include <string.h>

int main() {
	char name[32];
	char last[] = "passed the challenge!";
	char buffer[64];
	int ch, a;

	/* fetch input */
	printf("What is your name? ");
	/* initialize a to 0, the first element of the array */
	a = 0;
	/* the test condition is the character returned from
	 the getchar() function; It ends on the newline */
	while ((ch = getchar()) != '\n') {
		name[a] = ch; /* store the character input */
		a++; /* increment the array index */
		if (a == 31) /* check for buffer overflow; the 31st element is the last */
			break; /* cancel on a full buffer */
	}
	name[a] = '\0'; /* cap the array (string) with a null character */

	/* process the strings */
	printf("Buffer [%s] length %d\n", buffer, strlen(buffer));
	strcpy(buffer, name);
	printf("Buffer [%s] length %d\n", buffer, strlen(buffer));
	strcat(buffer, " ");
	printf("Buffer [%s] length %d\n", buffer, strlen(buffer));
	strcat(buffer, last);
	printf("Buffer [%s] length %d\n", buffer, strlen(buffer));

	return (0);
}
