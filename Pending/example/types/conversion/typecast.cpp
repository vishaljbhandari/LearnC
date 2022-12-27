// gcc -Wall -Wextra -Werror -lstdc++ -lm typecast.cpp
#include <iostream> 
using namespace std;

int main() {
	for (int x = 20; x < 120; x++) {
		cout << x << ". " << (char) x << " " << endl; // Casting of number x to character
	}
	cout << endl << endl;
	cout << static_cast<char>(65) << endl; // static cast of 65 as number into char
	int age = 35, pain_visits = 56;
	float visits_per_year = pain_visits / static_cast<float>(age);
	cout << visits_per_year << endl;
	visits_per_year = static_cast<float>(pain_visits) / age;
	cout << visits_per_year << endl;
	visits_per_year = pain_visits / age;
	cout << visits_per_year << endl;
	return 0;
}
