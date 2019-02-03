#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,count=0;
        cin>>n;
        int a[26]={0};
        for(int i=0;i<n;i++)
          {
              cin>>s[i];
              for(int j=0;j<s.length();j++)
              {
                  if(a[s[j]-'a']==i-1)
                   {
                       a[s[j]-'a']=i;
                   }
              }
          }
          for(int i=0;i<26;i++)
            if(a[i]==n-1)
             count++;
             
             cout<<count<<endl;
          
    
     
    }
}
