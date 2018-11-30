#include<bits/stdc++.h>
using namespace std;

int main()
{
   long long int m,n,d,dm;
   cin>>m>>n;
   d = (n-m)%60;
   dm = m%60;
   long long int a[62],sum =0,b[62];
   a[0] = 0;
   a[1] = 1;
   for(int i=2;i<61;i++)
    {
        a[i] = a[i-1]+a[i-2];
        
    }
    for(int i=0;i<61;i++)
     b[i] = a[i]%10;
    sum =b[dm]%10;
  for(int i =dm+1;i<=dm+d;i++)
     {
         if(i>=60)
           i =0;
         sum += b[i]%10;
         
     }
    cout<<sum%10<<endl;

    
    return 0;
}