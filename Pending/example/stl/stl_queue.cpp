// gcc -lstdc++ -lm stl_queue.cpp

#include <iostream>
#include <queue>
#include <list>
#include <deque>
#include <string>
using namespace std;

template<typename T>
void print_queue(const T &que) {
	size_t sz = que.size();
	cout << "size: " << sz;
	if (sz)
		cout << " front: " << que.front() << " back: " << que.back();
	cout << endl;
}

// print a simple message
void message(const char *s) {
	cout << s << endl;
}

int main() {
	cout << "initialize queue from list" << endl;
	list<int> lst = { 1, 2, 3, 4, 5 };
	queue<int, list<int>> que(lst);	// constructor copies to new list

	cout << "lst has " << lst.size() << " entries; que has " << que.size()
			<< " entries." << endl;

	cout << "pop all from que" << endl;
	while (!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;

	cout << "lst has " << lst.size() << " entries; que has " << que.size()
			<< " entries." << endl;

	cout << "contents of lst after que is emptied:" << endl;
	for (auto it = lst.begin(); it != lst.end(); it++) {// auto is C++11 only
		cout << *it << " ";
	}
	cout << endl;

	queue < string > sque;	// default queue uses deque object
	cout << "push strings onto qd" << endl;
	sque.push("one");
	sque.push("two");
	sque.push("three");
	sque.push("four");
	sque.push("five");
	cout << "size of sque: " << sque.size() << endl;
	cout << "pop all from sque" << endl;
	while (!sque.empty()) {
		cout << sque.front() << " ";
		sque.pop();
	}
	cout << endl;
	cout << "size of sque: " << sque.size() << endl;

	// queue from list
	message("initialize queue from list");
	queue<int, list<int>> ique(lst);    // constructor copies to new list
	print_queue(ique);

	message("pop all from ique");
	while (!ique.empty()) {
		cout << ique.front() << " ";
		ique.pop();
	}
	cout << endl;
	print_queue(ique);

	// default queue (deque)
	queue < string > squeue;
	message("push strings onto squeue");
	for (string str : { "one", "two", "three", "four", "five" }) {
		squeue.push(str);
	}
	print_queue (squeue);

	message("pop all from squeue");
	while (!squeue.empty()) {
		cout << squeue.front() << " ";
		squeue.pop();
	}
	cout << endl;
	print_queue(squeue);

	deque<int> numbers;
	int temp = 0;

	cout << "Pushing Back...\n";
	while (temp >= 0) {
		cout << "Enter Number: ";
		cin >> temp;
		if (temp >= 0)
			numbers.push_back(temp);
	}

	deque<int>::iterator itr;
	cout << "{  ";
	for (itr = numbers.begin(); itr != numbers.end(); itr++)
		cout << *itr << "  ";
	cout << "}";

	temp = 0;
	cout << endl;
	cout << "Pushing Front...\n";
	while (temp >= 0) {
		cout << "Enter Number: ";
		cin >> temp;
		if (temp >= 0)
			numbers.push_front(temp);
	}

	cout << "{  ";
	for (itr = numbers.begin(); itr != numbers.end(); itr++)
		cout << *itr << "  ";
	cout << "}";

	queue<int> nums;
	temp = 0;

	cout << "Pushing...\n";
	while (temp >= 0) {
		cout << "Enter numbers: ";
		cin >> temp;
		if (temp >= 0)
			nums.push(temp);
	}

	cout << "{  ";
	while (nums.size() > 0) {
		cout << nums.front();
		nums.pop();
		cout << "  ";
	}
	cout << "}";

	return 0;
}
