class Solution {
private : 
    int solve(vector<int>& satisfaction, int i, int time, int n,  vector<vector<int>> &dp){
            if( i >= n){
                return 0; 
            }

            if(dp[i][time]!=-1){
                return dp[i][time]; 
            }

            // case include 
            int includeAns = satisfaction[i] * time + solve(satisfaction, i+1, time + 1, n, dp); 

            // case exclude 

            int excludeAns = solve(satisfaction, i+1, time , n, dp); 

            return dp[i][time] = max(includeAns, excludeAns); 
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(), satisfaction.end()); 
        int n = satisfaction.size(); 
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1)); 
        return solve(satisfaction, 0, 1, n, dp); 
        
    }
};
