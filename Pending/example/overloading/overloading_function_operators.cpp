#include <iostream>
using namespace std;

class Box {
public:
	Box(double length, double breadth, double height) :
			length(length), breadth(breadth), height(height) {
		cout << "Parameterized Constructor Call" << endl;
	}

	Box() {
		cout << "Default Constructor Call" << endl;
	}

	double getVolume(void) {
		return length * breadth * height;
	}
	void setLength(double length) {
		length = length;
	}
	void setBreadth(double breadth) {
		breadth = breadth;
	}
	void setHeight(double height) {
		height = height;
	}
	void printBox() {
		cout << "length: " << length << ", breadth: " << breadth << ", height: "
				<< height << endl;
	}

	// overload function call
	Box operator()(double length, double breadth, double height) {
		Box b;
		b.length = length;
		b.breadth = breadth;
		b.height = height;
		cout << "Overloaded Function Operator Call" << endl;
		return b;
	}

private:
	double length;      // Length of a box
	double breadth;     // Breadth of a box
	double height;      // Height of a box
};

int main() {
	Box b1(11.0, 10.0, 15.0), b2;

	cout << "First Distance : ";
	b1.printBox();

	b2 = b1(10.0, 10.0, 10.0); // invoke operator()
	cout << "Second Distance :";
	b2.printBox();

	return 0;
}
