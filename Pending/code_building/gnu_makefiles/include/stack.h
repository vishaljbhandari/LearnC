# ifndef _STACK_H_
# define _STACK_H_
# include "include/main.h"
# include "include/node.h"
using namespace std;

class Node;
class Stack
{
	private:
		Node* top;
	public:
		Stack()
		{
			top=NULL;
		}
		Stack(Node* stackTop)
		{
			top=stackTop;
		}
		
		Node* getStackTop()
		{
			return top;
		}
		~Stack()
		{
			if(top!=NULL)
			{
				//delete top;
				top=NULL;
			}
		}
		void  destroy()
		{
			if(top!=NULL)
                        {
                                //delete top;
                                top=NULL;
                        }
		}
		void  push(Node*);
		void  push(int);
		void  push();
		Node* pop_node();
		int   pop_data();
		void  pop();
		void  show(Node*);
		void  show_reverse(Node*);
		void  print();
		void  print_reverse();
};

#endif // _STACK_H_
