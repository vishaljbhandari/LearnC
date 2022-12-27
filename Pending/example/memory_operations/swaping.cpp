// gcc -Wall -Wextra -Werror -lstdc++ -lm swaping.cp
#include <iostream>
/*
 Difficult to use and prone to errors
 Also needs a null check
 */
void swap_ptr(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

//Easy to use and no null check required
void swap_ref(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}
int main() {
	using namespace std;
	int a = 5, b = 10;
	cout << "a:" << a << "\n";
	cout << "b:" << b << "\n";
	swap_ptr(&a, &b);
	cout << "a:" << a << "\n";
	cout << "b:" << b << "\n";
	swap_ref(a, b);
	cout << "a:" << a << "\n";
	cout << "b:" << b << "\n";
	return 0;
}
