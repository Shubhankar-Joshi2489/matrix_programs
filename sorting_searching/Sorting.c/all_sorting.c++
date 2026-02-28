#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

using namespace std;

// --- 1. Bubble Sort ---
// Best: O(n), Average/Worst: O(n^2)
void bubble_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Optimization to stop early if already sorted
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

// --- 2. Insertion Sort ---
// Best: O(n), Average/Worst: O(n^2)
void insertion_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        // Shift elements that are greater than key to one position ahead
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// --- 3. Selection Sort ---
// Time: O(n^2) for all cases
void selection_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; 
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
}

// --- 4. Merge Sort (Optimized Single Array) ---
// Time: O(n log n), Space: O(n)

void merge(vector<int>& a, vector<int>& temp, int left, int mid, int right) {
    int i = left;      
    int j = mid + 1;   
    int k = left;      

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];

    for (int idx = left; idx <= right; idx++) a[idx] = temp[idx];
}

void merge_sort_recursive(vector<int>& a, vector<int>& temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_recursive(a, temp, left, mid);
        merge_sort_recursive(a, temp, mid + 1, right);
        merge(a, temp, left, mid, right);
    }
}

void merge_sort(vector<int>& a) {
    if (a.empty()) return;
    vector<int> temp(a.size()); 
    merge_sort_recursive(a, temp, 0, a.size() - 1);
}

// --- 5. Quick Sort ---
// Average: O(n log n), Worst: O(n^2)

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quick_sort_recursive(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quick_sort_recursive(a, low, pi - 1);
        quick_sort_recursive(a, pi + 1, high);
    }
}

void quick_sort(vector<int>& a) {
    if (a.empty()) return;
    quick_sort_recursive(a, 0, a.size() - 1);
}

// --- Utility Functions ---
void printArray(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> original = {38, 27, 43, 3, 9, 82, 10,5,6};
    vector<int> data;

    // Test Bubble Sort
    data = original;
    bubble_sort(data);
    cout << "Bubble Sort:    "; printArray(data);

    // Test Insertion Sort
    data = original;
    insertion_sort(data);
    cout << "Insertion Sort: "; printArray(data);

    // Test Merge Sort
    data = original;
    merge_sort(data);
    cout << "Merge Sort:     "; printArray(data);

    return 0;
}   