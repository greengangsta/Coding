#include<bits/stdc++.h>
using namespace std;

struct node{
    int a;
    int b;
};
bool cmp(node x,node y)
{
    if(x.a<y.a)
      return x.a<y.a;
    else if(x.a==y.a)
      return x.b<y.b;
}

int cmp2 (node x, node y)
{
    if(x.a==y.a&&x.b==y.b)
      return 1;
    return 0;
}

int binary_search(node pairs[],node x,int l,int r)
{
    if(l<r)
    {
    int mid =(l+r)/2;
    if(cmp2(x,pairs[l])||cmp2(x,pairs[r])||cmp2(x,pairs[mid]))
      return 1;
    else if(x.a<pairs[mid].a)
      binary_search(pairs,x,l,mid-1);
    else if(x.a>pairs[mid].a)
      binary_search(pairs,x,mid+1,r);
    else if(x.a==pairs[mid].a)
    {
        if(x.b<pairs[mid].b)
        binary_search(pairs,x,l,mid-1);
        else
        binary_search(pairs,x,mid+1,r);
    }
    }
    else 
     return 0;
}

int main()
{
     int t;
     cin>>t;
     while(t--)
      {
        int n,m,k;
        cin>>n>>m>>k;
        node pairs[k];
        for(int i=0;i<k;i++)
         cin>>pairs[i].a>>pairs[i].b;
        sort(pairs,pairs+k,cmp);
        int sum=0;
        for(int i=0;i<k;i++)
        {
            if(binary_search(pairs,pairs[i],0,k-1))
             sum++;
            if(binary_search(pairs,pairs[i],0,k-1))
             sum++;
            if(binary_search(pairs,pairs[i],0,k-1))
             sum++;
            if(binary_search(pairs,pairs[i],0,k-1))
             sum++;
        }
        cout<<(4*k)-sum<<endl;
      }
       
    
    
    return 0;
}