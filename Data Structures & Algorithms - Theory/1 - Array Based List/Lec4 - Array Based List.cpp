// Array-based list implementation
#include<iostream>
#include<assert.h>
#include<windows.h>
using namespace std;

template <class elemType>
class arrayListType
{
protected:
    elemType* list;
    int length, maxSize;
public:
    arrayListType(int); // parameterized constructor
    arrayListType(const arrayListType<elemType>&); //copy constructor
    arrayListType(); // constructor
    ~arrayListType();//destructor

    bool isEmpty() const;	//Function to determine whether the list is empty
    bool isFull() const;    //Function to determine whether the list is full.
    int listSize() const;   //Function to determine the number of elements in the list
    int maxListSize() const;    	//Function to determine the size of the list
    void print() const; //Function to output the elements of the list
    bool isItemAtEqual(int, const elemType&) const;// Function to determine whether the item is the same as the item in the list at the position specified 
    void insertAt(int, const elemType&); //Function to insert an item in the list at the position specified by location. 
    void insertEnd(const elemType&); //Function to insert an item at the end of the list.
    void removeAt(int);//Function to remove the item from the list at the position specified by location
    void retrieveAt(int, elemType&) const; //Function to retrieve the element from the list at the position specified by location. 
    void replaceAt(int, const elemType&); //Function to replace the elements in the list at the position specified by location. 
    void clearList(); //Function to remove all the elements from the list.
    int seqSearch(const elemType&) const; // //Function to search the list for a given item.
    void insert(const elemType&);   //Function to insert the item specified by the parameter insertItem at the end of the list without doublicate values. 
    void remove(const elemType&);   //Function to remove an item from the list. The parameter removeItem specifies the item to be removed.
    const arrayListType<elemType>& operator=(const arrayListType<elemType>&); // Overload = operator
};

template <class elemType>
arrayListType<elemType>::arrayListType()
{
    list = new elemType[10];
    length = 0;
    maxSize = 10;

    cout << "Creating an array of size 10." << endl;
}

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating an array of size 100. " << endl;
        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0; 
    list = new elemType[maxSize];
    assert(list != NULL);

   // The statement assert(list != NULL) is used to check if the pointer list is not pointing 
   // to NULL.If list is indeed NULL, the assert function will terminate the program with an 
   // error message indicating that the assertion has failed.
   // assert is a preprocessor macro defined in the assert.h header file
}

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize]; //create the array
    assert(list != NULL);
    //terminate if unable to allocate memory space
    for (int j = 0; j < length; j++) //copy otherList
        list[j] = otherList.list[j];
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete[] list;
    list = NULL;
}

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
    return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
    return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
    if (length != 0)
    {
        for (int i = 0; i < length; i++)
            cout << list[i] << " ";
        cout << endl;
    }
    else
        cout << "There is no element in the list." << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const
{
    return  (list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted is out of range" << endl;
    else if (length >= maxSize) //list is full
        cerr << "Cannot insert in a full list" << endl;
    else
    {
        for (int i = length; i > location; i--)
            list[i] = list[i - 1]; //move the elements down
        list[location] = insertItem; //insert the item at the specified position
        length++; //increment the length
    }
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    if (length >= maxSize) //the list is full
        cerr << "Cannot insert in a full list" << endl;
    else
    {
        list[length] = insertItem; //insert the item at the end
        length++; //increment the length
    }
}

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed is out of range." << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i + 1];
        length--;
    }
}

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType& retItem) const
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is out of range." << endl;
    else
        retItem = list[location];
}

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType& repItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is out of range." << endl;
    else
        list[location] = repItem;
}

template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0;
}

template <class elemType>
int  arrayListType<elemType>::seqSearch(const elemType& item) const
{
    int loc;
    bool found = false;
    for (loc = 0; loc < length; loc++)
        if (list[loc] == item)
        {
            found = true;
            break;
        }
    if (found)
        return loc;
    else
        return -1;

}

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
    int loc;
    if (length == 0) //list is empty
        list[length++] = insertItem;  //insert the item and increment the length
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        loc = seqSearch(insertItem);
        if (loc == -1) //the item to be inserted does not exist in the list
            list[length++] = insertItem;
        else
            cerr << "The item to be inserted is already in the list. No duplicates are allowed." << endl;
    }
}

