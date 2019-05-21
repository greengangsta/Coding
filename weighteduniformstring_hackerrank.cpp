#include<bits/stdc++.h>
using namespace std;

int main()
{
   
   int n;
   string s;
   cin>>s;
   unordered_set <int> set;
   int count = 1;
   set.insert(s[0]-'a'+1);
   for(int i=1;i<s.length();i++)
   {
      if(s[i]==s[i-1])
       {
         count++;
         set.insert((s[i]-'a'+1)*count);
       }
       else
       {
         count=1;
         set.insert(s[i]-'a'+1);
       }
   }
   cin>>n;
   for(int i=0;i<n;i++)
    {
        int q;
        cin>>q;
        if(set.find(q)==set.end())
         cout<<"No"<<endl;
        else
         cout<<"Yes"<<endl;

    }



    return 0;
}