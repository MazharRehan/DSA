#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Found the target at index i
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 23;
    int index = sequentialSearch(arr, size, target);

    if (index != -1) {
        cout << target << " found at index : " << index << endl;
    }
    else {
        cout << target << " not found in the array." << endl;
    }

    return 0;
}
