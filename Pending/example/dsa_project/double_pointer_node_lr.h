#include <iostream>
// Left Right Double Pointer Node
using namespace std;

template<class data_type>
class Node {
	data_type data;
	Node *left;
	Node *right;
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
	void set_left(Node*);
	void set_right(Node*);

	// Getters
	data_type get_data();
	Node* get_left();
	Node* get_right();

	// Factory Functions
	Node* static create_node();
	Node* static create_node(data_type);
};
