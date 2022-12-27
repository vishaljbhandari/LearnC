// gcc -lm -lstdc++ equal.cpp

#include <bits/stdc++.h>
#include <boost/algorithm/cxx14/equal.hpp>
using namespace std;

/*
 The equal() function in C++ boost library
 ‘boost/algorithm/cxx11/equal.hpp’
 tests to see if two sequences contain equal values.
 It returns a boolean value which determines if both the sequences are same or not.


 Syntax:
 bool equal ( InputIterator1 first1, InputIterator1 second1,
 InputIterator2 first2, InputIterator2 second2 )
 or
 bool equal ( InputIterator1 first1, InputIterator1 second1,
 InputIterator2 first2, InputIterator2 second2,
 BinaryPredicate pred )


 first1: It specifies the input iterators to the initial positions in the first sequence.
 second1: It specifies the input iterators to the final positions in the first sequence.
 first2: It specifies the input iterators to the initial positions in the second sequence.
 second2: It specifies the input iterators to the final positions in the second sequence.
 p: It specifies the comparison predicate if specified.
 Return Value: The function returns true if both the sequence are same, else it returns false.
 */

int main() {

	int seq1[] = { 1, 2, 5, 6, 8 };

	int seq2[] = { 1, 2, 5, 6, 8 };

	if (ans = boost::algorithm::equal(seq1, seq1 + 5, seq2, seq1 + 5))
		cout << "Sequence1 and Sequence2 are equal" << endl;
	else
		cout << "Sequence1 and Sequence2 are not equal" << endl;

	if (boost::algorithm::equal(seq1, seq1 + 5, seq2, seq2 + 5))
		cout << "Sequence1 and Sequence2 are equal" << endl;
	else
		cout << "Sequence1 and Sequence2 are not equal" << endl;

	return 0;
}
