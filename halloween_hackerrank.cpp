#include<bits/stdc++.h>
using namespace std;

int main()
{
   int p,d,m,s;
   cin>>p>>d>>m>>s;
   int count=0;
   while(s>=0)
   {
     count++;
     s = s -p;
     p = max(p-d,m);
   }
   cout<<count-1<<endl;
    return 0;
}