#include<bits/stdc++.h>
using namespace std;

struct node{
    long long int a;
    long long int b;
};

int main()
{
     int t;
     cin>>t;
     while(t--)
      {
        long long int n,m,k;
        cin>>n>>m>>k;
        node pairs[k];
        unordered_set <string> s;
        for(int i=0;i<k;i++)
         {
             string s1,s2;
             cin>>pairs[i].a>>pairs[i].b;
             s1 = to_string(pairs[i].a);
             s2 = to_string(pairs[i].b);
             s.insert(s1+":"+s2);
         }
        long long int sum=0;
        for(int j=0;j<k;j++)
        {
            string n1,n2,n3,n4;
            long long int p,q;
            p = pairs[j].a;
            q = pairs[j].b;
            n1 = to_string(p-1)+":"+to_string(q);
            n2 = to_string(p+1)+":"+to_string(q);
            n3 = to_string(p)+":"+to_string(q+1);
            n4 = to_string(p)+":"+to_string(q-1);
            if(s.find(n1)!=s.end())
             sum++;
            if(s.find(n2)!=s.end())
             sum++;
            if(s.find(n3)!=s.end())
             sum++;
            if(s.find(n4)!=s.end())
             sum++;
        }
        long long int plants = 4*k-sum;
         cout<<plants<<endl;
      }
    
    return 0;
}