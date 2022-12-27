//  gcc -lstdc++ -lm function_template.cpp
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Triangle {
	char *name;
	int sides;
public:
	Triangle() {
		strcpy(name, "Triangle");
	}
	char* get_name() {
		return name;
	}
};

class Rectangle {
	char *name;
	int sides;
public:
	Rectangle() {
		strcpy(name, "Rectangle");
	}
	char* get_name() {
		return name;
	}
};

class Square {
	char *name;
	int sides;
public:
	Square() {
		strcpy(name, "Square");
	}
	char* get_name() {
		return name;
	}
};

template<int number, class s_type>
class Shape {
	s_type my_shape;
	int count;
public:
	Shape() {
		count = number;
	}
	char* tell_me_shape(const char*);
};

template<int number, class s_type> char* Shape<number, s_type>::tell_me_shape(
		const char *t) {
	cout << t << ":" << count << endl;
	return my_shape.get_name();
}

/*
 template<typename T>
	 T maxof(T x, T y) {
	 return (x > y) ? x : y;
 }
 */

template<typename T>
T maxof(const T &a, const T &b) {
	return (a > b ? a : b);
}

template<typename T>
T const& Max(T const &a, T const &b) {
	return a < b ? b : a;
}



int main() {
	//Calling template function with template argument
	cout << maxof<int>(3, 7) << endl;  // Call maxof for int
	cout << maxof<double>(3.0, 7.0) << endl; // call maxof for double
	cout << maxof<char>('g', 'e') << endl;   // call maxof for char

	//Another way to call template function without specifying template arguments
	cout << maxof(3, 7) << endl;  // Call maxof for int
	cout << maxof(3.0, 7.0) << endl; // call maxof for double
	cout << maxof('g', 'e') << endl;   // call maxof for char

	int i = 39, j = 20;
	cout << "Max(i, j): " << Max(i, j) << endl;
	double f1 = 13.5, f2 = 20.7;
	cout << "Max(f1, f2): " << Max(f1, f2) << endl;

	int a = 7, b = 9;
	cout << "max is " << maxof<int>(a, b) << endl;
	cout << "max is " << maxof<int>(7, 9) << endl;

	Shape<4, Square> s_sq; // You can pass all arguments to template only when its object is created
	cout << s_sq.tell_me_shape("How Many Sides?") << endl;

	return 0;
}
