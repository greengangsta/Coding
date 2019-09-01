#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n,m;
   cin>>n>>m;
   int a[n][m] = {0};
   for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
     cin>>a[i][j];
   int sum = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
       if(a[i][j]>0)
       sum += 2;
    }
  for(int i=0;i<n;i++)
  {
      if(a[0][i]>0)
       sum += a[0][i];
      if(a[i][0]>0)
       sum += a[i][0];
      if(a[m-1][i]>0)
       sum += a[m-1][i];
      if(a[i][m-1]>0)
       sum += a[i][m-1];
  }
  for(int i=1;i<n-1;i++)
  {
      for(int j=1;j<m-1;j++)
      {
         if(a[i][j-1]>0)
         {
           sum += abs(a[i][j]-a[i][j-1]);
         }
         if(a[i][j+1]>0)
         {
           sum += abs(a[i][j]-a[i][j+1]);  
         }
         if(a[i-1][j]>0)
         {
           sum += abs(a[i][j]-a[i-1][j]);  
         }
         if(a[i+1][j-1]>0)
         {
            sum += abs(a[i][j]-a[i][j-1]); 
         }
      }
  }
  cout<<sum<<endl;



    return 0;
}