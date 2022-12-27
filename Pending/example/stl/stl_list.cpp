// gcc -lstdc++ -lm stl_list.cpp
#include <iostream>
#include <list>
using namespace std;

const static int size = 10;

void printIntegerList(const list<int> &my_list) {
	cout << "List content: {  ";
	for (const int &num : my_list)
		cout << num << "  ";
	cout << "}" << endl;
}

// print the elements of the list
template<typename T>
void print_list(list<T> &l) {
	if (l.empty())
		return;
	for (T &i : l)
		cout << i << " ";
	cout << endl;
}

// print a simple message
void message(const char *s) {
	cout << s << endl;
}
void message(const char *s, const int n) {
	cout << s << ": " << n << endl;
}

int main(int argc, char **argv) {
	// from initializer list (C++11)
	cout << "list of int from initializer list (C++11): " << endl;
	list<int> lst = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "size: " << lst.size() << endl;
	cout << "front: " << lst.front() << endl;
	cout << "back: " << lst.back() << endl;

	cout << "push_back 47: " << endl;
	lst.push_back(47);
	cout << "size: " << lst.size() << endl;
	cout << "back() " << lst.back() << endl;

	// range-based iterator (C++11)
	cout << "range-based iterator (C++11): " << endl;
	for (int &vect : lst) {
		cout << vect << " ";
	}
	cout << endl << endl;

	// need an iterator to insert and erase
	list<int>::iterator itlst1 = lst.begin();
	list<int>::iterator itlst2 = lst.begin();
	cout << "insert 112 before 5 " << endl;
	// find 5 first
	while (*++itlst1 != 5) {
	}
	// then insert element after iterator
	lst.insert(itlst1, 112);

	// first find the element
	while (*++itlst1 != 7) {
	}
	cout << "erase 7 " << endl;
	// then erase it
	lst.erase(itlst1);

	for (int &vect : lst)
		cout << vect << " ";
	cout << endl << endl;

	cout << "erase 112 to 8 " << endl;
	itlst1 = itlst2 = lst.begin();
	// find two points/elements
	while ((*++itlst1 != 112) && (itlst1 != lst.end())) {
	}
	while ((*++itlst2 != 8) && (itlst2 != lst.end())) {
	}
	cout << *itlst1 << " " << *itlst2 << endl;
	// then erase elements
	lst.erase(itlst1, itlst2);
	for (int &vect : lst)
		cout << vect << " ";
	cout << endl << endl;

	// from C-array
	cout << "list from C-array: " << endl;
	int arr[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> ilist(arr, arr + size);
	for (int item : ilist)
		cout << item << " ";
	cout << endl << endl;

	// from argc/argv list
	cout << "list of strings, from argc/argv list: " << endl;
	list < string > args(argv, argv + argc);

	// pop all from the beginning of the list
	cout << "while pop" << endl;
	while (args.size() > 0) {
		cout << args.front() << endl;
		args.pop_front();
	}
	cout << endl;

	list<int> l1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print_list(l1);
	message("size", (int) l1.size());
	message("front", l1.front());
	message("back", l1.back());

	message("push back 47");
	l1.push_back(47);
	print_list(l1);

	// need an iterator to insert and erase
	message("insert:");
	list<int>::iterator lst_it = l1.begin();
	while ((*++lst_it != 5) && (lst_it != l1.end()))
		;
	if (lst_it != l1.end()) {
		message("insert 112 before 5");
		l1.insert(lst_it, 112);
	}
	print_list(l1);

	// find element value 7
	while ((*++lst_it != 7) && (lst_it != l1.end()))
		;
	if (lst_it != l1.end()) {
		message("erase 7");
		l1.erase(lst_it);
	}
	print_list(l1);

	// remove element value 8
	l1.remove(8);
	message("remove 8");
	print_list(l1);

	list<int> numbers;
	int value = 0;

	cout << "Pushing back... [Enter negative number to quit]" << endl;
	while (value >= 0) {
		cout << "Enter number: ";
		cin >> value;
		if (value >= 0)
			numbers.push_back(value);
	}
	printIntegerList(numbers);

	numbers.clear();
	value = 0;
	cout << "Pushing front... [Enter negative number to quit]" << endl;
	while (value >= 0) {
		cout << "Enter number: ";
		cin >> value;
		if (value >= 0)
			numbers.push_front(value);
	}
	printIntegerList(numbers);

	return 0;
}
