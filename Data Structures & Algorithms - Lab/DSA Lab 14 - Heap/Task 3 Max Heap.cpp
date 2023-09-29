//Task 3: Implement a Max Heap

#include <iostream>
using namespace std;

class Heap
{
protected:
    int* arr;
    int capacity; // maximum possible size of the heap
    int current; // current size of the heap

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

class MaxHeap : public Heap
{
public:
    MaxHeap(int capacity) : Heap(capacity) {}

    void insert(int key) override
    {
        if (current == capacity)
        {
            cout << "Heap is full. Cannot insert key: " << key << endl;
            return;
        }

        // Insert the key at the end of the array
        arr[current] = key;

        // Fix the Max Heap property by calling heapify
        heapifyLast(current);

        current++;
    }

    // Heapify the last inserted element of the array
    void heapifyLast(int index)
    {
        if (index == 0)
            return;

        int parent = (index - 1) / 2;

        if (parent >= 0 && arr[parent] < arr[index])
        {
            swap(arr[parent], arr[index]);
            heapifyLast(parent);
        }
    }

    int getMax()
    {
        if (current == 0)
        {
            cout << "Heap is empty." << endl;
            return -1; // or any other suitable value to indicate an empty heap
        }

        return arr[0];
    }

    void print()
    {
        for (int i = 0; i < current; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void input()
    {
		int n;
		cout << "Enter the number of elements: ";
		cin >> n;

		cout << "Enter the elements: ";
        for (int i = 0; i < n; i++)
        {
			int x;
			cin >> x;
			insert(x);
		}
	}
};


int main()
{
    MaxHeap maxHeap(10);

    maxHeap.input();

    cout << "Max Heap array: ";
    maxHeap.print();

    int maxElement = maxHeap.getMax();
    if (maxElement != -1)
        cout << "Minimum element in Min Heap: " << maxElement << endl;

    return 0;
}

