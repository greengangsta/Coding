#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  // Write your code here

   if (str.length()%2 == 1) {
     return -1; 
   }

    stack <char> s1; 

    for(int i=0;i<str.length();i++){

      char ch = str[i];
      if(ch=='{'){
        s1.push(ch);
      }
      else if(!s1.empty()){
          char top = s1.top();
          if(top == '{'){
            s1.pop();
          }
          else {
            s1.push(ch);
          }
      }
      else{
        s1.push(ch);
      }
    }

    int count = 0; 
    while(!s1.empty()){
      char top1 = s1.top();
      s1.pop();
      char top2 = s1.top();
      s1.pop();

      if(top1 == top2){
        count += 1; 
      }
      else {
        count +=2; 
      }
      
    }

    return count;

}
