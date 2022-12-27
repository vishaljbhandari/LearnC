// gcc -lm -lstdc++ namespace.cpp

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

/*

 Namespaces allow us to group named entities that otherwise would have global scope into narrower scopes, giving them namespace scope.
 This allows organizing the elements of programs into different logical scopes referred to by names.

 Namespace is a feature added in C++ and not present in C.
 A namespace is a declarative region that provides a scope to the identifiers (names of the types, function, variables etc) inside it.
 Multiple namespace blocks with the same name are allowed. All declarations within those blocks are declared in the named scope.
 A namespace definition begins with the keyword namespace followed by the namespace name as follows:


 namespace namespace_name
 {
 int x, y; // code declarations where
 // x and y are declared in
 // namespace_name's scope
 }

 Namespace declarations appear only at global scope.
 Namespace declarations can be nested within another namespace.
 Namespace declarations don’t have access specifiers. (Public or private)
 No need to give semicolon after the closing brace of definition of namespace.
 We can split the definition of namespace over several units.

 */

// Variable created inside namespace
namespace first {
int val = 500;
}

// Global variable
int val = 100;

namespace ns1 {
int value() {
	return 5;
}
}
namespace ns2 {
const double x = 100;
double value() {
	return 2 * x;
}
}

namespace ns {
// A Class in a namespace
class geek {
public:
	void display() {
		cout << "ns::geek::display()\n";
	}
};
class ceek;
// class declaration without definition
}

// Defining class outside
class ns::ceek {
public:
	void display() {
		cout << "ns::ceek::display()\n";
	}
};

// Creating a namespace
namespace nps {
void display();
class geek {
public:
	void display();
};
}

// Defining methods of namespace
void nps::geek::display() {
	cout << "ns::geek::display()\n";
}
void nps::display() {
	cout << "ns::display()\n";
}

namespace name_space {
void funct() {
	cout << "Inside second_space" << endl;
}
}

// nested namespace

namespace ns_1 {
// code declarations
namespace ns_2 {
// code declarations
void name_fun() {
	cout << "inside ns_1::ns_2::name_fun function" << endl;
}
}
}

int main() {
	int value;
	value = 0;
	// double value = 0.0; // Compiler Error: 'value' has a previous declaration as 'int value'

	// In each scope, a name can only represent one entity.
	// So, there cannot be two variables with the same name in the same scope.
	// Using namespaces, we can create two variables or member functions having the same name.

	// These variables can be accessed from outside the namespace using the scope operator ::
	cout << "val(global) : " << val << ", first::val " << first::val << endl;

	// Local variable
	int val = 200;

	cout << "val(local) : " << val << ", first::val " << first::val << endl;

	// Access value function within ns1
	cout << ns1::value() << endl;

	// Access value function within ns2
	cout << ns2::value() << endl;

	// Access variable x directly
	cout << ns2::x << endl;

	// Creating Object of geek Class
	ns::geek obj;

	obj.display();

	ns::ceek cbj;
	cbj.display();

	nps::geek n_obj;
	nps::display();
	n_obj.display();

	/*
	 The using directive
	 You can also avoid prepending of namespaces with the using namespace directive.
	 This directive tells the compiler that the subsequent code is making use of names in the specified namespace.

	 */

	// before `using` directive (before opening namespace for use)
	// funct();// error, as function is not defined or allowed to use from namespace;
	name_space::funct();	// allowed using :: scope operator

	using namespace name_space;

	funct();// allowed as name_space is availed/opened before its use using `using` directive

	// Calling function from a nested namespace
	ns_1::ns_2::name_fun();

	// opening namespace using `using`
	using namespace ns_1;
	// opening ns_1 namespace
	using namespace ns_1::ns_2;
	// opening ns_2 namespace

	return 0;

}
