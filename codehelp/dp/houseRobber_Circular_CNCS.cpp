#include <bits/stdc++.h> 

long long int solve(vector<int> &nums, int i,  vector<long long> &dp, int n){

    // case include; 

    if(i >= n){
        return 0; 
    }

    if(dp[i] != -1){
        return dp[i]; 
    }

    long long int includeAns =  nums[i] +  solve(nums, i+2, dp, n );  

    // case exclude = 

    long long int excludeAns = solve(nums, i+1, dp, n);

    dp[i] =  max(includeAns,excludeAns); 


    return max(includeAns,excludeAns); 

}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.

    int sum = 0; 
    
    int n = valueInHouse.size(); 
    int first = valueInHouse[0]; 
    int last = valueInHouse[1];

    if(n==1){
        return valueInHouse[0]; 
    }

    vector<long long> dp(n +1 , -1); 
    vector<long long > dp2(n +2 , -1); 

    return max(solve(valueInHouse, 0, dp , n-1), solve(valueInHouse, 1, dp2 , n));
}
