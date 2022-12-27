// gcc -lstdc++ -lm class_template.cpp
#include <iostream>
using namespace std;

template<typename T, int size>
class Stack {
	T m_Buffer[size];
	int m_Top { -1 };
public:
	Stack() = default;
	Stack(const Stack<T, size> &obj) {
		m_Top = obj.m_Top;
		for (int i = 0; i <= m_Top; ++i) {
			m_Buffer[i] = obj.m_Buffer[i];
		}
	}
	void Push(const T &elem) {
		m_Buffer[++m_Top] = elem;
	}
	void Pop();
	const T& Top() const {
		return m_Buffer[m_Top];
	}
	bool IsEmpty() {
		return m_Top == -1;
	}
	/*
	 Shorthand notation for class name as return type,
	 because it appears inside the class
	 */
	static Stack Create();
};

template<typename T, int size>
void Stack<T, size>::Pop() {
	--m_Top;
}

template<typename T, int size>
/*
 Long hand notation for class name as return type,
 because it appears outside the class
 */
Stack<T, size> Stack<T, size>::Create() {
	return Stack<T, size>();
}
int main() {
	/*
	 The template parameter list is part of the type of class.
	 The following code will not work.

	 Stack<float, 9> s = Stack<float, 10>::Create();
	 ^
	 */
	Stack<float, 10> s = Stack<float, 10>::Create();
	s.Push(3);
	s.Push(1);
	s.Push(6);
	s.Push(9);
	auto s2(s);
	while (!s2.IsEmpty()) {
		cout << s2.Top() << " ";
		s2.Pop();
	}
	Stack<string, 5> ss;
	ss.Push("Hello");
	auto ss2(ss);
	cout << endl;
	return 0;
}
