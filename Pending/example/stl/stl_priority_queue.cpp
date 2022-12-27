// gcc -lstdc++ -lm stl_priority_queue.cpp

#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> numbers;
	int counter = 0;

	cout << "Pushing..." << endl;
	while (counter < 10) {
		int temp;
		cout << "Enter numbers: ";
		cin >> temp;
		numbers.push(temp);
		counter++;
	}

	cout << endl << "Priority queue contents : {  ";
	while (numbers.size() > 0) {
		cout << numbers.top();
		numbers.pop();
		cout << "  ";
	}
	cout << "}" << endl;

	return 0;
}
