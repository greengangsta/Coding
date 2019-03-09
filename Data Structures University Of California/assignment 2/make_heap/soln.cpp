#include<bits/stdc++.h>
using namespace std;
void min_heap(int a[],int j,int n,int &count)
{
          int min =j;
          int l=2*j+1;
          int r=2*j+2;
          if(a[l] < a[j] && l<n)
               min = l;
          if(a[r]<a[j]&& r<n&&a[r]<a[l])
               min = r;
          if(min!=j)
            {
                swap(a[j],a[min]);
                   count++;
                min_heap(a,min,n,count);
            }
}

int main()
{
     
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
       cin>>a[i];
       int count=0;
     for(int j = n/2;j>=0;j--)
      min_heap(a,j,n,count);
     cout<<count<<endl;
         for(int i=0;i<count;i++)
         cout<<0<<" "<<0<<endl;
     
     
     return 0;
}