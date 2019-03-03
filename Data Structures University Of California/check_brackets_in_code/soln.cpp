#include<bits/stdc++.h>
using namespace std;
int main()
{
     stack <char> x;
     string s;
     cin>>s;
     for(int i=0;i<s.length();i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
          x.push(s[i]);
        else if(s[i]==')'||s[i]=='}'||s[i]==']')
        {
            if(s[i]==')'&&x.top()!='(')
            {
                cout<<i+1<<endl;
                break;
            }
            else if(s[i]=='['&&x.top()!=']')
            {
                cout<<i+1<<endl;
                break;
            }
            else if(s[i]=='{'&&x.top()!='}')
            {
                cout<<i+1<<endl;
                break;
            }
            else
             x.pop();
        }
         if(i==s.length()-1&&x.empty())
             cout<<"Success"<<endl;
         else if(i==s.length()-1&&!x.empty())
             cout<<i+1<<endl;
      }
    

    
    
    return 0;
}