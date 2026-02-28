#include <vector>
#include <iostream>
using namespace std;
void rotate_left_manual(std::vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;
    k = k % n;
    std::vector<int> temp(n);

    // Copy elements from index k to n-1 to the start of temp
    for (int i = 0; i < n - k; ++i) {
        temp[i] = arr[i + k];
    }
    // Copy elements from index 0 to k-1 to the end of temp
    for (int i = 0; i < k; ++i) {
        temp[n - k + i] = arr[i];
    }
    
    arr = temp;
    for (int x:arr)
    {
    cout<<x;
    }
    cout<<" ";
}

void rotate_right_manual(std::vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;
    k = k % n;
    std::vector<int> temp(n);

    // Copy the last k elements to the beginning of temp
    for (int i = 0; i < k; ++i) {
        temp[i] = arr[n - k + i];
    }
    // Copy the remaining n-k elements
    for (int i = 0; i < n - k; ++i) {
        temp[k + i] = arr[i];
    }

    arr = temp;
     for (int x:arr)
    {
    cout<<x;
    }
    cout<<" ";
}
int main()

{   int k;
   
    cout<<"Enter k element";
    cin>>k;
   vector <int> a={1,2,3,4,5};
 vector <int> b=a;

   rotate_left_manual(a,k);
  rotate_right_manual(b,k);
}