class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped,  vector<vector<int>> &dp){

            if(index >= nums1.size()){
                return 0; 
            }

           int prev1 = nums1[index-1]; 
           int prev2 =  nums2[index-1]; 

           if(dp[index][swapped] != -1){
               return dp[index][swapped]; 
           }

            int ans = INT_MAX; 

            if(swapped){
                swap(prev1, prev2); 
            }
    
           // no swap case ==>> agar pahle se increasing order hai to bina swap kiye kaam chal sakta hai 
           // meaning ki no swap ki call aap tabhi kar sakte ho jab pahle se increasing order ho
           
            if(nums1[index] > prev1 && nums2[index] > prev2){
                ans = solve(nums1, nums2, index+1, 0, dp); 
            }

          // swap case ==>> swap karne se pahle ye check karna hai ki swapping ke baad increasing order rahega ki nahi 
          // IMP_NOTE ==> agar increasing order pahle se hai to bhi ye function call hogi kyuki ye if statement sirf ye 
          // check karta hai ki swap karne ke baad increasing order rahegi ya nahi. 

            if(nums1[index] > prev2 && nums2[index] > prev1){
                ans = min (ans, 1+ solve(nums1, nums2, index+1, 1, dp)); 
            }

           return dp[index][swapped] = ans; 

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1); 
        nums2.insert(nums2.begin(), -1); 
        vector<vector<int>> dp(nums1.size()+1, vector<int> (2, -1)); 
        return solve(nums1, nums2, 1, 0, dp); 
    }
};
