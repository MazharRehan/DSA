// Purpose: Implementation of the maxHeapify function
//Heapify is a process of converting a binary tree into a Heap data structure. 
//A binary tree is a Complete Binary Tree if all the levels are completely filled 
//except possibly the last level and the last level has all keys as left as possible. 
//A Heap is a special Tree-based data structure in which the tree is a complete binary tree. 
//Generally, Heaps can be of two types:
//Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children.
//Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children.

#include <iostream> 
using namespace std;

// Function to maintain the max heap property
void maxHeapify(int arr[], int n, int i) 
{
    int largest = i;                // Initialize the largest as the root
    int left = 2 * i + 1;           // Left child index
    int right = 2 * i + 2;          // Right child index

    // Check if the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if the right child is larger than the current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root, swap the largest with the root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively call maxHeapify on the affected subtree
        maxHeapify(arr, n, largest);
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() 
{
    int arr[] = { 4, 10, 3, 5, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before heapify: ";
    printArray(arr, n);

    maxHeapify(arr, n, 0); // Index of the root node is 0

    cout << "Array after heapify: ";
    printArray(arr, n);

    return 0;
}