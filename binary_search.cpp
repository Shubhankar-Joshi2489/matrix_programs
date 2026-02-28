#include<iostream>
#include<vector>
using namespace std;
void bin_search(vector <int> &a,int x,int &l,int &r)
{   
    if(l>r)
  {
    cout<<"element not found";
    return ;
}  int m=(l+r)/2;
    if(x==a[m])
    {
        cout<<"Element found";
        return ;
    }
    else if(x>a[m])
    {
        l=m+1;
        bin_search(a,x,l,r);
    }
    else{
       r=m-1;
       bin_search(a,x,l,r);
    }   
        
    }

int main()
{   int i,n,x;
    cout<<"Enter no of elemnts in your array";
    cin>>n;
    vector <int> a(n);
    for (i=0;i<n;i++)
    {
      cin>>a[i];
    }
    cout<<"Enter element to be searched";
    cin>>x;
    int l=0;
    int r=n-1;
    /*
    while(l<=r)
    {
      int mid=(l+r)/2;
      if(x==a[mid]) cout<<"Element found at index "<<mid;
      else if(x>a[mid])  l=mid+1;
      else  r=mid-1;
    }

    */
   bin_search(a,x,l,r);
   

    return 0;

}