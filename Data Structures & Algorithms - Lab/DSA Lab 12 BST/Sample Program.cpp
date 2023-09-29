// Binary Search Tree (BST) implementation in C++.

#include <iostream>
using namespace std;

struct Node 
{
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key) 
{
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int key) 
{
    if (root == nullptr)
        return createNode(key);

    if (key <= root->key) // use <= if you want to allow duplicates
        root->left = insertNode(root->left, key);
    else if (key >= root->key)
        root->right = insertNode(root->right, key);
    
    return root;
}

/*
Node* findMinNode(Node* node) 
{
    Node* current = node;
    // find the leftmost leaf
    while (current && current->left != nullptr)
        current = current->left;
    
    return current;
}
*/

// findMinNode using recursion
Node* findMinNode(Node* node)
{
	if (node == nullptr || node->left == nullptr)
		return node;
	return findMinNode(node->left);
}

Node* deleteNode(Node* root, int key) 
{
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else 
    {
        if (root->left == nullptr) 
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) 
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMinNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorderTraversal(Node* root) 
{
    if (!root) // if root == nullptr
        return;

    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
    
}
// input recursive function
void input(Node*& root)
{
	int key;
    cout << "Enter key: (-99 to exit): ";
	cin >> key;
	if (key == -99)
		return;
	root = insertNode(root, key);
	input(root);
}

int main() 
{
    Node* root = nullptr;

    input(root);

    cout << "BST after insertion: ";
    inorderTraversal(root);
    cout << endl;

    cout<< "Enter key to be deleted: ";
    int key;
    cin >> key;
    root = deleteNode(root, key);

    cout << "BST after deletion: ";
    inorderTraversal(root);
    cout << endl;

    // min value
    int min = findMinNode(root)->key;
    if(min != -1)
		cout << "Minimum value in BST: " << min << endl;
	else
		cout << "BST is empty." << endl;

    // please note that inorder traversal of BST is always in ascending order
    cout << "Inorder traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}