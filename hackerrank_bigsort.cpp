#include<bits/stdc++.h>
using namespace std;

bool cmp(string a,string b)
{
    if(a.length()>b.length())
     return 0;
    else if(a.length()< b.length())
     return 1;
    else
      {
          int flag=0;
          for(int i=0;i<a.length();i++)
           {
               if(a[i]-'0'<b[i]-'0')
                {
                    flag=1;
                    break;
                }
               else if(a[i]-'0'>b[i]-'0')
               {
                   flag=0;
                   break;
               }
           }
           if(flag==1)
            return 1;
           return 0;
      }
}
int main()
{
    int n;
    cin>>n;
    string unsorted[n];
    for(int i=0;i<n;i++)
      cin>>unsorted[i];
      sort(unsorted,unsorted+n,cmp);
    for(int i=0;i<n;i++)
     cout<<unsorted[i]<<endl;



    return 0;
}