// Task 1:
/*
 Implement the following operations of BST. Note that the Node class must have 3
members i.e., int data, Node* left, Node* right.
The BST class should have a pointer of type Node, called root, i.e., Node* root.
BSTree ()
Constructor. Creates an empty binary search tree.

insert ()
Inserts new DataItem into a BST. If a data item already exists in the BST, then by definition
of having distinct values in BST, you should not accept the duplicate value. Else if the
provided data is unique, insert it into the tree.

retrieve ()
Searches BST for the data item with the user given given value. Return true if it already
exists in BST, else return false.
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class BST
{
private:
    Node* root;
    Node* insertRecursive(Node* node, int data)
    {
        if (node == nullptr)
        {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        if (data < node->data)
            node->left = insertRecursive(node->left, data);
        else if (data > node->data)
            node->right = insertRecursive(node->right, data);

        return node;
    }

    bool retrieveRecursive(Node* node, int data) // search
    {
        if (node == nullptr) // not found
            return false; 

        if (data == node->data)
            return true;
        else if (data < node->data)
            return retrieveRecursive(node->left, data);
        else
            return retrieveRecursive(node->right, data);
    }

    void displayRecursive(Node* node)
    {
        if (node == nullptr)
            return;

        displayRecursive(node->left);
        cout << node->data << " ";
        displayRecursive(node->right);
    }

    void destroyTree(Node* node)
    {
        if (node == nullptr)
            return;

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    BST()
    {
        root = nullptr;
    }

    ~BST()
    {
        destroyTree(root);
    }

    void insert(int data)
    {
        root = insertRecursive(root, data);
    }

    bool retrieve(int data)
    {
        return retrieveRecursive(root, data);
    }

    void display()
    {
        displayRecursive(root);
    }

    void input()
    {
		int inpt;
		cout << "Enter values to insert into the BST (-9 to exit): " << endl;
        while (true)
        {
			cin >> inpt;
			if (inpt == -9)
				break;
			insert(inpt);
		}
	}

};

int main()
{
    BST bst;

    bst.input();

    cout << "BST: ";
    bst.display();
    cout << endl;

    int searchData;
    cout << "Enter data to search: ";
    cin >> searchData;

    bool found = bst.retrieve(searchData);
    if (found)
        cout << "Data found in BST." << endl;
    else
        cout << "Data not found in BST." << endl;

    return 0;
}