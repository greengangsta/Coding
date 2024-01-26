#include <bits/stdc++.h> 

void solve(stack<int> &myStack, int x, int count){
    if(myStack.empty()){
        myStack.push(x);
        return ; 
    }
    
    int top = myStack.top();
    myStack.pop();
    solve(myStack, x, count - 1);
    myStack.push(top);
    return  ; 
    

}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
     solve(myStack, x, myStack.size());
     
     return myStack; 
    // Write your code here.
}
