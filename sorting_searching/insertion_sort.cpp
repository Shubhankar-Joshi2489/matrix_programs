#include<iostream>
using namespace std ;

void insertion_sort(int a[],int n)
{int temp;
for(int i=1;i<n;i++)
    {
        int j=i;
        while(j>0 && a[j-1]>a[j])
        {
           temp=a[j];
           a[j]=a[j-1];
           a[j-1]=temp;
           j--;
        }
    }
}




int main()
{   int i,n;
    cout<<"Enter no of elements in your array";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
      cin>>a[i];
    }
    insertion_sort(a,n);
    for(i=0;i<n;i++)
    {
    cout<<a[i]<<endl;
     }
}

