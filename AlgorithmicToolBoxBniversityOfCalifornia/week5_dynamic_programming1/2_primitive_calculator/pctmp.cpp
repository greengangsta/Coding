#include <bits/stdc++.h>
using namespace std;


void get_change(int m,int x[]) {
 vector <int> sequence;
 sequence.push_back(m);
 int dp[m+1];
 memset(dp,100001,sizeof(dp));
  dp[0]=0;
  dp[1]=0;
 for(int i=2;i<=m;i++)
   {
       int y=100001;
       for(int j=0;j<2;j++)
       {
            y = min(y,dp[i-1]);
           if(i%x[j]==0)
           {
             y = min(y,dp[i/x[j]]);
           }
       }
    dp[i] = 1+y; 
   }
   for(int i=m;i>2;)
     {
         if(dp[i]==dp[i-1]+1)
          {
              sequence.push_back(i-1);
               i--;
          }
          else if(dp[i]==dp[i/x[0]]+1&&i%x[0]==0)
          {
              sequence.push_back(i/x[0]);
               i/=x[0];
          }
          else if(dp[i]==dp[i/x[1]]+1&&i%x[1]==0)
          {
              sequence.push_back(i/x[1]);
               i/=x[1];
          }
          
     }
     cout<<dp[m]<<endl;
    reverse(sequence.begin(), sequence.end());
  for(int i=0;i<sequence.size();i++)
    cout<<sequence[i]<<" ";
    cout<<endl;
// return dp[m];    
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
      int m;
      int x[]={2,3};
      std::cin >> m;
      get_change(m,x);
     // std::cout << get_change(m,x) << '\n';
    }
}
