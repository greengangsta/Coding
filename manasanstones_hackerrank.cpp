#include <bits/stdc++.h>
using namespace std;

int main() {
   
   int t;
   cin>>t;
   while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        set <int> s1;
        if(a<b)
        {
          s1.insert((n-1)*a);
          n--;
          while(n--)
          {
              auto it = s1.rbegin();
              int val = *it - a;
              s1.insert(val + b);
          }
        }
        else
        {
          s1.insert((n-1)*b);
          n--;
          while(n--)
          {
              auto it = s1.rbegin();
              int val = *it - b;
              s1.insert(val + a);
          }
        }
        for(auto it = s1.begin();it!=s1.end();it++)
          cout<<*it<<" ";
        cout<<endl;
        s1.clear();
    }



  return 0;
}
