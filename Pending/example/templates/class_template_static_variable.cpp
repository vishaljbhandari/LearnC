// gcc -lstdc++ -lm class_template_static_variable.cpp
#include <iostream>

using namespace std;

/*
 Class templates and static variables:
 The rule for class templates is same as function templates
 Each instantiation of class template has its own copy of member static variables. For example, in the following program there are two instances Test and Test. So two copies of static variable count exist.
 */

template<class T> class Test {
private:
	T val;
public:
	static int count;
	Test() {
		count++;
	}
	// some other stuff in class
};

template<class T>
int Test<T>::count = 0;

int main() {
	Test<int> a;  // value of count for Test<int> is 1 now
	Test<int> b;  // value of count for Test<int> is 2 now
	Test<double> c;  // value of count for Test<double> is 1 now
	cout << Test<int>::count << endl;  // prints 2
	cout << Test<double>::count << endl; //prints 1
	return 0;
}
