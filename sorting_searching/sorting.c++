#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int>&a)
{
   int n=a.size();
   int i,j,temp;
   for(i=0;i<n;i++)
   {
    for(j=0;j<n-i-1;j++)
    {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
   }
   for (i=0;i<n;i++)
   {
    cout<<a[i];
   }
}
void selection_sort(vector<int>&a)
{
  int n=a.size();
  int i,j,min,temp;
  for(i=0;i<n;i++)
  {
    min=a[i];
    for(j=i+1;j<n;j++)
    {
        if(a[j]<min)
        {
            min=a[j];

        }

    }
    temp=a[i];
    a[i]=min;
    min=temp;
  }
    for (i=0;i<n;i++)
   {
    cout<<a[i];
   }
}

void insertion_sort(vector<int>&a)
{
  int n=a.size();
  int i,temp;

  for(i=1;i<n;i++)
  {  int j=i;
    while(j>0 && a[j-1]>a[j])
    {
       temp=a[j-1];
       a[j-1]=a[j];
       a[j]=temp;
    }
  }
  for (i=0;i<n;i++)
   {
    cout<<a[i];
   }
}
void merge_sort(vector<int>&a)
{
  int n=a.size();
  void merge (vector<int>&a,int left,int mid,int right)
  {
    int i=left;
    int j=mid+1;
    int k=left;
    while (i<=mid && j<=right)
    {
      if(arr[i]<=arr[j])
      {
        temp[k++]=arr[i++];
      }
      else
      {
        temp[k++]=arr[j++];
      }
    }
    while(i<=mid) temp[k++]=a[i++];
    while(j<=right) temp[k++]=a[j++];
    for (i=left;i<=right;i++)
    {
      a[i]=temp[i];
    }
    for (i=0;i<n;i++)
   {
    cout<<a[i];
   }
  }
  void sort(vector<int>&a,int left,int right)
  {
    if(left<right)
    {
      int mid=left+(right-left)/2;
      sort(a,left,mid);
      sort(a,mid+1,right);
      merge(a,left,mid,right);


    }
  }
}
void quick_sort(vector<int>&a)
{
  int n=a.size();
  int partition(vector <int>&a,int low , int high)
  {
    int pivot =a[high];
    int i=low-1;
    int temp;
    for (int j=low;j<=high-1;j++)
    {
      if(arr[j]<pivot)
      {
        i++;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        
      }
      
    }
    temp=arr[i+1];
    arr[i+1]=arr[i];
    arr[i]=temp;

    void qsort(vector<int>&a,int low,int high)
    {
      if(low<high)
      {
        int pi=Partion(a,low,high);
        quicksort(a,pow,pi-1);
        quicksort(a,pi+1,high);
      }
    }
  }
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