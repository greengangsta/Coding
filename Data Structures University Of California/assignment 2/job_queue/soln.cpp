#include<bits/stdc++.h>
using namespace std;

struct node
{
    long long int p;
    long long int k;
};
void min_heap( node pr[], long long int  j, long long int n)
{
           long long int  min =j;
           long long int  l=2*j+1;
           long long int  r=2*j+2;
          if(l<n && pr[l].k < pr[j].k)
               min = l;
          if(l<n && pr[l].k <= pr[j].k &&pr[l].p < pr[j].p)
               min = l;
          if(r<n&& pr[r].k<pr[j].k&&pr[r].k<pr[l].k)
               min = r;
          if(r<n&& pr[r].k<pr[j].k&&pr[r].k<pr[l].k&&pr[r].p < pr[j].p)
               min = r;
          if(min!=j)
            {
                 swap(pr[j],pr[min]);
                 min_heap(pr,min,n);
            }
}

void siftup(node pr[],long long int j,long long int n)
{
    while(pr[j/2].k<pr[j].k||(pr[j/2].k==pr[j].k&&pr[j/2].p<pr[j].p))
    {
        swap(pr[j/2],pr[j]);
    }
}
node extract_min(node pr[],long long int n)
{
    long long int i=n-1;
    node a = pr[0];
    swap(pr[i],pr[0]);
    min_heap(pr,0, n);
    n = n-1;
    return a;
}

void insert(node pr[],long long int n,node a)
{
  pr[n-1] = a;
  siftup(pr,n-1,n);
}
int main()
{
     
    long long int n,m;
    cin>>n>>m;
    long long int x[m];
    node pr[n];
    for(long long int i=0;i<m;i++)
      cin>>x[i];
       for(long long int i=0;i<n;i++)
     {
         cout<<i<<" ";
         cout<<0;
         cout<<endl;
     }
    for(long long int i=0;i<n;i++)
     {
         pr[i].p=i;
         pr[i].k=x[i];
     }
     for( long long int  j = n/2;j>=0;j--)
       min_heap(pr,j,n);
     for(long long int i=n;i<m;i++)
      {
          node a,b;
           a = extract_min(pr, n);
           b.p = a.p;
           b.k = a.k + x[i];
          insert(pr,n,b);
          cout<<a.p<<" ";
          cout<<a.k<<endl;
      }
     
    
    
     
     
     return 0;
}