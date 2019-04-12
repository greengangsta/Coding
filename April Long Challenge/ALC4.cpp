#include<bits/stdc++.h>
using namespace std;


int n,x;
vector<list<int>> v(100001);
int a[100001],sum=0;
int val[100001];
int bfssum(int i)
{

    if(v[i].begin()==v[i].end())
     {
         cout<<"True : "<<i<<" ";
     // val[i]=a[i];
      auto it=v[i].begin();
      val[i] = a[i];
      return a[i];//a[*it-1];
     }
    else
    {
        int sum=0;
        int flag=0;
        for(auto it=v[i].begin();it!=v[i].end();it++)
         {
             if(flag==0)
              {
                  flag =1;
                  continue;
              }
              else
              {
              sum += bfssum(*it-1);
              }
         }
       auto it = v[i].begin();
       val[i] = sum +a[*it-1];
       cout<<"check : "<<a[*it-1]<<" ";
         return sum + a[*it-1];
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
    cin>>n>>x;
    for(int i=0;i<n;i++)
     {
         cin>>a[i];
         sum+=a[i];
     }
    for(int i=0;i<n;i++)
     v[i].push_front(i+1);
    for(int i=0;i<n-1;i++)
     {
         int x,y;
         cin>>x>>y;
         v[x-1].push_back(y);
     }
    for(int i=0;i<n;i++)
     {
         for(auto it=v[i].begin();it!=v[i].end();it++)
           cout<<*it<<" ";
           cout<<endl;
     }
  // for(int i=0;i<n;i++)
    // val[i]=bfssum(i);
    bfssum(0);
     cout<<endl;
    for(int i=0;i<n;i++)
      cout<<val[i]<<" ";
    


    }
    
    return 0;
}