#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack <char> s1; 
    // Write your code here.
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-'|| ch == '*'  || ch == '/'){
            s1.push(ch);
        }

        else if(ch == ')'){
           char top = s1.top();
           s1.pop();
           if(top == '(')
           {
                return true; 
           }
           else{
               while(top != '(' && !s1.empty()){
                   top = s1.top();
                    s1.pop();
               }
              
           }
           
        }
    }

    return false;
}
