#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   string s;
   cin>>s;
   int d,l,u,c;
   d=l=c=u=0;
   for(int i=0;i<n;i++)
    {
        int k= s[i]-NULL;
        if(k>=48&&k<=57)
         d=1;
        else if (k >= 65 && k <= 90)
         u=1;
        else if (k >= 97 && k <= 122)
         l=1;
        else if (k >= 33 && k <= 45)
         c=1;
    }
    int count=0;
     if(d==0)
      count++;
     if (l == 0)
       count++;
     if (u == 0)
       count++;
     if (c == 0)
       count++;
     if(count+s.length()<6)
       count = 6-s.length();
       cout<<count<<endl;
     return 0;
}