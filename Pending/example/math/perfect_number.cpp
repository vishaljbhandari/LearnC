// g++ -Wall -Wextra -Werror check_perfect_number.cpp
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int number, x;
	printf("Enter The Number :");
	cin >> number;
	x = sqrt(number);
	if (x * x == number)
		cout << "The Number is Perfect Number.";
	else
		cout << "The Number is Not Perfect Number.";
	return 0;
}
