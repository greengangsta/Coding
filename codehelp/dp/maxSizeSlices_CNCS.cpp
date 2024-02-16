class Solution {
private : 
     int solve(vector<int> &nums, int i,   vector<vector<int>> &dp, int n, int count){

    // case include; 

    if(  i >= n || count == 0 ){
        return 0; 
    }

    if(dp[i][count] != -1){
        return dp[i][count]; 
    }

    int includeAns =  nums[i] +  solve(nums, i+2, dp, n, count - 1);  

    int excludeAns = solve(nums, i+1, dp, n, count);

    dp[i][count] =  max(includeAns,excludeAns); 

    return max(includeAns,excludeAns); 

}
public:
    int maxSizeSlices(vector<int>& slices) {

    int n = slices.size(); 

    int k =  n/3; 

    vector<vector<int>> dp(n+1 ,vector<int> (k+1, -1)); 
    vector<vector<int> > dp2(n+1 ,vector<int> (k+1, -1)); 

    int first = solve(slices, 0, dp , n-1, k ); 
    int last = solve(slices, 1, dp2 , n, k); 

    return max(first, last);
    }
};
