#include <bits/stdc++.h>
using namespace std;


int get_change(int m,int x[]) {
 vector <int> sequence;
 int dp[m+1];
 memset(dp,100001,sizeof(dp));
  dp[0]=0;
  dp[1]=0;
 for(int i=2;i<=m;i++)
   {
       int y=100001;
       for(int j=0;j<2;j++)
       {
           if(i%x[j]==0)
           {
             y = min(y,dp[i/x[j]]);
             if(y==dp[i/x[j]]);
              {
                  sequence.push_back(dp[i]*x[j]);
              }
           }
       }
        y = min(y,dp[i-1]);
    dp[i] = 1+y; 
   }
  for(int i=0;i<sequence.size();i++)
    cout<<sequence[i]<<" ";
    cout<<endl;
 return dp[m];    
}

int main() {
  int m;
  int x[]={2,3};
  std::cin >> m;
  std::cout << get_change(m,x) << '\n';
}
