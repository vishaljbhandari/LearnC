#include<iostream.h>
void swap(int *a, int *b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void inmemory_swap(int *a, int *b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main() {
	int x, y;
	cout << "enter first numbers x : ";
	cin >> x;
	cout << "\nenter second number y : ";
	cin >> y;
	swap(&x, &y);
	cout << "\nafter swapping\n";
	cout << "x : " << x << " y : " << y;
	return 0;
}
