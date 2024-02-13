#include<bits/stdc++.h>

int solve(int n, int x, int y, int z, vector<int> &dp){

	if (n < 0){
		return INT_MIN; 
	}

	if(n==0){
		return 0; 
	}

	if(dp[n]!=-1){
		return dp[n]; 
	}

	int ansX =  solve(n-x, x, y, z, dp); 
	int ansY =  solve(n-y, x, y, z, dp ); 
	int ansZ =  solve(n-z, x, y, z, dp); 

	
   return dp[n] = 1 +  max(ansX, max(ansY, ansZ)); 


}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.

	vector<int> dp (n+1, -1); 

	int ans =  solve(n,x,y,z, dp); 
	if(ans < 0 ){
		return 0; 
	}
	return ans; 
}
