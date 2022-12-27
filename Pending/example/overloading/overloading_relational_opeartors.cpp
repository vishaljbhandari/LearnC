#include <iostream>
using namespace std;

class Box {
public:
	void setValue(int val) {
		value = val;
	}
	void printBox() {
		cout << "value: " << value << endl;
	}

	Box(int value) :
			value(value) {
	}

	Box() {
	}

	// Overload > operator to compare greater than
	bool operator>(const Box &box) {
		return value > box.value;
	}

	// Overload < operator to compare lesser than
	bool operator<(const Box &box) {
		return value < box.value;
	}

	// Overload == operator to compare equal to
	bool operator==(const Box &box) {
		return value == box.value;
	}

	// Overload >= operator to compare greater equal than
	bool operator>=(const Box &box) {
		return value >= box.value;
	}

	// Overload <= operator to compare lesser equal than
	bool operator<=(const Box &box) {
		return value <= box.value;
	}

private:
	int value;      	// value of a box
};

// Main function for the program
int main() {
	Box box1;                // Declare box1 of type Box
	Box box2;                // Declare box2 of type Box

	box1.setValue(5);
	box2.setValue(6);
	cout << "box1 ";
	box1.printBox();
	cout << "box2 ";
	box2.printBox();

	if (box1 > box2) {
		cout << "box1 is greater" << endl;
	} else {
		cout << "box2 is greater" << endl;
	}

	if (box1 < box2) {
		cout << "box1 is lesser" << endl;
	} else {
		cout << "box2 is lesser" << endl;
	}

	if (box1 == box2) {
		cout << "box1 and box2 are equal" << endl;
	} else {
		cout << "box1 and box2 are not equal" << endl;
	}

	if (box1 >= box2) {
		cout << "box1 is greater or equal" << endl;
	} else {
		cout << "box2 is greater or equal" << endl;
	}

	if (box1 <= box2) {
		cout << "box1 is lesser or equal" << endl;
	} else {
		cout << "box2 is lesser or equal" << endl;
	}

	return 0;
}
