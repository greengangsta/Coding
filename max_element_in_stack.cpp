#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int max = 0;
   set <int> s;
   stack <int> st;
   unordered_map <int,int> mp;;
   for(int i=0;i<n;i++)
   {
       int a;
       cin>>a; 
       if(a==1)
       {
           int x;
           cin>>x;
           if(x>max)
            max = x;
           st.push(x);
           s.insert(x);
           if(mp.find(x)==mp.end())
             {
                 mp.insert({x,1});
             }
            else{
                auto it = mp.find(x);
                it->second += 1;
            }
       }
       else if(a==2)
       {
           int x;
           x = st.top();
           if(max==x)
           {
            auto it = mp.find(x);
            if(it->second==1||it->second==0)
            {
             s.erase(it->second);
             it->second = 0;
             max = *s.end();
            }
            else
            {
                it->second -= 1;
            }
           }
           st.pop();
       }
       else
       {
           cout<<max<<endl;
       }
   }



    return 0;
}