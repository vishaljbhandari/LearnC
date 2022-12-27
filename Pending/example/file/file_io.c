#include <stdio.h>

void file_i() {
	const char filename[] = "integers.dat";
	FILE *fp;
	int x, a[10];

	/* open the file for reading */
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Unable to create %s\n", filename);
		return;
	}

	/* read integers */
	fread(&a, sizeof(int), 10, fp);
	for (x = 0; x < 10; x++)
		printf("%d\n", a[x]);

	/* read integers */
	for (x = 0; x < 10; x++) {
		fread(&a, sizeof(int), 1, fp);
		printf("%d\n", a);
	}

	fclose(fp);
}

void file_o() {
	const char filename[] = "integers.dat";
	FILE *fp;
	int x, a;

	/* open and create the file */
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Unable to create %s\n", filename);
		return;
	}

	/* write the integers */
	a = 10;
	for (x = 0; x < 10; x++) {
		fwrite(&a, sizeof(int), 1, fp);
		a += 5;
	}

	/* and remember to close */
	fclose(fp);
}

void file_structure_write() {
	const char filename[] = "presidents.dat";
	FILE *fp;
	struct person {
		char name[32];
		int inaguration;
		int age;
	} presidents[10] = { { "George Washington", 1789, 57 }, { "John Adams",
			1797, 62 }, { "Thomas Jefferson", 1801, 58 }, { "James Madison",
			1809, 58 }, { "James Monroe", 1817, 59 }, { "John Quincy Adams",
			1825, 58 }, { "Andrew Jackson", 1829, 62 }, { "Martin Van Buren",
			1837, 55 }, { "William Henry Harrison", 1841, 68 }, { "John Tyler",
			1841, 51 } };

	/* open the file */
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Unable to create %s\n", filename);
		return;
	}

	/* write the 10 structures */
	fwrite(presidents, sizeof(struct person), 10, fp);

	/* and remember to close */
	fclose(fp);
}

void file_structure_read() {
	const char filename[] = "presidents.dat";
	struct person {
		char name[32];
		int inauguration;
		int age;
	} president;
	int x;
	FILE *fp;

	/* open the file */
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Unable to open %s\n", filename);
		return;
	}

	/* prompt to read a specific record */
	printf("Enter record to read (1-10): ");
	scanf("%d", &x);
	/* validate the input */
	if (x < 1 || x > 10) {
		puts("Invalid input");
		return;
	}
	/* decrement x to reference the proper offset */
	x--;

	/* Set the file position indicator */
	fseek(fp, sizeof(struct person) * x, SEEK_SET);
	/* fetch the record */
	fread(&president, sizeof(struct person), 1, fp);

	/* printthe result */
	printf("President %s was %d years old when inaugurated in %d\n",
			president.name, president.age, president.inauguration);
}

int main() {
	file_i();
	file_o();
	file_structure_write();
	file_structure_read();
	return 0;
}
