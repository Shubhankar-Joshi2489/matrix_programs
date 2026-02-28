#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];
    unordered_map<int, int> freq;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    cout << "Frequency of elements:\n";
    for (auto p : freq) {
        cout << p.first << "-" << p.second << endl;
    }

    return 0;
}
