//Task 1:


#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* left, * right;
};

Node* create()
{
	int value;
	cout << " Enter value (-1 for no child): ";
	cin >> value;

	if (value == -1)
		return 0;

	Node* newNode;
	newNode = new Node;
	newNode->data = value;

	cout << endl << "Left child of " << value;
	newNode->left = create();
	cout << endl << "Right child of " << value;
	newNode->right = create();

	return newNode;
}


int findMaxElement(struct Node* root)
{
	if (root == NULL)
		return INT_MIN;

	int res = root->data;
	int lres = findMaxElement(root->left);
	int rres = findMaxElement(root->right);
	if (lres > res)
		res = lres;
	if (rres > res)
		res = rres;

	return res;
}

int main()
{
	Node* root = NULL;
	cout << "Enter the values for the binary tree: " << endl;
	root = create();
	int max = findMaxElement(root);
	if (max == INT_MIN)
		cout << endl << "Tree is empty." << endl;
	else
		cout << endl << "The maximum element in this tree is " << max << endl;

	return 0;
}
