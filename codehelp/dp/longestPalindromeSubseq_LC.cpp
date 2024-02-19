class Solution {
private : 
    int solve(string &s1, string &s2, int i, int j, vector <vector<int>> &dp){
        if(i>= s1.length() || j>= s2.length()){
            return 0; 
        }

        if(dp[i][j]!= -1){
            return dp[i][j]; 
        }

        // int ans = 0; 
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(s1, s2, i+1, j+1, dp ); 
        }

        else {
            return dp[i][j] = max(solve(s1, s2, i+1, j, dp ), solve(s1, s2, i, j+1, dp )); 
        }
    }
public:
    int longestPalindromeSubseq(string s) {
      int n = s.length(); 
      int m = s.length();
      string s2 = s; 
      vector <vector<int>> dp(n+1, vector<int>(m+1, -1)); 
      reverse(s2.begin(), s2.end()); 
      return solve(s,s2 , 0, 0, dp ); 
    }
};
