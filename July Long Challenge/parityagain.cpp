#include<bits/stdc++.h>
using namespace std;

int parity(int n)
{
    if(n==0)
     return 0;
    else if (n%2==0)
     return parity(n/2);
    else
     return  1 - parity(n/2);
     
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int q,x;
        unordered_set <int> s;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            cin>>x;
            int c1 = 0,c2 = 0;
            s.insert(x);
            for(auto it = s.begin();it!= s.end();it++)
            {
                    if(*it != x)
                    s.insert(*it ^ x);
            }
             for(auto it = s.begin();it!= s.end();it++)
            {
                 if(parity(*it)==0)
                     c1 ++;
                    else
                     c2 ++;
            }
            cout<<c1<<" "<<c2<<endl;
        }
    }
    
    
    
    
    return 0;
}