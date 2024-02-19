class Solution {
private : 
     int solve(vector<int>& arr, int d, int i){
        if(i <0 ){
            return 0; 
        }

        int ans = 0; 


        for(int j=i-1;j>=0;j--){
            if(arr[i] - arr[j] == d){
                ans = max(ans, 1 + solve(arr, d, j));
            }
        }

        // cout<<"returning ans -> "<<ans; 

        return ans; 

}
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n =arr.size();
        int ans = 0;  
        unordered_map <int, int> dp; 
        for(int i=0;i<n;i++){
            int temp = arr[i] - difference; 
            int tempAns = 0; 
            if(dp.count(temp)){
                tempAns = dp[temp]; 
            }

            dp[arr[i]] = tempAns + 1; 
            ans = max(ans, dp[arr[i]] ); 

        }
        return ans; 
    }
};
