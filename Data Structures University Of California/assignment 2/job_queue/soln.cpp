#include<bits/stdc++.h>
using namespace std;

struct node
{
    int p;
    int k;
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
node extract_min(node pr[])
{
    
}

void insert(node pr[])
{
    
}
int main()
{
     
    int n,m;
    cin>>n>>m;
    int a[m];
    node pr[n];
    for(int i=0;i<m;i++)
      cin>>a[i];
    for(int i=0;i<n;i++)
     {
         pr[i].p=i;
         pr[i].k=0;
     }
     for(int i=0;i<n;i++)
     {
         cout<<pr[i].p<<" ";
         cout<<pr[i].k;
         cout<<endl;
     }
     for( long long int  j = n/2;j>=0;j--)
       min_heap(pr,j,n);
     
     
    
    
     
     
     return 0;
}