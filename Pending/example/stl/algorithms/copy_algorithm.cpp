// gcc -lstdc++ -lm copy_algorithm.cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
void disp_vector(const T &vctr) {
	if (!vctr.size())
		return;
	for (auto element : vctr) {
		cout << element << " ";
	}
	cout << endl;
}

int main() {
	// prime numbers < 100
	vector<int> vector1 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
			53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	vector<int> vector2(vector1.size(), 0); // initialize all element with zero or zero fill for v1.size() times, equal size vector
	vector<int> vector3(vector1.size() - 5, 0); // initialize all element with zero or zero fill for v1.size() - 5 times, this smaller vector
	disp_vector(vector1);
	disp_vector(vector2);
	disp_vector(vector3);

	/*	copy function prototype

	 template<class InputIterator, class OutputIterator> OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result);
	 */

	copy(vector1.begin(), vector1.end(), vector2.begin());	// this will copy only elements in available space of destination vector // both size same, so all elements will be copied
	copy(vector1.begin(), vector1.end(), vector3.begin());	// this will copy only elements in available space of destination vector // destination vector is smaller, so less elements will get copied

	disp_vector(vector2);
	disp_vector(vector3);

	// other examples
	vector<int> vector4(vector1.size(), 0);
	copy(vector1.begin() + 2, vector1.end() - 5, vector4.begin() + 4);		// copy from 3rd element to 6th last element of vector 1 into vector 3 starting from 5th position in destination vector 4
	disp_vector(vector4);

	return 0;
}
