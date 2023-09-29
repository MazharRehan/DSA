#include<iostream>
using namespace std;

class nodeType
{
public:
	int info;
	nodeType* link;
};


template <class elemType>
class LinkedList
{
	nodeType* head, * p, * newNode;
public:
	LinkedList()
	{
		head = p = newNode = NULL;
	}
	bool isEmpty() const;
	void input();
	void display();
	bool search(const elemType&);
};

template <class elemType>
bool LinkedList<elemType>::isEmpty() const
{
	return (head==NULL);
}

template <class elemType>
void LinkedList<elemType>::input()
{
	int value = 0;
	
	cout << "Enter list values (-1 to terminate): ";
	cin >> value; //10

	if (value != -1)
	{
		newNode = new nodeType;
		newNode->info = value;
		head = p = newNode;
		
		cout << "Enter list values (-1 to terminate) : ";
		cin >> value; //20

		while (value != -1)
		{
			newNode = new nodeType;
			newNode->info = value;

			p->link = newNode;
			p = newNode;

			cout << "Enter list values (-1 to terminate) : ";
			cin >> value;
		} 
		
		newNode->link = NULL;
	}
}


template <class elemType>
void LinkedList<elemType>::display()
{
	nodeType* q = head;

	while (q != NULL)
	{
		cout << q->info << " ";
		q = q->link;
	}
}

template <class elemType>
bool LinkedList<elemType>::search(const elemType& value)
{

}


int main()
{
	LinkedList<int>obj;

	obj.input();
	obj.display();

	
	return 0;
}
