//Task 2: Implement a Min Heap

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


class MinHeap : public Heap
{
public:
    MinHeap(int capacity) : Heap(capacity) {}

    void insert(int key) override
    {
        if (current == capacity)
        {
            cout << "Heap is full. Cannot insert key: " << key << endl;
            return;
        }

        // Insert the key at the end of the array
        arr[current] = key;

        // Fix the Min Heap property by calling heapify
        //heapify(0);
        //instead of heapify the whole array, we can heapify only the last element
        heapifyLast(current);

        current++;
    }

    // Heapify the last inserted element of the array
    void heapifyLast(int index)
    {
		if (index == 0)
			return;

		int parent = (index - 1) / 2;

        if (parent >= 0 && arr[parent] > arr[index])
        {
			swap(arr[parent], arr[index]);
			heapifyLast(parent);
		}
	}

    // Heapify the whole array
    void heapify(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int smallest = index;

        if (left < current && arr[left] < arr[smallest])
            smallest = left;

        if (right < current && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != index)
        {
            swap(arr[index], arr[smallest]);
            heapify(smallest);
        }
    }

    int getMin()
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
		
        while(1)
        {
            cout << "Enter the number of elements: (n <= "<< capacity << "): ";
			cin >> n;
            if (n<1 || n>capacity)
				cout << "Invalid input. Try again." << endl;
            else
                break;
        }

        for (int i = 0; i < n; i++)
        {
			int key;
			cout << "Enter the key to be inserted: ";
			cin >> key;

			insert(key);
		}
	}
};

int main()
{
    MinHeap minHeap(10);

    minHeap.input();

    cout << "Min Heap array: ";
    minHeap.print();

    int minElement = minHeap.getMin();
    if (minElement != -1)
        cout << "Minimum element in Min Heap: " << minElement << endl;

    return 0;
}

