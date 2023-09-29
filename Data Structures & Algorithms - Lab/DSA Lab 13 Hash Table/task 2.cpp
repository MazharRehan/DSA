/*
Task 2:

Perform the following operations
Search:  search a key inside the hash table and return the value that is associated with
that key

Insert: insert a new key-value pair inside the hash table

Delete: delete a particular key from the hash table

Delete Hash table: delete the hash table
*/

#include <iostream>
using namespace std;

class HashTable 
{
    int* table;
    const int tableSize;
public:
    HashTable() : tableSize(10)
    {
        table = new int[tableSize];
        for (int i = 0; i < tableSize; i++)
            table[i] = -1;  // Mark all slots as empty (-1)
        
    }

    ~HashTable() 
    {
        delete[] table;
    }

    int hash(int key) 
    {
        return key % tableSize;  // Hash function h(k) = k mod 10
    }

    void insert(int key, int value) 
    {
        int index = hash(key);  // Get the initial index

        while (table[index] != -1) 
        {
            // Linear probing: move to the next slot if the current slot is occupied
            index = (index + 1) % tableSize;
        }

        table[index] = value;  // Insert the value into the empty slot
    }

    int search(int key)
    {
        int index = hash(key);  // Get the initial index

        while (index != -1)
        {
            if (index == key)
                return table[index];
            index = (index + 1) % tableSize;  // Move to the next slot
        }
    }

    void remove(int key) // here key is the index of the array
    {
        int index = hash(key);  // Get the initial index

        while (table[index] != -1) 
        {
            if (table[index] == key) 
            {
                table[index] = -1;  // Mark the slot as empty
                return;
            }
            index = (index + 1) % tableSize;  // Move to the next slot
        }
    }

    void clear() 
    {
        for (int i = 0; i < tableSize; i++)
            table[i] = -1;  // Mark all slots as empty (-1)
    }

    void display() 
    {
        for (int i = 0; i < tableSize; i++) 
            if (table[i] != -1)
                cout << "Index " << i << ": " << table[i] << endl;
    }
};

int main()
{
    HashTable hashTable;

    // Insert key-value pairs
    hashTable.insert(12, 100);
    hashTable.insert(18, 200);
    hashTable.insert(13, 300);
    hashTable.insert(2, 400);
    hashTable.insert(3, 500);
    hashTable.insert(23, 600);
    hashTable.insert(5, 700);
    hashTable.insert(15, 800);

    // Search for a key
    int searchKey = 6;
    int searchResult = hashTable.search(searchKey);

    if (searchResult != -1)
        cout << "Value associated with key " << searchKey << ": " << searchResult << endl;
    else
        cout << "Key " << searchKey << " not found in the hash table." << endl;

    // Delete a key
    int deleteKey = 13;
    hashTable.remove(deleteKey);

    // Display the updated hash table
    cout << "Hash table after deleting key " << deleteKey << ":" << endl;
    hashTable.display();

    // Delete the hash table
    hashTable.clear();

    return 0;
}