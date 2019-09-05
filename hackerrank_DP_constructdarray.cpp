#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k,x;
  cin>>n>>k>>x;
  long long int dp[n][2];
  long long int mod  = 1000000000 + 7;
  dp[0][0] = 1;
  dp[0][1] = 0;
  for(int i=1;i<n;i++)
   {
       dp[i][0] = ((((k-1)%mod)*(dp[i-1][1]%mod))%mod); 
       dp[i][1] =  ((dp[i-1][0]%mod)+  ((((k-2)%mod)*(dp[i-1][1]%mod))%mod))%mod; 
   }
    if(x==1)
   cout<<dp[n-1][0];
  else
   cout<<dp[n-1][1];
   /*
   cout<<endl;
   for(int i=0;i<n;i++)
   {
       cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
   }
  */


    return 0;
}