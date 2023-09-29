#include <iostream>
using namespace std;

int recursiveSequentialSearch(int arr[], int start, int end, int target) {
    if (start > end) {
        return -1; // Target not found
    }

    if (arr[start] == target) {
        return start; // Found the target at index start
    }

    return recursiveSequentialSearch(arr, start + 1, end, target);
}

int main() {
    int arr[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 23;
    int index = recursiveSequentialSearch(arr, 0, size - 1, target);

    if (index != -1) {
        cout << target <<" found at index : " << index << endl;
    }
    else {
        cout << target <<" not found in the array." << endl;
    }

    return 0;
}

