// gcc -lstdc++ -lm  range_base_for_loop.cpp
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv) {

	string rainbow[7];

	rainbow[0] = "red";
	rainbow[1] = "orange";
	rainbow[2] = "yellow";
	rainbow[3] = "green";
	rainbow[4] = "blue";
	rainbow[5] = "indigo";
	rainbow[6] = "violet";

	string rainbow2[] = { "red", "orange", "yellow", "green", "blue", "indigo",
			"violet" };

	cout << "Using for loop" << endl;
	for (int i = 0; i < 7; i++)
		cout << rainbow[i] << " ";
	cout << endl;

	cout << "Using range based loop" << endl;
	for (string s : rainbow2)
		cout << s << " ";
	cout << endl;

	int arr[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}

	for (const auto &x : arr) {

		cout << x << " ";
	}

	for (auto x : { 1, 2, 3, 4 }) {
		cout << x;
	}

	int ia[] = { 1, 2, 3, 4, 5 };
	for (auto i : ia) {
		printf("i is %d\n", i);
	}

	int ages[3];
	ages[1] = 18;
	ages[2] = 21;
	ages[3] = 35;

	int total(0);
	for (auto age : ages) {
		total += age;
	}
	cout << "Total = " << total << endl;

	return 0;
}
