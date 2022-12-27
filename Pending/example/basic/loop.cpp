// g++ loop.cpp
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	cout << "All c loops are directly inherited into c++ by default" << endl
			<< endl;

	cout << "Reading Command Line Arguments" << endl;
	for (int i = 0; argv[i]; i++) {
		cout << i << " - " << argv[i] << endl;
	}

	// in c++ loop counter variables can be declared within for statement
	for (int i = 1; i <= 10; i++) {
		cout << "Hello World" << endl;
	}

	// Range based for loops
	/*
	 for (const &ref_variable : range_object)
	 {
	 use ref_variable in this block
	 }

	 range object are -> array, string, stl objects like vector, list, map etc
	 */

	for(const char &ch : "abcd"){
		cout << ch << " ";
	}
	cout << endl;
	char charArray[10] = "Vishal";
	for(const char &ch : charArray){
		cout << ch << " ";
	}
	cout << endl;


	for(const int &i : {1, 2, 3, 4, 5, 6}){
		cout << i << " ";
	}
	cout << endl;
	int intArray[10] = {1, 2, 3, 4, 5, 6};	// rest elements will be initialized with default "zero" value
	for(const int &i : intArray){
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
