# include "include/stack.h"

using namespace std;

void Stack::print()
{
	if(top==NULL)
        {
		cout<<"STACK IS EMPTY\n";
                return;
        }
	show(top);
	return;
}

void Stack::print_reverse()
{
        if(top==NULL)
        {
                cout<<"STACK IS EMPTY\n";
                return;
        }
        show_reverse(top);
        return;
}

void Stack :: push(Node* node)
{
	node->set_next(top);
	top=node;
	return;
}

void Stack :: push(int value)
{
	Node* node = new Node(value); 
        push(node);
        return;
}

void Stack :: push()
{
	int value;
        cout<<"ENTER YOUR VALUE TO PUSH\n";
	cin>>value;
        push(value);
	cout<<"ELEMENT IS PUSHED INTO STACK\n";
        return;
}

Node* Stack :: pop_node()
{
	if(top==NULL)
	{
		return NULL;
	}
	Node* temp=top;
	top=temp->get_next();
	temp->set_next(NULL);
	return temp;
}

int Stack :: pop_data()
{
        Node* temp=pop_node();
	if(temp!=NULL)
	{
		int value = temp->get_data();
		delete temp;
        	return value;
	}
	else
	{
		return 0;
	}
}
void Stack :: pop()
{
	if(top!=NULL)
	{
        	Node* temp=pop_node();
               	delete temp;
		cout<<"STACK IS POPPED\n";
	}
	else
	{
		cout<<"STACK IS EMPTY\n";
	}	
}

void Stack :: show_reverse(Node *top)
{
	if(top==NULL)
	{
		return;
	}else{
		show_reverse(top->get_next());
	}	
	cout<<"Node: "<<top->get_data()<<"\n";
	return;
}

void Stack :: show(Node *top)
{
	if(top==NULL)
	{
		return;
	}
	cout<<"Node: "<<top->get_data()<<"\n";
        if(top->get_next()==NULL)
        {
                return;
        }else{
                show(top->get_next());
        }
        return;
}

