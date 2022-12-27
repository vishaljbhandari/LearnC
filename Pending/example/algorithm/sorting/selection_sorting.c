#include<stdio.h>
#define MAX 10

void selection(int *arr, int n) {
	int i, pos, tmp;

	for (i = 0; i < n; i++) {
		pos = getmin(arr, i, n);
		tmp = arr[i];
		arr[i] = arr[pos];
		arr[pos] = tmp;
	}
}

int getmin(int *arr, int lo, int hi) {
	int pos, min, i;
	pos = lo;
	min = arr[lo];

	for (i = lo; i < hi; i++) {
		if (arr[i] < min) {
			pos = i;
			min = arr[i];
		}
	}
	return pos;
}

int main() {
	int arr[MAX], n, i;

	puts("How many Number Of Element : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Enter Element[%d] : ", i + 1);
		scanf("%d", &arr[i]);
	}

	puts("\nArray Before Sorting......");
	for (i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}
	puts("\nArray After Sorting......");
	selection(arr, n);

	for (i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}
	puts("\n");
	return 0;
}

