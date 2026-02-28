#include <iostream>
#include <vector>
using namespace std;

// Function to reverse a portion of the array
void reverse(vector<int>& arr, int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to rotate array to the left by k positions
void rotateLeft(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // in case k > n
    if (k == 0) return;
    
    reverse(arr, 0, k-1);    // Reverse first k elements
    reverse(arr, k, n-1);    // Reverse remaining elements
    reverse(arr, 0, n-1);    // Reverse the whole array
}

// Function to rotate array to the right by k positions
void rotateRight(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // in case k > n
    if (k == 0) return;
    
    reverse(arr, 0, n-1);    // Reverse the whole array
    reverse(arr, 0, k-1);    // Reverse first k elements
    reverse(arr, k, n-1);    // Reverse remaining elements
}


void printArray(const vector<int>& arr) {
    for(int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 6;

    cout << "Original array: ";
    printArray(arr);

    rotateLeft(arr, k);
    cout << "Array after left rotation by " << k << ": ";
    printArray(arr);

    rotateRight(arr, k);
    cout << "Array after right rotation by " << k << ": ";
    printArray(arr);

    return 0;
}
