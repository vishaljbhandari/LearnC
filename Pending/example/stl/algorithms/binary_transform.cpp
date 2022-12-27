// gcc -lstdc++ -lm binary_transform.cpp
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
class embiggen {
	T _accum = 1;
public:
	T operator()(const T &n1, const T &n2) {
		return _accum = n1 * n2 * _accum;
	}
};

template<typename T>
void display(vector<T> &v) {
	if (!v.size())
		return;
	for (T e : v) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
	vector<long> v1 = { 1, 2, 3, 4, 5 };
	vector<long> v2 = { 5, 10, 15, 20, 25 };
	vector<long> v3(v1.size(), 0);
	embiggen<long> fbig;

	cout << "Before Binary Transformation" << endl;
	cout << "content of vector 1" << endl;
	display(v1);
	cout << "content of vector 2" << endl;
	display(v2);
	cout << "content of vector 3" << endl;
	display(v3);
	cout << endl;

	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), fbig);

	cout << "After Binary Transformation" << endl;
	cout << "content of vector 1" << endl;
	display(v1);
	cout << "content of vector 2" << endl;
	display(v2);
	cout << "content of vector 3" << endl;
	display(v3);
	cout << endl;

	return 0;
}
