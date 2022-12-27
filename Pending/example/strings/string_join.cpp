// gcc -Wall -Wextra -Werror -lstdc++ -lm string_join.cpp
#include <iostream>
#include <vector>
using namespace std;

template<typename cT, typename retT = cT,
		typename sepT = decltype(cT::value_type)>
retT joinContainer(const cT &o, const sepT &sep) {
	retT out;
	auto it = o.begin();
	while (it != o.end()) {
		out += *it;
		if (++it != o.end())
			out += sep;
	}
	return out;
}

int main() {
	string s1("This is a string");
	string s2("This is also a string");
	string s3("Yet another string");

	// join the characters of a string
	cout << joinContainer(s1, ':') << endl;

	// join strings from a vector, returning a string
	vector < string > vs( { s1, s2, s3 });
	cout << joinContainer<vector<string>, string>(vs, ", ") << endl;
	return 0;
}
