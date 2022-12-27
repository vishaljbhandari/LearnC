#include <math.h>
#include <stdio.h>
void main() {
	int amount;
	float time, rate = 6.5, interest;
	printf("Principal amount : ");
	scanf("%d", &amount);
	printf("Time period : ");
	scanf("%f", &time);
	interest = (amount * rate * time) / 100;
	printf("The interest is = %5.2f [Principal:%d, Rate:%f, Time:%f]\n",
			interest, amount, rate, time);
}
