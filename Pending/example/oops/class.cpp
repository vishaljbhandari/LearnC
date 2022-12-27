// gcc -lstdc++ -lm class.cpp
#include <utility>
#include <iostream>
using namespace std;

class DemoRaii {
public:
	explicit DemoRaii(string name) :
			m_name(move(name)) {
		cout << "DemoRaii: " << m_name << endl;
	}

	~DemoRaii() {
		cout << "~DemoRaii: " << m_name << endl;
		cout << "~DemoRaii: " << m_resourceId << endl;
	}
	explicit DemoRaii(int resourceId) :
			m_resourceId(resourceId) {
		cout << "DemoRaii: " << m_resourceId << endl;
	}

private:
	string m_name;
	int m_resourceId;
};

class Box {
	int i1, *ip1;
	char c1, *cp1;
public:
	Box() {
		i1 = 1;
		c1 = '1';
		ip1 = &i1;
		cp1 = &c1;
	}
	void printBox() {
		cout << "i1 = " << i1 << endl;
		cout << "c1 = " << c1 << endl;
		cout << "ip1 = " << *ip1 << endl;
		cout << "cp1 = " << *cp1 << endl;
		cout << "sizeof(i1) = " << sizeof(i1) << endl;
		cout << "sizeof(c1) = " << sizeof(c1) << endl;
		cout << "sizeof(cp1) = " << sizeof(cp1) << endl;
		cout << "sizeof(ip1) = " << sizeof(ip1) << endl;
	}
};

int main() {
	try {
		cout << "Enter demo " << endl;
		DemoRaii dr1("alpha");
		DemoRaii dr2(5);
		throw runtime_error("Allocation Error!!!");
		cout << "Exit demo clean " << endl;
	} catch (exception &e) {
		cout << "Error: " << e.what() << endl;
	}

	Box b1;
	//Box b2();
	Box *b2 = new Box();
	b1.printBox();	// accessing members using class object with . operator
	b2->printBox(); // accessing members using class object pointer with => operator
	cout << "Size Of Box Class is " << sizeof(Box) << endl;
	cout << "Size Of Box Object is " << sizeof(b1) << endl;
	cout << "Size Of Box Object Pointer is " << sizeof(b2) << endl;		// Size = 4/8 bytes
	return 0;
}
