class Solution {
private: 
    int solve(int i, vector<int> &dp, vector<int>& cost, int &totalCost){

    if(dp[i] != -1){
        return dp[i]; 
    }

    else {
        totalCost = min( cost[i-1] + solve(i-1,dp, cost, totalCost), cost[i-2] + solve(i-2, dp, cost, totalCost)); 
        dp[i] = totalCost; 
        return dp[i]; 
    }


}
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ; 
        int totalCost = 0; 
        vector<int> dp(n +1, -1); 
            dp[0] = 0; 
            dp[1] = 0; 
            solve(n, dp, cost, totalCost); 
            return dp[n]; 
    }
};
