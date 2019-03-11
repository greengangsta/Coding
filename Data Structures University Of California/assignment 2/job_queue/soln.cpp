#include<bits/stdc++.h>
using namespace std;

struct node
{
    long long int p;
    long long int k;
};

node min1(node a,node b)
{
    if(a.k<b.k)
     return a;
    else if(a.k==b.k && a.p<b.p)
     return a;
    else
     return b;
}
void min_heap( node pr[], long long int  j, long long int n)
{
           long long int  min =j;
           long long int  l=2*j+1;
           long long int  r=2*j+2;
           node m1,m2,m3;
           if(l<n)
           m1 = pr[l];
           if(r<n)
           m2 =pr[r];
           m3 = min1(m1,min1(m2,pr[j]));
           if(m3.p==m1.p)
           min = l;
           else if(m3.p==m2.p)
           min=r;
           
           /*
          if(l<n && pr[l].k < pr[j].k)
               min = l;
          if(l<n && pr[l].k == pr[j].k && pr[l].p < pr[j].p)
               min = l;
          if(r<n&& pr[r].k<pr[j].k&&pr[r].k<pr[l].k)
               min = r;
          if(r<n&&pr[r].k<pr[l].k&&pr[r].k==pr[j].k&&pr[r].p<pr[j].p)
               min = r;
                 */
          if(min!=j)
            {
                 swap(pr[j],pr[min]);
                 min_heap(pr,min,n);
            }
          
}

void siftup(node pr[],long long int j,long long int n)
{
    while(pr[j].k<pr[(j-1)/2].k||(pr[j].k==pr[(j-1)/2].k&&pr[j].p<pr[(j-1)/2].p))
    {
        swap(pr[(j-1)/2],pr[j]);
    }
}
node extract_min(node pr[],long long int n)
{
    long long int i=n-1;
    node a = pr[0];
    swap(pr[i],pr[0]);
    min_heap(pr,0, n-1);
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
     for(long long int  j = n/2;j>=0;j--)
       min_heap(pr,j,n);
     for(long long int i=n;i<m;i++)
      {
          node a,b;
           a = extract_min(pr, n);
           b.p = a.p;
           b.k = a.k+x[i] ;
          insert(pr,n,b);
          cout<<a.p<<" ";
          cout<<a.k<<endl;
      }

     
     
     return 0;
}