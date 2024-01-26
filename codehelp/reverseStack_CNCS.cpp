
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

void reverseStack(stack<int> &stack) {
    if(stack.empty())
        return; 
    int top = stack.top();
    stack.pop();
    reverseStack(stack);
    solve(stack, top, stack.size());

}
