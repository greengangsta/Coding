lass Solution {
private : 
    int solve(vector<int>& prices, int index, bool buy, vector <vector<int>> &dp ){
        if(index >= prices.size()){
            return 0; 
        }

        if(dp[index][buy] != - 1){
            return dp[index][buy]; 
        }

        int ans = 0; 
        // case buy
        if(buy){
            ans = max(solve(prices, index + 1 , false, dp ) - prices[index], solve(prices, index + 1 , true, dp)); 
        }
        else{
            ans = max(solve(prices, index + 1 , true, dp) + prices[index], solve(prices, index + 1 , false, dp)); 
        }

        return dp[index][buy] =  ans; 

        // case sell
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        vector <vector<int>> dp (n+1, vector<int>(2, -1)); 
        return solve(prices, 0, true, dp); 
    }
};
