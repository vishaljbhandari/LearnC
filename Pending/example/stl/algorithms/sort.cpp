// gcc -lstdc++ -lm sort.cpp
#include <iostream>
#include <algorithm>	// header for all STL algorithms
#include <vector>
using namespace std;

template<typename T>
bool mycomp(const T &lh, const T &rh) {
	return lh < rh;
}

template<typename T>
void display_vector(const T &vector_obj) {
	if (!vector_obj.size())
		return;
	for (auto element : vector_obj) {
		cout << element << " ";
	}
	cout << endl;
}

/*
 // sort function prototype

 default (1)	// Ascending sort
 template <class RandomAccessIterator>
 void sort (RandomAccessIterator first, RandomAccessIterator last);

 custom (2)		// For Descending sort, change the Compare
 template <class RandomAccessIterator, class Compare>
 void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
 */

bool comparatorAscending (int i,int j) { return (i<j); }
bool comparatorDescending (int i,int j) { return (i>j); }

int main() {
	// prime numbers < 100
	vector<int> vector1 = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67, 11,
			2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89 };
	vector<double> vector2 =
			{ 3.07, 2.49, 3.73, 6.58, 3.3, 2.72, 3.44, 8.78, 9.23, 4.09, 4.4,
					1.65, 4.92, 0.42, 4.87, 5.03, 3.27, 7.29, 8.4, 6.12 };
	cout << "Array" << endl;
	display_vector(vector1);
	// template <class RandomAccessIterator> void sort (RandomAccessIterator first, RandomAccessIterator last);
	sort(vector1.begin(), vector1.end());		// sort from begin to end of vector
	// sort(vector1.begin() + 1, vector1.end() - 5);		// sort from 2nd element to 5th last element only
	// sort(vector1.begin() + 1, vector1.begin() + 10);		// sort from 2nd element to 10th  element only
	// sort(vector1.end() - 10, vector1.end() - 5);		// sort from 10th last element to 5th last element only
	cout << "Sorted Array - Ascending" << endl;
	display_vector(vector1);

	// Descending sort
	// template <class RandomAccessIterator> void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
	sort(vector1.begin(), vector1.end(), comparatorDescending);		// sort from begin to end of vector
	cout << "Sorted Array - Descending" << endl;
	display_vector(vector1);

	cout << "Array" << endl;
	display_vector(vector2);
	//  template <class RandomAccessIterator> void sort (RandomAccessIterator first, RandomAccessIterator last);
	sort(vector2.begin(), vector2.end());
	cout << "Sorted Array" << endl;
	display_vector(vector2);

	return 0;
}
