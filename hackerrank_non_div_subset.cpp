#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int rem;
    int count;
};
bool cmp(Node a, Node b)
{
    return a.count < b.count;
}

int main()
{

   int n,k;
   cin>>n>>k;
   int a[n];
   Node node[k];
   for(int i=0;i<k;i++)
    {
        node[i].rem = i;
        node[i].count = 0;
    }
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
       int j = a[i]%k;
       node[j].count += 1;
   }
   int sum = 0;
   for(int i=1;i<=k/2;i++)
    {
        if(node[i].rem*2==k)
         sum += 1;
        else
        sum += max(node[i].count,node[k-i].count);
    }
    if(node[0].count>0)
     sum += 1;
     cout<<sum<<endl;

  


    return 0;
}
