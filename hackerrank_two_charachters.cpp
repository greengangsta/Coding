#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l;
    cin>>l;
    string s;
    cin>>s;
    int a[26]={0};
    for(int i=0;i<l;i++)
      a[s[i]-'a']++;
    int max = 0;
    for(int i=0;i<26;i++) 
    {
        for(int j = i+1;j<26;j++)
        {
            int last = -1;
            char it = 'a' + i;
            char jt = 'a' + j;
            int flag = 0;
            for(int k = 0;k<l;k++)
            { 
              if((last == i && s[k]==it) || (last == j && s[k]==jt) )
              {  flag = 1;
                  break;
              }
              if(s[k]==it)
              {
                 last = i;
              }
              else if(s[k]==jt)
              {
                  last = j;
              }
            }
            if(flag==0)
             {
                 if(max<a[i]+a[j])
                  max = a[i]+a[j];
             }
        }
    }

   cout<<max<<endl;


    return 0;
}