// gcc -lstdc++ -lm  conditional.cpp
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
const bool is_prime(const T &num) {
	if (num <= 1)
		return false;
	bool primeflag = true;
	for (T l = 2; l < num; ++l) {
		if (num % l == 0) {
			primeflag = false;
			break;
		}
	}
	return primeflag;
}

template<typename T>
void display(const T &v) {
	if (!v.size())
		return;
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
	// prime numbers < 100
	const vector<int> v1 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
			47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	cout << "Content of vector" << endl;
	display(v1);
	cout << "checking prime number in the vector using all_of" << endl;
	if (all_of(v1.begin(), v1.end(), is_prime<int>)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	return 0;
}
