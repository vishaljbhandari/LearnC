#include "single_pointer_node.h"
using namespace std;

// Constructors
template<class data_type>
Node::Node() {
	data = *(new data_type());
	next = NULL;
}

template<class data_type>
Node::Node(data_type data) :
		data(*new data_type()) {
	next = NULL;
}

template<class data_type>
Node::Node(data_type data, Node *next) :
		data(data), next(next) {
}

// Destructors
template<class data_type>
Node::~Node() {
	next = NULL;
}

// Setters
template<class data_type>
void Node::set_data(data_type data) {
	this->data = data;
}

template<class data_type>
void Node::set_next(Node *next) {
	this->next = next;
}

// Getters
template<class data_type>
data_type Node::get_data() {
	return this->data;
}

template<class data_type>
Node* Node::get_next() {
	return this->next;
}

// Factory Methods
template<class data_type>
static Node* Node::create_node(data_type data) {
	return new Node(data);
}

template<class data_type>
static Node* Node::create_node() {
	return new Node(data);
}

