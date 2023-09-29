//Task 1:
#include <iostream>
using namespace std;

class Heap
{
protected:
    int* arr;
    int capacity;
    int current;

public:
    Heap(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        current = 0;
    }

    virtual ~Heap()
    {
        delete[] arr;
    }

    virtual void insert(int key) = 0;
};
