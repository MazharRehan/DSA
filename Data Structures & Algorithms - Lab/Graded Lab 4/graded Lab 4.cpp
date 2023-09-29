/*
Task: Implement a program that allows users to create two binary search trees (BSTs) by providing
input values and then checks if they are identical using recursion.
Specifications:
1. Implement a binary search tree structure/class with the following operations:
 - `void insert(int value)`: Inserts a new node with the given value into the BST.
 - `bool search(int value)`: Searches for a node with the given value in the BST and returns true if
found, false otherwise.
 - `bool isIdentical(BST* other)`: Takes a pointer to another BST object as input and returns true if
the two BSTs are identical, and false otherwise.
2. Implement a function to take user input and create the two BSTs:
 - The function should prompt the user to enter the values for the first BST, one value at a time.
 - After entering all the values for the first BST, the function should prompt the user to enter the
values for the second BST.
 - The user can input any number of values for each BST.
3. The `isIdentical()` function should perform a recursive comparison of the trees, checking if the
values at each node match and if the left and right subtrees are also identical.
4. Use the `isIdentical()` function to check if the two BSTs are identical.
5. Print the results, indicating whether the BSTs are identical or not.
Example output:
Create the first binary search tree
Enter space-separated values for BST: 8 4 12 2 6 10 14
Create the second binary search tree
Enter space-separated values for BST: 8 4 12 2 6 10 14
The two binary search trees are identical.
*/

#include<iostream>
#include <sstream>
using namespace std;

class BST_Node
{
public:
	int key;
	BST_Node* left, * right;
	BST_Node()
	{
		key = 0;
		left = right = NULL;
	};
	BST_Node(int value)
	{
		key = value;
		left = right = NULL;
	};
};

class BST
{
	BST_Node* root;
public:
	BST()
	{
		root=NULL;
	}
	BST(int value)
	{
		root = new BST_Node(value);
	}
	void insert(int value)
	{
		if (root == NULL)
		{
			root = new BST_Node(value);
			return;
		}
		BST_Node* temp = root;
		while (temp != NULL)
		{
			if (value < temp->key)
			{
				if (temp->left == NULL)
				{
					temp->left = new BST_Node(value);
					return;
				}
				temp = temp->left;
			}
			else if (value > temp->key)
			{
				if (temp->right == NULL)
				{
					temp->right = new BST_Node(value);
					return;
				}
				temp = temp->right;
			}
				
			return;
			
		}
	}
	bool search(int value)
	{
		BST_Node* temp = root;
		while (temp != NULL)
		{
			if (value < temp->key)
			{
				temp = temp->left;
			}
			else if (value > temp->key)
			{
				temp = temp->right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	
	bool isIdentical(BST* other) 
	{
		return isIdenticalRecursive(root, other->root);
    }

    bool isIdenticalRecursive(BST_Node* node1, BST_Node* node2) 
	{
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        } 
		else if (node1 == nullptr || node2 == nullptr) {
            return false;
        } 
		else 
		{
            bool isDataEqual = (node1->key == node2->key);
            bool isLeftSubtreeIdentical = isIdenticalRecursive(node1->left, node2->left);
            bool isRightSubtreeIdentical = isIdenticalRecursive(node1->right, node2->right);

            return isDataEqual && isLeftSubtreeIdentical && isRightSubtreeIdentical;
        }
    }
};

void createBSTs(BST& bst1, BST& bst2) 
{
	cout << "Create the first binary search tree\nEnter space-separated values for BST: ";

	string input;
	getline(cin, input);
	istringstream iss(input);

	int value;
	while (iss >> value) 
		bst1.insert(value);
	
	cout << "Create the second binary search tree\nEnter space-separated values for BST: ";

	getline(cin, input);
	istringstream iss2(input);

	while (iss2 >> value)
		bst2.insert(value);
	
}

int main() 
{
	BST bst1;
	BST bst2;

	createBSTs(bst1, bst2);

	bool areIdentical = bst1.isIdentical(&bst2);

	if (areIdentical) 
		cout << "The two binary search trees are identical." << endl;
	else 
		cout << "The two binary search trees are not identical." << endl;
	

	return 0;
}