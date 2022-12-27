// gcc -lstdc++ -lm search.cpp

#include <iostream>
#include <algorithm>	// header for all STL algorithms
#include <vector>
using namespace std;

template<typename T>
bool is_odd(const T &n) {
	return ((n % 2) == 1);
}

template<typename T>
void display_vector(const T &v) {
	if (!v.size())
		return;
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;
}

/*
 * binary_search(begin_iterator_position, end_iterator_position, value_to_find)
 * begin_iterator_position, end_iterator_position are iterators pointing to positions inside container
 * Returns : iterator position of value in that container if an element equal to value_to_find is found, else end() of that container.
 */

int main() {
	// prime numbers < 100
	const vector<int> vector1 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
			47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	display_vector(vector1);
	int value = 41;
	auto it = find(vector1.begin(), vector1.end(), value);		// search from first element to last

	// it returns end of vector (vector1.end()), in case value is not found
	// vector1.end() is logically treated as false, can be searched with true or false
	if (it != vector1.end()) {
		size_t index = it - vector1.begin();	// Iterator arithmetic, just like pointer arithmetic
		cout << value << " found at index " << index << endl;
	} else {
		cout << value << " not found" << endl;
	}

	// other examples
	auto it1 = find(vector1.begin() + 1, vector1.end() - 5, value);		// search between 2nd element and 5th last element
	auto it2 = find(vector1.begin() + 1, vector1.begin() + 10, value);		// search between 2nd element and 10th  element
	auto it3 = find(vector1.end() - 10, vector1.end() - 5, value);		// search between 10th last element and 5th last element

	return 0;
}
