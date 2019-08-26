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
       int max = 0;
       for(int i=1;i<=n-1;i++)
        for(int j = i+1;j<=n;j++)
        {
            int temp = i&j;
            if( temp > max && temp < k)
             max = temp;
        }
      cout<<max<<endl;

   }





    return 0;
}