#include <bits/stdc++.h>
#define MOD 1000000007
int solve(int n, int i, vector<int> &dp){

    if(dp[i] != -1){
        return dp[i]; 
    }

    else {

        dp[i] = (solve(n, i-1, dp) + solve(n, i-2, dp))%MOD; 
        return dp[i]; 
    }


}
int countDistinctWays(int nStairs) {
    //  Write your code here.

    vector<int> dp(nStairs+1, -1); 
    dp[1] = 1; 
    dp[0] = 1; 
    solve(nStairs, nStairs, dp ); 
    return dp[nStairs]; 
}
