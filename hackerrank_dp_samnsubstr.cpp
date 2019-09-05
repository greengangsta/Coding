#include<bits/stdc++.h>
using namespace std;

int main()
{

   string s;
   cin>>s;
   long long int mod = 1000000000 + 7;
   int n = s.length();
   long long int b[n],t[n];
   b[0] = s[0]-'0';
   for(int i=1;i<n;i++)
    b[i] = (b[i-1]*10 + (s[i]-'0')%mod*(i+1)%mod)%mod;
   t[0]  = b[0];
   for(int i=1;i<n;i++)
    t[i] = (b[i]+ t[i-1])%mod;
   cout<<t[n-1];



    return 0;
}
