#include <iostream>
using namespace std;

template<class T, int size>
class Test {
private:
	T val;
public:
	static int count = size;
	Test() {
		count++;
	}
	// some other stuff in class
};

template<class T>
int Test<T>::count = 0;

int main() {
	cout << Test<int, 5>::count << endl;  // prints 2
	cout << Test<double, 6>::count << endl; //prints 1

	return 0;
}
