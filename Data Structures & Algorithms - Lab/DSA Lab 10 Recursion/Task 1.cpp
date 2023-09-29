/*
Task 1
Write a recursive function which takes head pointer of singly linked list as parameter and prints the singly
linked list in reverse order. Restriction: You are not allowed to use any other data structure in the function.
*/

#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node*next;
};

class SLList
{
	
public:
	Node* head;
	SLList()
	{
		head = NULL;
	}
	void input()
	{
		if (head == NULL)
		{
			int val = 0;
			cout << "Input values(-999 to terminate)" << endl;
			cin >> val;
			
			if(val==-999)
				return;
			
			head = new Node;
			Node *currentNode = head, *prev = head;
			currentNode->data = val;
			
			cin >> val;
			while (val != -999)
			{
				prev = currentNode;
				currentNode = new Node;
				currentNode->data = val;
				prev->next = currentNode;
				
				cin >> val;
			}
			currentNode->next = NULL;
		}
	}
	void reversePrint(Node* header)
	{
		if (header == NULL)
			return;

		reversePrint(header->next);
		cout << header->data << "\t";
	}

};

int main()
{
	SLList obj;

	obj.input();
	obj.reversePrint(obj.head);

	return 0;
}
