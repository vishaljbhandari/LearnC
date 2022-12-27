// gcc -lstdc++ -lm shape.cpp
#include<iostream>
using namespace std;

class Shape {
public:
	void Draw() {
		cout << "Draw of Shape" << endl;
	}
};

class Rectangle: public Shape {
public:
	void Draw() {
		cout << "Draw of Rectangle" << endl;
	}
};

class Circle: public Shape {
public:
	void Draw() {
		cout << "Draw of Circle" << endl;
	}
};

class Polygon: public Shape {
public:
	void Draw() {
		cout << "Draw of Polygon" << endl;
	}
};

int main() {
	int n = 3;
	Shape **sp;
	int *choice;
	sp = new Shape*[n];
	choice = new int[n];
	choice[0] = 0;
	choice[1] = 1;
	choice[2] = 2;

	for (int i = 0; i < n; i++) {
		switch (choice[i]) {
		case 0:
			sp[i] = new Rectangle;
			((Rectangle*) sp[i])->Draw();
			break;
		case 1:
			sp[i] = new Circle;
			((Circle*) sp[i])->Draw();
			break;
		case 2:
			sp[i] = new Polygon;
			((Polygon*) sp[i])->Draw();
			break;
		}

	}

	return 0;
}
