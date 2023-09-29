#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) 
{
    int left = 0;
    int right = size - 1;

    while (left <= right) 
	{
        int mid = (right + left) / 2;

        if (arr[mid] == target) {
            return mid; // Found the target
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        }
        else {
            right = mid - 1; // Target is in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 91;
    int index = binarySearch(arr, size, target);

    if (index != -1) {
        cout << target <<" found at index : " << index << endl;
    }
    else {
        cout << target <<" not found in the array." << endl;
    }

    return 0;
}
