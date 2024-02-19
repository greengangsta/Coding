class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0]; 
        int n = prices.size(); 
        int p = 0; 
        for(int i=1;i<n;i++){
            int d = prices[i] - mini; 
            p = max(p, d); 
            mini = min(mini, prices[i]); 
        }

        return p; 
    }
};
