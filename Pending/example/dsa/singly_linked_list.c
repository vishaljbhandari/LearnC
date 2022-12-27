#include<stdio.h>
#include <string.h>
#include <stdlib.h>
struct stud {
	int rollno;
	char name[20];
	struct stud *next;
};

typedef struct stud node;

node* createList(int, char*);
node* addToList(node*);
void displayList(node*);
node* delList(node*);
node* InsertData(node*);
node* InsertAfter(node*);
node* InsertBefore(node*);
node* SortedInsert(node*);
node* reverseList(node*);
node* SortList(node*);
node* BubbleSort(node*);

void main() {
	node *head = NULL;
	int choice;

	do {
		printf("\n\n\n1. Add Data To The List\n");
		printf("2. Display Content Of List\n");
		printf("3. Delete The Specified Data\n");
		printf("4. Insert Data After Any Node\n");
		printf("5. Reverse The Given Link List\n");
		printf("6. Sort List Using Bubble Sort\n");
		printf("7. E.......X.....I.......T\n\n");
		printf("Enter Your Choice[1-7]: ");
		// choice = getchar();
		//scanf("%d", &choice);
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			head = addToList(head);
			break;
		case 2:
			displayList(head);
			break;
		case 3:
			head = delList(head);
			break;
		case 4:
			head = InsertData(head);
			break;
		case 5:
			printf("Original List....\n\n");
			displayList(head);
			head = reverseList(head);
			printf("\n\nReversed List.....\n\n");
			displayList(head);
			break;
		case 6:
			head = BubbleSort(head);
			break;
		case 7:
			printf("Good Bye......\n\n");
			break;
		default:
			printf("INVALID CHOICE.....\n\n");
			printf("TRY AGAIN.....\n\n");
		}
	} while (choice != 7);
}

node* createList(int n, char *str) {
	node *ptr;
	ptr = (node*) malloc(sizeof(node));
	ptr->rollno = n;
	strcpy(ptr->name, str);
	ptr->next = NULL;

	return ptr;
}

node* addToList(node *start) {
	int n;
	node *newnode, *prev, *ptr;
	char xname[20], ch;
	do {
		fflush(stdin);
		printf("\n\n");
		printf("Enter The Roll number : ");
		scanf("%d", &n);

		fflush(stdin);
		printf("Enter The Name : ");
		scanf("%s", xname);
		fflush(stdin);
		newnode = createList(n, xname);
		if (!start) {
			start = newnode;
		} else {
			for (ptr = start; ptr; prev = ptr, ptr = ptr->next)
				;
			prev->next = newnode;
		}
		fflush(stdin);
		printf("\n\n");
		printf("Want To Continue[Y/N] : ");
		ch = getchar();
	} while (ch == 'Y' || ch == 'y');
	return start;
}

void displayList(node *start) {
	node *ptr;
	printf("\nCONTENTS OF LIST....");
	printf("\n");
	for (ptr = start; ptr; ptr = ptr->next) {
		printf("%5d %20s\n", ptr->rollno, ptr->name);
	}
	printf("\n\n\n\n");
}

node* delList(node *start) {
	int num, flag = 0;
	node *ptr, *prev;
	char ch;
	do {

		printf("Enter The Roll Number You Want to Delete : ");
		scanf("%d", &num);
		for (ptr = start; ptr; prev = ptr, ptr = ptr->next) {
			if (ptr->rollno == num) {
				flag = 1;
				break;
			}

		}

		if (flag == 0) {
			printf("Roll No Not Found...");
			printf("Try Again......");
			return start;
		}
		if (ptr == start) {
			start = ptr->next;
		} else {
			prev->next = ptr->next;
		}
		free(ptr);
		fflush(stdin);
		printf("\n\n");
		printf("Specified Node Deleted.....\n\n");
		printf("Want To Delete Another Record[Y/N]: ");

		ch = getchar();
	} while (ch == 'Y' || ch == 'y');
	return start;
}

node* InsertData(node *start) {
	int choice;

	do {
		printf("1. Insert After\n");
		printf("2. Insert Before\n");
		printf("3. Insert In Sorted Order\n");
		printf("4. Exit....\n\n");
		printf("Enter Your Choice[1-4] : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			start = InsertAfter(start);
			break;
		case 2:
			start = InsertBefore(start);
			break;
		case 3:
			start = SortedInsert(start);
			break;
		case 4:
			printf("Returning To Main Program....\n");
			printf("Press any Key To Continue....\n");
			break;
		default:
			printf("Invalid Entry....\n");
			printf("Try again.....\n");
		}
	} while (choice != 4);
	return start;
}

