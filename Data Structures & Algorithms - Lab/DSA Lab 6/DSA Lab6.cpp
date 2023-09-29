				// Doubly Linked List
//Lab 6:

#include<iostream>
using namespace std;

template<class T, T defaultVal = T()>
class Node
{
public:
    T data;
    Node<T>* next, * prev;
    Node()
    {
        data = defaultVal;
        next = prev = NULL;
    }
};

template<class T>
class MyDoublyLinkedList
{
    Node<T>* head, * tail;
    int maxSize;
public:
    MyDoublyLinkedList();
    ~MyDoublyLinkedList();
    void addNode(T);
    Node<T>* getHead();
    Node<T>* getTail();
    void insertAtBegin(T); // to add node at the begging of list.
    void insertAtEnd(T); // to add node at the last of list.
    void insertAt(T, T); // to insert new value anywhere in list.
    void deleteFromBegin(); // to delete node from the begging of list.
    void deleteFromEnd(); // to delete node from the last of list.
    void deleteMax(); // to delete maximum value in list.
    void deleteList(); //  delete the complete list.
    bool search(T); // search any node from the list.
    void display(); // display list on console.
    void reverveDisplay(); //  to display the complete list in reverse order.
    void inputList(); // input complete list at once

};

template <class T>
MyDoublyLinkedList<T>::MyDoublyLinkedList()
{
    head = tail = NULL;
    maxSize = 0;
}
template <class T>
MyDoublyLinkedList<T>::~MyDoublyLinkedList()
{
    if (head != NULL)
    {
        Node<T>* currentNode = head;
        Node<T>* nextNode;

        while (currentNode != NULL)
        {
            nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
    }
}
template <class T>
void MyDoublyLinkedList<T>::addNode(T value)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) 
	{
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    }
    else 
	{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    maxSize++;
}
template <class T>
Node<T>* MyDoublyLinkedList<T>::getHead() 
{
    return head;
}
template <class T>
Node<T>* MyDoublyLinkedList<T>::getTail() 
{
    return tail;
}
template <class T>
void MyDoublyLinkedList<T>::insertAtBegin(T value)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->prev = NULL;

    if (head == NULL) 
    {
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    }
    else 
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    maxSize++;
}
template <class T>
void MyDoublyLinkedList<T>::insertAtEnd(T value)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) 
    {
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    }
    else 
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    maxSize++;
}
template <class T>
void MyDoublyLinkedList<T>::insertAt(T index, T value)
{
    if (index >= 0 && index <= maxSize)
    {
        if (index == 0)
            insertAtBegin(value);
        else if (index == maxSize)
            insertAtEnd(value);
        else
        {
            Node<T>* newNode = new Node<T>;
            newNode->data = value;
            Node<T>* currentNode = head;

            for (int i = 0; i < index; i++) // finding index node
                currentNode = currentNode->next;

            newNode->next = currentNode;
            newNode->prev = currentNode->prev;
            currentNode->prev->next = newNode;
            currentNode->prev = newNode;
            maxSize++;
        }
    }
    else
        cout << "Invalid index." << endl;
}
template <class T>
void MyDoublyLinkedList<T>::deleteFromBegin()
{
    if (head != NULL)
    {
        Node<T>* firstNode = head;

        if (head->next != NULL) // for more than 1 node node
        {
            head = head->next;
            head->prev = NULL;
        }

        delete firstNode;
        firstNode = NULL;
        maxSize--;
    }
    else
        cout << "List is empty." << endl;
}
template <class T>
void MyDoublyLinkedList<T>::deleteFromEnd()
{
    if (head != NULL)
    {
        Node<T>* lastNode = tail;

        if (tail->prev != NULL) // tail is not at head
        {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete lastNode;
        lastNode = NULL;
        maxSize--;
    }
    else
        cout << "List is empty." << endl;
}
template <class T>
void MyDoublyLinkedList<T>::deleteMax()
{
    if (head != NULL)
    {
        Node<T>* maxNode = head;
        Node<T>* currentNode = head;

        while (currentNode != NULL)
        {
            if (currentNode->data > maxNode->data)
                maxNode = currentNode;
            currentNode = currentNode->next;
        }

        if (maxNode == head)
        {
            if (head->next != NULL) // more than one nodes in the list
            {
                head = head->next;
                head->prev = NULL;
            }
            else // only one node in the list
            {
                delete maxNode;
                maxNode = NULL;

                head = NULL;
                tail = NULL;

                maxSize--;
                return;
            }
        }
        else if (maxNode == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
        }

        if (maxNode->prev != NULL)
            maxNode->prev->next = maxNode->next;

        if (maxNode->next != NULL)
            maxNode->next->prev = maxNode->prev;

        delete maxNode;
        maxNode = NULL;
        maxSize--;
    }
    else
        cout << "List is empty." << endl;
}
template <class T>
void MyDoublyLinkedList<T>::deleteList()
{
    if (head != NULL)
    {
        Node<T>* currentNode = head;
        Node<T>* nextNode;

        while (currentNode != NULL)
        {
            nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }

        head = NULL;
        tail = NULL;
        maxSize = 0;
    }
}
template <class T>
bool MyDoublyLinkedList<T>::search(T val)
{
    Node<T>* temp = head;

    while (temp != NULL)
        if (temp->data == val)
            return true;
        else
            temp = temp->next;

    return false;
}
template <class T>
void MyDoublyLinkedList<T>::display()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node<T>* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
}
template <class T>
void MyDoublyLinkedList<T>::reverveDisplay()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node<T>* temp = tail;

        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->prev;
        }
        cout << endl;
    }
}
template <class T>
void MyDoublyLinkedList<T>::inputList()
{
    cout << "Enter the number of elements do you want to add: ";

    while (1) 
	{
        cin >> maxSize;
        if (maxSize < 1)
            cout << "Please input correct(+ve number) size.";
        else
            break;
    }


    head = new Node<T>;

    Node<T>* newNode, * previousNode;
    newNode=previousNode = head;
    T value = T();

    cout << "Input elements: ";
    cin >> value;
    head->data = value;
    head->prev = NULL;

    for (int i = 1; i < maxSize; i++)
    {
        cin >> value;
        newNode = new Node<T>;

        newNode->data = value;
        previousNode->next = newNode;
        newNode->prev = previousNode;
        previousNode = newNode;
    }

    tail = newNode;
    tail->next = NULL;
}

