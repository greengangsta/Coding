#include<bits/stdc++.h>
using namespace std;

int main()
{

   stack <int> s,m;
   int n;
   cin>>n;
    m.push(-1);
   while(n--)
   {
       int a;
       cin>>a;
       if(a==1)
       {
         int x;
         cin>>x;
         s.push(x);
         if(x>=m.top())
          m.push(x);
       }
       else if(a==2)
       {
           int x = m.top();
           int y = s.top();
          if(x==y)
             {
                 s.pop();
                 m.pop();
             }
           else
             s.pop();
       }
       else
       {
          cout<<m.top()<<endl;
       }
   }






    return 0;
}