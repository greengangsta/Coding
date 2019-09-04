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
       sort(a,a+n);
       int m = a[0];
       int m1 = INT_MAX;
       for(int i=m;i>=m-5;i--)
       {
           int b[n];
           for(int j=0;j<n;j++)
            b[j] = a[j] - i;
            int ops = 0;
           for(int j = 0;j<n;j++)
           {
             ops += b[j]/5;
             ops += (b[j]%5)/2;
             ops += ((b[j]%5)%2)/1;
           }
           if(ops<m1)
            m1 = ops;
       }
     cout<<m1<<endl;
       
       
   }





    return 0;
}
