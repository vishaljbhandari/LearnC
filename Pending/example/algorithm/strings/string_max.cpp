// g++ -Wall -Wextra -Werror string_max.cpp
#include <string>
#include <iostream>
using namespace std;
//
// Determines the maximum string using the ASCII collating sequence to 
// define rank.  A string is defined to be greater than another if the
// ASCII values of its characters are greater than the values of the other
// string.  For example,
//
// strngmax Alpha Beta Charlie
//
// would print Charlie to stdout and return 3.
//
int main(int argc, char *argv[]) {
	if (argc < 2) {
		cerr << "Usage:  strngmax string1 [string2 ...]\n";
		return 1;
	}

	string theGreatestString(argv[1]);
	int positionOfTheGreatestString = 1;
	int nextArg = 2;

	while (nextArg < argc) {
		string argListString(argv[nextArg++]);
		if (argListString > theGreatestString) {
			theGreatestString = argListString;
			positionOfTheGreatestString = nextArg - 1;
		}
	}

	cout << theGreatestString << endl;
	return positionOfTheGreatestString;
}
