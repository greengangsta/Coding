class Solution{
private : 
    int solve(int n, int arr[], int target, int sum, int index, vector<vector<int>> &dp){
      
        if(index >= n){
            return 0; 
        }
        
        if(sum > target){
            return 0; 
        }
        
         
        if(sum == target){
            return 1; 
        }
        
        if(dp[index][sum]!= -1){
            return dp[index][sum]; 
        }
        
        // case include 
        
        int includeAns = 0;
        int excludeAns = 0; 
        
        includeAns = solve(n, arr, target, sum + arr[index], index + 1, dp);
        
        // case exclude 
        
        excludeAns = solve(n, arr, target, sum, index + 1, dp);
        
        return dp[index][sum] =  includeAns || excludeAns; 
        
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int target = 0;
        for(int i=0;i<N;i++){
            target += arr[i]; 
        }
        
        if(target%2!=0){
            return 0; 
        }
        
        target = target/2; 
        
        vector<vector<int>> dp(N+1, vector<int> (target + 1, -1)); 
        
        int ans = solve(N, arr, target, 0, 0, dp);
        
        // cout<<ans; 
        
        return ans; 
    }
};
