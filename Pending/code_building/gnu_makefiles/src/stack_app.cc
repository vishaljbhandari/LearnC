# include "include/stack_app.h"
using namespace std;

int main(int argc, char* argv[])
{
	int ch;
	Stack* stack = new Stack();;
	while(1)
	{
		cout	<<"ENTER YOUR CHOICE\n"
			<<"1 SHOW STACK\n"
			<<"2 SHOW REVERSE STACK\n"
			<<"3 PUSH AN ITEM\n"
			<<"4 POP AN ITEM\n"
			<<"ANY OTHER TO TERMINATE THE PROGRAM\n" ;
		cin>>ch;
		cout<<"- - - - - - - - - - - - -\n";
		switch(ch)
		{
			case 1:	cout<<"STACK INFORMATION IS\n"<<"TOP\n";
				stack->print();
				cout<<"END\n";
				break;
			case 2: cout<<"REVERSE STACK INFORMATION IS\n"<<"TOP\n";
                                stack->print_reverse();
                                cout<<"END\n";
				break;
			case 3:	stack->push();
				break;
			case 4:	stack->pop();
				break;
			case 5: stack->destroy();
			default:return 0;
		}
		cout<<"=========================\n";
	}
}
