#include <bits/stdc++.h> 
#define MOD 1000000007

long long int solve(int n,  int k, vector <long long > &dp){

    // if(n==0){
    //     return 0; 
    // }

    if(n==1){
        return k; 
    }

    if(n==2){
        return k + k*(k-1); 
    }

    if(dp[n] != -1){
        return dp[n]; 
    }

    else {
        return dp[n] = (k-1)*(solve(n-1,k, dp) + solve(n-2, k, dp))%MOD; 
    }

}
int numberOfWays(int n, int k) {
    // Write your code here.
    vector <long long > dp(n+1, -1); 

    return solve(n, k,  dp); 
}
