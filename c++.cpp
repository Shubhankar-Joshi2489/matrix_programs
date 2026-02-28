#include<bits/stdc++.h>
using namespace std;
int main()
{
/*vector<pair <int,int>> v;
v.emplace_back(1,2);
cout<<v[0].second;
v.emplace_back(3,4);
cout<<v[1].second;
return 0;*/
vector <int> v={10,20,30,40,50};
for(vector<int>::iterator it=v.begin();it!=v.end()+1;it++)
{
    cout<<*it<<" "<<"\n";
}
for(auto it=v.rend();it!=v.rbegin()-1;it--)
{
    cout<<*it<<" ";
}

}
