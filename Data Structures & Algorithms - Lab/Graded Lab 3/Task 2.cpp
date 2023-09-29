// Task 2:

#include <iostream>
#include <cmath>
using namespace std;


struct Node 
{
    int val;
    Node* left, *right;

    Node(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

int getHeight(Node* root) 
{
    if (root == nullptr)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* root) 
{
    if (root == nullptr)
        return true;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    int heightDiff = abs(leftHeight - rightHeight);
    if (heightDiff > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

Node* constructTree() 
{
    int value;
    cin >> value;

    if (value == -1)
        return nullptr;

    Node* root = new Node(value);

    std::cout << "Left child of " << value << ": ";
    root->left = constructTree();

    std::cout << "Right child of " << value << ": ";
    root->right = constructTree();

    return root;
}

int main() 
{
    cout << "Enter the values for the binary tree:\n";
    cout << "Root node: ";
    Node* root = constructTree();

    bool balanced = isBalanced(root);

    if (balanced)
        cout << "The tree is balanced.\n";
    else
        cout << "The tree is not balanced.\n";

    return 0;
}
