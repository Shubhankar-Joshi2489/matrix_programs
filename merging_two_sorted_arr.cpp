
#include <bits/stdc++.h>
using namespace std;

int main ()
{
   vector <int> a1={1,4,5};
   vector <int> a2={1,2,3,4};
   vector <int> a3;
   int n1=2;
   int n2=3;
   int i=0;
   int j=0;
   while(i<=n1 && j<=n2)
   {
      /*if(a1[i]==a2[j])
      {
        a3.push_back(a1[i]);
        a3.push_back(a2[j]);
        i++;
        j++;

      }*/
      if(a1[i]>a2[j])
      {
        a3.push_back(a2[j]);
        j++;
      }
    else{
        a3.push_back(a1[i]);
        i++;

    } 


   }
   while(i < a1.size()) a3.push_back(a1[i++]);
   while(j < a2.size()) a3.push_back(a2[j++]);
   for (i=0;i<7;i++)
   {
    cout<<a3[i];
   }




}