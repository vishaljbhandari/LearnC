#include <iostream>
#include <vector>		// Header file
#include <string>
#include <functional>
#include <algorithm>
#include <numeric>	// header for accumulate
using namespace std;

/*

 template < class T, class Alloc = allocator<T> > class vector; // generic template
 T is type of vector elements
 example -
 vector<int>    	integer vector
 vector<char> 	character vector
 vector<Car>		Car vector

 Member functions:
 (constructor) 		Construct vector (public member function )
 (destructor)		Vector destructor (public member function )
 operator=			Assign content (public member function )

 Iterators:
 begin			Return iterator to beginning (public member function )
 end 		    Return iterator to end (public member function )
 rbegin		    Return reverse iterator to reverse beginning (public member function )
 rend			Return reverse iterator to reverse end (public member function )

 above same iterators are available in const variant, using these iterators, user can not modify anything in vector
 cbegin			Return const_iterator to beginning (public member function )
 cend		    Return const_iterator to end (public member function )
 crbegin			Return const_reverse_iterator to reverse beginning (public member function )
 crend			Return const_reverse_iterator to reverse end (public member function )

 Capacity:
 size			Return size (public member function )
 max_size	    Return maximum size (public member function )
 resize		    Change size (public member function )
 capacity	    Return size of allocated storage capacity (public member function )
 empty		    Test whether vector is empty (public member function )
 reserve		    Request a change in capacity (public member function )
 shrink_to_fit   Shrink to fit (public member function )

 Element access:
 operator[]	    Access element (public member function )
 at			    Access element (public member function )
 front		    Access first element (public member function )
 back		    Access last element (public member function )
 data		    Access data (public member function )

 Modifiers:
 assign		    Assign vector content (public member function )
 push_back	    Add element at the end (public member function )
 pop_back	    Delete last element (public member function )
 insert		    Insert elements (public member function )
 erase		    Erase elements (public member function )
 swap			Swap content (public member function )
 clear		    Clear content (public member function )
 emplace		    Construct and insert element (public member function )
 emplace_back	Construct and insert element at the end (public member function )

 Allocator:
 get_allocator		Get allocator (public member function )

 Non-member function overloads
 relational operators	Relational operators for vector (function template )
 swap 				    Exchange contents of vectors (function template )

 Template specializations
 vector<bool>		    Vector of bool (class template specialization )


 */

enum class BattleCondition {
	red, yellow, green
};

void print_it(const int &n) {
	cout << "-" << n;
}

// print the element of the in vector
void print(const vector<int> &my_vector) {
	cout << "Vector content: {  ";
	for (const int &num : my_vector)
		cout << num << "  ";
	cout << "}\n\n";
}

// print the elements of the vector [template function]
template<typename T>
void print_vector(const vector<T> &v) {	// accepting vector as reference	// recieve as const as it will be used for print pupose only
	if (v.empty())					// empty() function of vector class
		return;
	for (const T &i : v) {// range based for loop	// type &ref_variable : range_object		// use only reference variable, else copy constructor will be called
		cout << i << " ";
	}
	cout << endl;
}

// print a simple message
void message(const char *s) {
	cout << s << endl;
}
void message(const char *s, const int n) {
	cout << s << ": " << n << endl;
}

void vector_use_with_lambda() {
	vector<int> int_vector { 3, 4, 2, 8, 15, 267 };
	for_each(int_vector.begin(), int_vector.end(),
			bind(&print_it, placeholders::_1));
	cout << endl;
	for_each(int_vector.begin(), int_vector.end(), [](const int &n) {
		cout << "-" << n;
	});
	cout << endl;

	auto myLambda = [](const int &n) {
		cout << "*" << n;
	};
	for_each(int_vector.begin(), int_vector.end(), myLambda);
	cout << endl;

	auto currentLight = BattleCondition::green;
	const auto shieldLevel = [&]() {
		switch (currentLight) {
		case BattleCondition::green:
			return 50;
		case BattleCondition::yellow:
			return 700;
		case BattleCondition::red:
		default:
			return 1000;
		}
	}();
	cout << "Current Shield Level = " << shieldLevel << endl;
}

