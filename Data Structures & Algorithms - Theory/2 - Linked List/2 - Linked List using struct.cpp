// Linked List using struct
#include<iostream>
using namespace std;

struct nodeType
{
	int info;
	nodeType* link;
};

//10 20 30 40

int main()
{
	nodeType* head, * p, * q, * newNode;
	int value = 0;
	head = p = q = newNode = NULL;

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


	q = head;

	while (q != NULL)
	{
		cout << q->info << " ";
		q = q->link;
	}

	return 0;
}
