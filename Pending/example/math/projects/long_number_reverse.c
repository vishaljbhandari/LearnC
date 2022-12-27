#include<stdio.h>
#include<math.h>
int main() {
	long n, rev = 0;
	printf("Enter Number : ");
	scanf("%ld", &n);
	while (n) {
		rev = rev * 10 + (n % 10);
		n = n / 10;
	}
	printf("Reverse Number : %ld\n", rev);
	return 0;
}
