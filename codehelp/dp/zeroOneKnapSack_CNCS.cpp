#include <bits/stdc++.h> 

int solve(vector<int> &weight, vector<int> &value, int n, int maxWeight, int i, vector < vector<int> > &dp){

  if (i >= n || maxWeight <= 0) {
    return 0;
  }

  if (dp[maxWeight][i] != -1){
	  return dp[maxWeight][i]; 
  }

                // case include current
		int includeAns = 0; 
		int excludeAns = 0; 
		if(maxWeight - weight[i] >= 0 )
			includeAns = value[i] + solve(weight,value, n, maxWeight - weight[i] , i + 1, dp);  

		// case exclude current 

		excludeAns = solve(weight, value, n, maxWeight, i + 1, dp); 

		return dp[maxWeight][i] = max(includeAns, excludeAns);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here

	vector <vector<int>> dp(maxWeight + 1, vector<int> (n+1, -1)); 

	return solve(weight,value, n, maxWeight, 0, dp);  
}
