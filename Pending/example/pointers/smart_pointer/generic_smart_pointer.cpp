// gcc -lstdc++ -lm generic_smart_pointer.cpp
#include<iostream>
using namespace std;

// A generic smart pointer class

/*
 * What a generic smart pointer class has
 * One underlying pointer
 * One single argument constructor
 * One destructor
 * Operator overloaded functions for * and ->
*/

template<class T>
class SmartPtr {
	T *ptr;  // Actual pointer
public:
	// Constructor
	explicit SmartPtr(T *p = NULL) {		// assign external pointer to internal pointer
		ptr = p;
	}

	// Destructor
	~SmartPtr() {
		delete (ptr);			// deletes underlying pointer
	}

	// Overloading dereferencing operator
	T& operator *() {	// returns/connects to internal pointer value
		return *ptr;
	}

	// Overloading arrow operator so that members of T can be accessed
	// like a pointer (useful if T represents a class or struct or
	// union type)
	T* operator ->() {	// returns/connects to internal pointer
		return ptr;
	}
};

int main() {
	SmartPtr<int> iptr(new int());
	*iptr = 20;
	cout << "int pointer " << *iptr << endl;

	SmartPtr<char> cptr(new char());
	*cptr = 'A';
	cout << "char pointer " << *cptr << endl;

	SmartPtr<float> fptr(new float());
	*fptr = 56.45f;
	cout << "float pointer " << *fptr << endl;

	// We don't need to call delete ptr: when the object ptr goes out of scope, destructor for it is automatically called and destructor does delete ptr.
	return 0;
}

