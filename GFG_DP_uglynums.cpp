#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   long long int ugly[n];
   int i2 = 0,i3 = 0,i5 = 0;
   ugly[0]  = 1;
   long long int n2 = ugly[i2]*2;
   long long int n3 = ugly[i3]*3;
   long long int n5 = ugly[i5]*5;
   for(int i=1;i<n;i++)
   {
       ugly[i] = min(min(n3,n5),n2);
       if(ugly[i]==n2)
       {
          i2+= 1;
          n2 = ugly[i2]*2;
       }
       if(ugly[i]==n3)
       {
           i3 += 1;
           n3 = ugly[i3]*3;
       }
       if(ugly[i]==n5)
       {
           i5 += 1;
           n5 = ugly[i5]*5;
       }
   }
   cout<<ugly[n-1]<<endl;
    
    
    return 0;
}