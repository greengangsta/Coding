//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define MOD 1000000007
class Solution {
  public:
  
    int solve(int m, int n, long long int &count, int i, int j,  vector <vector<long long int>> &dp){
        
        if(i >= m || j >= n){
            return 0 ; 
        }
        
        
        else if(i==m-1 && j==n-1){
            count++; 
            return 1; 
        }
        
        if(dp[i][j]!= -1){
            return dp[i][j]; 
        }
        
        // go down 
        
        // cout<<"i->"<<i<<" "<<"j-> "<<j<<endl; 
        
        long long int iAns = solve(m, n, count, i+1, j, dp); 
        
        
        // go right 
        long long int jAns = solve(m, n, count, i, j+1, dp); 
        
        return dp[i][j]=  (iAns + jAns)%MOD; 
        
        
    }
    long long int numberOfPaths(int m, int n){
        // code here
        long long int count = 0; 
      vector <vector<long long int>> dp (m+1, vector<long long int>(n+1, -1)); 
        return solve(m, n, count, 0, 0, dp ); 
        // return count; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
