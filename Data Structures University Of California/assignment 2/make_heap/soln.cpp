#include<bits/stdc++.h>
using namespace std;
int count=0;
void min_heap(int a[],int j,int n)
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
                min_heap(a,min,n);
            }
}

int main()
{
     
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
       cin>>a[i];
     for(int j = n/2;j>0;j--)
       min_heap(a,j,n);
     cout<<count<<endl;
     
     
     return 0;
}