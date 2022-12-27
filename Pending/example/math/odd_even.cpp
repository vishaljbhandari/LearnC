// g++ -Wall -Wextra -Werror check_perfect_number.cpp
#include <iostream>
using namespace std;

int main() {
	int your_number = 20;

	if (your_number % 2 == 0)
		cout << "Your number " << your_number << " is even\n";
	else {
		cout << "Your number " << your_number << " is odd.\n";
	}
	cout << "That's all!\n";
	return 0;
}
