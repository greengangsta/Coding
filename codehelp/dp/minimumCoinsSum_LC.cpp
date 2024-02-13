#include <bits/stdc++.h> 

int solve(vector<int> &num, int x, int n, vector<int> &dp){
        if(x == 0){
            return 0; 
        }
        else if(x < 0 ){
            return INT_MAX; 
        }

        if(dp[x]!=-1){
            return dp[x]; 
        }

        // include ith 
        int mini = INT_MAX; 
        for(int i=0;i<n;i++){
          int ans = solve(num, x - num[i], n, dp); 
          if(ans!= INT_MAX){

              mini = min(mini, 1 + ans); 
          }
        }
        
        dp[x] = mini; 

        return  mini; 
            
         
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.

    int i =0;
    int n = num.size(); 
    vector<int> dp(x+1, -1); 
    dp[0] = 0; 
    int ans = solve(num, x, n, dp);
    if(ans==INT_MAX){
        return -1; 
    }

    return dp[x]; 
}
