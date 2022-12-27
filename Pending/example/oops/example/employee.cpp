// gcc -Wall -Wextra -Werror -lstdc++ -lm employee.cpp
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;

class employee {
	int card_number, age, salary;
	char name[20];
public:
	employee() {
		card_number = 0;
		age = 0;
		salary = 0;
		cout << "default constructor" << endl;
	}

	employee(int cn) {
		card_number = cn;
		salary = 5000;
		age = 25;
		strcpy(name, "employee");
		cout << "double argument constructor" << endl;
	}

	employee(int cn, const char *n, int age1, int salary1) {
		card_number = cn;
		strcpy(name, n);
		age = age1;
		salary = salary1;
		cout << "4 argument constructor.." << endl;
	}

	employee(employee &e) {
		card_number = e.card_number;
		strcpy(name, e.name);
		age = e.age;
		salary = e.salary;
		cout << "copy constructor..." << endl;
	}
	void get_data();
	void print_data();
	void total_annual_salary();
};

void employee::get_data() {
	cout << "input detail.." << endl << "enter card number : ";
	cin >> card_number;
	cout << "name : ";
	cin >> name;
	cout << "age : ";
	cin >> age;
	cout << "salary : ";
	cin >> salary;
}

void employee::print_data() {
	cout << "output detail.." << endl << "card number : " << card_number << endl
			<< "name : " << name << endl << "age : " << age << endl
			<< "salary : " << salary << endl;
}

void employee::total_annual_salary() {
	long x = salary * 12l;
	if (age >= 45) {
		cout << "employee age above 45 year, age bonus ; " << "3000" << endl;
		x = x + 1000;
	}
	cout << "total annual salary : " << x << endl;
}

int main() {
	cout << "employee class object 1 declaration..." << endl;
	employee e1;
	e1.print_data();
	e1.total_annual_salary();
	cout << endl << "employee class object 2 declaration..." << endl;
	employee e2(2);
	e2.print_data();
	e2.total_annual_salary();
	cout << endl << "employee class object 3 declaration..." << endl;
	employee e3(3, "raj kumar", 46, 6000);
	e3.print_data();
	e3.total_annual_salary();
	cout << endl << "employee class object 4 declaration..." << endl;
	employee e4(e3);
	e4.print_data();
	e4.total_annual_salary();
	cout << endl << "employee class object 5 declaration..." << endl;
	employee e5;
	e5.get_data();
	e5.print_data();
	e5.total_annual_salary();
	return 0;
}
