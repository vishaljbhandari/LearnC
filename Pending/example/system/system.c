#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Press Enter to clear the screen: ");
	getchar();
//	system("clear");	/* unix */
	system("cls"); /* Windows */
	puts("Thank you");

	return (0);
}
