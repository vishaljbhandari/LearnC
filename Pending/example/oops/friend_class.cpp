// gcc -Wall -Wextra -Werror -lstdc++ -lm friend_class.cpp
// A class friendly to another class
// A class(1) which is declared within another class(2) is friend of that class(2)
// then its objects(1's) can access all private members of that class(2)

#include<iostream>
using namespace std;

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
	friend Sample1;
	// Now Sample1 is friend of Sample2 class
	// whichever class is declared as friend, can access its private members
};

// as Sample1 is a friend class of Sample2, therefore, Sample1 can access private members of Sample2
void Sample1::Add(Sample2 &S2) {
	cout << "Addition of a & b : " << a + S2.b << endl;
}

int main() {
	Sample1 S1;
	Sample2 S2;
	S1.Add(S2);
	return 0;
}
