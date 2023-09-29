#include <iostream>
using namespace std;

int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Found the target at index mid
        }
        else if (arr[mid] < target) {
            return recursiveBinarySearch(arr, mid + 1, right, target); // Target is in the right half
        }
        else {
            return recursiveBinarySearch(arr, left, mid - 1, target); // Target is in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 72;
    int index = recursiveBinarySearch(arr, 0, size - 1, target);

    if (index != -1) {
        cout << target <<" found at index : " << index << endl;
    }
    else {
        cout << target <<" not found in the array." << endl;
    }

    return 0;
}
