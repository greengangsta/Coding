#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++)
      cin>>a[i];
      int m,h=0;
      for(int i=0;i<n;i++)
      {
         int p=a[i];
         m=0;
        while(p!=-1)  
          {
              m++;
              p=a[p];
          }
          h=max(m,h);
      }
     cout<<h+1<<endl;
    
     
    

    
    }
    return 0;
}