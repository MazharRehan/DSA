#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
};

Node* create() 
{
    int data;
    cout << "Enter root value (-1 for no child): ";
    cin >> data;

    if (data == -1) 
	{
        return nullptr;
    }

    Node* newNode = new Node;
    newNode->data = data;

    cout << "Enter left child of " << data << ": ";
    newNode->left = create();

    cout << "Enter right child of " << data << ": ";
    newNode->right = create();

    return newNode;
}

int main() 
{
    Node* root = create();

    // Test the tree by printing the root node value
    if (root != nullptr) 
	{
        cout << "Root value: " << root->data << endl;
    } 
	else {
        cout << "Empty tree!" << endl;
    }

    return 0;
}

