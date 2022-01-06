#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
struct Node* top = NULL;
void push(int value)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = value;
	new_node->next = top;
	top = new_node;
}
void Pop()
{
	if (top == NULL)
	{
		cout << "Your Stack Underflow is :" << endl;
	}
	else
	{
		cout << "The popped element is " << top->data << endl;
		top = top->next;
	}
}
void Display()
{
	struct Node* foo;
	if (top == NULL)
	{
		cout << "Your Stack is empty :" << endl;
	}
	else
	{
		foo = top;
		cout << " The elements of the stack are:" << endl;
		while (foo != NULL) 
		{
			cout << foo->data << " ";
			ptr = foo->next;
		}
	}
	cout << endl;
}
int main()
{
	int character;
	int value; 
	cout << "1 : To Pushed into the stack:" << endl;
	cout << "2 : To Pop into the stack:" << endl;
	cout << "3 :To  Display stack:" << endl;
	cout << "4 :Exit your Program:" << endl;
	do {
		cout << "Enter your choices according to your input: " << endl;
		cin >> character;
		switch (character)
		{
		case 1:
		{
			cout << "Enter the all  values which are  to be pushed:" << endl;
			cin >> value;
			push(value);
			break;
		}
		case 2:
		{
			Pop();
			break;
		}
		case 3:
		{
			Display();
			break;
		}
		case 4:
		{
			cout << "Exit your program :" << endl;
			break;
		}
		default:
		{
			cout << "Invalid!!!!!!" << endl;
		}
		}
	} while (character != 4);
	system("pause");
	return 0;
}