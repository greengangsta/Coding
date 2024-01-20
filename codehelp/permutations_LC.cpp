class Solution {

private : 
    void solve(vector<int> &nums, int index, vector<int> output, vector<vector<int>> &ans ) {

        if(index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        for(int i=index;i<nums.size();i++){
            output.push_back(nums[i]);
            swap(nums[i], nums[index]); 
            solve(nums, index+1, output, ans);
            swap(nums[i], nums[index]); 
            output.pop_back();

        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector <int> output; 
        solve(nums, 0, output, ans);

        return ans;
    }
};
