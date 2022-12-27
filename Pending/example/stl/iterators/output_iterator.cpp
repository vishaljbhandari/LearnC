// gcc -lstdc++ -lm output_iterator.cpp
#include <iostream>
#include <iterator>
using namespace std;

int main() {
	ostream_iterator<int> output(cout, " ");

	for (int i : { 3, 197, 42 }) {
		*output++ = i;
	}
	cout << endl;

	return 0;
}
