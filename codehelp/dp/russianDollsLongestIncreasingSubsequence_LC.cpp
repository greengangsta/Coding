 bool comparator(vector<int> &a, vector<int> &b){ 
       if(a[0]== b[0]){
           return a[1] > b[1]; 
       }
        return a[0] < b[0]; 
     } 

class Solution {
   
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(), comparator); 
         vector<int> sortedHeights; 
        for(int i=0;i<envelopes.size();i++){
            // cout<<envelopes[i][0]<<" "<<envelopes[i][1]<<endl;
            sortedHeights.push_back(envelopes[i][1]); 
        }
       
        vector<int> ans; 
        ans.push_back(sortedHeights[0]); 
        for(int i=1;i<sortedHeights.size();i++){
            if(sortedHeights[i] > ans.back()){
                ans.push_back(sortedHeights[i]);
            }
            else {
                int idx = lower_bound(ans.begin(), ans.end(), sortedHeights[i] ) - ans.begin(); 
                ans[idx] = sortedHeights[i] ; 
            }
        }

        return ans.size(); 
    }
};
