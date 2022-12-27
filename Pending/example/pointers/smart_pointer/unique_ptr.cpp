// gcc -lm -lstdc++ unique_ptr.cpp

/*
 std::unique_ptr was developed in C++11 as a replacement for std::auto_ptr.
 unique_ptr is a new facility with similar functionality, but with improved security (no fake copy assignments), added features (deleters) and support for arrays. It is a container for raw pointers. It explicitly prevents copying of its contained pointer as would happen with normal assignment i.e. it allows exactly one owner of the underlying pointer.
 So, when using unique_ptr there can only be at most one unique_ptr at any one resource and when that unique_ptr is destroyed, the resource is automatically claimed. Also, since there can only be one unique_ptr to any resource, so any attempt to make a copy of unique_ptr will cause a compile-time error.

 unique_ptr<A> ptr1 (new A);

 // Error: can't copy unique_ptr
 unique_ptr<A> ptr2 = ptr1;
 But, unique_ptr can be moved using the new move semantics i.e. using std::move() function to transfer ownership of the contained pointer to another unique_ptr.

 // Works, resource now stored in ptr2
 unique_ptr<A> ptr2 = move(ptr1);
 So, it’s best to use unique_ptr when we want a single pointer to an object that will be reclaimed when that single pointer is destroyed.

 */

/*

 non-specialized
 template <class T, class D = default_delete<T>> class unique_ptr;
 array specialization
 template <class T, class D> class unique_ptr<T[],D>;
 Unique pointer
 Manages the storage of a pointer, providing a limited garbage-collection facility, with little to no overhead over built-in pointers (depending on the deleter used).

 These objects have the ability of taking ownership of a pointer: once they take ownership they manage the pointed object by becoming responsible for its deletion at some point.

 unique_ptr objects automatically delete the object they manage (using a deleter) as soon as they themselves are destroyed, or as soon as their value changes either by an assignment operation or by an explicit call to unique_ptr::reset.

 unique_ptr objects own their pointer uniquely: no other facility shall take care of deleting the object, and thus no other managed pointer should point to its managed object, since as soon as they have to, unique_ptr objects delete their managed object without taking into account whether other pointers still point to the same object or not, and thus leaving any other pointers that point there as pointing to an invalid location.

 A unique_ptr object has two components:
 a stored pointer: the pointer to the object it manages. This is set on construction, can be altered by an assignment operation or by calling member reset, and can be individually accessed for reading using members get or release.
 a stored deleter: a callable object that takes an argument of the same type as the stored pointer and is called to delete the managed object. It is set on construction, can be altered by an assignment operation, and can be individually accessed using member get_deleter.

 unique_ptr objects replicate a limited pointer functionality by providing access to its managed object through operators * and -> (for individual objects), or operator [] (for array objects). For safety reasons, they do not support pointer arithmetics, and only support move assignment (disabling copy assignments).

 */

/*
 Member functions
 ----------------
 (constructor)
 Construct unique_ptr (public member function )

 (destructor)
 Destroy unique_ptr (public member function )

 operator=
 unique_ptr assignment (public member function )

 get
 Get pointer (public member function )

 get_deleter
 Get stored deleter (public member function )

 operator bool
 Check if not empty (public member function )

 release
 Release pointer (public member function )

 reset
 Reset pointer (public member function )

 swap
 Swap content (public member function )

 Exclusive for non-specialized version (single objects)
 ------------------------------------------------------
 operator*
 Dereference object (public member function )

 operator->
 Dereference object member (public member function )

 Exclusive for the version specialized for arrays with runtime length
 --------------------------------------------------------------------
 operator[]
 Offset access (public member function )

 Non-member function overloads
 -----------------------------
 swap
 Exchange content of unique_ptr objects (function template )

 relational operators
 Relational operators ==, !=, <, <=, >, >= (function template )

 */

#include <iostream>
#include <memory>
using namespace std;

class A {
public:
	void show() {
		cout << "A::show()" << endl;
	}
};

// The below code returns a resource and if we don’t explicitly capture the return value,
// the resource will be cleaned up. If we do, then we have exclusive ownership of that resource.
// In this way, we can think of unique_ptr as safer and better replacement of auto_ptr.

unique_ptr<A> fun() {
	unique_ptr<A> ptr(new A);

	/* ...
	 ... */

	return ptr;
}

int main() {
	unique_ptr<A> p1(new A);
	p1->show();

	// returns the memory address of p1
	cout << p1.get() << endl;

	// transfers ownership to p2
	unique_ptr<A> p2 = move(p1);
	p2->show();
	cout << p1.get() << endl;
	cout << p2.get() << endl;

	// transfers ownership to p3
	unique_ptr<A> p3 = move(p2);
	p3->show();
	cout << p1.get() << endl;
	cout << p2.get() << endl;
	cout << p3.get() << endl;

	return 0;
}

/*
 When to use unique_ptr?

 Use unique_ptr when you want to have single ownership(Exclusive) of the resource.
 Only one unique_ptr can point to one resource.
 Since there can be one unique_ptr for single resource its not possible to copy one unique_ptr to another.
 */
