// Binary Tree Traversal

#include <iostream>
using namespace std;

struct Node
{
	int data;
	//struct Node* left, * right;  //Or
	Node* left, * right; // There is no difference between [struct Node*] & [Node*] 
};

//struct Node* create() // Or
Node* create()
{
	int x;
	cout << " Enter value (-1 for no child): ";
	cin >> x;
	if (x == -1)
		return 0; // Or return NULL

	Node* newNode = new Node;
	newNode->data = x;
	cout << endl << "Left child of " << x;
	newNode->left = create();
	cout << endl << "Right child of " << x;
	newNode->right = create();
	return newNode;
}

void preOrder(struct Node* root)
{
	if (root == NULL)
		return;
	cout << root->data << "\t";
	preOrder(root->left);
	preOrder(root->right);
}

void InOrder(struct Node* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	cout << root->data << "\t";
	InOrder(root->right);
}

void PostOrder(struct Node* root)
{
	if (root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << "\t";

}

void main()
{
	struct Node* root;
	root = 0;
	root = create();

	cout << endl << "PreOrder Traversal is: ";
	preOrder(root);
	cout << endl;

	cout << endl << "InOrder Traversal is: ";
	InOrder(root);
	cout << endl;

	cout << endl << "PostOrder Traversal is: ";
	PostOrder(root);
	cout << endl;
}