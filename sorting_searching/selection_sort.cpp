#include<iostream>
#include<vector>
using namespace std;

int main()
{ int n,i,j,temp=0;
   int maxx;
  cout<<"Enter the no of elements in your array";
  cin>>n;
  cout<<"Enter your elements ";
  vector<int> a(n);
  for (i=0;i<n;i++)
  {  cin>>a[i];
     }
  for( i=0;i<n-1;i++)
  { maxx=i;
    for(j=i+1;j<n;j++)
    {
        if(a[j]>a[maxx])
        {
            maxx=j;
        }
       5
       

    }
        temp=a[maxx];
        a[maxx]=a[i];
        a[i]=temp;
  }
  for (i=0;i<n;i++)
  {  cout<<a[i];
     }
}
