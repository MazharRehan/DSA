  						// Linked List
//Task 2: 
//Perform the following operations.
//1. Create your own class of link list which will have the following functions.
//	a.Function called  InsertAtBegin to add node at the begging of list.
//	b.Function called  InsertAtEnd to add node at the last of list.
//	c.Function called Display to display list on console.
//	d.Function called Search to search a specific value in list.
//	e.Function called Update to update value of list.

#include<iostream> 
#include<string> 
using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node <T>* next; // Address of next node
	Node() 
	{ 
		next = NULL;
	}
	Node(T val, Node * address) // constructor
	{
		data = val;
		next = address;
	}
	Node(T val)
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
	~LinkedList() 
	{	
		//Deletion of linked list
		if (head != NULL)
		{
			Node<Type>* p = head;

			while (p != NULL)
			{
				head = p->next;
				delete p;
				p = head;
			}
		}
	}
	void display();
	void insertAtBegin(Type);
	void insertAtEnd(Type);
	bool search(Type);
	bool update(Type, Type);
	void initializeList();
};
template<typename Type>
void LinkedList<Type>::display()
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
	cout << endl;
}
template<typename Type>
void LinkedList< Type>::insertAtBegin(Type val)
{
	Node<Type>* myNode = new Node<Type>(val, head);
	head = myNode;
}
template<typename Type>
void LinkedList< Type>::insertAtEnd(Type val)
{
	if (head == NULL)
	{
		head = new Node<Type>(val, NULL);
	}
	else
	{
		Node<Type>* myNode = head;

		while (myNode->next != NULL) 
			myNode = myNode->next;
		
		myNode->next = new Node<Type>(val, NULL);
	}
}
template<typename Type>
bool LinkedList< Type>::search(Type val)
{
	Node<Type>* temp = head;

	while (temp != NULL)
		if (temp->data == val)
			return true;
		else
			temp = temp->next;

	return false;
}

template<typename Type>
bool LinkedList< Type>::update(Type oldValue, Type newValue)
{
	Node<Type>* temp = head;

	while (temp != NULL)
	{
		if (temp->data == oldValue) {
			temp->data = newValue;
			return true;
		}
		else
			temp = temp->next;
	}

	cout << oldValue << " is not found in the list." << endl;
	return false;
}
template<typename Type>
void LinkedList< Type>::initializeList()
{
	cout << "Enter the number of elements do you want to add: ";
	int size = 0;

	while (1) {
		cin >> size;
		if (size < 1)
			cout << "Please input correct(+ve number) size.";
		else
			break;
	}
	

	head = new Node<Type>;
	Node<Type>* newNode = head, * previousNode = head;
	Type value;

	cout << "Input elements::" << endl;
	cin >> value;
	head->data = value;

	for (int i = 1; i < size; i++)
	{
		cin >> value;
		newNode = new Node<Type>;
		newNode->data = value;
		previousNode->next = newNode;
		previousNode = newNode;
	}
}

template<typename T>
void factory()
{
	LinkedList<T> L;
	string input = "";

	do
	{
		cout << "Choose one of the following option.\n"
			<< "\t1-Insert element at the begin of linked list\n"
			<< "\t2-Insert element at the end of linked list\n"
			<< "\t3-Search an element from linked list\n"
			<< "\t4-Update an element of the linked list\n"
			<< "\t5-Initialize linked list\n"
			<< "\t6-Display elements of linked list\n"
			<< "\t7-Exit\n_";
		cin >> input;

		if (input == "1")
		{
			T value;
			cout << "Input element do you want to add.\n_";
			cin >> value;
			L.insertAtBegin(value);
		}
		else if (input == "2")
		{
			T value;
			cout << "Input element do you want to add.\n_";
			cin >> value;
			L.insertAtEnd(value);
		}
		else if (input == "3")
		{
			T value;
			cout << "Input element do you want to find.\n_";
			cin >> value;
			cout << value << " is " << ((L.search(value) == 1) ? "found." : "not found.") << endl;
		}
		else if (input == "4")
		{
			T value, newVal;
			cout << "Input element do you want to update.\n_";
			cin >> value;
			cout << "Enter new value: ";
			cin >> newVal;
			cout << "Value is " << ((L.update(value, newVal) == 1) ? "updated" : "not updated.") << endl;
		}
		else if (input == "5")
			L.initializeList();
		else if (input == "6")
			L.display();
		else if (input == "7")
			exit(1);
		else 
			cout << "Please choose the currect option." << endl;

	} while (input != "7");

}

int main()
{
	factory<float>();
	
	return 0;
}
