#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       string s1,s2;
       cin>>s1>>s2;
       int n,m;
       n = s1.length();
       m  = s2.length();
       bool dp[n+1][m+1];
       dp[0][0] = true;
       for(int j = 1;j<=m;j++)
        dp[0][j] = false;
        int count = 0;
       for(int i=1;i<=n;i++)
       {
           if(s1[i-1]>=65 && s1[i-1]<=90||count == 1)
           {
             dp[i][0] = false;
             count = 1;
           }
           else
           {
              dp[i][0] = true;
           } 
       }
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               if(s1[i-1]==s2[j-1])
               {
                   dp[i][j] = dp[i-1][j-1];
               }
               else if(toupper(s1[i-1])==s2[j-1])
               {
                   dp[i][j] = dp[i-1][j-1] || dp[i-1][j];
               }
               else if(s1[i-1]>=65 && s1[i-1]<=90)
               {
                   dp[i][j] = false;
               }
               else
               {
                   dp[i][j] = dp[i-1][j];
               }

           }
       }
       dp[n][m]?cout<<"YES":cout<<"NO";
       cout<<endl;

    /*
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=m;j++)
           {
               cout<<dp[i][j]<<" ";
           }
           cout<<endl;
       }
    */
   }





    return 0;
}