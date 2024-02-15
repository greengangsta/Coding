class Solution {
private : 

    bool compareCuboids(vector<int>&a, vector<int>& b){
        if(a[0]<=b[0] && a[1]<=b[1]&&  a[2]<=b[2]){
            return true; 
        }
        return false; 
    }

    int solve(vector<vector<int>>& cuboids, int i, int last,  vector<vector <int> > &dp){
        
        if(i< 0){
            return 0; 
        }
        
        
        // include current 
        
        if(dp[i][last+1] != -1){
            return dp[i][last+1]; 
        }
        
        int includeAns = INT_MIN; 
        int excludeAns = INT_MIN; 
        
        if(last == -1 ||  compareCuboids(cuboids[i],cuboids[last])){
            // cout<<"included->"<<a[i]<<" ";
            includeAns = cuboids[i][2] + solve(cuboids, i-1, i, dp); 
            
        }

        // exclude current
        
        // cout<<"excluded->"<<a[i]<<" ";
        
         excludeAns = solve(cuboids, i-1, last, dp); 
         
        
         return  dp[i][last+1] = max(includeAns, excludeAns); 
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {

        for(auto &c : cuboids){
            sort(c.begin(), c.end()); 
        }

        sort(cuboids.begin(), cuboids.end()); 

        //  for(int i=0;i<cuboids.size();i++){
        //     cout<<cuboids[i][0]<<" "<<cuboids[i][1]<<" "<<cuboids[i][2]<<endl;
        // }

        int n = cuboids.size(); 

    
        vector<vector <int> > dp(n+1, vector<int>(n+1, -1)); 

        return  solve(cuboids, n-1, -1, dp); 
    }
};
