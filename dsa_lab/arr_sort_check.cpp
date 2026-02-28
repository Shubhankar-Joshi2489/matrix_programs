#include<iostream>
using namespace std;
int main()
{
    int i,n;
    cout<<"Enter no of elemnts in your array";
    cin>>n;
    int a[n];

    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (i=0;i<n-1;i++)
    {
        if(a[i+1]<a[i])
        {
            cout<<"Array not in ascending order";
            return 0;

        }

    }
    cout<<"Array in ascending order";
    return 0;
}