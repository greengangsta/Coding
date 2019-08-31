#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<vector<long long int>> v(n);
    long long int last_ans = 0;
    for(int i=0;i<q;i++)
      {
          long long int a,x,y;
          cin>>a>>x>>y;
          if(a==1)
          {
                int id = (x^last_ans)%n;
                v[id].push_back(y);
          }
          else if(a==2)
          {
                 int id = (x^last_ans)%n;
                 int size = v[id].size();
                 last_ans = v[id][y% size];
                 cout<<last_ans<<endl;   
         }
      }
    return 0;
}