node* InsertAfter(node *start) {
	node *newnode, *ptr;
	int rno, after, flag = 0;
	char ch, sname[20];
	do {
		fflush(stdin);
		printf("Enter The Roll Number : ");
		scanf("%d", &rno);
		fflush(stdin);
		printf("Enter The Student name : ");
		scanf("%s", sname);
		fflush(stdin);

		printf("Insert After Which Node :");
		scanf("%d", &after);

		for (ptr = start; ptr; ptr = ptr->next) {
			if (ptr->rollno == after) {
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			printf("Specified Node Not Found.....\n");
			printf("Try Again.....");
			return start;
		}
		newnode = createList(rno, sname);

		newnode->next = ptr->next;
		ptr->next = newnode;

		printf("New Node Is Inserted After Specified Node....\n\n");
		fflush(stdin);
		printf("Want To Insert Again[Y/N] : ");
		ch = getchar();
	} while (ch == 'Y' || ch == 'y');
	return start;
}

node* InsertBefore(node *start) {
	node *ptr, *prev, *newnode;
	int rno, before, flag = 0;
	char ch, sname[20];
	do {
		fflush(stdin);
		printf("Enter The Roll Number : ");
		scanf("%d", &rno);

		fflush(stdin);

		printf("Enter The Student name : ");
		scanf("%s", sname);

		fflush(stdin);

		printf("Insert Before Which Node :");
		scanf("%d", &before);

		for (ptr = start; ptr; prev = ptr, ptr = ptr->next) {
			if (ptr->rollno == before) {
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			printf("Specified Node Not Found.....\n");
			printf("Try Again.....");
			return start;
		}
		newnode = createList(rno, sname);
		if (ptr == start) {
			ptr->next = start;
			start = ptr;
		} else {
			prev->next = newnode;
			newnode->next = ptr;
		}

		printf("New Node Is Inserted Before Specified Node....\n\n");
		fflush(stdin);
		printf("Want To Insert Again[Y/N] : ");
		ch = getchar();
	} while (ch == 'Y' || ch == 'y');
	return start;
}

node* SortedInsert(node *start) {
	node *prev, *ptr, *newnode;
	int no;
	char sname[20], ch;

	do {
		fflush(stdin);
		printf("Enter New Roll Number : ");
		scanf("%d", &no);

		fflush(stdin);

		printf("Enter The Student Name : ");
		scanf("%s", sname);
		fflush(stdin);

		newnode = createList(no, sname);

		if (start == NULL) {
			start = newnode;
		} else {
			for (ptr = start; ptr && no > ptr->rollno;
					prev = ptr, ptr = ptr->next)
				;

			if (ptr == start) {
				newnode->next = start;
				start = newnode;
			} else {
				prev->next = newnode;
				newnode->next = ptr;
			}
		}
		fflush(stdin);
		printf("\n\nNode Inserted At It Location\n\n");
		printf("Want To Continue[Y/N] : ");
		ch = getchar();

	} while (ch == 'y' || ch == 'y');
	return start;
}

node* reverseList(node *start) {
	node *ptr, *temp, *pre = NULL;

	ptr = start;
	temp = ptr->next;
	ptr->next = NULL;
	while (temp != NULL) {
		pre = ptr;
		ptr = temp;
		temp = temp->next;
		ptr->next = pre;
	}
	printf("\nGiven List Is Reversed...");
	return ptr;
}

node* BubbleSort(node *start) {
	node *ptr1, *ptr2, *pre, *temp, *end;
	end = NULL;

	while (end != start->next) {
		ptr1 = pre = start;
		ptr2 = ptr1->next;
		while (ptr1 != end) {
			if (ptr1->rollno > ptr2->rollno) {
				if (ptr1 == start) {
					temp = ptr2->next;
					ptr2->next = ptr1;
					ptr1->next = temp;

					start = ptr2;
					pre = ptr2;
				} else {
					temp = ptr2->next;
					ptr2->next = ptr1;
					ptr1->next = temp;

					pre->next = ptr2;
					pre = ptr2;
				}
			} else {
				pre = ptr1;
				ptr1 = ptr1->next;
			}
			ptr2 = ptr1->next;
			if (ptr2 == end)
				end = ptr1;
		}
	}
	printf("Node Successfully Swapped.....");
	return start;
}
