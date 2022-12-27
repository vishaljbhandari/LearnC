// gcc -Wall -Wextra -Werror -lstdc++ -lm types.cpp

// Types -> Arithmetic and Void Type
// Arithmetic Type -> Integral, Floating Type
// Integral -> Bool, char, wchar, char16_t, char32_t, short, int, long
// Floating -> Float, Double
// Void -> NO type, used for pointers and functions mainly

// Modifiers -> TO define meaning of type (Short, long, signed and unsigned are modifiers for integral types

// Qualifiers -> Defines scope and nature of type (const, static, volatile)

// Types may occupy different memory based on the platform used 32bit and 64 bit platform

#include <cstdio>
#include <string>
#include <typeinfo>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
// Creating variables
// Whole Numbers (Signed)
	int myInt = 5; // Signed Integer(whole number) Size(4)	Range(-2,147,483,648 to 2,147,483,647)
	short int myShortInt = 5; // Signed Short Integer(whole number) Size(2) Range(-32,768 to 32,767)
	long int myLongInt = 20; // Signed Long Integer(whole number) Size(4) Range(-2,147,483,648 to 2,147,483,647)
	long long int myLongLongInt = 100000000000; // Signed Long Long Integer(whole number) Size(8)	Range(-(2^63) to (2^63)-1)

// Whole Numbers (Signed)
	unsigned int myUnsignedInt = 5; // Unsigned Integer(whole number) Size(4)	Range(0 to 4,294,967,295)
	unsigned short int myUnsignedShortInt = 5; // Unsigned Short Integer(whole number) Size(2) Range(0 to 65,535)
	unsigned long int myUnsignedLongInt = 20; // Unsigned Long Integer(whole number) Size(4) Range(0 to 4,294,967,295)
	unsigned long long int myUnsignedLongLongInt = 1000000000; // Unsigned Long Long Integer(whole number) Size(8) Range(0 to 18,446,744,073,709,551,615)

// Character Type
	char myChar = 'D';       // Signed Character Type Size(1) Range(-128 to 127)
	signed char mySignedChar = 'D'; // Signed Character Type Size(1) Range(-128 to 127)
	unsigned char myUnsignedChar = 'D'; // Unsigned Character Type Size(1) Range(0 to 255)
	wchar_t myWideCharacter = 'E'; // Wide character Size(2 or 4) Range(1 wide character)

// Floating point numbers
	float myFloatNum = 5.99;     // Float Number	Size(4)
	double myDoubleNum = 9.98;   // Double Number	Size(8)
	long double myLongDoubleNum = 9.98;   // Long Double Number	Size(8)

	bool myBoolean = true;       // Boolean
	string myString = "Hello";   // String

// Print variable values
	cout << "int myInt : " << myInt << ", Size: " << sizeof(myInt) << endl;
	cout << "short int myShortInt: " << myShortInt << ", Size: "
			<< sizeof(myShortInt) << endl;
	cout << "long int myLongInt: " << myLongInt << ", Size: "
			<< sizeof(myLongInt) << endl;
	cout << "long long int myLongLongInt: " << myLongLongInt << ", Size: "
			<< sizeof(myLongLongInt) << endl;

	cout << "unsigned int myUnsignedInt: " << myUnsignedInt << ", Size: "
			<< sizeof(myUnsignedInt) << endl;
	cout << "unsigned short int myUnsignedShortInt: " << myUnsignedShortInt
			<< ", Size: " << sizeof(myUnsignedShortInt) << endl;
	cout << "unsigned long int myUnsignedLongInt: " << myUnsignedLongInt
			<< ", Size: " << sizeof(myUnsignedLongInt) << endl;
	cout << "unsigned long long int myUnsignedLongLongInt: "
			<< myUnsignedLongLongInt << ", Size: "
			<< sizeof(myUnsignedLongLongInt) << endl;

	cout << "char myChar: " << myChar << ", Size: " << sizeof(myChar) << endl;
	cout << "signed char mySignedChar: " << mySignedChar << ", Size: "
			<< sizeof(mySignedChar) << endl;
	cout << "unsigned char myUnsignedChar: " << myUnsignedChar << ", Size: "
			<< sizeof(myUnsignedChar) << endl;
	cout << "wchar_t myWideCharacter: " << myWideCharacter << ", Size: "
			<< sizeof(myWideCharacter) << endl;

	cout << "float myFloatNum: " << myFloatNum << ", Size: "
			<< sizeof(myFloatNum) << endl;
	cout << "double myDoubleNum: " << myDoubleNum << ", Size: "
			<< sizeof(myDoubleNum) << endl;
	cout << "long double myLongDoubleNum: " << myLongDoubleNum << ", Size: "
			<< sizeof(myLongDoubleNum) << endl;

	cout << "bool myBoolean: " << myBoolean << ", Size: " << sizeof(myBoolean)
			<< endl;
	cout << "string myString: " << myString << ", Size: " << sizeof(myString)
			<< endl;

// Size of data types
	cout << endl << "Size of data types" << endl;
	cout << "int : " << sizeof(int) << endl;
	cout << "short int: " << sizeof(short int) << endl;
	cout << "long int: " << sizeof(long int) << endl;
	cout << "long long int: " << sizeof(long long int) << endl;

	cout << "unsigned int: " << sizeof(unsigned int) << endl;
	cout << "unsigned short int: " << sizeof(unsigned short int) << endl;
	cout << "unsigned long int: " << sizeof(unsigned long int) << endl;
	cout << "unsigned long long int: " << sizeof(unsigned long long int)
			<< endl;

	cout << "char: " << sizeof(char) << endl;
	cout << "signed char: " << sizeof(signed char) << endl;
	cout << "unsigned char: " << sizeof(unsigned char) << endl;
	cout << "wchar_t: " << sizeof(wchar_t) << endl;

	cout << "float: " << sizeof(float) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "long double: " << sizeof(long double) << endl;

	cout << "bool: " << sizeof(bool) << endl;
	cout << "string: " << sizeof(string) << endl;

	cout << endl << endl;

	float f1 = 35e3;
	double d1 = 12E4;

	cout << "ffloat f1 = 35e3 = " << f1 << ", Size: " << sizeof(f1) << endl;
	cout << "double d1 = 12E4 = " << d1 << ", Size: " << sizeof(d1) << endl;

	bool isCodingFun = true;
	bool isFishTasty = false;
	cout << "bool isCodingFun = " << isCodingFun << " [true:1], Size: "
			<< sizeof(isCodingFun) << endl;
	cout << "bool isFishTasty = " << isFishTasty << " [false:0], Size: "
			<< sizeof(isFishTasty) << endl;

	char string[] = "This is a string.";
	cout << "char string[]: " << string << ", Size: " << sizeof(string)
			<< ", Length: " << strlen(string) << endl;
	// Size is including null character
	// Whereas length is excluding null character
	return 0;
}
