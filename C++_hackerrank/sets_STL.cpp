#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int q;
    cin>>q;
    unordered_set <int> s;
    for(int i=0;i<q;i++)
    {
        int y,x;
        cin>>y;
        cin>>x;
        if(y==1)
         s.insert(x);
        else if (y==2)
         s.erase(x);
        else
         {
             if(s.find(x)!=s.end())
              cout<<"Yes"<<endl;
              else
              cout<<"No"<<endl;
         }
    }
}

