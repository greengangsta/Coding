#include<bits/stdc++.h>
using namespace std;

struct node
{
    int a;
    int b;
};

bool cmp(node x, node y)
{
  if (x.b == y.b)
    return x.a < y.a;
  else
    return x.b < y.b;
}

int main()
{
    int n;
    cin>>n;
    node cus[n];
    for(int i=0;i<n;i++)
     {
         int x,y;
         cin>>x>>y;
         cus[i].a=i+1;
         cus[i].b = x+y;
     }
     sort(cus,cus+n,cmp);
     for(int i=0;i<n;i++)
      cout<<cus[i].a<<" ";
    return 0;
}