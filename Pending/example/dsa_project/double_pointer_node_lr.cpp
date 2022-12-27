#include "double_pointer_node_lr.h"
// Left Right Double Pointer Node
using namespace std;

// Constructors
template<class data_type>
Node::Node() {
	data = *(new data_type());
	left = NULL;
	right = NULL;
}

template<class data_type>
Node::Node(data_type data) :
		data(*new data_type()) {
	left = NULL;
	right = NULL;
}

template<class data_type>
Node::Node(data_type data, Node *left, Node *right) :
		data(data), left(left), right(right) {
}

// Destructors
template<class data_type>
Node::~Node() {
	left = NULL;
	right = NULL;
}

// Setters
template<class data_type>
void Node::set_data(data_type data) {
	this->data = data;
}

template<class data_type>
void Node::set_left(Node *left) {
	this->left = left;
}

template<class data_type>
void Node::set_right(Node *right) {
	this->right = right;
}


// Getters
template<class data_type>
data_type Node::get_data() {
	return this->data;
}

template<class data_type>
Node* Node::get_left() {
	return this->left;
}

template<class data_type>
Node* Node::get_right() {
	return this->right;
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

