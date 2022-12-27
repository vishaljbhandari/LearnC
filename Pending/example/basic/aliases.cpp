// gcc -lm -lstdc++ aliases.cpp

// Type alias, alias template (since C++11) C++ language Declarations
// Type alias is a name that refers to a previously defined type (similar to typedef).

// Alias template is a name that refers to a family of types.

/*

 using identifier attr(optional) = type-id ;

 template < template-parameter-list >
 using identifier attr(optional) = type-id ;

 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

const char* GetErrorMessage(int errorNo) {
	cout << "inside GetErrorMessage" << endl;
	return "Empty";
}
//typedef const char *(*PFN)(int);
using PFN = const char *(*)(int);

void ShowError(PFN pfn) {
	cout << "inside ShowError" << endl;
}
//typedef std::vector < std::list<std::string>> Names;

//template<typename T>
//using Names = std::vector<std::list<T>>;

using Names = std::vector<std::list<std::string>>;

int main() {
	Names names;
	Names nnames;

	PFN pfn = GetErrorMessage;
	ShowError(pfn);
	return 0;
}
