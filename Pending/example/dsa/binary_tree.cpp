#include<iostream>
using namespace std;

struct tree_node {
	tree_node *left;
	tree_node *right;
	int data;
};

class bst {
	tree_node *root;
public:
	bst() {
		root = NULL;
	}
	int isempty() {
		return (root == NULL);
	}
	void insert(int item);
	void in_order_traversal();
	void in_order(tree_node*);
	void post_order_traversal();
	void post_order(tree_node*);
	void pre_order_traversal();
	void pre_order(tree_node*);
};

void bst::insert(int item) {
	tree_node *p = new tree_node;
	tree_node *parent;
	p->data = item;
	p->left = NULL;
	p->right = NULL;
	parent = NULL;
	if (isempty())
		root = p;
	else {
		tree_node *ptr;
		ptr = root;
		while (ptr != NULL) {
			parent = ptr;
			if (item > ptr->data)
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}
		if (item < parent->data)
			parent->left = p;
		else
			parent->right = p;
		cout << "Added " << item << "; ";
	}
}

void bst::in_order_traversal() {
	in_order(root);
}

void bst::in_order(tree_node *ptr) {
	if (ptr != NULL) {
		in_order(ptr->left);
		cout << "  " << ptr->data << "\t";
		in_order(ptr->right);
	}
}

void bst::post_order_traversal() {
	post_order(root);
}

void bst::post_order(tree_node *ptr) {
	if (ptr != NULL) {
		post_order(ptr->left);
		post_order(ptr->right);
		cout << "  " << ptr->data << "\t";
	}
}

void bst::pre_order_traversal() {
	pre_order(root);
}

void bst::pre_order(tree_node *ptr) {
	if (ptr != NULL) {
		cout << "  " << ptr->data << "\t";
		pre_order(ptr->left);
		pre_order(ptr->right);
	}
}

int main() {
	bst tree;
	tree.insert(52);
	tree.insert(25);
	tree.insert(50);
	tree.insert(15);
	tree.insert(40);
	tree.insert(45);
	tree.insert(20);
	cout << endl << "In Order Traversal" << endl;
	tree.in_order_traversal();
	cout << endl << "Post Order Traversal" << endl;
	tree.post_order_traversal();
	cout << endl << "Pre Order Traversal" << endl;
	tree.pre_order_traversal();
	cout << endl;
	return 0;
}
