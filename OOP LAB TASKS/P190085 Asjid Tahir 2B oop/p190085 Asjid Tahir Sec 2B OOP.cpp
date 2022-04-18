#include<iostream>
using namespace stsd;
struct node
{
	int data;     	// Data
	node *prev;  	// A reference to the previous node
	node *next; 	// A reference to the next node
};
class Doubly_Linked_List
{
	node *head;  	// points to first node of list
	node *tail;   	// points to first las of list
	public:
	Doubly_Linked_List()
	{
		head = NULL;
		tail= NULL;
	}
	void add_head(int );
	void add_after(node* , int );
	void add_before(node* , int );
	void add_end(int );
	void delete_node(node*);
	void forward_traverse();
	void backward_traverse();
};
void Doubly_Linked_List :: add_front(int d)
{
	// Creating new node
	node *temp;
	temp = new node();
	temp->data = d;
	temp->prev = NULL;
	temp->next = front;

	// List is empty
	if(head == NULL)
		tail = temp;
		
	else
		head->prev = temp;
		
	head=temp;
}
void Doubly_Linked_List :: add_before(node *n, int d)
{
	node *temp;
	temp = new node();
	temp->data = d;
	temp->next = n;
	temp->prev = n->prev;
	n->prev = temp;

	//if node is to be inserted before first node
	if(n->prev == NULL)
		tail = temp;
} 
void Doubly_Linked_List :: add_after(node *n, int d)
{
	node *temp;
	temp = new node();
	temp->data = d;
	temp->prev = n;
	temp->next = n->next;
	n->next = temp;

	//if node is to be inserted after last node
	if(n->next == NULL)
		tail = temp;
}
void Doubly_Linked_List :: add_tail(int d)
{
	// create new node
	node *temp;
	temp = new node();
	temp->data = d;
	temp->prev = tail;
	temp->next = NULL;

	// if list is empty
	if(tail == NULL)
		head = temp;
	else
		tail->next = temp;	
	tail = temp;
}
void Doubly_Linked_List :: delete_node(node *n)
{	
	// if node to be deleted is first node of list
	if(n->prev == NULL)
	{
		head = n->next; //the next node will be front of list
		head->prev = NULL;
	}
	// if node to be deleted is last node of list
	else if(n->next == NULL)
	{
		head = n->prev;   // the previous node will be last of list
		tail->next = NULL;
	}
	else
	{
		//previous node's next will point to current node's next
		n->prev->next = n->next;
		//next node's prev will point to current node's prev
		n->next->prev = n->prev;
	}
	//delete node
	delete(n);			
}
void Doubly_Linked_List :: forward_traverse()
{
	node *trav;
	trav = head;
	while(trav != NULL)
	{
		cout<<trav->data<<endl;
		trav = trav->next;
	}
}
void Doubly_Linked_List :: backward_traverse()
{
	node *trav;
	trav = tail;
	while(trav != NULL)
	{
		cout<<trav->data<<endl;
		trav = trav->prev;
	}
}

