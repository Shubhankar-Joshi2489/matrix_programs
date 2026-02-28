#include<iostream>
#include <vector>
using namespace std;
int main()
{   int i,j,n;
    int temp;
    cout<<"enter no of elemnts";
    cin>>n;
    vector <int> a(n);
     for(i=0;i<n;i++)
    {  cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<"Maximum ="<<a[n-1]<<endl;
    cout<<"second Maximum ="<<a[n-2]<<endl;
    cout<<"minimum ="<<a[0]<<endl;
    cout<<"second minimum ="<<a[1]<<endl;
}

    
    