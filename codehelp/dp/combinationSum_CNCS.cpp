#include <bits/stdc++.h> 

int solve(vector<int> &num, int tar, int n,  vector<int> &dp){

    if(tar < 0){
        return 0; 
    }

    else if(tar == 0){
        return 1; 
    }

    if(dp[tar] != -1){
        return dp[tar]; 
    }

    // case include current 
    int ans = 0; 
    for(int i=0;i<n;i++){
          ans +=  solve(num, tar - num[i], n, dp); 
         
        
    }

    return dp[tar] = ans; 


}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    vector<int> dp(tar + 1, -1); 
    return solve(num, tar, num.size(), dp ); 
}
