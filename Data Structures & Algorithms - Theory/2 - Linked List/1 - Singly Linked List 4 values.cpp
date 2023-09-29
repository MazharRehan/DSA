#include<iostream>
using namespace std;

class nodeType
{
public:
	int info;
	nodeType *link;
};

//10 20 30 40

int main()
{
	nodeType *head, *p, *q, *newNode;

	//first node
	newNode = new nodeType;
	newNode->info = 10;
	p = newNode;
	head = newNode;
	
	// second node
	newNode = new nodeType;
	newNode->info = 20;
	p->link = newNode; // p is at previous node
	p = newNode;

	// Third node
	newNode = new nodeType;
	newNode->info = 30;
	p->link = newNode;
	p = newNode;

	// fourth node
	newNode = new nodeType;
	newNode->info = 40;
	p->link = newNode;
	newNode->link = NULL;


	q = head;

 	while (q != NULL)
	{
		cout << q->info << " ";
		q = q->link;
	}

	return 0;
}
