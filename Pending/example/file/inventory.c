#include  <stdio.h>

void main() {
	FILE *fp;
	int number, quantity, i;
	float price, value;
	char item[15], filename[15] = "inventory.txt";

	fp = fopen(filename, "w");
	printf("Input inventory data\n\n");
	printf("Item name  Number   Price   Quantity\n");
	for (i = 1; i <= 3; i++) {
		fscanf(stdin, "%s %d %f %d", item, &number, &price, &quantity);
		fprintf(fp, "%s %d %f %d", item, number, price, quantity);
	}
	fclose(fp);
	fprintf(stdout, "\n\n");

	fp = fopen(filename, "r");

	printf("Item name  Number   Price   Quantity    Value\n");
	for (i = 1; i <= 3; i++) {
		fscanf(fp, "%s %d %f %d", item, &number, &price, &quantity);
		value = price * quantity;
		fprintf(stdout, "%-8s %7d %8.2f %8d %11.2f\n", item, number, price,
				quantity, value);
	}
	fclose(fp);
}
