#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

void unordered_multiset_demo() {
	/*
	 unordered_multiset
	 (i) Elements can be stored in any order.
	 (ii) Duplicate elements can be stored.
	 (iii) Hash-table used to store elements.
	 (iv) We can erase only the element for which iterator position is given.
	 */
	unordered_multiset < string > uo_multiset;
	//elements are stored based on the hash, but in unspecified order
	uo_multiset.insert("Hulk");
	uo_multiset.insert("Batman");
	uo_multiset.insert("Green Lantern");
	uo_multiset.insert("Wonder Woman");
	uo_multiset.insert("Iron man");
	uo_multiset.insert("Iron man");
	uo_multiset.insert("Wolverine");
	uo_multiset.insert("Dr. Strange");
	uo_multiset.insert("Hawkman");

	for (const auto set : uo_multiset) {
		cout << "Bucket #:" << uo_multiset.bucket(set) << " contains :" << set
				<< endl;
	}
	cout << "Bucket count:" << uo_multiset.bucket_count() << endl;
	cout << "Number of elements:" << uo_multiset.size() << endl;
	cout << "Load factor:" << uo_multiset.load_factor() << endl;
}

void unordered_multimap_demo() {
	unordered_multimap < std::string, std::string > uo_multimap;
	//Only unordered_map support [] operator
	/*
	 uo_multimap["Batman"] = "Brue Wayne";
	 uo_multimap["Superman"] = "Clark Kent";
	 uo_multimap["Hulk"] = "Bruce Banner";
	 */
	uo_multimap.insert(make_pair("Batman", "Bruce Wayne"));
	uo_multimap.insert(make_pair("Batman", "Matches Malone"));
	uo_multimap.insert(make_pair("Superman", "Clark Kent"));
	uo_multimap.insert(make_pair("Hulk", "Bruce Banner"));

	for (const auto &uo_mmap : uo_multimap) {
		cout << "Bucket #:" << uo_multimap.bucket(uo_mmap.first) << " ->"
				<< uo_mmap.first << ":" << uo_mmap.second << endl;
	}
}

class Employee {
	std::string m_Name;
	int m_Id;
public:
	Employee(const std::string &n, int id) :
			m_Name(n), m_Id(id) {

	}
	const std::string& GetName() const {
		return m_Name;
	}
	int GetId() const {
		return m_Id;
	}
};

//Custom hash function
struct EmployeeHash {
	size_t operator()(const Employee &emp) const {
		auto s1 = std::hash<std::string> { }(emp.GetName());
		auto s2 = std::hash<int> { }(emp.GetId());
		return s1 ^ s2;
	}
};

//Custom function object for equality
struct EmpEquality {
	bool operator()(const Employee &e1, const Employee e2) const {
		return e1.GetId() == e2.GetId();
	}
};

void hash_demo() {
	hash < string > hsh;
	//Hash is computed by the function object
	cout << "Hash: " << hsh("Hello") << endl;

	unordered_set<Employee, EmployeeHash, EmpEquality> uo_set;
	uo_set.insert(Employee("Umar", 123));
	uo_set.insert(Employee("Bob", 678));
	uo_set.insert(Employee("Joey", 612));

	for (const auto &uos : uo_set) {
		cout << uos.GetId() << ":" << uos.GetName() << endl;
	}
}

int main() {
	unordered_multiset_demo();
	unordered_multimap_demo();
	hash_demo();
	return 0;
}
