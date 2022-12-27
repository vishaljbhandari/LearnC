// gcc -lstdc++ -lm stl_tuple.cpp
#include <iostream>
#include <tuple>
#include <string>
using namespace std;

// A tuple is an object/collection that can hold a number of elements.
// The elements can be of different data types.
// The elements of tuples are initialized as arguments in order in which they will be accessed. 1,2,3, . . . .
// Can be used to store a record of data base or file system

// print the elements of the tuple
template<typename T>
void print3tuple(T &tpl) {		// Receiving tuple object as const reference
	// decltype(tpl) -> data_type
	// tuple_size<decltype(tpl)>  -> size of that tuple type
	// tuple_size<decltype(tpl)>:: value	-> size of that tuple type, value part
	cout << tuple_size<decltype(tpl)>::value << endl;
	//auto tsize = tuple_size<decltype(tpl)>::value;		// tuple_size<decltype(tpl)> gives total number of elements in tuple object
	//for (int index = 0; index < tsize ; index++)
	//	cout << (get<index>(tpl)) << " ";
	cout << endl;
}

// print a simple message
void message(const char *s) {
	cout << s << endl;
}

void message(const char *s, const int n) {
	cout << s << ": " << n << endl;
}

int main() {
	// initializer list
	message("tuple tuple1 using initializer list");
	tuple<int, string, int> tuple1 = { 47, "forty-seven", 1 };
	// type of this tuple is  tuple<int, string, int>
	// object is tuple1
	// values inside this tuple object are 1) 47, 2) forty-seven, 3) 1
	print3tuple(tuple1);	// passing tuple object to a function
	cout << endl;

	// default constructor
	message("tuple tuple2 using default constructor");
	tuple<int, string, int> tuple2(72, "seventy-two", 2);
	// type of this tuple is  tuple<int, string, int>
	// object is tuple2
	// values inside this tuple object are 1) 72, 2) forty-two, 3) 2
	print3tuple(tuple2);
	cout << endl;

	/*
	1. get() :- get() is used to access the tuple values and modify them, it accepts the index and tuple name as arguments to access a particular tuple element.

	2. make_tuple() :- make_tuple() is used to assign tuple with values. The values passed should be in order with the values declared in tuple.
	pass three values to this function and this will return a tuple

	3. tuple_size :- It returns the number of elements present in the tuple.

	4. swap() :- The swap(), swaps the elements of the two different tuples.

	5. tie() :- The work of tie() is to unpack the tuple values into separate variables.
	There are two variants of tie(), with and without “ignore” , the “ignore” ignores a particular tuple element and stops it from getting unpacked.

	6. tuple_cat() :- This function concatenates two tuples and returns a new tuple.
	*/

	// make_tuple
	message("tuple tuple3 using make_tuple");
	// &tuple make_tuple(type_1_variable, type_2_variable, type_3_variable)
	auto tuple3 = make_tuple(7, "seven", 3);
	// using auto that we don't know which type tuple is to create
	print3tuple(tuple3);
	cout << endl;

	// Printing tuple values
	cout << "Printing first value of tuple3 - " << get<0>(tuple3) << endl;		// get<index_number>(tuple_object)	// index number 0, 1, 2 for 1st, 2nd and 3rd values
	cout << "Printing second value of tuple3 - " << get<1>(tuple3) << endl;		// get<index_number>(tuple_object)	// index number 0, 1, 2 for 1st, 2nd and 3rd values
	cout << "Printing third value of tuple3 - " << get<2>(tuple3) << endl;		// get<index_number>(tuple_object)	// index number 0, 1, 2 for 1st, 2nd and 3rd values

	// Setting tuple values
	get<0>(tuple1) = 7;		// you can set similar type values only. as tuple1 first element is integer, so only integer
	get<1>(tuple2) = "changed";		// as tuple2 second element is string, so only string
	get<2>(tuple1) = 45;

	// tuple_size - getting number of elements inside the tuple object
	cout << "Tuple size of tuple1 " << tuple_size<decltype(tuple1)>::value << endl;


	print3tuple(tuple1);
	print3tuple(tuple2);
	print3tuple(tuple3);

	// comparison operators, overloaded in class
	message("tuple1 == tuple2", tuple1 == tuple2);
	message("tuple1 < tuple2", tuple1 < tuple2);
	message("tuple1 < tuple3", tuple1 < tuple3);
	message("tuple1 > tuple2", tuple1 > tuple2);
	message("tuple2 > tuple3", tuple2 > tuple3);

	return 0;
}
