bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> stack1; 
    for(int i=0;i<s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack1.push(s[i]);
            }

            else if(s[i] == ')'){
                char currTop = 'a'; 
                if(!stack1.empty())
                currTop = stack1.top();
                if(currTop != '('){
                    return false;
                }
                stack1.pop();
            }
            else if(s[i] == '}'){
                char currTop = 'a';
                if(!stack1.empty())
                currTop = stack1.top();
                if(currTop != '{'){
                    return false;
                }
                 stack1.pop();
            }
            else if(s[i] == ']'){
                char currTop = 'a';
                if(!stack1.empty())
                currTop = stack1.top();
                if(currTop != '['){
                    return false;
                }
                 stack1.pop();
            }
        
    }
    // cout<<"code reached here";

    if(stack1.empty()){
        return true ;
    }

    return false; 

}
