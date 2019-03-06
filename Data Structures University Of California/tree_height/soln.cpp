#include<bits/stdc++.h>
using namespace std;
long long int a[100001];
int main()
{
  
      int n;
      cin>>n;
      for(long long int i=0;i<n;i++)
      cin>>a[i];
      long long int m,h=0;
      for(long long int i=0;i<n;i++)
      {
         long long int p=i;
         m=1;
        while(a[p]!=-1)  
          {
              m++;
              p=a[p];
          }
          h=max(m,h);
      }
     cout<<h<<endl;
    
     
    

    
   
    return 0;
}