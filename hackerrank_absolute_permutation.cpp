#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       int a[n+1];    
       int flag = 0;
       for(int i=1;i<=n;i++)
       {
         a[i] = i;
       }
       if(k!=0 && n%(2*k)==0)
       for(int i=0;i<=n;i+=2*k)
       {
         if(i+2*k<=n)
          for(int j=i+1;j<=i+k;j++)
          {
              int temp = a[j];
              a[j] = a[j+k];
              a[j+k] = temp;
          }
       }
       else if(k!=0 && n%(2*k)!=0)
        flag = 1;
       for(int i=1;i<=n;i++)
         if(abs(a[i]-i) != k)
          {
              flag = 1;
              break;
          }
    
       if(flag==1)
        cout<<-1;
       else
       {
       for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
       }
       
       cout<<endl;
    
   }






    return 0;
}
