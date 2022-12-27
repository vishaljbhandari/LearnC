# include <stdio.h>

void main() {

	char input[64];

	printf("Instructions: ");
	fgets(input, 64, stdin);
	puts("Thank you! Here are your instructions:");
	puts(input);

	int x;
	char name[15];

	printf("Type an integer: ");
	scanf("%d", &x);
	printf("Integer %d\n", x);

	printf("Your name? ");
	scanf("%s", name);
	printf("You are %s.\n", name);

	int number;

	printf("Enter an integer number\n");
	scanf("%d", &number);

	if (number < 100)
		printf("Your number is smaller than 100\n\n");
	else
		printf("Your number contains more than two digits\n");

	int year, period;
	float amount, inrate, value;

	printf("Input amount, interest rate, and period\n\n");
	scanf("%f %f %d", &amount, &inrate, &period);
	printf("\n");
	year = 1;

	while (year <= period) {
		value = amount + inrate * amount;
		printf("%2d  Rs %8.2f\n", year, value);
		amount = value;
		year = year + 1;

	}
}
