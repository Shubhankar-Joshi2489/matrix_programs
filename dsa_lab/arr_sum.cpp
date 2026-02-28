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
int sum=0;
for (i=0;i<n;i++)
{
    sum=sum+a[i];
}
cout<<"Sum of all the elemnts ="<<sum;
return 0;
}