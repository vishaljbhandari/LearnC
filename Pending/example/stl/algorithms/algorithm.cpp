#include <iostream>
#include <vector>
#include <locale>
#include <algorithm>
using namespace std;

// functor for count_if
class strhas {
	char needle;
	strhas() {
	}
public:
	strhas(char c) :
			needle(c) {
	}
	bool operator()(string &haystack) {
		return haystack.find_first_of(needle) != haystack.npos;
	}
};

string uppercase(string &s) {
	string out;
	for (char c : s)
		out += toupper(c);
	return out;
}

int main() {
	vector < string > str_vector { "one", "two", "three", "four", "five", "six",
			"seven", "eight", "nine", "ten" };
	vector<int> int_vector { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<string>::iterator str_vector_it;
	vector<int>::iterator int_vector_it;
	string sentence = "big light in sky slated to appear in east";

	// count
	cout << "push two extra sevens onto str_vector" << endl;
	str_vector.push_back("seven");
	str_vector.push_back("seven");
	cout << "count \"seven\" in str_vector: "
			// int count(Iterator first, Iterator last, T &value)		// it searches and counts value from container between given iterator range (begin-end)
			// it returns number of instances, value was found in container
			<< count(str_vector.begin(), str_vector.end(), "seven") << endl;
	cout << "pop those extra sevens" << endl;
	str_vector.pop_back();
	str_vector.pop_back();

	// find
	cout << "find 7 in int_vector: ";
	// InputIterator find (InputIterator first, InputIterator last, const T& value)		// it searches value from container between given iterator range (begin-end)
	// it returns iterator position of first occurrence instances of value  found in container
	int_vector_it = find(int_vector.begin(), int_vector.end(), 7);
	if (int_vector_it != int_vector.end()) {
		cout << "found: " << *int_vector_it << endl;
	} else {
		cout << "not found" << endl;
	}

	// equal
	string _palindrome = "radar";
	if (equal(_palindrome.begin(),
			_palindrome.begin() + (_palindrome.size() / 2),
			_palindrome.rbegin())) {
		cout << _palindrome << " is";
	} else {
		cout << _palindrome << " is not";
	}
	cout << " a palindrome" << endl;

	// search
	string match = "slated";
	cout << "string is \"" << sentence << "\", search term is \"" << match
			<< "\"" << endl;
	cout << "search: ";
	string::iterator search_it = search(sentence.begin(), sentence.end(),
			match.begin(), match.end());
	if (search_it != sentence.end()) {
		cout << "search term found at position "
				<< size_t(search_it - sentence.begin()) << endl;
	} else {
		cout << "search term not found" << endl;
	}

	// show str_vector before count_if
	cout << "str_vector is: ";
	for (string str : str_vector)
		cout << str << " ";
	cout << endl;

	// count_if
	cout << "count_if str_vector has 's' (functor): ";
	cout << count_if(str_vector.begin(), str_vector.end(), strhas('s')) << endl;

	// C++11 count_if with lambda expression
	cout << "count_if str_vector has 's' (lambda): ";
	cout << count_if(str_vector.begin(), str_vector.end(), [](string &str) {
		return str.find_first_of('s') != str.npos;
	}
	) << endl;

	// for_each
	cout << "for_each uppercase: ";
	for_each(str_vector.begin(), str_vector.end(), [](string &str) {
		cout << uppercase(str) << " ";
	});
	cout << endl;

	// transform
	cout << "transform: " << endl;
	vector<int> transform_int_vector;
	cout << "int_vector before transformation: ";
	for (int item : int_vector)
		cout << item << " ";
	cout << endl;
	transform_int_vector.resize(int_vector.size());	// make space for transformation
	transform(int_vector.begin(), int_vector.end(),
			transform_int_vector.begin(), [](int item) {
				return ++item;
			});

	cout << "transform_int_vector after transformation: ";
	for (int item : transform_int_vector)
		cout << item << " ";
	cout << endl;

	transform(int_vector.begin(), int_vector.end(),
			transform_int_vector.begin(), transform_int_vector.begin(),
			[](int i, int j) {
				return i + j;
			});
	cout << "transform_int_vector after second transformation: ";
	for (int item : transform_int_vector)
		cout << item << " ";
	cout << endl;

	cout << "int_vector after all transformations: ";
	for (int item : int_vector)
		cout << item << " ";
	cout << endl;

	cout << "string before initial cap transformation: " << sentence << endl;
	char last = 0;
	transform(sentence.begin(), sentence.end(), sentence.begin(),
			[&last](char ch) {
				if (last == ' ' || last == 0) {
					last = ch;
					return toupper(ch);
				} else {
					last = ch;
					return tolower(ch);
				}
			});
	cout << "string after initial cap transformation: " << sentence << endl;

	return 0;
}
