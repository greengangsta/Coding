#include<bits/stdc++.h>
using namespace std;
int main()
{
     stack <char> x;
     stack <int> y;
     string s;
     cin>>s;
     for(int i=0;i<s.length();i++)
      {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
         { 
             x.push(s[i]);
             y.push(i+1);
         }
        else if(s[i]==')'||s[i]=='}'||s[i]==']')
        {
            if(s[i]==')'&&(x.empty()||x.top()!='('))
            {
                cout<<i+1<<endl;
                break;
            }
            else if(s[i]==']'&&(x.empty()||x.top()!='['))
            {
                cout<<i+1<<endl;
                break;
            }
            else if(s[i]=='}'&&(x.empty()||x.top()!='{'))
            {
                cout<<i+1<<endl;
                break;
            }
            else
            { x.pop();
              y.pop();
            }
        }
        if(i==s.length()-1&&x.empty())
             cout<<"Success"<<endl;
        else if(i==s.length()-1&&!x.empty())
             cout<<y.top()<<endl;
      }
    

    
    
    return 0;
}