#include <cstdio>
#include <iostream>
using namespace std;

void basic() {
	// const qualifier is used to make a variable declaration as CONSTANT
	const int ABC = 5;
	const char *STR = "vishal";

	// Later that value can not be modified
	// Any attempt to modify that value cause compilation error
	// ABC = 7; 	// compiler error, constant can not be modified

	// const qualifier, qualifies to a declaration but always needs an initializer, with out initializer, there will be compiler error
	const int PQR = 8;
	// const int XYZ;	// this will cause and compiler error

	// const usage replaces c macros, instead c macros, const qualifiers are used
	// Disadvantages of MACROS -> They are not type safe and they dont have any scope, they cause confusing bugs

	// const qualifiers are commonly used with references to create const references for read only use of variables

	// Conventionally, all constant variables are kept in UPPER case, always a good practice to differentiate constants with other variables

	float radius = 0;
	cin >> radius;
	const float PI = 3.14159f;
	float area = PI * radius * radius;
	float circumference = PI * 2 * radius;
	cout << "Area is : " << area << endl;
	cout << "Circumference is : " << circumference << endl;
}

void pointerToConstant() {
	// Creating a constant variable
	const int CHUNK_SIZE = 512;
	int abc = 10;
	// creating pointer to constant
	//int* ptr = &CHUNK_SIZE;		// this is not allowed(compiler error), because using this pointer, constant variable can be modified using *ptr = 5, which is against concept of constant

	// so language says, if pointer is created to a constant, then pointer itself must be a constant
	const int *ptr = &CHUNK_SIZE;
	// now using this we can not modify *ptr, so *ptr is constant

	// but ptr is not constant, as after declaring const int *ptr, we can still change ptr
	// ptr = &abc;	// this also should not have been allowed

	// so correct way to create a const pointer to constant is

	const int *const pointer = &CHUNK_SIZE;		// dont write "const int const *pointer"
	// above says pointing int is constant "const int" and even pointer is constant "*const pointer"

	// using this, one can not modify constant variable and pointer value
	// *pointer = 5;	// not allowed, you can not modify pointing variable's value
	// pointer = &x;	// not allowed, you can not modify pointer value
}

void PrintNonConstantREF(int &value) {	// passing without constant reference, anyone can modify its value inside function scope
	value = 6;
	cout << value << endl;
}

// passing as const reference is widely used for copy constructors, assignments and various other implementations
void PrintConstantREF(const int &value) {	// passing it as constant reference will not allow anyone to modify its value inside function scope
	// value = 6;		// not allowed, this value is for read only purpose
	cout << value << endl;
}

void constReferences(){
	int value = 5;
	PrintNonConstantREF(value);	// value is passed by reference
	cout << "main-> value" << value << endl;
	value = 5;
	PrintConstantREF(value);	// passing to a constant reference parameters
	cout << "main-> value" << value << endl;
}

int main() {
	basic();
	pointerToConstant();
	constReferences();
	return (0);
}

