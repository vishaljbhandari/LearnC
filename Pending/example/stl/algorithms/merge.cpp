// gcc -lstdc++ -lm merge.cpp

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// compare for reverse sort
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

int main() {
	vector<int> v1 = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67 };
	vector<int> v2 = { 2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89, 11 };
	vector<int> v3(v1.size() + v2.size());
	display(v1);
	display(v2);
	cout << endl;

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	display(v1);
	display(v2);
	cout << endl;

	/*		// merger function prototype
	 template<class InputIterator1, class InputIterator2, class OutputIterator>
	 OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
	 InputIterator2 first2, InputIterator2 last2, OutputIterator result);
	 template<class InputIterator1, class InputIterator2, class OutputIterator,
	 class Compare>

	 OutputIterator merge(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare comp);
	 */

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	display(v3);

	return 0;
}
