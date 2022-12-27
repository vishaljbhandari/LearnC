// g++ stl_stack.cpp
#include <iostream>
#include <stack>
#include <list>
#include <vector>
using namespace std;

template<typename T>
void print_stack(T &stk) {
	cout << "size: " << stk.size() << " top: " << stk.top() << endl;
}

// print a simple message
void message(const char *s) {
	cout << s << endl;
}

void string_stack() {
	message("str_stack a string stack");
	stack < string > str_stack;
	for (string str : { "one", "two", "three", "four", "five" }) {
		str_stack.push(str);
	}
	print_stack (str_stack);
	message("str_stack push forty-two");
	str_stack.push("forty-two");
	print_stack(str_stack);
	message("str_stack pop");
	str_stack.pop();
	print_stack(str_stack);

	cout << "pushing more strings onto str_stack" << endl;
	str_stack.push("one");
	str_stack.push("two");
	str_stack.push("three");
	str_stack.push("four");
	str_stack.push("five");

	cout << "size of str_stack: " << str_stack.size() << endl;
	cout << "popping all items from str_stack" << endl;
	while (!str_stack.empty()) {
		cout << str_stack.top() << " ";
		str_stack.pop();
	}
	cout << endl;
	cout << "size of str_stack: " << str_stack.size() << endl;
}

void int_stack_using_vector() {
	message("initializing stack int_vector from list");
	vector<int> int_vector = { 1, 2, 3, 4, 5 };
	stack<int, vector<int>> int_stack(int_vector); // initializing stack with vector
	print_stack(int_stack);
	message("int_stack push 42");
	int_stack.push(42);
	print_stack(int_stack);
	message("int_stack pop");
	int_stack.pop();
	print_stack(int_stack);

	int temp;

	cout << "Pushing...\n";
	while (temp >= 0) {
		cout << "Enter numbers: ";
		cin >> temp;
		if (temp >= 0)
			int_stack.push(temp);
	}
	print_stack(int_stack);

	cout << "items {  ";
	while (int_stack.size() > 0) {
		cout << int_stack.top();
		int_stack.pop();
		cout << "  ";
	}
	cout << "} popped" << endl;

	print_stack(int_stack);
}

void int_stack_using_list() {
	cout << "initializing stack from list" << endl;
	list<int> int_list = { 1, 2, 3, 4, 5 }; // initializer list is C++11 only
	stack<int, list<int>> int_stack(int_list); // constructor copies to new list

	cout << "int_stack has " << int_stack.size() << " entries" << endl
			<< "list has " << int_list.size() << " entries." << endl;

	cout << "pop all from int_stack" << endl;
	while (!int_stack.empty()) {
		cout << int_stack.top() << " ";
		int_stack.pop();
	}
	cout << endl;

	cout << "int_stack has " << int_stack.size() << " entries" << endl
			<< "list has " << int_list.size() << " entries." << endl;

	for (int item : int_list) {	// range-based for loop is C++11 only
		cout << item << " ";
	}
	cout << " items of list" << endl;
}

int main() {
	string_stack();
	cout << endl;
	int_stack_using_list();
	cout << endl;
	int_stack_using_vector();
	return 0;
}
