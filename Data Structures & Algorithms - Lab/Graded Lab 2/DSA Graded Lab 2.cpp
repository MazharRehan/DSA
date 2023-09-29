/* ```````````````Graded Lab 2`````````````````````````````
Given a singly linked list and an integer K, the task is to rotate the linked list
clockwise to the right by K places.
Example 1:
Input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL, K = 2
Output: 4 -> 5 -> 1 -> 2 -> 3 -> NULL
Example 2:
Input: 7 -> 9 -> 11 -> 13 -> 3 -> 5 -> NULL, K = 12
Output: 7 -> 9 -> 11 -> 13 -> 3 -> 5 -> NULL
Example 3
Input: 7 -> 4 -> 8 -> 11 -> 2 -> 1 -> NULL, K = 4
Output: 8 -> 11 -> 2 -> 1 -> 7 -> 4 -> NULL
*/

#include<iostream> 
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
	Node(T val, Node* address) // constructor
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
	int k, maxSize;

	LinkedList()
	{
		head = NULL;
		k = 0;
		maxSize = 0;
	}
	~LinkedList()
	{
		//Deletion of linked list
		if (head != NULL)
		{
			Node<T>* p = head;

			while (p != NULL)
			{
				head = p->next;
				delete p;
				p = head;
			}
		}
	}
	void display();
	void initializeList();
	void rotate();
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
void LinkedList< Type>::initializeList()
{
	cout << "Enter the number of elements do you want to add: ";

	while (1) 
	{
		cin >> maxSize;
		if (maxSize < 1)
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

	for (int i = 1; i < maxSize; i++)
	{
		cin >> value;
		newNode = new Node<Type>;
		newNode->data = value;
		previousNode->next = newNode;
		previousNode = newNode;
	}
}

template<typename Type>
void  LinkedList< Type>::rotate()
{
	cout << "Enter number of places do you want to move the Linked List: ";
	cin >> k;

	Node<Type>* temp, * p;
	temp = p = head;

	for (int i = 1; i <= k; i++)
	{
		while (temp->next != NULL) // finding last node
		{
			p = temp; // p is 1 step back
			temp = temp->next;
		}

		temp->next = head;
		head = temp;
		p->next = NULL;
	}
}

int main()
{
	LinkedList<int> L;

	L.initializeList();
	
	cout << "Before Rotation: ";
	L.display();
	L.rotate();

	cout << "After Rotation: ";
	L.display();

	return 0;
}
