#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Employee {
	string m_Name;
	int m_Id;
	string m_ProgLang;
public:
	Employee(const string &name, int id, const string &language) :
			m_Name(name), m_Id(id), m_ProgLang(language) {

	}
	const string& GetName() const {
		return m_Name;
	}
	int GetId() const {
		return m_Id;
	}
	const string& GetProgrammingLanguage() const {
		return m_ProgLang;
	}
	bool operator <(const Employee &employee) const {
		return m_Id < employee.m_Id;
	}
};

struct EmpIds {
	vector<int> emp_ids;
	void operator()(const Employee &employee) {
		if (employee.GetProgrammingLanguage() == "C++")
			emp_ids.push_back(employee.GetId());
	}
};

// Custom comparator for associative containers
struct EmpCompare {
	bool operator ()(const Employee &e1, const Employee &e2) const {
		return e1.GetId() < e2.GetId();
	}
};

int main() {
	// Employee using vector
	vector<Employee> employee_vector { Employee { "Umar", 101, "C++" },
			Employee { "Bob", 202, "Java" }, Employee { "Joey", 200, "C++" } };
	// Use callback to avoid overloading comparison operators
	sort(employee_vector.begin(), employee_vector.end(),
			[](const auto &employee_1, const auto &employee_2) {
				return employee_1.GetName() < employee_2.GetName();
			});

	for (const auto &employee : employee_vector) {
		cout << "Id:" << employee.GetId() << " | Name:" << employee.GetName()
				<< " | Language:" << employee.GetProgrammingLanguage() << endl;
	}

	int cppCount { };
	for (const auto &employee : employee_vector) {
		if (employee.GetProgrammingLanguage() == "C++")
			++cppCount;
	}

	// gives more information to the reader as compared to a for loop
	cppCount = count_if(employee_vector.begin(), employee_vector.end(),
			[](const auto &employee) {
				return employee.GetProgrammingLanguage() == "C++";
			});
	cout << "Count:" << cppCount << endl;

	// Find if any employee knows Java
	auto emp_itr = find_if(employee_vector.begin(), employee_vector.end(),
			[](const auto &employee) {
				return employee.GetProgrammingLanguage() == "Java";
			});

	if (emp_itr != employee_vector.end()) {
		cout << "Found:" << emp_itr->GetName() << " is a Java programmer"
				<< endl;
	}

	// Print all employee names
	for_each(employee_vector.begin(), employee_vector.end(),
			[](const auto &employee) {
				cout << employee.GetName() << endl;
			});

	// Get ids of all employees that know C++
	auto foundIds = for_each(employee_vector.begin(), employee_vector.end(),
			EmpIds());
	for (int id : foundIds.emp_ids) {
		cout << "Id:" << id << endl;
	}

	// Employee using Set operations

	// Using custom comparator
	set<Employee, EmpCompare> employee_set {
			//				 ^^^^
			Employee { "Umar", 101, "C++" }, Employee { "Bob", 202, "Java" },
			Employee { "Joey", 200, "C++" } };

	for (const auto &employee : employee_set) {
		cout << "Id:" << employee.GetId() << " | Name:" << employee.GetName()
				<< " | Language:" << employee.GetProgrammingLanguage() << endl;
	}
	return 0;
}
