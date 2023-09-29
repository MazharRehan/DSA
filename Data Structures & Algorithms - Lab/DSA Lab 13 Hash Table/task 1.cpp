/* Task 1:
Consider an empty hash table of size 10 and insert following keys 12, 18, 13, 2, 3, 23, 5 and 15
using open addressing with hash function h(k) = k mod 10 and linear probing.
*/

#include <iostream>
using namespace std;

class HashTable 
{
private:
    int* table;
    const int tableSize;
public:
    HashTable(): tableSize(10)
    {
        table = new int[tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = -1;  // Mark all slots as empty (-1)
        }
    }

    ~HashTable() 
    {
        delete[] table;
    }

    int hash(int key) 
    {
        return key % tableSize;  // Hash function h(k) = k mod 10
    }

    void insert(int key)
    {
        int index = hash(key);  // Get the initial index

        while (table[index] != -1) 
        {
            // Linear probing: move to the next slot if the current slot is occupied
            index = (index + 1) % tableSize;
        }

        table[index] = key;  // Insert the key into the empty slot
    }

    void display() 
    {
        for (int i = 0; i < tableSize; i++) 
        {
            if (table[i] != -1) 
            {
                cout << "Index " << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() 
{
    HashTable hashTable;

    int keys[] = { 12, 18, 13, 2, 3, 23, 5, 15 };
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++)
        hashTable.insert(keys[i]);
    

    hashTable.display();

    return 0;
}
