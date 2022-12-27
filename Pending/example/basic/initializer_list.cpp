#include <iostream>
#include <initializer_list>
#include <cassert>
using namespace std;
// gcc -Wall -Wextra -Werror -lstdc++ initializer_list.cpp

// 1) For initialization of non-static const data members
// 2) For initialization of reference members
// 3) For initialization of member objects which do not have default constructor
// 4) For initialization of base class members
// 5) When constructor’s parameter name is same as data member
// 6) For Performance reasons : It is better to initialize all class variables in Initializer List instead of assigning values inside body

class Bag {
	int arr[10];
	int m_Size { };
public:
	//Provides uniform initialization support for braced list of elements as arguments
	Bag(std::initializer_list<int> values) {
		assert(values.size() < 10);
		auto it = values.begin();
		while (it != values.end()) {
			Add(*it);
			++it;
		}
	}
	void Add(int value) {
		assert(m_Size < 10);
		arr[m_Size++] = value;
	}
	void Remove() {
		--m_Size;
	}
	int operator [](int index) {
		return arr[index];
	}
	int GetSize() const {
		return m_Size;
	}
};

void Print(std::initializer_list<int> values) {
	auto it = values.begin();
	while (it != values.end()) {
		std::cout << *it++ << " ";
	}
	for (auto x : values) {
		std::cout << x << " ";
	}
}

class Temp {
	int &t;
public:
	Temp(int &t) :
			t(t) {
	}  // Initializer list must be used For initialization of reference members
	   // Initializer list should be used, When constructor’s parameter name is same as data member
	int getT() {
		return t;
	}
};

class A {
	int i;
public:
	A(int);
};

A::A(int arg) {
	i = arg;
	cout << "A's Constructor called: Value of i: " << i << endl;
}

// Class B contains object of A
class B {
	A a;
public:
	B(int);
};

B::B(int x) :
		a(x) { //Initializer list must be used For initialization of member objects which do not have default constructor
	cout << "B's Constructor called";
}

class A1 {
	int i;
public:
	A1(int);
};

A1::A1(int arg) {
	i = arg;
	cout << "A1's Constructor called: Value of i: " << i << endl;
}

// Class B is derived from A1
class B1: A1 {
public:
	B1(int);
};

B1::B1(int x) :
		A1(x) { //Initializer list must be used For initialization of base class members
	cout << "B1's Constructor called" << endl;
}

class Test {
	const int t;
public:
	Test(int t) :
			t(t) {
	} // Initializer list must be used For initialization of non-static const data members
	int getT() {
		return t;
	}
};

int main() {
	// Initializing integer
	int x { 0 };
	cout << x << std::endl;
	;
	// Initializing float
	float y { 3.1f };
	cout << y << std::endl;
	;
	// Initializing integer array
	int arr[5] { 3, 1, 3, 8, 2 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	cout << std::endl;
	// Initializing string
	std::string s { "Hello C++" };
	cout << s << std::endl;

	// Initializing list of int
	std::initializer_list<int> data = { 1, 2, 3, 4 };
	Print(data);
	cout << std::endl;

	//Braced list of elements automatically creates an initializer_list object
	auto values = { 1, 2, 3, 4 };
	Print(values);
	Bag b { 3, 1, 8 };
	b.Add(3);
	b.Add(1);
	b.Add(8);
	for (int i = 0; i < b.GetSize(); ++i) {
		std::cout << b[i] << " ";
	}
	cout << std::endl;
	//Print({ 8,2,6,7 });
	for (auto x : { 8, 2, 6, 7 }) {
		std::cout << x << " ";
	}
	cout << std::endl;

	Test t1(10);
	cout << t1.getT();

	B obj(10);

	B1 obj1(10);
	return 0;
}
