#include <iostream>
using namespace std;

template<class data_type>
class Node {
	data_type data;
	Node *next;
public:
	// Constructor
	Node();
	Node(data_type);
	Node(data_type, Node*);

	// Destructor
	~Node();

	// Setters
	void set_data(data_type);
	void set_next(Node*);

	// Getters
	data_type get_data();
	Node* get_next();

	// Factory Functions
	Node* static create_node();
	Node* static create_node(data_type);
};
