// gcc -Wall -Wextra -Werror -lstdc++ -lm student.cpp
#include<iostream>
#include<iomanip>
using namespace std;

class Student {
	char name[15];
	int rollno;
	int m1, m2, m3;
	int total, rank;
public:
	void getdata();
	void printdata();
	int isLessThan(Student&);
	void putrank(int r) {
		rank = r;
	}
};

void Student::getdata() {
	cout << "Enter Name : ";
	cin >> name;
	cout << "Enter RollNo. : ";
	cin >> rollno;
	cout << "Enter details of marks..." << endl;
	cout << "DOS : ";
	cin >> m1;
	cout << "WIN : ";
	cin >> m2;
	cout << "UNIX : ";
	cin >> m3;
	total = m1 + m2 + m3;
}

void Student::printdata() {
	cout << setw(8) << rollno << setw(15) << name << setw(5) << m1 << setw(5)
			<< m2 << setw(5) << m3 << setw(7) << total << setw(5) << rank
			<< endl;
}

int Student::isLessThan(Student &S) {
	if (total < S.total)
		return 1;
	return 0;
}

void GetRecords(Student *Sarr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "\nEnter details of Student : " << i + 1 << "\n";
		Sarr[i].getdata();
	}
}

void SortRecords(Student *Sarr, int n) {
	for (int i = 1; i < n; i++) {
		int j = 0;
		for (j = 0; j < n - i; j++) {
			//    if(Sarr[j].total < Sarr[j+1].total)
			if (Sarr[j].isLessThan(Sarr[j + 1])) {
				Student tmp;
				tmp = Sarr[j];
				Sarr[j] = Sarr[j + 1];
				Sarr[j + 1] = tmp;
			}
		}
		//  Sarr[j].rank=j+1;
		Sarr[j].putrank(j + 1);
	}
	Sarr[0].putrank(1);
}

void PrintList(Student *Sarr, int n) {
	cout << "MARK LIST" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << setw(8) << "ROLL NO" << setw(15) << "NAME" << setw(5) << "DOS"
			<< setw(5) << "WIN" << setw(5) << "UNIX" << setw(7) << "TOTAL"
			<< setw(5) << "RANK" << endl;
	cout << "-----------------------------------------------" << endl;
	for (int i = 0; i < n; i++)
		Sarr[i].printdata();
	cout << "-----------------------------------------------" << endl;
}

int main() {
	int n;
	cout << "Enter number of students : ";
	cin >> n;
	Student *Sarr;
	Sarr = new Student[n];
	GetRecords(Sarr, n);
	SortRecords(Sarr, n);
	PrintList(Sarr, n);
	return 0;
}
