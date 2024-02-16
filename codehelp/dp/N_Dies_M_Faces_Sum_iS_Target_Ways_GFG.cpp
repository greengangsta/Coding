
class Solution {
    
  private: 
    long long solve(int m, int n, int x,  vector<vector<long long>> &dp){
        
        if(x==0 && n==0){
            return 1; 
        }
        
         if(n==0){
            return 0; 
        }
        
        if(x < 0){
            return 0; 
        }
        
        if(dp[n][x] != -1){
            return dp[n][x]; 
        }
        
        long long ans = 0; 
        for(int j=1;j<=m;j++){
            ans += solve(m, n-1, x-j, dp); 
        }
        
        return dp[n][x] = ans; 
        
        
    }
  public:
    long long noOfWays(int M , int N , int X) {
        // code here
        
        long long count = 0; 
        vector<vector<long long>> dp(N+1, vector<long long> (X+1, -1)); 
        
        return solve(M, N, X, dp); 
        
        // return count; 
    }
};

