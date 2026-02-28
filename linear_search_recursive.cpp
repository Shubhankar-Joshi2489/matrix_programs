#include<iostream>
#include<vector>
using namespace std;
void lin_search(vector <int> &a,int x,int ind)
{   if(ind==a.size())
    {
        cout<<"element not found";
        return ;
    }
    if(x==a[ind])
    {
        cout<<"Element found at ="<<ind<<" index";
        return ;
    }
    else{
        
        lin_search(a,x,ind+1);
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
    /*  Iterative Linear_search
for (i=0;i<n;i++)
    {
      if(x==a[i])
      { cout<<"Element found at ="<<ind<<" index";
       return;
      }
    }
*/
    lin_search(a,x,0);
    return 0;

}
