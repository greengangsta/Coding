#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int l=s.length();
        int i=0,j=l-1;
        int flag=0;
        while(i<=(l/2)+1&&j>=(l/2)-1)
        {
          if(s[i]==s[j])
           {
               i++;
               j--;
           }
          else if(flag==0)
          {
              if(s[i+1]==s[j]&&s[i+2]==s[j-1])
               cout<<i<<endl;
              else if(s[i]==s[j-1]&&s[i+1]==s[j-2])
               cout<<j<<endl;
              else 
              cout<<-1<<endl;
              flag =1 ;
              break;
          }
        }
        if(flag==0)
         cout<<-1<<endl;
    }




}