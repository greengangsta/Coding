#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int a[i],sum=0;
    for(int i=0;i<n;i++)
     {
         cin>>a[i];
         sum+=a[i];
     }
     vector<list<int>> vec;
    for(int i=0;i<n;i++)
     {
         int x,y;
         cin>>x>>y;
         vec[x-1].push_front(y);
     }
    
    
    
    return 0;
}