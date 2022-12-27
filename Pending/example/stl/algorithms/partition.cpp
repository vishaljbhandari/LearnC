// gcc -lstdc++ -lm partition.cpp
#include<iostream>
#include<algorithm> // for partition algorithm
#include<vector> // for vector
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

/*

 template<class ForwardIterator, class UnaryPredicate> ForwardIterator partition(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);

 */

int main() {
	// Initializing vector
	vector<int> vectorList = { 2, 1, 5, 6, 8, 7 };
	cout << "Vector before partitioning" << endl;
	display(vectorList);

	// Checking if vector is partitioned
	// using is_partitioned()
	is_partitioned(vectorList.begin(), vectorList.end(), [](int x) {
		return x % 2 == 0;
	}) ? cout << "Vector is partitioned" : cout << "Vector is not partitioned";
	cout << endl << endl;

	// partitioning vector using partition()
	partition(vectorList.begin(), vectorList.end(), [](int x) {
		return x % 2 == 0;
	});
	cout << "Vector is partitioned" << endl << endl;

	// Checking if vector is partitioned
	// using is_partitioned()
	is_partitioned(vectorList.begin(), vectorList.end(), [](int x) {
		return x % 2 == 0;
	})? cout << "Now, vector is partitioned after partition operation" : cout
				<< "Vector is still not partitioned after partition operation";
	cout << endl;

	// Displaying partitioned Vector
	cout << "Vector after partitioning" << endl;
	display(vectorList);

	return 0;
}
