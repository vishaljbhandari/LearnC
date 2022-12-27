// gcc -lm -lstdc++ auto_ptr.cpp

/*
 This class template is deprecated as of C++11.
 unique_ptr is a new facility with a similar functionality, but with improved security.
 auto_ptr is a smart pointer that manages an object obtained via new expression and deletes that object when auto_ptr itself is destroyed.
 An object when described using auto_ptr class it stores a pointer to a single allocated object
 which ensures that when it goes out of scope, the object it points to must get automatically destroyed.
 It is based on exclusive ownership model i.e.

 two pointers of the same type can’t point to the same resource at the same time.
 As shown in the below program, copying or assigning of pointers changes the ownership i.e.
 source pointer has to give ownership to the destination pointer.

 */

// C++ program to illustrate the use of auto_ptr
#include <iostream>
#include <memory>
using namespace std;

class A {
public:
	void show() {
		cout << "A::show()" << endl;
	}
};

int main() {
	// p1 is an auto_ptr of type A
	auto_ptr<A> p1(new A);
	// warning: ‘template<class> class std::auto_ptr’ is deprecated [-Wdeprecated-declarations]
	p1->show();

	// returns the memory address of p1
	cout << p1.get() << endl;

	// copy constructor called, this makes p1 empty.
	auto_ptr<A> p2(p1);
	// warning: ‘template<class> class std::auto_ptr’ is deprecated [-Wdeprecated-declarations]

	p2->show();

	// p1 is empty now
	cout << p1.get() << endl;

	// p1 gets copied in p2
	cout << p2.get() << endl;

	return 0;
}

/*

 The copy constructor and the assignment operator of auto_ptr do not actually copy the stored pointer instead they transfer it, leaving the first auto_ptr object empty.
 This was one way to implement strict ownership so that only one auto_ptr object can own the pointer at any given time i.e. auto_ptr should not be used where copy semantics are needed.

 Why is auto_ptr deprecated?
 It takes ownership of the pointer in a way that no two pointers should contain the same object.
 Assignment transfers ownership and resets the rvalue auto pointer to a null pointer.
 Thus, they can’t be used within STL containers due to the aforementioned inability to be copied.

 */
