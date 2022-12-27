// gcc -Wall -Wextra -Werror -lstdc++ -lm external_friend_function.cpp
#include<iostream>
using namespace std;

// Constructor with default arguments

class iClass {
private:
	int data;
	iClass *ptr;
public:
	iClass(int c_data = 0, iClass *c_ptr = NULL) {
		data = c_data;
		ptr = c_ptr == NULL ? this : c_ptr;
	}
	~iClass() {
		ptr = NULL;
	}
	int getData() {
		return data;
	}
	iClass* getPtr() {
		return ptr;
	}
};

int main() {
	iClass iC1;
	cout << iC1.getData() << " " << iC1.getPtr() << endl;
	iClass iC2(2);
	cout << iC2.getData() << " " << iC2.getPtr() << endl;
	iClass iC3(3, NULL);
	cout << iC3.getData() << " " << iC3.getPtr() << endl;
	return 0;
}
