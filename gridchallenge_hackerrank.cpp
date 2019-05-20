#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      string s[n];
      for(int i=0;i<n;i++)
       cin>>s[i];
      int m = s[0].length();
      int flag=0;
      for(int i=0;i<n;i++)
        sort(s[i].begin(), s[i].end());
      for(int i=0;i<n-1;i++)
       {
           for(int j=0;j<m;j++)
        {
             if (int(s[i][j])>int(s[i+1][j])) {
               flag = 1;
               break;
             }
        }
        if(flag==1)
         break;
       }
     if(flag==1)
      cout<<"NO"<<endl;
     else 
      cout<<"YES"<<endl;
      
  }



    return 0;
}