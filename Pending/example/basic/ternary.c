#include <stdio.h>

#define MAXLOAN 50000
int main() {

	int a, b, c;

	a = 10;
	b = 14;
	c = (a > b) ? a : b;
	printf("%d is the greater of %d and %d\n", c, a, b);

	int x;

	for (x = 1; x <= 10; x++) {
		printf("%d - %s\n", x, x % 2 ? "odd" : "even");
	}

	int age = 62;
	char *classification;

	classification = ((age < 19) ? "kid" : (age < 65 ? "adult" : "geezer"));
	printf("You are a %s.\n", classification);

	long int loan1, loan2, loan3, sancloan, sum23;

	printf("Enter the values of previous two loans:\n");
	scanf(" %ld %ld", &loan1, &loan2);

	printf("\nEnter the value of new loan:\n");
	scanf(" %ld", &loan3);

	sum23 = loan2 + loan3;
	sancloan = (loan1 > 0) ? 0 : ((sum23 > MAXLOAN) ? MAXLOAN - loan2 : loan3);

	printf("\n\n");
	printf("Previous loans pending:\n%ld %ld\n", loan1, loan2);
	printf("Loan requested  = %ld\n", loan3);
	printf("Loan sanctioned = %ld\n", sancloan);

	return (0);
}
