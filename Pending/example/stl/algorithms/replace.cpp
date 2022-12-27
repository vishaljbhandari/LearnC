// gcc -lstdc++ -lm replace.cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
void display(const T &v) {
	if (!v.size())
		return;
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;
}

/*	// replace function prototype

 template<class ForwardIterator, class T> void replace(ForwardIterator first, ForwardIterator last, const T &old_value, const T &new_value);

 >> Parameters
 first, last : Forward iterators to the initial and final positions in a sequence of elements that support being compared and assigned a value of type T. The range used is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.
 old_value : Value to be replaced.
 new_value : Replacement value.

 >> Return value : none

 */

int main() {
	// prime numbers < 100
	vector<int> v1 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
			53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	cout << "Vector contents" << endl;
	display(v1);
	int find_value = 47, replace_value = 99;
	// start and end iterator range cane be anything with in the container
	replace(v1.begin(), v1.end(), find_value, replace_value);	// search from start to end and replace value if found

	cout << find_value << " is replaced with " << replace_value << endl;
	cout << "Vector contents" << endl;
	display(v1);

	// other examples
	replace(v1.begin()+2, v1.end(), find_value, replace_value);	// search from 3rd element to end element and replace value if found
	replace(v1.begin()+7, v1.end()-5, find_value, replace_value);	// search from 8th element to 6th last element and replace value if found
	replace(v1.end() - 5, v1.end()-1, find_value, replace_value);	// search from 6th end element to 2nd last element and replace value if found

	return 0;
}
