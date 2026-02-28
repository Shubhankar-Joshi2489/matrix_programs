#include <iostream>
#include <vector>
using namespace std;

void rotateLeftPush(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;

    for(int i = 0; i < k; i++) {
        int first = arr[0];
        arr.push_back(first);
        arr.erase(arr.begin());
    }
}

void rotateRightPush(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;

    for(int i = 0; i < k; i++) {
        int last = arr.back();
        arr.pop_back();
        arr.insert(arr.begin(), last);
    }
}

void printArray(vector<int>& arr) {
    for(int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    int k = 2;

    rotateLeftPush(arr, k);
    cout << "Left rotated: ";
    printArray(arr);

    rotateRightPush(arr, k);
    cout << "Right rotated: ";
    printArray(arr);

    return 0;
}
