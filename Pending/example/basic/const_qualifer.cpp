// gcc -lstdc++ -lm  const_qualifer.cpp

#include <iostream>
using namespace std;

void Print(int *ptr) {
	using namespace std;
	cout << *ptr << endl;
}

void PrintRef(const int &ref) {
	using namespace std;
	cout << ref << endl;
}

int main() {
	using namespace std;
	float radius = 0;
	cin >> radius;
	const float PI = 3.14159f;
	float area = PI * radius * radius;
	float circumference = PI * 2 * radius;
	cout << "Area is : " << area << endl;
	cout << "Circumference is : " << circumference << endl;

	const int CHUNK_SIZE = 512;
	const int *const ptr = &CHUNK_SIZE;
	//*ptr = 1;
	int x = 10;
	//ptr = &x;
	//*ptr = 1;
	Print(&x);
	cout << "main->x" << x << endl;

	x = 5;
	PrintRef(1);

	return 0;
}
