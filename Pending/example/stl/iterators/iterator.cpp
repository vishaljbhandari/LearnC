#include <iostream>
#include <vector>
using namespace std;

// Iterators are pointer like objects
// Used to access elements by their positions
// As there are objects of a class, they are overloaded with many operators like ++, --, * etc

int main() {
	// from initializer list (C++11)
	cout << "vector from initializer list (C++11): " << endl;
	vector<int> vi = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };			// int vector to be accessed
	vector<int>::iterator it;	// vector iterator object		// declaring iterator of same type to access integer vector
	
	// iterators are usually initialized with .begin() or .end() functions

	vector<int>::iterator it_begin = vi.begin();		// gives first position
	vector<int>::iterator it_end = vi.end();			// gives last position beyond last element

	// iterator given by .begin() function can be dereferenced as it holds first position element.
	// iterator given by .end() function can not be dereferenced as it does not hold any element, it holds a end of container(an imaginary position) not last position of container.

	cout << *it_begin << endl; 	// prints first value
	cout << *it_end << endl;	// error, as it_end does not hold any element

	// .end() iterator value is also used to check failure of many algorithms.

	vector<int>::iterator beginning = vi.begin(); // save for later

	cout << "printing vector using iterator" << endl;			// forward iterator
	for (it = vi.begin(); it < vi.end(); it++) {		// for loop		// ++ operator is overloaded to increment value pointed by iterator
		cout << *it << " ";					// * operator is overloaded to extract/dereference value pointed by iterator
	}
	cout << endl;

	// forward iterator allows re-iteration of same set with same results
	// use beginning value saved before previous iteration
	cout << "printing vector using forward iterator" << endl;
	for (it = beginning; it < vi.end(); it++) {		// do not use <= with end iterator, as end iterator can not be dereferenced (*it) later in loop body.
		cout << *it << " ";
	}
	cout << endl;

	// bidirectional iterator -- iterate backwards
	// allows it--
	for (it -= 1; it >= beginning; it--) {		// -- operator is overloaded to decrement value pointed by iterator
		cout << *it << " ";
	}
	cout << endl;

	// output iterator
	// may write to object via iterator
	for (it = beginning; it < vi.end(); it++) {
		*it = 0;				// writing to element using derefencing of iterator, element at position held by iterator will be updated with value
		// it = 0; 	// you can not modify iterator just like pointers. You can only modify values at position held be iterator
	}
	for (it = beginning; it < vi.end(); it++) {
		cout << *it << " ";
	}

	// random access iterator // jumping to any position // No sequential access, one by one using iterator
	// random access iterator are returned from only those containers which allows random access
	// allows += and -= access
	it = beginning + 7;
	cout << *it << " ";
	it -= 3;
	cout << *it << " ";
	it += 4;
	cout << *it << " ";
	cout << endl;

	return 0;
}
