// gcc -lstdc++ -lm sequence_containers.cpp
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;

void Array() {
	cout << "array as sequence containers" << endl;
	std::array<int, 5> arr { 3, 1, 8, 5, 9 };
	for (int i = 0; i < arr.size(); ++i) {
		arr[i] = i;
	}
	auto itr = arr.begin();
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	arr.data();
}

void Vector() {
	cout << "vector as sequence containers" << endl;
	std::vector<int> coll { 1, 2, 3, 4 };
	for (int i = 0; i < 5; ++i) {
		coll.push_back(i * 10);
		std::cout << coll.size() << std::endl;
	}
	coll[0] = 100;
	//for (int i = 0; i< coll.size(); ++i) {
	//	std::cout << coll[i] << " ";
	//}
	auto itr = coll.begin();
	while (itr != coll.end()) {
		std::cout << *itr++ << " ";
	}
	coll.insert(coll.begin(), 700);
	coll.erase(coll.end() - 5);
	coll.pop_back();
}

void Deque() {
	cout << "deque as sequence containers" << endl;
	std::deque<int> coll;
	for (int i = 0; i < 5; ++i) {
		coll.push_back(i * 10);
	}
	for (int i = 0; i < 5; ++i) {
		coll.push_front(i * 10);
	}
	coll[0] = 100;
	//for (int i = 0; i< coll.size(); ++i) {
	//	std::cout << coll[i] << " ";
	//}
	auto itr = coll.begin();
	while (itr != coll.end()) {
		std::cout << *itr++ << " ";
	}
	coll.insert(coll.begin(), 700);
	coll.erase(coll.end() - 5);
	coll.pop_back();
	coll.pop_front();
}

void List() {
	cout << "list as sequence containers" << endl;
	std::list<int> coll;
	for (int i = 0; i < 5; ++i) {
		coll.push_back(i * 10);
	}
	auto itr = coll.begin();
	while (itr != coll.end()) {
		std::cout << *itr++ << " ";
	}
	itr = coll.begin();
	coll.insert(itr, 800);
	coll.erase(itr);
}

void ForwardList() {
	cout << "forward list as sequence containers" << endl;
	std::forward_list<int> coll;
	for (int i = 0; i < 10; ++i) {
		coll.push_front(i);
	}
	for (auto x : coll) {
		std::cout << x << " ";
	}
	coll.insert_after(coll.begin(), 10);
	coll.erase_after(coll.begin());
}

int main() {
	Array();
	cout << endl;
	Vector();
	cout << endl << endl;
	Deque();
	cout << endl << endl;
	List();
	cout << endl << endl;
	ForwardList();
	cout << endl;
	return 0;
}
