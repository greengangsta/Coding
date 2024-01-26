#include <bits/stdc++.h> 

void insertAtRightPlace(stack<int> &stack, int x){
	if(stack.empty()){
		stack.push(x);
		return; 
	}

	int top = stack.top();
	stack.pop();
	if(top < x){
		stack.push(top);
		stack.push(x); 
		return; 
	}
	else{
		insertAtRightPlace(stack, x);
		stack.push(top);
		return; 
	}

}

void sortStack(stack<int> &stack)
{
	// Write your code here

	if(stack.empty() || stack.size() == 1 ){
		return; 
	}

	int top = stack.top(); 
	stack.pop(); 
	sortStack(stack); 
	insertAtRightPlace(stack, top); 

}
