class Solution{
    private : 
    int solve(int n,  vector <int> &dp){
        if(n==0){
            return 0; 
        }
        if(n==1){
            return 1; 
        }
        else if (n< 0){
            return INT_MAX; 
        }
        
        if(dp[n]!= -1){
            return dp[n]; 
        }
        int mini = INT_MAX; 
        for(int i=1;i*i<= n; i++){
            int ans = solve(n - i*i, dp);
            if(ans != INT_MAX){
                mini = min(ans+ 1, mini); 
            }
        }
        
        return dp[n] = mini; 
    }
	public:
	int MinSquares(int n)
	{
	    // Code here
	    
	    vector <int> dp(n+1, -1); 
	    
	    return solve(n, dp); 
	}
};
