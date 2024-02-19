class Solution {
private : 
     int solve(vector<int>& prices, int index, bool buy, int count,  vector <vector<vector<int>>> &dp ){
        if(index >= prices.size() || count ==0){
            return 0; 
        }

        if(dp[index][buy][count] != - 1){
            return dp[index][buy][count]; 
        }

        int ans = 0; 
        // case buy
        if(buy){
            ans = max(solve(prices, index + 1 , false, count, dp ) - prices[index], solve(prices, index + 1 , true, count, dp )); 
        }
        else{
            ans = max(solve(prices, index + 1 , true, count - 1, dp ) + prices[index], solve(prices, index + 1 , false, count, dp )); 
        }

        return dp[index][buy][count] = ans; 
        // return dp[index][buy] =  ans; 
     }

public:
    int maxProfit(int k, vector<int>& prices) {
          int n = prices.size(); 
        vector <vector<vector<int>>> dp (n+1, vector<vector<int>>(2, vector<int>(k+1, -1))); 
        return solve(prices, 0, true, k, dp ); 
    }
};
