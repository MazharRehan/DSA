Task 3:

#include <iostream>
using namespace std;

template <class Type>
class Node
{
public:
    Type key;
    Node<Type>* leftChild;
    Node<Type>* rightChild;
};

template <class Type>
class Tree
{
protected:
    Node<Type>* root;

public:
    Tree()
    {
        root = nullptr;
    }

    virtual void insert(Type) = 0;

    virtual bool deleteNode(Type) = 0;
};

template <class Type>
class BinaryTree : public Tree<Type>
{
public:
    void insert(Type data) override
    {
        Node<Type>* newNode = new Node<Type>;
        newNode->key = data;
        newNode->leftChild = nullptr;
        newNode->rightChild = nullptr;

        if (this->root == nullptr)
        {
            this->root = newNode;
            return;
        }

        insertRecursive(this->root, newNode);
    }

    bool deleteNode(Type data) override
    {
        return deleteNodeRecursive(this->root, data);
    }

    //get root
    Node<int>* getRoot()
    {
        return this->root;
    }

    void inorderTraversal(Node<Type>* node)
    {
		if (node == nullptr)
			return;

		inorderTraversal(node->leftChild);
		cout << node->key << " ";
		inorderTraversal(node->rightChild);
	}
private:
    void insertRecursive(Node<Type>* currentNode, Node<Type>* newNode)
    {
        if (newNode->key < currentNode->key)
        {
            if (currentNode->leftChild == nullptr)
                currentNode->leftChild = newNode;
            else
                insertRecursive(currentNode->leftChild, newNode);
        }
        else if (newNode->key > currentNode->key)
        {
            if (currentNode->rightChild == nullptr)
                currentNode->rightChild = newNode;
            else
                insertRecursive(currentNode->rightChild, newNode);
        }
    }

    bool deleteNodeRecursive(Node<Type>*& currentNode, Type data)
    {
        if (currentNode == nullptr)
            return false;

        if (data < currentNode->key)
            return deleteNodeRecursive(currentNode->leftChild, data);
        else if (data > currentNode->key)
            return deleteNodeRecursive(currentNode->rightChild, data);
        else
        {
            if (currentNode->leftChild == nullptr && currentNode->rightChild == nullptr)
            {
                delete currentNode;
                currentNode = nullptr;
            }
            else if (currentNode->leftChild == nullptr)
            {
                Node<Type>* temp = currentNode;
                currentNode = currentNode->rightChild;
                delete temp;
            }
            else if (currentNode->rightChild == nullptr)
            {
                Node<Type>* temp = currentNode;
                currentNode = currentNode->leftChild;
                delete temp;
            }
            else
            {
                Node<Type>* successor = findMinNode(currentNode->rightChild);
                currentNode->key = successor->key;
                deleteNodeRecursive(currentNode->rightChild, successor->key);
            }

            return true;
        }
    }

  

    Node<Type>* findMinNode(Node<Type>* node)
    {
        if (node == nullptr || node->leftChild == nullptr)
            return node;

        return findMinNode(node->leftChild);
    }
};

int main()
{
    BinaryTree<int> binaryTree;

    binaryTree.insert(5);
    binaryTree.insert(3);
    binaryTree.insert(7);
    binaryTree.insert(2);
    binaryTree.insert(4);
    binaryTree.insert(6);
    binaryTree.insert(8);

    cout << "Binary Tree: ";
    binaryTree.inorderTraversal(binaryTree.getRoot());
    cout << endl;

    int data;
    cout << "Enter data to delete: ";
    cin >> data;

    bool deleted = binaryTree.deleteNode(data);
    if (deleted)
        cout << "Data deleted from Binary Tree." << endl;
    else
        cout << "Data not found in Binary Tree." << endl;

    cout << "Binary Tree after deletion: ";
    binaryTree.inorderTraversal(binaryTree.getRoot());
    cout << endl;

    return 0;
}
