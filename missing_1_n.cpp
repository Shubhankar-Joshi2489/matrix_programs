#include<iostream>
using namespace std;
int main()
{ int i,n;
    cout<<"Enter No of elements in Your array";
    cin>>n;
    int a[n];
    cout<<"Enter your elements from 1-n";
    for (i=1;i<=n;i++)
{
   cin>>a[i];
}
for(i=1;i<=n;i++)
{
    if(a[i]!=i)
    {
        cout<<i<<" is Missing no ";
        return 0;
    }
}
cout<<"No missing no";
return 0;
}