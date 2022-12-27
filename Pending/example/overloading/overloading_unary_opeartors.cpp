#include <iostream>
using namespace std;

class Box {
public:
	Box(double length, double breadth, double height) :
			length(length), breadth(breadth), height(height) {
	}
	Box() {
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

	// Overload unary - operator to negate a Box object.
	Box operator-() {
		Box box;
		box.length = -length;
		box.breadth = -breadth;
		box.height = -height;
		return box;
	}

	Box operator!() {
		Box box;
		box.length = !length;
		box.breadth = !breadth;
		box.height = !height;
		return box;
	}

	// Prefix incremental operator
	Box operator++() {
		Box box;
		box.length = ++length;
		box.breadth = ++breadth;
		box.height = ++height;
		return box;
	}

	// Postfix incremental operator
	Box operator++(int) {
		Box box(length, breadth, height);
		++length;
		++breadth;
		++height;
		return box;
	}

	// Prefix decrement operator
	Box operator--() {
		Box box;
		box.length = --length;
		box.breadth = --breadth;
		box.height = --height;
		return box;
	}

	// Postfix decrement operator
	Box operator--(int) {
		Box box(length, breadth, height);
		--length;
		--breadth;
		--height;
		return box;
	}

private:
	double length;      // Length of a box
	double breadth;     // Breadth of a box
	double height;      // Height of a box
};

// Main function for the program
int main() {
	Box box1;                // Declare box1 of type Box

	double volume = 0.0;     // Store the volume of a box here

	// box 1 specification
	box1.setLength(16.0);
	box1.setBreadth(17.0);
	box1.setHeight(15.0);

	// volume of box 1
	volume = box1.getVolume();
	cout << "Volume of box1 : " << volume << endl;
	cout << "box1 ";
	box1.printBox();

	// Negating Box object as follows:
	Box box2 = -box1;
	cout << "Negation of box2" << endl << "box2 = -box1" << endl;
	cout << "box2 ";
	box2.printBox();

	// box 1 specification
	box1.setLength(1);
	box1.setBreadth(0);
	box1.setHeight(1);
	cout << "box1 ";
	box1.printBox();

	// Inverting Box object as follows:
	box2 = !box1;
	cout << "Inverting of box1" << endl << "box2 = !box1" << endl;
	cout << "box2 ";
	box2.printBox();

	cout << endl;

	// Pre Incremental Operator
	Box box3 = ++box1;
	cout << "Prefix Increment of box1" << endl << "box3 = box1" << endl;
	cout << "box3 ";
	box3.printBox();
	cout << "box1 ";
	box1.printBox();

	// Post Incremental Operator
	Box box4 = box1++;
	cout << "Postfix Increment of box1" << endl << "box4 = box1++" << endl;
	cout << "box4 ";
	box4.printBox();
	cout << "box1 ";
	box1.printBox();

	// Pre Decrement Operator
	Box box5 = --box1;
	cout << "Prefix Increment of box1" << endl << "box5 = --box1" << endl;
	cout << "box5 ";
	box5.printBox();
	cout << "box1 ";
	box1.printBox();

	// Post Decrement Operator
	Box box6 = box1--;
	cout << "Postfix Increment of box1" << endl << "box6 = box1--" << endl;
	cout << "box6 ";
	box6.printBox();
	cout << "box1 ";
	box1.printBox();

	return 0;
}
