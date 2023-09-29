/*
Task 1
Write a recursive function which takes head pointer of singly linked list as parameter and prints the singly
linked list in reverse order. Restriction: You are not allowed to use any other data structure in the function.
*/

#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class SLList
{
private:
    Node* head;
    void inputRecursive(Node*& currentNode) // *& is used to pass the pointer by reference
    {
        int val = 0;
        cout << "Input values (-999 to terminate): ";
        cin >> val;

        if (val == -999)
        {
            currentNode = NULL;
            return;
        }

        currentNode = new Node;
        currentNode->data = val;
        //currentNode->next = NULL;

        inputRecursive(currentNode->next);
    }

    void reversePrint(Node* header)
    {
        if (header == NULL)
            return;

        reversePrint(header->next);
        cout << header->data << "\t";
    }

    void destroyList(Node* currentNode)
    {
        if (currentNode == nullptr)
            return;

        destroyList(currentNode->next);
        delete currentNode;
    }


public:

    SLList()
    {
        head = NULL;
    }
    void input()
    {
        inputRecursive(head);
    }

    void reversePrint()
    {
        reversePrint(head);
    }
    ~SLList()
    {
        destroyList(head);
    }

};

int main()
{
    SLList obj;

    obj.input();
    obj.reversePrint();

    return 0;
}
