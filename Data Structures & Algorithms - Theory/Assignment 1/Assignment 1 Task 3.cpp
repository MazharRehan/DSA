//Assignment 1 Task 3:

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
	~Node() { }
};

template<typename T> void initializeList(Node<T>*&);
template<typename T> void sort(Node<T>*&);
template<typename T> Node<T>*& mergeLists(Node<T>*&, Node<T>*&);
template<typename T> void display(Node<T> *head);
template<typename T> void deleteLinkedList(Node<T>*&);
template<typename T> void factory();

int main()
{
	factory<int>();

	return 0;
}


template<typename T>
void deleteLinkedList(Node<T>*& head)
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


template<typename T>
Node<T>*& mergeLists(Node<T>*& nodeA, Node<T>*& nodeB)
{
	sort<T>(nodeA);
	sort<T>(nodeB);

	Node<T>* mergedNode = new Node<T>;
	Node<T>* temp = mergedNode = nodeA;

	//finding last node
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = nodeB;

	sort<T>(mergedNode);

	return mergedNode;
}

template<typename T>
void sort(Node<T>*& head)
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		for (Node<T>* temp1 = head; temp1 != NULL; temp1 = temp1->next)
		{
			for (Node<T>* temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
			{
				if (temp1->data > temp2->data)
				{
					temp1->data = temp1->data + temp2->data;
					temp2->data = temp1->data - temp2->data;
					temp1->data = temp1->data - temp2->data;
				}
			}
		}
	}
}

template<typename T>
void display(Node<T>* head)
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		Node<T>* temp = head;

		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
	cout << endl;
}



template<typename T>
void initializeList(Node<T>*& head)
{
	cout << "Enter the number of elements do you want to add: ";
	int size = 0;

	while (1) 
	{
		cin >> size;
		if (size < 1)
			cout << "Please input correct(+ve number) size.";
		else
			break;
	}

	Node<T>* newNode, * previousNode;

	head = new Node<T>;
	newNode = previousNode = head;
	T value;

	cout << "Input elements::" << endl;
	cin >> value;
	head->data = value;

	for (int i = 1; i < size; i++)
	{
		cin >> value;
		newNode = new Node<T>;
		newNode->data = value;
		previousNode->next = newNode;
		previousNode = newNode;
	}
}

template<typename T>
void factory()
{
	Node<T>* nodeA = NULL, * nodeB = NULL, * mergedNode = NULL;

	cout << "Node A" << endl;
	initializeList<T>(nodeA);
	cout << "Node B" << endl;
	initializeList<T>(nodeB);

	mergedNode = mergeLists<T>(nodeA, nodeB);


	cout << "Node A: ";
	display<T>(nodeA);
	cout << "Node B: ";
	display<T>(nodeB);

	cout << "Merged Node: ";
	display<T>(mergedNode);

	deleteLinkedList<T>(nodeA);
	deleteLinkedList<T>(nodeB);
	deleteLinkedList<T>(mergedNode);
}

/*
The worst-case time complexity of the mergeLists function is O(n^2), where n is the 
total number of nodes in both linked lists. This is because the function first sorts 
both lists using a bubble sort algorithm, which has a worst-case time complexity of 
O(n^2). Then, it iterates through the first list to append the second list, which takes 
O(n) time. Finally, it sorts the merged list again using the bubble sort algorithm, 
which takes another O(n^2) time in the worst case. Therefore, the overall worst-case 
time complexity of the mergeLists function is O(n^2).
*/
