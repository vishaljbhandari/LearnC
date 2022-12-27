// gcc -lstdc++ -lm stl_pair.cpp
#include <iostream>
#include <utility>
#include <string>
using namespace std;

/*
 * pair type - a simple container to store two data
 * Header -> <utility>
 * Consisting of two data elements or homogeneous/heterogeneous(may be of different type) objects as a single unit
 *
 * the order is fixed (first, second).
 * First Element -> .first
 * Second Element -> .second
 *
 * with Pair object p_obj -> p_obj.first, p_obj.second to access elements of paid object
 * these pair objects can be assigned, copied, passed and compared ..
 *
 * array objects allocated in map or hash_map are of type "pair" by default
 *
 *  can be used to store key value pairs
 */

// print the pair
template<typename T1, typename T2>
void print_pair(const pair<T1, T2> &pair_obj) {	// pair object is passed a const reference
	cout << pair_obj.first << " : " << pair_obj.second << endl;	// first and second elements of pair object
}

// print a simple message
void message(const char *s) {
	cout << s << endl;
}

void message(const char *s, const int n) {
	cout << s << ": " << n << endl;
}

/*
 * make_pair() : This template function allows to create a value pair without writing the types explicitly.
 * operators(=, ==, !=, >=, <=) : We can use operators with pairs as well.
 * swap : This function swaps the contents of one pair object with the contents of another pair object. The pairs must be of same type.
 *
 */

int main() {
	// initializer list
	message("pair p1 using initializer list");
	pair<int, string> p1 = { 47, "forty-seven" };// pair type is "pair<int, string>
	print_pair(p1);
	cout << endl;

	// default constructor
	message("pair p2 using default constructor");
	pair<int, string> p2(72, "seventy-two");
	print_pair(p2);
	cout << endl;

	// from make_pair
	message("pair p3 using make_pair");
	pair<int, string> p3 = make_pair(7, "seven");// used to create pair object values or initialize pair object
	print_pair(p3);
	cout << endl;

	// printing pair object elements
	// directly use pair_object.first and pair_object.second
	cout << "First Element " << p3.first << endl;
	cout << "Second Element " << p3.second << endl;
	string str = p3.second;
	int i = p3.first;

	// updating pair object
	// directly use pair_object.first = value and pair_object.second = value with respective values
	p3.first = 48;
	p3.second = "Hello";

	// swapping pairs
	p1.swap(p2);		// both pairs should be of same types for swapping

	pair<int, string> p4(1, "AAA");
	print_pair(p4);
	// pair<string, int> p5("BBB", 2);
	pair<int, string> p5(2, "BBB");
	print_pair(p5);
	cout << "SWAPPING " << endl;
	p4.swap(p5);
	print_pair(p4);
	print_pair(p5);

	// comparison operators		// these operators are overloaded inside pair class
	// for any comparison of pairs, both pairs must be of same type
	message("p1 == p2", p1 == p2);
	message("p1 < p2", p1 < p2);
	message("p1 < p3", p1 < p3);
	message("p1 > p2", p1 > p2);
	message("p2 > p3", p2 > p3);

	return 0;
}
