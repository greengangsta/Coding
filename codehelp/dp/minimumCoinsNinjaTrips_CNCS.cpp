#include<bits/stdc++.h>

int solve(int n, vector<int> days, vector<int> cost, int i, vector<int> &dp){

    if(i >= n){
        return 0; 
    }

    // case cost [0]

    if(dp[i] != -1){
        return dp[i]; 
    }

    int curr; 

    int j = i; 
    int k = i; 
    int l = i; 
    
    curr = days[i]; 

    while(curr < days[i] + 1 && j<n){
        curr = days[j+1]; 
        j++; 
    }

    curr = days[k]; 

    while(curr < days[i] + 7  && k<n){
         curr = days[k+1]; 
         k++; 
    }

    curr = days[l]; 
     while(curr < days[i] + 30  && l<n){
        curr = days[l+1]; 
        l++; 
    }


    int ansZero = cost[0] + solve(n, days, cost, j, dp); 

    // case cost [1]

    int ansOne = cost[1] + solve(n, days, cost, k, dp); 


    int ansTwo = cost[2] + solve(n, days, cost, l, dp); 


    return dp[i] = min(ansZero, min(ansOne, ansTwo)); 


}


int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int> dp(n+1, -1); 

    return solve(n, days, cost, 0, dp); 
}
