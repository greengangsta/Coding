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
       int left[n],right[n];
       left[0]=a[0];
       right[n-1]=a[n-1];
       for(int i=1;i<n;i++)
        left[i] = left[i-1]+a[i];
       for(int i=n-2;i>=0;i--)
        right[i] = a[i]+right[i+1];
       int flag=0;
       for(int i=0;i<n;i++)
        if(left[i]==right[i])
         flag=1;

       if(flag==1||n==1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
   }



    return 0;
}