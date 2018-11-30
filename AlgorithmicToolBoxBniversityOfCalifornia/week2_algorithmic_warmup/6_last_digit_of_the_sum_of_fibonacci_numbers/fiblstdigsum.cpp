#include<bits/stdc++.h>
using namespace std;

int main()
{
   long long int n;
   cin>>n;
   int m = n%60;
   long long int a[62],sum =0;
   a[0] = 0;
   a[1] = 1;
   for(int i=2;i<61;i++)
     a[i] = a[i-1]+a[i-2];
   for(int i=0;i<61;i++)
    {
        sum+=a[i];
        if(i==m)
         cout<<sum%10<<endl;
    }
 
    
    
    return 0;
}