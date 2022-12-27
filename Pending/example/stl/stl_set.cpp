#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

// print the elements of the set
template<typename T>
void print_set(T &s) {
	if (s.empty())
		return;
	for (auto x : s)
		cout << x << " ";
	cout << endl;
}

// print a simple message
void message(const char *m) {
	cout << m << endl;
}
template<typename T>
void message(const char *m, const T &v) {
	cout << m << ": " << v << endl;
}

void set_demo() {
	message("construct set set1");
	set < string > str_set = { "one", "two", "three", "four", "five" };
	message("size of set", str_set.size());
	message("ordered set is alphabetical");
	print_set (str_set);

	message("insert element six");
	str_set.insert("six");
	print_set(str_set);

	message("find and erase element six");
	set<string>::iterator it = str_set.find("six");
	if (it != str_set.end()) {
		message("erasing", *it);
		str_set.erase(it);
	} else {
		cout << "not found" << endl;
	}
	print_set(str_set);

	message("inserting duplicate element five");
	str_set.insert("five");
	print_set(str_set);
	cout << endl << endl;
}

void unordered_set_demo() {
	message("construct unordered set set");
	unordered_set < string > set = { "one", "two", "three", "four", "five" };
	message("size of set", set.size());
	message("unordered set has no defined order");
	print_set (set);

	message("insert element six");
	set.insert("six");
	print_set(set);

	message("find and erase element six");
	auto it2 = set.find("six");
	if (it2 != set.end()) {
		message("erasing", *it2);
		set.erase(it2);
	} else {
		cout << "not found" << endl;
	}
	print_set(set);

	message("inserting duplicate element five");
	set.insert("five");
	print_set(set);
	cout << endl << endl;
}

void unordered_multiset_demo() {
	unordered_multiset<int> set;
	int temp;

	cout << "Inserting...\n";
	while (temp >= 0) {
		cout << "Enter number: ";
		cin >> temp;
		if (temp >= 0)
			set.insert(temp);
	}

	cout << "{  ";
	for (auto it = set.begin(); it != set.end(); it++)
		cout << *it << "  ";
	cout << "}\n";

	temp = 0;
	cout << "Removing...\n";
	while (temp >= 0) {
		cout << "Enter number: ";
		cin >> temp;
		if (temp >= 0)
			set.erase(temp);
	}
	cout << "{  ";
	for (auto it = set.begin(); it != set.end(); it++)
		cout << *it << "  ";
	cout << "} " << endl << endl;
}

void string_set() {
	cout << "set of strings from initializer list (C++11): " << endl;
	set < string > strset = { "one", "two", "three", "four", "five" };
	cout << "size: " << strset.size() << endl;
	for (string str : strset) {
		cout << str << " ";
	}
	cout << endl << endl;

	cout << "insert element \"six\"" << endl;
	strset.insert("six");
	for (string str : strset) {
		cout << str << " ";
	}
	cout << endl << endl;

	cout << "insert duplicate element \"five\"" << endl;
	strset.insert("five");
	for (string str : strset) {
		cout << str << " ";
	}
	cout << endl << endl;

	cout << "find and erase element \"six\"" << endl;
	set<string>::iterator it = strset.find("six");
	if (it != strset.end()) {
		cout << "found " << *it << endl;
		strset.erase(it);
	} else {
		cout << "not found" << endl;
	}
	for (string str : strset) {
		cout << str << " ";
	}
	cout << endl << endl;
}

int main() {
	set_demo();
	unordered_set_demo();
	string_set();
	unordered_multiset_demo();
	return 0;
}
