#include <bits/stdc++.h>
using namespace std;


int get_change(int m,int x[]) {
 
 int dp[m+1];
 dp[0]=0;
 memset(dp,0,sizeof(dp));
 for(int i=1;i<=m;i++)
     dp[i] = 1+min(dp[i-x[0]],min(dp[i-x[1]],dp[i-x[2]]));
     
 return dp[m];    
}

int main() {
  int m;
  int c[]={1,3,4};
  std::cin >> m;
  std::cout << get_change(m,c) << '\n';
}
