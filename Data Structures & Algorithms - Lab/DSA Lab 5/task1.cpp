						// Linked List
//Task 1:

#include<iostream> 
using namespace std;

template <typename T>
class Node 
{
public:
	T data;
	Node <T> * next; // Address of next node
	Node(){ }
	Node(T val) // constructor
	{
		data = val;
		next = NULL;
	}
	~Node() { }
};


template <typename Type>
class LinkedList
{
public:
	Node<Type>* head; // create an object of class node

	LinkedList()
	{
		head = NULL;
	}
	~LinkedList() {	}
	void insertHead(Type val) // insert value at the head
	{
		Node<Type>* myNode = new Node<Type>(val); // call parameterized constructor

		if (head == NULL)
		{
			head = myNode;
		}
		else
		{ // actually it inserts value at the head and move the old head to next of it
			myNode->next = head;
			head = myNode;
		}
	}
	void display()
	{
		if (head == NULL)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			Node<Type>* temp = head;

			while (temp != NULL)
			{
				cout << temp->data << "\t";
				temp = temp->next;
			}
		}
	}

};

int main() 
{
	LinkedList<float> L;

	L.insertHead(20.12);
	L.insertHead(30.5); 
	L.insertHead(40.9);
	L.insertHead(50.990);
	L.display();

	return 0;
}
