// gcc -lstdc++ -lm stl_map.cpp

#include <iostream>
#include <string>
#include <map>
using namespace std;

// print a pair
template<typename T1, typename T2>
void print_pair(pair<T1, T2> &p) {
	cout << p.first << ": " << p.second << endl;
}

// print the elements of the map
template<typename T>
void print_map(T &m) {
	if (m.empty())
		return;
	for (auto x : m)
		print_pair(x);
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

class Person {
	friend class PersonLessThan;
public:
	string firstName, lastName;
	Person(const string &_firstName, const string &_lastName) :
			firstName(_firstName), lastName(_lastName) {
	}
};

class PersonLessThan {
public:
	bool operator( )(const Person &p1, const Person &p2) const {
		if (p1.lastName < p2.lastName)
			return (true);
		else if (p1.lastName == p2.lastName)
			return (p1.firstName < p2.firstName);
		else
			return (false);
	}
};

int main() {
	message("map of strings from initializer list");
	map < string, string > mapstr = { { "George", "Father" }, { "Ellen",
			"Mother" }, { "Ruth", "Daughter" }, { "Spike", "Neighbor's Son" } };

	message("size", mapstr.size());
	message("get some values");
	message("George", mapstr["George"]);
	message("Ellen", mapstr.at("Ellen"));
	message("Spike", mapstr.find("Spike")->second);
	message("print_map:");
	print_map (mapstr);

	message("insert an element");
	mapstr.insert( { "Luke", "Neighbor" });
	message("size", mapstr.size());
	print_map(mapstr);

	cout << "insert a duplicate:" << endl;
	auto rp = mapstr.insert( { "Luke", "Neighbor" });
	if (rp.second) {
		message("insert succeeded");
		print_pair(*rp.first);
	} else {
		message("insert failed");
	}
	message("size", mapstr.size());
	print_map(mapstr);

	message("find and erase Spike");
	auto it = mapstr.find("Spike");
	if (it != mapstr.end()) {
		message("found");
		print_pair(*it);
		mapstr.erase(it);
		message("erased");
	} else {
		message("not found");
	}
	message("size", mapstr.size());
	print_map(mapstr);

	multimap<int, string> this_map;
	int temp;
	string str;
	pair<int, string> p;

	cout << "Inserting...[Enter negative number to break]" << endl;
	while (temp >= 0) {
		cout << "Enter key: ";
		getline(cin, str);
		temp = stoi(str);
		if (temp >= 0) {
			p.first = temp;
			cout << "Enter name: ";
			getline(cin, str);
			p.second = str;
			this_map.insert(p);
		}
	}

	cout << "{   ";
	for (auto it = this_map.begin(); it != this_map.end(); it++)
		cout << it->first << "->" << it->second << "   ";
	cout << "}\n";

	temp = 0;
	cout << "Removing... [Enter negative number to break]" << endl;
	while (temp >= 0) {
		cout << "Enter key: ";
		getline(cin, str);
		temp = stoi(str);
		if (temp >= 0)
			this_map.erase(temp);
	}

	cout << "{   ";
	for (auto it = this_map.begin(); it != this_map.end(); it++)
		cout << it->first << "->" << it->second << "   ";
	cout << "}";

	cout << "map of strings from initializer list (C++11): " << endl;
	map < string, string > strmap = { { "George", "Father" }, { "Ellen",
			"Mother" }, { "Ruth", "Daughter" }, { "Spike", "Neighbor's Son" } };
	map<string, string>::iterator itr;	// will use throughout

	cout << "size is " << strmap.size() << endl;
	cout << "check a couple of key/value pairs" << endl;
	cout << "George is " << strmap["George"] << endl;
	cout << "Ellen is " << strmap.find("Ellen")->second << endl;
	cout << endl;

	cout << "iterate the set" << endl;
	for (itr = strmap.begin(); itr != strmap.end(); itr++) {
		cout << itr->first << " is " << itr->second << endl;
	}
	cout << endl;

	cout << "insert an element" << endl;
	// strmap.insert( pair<string, string>("Luke", "Neighbor") );	// pre-C++11
	strmap.insert( { "Luke", "Neighbor" });	// initializer list (C++11)
	cout << "inserted - size is " << strmap.size() << endl;
	for (it = strmap.begin(); it != strmap.end(); it++) {
		cout << it->first << " is " << it->second << endl;
	}
	cout << endl;

	cout << "insert a duplicate" << endl;
	strmap.insert( { "Luke", "Neighbor" });
	cout << "after insert size is " << strmap.size() << endl;
	for (it = strmap.begin(); it != strmap.end(); it++) {
		cout << it->first << " is " << it->second << endl;
	}
	cout << endl;

	cout << "find and erase an element" << endl;
	it = strmap.find("Luke");
	if (it != strmap.end()) {
		cout << "found " << it->first << ":" << it->second << endl;
		strmap.erase(it);
		cout << "erased - size is " << strmap.size() << endl;
	} else {
		cout << "not found" << endl;
	}
	for (it = strmap.begin(); it != strmap.end(); it++) {
		cout << it->first << " is " << it->second << endl;
	}
	cout << endl;

	map<int, string> iEmployees;
	// 1) Assignment using array index notation
	iEmployees[5234] = "Mike C.";
	iEmployees[3374] = "Charlie M.";
	iEmployees[1923] = "David D.";

	cout << "iEmployees[3374]=" << iEmployees[3374] << endl;
	cout << "Map size: " << iEmployees.size() << endl;
	cout << endl << "Natural Order:" << endl;
	for (map<int, string>::iterator ii = iEmployees.begin();
			ii != iEmployees.end(); ++ii) {
		cout << (*ii).first << ": " << (*ii).second << endl;
	}
	cout << endl << "Reverse Order:" << endl;
	for (map<int, string>::reverse_iterator ii = iEmployees.rbegin();
			ii != iEmployees.rend(); ++ii) {
		cout << (*ii).first << ": " << (*ii).second << endl;
	}

	map<string, int> sEmployees;
	// 1) Assignment using array index notation
	sEmployees["Mike C."] = 5234;
	sEmployees["Charlie M."] = 3374;
	// 2) Assignment using member function insert() and STL pair
	sEmployees.insert(std::pair<string, int>("David D.", 1923));
	// 3) Assignment using member function insert() and "value_type()"
	sEmployees.insert(map<string, int>::value_type("John A.", 7582));
	// 4) Assignment using member function insert() and "make_pair()"
	sEmployees.insert(std::make_pair("Peter Q.", 5328));
	cout << endl << "Map size: " << sEmployees.size() << endl;
	for (map<string, int>::iterator ii = sEmployees.begin();
			ii != sEmployees.end(); ++ii) {
		cout << (*ii).first << ": " << (*ii).second << endl;
	}

	map<Person, bool, PersonLessThan> M;
	Person p_1("Wilma", "Flintstone");
	Person p_2("Betty", "Rubble");
	Person p_3("Fred", "Flintstone");
	Person p_4("Barney", "Rubble");

	M[p_1] = true;
	M[p_2] = false;
	M[p_3] = true;
	M[p_4] = true;

	for (map<Person, bool>::iterator ii = M.begin(); ii != M.end(); ++ii) {
		cout << ((*ii).first).lastName << ", " << ((*ii).first).firstName
				<< ": " << (*ii).second << endl;
	}

	map<int, string> nicknames { { 1, "biz" }, { 2, "fox" }, { 3, "wiz" } };
	for (auto map_items : nicknames) {
		cout << map_items.first << ", " << map_items.second << endl;
	}

	return 0;
}
