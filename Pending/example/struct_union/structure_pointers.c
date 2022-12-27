#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void structure_pointer1() {
	struct person {
		char *name;
		int age;
	}*you;
	char buffer[32];

	/* allocate storage for the structure */
	you = (struct person *) malloc(sizeof(struct person) * 1);
	if (you == NULL) {
		puts("Unable to allocate storage");
		exit(1);
	}

	printf("Enter your name: ");
	fgets(buffer, 32, stdin);
	/* allocate storage */
	you->name = (char *) malloc(sizeof(buffer));
	if (you->name == NULL) {
		puts("Unable to allocate storage");
		exit(1);
	}
	/* copy the buffer */
	strcpy(you->name, buffer);
	/* get your age */
	printf("Enter your age: ");
	scanf("%d", &you->age);

	printf("You are %s", you->name);
	printf("You are %d years old\n", you->age);
}

void structure_pointer2() {
	struct person {
		char name[32];
		int age;
	}*you;

	/* allocate storage for the structure */
	you = (struct person *) malloc(sizeof(struct person) * 1);
	if (you == NULL) {
		puts("Unable to allocate storage");
		exit(1);
	}

	printf("Enter your name: ");
	fgets(you->name, 32, stdin);
	/* get your age */
	printf("Enter your age: ");
	scanf("%d", &you->age);

	printf("You are %s", you->name);
	printf("You are %d years old\n", you->age);
}

void structure_pointer3() {
	struct person {
		char *name;
		int age;
	} you;
	char buffer[32];

	printf("Enter your name: ");
	fgets(buffer, 32, stdin);
	/* allocate storage */
	you.name = (char *) malloc(strlen(buffer) + 1);
	if (you.name == NULL) {
		puts("Unable to allocate storage");
		exit(1);
	}
	/* copy the buffer */
	strcpy(you.name, buffer);
	/* get your age */
	printf("Enter your age: ");
	scanf("%d", &you.age);

	printf("You are %s", you.name);
	printf("You are %d years old\n", you.age);
}

int main() {
	structure_pointer1();
	structure_pointer2();
	structure_pointer3();
	return 0;
}
