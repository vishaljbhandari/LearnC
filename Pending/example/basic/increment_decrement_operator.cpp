// gcc -lstdc++ -lm increment_decrement_operator.cpp
#include <iostream>
using namespace std;
/*
 Evaluating post and pre-increment together

 Precedence of postfix ++ is more than prefix ++ and their associativity is also different.
 Associativity of prefix ++ is right to left and associativity of postfix ++ is left to right.

 >> Associativity of postfix ++ is left to right
 >> Associativity of prefix ++ is right to left
 */

int main() {
	int val = 1;

	cout << "val is " << val++ << " and then post-incremented" << endl;
	cout << "val is now " << val << endl;
	cout << "val is pre-incremented to " << ++val << endl;

	return 0;
}