template <typename T> void factory();

int main() 
{
    factory<int>();

    return 0;
}

template<typename T>
void factory()
{
    MyDoublyLinkedList<int> myList;
    int choice = 0, index = 0;
    T value = T();

    do {
        cout << "Select an action:\n"
            << "1.  Add a node at the beginning\n"
            << "2.  Add a node at the end\n"
            << "3.  Add a node at a specific position\n"
            << "4.  Remove a node from the beginning\n"
            << "5.  Remove a node from the end\n"
            << "6.  Delete maximum value in list.\n"
            << "7.  Delete the complete list\n"
            << "8.  Search any node from the list\n"
            << "9.  Display the list\n"
            << "10. Display the complete list in reverse order\n"
            << "11. Input complete list\n"
            << "0. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a value to add: ";
            cin >> value;
            myList.insertAtBegin(value);
            break;
        case 2:
            cout << "Enter a value to add: ";
            cin >> value;
            myList.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter the index to add: ";
            cin >> index;
            cout << "Enter a value to add: ";
            cin >> value;
            myList.insertAt(index, value);
            break;
        case 4:
            myList.deleteFromBegin();
            break;
        case 5:
            myList.deleteFromEnd();
            break;
        case 6:
            myList.deleteMax();
            break;
        case 7:
            myList.deleteList();
            break;
        case 8:
            cout << "Enter a value do you want to search: ";
            cin >> value;
            cout << value << " is " << ((myList.search(value)) ? "" : "not ") << "found in the list." << endl;
            break;
        case 9:
            cout << "The list is: ";
            myList.display();
            break;
        case 10:
            myList.reverveDisplay();
            break;
        case 11:
            myList.inputList();
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}
