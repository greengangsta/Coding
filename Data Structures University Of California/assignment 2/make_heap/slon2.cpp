#include<bits/stdc++.h>
using namespace std;
void min_heap( long long int  a[], long long int  j, long long int  n, long long int  &count)
{
           long long int  min =j;
           long long int  l=2*j+1;
           long long int  r=2*j+2;
          if(l<n && a[l] < a[j])
               min = l;
          if(r<n&& a[r]<a[j]&&a[r]<a[l])
               min = r;
          if(min!=j)
            {
                 swap(a[j],a[min]);
                 count++;
                 min_heap(a,min,n,count);
            }
}
void min_heap1( long long int  a[], long long int  j, long long int  n)
{
           long long int  min =j;
           long long int  l=2*j+1;
           long long int  r=2*j+2;
          if( l<n && a[l] < a[j])
               min = l;
          if( r<n&& a[r]<a[j]&&a[r]<a[l])
               min = r;
          if(min!=j)
            {
                cout<<j<<" "<<min<<endl;
                 swap(a[j],a[min]);
                 min_heap1(a,min,n);
            }
}

int main()
{
     
      long long int  n;
     cin>>n;
      long long int  a[n],b[n],k=0;
     for( long long int  i=0;i<n;i++)
      {  
           long long int  p;
          cin>>p;
          a[i]=p;
          b[i]=p;
      }
        long long int  count=0;
     for( long long int  j = n/2;j>=0;j--)
      min_heap(a,j,n,count);
     cout<<count<<endl;
     for( long long int  j = n/2;j>=0;j--)
      min_heap1(b,j,n);
     
     
     return 0;
}