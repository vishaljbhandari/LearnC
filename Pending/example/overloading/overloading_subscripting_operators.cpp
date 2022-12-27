#include <iostream>
using namespace std;
const int SIZE = 10;

class Array {
private:
	int array[SIZE];
public:
	Array() {
		for (register int index = 0; index < SIZE; index++) {
			array[index] = index;
		}
	}

	int& operator[](int index) {
		if (index > SIZE) {
			cout << "Index out of bounds. ";
			// return first element.
			return array[0];
		}
		return array[index];
	}
};

int main() {
	Array array;
	cout << "Value at 2nd position in array : " << array[2] << endl;
	cout << "Value at 5th position in array : " << array[5] << endl;
	cout << "Value at 12th position in array : " << array[12] << endl;
	return 0;
}
