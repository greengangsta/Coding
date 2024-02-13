#include <bits/stdc++.h> 

int solve(vector<int> &nums, int i,  vector<int> &dp){

    // case include; 

    if(i >=nums.size()){
        return 0; 
    }

    if(dp[i] != -1){
        return dp[i]; 
    }

    int includeAns =  nums[i] +  solve(nums, i+2, dp ); ; 

    // case exclude = 

    int excludeAns = solve(nums, i+1, dp);

    dp[i] =  max(includeAns,excludeAns); 


    return max(includeAns,excludeAns); 

}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int sum = 0; 
    vector<int> dp(nums.size() + 1, -1); 
    return solve(nums, 0, dp ); 
}
