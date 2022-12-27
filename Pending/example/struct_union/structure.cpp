#include <iostream>
#include <cstdio>
using namespace std;

struct Point {
	int x;
	int y;
};

void DrawLine(Point start, Point end) {
	std::cout << start.x << std::endl;
	std::cout << start.y << std::endl;
	std::cout << end.x << std::endl;
	std::cout << end.y << std::endl;
}

void DrawLine(int x1, int y1, int x2, int y2) {
	Point start_point = { x1, y1 };
	Point end_point = { x2, y2 };
	DrawLine(start_point, end_point);
}

struct Employee {
	int id;
	const char *name;
	const char *role;
};

int main() {
	DrawLine(1, 2, 3, 4);
	Employee joe = { 42, "Joe", "Boss" };
	printf("%s is the %s and has id %d\n", joe.name, joe.role, joe.id);
	return 0;
}
