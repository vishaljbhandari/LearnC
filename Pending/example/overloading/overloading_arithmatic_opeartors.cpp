#include <iostream>
using namespace std;

class Box {
public:
	double getVolume(void) {
		return length * breadth * height;
	}
	void setLength(double len) {
		length = len;
	}
	void setBreadth(double bre) {
		breadth = bre;
	}
	void setHeight(double hei) {
		height = hei;
	}
	void printBox() {
		cout << "length: " << length << ", breadth: " << breadth << ", height: "
				<< height << endl;
	}

	Box(double length, double breadth, double height) :
			length(length), breadth(breadth), height(height) {
	}
	Box() {
	}

	// Overload + operator to add two Box objects.
	Box operator+(const Box &b) {
		Box box;
		box.length = this->length + b.length;
		box.breadth = this->breadth + b.breadth;
		box.height = this->height + b.height;
		return box;
	}

	// Overload - operator to subtract two Box objects.
	Box operator-(const Box &b) {
		Box box;
		box.length = this->length - b.length;
		box.breadth = this->breadth - b.breadth;
		box.height = this->height - b.height;
		return box;
	}

	// Overload * operator to multiply two Box objects.
	Box operator*(const Box &b) {
		Box box;
		box.length = this->length * b.length;
		box.breadth = this->breadth * b.breadth;
		box.height = this->height * b.height;
		return box;
	}

	// Overload / operator to divide two Box objects.
	Box operator/(const Box &b) {
		Box box;
		box.length = this->length / b.length;
		box.breadth = this->breadth / b.breadth;
		box.height = this->height / b.height;
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
	Box box2;                // Declare box2 of type Box
	double volume = 0.0;     // Store the volume of a box here

	// box 1 specification
	box1.setLength(16.0);
	box1.setBreadth(17.0);
	box1.setHeight(15.0);

	// box 2 specification
	box2.setLength(12.0);
	box2.setBreadth(13.0);
	box2.setHeight(10.0);

	// volume of box 1
	volume = box1.getVolume();
	cout << "Volume of box1 : " << volume << endl;

	// volume of box 2
	volume = box2.getVolume();
	cout << "Volume of box2 : " << volume << endl;

	cout << "box1 ";
	box1.printBox();
	cout << "box2 ";
	box2.printBox();

	// Add two object as follows:
	Box box3 = box1 + box2;
	cout << "Addition of box" << endl << "box3 = box1 + box2" << endl;
	cout << "box3 ";
	box3.printBox();

	// Subtract two object as follows:
	Box box4 = box1 - box2;
	cout << "Subtraction of box" << endl << "box4 = box1 - box2" << endl;
	cout << "box4 ";
	box4.printBox();

	// Multiply two object as follows:
	Box box5 = box1 * box2;
	cout << "Multiplication of box" << endl << "box5 = box1 * box2" << endl;
	cout << "box5 ";
	box5.printBox();

	// Divide two object as follows:
	Box box6 = box1 / box2;
	cout << "Division of box" << endl << "box6 = box1 / box2" << endl;
	cout << "box6 ";
	box6.printBox();

	// volume of box 3
	volume = box3.getVolume();
	cout << "Volume of box3 : " << volume << endl;

	return 0;
}
