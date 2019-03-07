#include<bits/stdc++.h>
using namespace std;
int main()
{  
  stack <int> x;
  stack <int> y;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
      string s;
      cin>>s;
      if(s=="push")
      {
          int a;
          cin>>a;
          x.push(a);
          if(y.empty())
           y.push(a);
          else if(y.top()<a)
          y.push(a);
      }
      else if(s=="pop")
      {
          if(x.top()==y.top())
         {
             x.pop();
             y.pop();
             
         }
         else
         {
             x.pop();
         }
          
      }
      else if(s=="max")
      {
          cout<<y.top()<<endl;
      }
  }

   return 0; 
}