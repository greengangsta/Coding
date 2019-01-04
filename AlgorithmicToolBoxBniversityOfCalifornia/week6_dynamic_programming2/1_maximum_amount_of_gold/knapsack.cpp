#include <bits/stdc++.h>
using namespace std;

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n=w.size();
  vector <vector <int> > dp(n+1,vector<int>(W+1,0));
  for(int i=0;i<=W;i++)
     dp.at(0).at(i)=0; 
  for(int i=0;i<=n;i++)
     dp.at(i).at(0)=0;   
     
  for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            int v;
            dp.at(i).at(j) = dp.at(i-1).at(j);
            if(w[i-1]<=j)
              { 
                v = dp.at(i-1).at(j-w[i-1]) + w[i-1];
                 if(dp.at(i).at(j)<v)
                   dp.at(i).at(j)=v;
               }
        }
    }
  return dp.at(n).at(W);
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
