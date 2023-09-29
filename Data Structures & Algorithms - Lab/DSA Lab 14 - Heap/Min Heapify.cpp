#include <iostream>
using namespace std;

void minHeapify(int* arr, int size, int index) 
{
    int smallest = index;        // Initialize the smallest element as the root
    int leftChild = 2 * index + 1;   // Left child index
    int rightChild = 2 * index + 2;  // Right child index

    // If the left child is smaller than the root
    if (leftChild < size && arr[leftChild] < arr[smallest])
        smallest = leftChild;

    // If the right child is smaller than the current smallest
    if (rightChild < size && arr[rightChild] < arr[smallest])
        smallest = rightChild;

    // If the smallest element is not the root, swap them
    if (smallest != index) 
    {
        swap(arr[index], arr[smallest]);

        // Recursively heapify the affected sub-tree
        minHeapify(arr, size, smallest);
    }
}

int main() 
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int* arr = new int[size];

    std::cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];

    // Heapify the array
    for (int i = size / 2 - 1; i >= 0; --i)
        minHeapify(arr, size, i);

    std::cout << "Min Heap: ";
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";

    delete[] arr;  // Deallocate the dynamically allocated array

    return 0;
}
