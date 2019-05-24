#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,m;
       cin>>m;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++)
        cin>>a[i];
       int flag=0;
       for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)
           {
               if(a[i]+a[j]==m)
                {
                    cout<<i+1<<" "<<j+1<<endl;
                    flag=1;
                    break;
                }
           }
           if(flag==1)
            break;
       }
    
   }


    return 0;
}