// DSA Graded Lab 5

#include <iostream>
#include <list> 
using namespace std;

template<typename K, typename V>
struct HashEntry 
{
    K key;
    V value;
};


template<typename K, typename V>
class HashTable
{
private:
    list<HashEntry<K, V>>* table;
    int capacity;
    int size;

    int hashFunction(const K& key) 
    {
        hash<K> hasher;
        return hasher(key) % capacity;
    }

public:
    HashTable(int capacity) : capacity(capacity), size(0) 
    {
        table = new list<HashEntry<K, V>>[capacity];
    }

    ~HashTable() 
    {
        delete[] table;
    }

    void insert(const K& key, const V& value) 
    {
        int index = hashFunction(key);
        for (auto& entry : table[index]) 
        {
            if (entry.key == key) 
            {
               
                entry.value = value;
                return;
            }
        }
      
        table[index].push_back({ key, value });
        size++;
    }

    void remove(const K& key) 
    {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if (it->key == key) 
            {
                table[index].erase(it);
                size--;
                return;
            }
        }
    }

    V search(const K& key) 
    {
        int index = hashFunction(key);

        for (auto& entry : table[index])
            if (entry.key == key)
                return entry.value;
       
        return V();
    }

    int getSize()
    {
        return size;
    }

    void clear()
    {
        for (int i = 0; i < capacity; i++)
            table[i].clear();
        
        size = 0;
    }
};

int main() 
{
    HashTable<string, int> hashTable(10);

    cout << "Insertion" << endl;
    hashTable.insert("Orange", 5);
    hashTable.insert("Banana", 10);
    hashTable.insert("Mango", 15);

    cout << "Search" << endl;
    cout << "Value for key 'Orange': " << hashTable.search("Orange") << endl;
    cout << "Value for key 'Banana': " << hashTable.search("Banana") << endl;
    cout << "Value for key 'Mango': " << hashTable.search("Mango") << endl;
    cout << "Value for key 'Grapes': " << hashTable.search("Grapes") << endl;

    cout << "Remove `Banana`" << endl;
    hashTable.remove("Banana");

    cout << "Value for key 'Banana': " << hashTable.search("Banana") << endl;

    cout << "\nSize of hash table: " << hashTable.getSize() << endl;

    hashTable.clear();

    return 0;
}