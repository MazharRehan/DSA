//linked list implementation

#include <iostream>
#include <assert.h>
#include <windows.h>
using namespace std;

template <class Type>
struct Node
{
    Type info;
    Node<Type>* link;
};

template <class Type>
class LinkedList
{
protected:
    Node<Type>* first;
    Node<Type>* last;
    int count;

public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    int length() const;
    void print() const;
    void insertAt(int location, const Type& insertItem);
    void insertEnd(const Type& insertItem);
    void removeAt(int location);
    void retrieveAt(int location, Type& retItem) const;
    void replaceAt(int location, const Type& repItem);
    void clearList();
    int seqSearch(const Type& item) const;
    void insert(const Type& insertItem);
    void remove(const Type& removeItem);
};

template <class Type>
LinkedList<Type>::LinkedList()
{
    first = nullptr;
    last = nullptr;
    count = 0;

    cout << "Creating an empty linked list." << endl;
}

template <class Type>
LinkedList<Type>::~LinkedList()
{
    clearList();
}

template <class Type>
bool LinkedList<Type>::isEmpty() const
{
    return (first == nullptr);
}

template <class Type>
int LinkedList<Type>::length() const
{
    return count;
}

template <class Type>
void LinkedList<Type>::print() const
{
    Node<Type>* current = first;

    if (isEmpty())
    {
        cout << "There is no element in the list." << endl;
    }
    else
    {
        while (current != nullptr)
        {
            cout << current->info << " ";
            current = current->link;
        }
        cout << endl;
    }
}

template <class Type>
void LinkedList<Type>::insertAt(int location, const Type& insertItem)
{
    if (location < 0 || location > count)
    {
        cerr << "The position of the item to be inserted is out of range." << endl;
        return;
    }

    Node<Type>* newNode = new Node<Type>;
    newNode->info = insertItem;
    newNode->link = nullptr;

    if (isEmpty()) // if the list is empty
    {
        first = newNode;
        last = newNode;
    }
    else if (location == 0) // if inserting at the beginning
    {
        newNode->link = first;
        first = newNode;
    }
    else if (location == count) // if inserting at the end
    {
        last->link = newNode;
        last = newNode;
    }
    else // if inserting in the middle
    {
        Node<Type>* current = first;
        for (int i = 0; i < location - 1; i++)
            current = current->link;

        newNode->link = current->link;
        current->link = newNode;
    }

    count++;
}

template <class Type>
void LinkedList<Type>::insertEnd(const Type& insertItem)
{
    insertAt(count, insertItem);
}

template <class Type>
void LinkedList<Type>::removeAt(int location)
{
    if (location < 0 || location >= count)
    {
        cerr << "The position of the item to be removed is out of range" << endl;
            return;
    }

    if (isEmpty()) // if the list is empty
    {
        cerr << "Cannot remove from an empty list" << endl;
            return;
    }

    Node<Type>* current = nullptr;
    if (location == 0) // if removing the first node
    {
        current = first;
        first = first->link;

        if (first == nullptr) // if the list becomes empty after removal
            last = nullptr;
    }
    else if (location == count - 1) // if removing the last node
    {
        Node<Type>* prev = first;
        for (int i = 0; i < location - 1; i++)
            prev = prev->link;

        current = prev->link;
        prev->link = nullptr;
        last = prev;
    }
    else // if removing a node in the middle
    {
        Node<Type>* prev = first;
        for (int i = 0; i < location - 1; i++)
            prev = prev->link;

        current = prev->link;
        prev->link = current->link;
    }

    delete current;
    count--;
}

template <class Type>
void LinkedList<Type>::retrieveAt(int location, Type& retItem) const
{
    if (location < 0 || location >= count)
    {
        cerr << "The position of the item to be retrieved is out of range" << endl;
        return;
    }

    Node<Type>* current = first;
    for (int i = 0; i < location; i++)
        current = current->link;

    retItem = current->info;
}

template <class Type>
void LinkedList<Type>::replaceAt(int location, const Type& repItem)
{
    if (location < 0 || location >= count)
    {
        cerr << "The position of the item to be replaced is out of range" << endl;
        return;
    }

    Node<Type>* current = first;
    for (int i = 0; i < location; i++)
        current = current->link;

    current->info = repItem;
}

template <class Type>
void LinkedList<Type>::clearList()
{
    Node<Type>* current = nullptr;
    while (first != nullptr)
    {
        current = first;
        first = first->link;
        delete current;
    }

    last = nullptr;
    count = 0;
}

template <class Type>
int LinkedList<Type>::seqSearch(const Type& item) const
{
    int index = 0;
    Node<Type>* current = first;

    while (current != nullptr)
    {
        if (current->info == item)
            return index;

        current = current->link;
        index++;
    }

    return -1; // item not found
}

template <class Type>
void LinkedList<Type>::insert(const Type& insertItem)
{
    insertEnd(insertItem);
}

template <class Type>
void LinkedList<Type>::remove(const Type& removeItem)
{
    int location = seqSearch(removeItem);
    if (location != -1)
        removeAt(location);
}

int main()
{
    LinkedList<int> myList;

    myList.insert(5);
    myList.insert(10);
    myList.insert(15);
    myList.insert(20);

    cout << "List: ";
    myList.print();

    cout << "List Length: " << myList.length() << endl;

    int item;

    myList.retrieveAt(2, item);
    cout << "Item at index 2: " << item << endl;

    myList.replaceAt(1, 25);
    cout << "List after replacing item at index 1 with 25: ";
    myList.print();

    myList.remove(10);
    cout << "List after removing item 10: ";
    myList.print();

    myList.clearList();
    cout << "List after clearing: ";
    myList.print();

    return 0;
}