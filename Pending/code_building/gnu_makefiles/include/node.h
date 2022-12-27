# ifndef _NODE_H_
# define _NODE_H_
# include "include/main.h"
using namespace std;

class Node
{
	private:
		int data;
		Node* next;
	public:
		Node()
		{
			data=0;
			next=NULL;
		}
		Node(int value)
		{
			data=value;
			next=NULL;
		}
		Node(int value, Node* node)
		{
			data=value;
			next=node;
		}
                Node* createNode();
                Node* createNode(int value);
                Node* createNode(int value, Node* next);

		void set_data(int value)
		{
			data=value;
		}
		void set_next(Node* ptr)
		{	
			next=ptr;
		}
		int get_data()
		{
			return data;
		}
		Node* get_next()
		{
			return next;
		}
		~Node()
		{
			data=0;
			if(next!=NULL)
			{
				//delete next;
				next=NULL;
			}
		}
};

#endif // _NODE_H_
