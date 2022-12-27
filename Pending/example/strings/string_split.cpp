// gcc -Wall -Wextra -Werror -lstdc++ -lm string_split.cc
#include <iostream>
#include <string>
using namespace std;

int main() {
	string cmd = "HELLO WORLD";
	string arg;

	string::size_type pos = cmd.find(' ');
	if (cmd.npos != pos) {
		arg = cmd.substr(pos + 1);
		cmd = cmd.substr(0, pos);
	}

	cout << cmd << endl;
	cout << arg << endl;

	return 0;
}
