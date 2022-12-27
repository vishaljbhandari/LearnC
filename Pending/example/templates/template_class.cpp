#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Exception: public exception {
private:
	const char *msg;
	Exception() {
	}
public:
	explicit Exception(const char *s) throw () :
			msg(s) {
	}
	const char* what() const throw () {
		return msg;
	}
};

template<typename T>
class Stack {
private:
	static const int defaultsize = 10;
	static const int maxsize = 1000;
	int _size;
	int _top;
	T *_stkptr;
public:
	explicit Stack(int s = defaultsize);
	~Stack() {
		delete[] _stkptr;
	}
	T& push(const T&);
	T& pop();
	bool isempty() const {
		return _top < 0;
	}
	bool isfull() const {
		return _top >= _size - 1;
	}
	int top() const {
		return _top;
	}
	int size() const {
		return _size;
	}
};

template<typename T>
Stack<T>::Stack(int s) {
	if (s > maxsize || s < 1)
		throw Exception("invalid stack size");
	else
		_size = s;
	_stkptr = new T[_size];
	_top = -1;
}

template<typename T>
T& Stack<T>::push(const T &i) {
	if (isfull())
		throw Exception("stack full");
	return _stkptr[++_top] = i;
}

template<typename T>
T& Stack<T>::pop() {
	if (isempty())
		throw Exception("stack empty");
	return _stkptr[_top--];
}

template<typename T>
T summer(T v) {
	return v;
}

template<typename T, typename ... Args>
T summer(T first, Args ... args) {
	return first + summer(args...);
}

template<typename T>
T rcatenate(T v) {
	return v;
}

template<typename T, typename ... Args>
T rcatenate(T first, Args ... args) {
	return rcatenate(args...) + " " + first;
}

int main() {
	try {
		Stack<int> int_stack(5);

		cout << "int_stack size: " << int_stack.size() << endl;
		cout << "int_stack top: " << int_stack.top() << endl;

		for (int item : { 1, 2, 3, 4, 5 }) {
			int_stack.push(item);
		}

		cout << "int_stack top after pushes: " << int_stack.top() << endl;
		cout << "int_stack is " << (int_stack.isfull() ? "" : "not ") << "full"
				<< endl;

		while (!int_stack.isempty()) {
			cout << "popped " << int_stack.pop() << endl;
		}
	} catch (Exception &exception) {
		cout << "Stack error: " << exception.what() << endl;
	}

	try {
		Stack<string> string_stack(5);

		cout << "string_stack size: " << string_stack.size() << endl;
		cout << "string_stack top: " << string_stack.top() << endl;

		for (const char *str : { "one", "two", "three", "four", "five" }) {
			string_stack.push(str);
		}

		cout << "string_stack top after pushes: " << string_stack.top() << endl;
		cout << "string_stack is " << (string_stack.isfull() ? "" : "not ")
				<< "full" << endl;

		while (!string_stack.isempty()) {
			cout << "popped " << string_stack.pop() << endl;
		}
	} catch (Exception &exception) {
		cout << "Stack error: " << exception.what() << endl;
	}

	string str1 = "biz", str2 = "fox", str3 = "wiz";
	string concatenated_string = rcatenate(str1, str2, str3);
	cout << "reverse concatenated = " << concatenated_string << endl;

	cout << "summer(1, 2, 13, 100, 200) = " << summer(1, 2, 13, 100, 200)
			<< endl;

	return 0;
}
