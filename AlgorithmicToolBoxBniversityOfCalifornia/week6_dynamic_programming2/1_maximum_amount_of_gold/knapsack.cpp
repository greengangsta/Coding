#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n=w.size();
  int dp[n+1][W+1];
  for(int i=0;i<=W;i++)
     dp[0][i]=0; 
  for(int i=0;i<=n;i++)
     dp[i][0]=0;   
     
  for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            int v;
            dp[i][j] = dp[i-1][j];
            if(w[i]<=j)
              { 
                v = dp[i-1][j-w[i]] + w[i];
                 if(dp[i][j]<v)
                   dp[i][j]=v;
               }
        }
    }
  return dp[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
