#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void malloc_allocation() {
	int *scores, x;

	scores = (int*) malloc(sizeof(int) * 4);
	if (scores == NULL) {
		puts("Unable to allocate memory");
		return;
	}

	*(scores + 0) = 100;
	*(scores + 1) = 97;
	*(scores + 2) = 105;
	*(scores + 3) = 110;

	for (x = 0; x < 4; x++)
		printf("Score %d: %d\n", x + 1, *(scores + x));
}

void realloc_allocation() {
	char *buffer, *buff;
	const static int strSize = 15;
	if ((buffer = (char*) malloc(sizeof(char) * strSize)) == NULL) {
		printf("malloc failed.\n");
		return;
	}
	printf("Buffer of size 10 created [%s] %d\n", buffer, strlen(buffer));
	strcpy(buffer, "HYDERABAD");
	printf("Buffer [%s] %d\n", buffer, strlen(buffer));
	printf("Location of buffer %ul before realloc\n", &buffer);
	/* Realloction */
	if ((buff = (char*) realloc(buffer, 15)) == NULL) {
		free(buffer);
		printf("Reallocation failed. \n");
		return;
	}
	free(buffer);
	buffer = NULL;
	printf("Location of buff %ul before realloc\n", &buff);
	printf("buff size modified.\n");
	printf("buff [%s] %d\n", buff, strlen(buff));
	strcpy(buff, "SECUNDERBAD");
	printf("buff [%s] %d\n", buff, strlen(buff));

	printf("\nSTRCPY Example\n");
	const char *source = "123456789";
	strncpy(buff, source, 1);
	printf("buff [%s] %d\n", buff, strlen(buff));
	strncpy(buff, source, 5);
	printf("buff [%s] %d\n", buff, strlen(buff));
	strncpy(buff, source, 9);
	printf("buff [%s] %d\n", buff, strlen(buff));
	strncpy(buff, source, 10);
	printf("buff [%s] %d\n", buff, strlen(buff));

	free(buff);
	buff = NULL;
}

int main() {
	malloc_allocation();
	realloc_allocation();
	return 0;
}
