class Solution {

private : 
    int solve(vector<int>& obstacles, int pos, int n, int lane, vector<vector<int>> &dp){
        if(pos == n){
            return 0; 
        }
        else if(obstacles[pos+1] != lane){
            return  solve(obstacles, pos+1, n, lane, dp); 
        }

        if(dp[pos][lane]!=-1){
            return dp[pos][lane]; 
        }

        int firstAns = INT_MAX; 
        int secondAns  = INT_MAX; 

        if(obstacles[pos+1] == lane){

           if(lane == 1){
               if(obstacles[pos] != 2 )
               firstAns =  solve(obstacles, pos+1, n, 2, dp); 
               if(obstacles[pos] != 3)
               secondAns =  solve(obstacles, pos+1,n,  3, dp); 

           }
           else if(lane == 2){
                if(obstacles[pos] != 1)
                firstAns = solve(obstacles, pos+1, n, 1, dp); 
               if(obstacles[pos] != 3)
                secondAns = solve(obstacles, pos+1, n, 3, dp); 

           }
           else {
               if(obstacles[pos] != 1)
                 firstAns = solve(obstacles, pos+1, n, 1, dp); 
                if(obstacles[pos] != 2)
                secondAns = solve(obstacles, pos+1, n, 2, dp); 
           }
        }


        return dp[pos][lane] = 1 + min(firstAns, secondAns); 
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n =  obstacles.size(); 
        vector<vector<int>> dp(n+1, vector<int>(4, -1)); 
        return solve(obstacles, 0, n -1, 2, dp); 
    }
};
