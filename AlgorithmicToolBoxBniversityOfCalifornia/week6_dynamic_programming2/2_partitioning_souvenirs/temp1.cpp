#include <bits/stdc++.h>
using namespace std;


int partition3(vector<int> &A) {
  //write your code here
  int n=A.size();
  sort(A.begin(),A.end(),greater<>());
    int flag1=0,flag2=0;
  int sum=0;
  for(int i=0;i<A.size();i++)
    sum+=A[i];
  if(sum%3!=0)
   return 0;
  else
  {
    //   cout<<"check0"<<endl;
      int dp[n+1][(sum/3) + 1];
        for(int i=0;i<=n;i++)
      {
          for(int j=0;j<=sum/3;j++)
          {
              if(i==0||j==0)
              dp[i][j]=0;
              else
              {
                int v;
                dp[i][j]=dp[i-1][j];
                if(A[i-1]<=j)
                 {
                    v = dp[i-1][j-A[i-1]]+A[i-1];
                   if(dp[i][j]<v)
                   dp[i][j] = v;
                 }
              }
          }
      }
    //  cout<<"check1"<<endl;
      if(dp[n][sum/3]==sum/3)
       flag1=1;
      int it=n,jt=sum/3;
      while(it>0&&jt>0)
       {
           if(dp[it][jt]==dp[it-1][jt])
            { 
                jt=jt-A[it];
             it--;
            }
           else
           {
            A[it-1]=0;
                it--;
           }
       }
     //   cout<<"check2"<<endl;
       for(int i=0;i<=n;i++)
      {
          for(int j=0;j<=sum/3;j++)
          {
              if(i==0||j==0)
              dp[i][j]=0;
              else
              {
                int v;
                dp[i][j]=dp[i-1][j];
                if(A[i-1]<=j)
                 {
                    v = dp[i-1][j-A[i-1]]+A[i-1];
                   if(dp[i][j]<v)
                     dp[i][j] = v;
                 }
              }
          }
      }
      // cout<<"check3"<<endl;
      if(dp[n][sum/3]==sum/3)
       flag2=1;
       
  }
  
  if(flag1&&flag2)
  return 1;
  else
  return 0;
}

int main() {
   
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
    
}
