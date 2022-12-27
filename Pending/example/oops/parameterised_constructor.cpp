// gcc -Wall -Wextra -Werror -lstdc++ -lm parameterised_constructor.cpp

#include <iostream>
using namespace std;

class Point {
private:
	int x, y;

public:
	// Parameterized Constructors
	Point() {
		x = 10;
		y = 20;
	}
	Point(int x1) {
		x = x1;
		y = 20;
	}
	Point(int x1, int y1) {
		x = x1;
		y = y1;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

int main() {
	// Constructor called - 0 argumented
	// Point p1(); 	// Error ??
	Point p1;
	cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY() << endl;

	// Constructor called - 1 argumented
	Point p2(55);
	cout << "p2.x = " << p2.getX() << ", p2.y = " << p2.getY() << endl;

	// Constructor called - 2 argumented
	Point p3(55, 66);
	cout << "p3.x = " << p3.getX() << ", p3.y = " << p3.getY() << endl;

	return 0;
}
