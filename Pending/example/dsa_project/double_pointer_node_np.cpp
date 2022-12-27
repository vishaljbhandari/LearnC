#include "double_pointer_node_np.h"
// Next Previous Double Pointer Node
using namespace std;

// Constructors
template<class data_type>
Node::Node() {
	data = *(new data_type());
	next = NULL;
	previous = NULL;
}

template<class data_type>
Node::Node(data_type data) :
		data(*new data_type()) {
	next = NULL;
	previous = NULL;
}

template<class data_type>
Node::Node(data_type data, Node *next, Node *previous) :
		data(data), next(next), previous(previous) {
}

// Destructors
template<class data_type>
Node::~Node() {
	next = NULL;
	previous = NULL;
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

template<class data_type>
void Node::set_previous(Node *previous) {
	this->previous = previous;
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

template<class data_type>
Node* Node::get_previous() {
	return this->previous;
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

