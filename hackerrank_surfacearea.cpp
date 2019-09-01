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
       sum += 2;#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h,w,b[101][101]={0},z=0,y;
    cin>>h>>w;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>b[i][j];
        }
    }
    for(int j=0;j<h;j++)
    {
        for(int i=1;i<w+1;i++)
    {
        y=b[j][i]-b[j][i-1];
        if(y<0)
        {
            y=-y;
        }
        z+=y;
    }
    }
    for(int i=1;i<h+1;i++)
    {
        for(int j=0;j<w;j++)
        {
            y=b[i][j]-b[i-1][j];
            if(y<0)
            {
                y=-y;
            }
            z+=y;
        }
    }
    z+=2*(h*w);
    for(int j=0;j<w;j++)
    {
        z+=b[0][j];
    }
    for(int i=0;i<h;i++)
    {
        z+=b[i][0];
    }
    cout<<z;

}
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