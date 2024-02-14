class Solution{
private : 

    int solve(int n, int m, int i, int j, vector<vector<int>> mat, int &maxi, vector<vector<int>> &dp){
        
        if(i >= n || j >= m ){
            return 0; 
        }
        
      
        if(dp[i][j] != -1){
            return dp[i][j]; 
        }
        
        int rightAns =  solve(n, m, i, j + 1, mat, maxi, dp); 
        int downAns =  solve(n, m, i+1, j , mat, maxi, dp); 
        int diagAns =  solve(n, m, i+1, j + 1, mat, maxi, dp); 
        
        if(mat[i][j] == 1){
            int ans = 1 + min(rightAns, min(downAns, diagAns)); 
            maxi = max(ans, maxi); 
            return dp[i][j] = ans; 
        }
        else {
            return 0; 
        }

    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi = 0; 
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1)); 
        solve(n, m, 0, 0, mat, maxi, dp); 

        
        return maxi; 
    }
};
