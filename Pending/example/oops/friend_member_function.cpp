// gcc -Wall -Wextra -Werror -lstdc++ -lm friend_member_function.cpp
#include<iostream>
using namespace std;

//a member function friendly to another class

class Sample2;
//Forward declaration of class

class Sample1 {
	int a;
public:
	Sample1() {
		a = 10;
	}
	void Add(Sample2&);

};

class Sample2 {
	int b;
public:
	Sample2() {
		b = 20;
	}
	friend void Sample1::Add(Sample2&);	// This function of class Sample1 can use private members of the class Sample2
};

void Sample1::Add(Sample2 &S2) {
	cout << "Addition of a & b : " << a + S2.b << endl;
}

int main() {
	Sample1 S1;
	Sample2 S2;
	S1.Add(S2);
	return 0;
}
