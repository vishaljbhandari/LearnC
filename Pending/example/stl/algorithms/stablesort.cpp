// gcc -lstdc++ -lm  stablesort.cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
bool mycomp(const T &lh, const T &rh) {
	return int(lh) < int(rh);
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

/*
 Stability is mainly important when we have key value pairs with duplicate keys possible (like people names as keys and their details as values). And we wish to sort these objects by keys.

 What is it?
 A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input array to be sorted.

 To make stable sort, use comparators in sort function

 */

int main() {
	// prime numbers < 100
	vector<int> v1 = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67, 11, 2,
			97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89 };
	vector<double> v2 = { 3.07, 2.49, 3.73, 6.58, 3.3, 2.72, 3.44, 8.78, 9.23,
			4.09, 4.4, 1.65, 4.92, 0.42, 4.87, 5.03, 3.27, 7.29, 8.4, 6.12 };
	cout << "Array before sort" << endl;
	display(v2);

	vector<double> v3;

	v3 = v2;
	sort(v3.begin(), v3.end(), mycomp<double>);
	cout << "Array after sort" << endl;
	display(v3);

	cout << endl << "Array before sort" << endl;
	v3 = v2;
	display(v3);
	stable_sort(v3.begin(), v3.end(), mycomp<double>);
	cout << "Array after stable sort" << endl;
	display(v3);

	return 0;
}
