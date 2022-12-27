# include "include/node.h"
using namespace std;

Node* Node::createNode()
{
        Node* node = new Node();
        return node;
}

Node* Node::createNode(int value)
{
        Node* node = new Node(value);
        return node;
}

Node* Node::createNode(int value, Node* next)
{
        Node* node = new Node(value, next);
        return node;
}
