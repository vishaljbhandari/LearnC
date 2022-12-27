// gcc -Wall -Wextra -Werror -lstdc++ -lm friend_external_function.cpp
#include<iostream>
using namespace std;

//an external function friendly to a class

class Sample {
	int a, b;
public:
	Sample() {
		a = 10;
		b = 20;
	}
	friend void Add(Sample&); // This external function can access private member of the class Sample
};

void Add(Sample &S) {
	cout << "Addition of a & b : " << S.a + S.b << endl;
}

int main() {
	Sample S;
	Add(S);
	return 0;
}
