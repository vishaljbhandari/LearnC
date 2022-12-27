# include <iostream>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

using namespace std;

class Node {
private:
	int data;
	Node *next;
public:
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int value) {
		data = value;
		next = NULL;
	}
	Node(int value, Node *node) {
		data = value;
		next = node;
	}

	void set_data(int value) {
		data = value;
	}
	void set_next(Node *ptr) {
		next = ptr;
	}
	int get_data() {
		return data;
	}
	Node* get_next() {
		return next;
	}
	~Node() {
		data = 0;
		if (next != NULL) {
			//delete next;
			next = NULL;
		}
	}
	Node* createNode() {
		Node *node = new Node();
		return node;
	}

	Node* createNode(int value) {
		Node *node = new Node(value);
		return node;
	}

	Node* createNode(int value, Node *next) {
		Node *node = new Node(value, next);
		return node;
	}
};

class Stack {
private:
	Node *top;
public:
	Stack() {
		top = NULL;
	}
	Stack(Node *stackTop) {
		top = stackTop;
	}

	Node* getStackTop() {
		return top;
	}
	~Stack() {
		if (top != NULL) {
			clear();
			cout << "Stack is cleared and deleted" << endl;
			top = NULL;
		}
	}

	void print() {
		if (top == NULL) {
			cout << "Stack is empty" << endl;
			return;
		}
		show(top);
		return;
	}

	void print_reverse() {
		if (top == NULL) {
			cout << "Stack is empty" << endl;
			return;
		}
		show_reverse(top);
		return;
	}

	void push(Node *node) {
		node->set_next(top);
		top = node;
		return;
	}

	void push(int value) {
		Node *node = new Node(value);
		push(node);
		return;
	}

	void push() {
		int value;
		cout << "Enter your value to push" << endl;
		cin >> value;
		push(value);
		cout << "Element is pushed into stack" << endl;
		return;
	}

	Node* pop_node() {
		if (top == NULL) {
			return NULL;
		}
		Node *temp = top;
		top = temp->get_next();
		temp->set_next(NULL);
		return temp;
	}

	int pop_data() {
		Node *temp = pop_node();
		if (temp != NULL) {
			int value = temp->get_data();
			delete temp;
			return value;
		} else {
			return 0;
		}
	}
	void pop() {
		if (top != NULL) {
			Node *temp = pop_node();
			delete temp;
			cout << "Stack is popped" << endl;
		} else {
			cout << "Stack is empty" << endl;
		}
	}

	void clear() {
		while (top != NULL) {
			Node *temp = pop_node();
			delete temp;
		}
	}

	void show_reverse(Node *top) {
		if (top == NULL) {
			return;
		} else {
			show_reverse(top->get_next());
		}
		cout << "Node: " << top->get_data() << "" << endl;
		return;
	}

	void show(Node *top) {
		if (top == NULL) {
			return;
		}
		cout << "Node: " << top->get_data() << "" << endl;
		if (top->get_next() == NULL) {
			return;
		} else {
			show(top->get_next());
		}
		return;
	}

};

int main() {
	int ch;
	Stack *stack = new Stack();
	while (1) {
		cout << "Enter your choice" << endl << "1 Show stack" << endl
				<< "2 Show reverse stack" << endl << "3 Push an item" << endl
				<< "4 Pop an item" << endl
				<< "Any other to terminate the program" << endl;
		cin >> ch;
		cout << "- - - - - - - - - - - - -" << endl;
		switch (ch) {
		case 1:
			cout << "Stack information is" << endl << "Top" << endl;
			stack->print();
			cout << "End" << endl;
			break;
		case 2:
			cout << "Reverse stack information is" << endl << "Top" << endl;
			stack->print_reverse();
			cout << "End" << endl;
			break;
		case 3:
			stack->push();
			break;
		case 4:
			stack->pop();
			break;
		case 5:
		default:
			cout << endl;
			delete stack;
			return 0;
		}
		cout << "=========================" << endl;
	}
}
