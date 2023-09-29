// Binary Search Tree
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left, * right;
};

Node* insert(Node* root, int data)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);
	return root;
}

bool search(Node* root, int data)
{
	if (root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root->data)
		return search(root->left, data);
	else
		return search(root->right, data);
}

void preOrder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->data << "\t";
	preOrder(root->left);
	preOrder(root->right);
}

void InOrder(Node* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	cout << root->data << "\t";
	InOrder(root->right);
}

void PostOrder(Node* root)
{
	if (root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << "\t";

}
//memory is leaked in this program so we need to delete the nodes
void Delete(Node* root)
{
	if (root == NULL)
		return;
	Delete(root->left);
	Delete(root->right);
	delete root;
}

//driver code
int main()
{
	Node* root = NULL;
	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 25);
	root = insert(root, 8);
	root = insert(root, 12);
	
	cout << "PreOrder Traversal\n";
	preOrder(root);
	cout << "\nInOrder Traversal\n";
	InOrder(root);
	cout << "\nPostOrder Traversal\n";
	PostOrder(root);

	int number;
	cout << "\nEnter number to be searched: ";
	cin >> number;
	if (search(root, number) == true)
		cout << "Found\n";
	else
		cout << "Not Found\n";

	Delete(root);
	root = NULL;

	return 0;
}