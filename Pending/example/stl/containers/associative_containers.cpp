#include <iostream>
#include <set>
#include <functional>
#include <map>
#include <string>
using namespace std;

void Set() {
	cout << "set as associative containers" << endl;
	multiset<int, greater<int>> s { 8, 2, 0, 9, 5 };
	//No push_back, only insert as elements are ordered automatically
	s.insert(1);

	//Only multiset allows duplicates
	s.insert(3);
	s.insert(3);
	s.insert(3);

	auto itr = s.begin();
	// *itr = 3;
	while (itr != s.end()) {
		cout << *itr++ << " ";
	}
	cout << endl;

	// Erase by key or position
	s.erase(0);
	s.erase(s.begin());
	itr = s.find(9);
	if (itr != s.end()) {
		cout << "Element found" << endl;
	} else {
		cout << "Not found" << endl;
	}
	auto found = s.equal_range(3);
	while (found.first != found.second) {
		cout << *found.first++ << " ";
	}
	cout << endl;
}

void Map() {
	cout << "map as associative containers" << endl;
	multimap<int, string> m { { 1, "Superman" }, { 2, "Batman" }, { 3,
			"Green Lantern" } };
	m.insert(pair<int, string>(8, "Aquaman"));
	m.insert(make_pair(6, "Wonder Woman"));
	m.insert(make_pair(6, "Powergirl"));

	// Only map support [] operator
	/*
	 m[0] = "Flash";
	 m[0] = "Kid Flash";
	 */
	auto itr = m.begin();
	m.erase(0);
	// returns a pair that contains begin & end of the range.
	auto found = m.equal_range(6);
	while (found.first != found.second) {
		cout << found.first->first << ":" << found.first->second << endl;
		found.first++;
	}

	cout << itr->first << ":" << itr->second << endl;

	// Avoid using [] for searching as it will insert an empty element if a key cannot be found
	// cout << "10:" << m[10] << endl;

	for (const auto &x : m) {
		cout << x.first << ":" << x.second << endl;
	}

	// Lookup by key
	itr = m.find(1);
	if (itr != m.end()) {
		cout << "Found:" << itr->second << endl;
	} else {
		cout << "Not found" << endl;
	}
}

int main() {
	Map();
	cout << endl;
	Set();
	return 0;

}
