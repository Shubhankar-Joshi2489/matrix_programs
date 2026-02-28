#include <iostream>
#include <vector>
using namespace std;

int main()
{ int n,i,j,temp=0;
   bool swap=false;
  cout<<"Enter the no of elements in your array";
  cin>>n;
  cout<<"Enter your elements ";
  int a[n];
  for (i=0;i<n;i++)
  {  cin>>a[i];
     }
   for (i=0;i<n-1;i++)//n-1 passes
   { 
   for (j=0;j<n-i-1;j++)//n-i-1 comparissions
   {   if(a[j+1]<a[j])
    { 
      temp=a[j];
      a[j]=a[j+1];
      a[j+1]=temp;
      swap=true;
   }
}
if(swap==false)
      {
         cout<<"already swaped";
         break;
      }
   }
for (i=0;i<n;i++)
  {  cout<<a[i]<<" ";
     }
return 0;
}