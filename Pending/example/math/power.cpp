#include<stdio.h>
#include<iostream>
using namespace std;

int power(int num, int raise = 2) {
	int ans = 1;
	int i = 0;
	while (i < raise) {
		ans *= num;
		i++;
	}
	return ans;
}

int main() {
	int num, raise, ans;

	cout << "Enter The Base Value : ";
	cin >> num;

	cout << "Enter The Power : ";
	cin >> raise;

	cout << "Value Of Number When Raised By User Some Power : ";
	ans = power(num, raise);
	cout << ans << "\n\n";

	cout << "Value Of Number When Raised By 2 (Default Value): ";
	ans = power(num);
	cout << ans << "\n\n";
	return 0;
}

