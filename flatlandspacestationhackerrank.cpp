#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n]={0};
    for(int i=0;i<m;i++)
     {
         int y;
         cin>>y;
         a[y] =1; 
     }
    int left[n],right[n];
    int curr=100000;
    for(int i=0;i<n;i++)
     {
         if(a[i]==1)
         {
          left[i] = 0;
          curr=0;
         }
         else
         {
            left[i] = curr+1;
            curr++;
         }
     }
     curr = 100000;
     for (int i = n-1; i >=0; i--) 
     {
       if (a[i] == 1)
        {
         right[i] = 0;
         curr = 0;
        } 
       else
        {
         right[i] = curr+1;
         curr++;
        }
    
     }
     int c[n];
     for (int i = 0; i < n; i++)
       c[i] = min(left[i],right[i]);
     sort(c,c+n);
     cout<<c[n-1]<<endl;

     return 0;
}