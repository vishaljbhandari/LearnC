#include <iostream>
using namespace std;

/*
 Why Exception Handling?
 Following are main advantages of exception handling over traditional error handling.

 1) Separation of Error Handling code from Normal Code
 In traditional error handling codes, there are always if else conditions to handle errors.
 These conditions and the code to handle errors get mixed up with the normal flow.
 This makes the code less readable and maintainable. With try catch blocks, the code for error handling becomes separate from the normal flow.

 2) Functions/Methods can handle any exceptions they choose
 A function can throw many exceptions, but may choose to handle some of them.
 The other exceptions which are thrown, but not caught can be handled by caller.
 If the caller chooses not to catch them, then the exceptions are handled by caller of the caller.
 In C++, a function can specify the exceptions that it throws using the throw keyword.
 The caller of this function must handle the exception in some way (either by specifying it again or catching it)

 3) Grouping of Error Types: In C++,
 both basic types and objects can be thrown as exception.
 We can create a hierarchy of exception objects, group exceptions in namespaces or classes, categorize them according to types.
 */

class Base {
};
class Derived: public Base {
};

class Test {
public:
	Test() {
		cout << "Constructor of Test " << endl;
	}
	~Test() {
		cout << "Destructor of Test " << endl;
	}
};

// Here we specify the exceptions that this function throws.
void fun(int *ptr, int x) throw (int*, int)	// this function can throw only int and int* type exception
// but this dynamic exception specifications are deprecated in C++11 [-Wdeprecated]
{
	if (ptr == NULL)
		throw ptr;
	if (x == 0)
		throw x;
	/* Some functionality */
}

// Own exception class, inheriting from exception
// exception class is super class for all exceptions
class MyException: public exception {
	const char* what() const throw () {
		return "C++ Exception";
	}
};

int main() {
	int x = -1;

	// simple example to show exception handling
	cout << "Before try \n";
	try {
		cout << "Inside try \n";
		if (x < 0) {
			throw x;		// exception thrown here
			cout << "After throw (Never executed) \n";
		}
	} catch (int y) {// exception caught here, matching catch for try/throw (x is integer and y is also integer
		cout << "Exception Caught \n";
	}
	cout << "After catch (Will be executed) \n";

	// There is a special catch block called ‘catch all’ catch(…) that can be used to catch all types of exceptions.
	cout << "Before try \n";
	try {
		cout << "Inside try \n";
		throw 10;
	} catch (char *excp) {
		cout << "Caught " << excp;
	} catch (...) {	// if not matching catch block is found then this "catch all" will be executed  when it is encountered in sequence
		cout << "Default Exception\n";
	}
	cout << "After catch (Will be executed) \n";

	// implicit type conversion doesn’t happen for primitive types while matching catch argument with thrown type

	cout << "Before try \n";
	try {
		cout << "Inside try \n";
		throw 'a';
	} catch (int x) {		// no conversion here, hence skipped
		cout << "Caught " << x;
	} catch (...) {			// this catch all will be executed
		cout << "Default Exception\n";
	}
	cout << "After catch (Will be executed) \n";

	// If an exception is thrown and not caught anywhere, the program terminates abnormally

	cout << "Before try \n";
	try {
		cout << "Inside try \n";
		// throw 'a';      // uncomment this line to check this example
	} catch (int x) {		// not matchable, hence skipped
		cout << "Caught ";
	}
	cout << "After catch (Will be executed) \n";
	// no matching catch is found for throw 'a', hence program terminates

	// Exception Handling – catching base and derived classes as exceptions:
	// If both base and derived classes are caught as exceptions then catch block of derived class must appear before the base class.
	// A derived class exception should be caught before a base class exception
	// If we put base class first then the derived class catch block will never be reached.

	Derived d;
	try {
		// Some monitored code
		throw d;			// throwing derived class object exception
	} catch (Base b) {		// base will catch block will catch this
		cout << "Caught Base Exception";
	} catch (Derived d) { //This catch block is NEVER executed, as it comes after base class, Compiler Warning
		cout << "Caught Derived Exception";
	}

	// Unlike Java, in C++, all exceptions are unchecked. Compiler doesn’t check whether an exception is caught or not
	// Checked: are the exceptions that are checked at compile time. If some code within a method throws a checked exception, then the method must either handle the exception or it must specify the exception using throws keyword.
	// Unchecked are the exceptions that are not checked at compiled time. In C++, all exceptions are unchecked, so it is not forced by the compiler to either handle or specify the exception. It is up to the programmers to be civilized, and specify or catch the exceptions.

	// In C++, try-catch blocks can be nested. Also, an exception can be re-thrown using “throw; ”
	// such examples can be used to partially handle exception.

	try {
		try {
			throw 20;
		} catch (int n) {
			cout << "Handle Partially ";
			throw; // Re-throwing an exception
		}
	} catch (int n) {
		cout << "Handle remaining ";
	}

	// When an exception is thrown, all objects created inside the enclosing try block are destructed before the control is transferred to catch block.
	try {
		Test t1;
		int *ptr = new int[5];
		throw 10; // before throwing all objects created in this scope will be destroyed, hence their respective destructors will be called
		// but all dynamically allocated memories in this block will not be released, resulting into memory leak. here ptr pointer memory is not release, hence that memory leak.
	} catch (int i) {
		cout << "Caught " << i << endl;
	}

	// Where does compiler find catch block for a throw statement ?
	/*
	 * 1) In same function after throw statement, in all catches block associated with that try block having throw statement.
	 * 2) In parent function after call of that function, in all catches block associated with that try block having function call.
	 * 3) In main function after call of that function, in all catches block associated with that try block having function call.
	 */

	try {
		fun(NULL, 0);// special function to check null and divide by zero exception, this function throws exception
	} catch (...) {
		cout << "Caught exception from fun()";
	}

	// Creating class exception
	try {
		throw MyException();
	} catch (MyException &e) {
		std::cout << "MyException caught" << std::endl;
		std::cout << e.what() << std::endl;
	} catch (std::exception &e) {
		//Other errors
	}

	return 0;
}
