#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k,x;
  cin>>n>>k>>x;
  long long int dp[n][k];
  long long int mod  = 10e9 + 7;
  dp[0][0] = 1;
  for(int j = 1;j<n;j++)
   dp[0][j] = 0;
  for(int i=1;i<n;i++)
   {
       dp[i][0] = ((((k-1)%mod)*(dp[i-1][1]%mod))%mod); 
       dp[i][1] =  dp[i-1][0] +  ((((k-2)%mod)*(dp[i-1][1]%mod))%mod); 
   }
  if(x==1)
   cout<<dp[n-1][0];
  else
   cout<<dp[n-1][1];





    return 0;
}