class Solution {
private: 
    int solve(string &s1, string &s2, int i, int j , vector <vector<int>> &dp){
    
     if(i>=s1.length()){
         return s2.length() - j; 
     }
     if(j>=s2.length()){
         return s1.length() - i; 
     }

     if(dp[i][j]!= -1){
        return  dp[i][j]; 
     }

    if(s1[i] == s2[j]){
        return dp[i][j] = solve(s1, s2, i+1, j+1, dp); 
    }

    else {

        int insertAns =  1 + solve(s1, s2, i, j+1, dp); 
        int deleteAns = 1 +  solve(s1, s2, i+1, j, dp); 
        int replaceAns = 1 +  solve(s1, s2, i+1, j+1, dp); 

        return dp[i][j] = min(insertAns, min(deleteAns, replaceAns)); 

    }


        
    }
public:
    int minDistance(string word1, string word2) {
    int n = word1.length(); 
      int m = word2.length();
      vector <vector<int>> dp(n+1, vector<int>(m+1, -1)); 
        return solve(word1, word2, 0, 0, dp ); 
    }
};
