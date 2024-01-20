class Solution {

private : 

void solve(vector<int>& nums, int i, vector<int> temp, vector<vector<int>> &ans) {
 
   if(i >= nums.size()) {
       ans.push_back(temp);
       return; 
   }

   // exclude 
   
   solve(nums, i+1 , temp, ans); 

   temp.push_back(nums[i]); 

   // include 
    solve(nums, i+1, temp, ans); 

}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> temp; 
        solve(nums, 0,temp,ans); 
        return ans; 
    }
};