void vector_map() {		// same can be used for other STL containers
	for (int item : { 9, 8, 7, 6, 5, 4 }) {
		cout << item << ' ';
	}
	cout << endl;

	vector < string > str_vector = { "one", "two", "three", "four", "five" };
	for (auto &str : str_vector) {
		cout << str << ' ';
	}
	cout << endl;

	int arr[] { 0, 1, 2, 3, 4, 5 };
	for (auto item : arr) {
		cout << item << ' ';
	}
	cout << endl;

	string str { "Modern C++" };
	for (auto character : str) {
		cout << character << ' ';
	}
	cout << endl;
}

void vector_collection() {
	auto header = [](string title) {
		cout << "---- " << title << " ----" << endl;
	};
	auto render = [](auto collection) {
		for (const auto &val : collection) {
			cout << val << endl;
		}
	};

	header("map");
	vector<int> inCollection { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	vector<int> outCollection;
	transform(inCollection.begin(), inCollection.end(),
			back_inserter(outCollection), [](const int &value) {
				return value * 3;
			});
	render(outCollection);

	header("filter");
	vector<int> filteredCollection;

	copy_if(outCollection.begin(), outCollection.end(),
			back_inserter(filteredCollection), [](int &value) {
				return value % 2 != 0;
			});
	render(filteredCollection);

	header("reduce");
	int results = std::accumulate(filteredCollection.begin(),
			filteredCollection.end(), 0, [](int total, int current) {
				return total + current;
			});
	cout << "results: " << results << endl;
}

void int_vector() {
	cout << "vector from initializer list: " << endl;
	vector<int> int_vector = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print_vector(int_vector);		// passing vector

	// info
	message("size", (int) int_vector.size());		// size() function of vector
	message("front elements ", int_vector.front());	// front() function of vector
	message("back elements ", int_vector.back());	// back() function of vector

	// index operations element at certain location/index
	message("element at 5", int_vector[5]);	// as subscript operator is implemented
	message("element at 5", int_vector.at(5));		// at as a vector function

	// insert
	message("insert 45 at begin:");
	int_vector.insert(int_vector.begin(), 45);		// insert function of vector
	print_vector(int_vector);

	message("insert 42 at begin + 5:");
	int_vector.insert(int_vector.begin() + 5, 42);
	print_vector(int_vector);

	// erase
	message("erase at begin + 5:");
	int_vector.erase(int_vector.begin() + 5);
	print_vector(int_vector);

	// push_back
	message("push back 47:");
	int_vector.push_back(47);
	print_vector(int_vector);

	// pop_back
	message("pop_back:");
	int_vector.pop_back();
	print_vector(int_vector);

	if (int_vector.empty()) {
		message("empty vector");
	}

	// empty
	message("emptying vector");
	while (!int_vector.empty()) {
		print_vector(int_vector);
		int_vector.pop_back();
	}
	print_vector(int_vector);

	// clear
	message("clearing vector");
	int_vector.clear();
	print_vector(int_vector);

	message("inserting from initializing list:");
	int_vector.insert(int_vector.begin(), { 1, 2, 3, 4, 5 });
	print_vector(int_vector);
	message("size :", (int) int_vector.size());
	message("clearing");
	int_vector.clear();
	message("size", (int) int_vector.size());
	print_vector(int_vector);

	// from C-array
	constexpr size_t arr_size = 10;
	int arr[arr_size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	message("vector created from a C-array taking ", arr_size);
	vector<int> copied_vector(arr, arr + arr_size);
	print_vector(copied_vector);
	message("copied_vector size", (int) copied_vector.size());

	cout << "{";
	for (vector<int>::iterator vect_itr = copied_vector.begin();
			vect_itr != copied_vector.end(); vect_itr++) {
		cout << *vect_itr << " " << endl;	// Displaying vector using iterator
	}
	cout << "} " << endl;

	cout << "{";
	for (int counter = 0; counter < 5; counter++) {
		cout << "[" << counter << "]" << copied_vector[counter] << "  ";// Displaying vector using subscript
	}
	cout << "} " << endl;

	cout << "{";		// range based auto for loop
	for (auto item : int_vector) {
		cout << item << ' ';
	}
	cout << "} printing vector using auto and range based loop" << endl;
}

void string_vector() {
	// filled with strings
	message("vector filled with string:");
	vector < string > str_vector(5, "string");
	print_vector (str_vector);

	// copy constructor
	message("vector copied from vector:");
	vector < string > str_vector_copied(str_vector);
	print_vector (str_vector_copied);

	// move constructor
	message("vector (str_vector_moved) moved from vector (str_vector):");
	message("size of str_vector", (int) str_vector.size());
	vector < string > str_vector_moved(move(str_vector));
	print_vector (str_vector_moved);
	message("size of str_vector", (int) str_vector.size());
	message("size of str_vector_moved", (int) str_vector_moved.size());
}

void vector_constructors() {
	// Create an empty vector
	vector<int> empty_vector;
	print_vector(empty_vector);

	int size = 3;
	// Create a vector of size with
	// all values as zero.
	vector<int> sized_null_vector(size);
	print_vector(sized_null_vector);

	vector<int> predefined_vector = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };// Initializing like array
	print_vector(predefined_vector);

	// Initializing from an array
	int array[] = { 10, 20, 30 };
	int array_elements_count = sizeof(array) / sizeof(array[0]);

	vector<int> vector_from_array(array, array + array_elements_count);	// creating vector from array, from first element to last element
	// array is first element address
	// array + array_elements_count is last element address
	print_vector(vector_from_array);

	// Initializing all elements with a particular value
	vector<int> same_value_vector(10);		// Size = 10
	int value = 5;
	fill(same_value_vector.begin(), same_value_vector.end(), value);// fill value to all elements starting from begin to end of vector
	print_vector(same_value_vector);

	size = 3;
	// Create a vector of size with
	// all values as 10.
	vector<int> sized_vector(size, 10);
	print_vector(sized_vector);
}

void vector_assignment() {// copying values of one vector into another (clearing old values first)

	std::vector<int> vector1(3, 1);
	std::vector<int> vector2(5, 2);
	cout << "Vector 1 " << endl;
	print_vector(vector1);
	cout << "Vector 1 " << endl;
	print_vector(vector2);
	vector2 = vector1;// vector2 values are cleared, and vector 1 values are copied into vector2
	print_vector(vector1);
	cout << "Vector 1 " << endl;
	print_vector(vector1);
	vector1 = std::vector<int>();
	print_vector(vector1);
	print_vector(vector2);

	std::cout << "Size of vector1: " << int(vector1.size()) << endl;
	std::cout << "Size of vector2: " << int(vector2.size()) << endl;
}

void vector_pointer() {
	std::vector<int> *vector_pointer = new std::vector<int>();
	vector_pointer->push_back(0);
	vector_pointer->push_back(12);
	vector_pointer->push_back(1);

	int twelve = vector_pointer->at(12);
	int two = (*vector_pointer)[2];

	// iterate it
	for (std::vector<int>::const_iterator cit = vector_pointer->begin();
			cit < vector_pointer->end(); ++cit) {
		int value = *cit;
	}

	// or, more perversely
	for (int index = 0; index < vector_pointer->size(); ++index) {
		cout << (*vector_pointer)[index] << endl;
	}

	// Or -- with C++ 11 support
	for (auto index : *vector_pointer) {
		cout << index << endl;
	}
}

int main() {
	vector_constructors();
	vector_assignment();
	int_vector();
	string_vector();
	vector_use_with_lambda();
	vector_collection();
	return 0;
}
