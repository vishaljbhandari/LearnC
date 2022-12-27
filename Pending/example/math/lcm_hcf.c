#include<stdio.h>
#include<math.h>

void main() {
	int lcm = 1, hcf = 1, n1, n2, dif = 0, rem = 1;
	printf("Enter two numbers\n");
	scanf("%d\t%d", &n1, &n2);
	if (n1 && n2) {
		hcf = n1 > n2 ? n2 : n1;
		dif = n1 < n2 ? n1 : n1;
		rem = dif % hcf;
		while (rem) {
			dif = hcf;
			hcf = rem;
			rem = dif % hcf;
		}

		lcm = (n1 * n2) / hcf;
	}
	printf("Number were : %d and %d", n1, n2);
	printf("\nHCF of both numbers is : %d", hcf);
	printf("\nLCM of both numbers is : %d\n", lcm);
}
