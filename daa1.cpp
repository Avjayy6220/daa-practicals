#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they're in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform binary search using divide and conquer
int binarySearch(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2; // Calculate mid-point to avoid overflow

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found at mid
        }
        // If target is greater, ignore left half
        else if (arr[mid] < target) {
            return binarySearch(arr, mid + 1, high, target);
        }
        // If target is smaller, ignore right half
        else {
            return binarySearch(arr, low, mid - 1, target);
        }
    }

    return -1; // Target not found
}

int main() {
    int n, target;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array using Bubble Sort
    bubbleSort(arr, n);

    cout << "Enter the element to search for: ";
    cin >> target;

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, target);

    // Output sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Output search result
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
