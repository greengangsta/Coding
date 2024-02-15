class Solution {

private : 
    int solve(vector<int>& values, int i, int j, vector<vector<int>> &dp){

        if( i== j -1){
            return 0; 
        }

        if(dp[i][j]!=-1){
            return dp[i][j]; 
        }
        int ans = INT_MAX;  
        for( int k = i+1; k < j;k++){
            ans = min(ans, values[i]*values[j]*values[k] + solve(values, i, k, dp)  + solve(values, k, j, dp)); 

        }

    
        return dp[i][j] = ans; 

    }
public:


    int minScoreTriangulation(vector<int>& values) {
        int n = values.size(); 
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1)); 
        int mini = INT_MAX; 
        return solve(values, 0, n-1, dp); 
    }
};
