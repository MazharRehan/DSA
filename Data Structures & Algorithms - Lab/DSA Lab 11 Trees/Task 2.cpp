/*
Task 2: 
In the above task after adding multiple values perform search operation in different
traversal order like InOrderTraversal, PreOrderTraversal and PostOrderTraversal with different
values. And find traversal order where least number of nodes have to visit in order to find the
number searched.
*/

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *child1, *child2, *child3;
};
struct Node* create()
{
	int x;
	cout << " Enter value (-1 for no child): ";
	cin >> x;
	if (x == -1)
		return 0;
		
	struct Node* newNode;
	newNode = new Node;
	
	newNode->data = x;
	cout << endl << "1st child of " << x;
	newNode->child1 = create();
	cout << endl << "2nd child of " << x;
	newNode->child2 = create();
	cout << endl << "3rd child of " << x;
	newNode->child3 = create();

	return newNode;
}
void preOrder(struct Node* root)
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

void searchPreOrder(Node* root, int key, int& count)
{
	if (root == NULL)
		return;
	if (root->data == key)
	{
		count++;
		return;
	}
	count++;
	searchPreOrder(root->child1, key, count);
	searchPreOrder(root->child2, key, count);
	searchPreOrder(root->child3, key, count);
}
void searchInOrder1(Node* root, int key, int& count)
{
	if (root == NULL)
		return;
	searchInOrder1(root->child1, key, count);
	if (root->data == key)
	{
		count++;
		return;
	}
	count++;
	searchInOrder1(root->child2, key, count);
	searchInOrder1(root->child3, key, count);
}
void searchInOrder2(struct Node* root, int key, int& count)
{
	if (root == NULL)
		return;
	searchInOrder2(root->child1, key, count);
	searchInOrder2(root->child2, key, count);
	if (root->data == key)
	{
		count++;
		return;
	}
	count++;
	searchInOrder2(root->child3, key, count);
}
void searchPostOrder(struct Node* root, int key, int& count)
{
	if (root == NULL)
		return;
	searchPostOrder(root->child1, key, count);
	searchPostOrder(root->child2, key, count);
	searchPostOrder(root->child3, key, count);
	if (root->data == key)
	{
		count++;
		return;
	}
	count++;
}


int main()
{
	struct Node* root;
	root = 0;
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


	int key;
	cout << endl << "Enter the value to be searched: ";
	cin >> key;

	int preOrderCount = 0, postOrderCount = 0, inOrder1Count = 0, inOrder2Count = 0;
	searchPreOrder(root, key, preOrderCount);
	cout << endl << "Number of nodes visited in PreOrder Traversal: " << preOrderCount;
	searchInOrder1(root, key, inOrder1Count);
	cout << endl << "Number of nodes visited in 1st InOrder Traversal: " << inOrder1Count;
	searchInOrder2(root, key, inOrder2Count);
	cout << endl << "Number of nodes visited in 2nd InOrder Traversal: " << inOrder2Count;
	searchPostOrder(root, key, postOrderCount);
	cout << endl << "Number of nodes visited in PostOrder Traversal: " << postOrderCount;
	cout << endl;

	if (preOrderCount <= inOrder1Count && preOrderCount <= inOrder2Count && preOrderCount <= postOrderCount)
		cout << endl << "PreOrder Traversal has least number of nodes visited";
	else if (inOrder1Count <= preOrderCount && inOrder1Count <= inOrder2Count && inOrder1Count <= postOrderCount)
		cout << endl << "1st InOrder Traversal has least number of nodes visited";
	else if (inOrder2Count <= preOrderCount && inOrder2Count <= inOrder1Count && inOrder2Count <= postOrderCount)
		cout << endl << "2nd InOrder Traversal has least number of nodes visited";
	else
		cout << endl << "PostOrder Traversal has least number of nodes visited";


	return 0;
}
