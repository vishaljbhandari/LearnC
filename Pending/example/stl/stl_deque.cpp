#include <iostream>
#include <deque>
using namespace std;

// report deque info
template<typename T>
void printDeque(T &d) {
	size_t sz = d.size();
	cout << "size: " << sz;
	if (sz)
		cout << " front: " << d.front() << " back: " << d.back();
	cout << endl;
}

// print deque
template<typename T>
void printDequeContents(T &d) {
	if (d.empty())
		return;
	for (auto v : d)
		cout << v << " ";
	cout << endl;
}

// print a simple message
void message(const char *s) {
	cout << s << endl;
}

int main() {
	message("Creating int deque");
	deque<int> dq = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // Deque from initializer list (C++11)

	printDeque(dq);
	printDequeContents(dq);

	cout << "size: " << dq.size() << endl;
	cout << "front: " << dq.front() << endl;
	cout << "back: " << dq.back() << endl;

	cout << "insert 42 at begin + 5: " << endl;
	dq.insert(dq.begin() + 5, 42);

	cout << "size: " << dq.size() << endl;
	cout << "dq[5]: " << dq[5] << endl;

	cout << "erase at begin + 5: " << endl;
	dq.erase(dq.begin() + 5);
	cout << "size: " << dq.size() << endl;
	cout << "dq[5]: " << dq[5] << endl;

	cout << "push_back 47: " << endl;
	dq.push_back(47);
	cout << "size: " << dq.size() << endl;
	cout << "dq.back() " << dq.back() << endl;

	cout << "push_front 192: " << endl;
	dq.push_front(192);
	cout << "size: " << dq.size() << endl;
	cout << "dq.front() " << dq.front() << endl;

	cout << "dq.pop_front() " << endl;
	dq.pop_front();
	cout << "size: " << dq.size() << endl;
	cout << "dq.pop_back() " << endl;
	dq.pop_back();
	cout << "size: " << dq.size() << endl;

	// range-based iterator (C++11)
	cout << "range-based iterator (C++11): " << endl;
	for (int &v : dq) {
		cout << v << " ";
	}
	cout << endl << endl;

	message("Creating string deque");
	deque < string > d1 = { "one", "two", "three" };

	printDeque (d1);
	printDequeContents(d1);

	message("push back values");
	d1.push_back("four");
	d1.push_back("five");

	printDeque(d1);
	printDequeContents(d1);

	message("pop from front");
	d1.pop_front();
	printDeque(d1);
	printDequeContents(d1);

	message("pop from back");
	d1.pop_back();
	printDeque(d1);
	printDequeContents(d1);

	message("push front");
	d1.push_front("newfront");
	printDeque(d1);
	printDequeContents(d1);

	message("push back");
	d1.push_back("newback");
	printDeque(d1);
	printDequeContents(d1);

	return 0;
}
