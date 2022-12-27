// gcc -lstdc++ -lm binary_search.cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
bool gtcomp(const T &lh, const T &rh) {
	return lh > rh;
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

/*	// binary_search prototype
 template <class ForwardIterator, class T>
 bool binary_search (ForwardIterator first, ForwardIterator last, const T& val);

 custom (2)
 template <class ForwardIterator, class T, class Compare>
 bool binary_search (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);

 */

int main() {
	int value = 47;

	// prime numbers < 100
	vector<int> v1 = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67, 11, 2,
			97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89 };
	display(v1);

	sort(v1.begin(), v1.end());
	display(v1);
	// array should be sorted
	cout << "searching for " << value << " in vector ... " << endl;
	if (binary_search(v1.begin(), v1.end(), value)) {
		cout << "found " << endl;
	} else {
		cout << "not found" << endl;
	}
	return 0;
}
