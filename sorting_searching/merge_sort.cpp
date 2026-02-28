
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &arr,int left,int mid ,int right)
{
  int n1=mid-left+1;
  int n2=right-mid;
  vector <int> L(n1),R(n2);
  for(int i=0;i<n1;i++)
  L[i]=arr[left+i];
  for(int j=0;j<n2;j++)
  R[j]=arr[mid+1+j];
  int i=0,j=0;
  int k=left;
  while(i<n1 && j<n2 )
  {
    if(L[i]>R[j])
    {
        arr[k]=L[i];
        i++;
    }
    else
    {
        arr[k]=R[j];
        j++;
    }
    k++;
  }
  while(i<n1)
  {
    arr[k]=L[i];
    i++;
    k++;
  }
  while(j<n2)
  {
    arr[k]=R[j];
    j++;
    k++;
  }
}
void mergesort (vector<int> &arr,int left,int right)
{   if(left>=right)
    return ;

    int mid=left+(right-left)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);


}
int main(){
    
    vector<int> arr = {38, 27, 43, 10,5,2,7,13};
    int n = arr.size();

    mergesort(arr, 0, n - 1);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}

/*
#include <iostream>
#include <vector>

// Merges two sorted halves into the auxiliary array, then back to original
void merge(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right) {
    int i = left;      // Starting index for left subarray
    int j = mid + 1;   // Starting index for right subarray
    int k = left;      // Starting index for temporary array

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements of left subarray, if any
    while (i <= mid) temp[k++] = arr[i++];

    // Copy remaining elements of right subarray, if any
    while (j <= right) temp[k++] = arr[j++];

    // Copy the merged elements back into the original array
    for (int idx = left; idx <= right; idx++) {
        arr[idx] = temp[idx];
    }
}

void mergeSort(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursive calls
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);

        // Merge the sorted halves
        merge(arr, temp, left, mid, right);
    }
}

int main() {
    std::vector<int> data = {38, 27, 43, 3, 9, 82, 10};
    
    // The single extra array used for merging
    std::vector<int> temp(data.size());

    mergeSort(data, temp, 0, data.size() - 1);

    std::cout << "Sorted array: ";
    for (int x : data) std::cout << x << " ";
    
    return 0;
}


*/