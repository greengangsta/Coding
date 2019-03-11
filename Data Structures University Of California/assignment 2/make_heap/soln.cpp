#include<bits/stdc++.h>
using namespace std;
void min_heap(int a[],int j,int n,int &count,int pairs [][2],int &k)
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
                 pairs[k][0] = j;
                 pairs[k][1] = min;
                 k++;
                 swap(a[j],a[min]);
                 count++;
                 min_heap(a,min,n,count,pairs,k);
            }
}

int main()
{
     
     int n;
     cin>>n;
     int a[n],k=0;
     int pairs[4*n][2];
     for(int i=0;i<n;i++)
       cin>>a[i];
       int count=0;
     for(int j = n/2;j>=0;j--)
      min_heap(a,j,n,count,pairs,k);
     cout<<count<<endl;
         for(int i=0;i<count;i++)
         cout<<pairs[i][0]<<" "<<pairs[i][1]<<endl;
     
     
     return 0;
}