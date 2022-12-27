#include <stdio.h>
#include <stdlib.h>
void main() {
	int array[10], i, j, no, index, flag = 0;

	printf("Enter The Elements of Array : \n");
	for (i = 0; i < 10; i++) {
		printf("Element %d : ", i + 1);
		scanf("%d", &array[i]);
	}
	printf("Enter The Number To Remove : ");
	scanf("%d", &no);

	for (i = 0; i < 10; i++) {
		if (no == array[i]) {
			flag = 1;
			index = i;
			break;
		}
	}
	if (flag == 0) {
		printf("Number To Remove is Not PRESENT....\nTry. AGAIN.......");
		exit(0);
	}

	for (i = index, j = index; i < 10; i++, j++) {
		array[i] = array[i + 1];
	}
	array[i] = '\0';
	for (i = 0; i < j - 1; i++) {
		printf("%d\n", array[i]);
	}
}
