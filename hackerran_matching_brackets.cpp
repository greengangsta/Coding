#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   while(n--)
   {
       string s;
       cin>>s;
       stack <char> st;
       int flag = 0;
       for(int i=0;i<s.length();i++)
       {
           //cout<<i<<endl;
          if(s[i]=='{'||s[i]=='('||s[i]=='[')
           st.push(s[i]);
          else if((s[i]=='}'||s[i]==')'||s[i]==']') && st.empty())
           {
               flag = 1;
                break;
           }
          else if(s[i]==')' && st.top()=='(')
          { 
            st.pop();
          }
          else if(s[i]=='}' && st.top()=='{')
          {
            st.pop();
          }
          else if(s[i]==']'&&st.top()=='[')
          {
            st.pop();
          }   
          else
          {
              flag = 1;
              break;
           }
       }
      if(!st.empty())
        flag = 1;
      if(flag==1)
        cout<<"NO"<<endl;
      else
        cout<<"YES"<<endl;
   }







    return 0;
}