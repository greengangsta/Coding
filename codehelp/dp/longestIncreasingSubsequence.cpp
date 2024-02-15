class Solution
{
    
    private : 
    
    int solve(int n, int *a, int i, int last,  vector<vector <int> > &dp){
        
        if(i>= n){
            return 0; 
        }
        
        
        // include current 
        
        if(dp[i][last+1] != -1){
            return dp[i][last+1]; 
        }
        
        int includeAns = INT_MIN; 
        int excludeAns = INT_MIN; 
        
        if(last == -1 ||  a[i] > a[last]){
            // cout<<"included->"<<a[i]<<" ";
            includeAns = 1 + solve(n, a, i+1, i, dp); 
            
        }

        // exclude current
        
        // cout<<"excluded->"<<a[i]<<" ";
        
         excludeAns = solve(n, a, i+1, last, dp); 
         
        
         return dp[i][last+ 1] = max(includeAns, excludeAns); 
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
    //   vector<vector <int> > dp(n+1, vector<int>(n+1, -1)); 
    //   return solve(n, a, 0, -1, dp) ; 
    
    vector<int> ans;
        ans.push_back(a[0]);
        for(int i=1;i<n;i++) {
            if(a[i] > ans.back()) {
                ans.push_back(a[i]);
            }
            else {
                int idx = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
                ans[idx] = a[i];
            }
        }
        
        return ans.size();
    }
};
