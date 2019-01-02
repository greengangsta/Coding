#include <bits/stdc++.h>
using namespace std;

vector<int> optimal_sequence(int m) {
  vector <int> sequence;
  int x[]={2,3};
 sequence.push_back(m);
 int dp[m+1];
 memset(dp,100001,sizeof(dp));
  dp[0]=0;
  dp[1]=0;
 for(int i=2;i<=m;i++)
   {
       int y=100001;
         y = min(y,dp[i-1]);
       for(int j=0;j<2;j++)
       {
          
           if(i%x[j]==0)
           {
             y = min(y,dp[i/x[j]]);
           }
       }
    dp[i] = 1+y; 
   }
   for(int i=m;i>=2;)
     {
          if(dp[i]==dp[i/x[0]]+1&&i%x[0]==0)
          {
              sequence.push_back(i/x[0]);
               i/=x[0];
          }
          else if(dp[i]==dp[i/x[1]]+1&&i%x[1]==0)
          {
              sequence.push_back(i/x[1]);
               i/=x[1];
          }
          else if(dp[i]==dp[i-1]+1)
          {
              sequence.push_back(i-1);
               i--;
          }
          
     }
     //cout<<dp[m]<<endl;
    reverse(sequence.begin(), sequence.end());
	return sequence;
}

int main() {
  

  int m;
  std::cin >> m;
  vector<int> sequence = optimal_sequence(m);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }

}
