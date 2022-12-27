#include <iostream>
// Next Previous Double Pointer Node
using namespace std;

template<class data_type>
class Node {
	data_type data;
	Node *next;
	Node *previous;
public:
	// Constructor
	Node();
	Node(data_type);
	Node(data_type, Node*);
	Node(data_type, Node*, Node*);

	// Destructor
	~Node();

	// Setters
	void set_data(data_type);
	void set_next(Node*);
	void set_previous(Node*);

	// Getters
	data_type get_data();
	Node* get_next();
	Node* get_previous();

	// Factory Functions
	Node* static create_node();Node* static create_node(data_type);
};
