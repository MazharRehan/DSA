// sir's code
#include<iostream>
using namespace std;

struct nodeType
{
	int info;
	nodeType *link;
};

//10 20 30 40

int main()
{
	nodeType *head, *p, *q, *newNode;
	int value = 0;
	head = p = q = newNode = NULL;

	while (value != -1)
	{
		if (value == 0)
		{
			cout << "Enter list values (-1 to terminate) : ";
			cin >> value;
			if (value == -1) break;
			newNode = new nodeType;
			newNode->info = value;
			head = p = newNode;
		}
		else
		{
			cout << "Enter list values (-1 to terminate) : ";
			cin >> value;
			if (value == -1) break;
			newNode = new nodeType;
			newNode->info = value;
			p->link = newNode;
			p = newNode;
		}
		newNode->link = NULL;	
	}

	

	q = head;

	cout << q->info << " ";

 	while (q->link != NULL)
	{
		cout << q->link->info << " ";
		q = q->link;
	}

	return 0;
}
