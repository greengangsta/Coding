#include <bits/stdc++.h> 


void solve(stack<int>&inputStack, int count, int size){
   if(count==size/2){
      inputStack.pop(); 
      return; 
   }

   int top = inputStack.top();
   inputStack.pop();
   solve(inputStack, count+1, size);
   inputStack.push(top);
   return; 

}
void deleteMiddle(stack<int>&inputStack, int N){
      
      solve(inputStack, 0, N);

   // Write your code here
   
}
