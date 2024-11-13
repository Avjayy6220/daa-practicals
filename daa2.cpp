#include <iostream>
using namespace std;

class quickSort {
public:
    void Sort(int arr[], int low, int high) {
        int loctn;
        if (low < high) {
            loctn = partition(arr, low, high);
            Sort(arr, low, loctn - 1);
            Sort(arr, loctn + 1, high);
        }
    }

    int partition(int arr[], int low, int high) {
        int pivot = arr[low];
        int start = low;
        int end = high;

        while (start < end) {
            // Move start index forward if arr[start] <= pivot and it hasn't exceeded high
            while (start <= high && arr[start] <= pivot) {
                start++;
            }

            // Move end index backward if arr[end] > pivot and it hasn't dropped below low
            while (end >= low && arr[end] > pivot) {
                end--;
            }

            if (start < end) {
                swap(arr[start], arr[end]);
            }
        }
        
        // Place the pivot element in its correct position
        swap(arr[low], arr[end]);
        return end;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort obj;
    obj.Sort(arr, 0, n - 1);

    cout << "Sorted array using Quick sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
