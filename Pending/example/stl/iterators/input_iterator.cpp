// gcc -lstdc++ -lm input_iterator.cpp
#include <iostream>
#include <iterator>
using namespace std;

void message(const char *m) {
	cout << m << endl;
}

int main() {
	double d1 = 0, d2 = 0;

	cout << "Two numeric values\n" << flush;
	cin.clear();
	istream_iterator<double> eos;        // default constructor is end-of-stream
	istream_iterator<double> iit(cin);    // stdin iterator

	if (iit == eos) {
		message("no values");
		return 0;
	} else {
		d1 = *iit++;
	}

	if (iit == eos) {
		message("no second value");
		return 0;
	} else {
		d2 = *iit;
	}

	cin.clear();
	cout << d1 << " * " << d2 << " = " << d1 * d2 << endl;

	return 0;
}
