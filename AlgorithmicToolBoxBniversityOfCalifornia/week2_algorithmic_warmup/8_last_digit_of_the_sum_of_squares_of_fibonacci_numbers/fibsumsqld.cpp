#include<bits/stdc++.h>
using namespace std;

int main()
{
   long long int n;
   cin>>n;
   long long int a[62],sum =0,b[62];
   a[0] = 0;
   a[1] = 1;
   for(int i=2;i<61;i++)
    {
        a[i] = a[i-1]+a[i-2];
    }
  for(int i=0;i<62;i++)
    {
        sum += a[i]%10*a[i]%10;
       // cout<<sum%10<<" ";
        b[i] = sum%10;
       
    }
    int d = n%60;
    cout<<b[d]<<endl;

    return 0;
}