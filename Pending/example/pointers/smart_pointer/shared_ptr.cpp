// gcc -lm -lstdc++ shared_ptr.cpp

/*
 A shared_ptr is a container for raw pointers. It is a reference counting ownership model
 i.e. it maintains the reference count of its contained pointer in cooperation with all copies of the shared_ptr.
 So, the counter is incremented each time a new pointer points to the resource and decremented when the destructor of the object is called.

 Reference Counting: It is a technique of storing the number of references, pointers or handles to a resource
 such as an object, block of memory, disk space or other resources.

 An object referenced by the contained raw pointer will not be destroyed until reference count is greater than zero
 i.e. until all copies of shared_ptr have been deleted.
 So, we should use shared_ptr when we want to assign one raw pointer to multiple owners.

 */

/*
 // template <class T> class shared_ptr;

 Shared pointer

 Manages the storage of a pointer, providing a limited garbage-collection facility, possibly sharing that management with other objects.

 Objects of shared_ptr types have the ability of taking ownership of a pointer and share that ownership: once they take ownership, the group of owners of a pointer become responsible for its deletion when the last one of them releases that ownership.

 shared_ptr objects release ownership on the object they co-own as soon as they themselves are destroyed, or as soon as their value changes either by an assignment operation or by an explicit call to shared_ptr::reset. Once all shared_ptr objects that share ownership over a pointer have released this ownership, the managed object is deleted (normally by calling ::delete, but a different deleter may be specified on construction).

 shared_ptr objects can only share ownership by copying their value: If two shared_ptr are constructed (or made) from the same (non-shared_ptr) pointer, they will both be owning the pointer without sharing it, causing potential access problems when one of them releases it (deleting its managed object) and leaving the other pointing to an invalid location.

 Additionally, shared_ptr objects can share ownership over a pointer while at the same time pointing to another object. This ability is known as aliasing (see constructors), and is commonly used to point to member objects while owning the object they belong to. Because of this, a shared_ptr may relate to two pointers:

 A stored pointer, which is the pointer it is said to point to, and the one it dereferences with operator*.
 An owned pointer (possibly shared), which is the pointer the ownership group is in charge of deleting at some point, and for which it counts as a use.

 Generally, the stored pointer and the owned pointer refer to the same object, but alias shared_ptr objects (those constructed with the alias constructor and their copies) may refer to different objects.

 A shared_ptr that does not own any pointer is called an empty shared_ptr. A shared_ptr that points to no object is called a null shared_ptr and shall not be dereferenced. Notice though that an empty shared_ptr is not necessarily a null shared_ptr, and a null shared_ptr is not necessarily an empty shared_ptr.

 shared_ptr objects replicate a limited pointer functionality by providing access to the object they point to through operators * and ->. For safety reasons, they do not support pointer arithmetics.

 A related class, weak_ptr, is able to share pointers with shared_ptr objects without owning them.

 Member functions
 ----------------
 (constructor)
 Construct shared_ptr (public member function )

 (destructor)
 Destroy shared_ptr (public member function )

 operator=
 shared_ptr assignment (public member function )

 swap
 Swap content (public member function )

 reset
 Reset pointer (public member function )

 get
 Get pointer (public member function )

 operator*
 Dereference object (public member function )

 operator->
 Dereference object member (public member function )

 use_count
 Use count (public member function )

 unique
 Check if unique (public member function )

 operator bool
 Check if not null (public member function )

 owner_before
 Owner-based ordering (public member function template )
 */

/*
 Non-member functions
 -------------------
 Overloads:

 swap
 Exchange content of shared_ptr objects (function template )

 relational operators
 Relational operators ==, !=, <, <=, >, >= (function template )

 ostream operator<<
 Insert into output stream (function template )


 Specific functions:
 make_shared
 Make shared_ptr (function template )

 allocate_shared
 Allocate shared_ptr (function template )

 static_pointer_cast
 Static cast of shared_ptr (function template )

 dynamic_pointer_cast
 Dynamic cast of shared_ptr (function template )

 const_pointer_cast
 Const cast of shared_ptr (function template )

 get_deleter
 Get deleter from shared_ptr (function template )
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
/*
 When to use shared_ptr?
 Use shared_ptr if you want to share ownership of a resource.
 Many shared_ptr can point to a single resource.
 shared_ptr maintains reference count for this propose.
 when all shared_ptr’s pointing to resource goes out of scope the resource is destroyed.
 */
