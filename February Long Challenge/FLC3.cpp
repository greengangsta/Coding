#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       int a[n],d[n];
       for(int i=0;i<n;i++)
         cin>>a[i];
       for(int j=0;j<n;j++)
         cin>>d[j];
       int ans[n];
       for(int i=0;i<n;i++)
        {
            if(i==0&&d[i]>a[n-1]+a[1])
             ans[i]=d[i];
            else if(i==n-1&&d[i]>a[1]+a[n-2])
              ans[i]=d[i];
            else if(i!=0&&i!=n-1&&d[i]>a[i+1]+a[i-1])
              ans[i]=d[i];
            else
              ans[i]=-1;
        }
       sort(ans,ans+n);
       cout<<ans[n-1]<<endl;
       for(int i=0;i<n;i++)
         cout<<ans[i]<<" ";
    
     cout<<endl;
    }
}