template <class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc;
    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);
        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list." << endl;
    }
}

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator = (const arrayListType<elemType>& otherList)
{
    if (this != &otherList) //avoid self-assignment
    {
        delete[] list;
        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new elemType[maxSize]; //create the array
        assert(list != NULL); //if unable to allocate memory space, terminate the program
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}



void displayMenu() 
{
    cout << "\n\t1  - Insert an item at a specific position\n"
        << "\t2  - Insert an item at the end\n"
        << "\t3  - Insert an item at the end of the list without doublicate values\n"
        << "\t4  - Remove an item from a specific position\n"
        << "\t5  - Remove a specific item\n"
        << "\t6  - Retrieve an item at a specific position\n"
        << "\t7  - Replace an item at a specific position\n"
        << "\t8  - Clear the list\n"
        << "\t9  - Check if the list is empty\n"
        << "\t10 - Check if the list is full\n"
        << "\t11 - Get the length of the list\n"
        << "\t12 - Get the maximum size of the list\n"
        << "\t13 - Print the list\n"
        << "\t14 - Search for an item\n"
        << "\t15 - Check if an item is equal to an item at a given position\n"
        << "\t16 - Assign another list to the current list\n"
        << "\t0  - Exit" << endl;
}

int main()
{
    int choice = 0, position = 0, temp = 0, maxSize = 0;
    arrayListType<int> list;

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        system("cls");
        cout << "Enter your choice: " << choice << endl;

        switch (choice)
        {
        case 1:
            cout << "Enter the position and item: ";
            cin >> position >> temp;
            list.insertAt(position, temp);
            break;
        case 2:
            cout << "Enter the item: ";
            cin >> temp;
            list.insertEnd(temp);
            break;
        case 3:
            cout << "Enter the item to insert: ";
            cin >> temp;
            list.insert(temp);
            break;
        case 4:
            cout << "Enter the position: ";
            cin >> position;
            list.removeAt(position);
            break;
        case 5:
            cout << "Enter the item: ";
            cin >> temp;
            list.remove(temp);
            break;
        case 6:
            cout << "Enter the position: ";
            cin >> position;
            list.retrieveAt(position, temp);
            cout << "Item at position " << position << ": " << temp << endl;
            break;
        case 7:
            cout << "Enter the position and item: ";
            cin >> position >> temp;
            list.replaceAt(position, temp);
            break;
        case 8:
            list.clearList();
            break;
        case 9:
            if (list.isEmpty()) {
                cout << "The list is empty." << endl;
            }
            else {
                cout << "The list is not empty." << endl;
            }
            break;
        case 10:
            if (list.isFull()) {
                cout << "The list is full." << endl;
            }
            else {
                cout << "The list is not full." << endl;
            }
            break;
        case 11:
            cout << "The length of the list is: " << list.listSize() << endl;
            break;
        case 12:
            cout << "The maximum size of the list is: " << list.maxListSize() << endl;
            break;
        case 13:
            list.print();
            break;
        case 14:
            cout << "Enter the item to search for: ";
            cin >> temp;
            position = list.seqSearch(temp);
            if (position == -1) {
                cout << "Item not found." << endl;
            }
            else {
                cout << "Item found at position: " << position << endl;
            }
            break;
        case 15:
            cout << "Enter the location: ";
            cin >> position;
            cout << "Enter the item: ";
            cin >> temp;
            if (list.isItemAtEqual(position, temp))
                cout << "The item is equal to the item at the specified location." << endl;
            else
                cout << "The item is not equal to the item at the specified location." << endl;
            break;

        

//        case 16:
//        	arrayListType<int> otherList;
//
//           	cout << "Enter the length of the other list: ";
//            cin >> length;
//         	cout << "Enter the items of the other list: ";
//     		for (int i = 0; i < length; i++)
//       		{
//        	   cin >> position;
//               otherList.insert(position);
//            }
//
//            list = otherList; // operater overload
//            cout << "List assigned." << endl;
//
//            break;

        case 0:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}

/*
#include <iostream>
#include "arrayListType.h"

using namespace std;

int main()
{
    arrayListType<int> myList;
    int choice, location, item;

    do
    {
        cout << endl;
        cout << "1. Check if an item is equal to an item at a given position" << endl;
        cout << "2. Clear the list" << endl;
        cout << "3. Insert an item at the end of the list" << endl;
        cout << "4. Assign another list to the current list" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the location: ";
            cin >> location;
            cout << "Enter the item: ";
            cin >> item;
            if (myList.isItemAtEqual(location, item))
                cout << "The item is equal to the item at the specified location." << endl;
            else
                cout << "The item is not equal to the item at the specified location." << endl;
            break;

        case 2:
            myList.clearList();
            cout << "List cleared." << endl;
            break;

        case 3:
            cout << "Enter the item to insert: ";
            cin >> item;
            myList.insert(item);
            break;

        case 4:
        {
            arrayListType<int> otherList;
            int otherLength, otherItem;

            cout << "Enter the length of the other list: ";
            cin >> otherLength;
            cout << "Enter the items of the other list: ";
            for (int i = 0; i < otherLength; i++)
            {
                cin >> otherItem;
                otherList.insert(otherItem);
            }

            myList = otherList;
            cout << "List assigned." << endl;
        }
        break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}
*/
