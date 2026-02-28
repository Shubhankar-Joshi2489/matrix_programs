#include<iostream>
using namespace std;
int main()
{ int i,n;
    cout<<"Enter No of elements in Your array";
    cin>>n;
    int a[n];
    cout<<"Enter your elements";
for (i=0;i<n;i++)
{
   cin>>a[i];
}
for (i=n-1;i>=0;i--)
{
    cout<<a[i]<<" ";
}
}