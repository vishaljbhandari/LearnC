// gcc -Wall -Wextra -Werror -lstdc++ -lm external_friend_function.cpp
#include<iostream>
using namespace std;

//an external function friendly to more than one class

class Sample2;
//Forward declaration of class

class Sample1 {
	int a;
public:
	Sample1() {
		a = 10;
	}
	friend void Add(Sample1&, Sample2&); // This external function can access private member of the class Sample1
};

class Sample2 {
	int b;
public:
	Sample2() {
		b = 20;
	}
	friend void Add(Sample1&, Sample2&); // This external function can access private member of the class Sample1
};

void Add(Sample1 &S1, Sample2 &S2) {
	cout << "Addition of a & b : " << S1.a + S2.b << endl;
}

int main() {
	Sample1 S1;
	Sample2 S2;
	Add(S1, S2);
	return 0;
}
