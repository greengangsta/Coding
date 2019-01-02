#include <bits/stdc++.h>
using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int m,n;
  m = a.size();
  n = b.size();
  int dp[m+1][n+1];
  for(int i=0;i<=m;i++)
    dp[i][0]=0;
  for(int j=0;j<=n;j++)
    dp[j][0]0;
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
       {
           if(a[i]==b[j])
            dp[i][j] = dp[i-1][j-1]+1;
           else
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])
       }
  
  return  dp[m][n];//std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
