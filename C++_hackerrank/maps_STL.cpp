#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int q;
    cin>>q;
    unordered_map <string,int> mp;
    for(int i=0;i<q;i++)
    {
        int t;
        cin>>t;
        string s;
        cin>>s;
        if(t==1)
        {
          int x;
          cin>>x;
          if(mp.find(s)==mp.end())
          mp.insert({s,x}); 
          else
          mp[s] += x;
        }
        else if(t==2)
        {
          mp.erase(s);
        }
        else 
        {
          auto it = mp.find(s);
          if (it!=mp.end())
          {
              cout<<it->second<<endl;
          }
          else
          {
              cout<<0<<endl;
          }
        }
    }
    
}

