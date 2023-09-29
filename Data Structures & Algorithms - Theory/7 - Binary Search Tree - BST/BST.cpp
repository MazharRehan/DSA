//BST
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class BST
{
private:
    Node* root;

    Node* insert(Node* node, int data)
    {
        if (node == NULL)
        {
            node = new Node;
            node->data = data;
            node->left = node->right = NULL;
        }
        else if (data <= node->data) // here = sign is used to handle duplicate values, it insert duplicate values in left subtree
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        return node;
    }

    bool search(Node* node, int data)
    {
        if (node == NULL)
            return false;
  
        else if (node->data == data)
            return true;
        else if (data <= node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
        
    }

    void preOrder(Node* node)
    {
        if (node == NULL)
            return;

        cout << node->data << "\t";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node* node)
    {
        if (node == NULL)
            return;

        inOrder(node->left);
        cout << node->data << "\t";
        inOrder(node->right);
    }

    void postOrder(Node* node)
    {
        if (node == NULL)
            return;

        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << "\t";
    }

    void deleteTree(Node* node)
    {
        if (node == NULL)
            return;

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
public:
    BST()
    {
        root = NULL;
    }
    void insert(int data)
    {
        root = insert(root, data);
    }
    bool search(int data)
    {
        return search(root, data);
    }
    void preOrder()
    {
        preOrder(root);
    }
    void inOrder()
    {
        inOrder(root);
    }
    void postOrder()
    {
        postOrder(root);
    }
    ~BST()
    {
        deleteTree(root);
    }
};

int main()
{
    BST bst;
    bst.insert(15);
    bst.insert(10);
    bst.insert(20);
    bst.insert(25);
    bst.insert(8);
    bst.insert(12);

    cout << "PreOrder Traversal\n";
    bst.preOrder();
    cout << "\nInOrder Traversal\n";
    bst.inOrder();
    cout << "\nPostOrder Traversal\n";
    bst.postOrder();

    int number;
    cout << "\nEnter number to be searched: ";
    cin >> number;
    if (bst.search(number))
    {
        cout << "Found\n";
    }
    else {
        cout << "Not Found\n";
    }

    return 0;
}

