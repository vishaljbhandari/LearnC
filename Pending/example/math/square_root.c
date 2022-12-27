#include<stdio.h>
#include <stdlib.h>
#include <math.h>

float square_root(float val) {
	float low, high, mid, oldmid, midsqr;
	int step = 0;

	// Set initial bounds and print heading.

	low = 0;
	high = mid = val;
	oldmid = -1;

	printf("%4s  %10s  %10s  %10s  %10s  %10s    %s\n", "Step", "Number", "Low",
			"High", "Mid", "Square", "Result");

	// Keep going until accurate enough.

	while (fabs(oldmid - mid) >= 0.00001) {
		oldmid = mid;

		// Get midpoint and see if we need lower or higher.

		mid = (high + low) / 2;
		midsqr = mid * mid;
		printf("%4d  %10.4f  %10.4f  %10.4f  %10.4f  %10.4f  ", ++step, val,
				low, high, mid, midsqr);
		if (mid * mid > val) {
			high = mid;
			printf("- too high\n");
		} else {
			low = mid;
			printf("- too low\n");
		}
	}

	// Desired accuracy reached, print it.
	return mid;
}

int main() {
	float root;
	int value;
	printf("Enter the square number = ");
	scanf("%d", &value);
	root = square_root(value);
	printf("Square root of the given number : %f\n", root);
	return 0;
}
