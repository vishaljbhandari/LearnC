// gcc -lm -lstdc++ sort.cpp

#include <bits/stdc++.h>
#include <boost/algorithm/cxx11/is_sorted.hpp>
using namespace std;

int main() {

	int seq3[] = { 1, 2, 6, 8 };

	if (boost::algorithm::is_sorted(seq3))
		cout << "sorted" << endl;
	else
		cout << "not sorted" << endl;

	int seq4[] = { 1, 2, 6, 8, 5, 4, 2, 8 };

	if (boost::algorithm::is_sorted(seq4, seq4 + 3))
		cout << "sorted till 3rd index" << endl;
	else
		cout << "not sorted till 3rd index" << endl;

	return 0;
}
