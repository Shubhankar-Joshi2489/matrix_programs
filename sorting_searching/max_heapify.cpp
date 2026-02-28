#include <iostream>
#include <algorithm> // for std::swap

using namespace std;

// Function to maintain the Max Heap property
void max_heapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}

// Function to build a Max Heap from an arbitrary array
void build_max_heap(int arr[], int n) {
    // Index of last non-leaf node is (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, n);

    build_max_heap(arr, n);

    cout << "Max Heap array: ";
    printArray(arr, n);

    delete[] arr; // Free memory
    return 0;
}