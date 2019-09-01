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
   Node node[100];
   for(int i=0;i<100;i++)
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
   sort(node, node + 100,cmp);
   int sum = node[99].count;
   unordered_set<int> s1;
   s1.insert(node[99].rem);
   for(int i=98;i>=0;i--)
    {
        int x = node[i].rem;
        int flag = 0;
        for(auto it = s1.begin();it!=s1.end();it++)
        {
          int y = *it;
          if(x+y==k)
          {
              flag = 1;
              break;
          }
          else if(x==0 and y==0)
          {
              flag = 1;
              break;
          }
        }
        if(flag==0)
        {
         sum += node[i].count;
         s1.insert(node[i].rem);
        }
       }
     cout<<sum<<endl;

  


    return 0;
}
