#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
};

class BinaryTree 
{
private:
    Node* root;

    Node* createNode(int data) 
	{
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    Node* insertNode(Node* node, int data) 
	{
        if (node == nullptr) {
            node = createNode(data);
        } 
		else 
		{
            if (node->left == nullptr)
                node->left = insertNode(node->left, data);
            else
                node->right = insertNode(node->right, data);
        }
        return node;
    }

    void destroyTree(Node* node) 
	{
        if (node != nullptr)
		{
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    void preOrderTraversal(Node* node) 
	{
        if (node != nullptr)
		{
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void inOrderTraversal(Node* node) 
	{
        if (node != nullptr) 
		{
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(Node* node) 
	{
        if (node != nullptr) 
		{
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int data) 
	{
        root = insertNode(root, data);
    }

    void preOrder() 
	{
        preOrderTraversal(root);
    }

    void inOrder() 
	{
        inOrderTraversal(root);
    }

    void postOrder() 
	{
        postOrderTraversal(root);
    }

    ~BinaryTree() 
	`{
        destroyTree(root);
    }
};

int main() {
    BinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    cout << "Preorder traversal: ";
    tree.preOrder();
    cout << endl;

    cout << "Inorder traversal: ";
    tree.inOrder();
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postOrder();
    cout << endl;

    return 0;
}

