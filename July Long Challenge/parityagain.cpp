#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int q,x;
        unordered_set <int> s;
        cin>>q;
        int c1 = 0,c2 = 0;
        for(int i=0;i<q;i++)
        {
            cin>>x;
            vector <int> v1;
            v1.push_back(x);
            if(s.find(x)==s.end())
            {
                s.insert(x);
            for(auto it = s.begin();it!= s.end();it++)
            {
                    if(*it != x)
                     v1.push_back(*it ^ x);
            }
            for(auto it = v1.begin();it!=v1.end();it++)
             {
                s.insert(*it);
               bitset <32> b1(*it); 
                 if(b1.count()%2==0)
                     c1 ++;
                    else
                     c2 ++;  
             }
             s.insert(x);
            }
             v1.clear();
            cout<<c1<<" "<<c2<<endl;
        }
    }
    
    
    
    
    return 0;
}