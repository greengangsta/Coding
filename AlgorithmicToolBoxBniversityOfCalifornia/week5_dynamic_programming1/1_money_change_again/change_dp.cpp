#include <bits/stdc++.h>
using namespace std;


int get_change(int m,int x[]) {
 
 int dp[m+1];
 memset(dp,1001,sizeof(dp));
  dp[0]=0;
 for(int i=1;i<=m;i++)
   {
       int y=1001;
       for(int j=0;j<3;j++)
        {
            if(i-x[j]>=0)
            {
                y = min(y,dp[i-x[j]]);
            }
        } 
    dp[i] = 1+y; 
   }
 return dp[m];    
}

int main() {

  int m;
  int c[]={1,3,4};
  std::cin >> m;
  std::cout << get_change(m,c) << '\n';
    
}
