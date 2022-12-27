// g++ -Wall -Wextra -Werror check_perfect_number.cpp
#include <iostream> 
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	int dice = 0;
	//seed the random number generator
	srand(time(0));

	dice = (rand() % 6) + 1;
	cout << "You rolled a " << dice << endl;

	return 0;
}
