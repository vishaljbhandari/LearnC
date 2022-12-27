// gcc -lstdc++ -lm range_based_iterator.cpp
#include <iostream>
#include <vector>
using namespace std;

void message(const char *m) {
	cout << m << endl;
}
void message(const char *m, int i) {
	cout << m << ": " << i << endl;
}

int main() {
	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int>::iterator it1;   // iterator object

	// iterate forward
	for (it1 = v1.begin(); it1 != v1.end(); ++it1) {
		cout << *it1 << " ";
	}
	cout << endl;

	// iterate backward
	for (it1 = v1.end(); it1 != v1.begin();) {
		cout << *--it1 << " ";
	}
	cout << endl;

	// range-based for loop
	for (int i : v1) {
		cout << i << " ";
	}
	cout << endl;

	it1 = v1.begin() + 5;
	message("element begin + 5", *it1);
	message("element [5]", v1[5]);

	it1 = v1.end() - 3;
	message("element end - 3", *it1);

	return 0;
}
