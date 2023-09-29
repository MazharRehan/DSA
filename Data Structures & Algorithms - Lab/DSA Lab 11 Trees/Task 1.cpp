/*
Task 1: 
	Consider a ternary tree that stores integer values. Each node in the tree has three children
pointers. Implement the following operations :
1. Initialize an empty ternary tree.
2. Insert a new node with a given value into the ternary tree.Prompt the user to input the
	values for child 1, child 2, and child 3 of the new node.
3. Perform a traversal order root, child 1, child 2, and child 3 of the ternary tree and print
	the node values.
4. Perform a traversal order child 1, child 2, child 3 and root of the ternary tree and print the
	node values.
*/

//Implementation of Ternary Tree :
#include<iostream>
using namespace std;
// Structure of each node of the tree
struct Node 
{
	int data;
	Node *child1, *child2, *child3;
};
Node* create()
{
	int x;
	cout << " Enter value (-1 for no child): ";
	cin >> x;
	if (x == -1)
		return 0;
		
	Node* newNode = new Node;
	newNode->data = x;
	cout << endl << "1st child of " << x;
	newNode->child1 = create();
	cout << endl << "2nd child of " << x;
	newNode->child2 = create();
	cout << endl << "3rd child of " << x;
	newNode->child3 = create();

	return newNode;
}
void preOrder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->data << "\t";
	preOrder(root->child1);
	preOrder(root->child2);
	preOrder(root->child3);
}
void InOrder1(struct Node* root)
{
	if (root == NULL)
		return;
	InOrder1(root->child1);
	cout << root->data << "\t";
	InOrder1(root->child2);
	InOrder1(root->child3);
}
void InOrder2(struct Node* root)
{
	if (root == NULL)
		return;
	InOrder2(root->child1);
	InOrder2(root->child2);
	cout << root->data << "\t";
	InOrder2(root->child3);
}
void PostOrder(struct Node* root)
{
	if (root == NULL)
		return;
	PostOrder(root->child1);
	PostOrder(root->child2);
	PostOrder(root->child3);
	cout << root->data << "\t";
}
int main()
{
	struct Node* root;
//	root = 0;
	root = create();
	cout << endl << "PreOrder Traversal is: ";
	preOrder(root);
	cout << endl;
	cout << endl << "1st InOrder Traversal is: ";
	InOrder1(root);
	cout << endl;
	cout << endl << "2st InOrder Traversal is: ";
	InOrder2(root);
	cout << endl << "PostOrder Traversal is: ";
	PostOrder(root);
	cout << endl;

	return 0;
}
