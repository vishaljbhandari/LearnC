// gcc -lm -lstdc++ weak_ptr.cpp

/*
 weak_ptr

 A weak_ptr is created as a copy of shared_ptr.
 It provides access to an object that is owned by one or more shared_ptr instances but does not participate in reference counting.
 The existence or destruction of weak_ptr has no effect on the shared_ptr or its other copies.
 It is required in some cases to break circular references between shared_ptr instances.

 Cyclic Dependency (Problems with shared_ptr):
 Let’s consider a scenario where we have two classes A and B, both have pointers to other classes.
 So, it’s always like A is pointing to B and B is pointing to A.
 Hence, use_count will never reach zero and they never get deleted.

 This is the reason we use weak pointers(weak_ptr) as they are not reference counted.
 So, the class in which weak_ptr is declared doesn’t have a stronghold of it
 i.e. the ownership isn’t shared, but they can have access to these objects.

 So, in case of shared_ptr because of cyclic dependency use_count never reaches zero which is prevented using weak_ptr,
 which removes this problem by declaring A_ptr as weak_ptr, thus class A does not own it,
 only have access to it and we also need to check the validity of object as it may go out of scope.
 In general, it is a design issue.

 When to use weak_ptr?
 When you do want to refer to your object from multiple places –
 for those references for which it’s ok to ignore and deallocate
 (so they’ll just note the object is gone when you try to dereference).

 */

// C++ program to demonstrate shared_ptr
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
	shared_ptr<A> p1(new A);
	cout << p1.get() << endl;
	p1->show();
	shared_ptr<A> p2(p1);
	p2->show();
	cout << p1.get() << endl;
	cout << p2.get() << endl;

	// Returns the number of shared_ptr objects
	// referring to the same managed object.
	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;

	// Relinquishes ownership of p1 on the object
	// and pointer becomes NULL
	p1.reset();
	cout << p1.get() << endl;
	cout << p2.use_count() << endl;
	cout << p2.get() << endl;

	return 0;
}
